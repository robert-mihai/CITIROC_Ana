#include <stdio.h>
#include <string.h>
#include <exception>
#include <fstream>
#include <vector>
#include "TFile.h"
#include "TDirectory.h"
#include "TH1D.h"
#include "TSystem.h"
#include "TMacro.h"
#include <TTree.h>
#include <iostream>
#include <sstream>
#include "TH2.h"
#include "TF1.h"
#include "TH3.h"
#include <iterator>
#include <algorithm>
#include <TProfile.h>


using namespace std;


Double_t bestfit(Double_t *x, Double_t *par) {
    //return par[0]*TMath::Exp(par[1]*x[0]) + par[2]*TMath::Exp(par[3]*x[0]);
    //return par[0]*TMath::Power(x[0],par[1]);
    //return par[0] + (par[1] - TMath::Exp(par[2]*(x[0] + par[3])))/(par[4] - TMath::Exp(par[5]*(x[0]+par[6])));
    return par[0] + par[1]*x[0] + par[2]*x[0]*x[0] +par[3]*x[0]*x[0]*x[0] +par[4]*x[0]*x[0]*x[0]*x[0];
}
Double_t lineFit(Double_t *x, Double_t *par) {
    return par[0] + par[1]*x[0];
}

string GetLocation(string str)
{
     
    int i = str.rfind("_Slot_");
    string way = str.substr(0,i);  
    return way;
}

struct vectorsTree
{
  vector<double> *FEBSN;
  vector<double> *SpillNum;
  vector<double> *GTrigTag;
  vector<double> *GTrigTime;
  vector<double> *hitsChannel;
  vector<double> *hitAmpl;
  vector<double> *hitLGAmplMatched;
  vector<double> *hitLeadTime;
  vector<double> *hitTrailTime;
  vector<double> *hitTimeDif;
};

int main ()
{
    int NumberOfFEB=65;
    
    vector<string> vFileNames;
    string sFileName;
    ifstream fList("febs_files_list.list");
    while (!fList.eof()) {
        fList >> sFileName;
        vFileNames.push_back(sFileName);
    }
    string rootFileInput=GetLocation(vFileNames[0].c_str());
    string rootFileOutput=GetLocation (vFileNames[0].c_str());
    rootFileInput+="_all_matching.root";
    rootFileOutput+="_LG_ToT_calib.root";
    cout << rootFileInput<<endl;
    cout << rootFileOutput<<endl;
    TFile *FileInput = new TFile(rootFileInput.c_str());
    
    vectorsTree FEB[NumberOfFEB];
    
    for (Int_t i=0;i<NumberOfFEB;i++){
        FEB[i].FEBSN=0;
        FEB[i].SpillNum=0;
        FEB[i].hitsChannel=0;
        FEB[i].hitAmpl=0;
        FEB[i].hitLeadTime=0;
        FEB[i].GTrigTag=0;
        FEB[i].GTrigTime=0;
        FEB[i].hitLGAmplMatched=0;
        FEB[i].hitTrailTime=0;
        FEB[i].hitTimeDif=0;
    }
    
    TTree *FEBtree[NumberOfFEB];
    vector<int> FEBnumbers;
    FEBnumbers.clear();
    Long64_t nentries[NumberOfFEB];

    ostringstream sFEBnum;
    string sFEB;
    for (Int_t ih=0; ih<NumberOfFEB; ih++) {
        sFEBnum.str("");
        sFEBnum << ih;
        sFEB = "FEB_"+sFEBnum.str();
        FEBtree[ih] = (TTree*)FileInput->Get(sFEB.c_str());
        if ((TTree*)FileInput->Get(sFEB.c_str())){
            FEBnumbers.push_back(ih);
            std::cout<<sFEB<<" ";
            FEBtree[ih]->SetBranchAddress((sFEB+"_SN").c_str(),&FEB[ih].FEBSN);
            FEBtree[ih]->SetBranchAddress((sFEB+"_SpillTag").c_str(),&FEB[ih].SpillNum);
            FEBtree[ih]->SetBranchAddress((sFEB+"_GTrigTag").c_str(),&FEB[ih].GTrigTag);
            FEBtree[ih]->SetBranchAddress((sFEB+"_GTrigTime").c_str(),&FEB[ih].GTrigTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitsChannel").c_str(),&FEB[ih].hitsChannel);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitAmpl").c_str(),&FEB[ih].hitAmpl);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitLGAmplMatched").c_str(),&FEB[ih].hitLGAmplMatched);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitLeadTime").c_str(),&FEB[ih].hitLeadTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTrailTime").c_str(),&FEB[ih].hitTrailTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTimeDif").c_str(),&FEB[ih].hitTimeDif);
            
            nentries[ih] = FEBtree[ih]->GetEntries();
            std::cout << "Number of Spills = " <<nentries[ih]<<std::endl;
        }
  }
  
  TFile wfile(rootFileOutput.c_str(), "recreate");
  TH2F *LG_vs_ToT[NumberOfFEB][96];

  Double_t fitPar[6];
  TF1 *f = new TF1("f",bestfit,10,30,5);

  Double_t fitLin1[2];
  TF1 *fline1 = new TF1("fline1",lineFit,0,11,2);

  Double_t fitLin2[2];
  TF1 *fline2 = new TF1("fline2",lineFit,26,35,2);

  //TF1 *f = new TF1("f","gaus",10,25);
  //TF1 *f = new TF1("f", "pol1", 10, 200, 6);
  for (int ih = 0; ih<FEBnumbers.size();ih++) {
        cout <<"FEB " <<FEBnumbers.at(ih)<<" in process."<<endl;
        sFEBnum.str("");
        sFEBnum << FEBnumbers.at(ih);
        sFEB = "FEB_"+sFEBnum.str();
    
        string fouttxt = "LG_ToT_calib/";
        fouttxt+=sFEB.c_str();
        fouttxt+="_LG_ToT_calib.txt";
        ofstream foutDat(fouttxt.c_str());
        TDirectory *FEB_LG_ToT = wfile.mkdir(sFEB.c_str());
        
        ostringstream sChnum;
        string sCh;
        
        for (Int_t ich=0; ich < 96;ich++){
            sChnum.str("");
            sChnum << ich;
            sCh =  "FEB_" + sFEBnum.str() + "_channel_" + sChnum.str();
            LG_vs_ToT[FEBnumbers.at(ih)][ich]=new TH2F(sCh.c_str(),sCh.c_str(),  51, 0, 50, 4096, 0, 4095);
        }
        
        
        for (Int_t enu = 0; enu<nentries[FEBnumbers.at(ih)]; enu++){
            FEBtree[FEBnumbers.at(ih)]->GetEntry(enu);
            for (Int_t i = 0; i<FEB[FEBnumbers.at(ih)].hitTimeDif->size(); i++){
                if (FEB[FEBnumbers.at(ih)].hitLGAmplMatched->at(i)>0 && FEB[FEBnumbers.at(ih)].hitTimeDif->at(i)>0 && FEB[FEBnumbers.at(ih)].hitLGAmplMatched->at(i) < 3500) {
                //cout<< FEB[FEBnumbers.at(ih)].hitAmpl->at(i)<< " "<< FEB[FEBnumbers.at(ih)].hitLGAmplMatched->at(i)<<endl;
                    if (FEB[FEBnumbers.at(ih)].hitTimeDif->at(i)>12){
                        LG_vs_ToT[FEBnumbers.at(ih)][(int)FEB[FEBnumbers.at(ih)].hitsChannel->at(i)]-> Fill(FEB[FEBnumbers.at(ih)].hitTimeDif->at(i),FEB[FEBnumbers.at(ih)].hitLGAmplMatched->at(i) , 1);
                    } else {
                    if (FEB[FEBnumbers.at(ih)].hitLGAmplMatched->at(i) < 200)
                        LG_vs_ToT[FEBnumbers.at(ih)][(int)FEB[FEBnumbers.at(ih)].hitsChannel->at(i)]-> Fill(FEB[FEBnumbers.at(ih)].hitTimeDif->at(i),FEB[FEBnumbers.at(ih)].hitLGAmplMatched->at(i) , 1);
                    }
                }
            }
        }
        
        
        FEB_LG_ToT->cd();
        for (Int_t ich=0; ich < 96;ich++){
            if (LG_vs_ToT[FEBnumbers.at(ih)][ich]->GetEntries()>1) {
                int LastBin = LG_vs_ToT[FEBnumbers.at(ih)][ich]->FindLastBinAbove(0);

                TProfile *prof = LG_vs_ToT[FEBnumbers.at(ih)][ich]->ProfileX();
                prof->GetYaxis()->SetTitle("LG [ADC]");
                prof->GetXaxis()->SetTitle("Time over Threshold [2.5 ns]");

                std::fill(fitLin1, fitLin1 + 2, 0);
                std::fill(fitPar, fitPar + 5, 0);
                std::fill(fitLin2, fitLin2 + 2, 0);

                prof->Fit("fline1","MER");
                fline1->GetParameters(&fitLin1[0]);

                prof->Fit("f","MER+");
                f->GetParameters(&fitPar[0]);

                prof->Fit("fline2","MER+");
                fline2->GetParameters(&fitLin2[0]);


                cout<<"Channel "<< ich <<" fit par "<<fitLin1[0]<<" "<< fitLin1[1] <<" "<< fitPar[0]<<" "<< fitPar[1]<<" "<< fitPar[2]<<" "<< fitPar[3]<<" "<< fitPar[4] <<" "<< fitLin2[0]<<" "<< fitLin2[1] <<endl;
               // cout<<"Channel "<< ich <<" fit par "<< fitPar[0]<<" "<< fitPar[1]<<" "<< fitPar[2]<<" "<< fitPar[3]<<endl;
                foutDat << ich<<" "<<fitLin1[0]<<" "<< fitLin1[1] <<" "<< fitPar[0]<<" "<< fitPar[1]<<" "<< fitPar[2]<<" "<< fitPar[3]<<" "<< fitPar[4]<<" "<< fitLin2[0]<<" "<< fitLin2[1] << endl;
               //foutDat << ich<<" "<<fitPar[0]<<" "<< fitPar[1]<<" "<< fitPar[2]<<" "<< fitPar[3]<<endl;
                prof->Write();
                prof->Delete();
                //f->Delete();
            }
            delete LG_vs_ToT[FEBnumbers.at(ih)][ich];
           
        }
        
        foutDat.close();
        FEB[FEBnumbers.at(ih)].FEBSN->clear();
        FEB[FEBnumbers.at(ih)].SpillNum->clear();
        FEB[FEBnumbers.at(ih)].hitsChannel->clear();
        FEB[FEBnumbers.at(ih)].hitAmpl->clear();
        FEB[FEBnumbers.at(ih)].hitLeadTime->clear();
        FEB[FEBnumbers.at(ih)].hitTrailTime->clear();
        FEB[FEBnumbers.at(ih)].hitTimeDif->clear();
        FEB[FEBnumbers.at(ih)].GTrigTag->clear();
        FEB[FEBnumbers.at(ih)].GTrigTime->clear();
        FEB[FEBnumbers.at(ih)].hitLGAmplMatched->clear();
  }
  wfile.Close();
  FileInput->Close();
  return 0;
}

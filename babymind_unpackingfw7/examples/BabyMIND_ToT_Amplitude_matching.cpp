#include <stdio.h>
#include <string.h>
#include <exception>
#include <fstream>
#include <vector>
#include "TFile.h"
#include "TDirectory.h"
#include "TSystem.h"
#include "TMacro.h"
#include <TTree.h>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;

int min (int a, int b){
    if (a>=b)
        return b;
    else
        return a;
}

string GetLocation(string str){    
    int i = str.rfind("_Slot_");
    string way = str.substr(0,i);  
    return way;
}

struct vectorsTree{
  vector<double> *FEBSN;
  vector<double> *SpillNum;
  vector<double> *SpillTime;
  vector<double> *SpillTimeGTrig;
  vector<double> *GTrigTag;
  vector<double> *GTrigTime;
  vector<double> *hitsChannel;
  vector<double> *hitAmpl;
  vector<double> hitAmplMatched;
  vector<double> *hitLGAmpl;
  vector<double> hitLGAmplMatched;
  vector<double> *hitLeadTime;
  vector<double> *hitTrailTime;
  vector<double> *hitTimeDif;
  vector<double> *hitTimefromSpill;
  vector<double> *SpillTrailTime;
  vector<double> *AsicTemperature;
  vector<double> *FPGATemperature;
  vector<double> *GlobalHV;
  vector<double> *BoardTemperature;
  vector<double> *BoardHumidity;
  vector<double> *HoldTimeStart;
  vector<double> *HoldTimeStop;
  vector<double> *HoldTimeStartNumber;
  vector<double> *HoldTimeStopNumber;
};

int main (){   
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
    rootFileInput+="_all.root";
    rootFileOutput+="_all_matching.root";
    cout << rootFileInput<<endl;
    cout << rootFileOutput<<endl;
    TFile *FileInput = new TFile(rootFileInput.c_str());
    
    TFile wfile(rootFileOutput.c_str(), "recreate");
    TTree* FEBtreer[65];
    
    vectorsTree FEB[NumberOfFEB];
    
    for (Int_t i=0;i<NumberOfFEB;i++){
        FEB[i].FEBSN=0;
        FEB[i].SpillNum=0;
        FEB[i].SpillTime=0;
        FEB[i].SpillTimeGTrig=0;
        FEB[i].GTrigTag=0;
        FEB[i].GTrigTime=0;
        FEB[i].hitsChannel=0;
        FEB[i].hitAmpl=0;
        FEB[i].hitLGAmpl=0;
        FEB[i].hitLeadTime=0;
        FEB[i].hitTrailTime=0;
        FEB[i].hitTimeDif=0;
        FEB[i].hitTimefromSpill=0;
        FEB[i].SpillTrailTime=0;
        FEB[i].AsicTemperature=0;
        FEB[i].FPGATemperature=0;
        FEB[i].GlobalHV=0;
        FEB[i].BoardTemperature=0;
        FEB[i].BoardHumidity=0;
        FEB[i].HoldTimeStart=0;
        FEB[i].HoldTimeStop=0;
        FEB[i].HoldTimeStartNumber=0;
        FEB[i].HoldTimeStopNumber=0;
    }
    
    TTree *FEBtree[NumberOfFEB];
    vector<int> FEBnumbers;
    Long64_t nentries[64];
    FEBnumbers.clear();
    
    ostringstream sFEBnum;
    string sFEB;
    for (Int_t ih=0; ih<NumberOfFEB; ih++){
        sFEBnum.str("");
        sFEBnum << ih;
        sFEB = "FEB_"+sFEBnum.str();
        FEBtree[ih] = (TTree*)FileInput->Get(sFEB.c_str());
        
        if ((TTree*)FileInput->Get(sFEB.c_str())){
            FEBnumbers.push_back(ih);
            std::cout<<sFEB<<" ";
            FEBtree[ih]->SetBranchAddress((sFEB+"_SN").c_str(),&FEB[ih].FEBSN);
            FEBtree[ih]->SetBranchAddress((sFEB+"_SpillTag").c_str(),&FEB[ih].SpillNum);
            FEBtree[ih]->SetBranchAddress((sFEB+"_SpillTime").c_str(),&FEB[ih].SpillTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_SpillTimeGTrig").c_str(),&FEB[ih].SpillTimeGTrig);
            FEBtree[ih]->SetBranchAddress((sFEB+"_GTrigTag").c_str(),&FEB[ih].GTrigTag);
            FEBtree[ih]->SetBranchAddress((sFEB+"_GTrigTime").c_str(),&FEB[ih].GTrigTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitsChannel").c_str(),&FEB[ih].hitsChannel);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitAmpl").c_str(),&FEB[ih].hitAmpl);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitLGAmpl").c_str(),&FEB[ih].hitLGAmpl);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitLeadTime").c_str(),&FEB[ih].hitLeadTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTrailTime").c_str(),&FEB[ih].hitTrailTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTimeDif").c_str(),&FEB[ih].hitTimeDif);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTimefromSpill").c_str(),&FEB[ih].hitTimefromSpill);
            FEBtree[ih]->SetBranchAddress((sFEB+"_SpillTrailTime").c_str(),&FEB[ih].SpillTrailTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_AsicTemperature").c_str(),&FEB[ih].AsicTemperature);
            FEBtree[ih]->SetBranchAddress((sFEB+"_FPGATemperature").c_str(),&FEB[ih].FPGATemperature);
            FEBtree[ih]->SetBranchAddress((sFEB+"_GlobalHV").c_str(),&FEB[ih].GlobalHV);
            FEBtree[ih]->SetBranchAddress((sFEB+"_BoardTemperature").c_str(),&FEB[ih].BoardTemperature);
            FEBtree[ih]->SetBranchAddress((sFEB+"_BoardHumidity").c_str(),&FEB[ih].BoardHumidity);

            FEBtree[ih]->SetBranchAddress((sFEB+"_HoldTimeStart").c_str(),&FEB[ih].HoldTimeStart);
            FEBtree[ih]->SetBranchAddress((sFEB+"_HoldTimeStop").c_str(),&FEB[ih].HoldTimeStop);
            FEBtree[ih]->SetBranchAddress((sFEB+"_HoldTimeStartNumber").c_str(),&FEB[ih].HoldTimeStartNumber);
            FEBtree[ih]->SetBranchAddress((sFEB+"_HoldTimeStopNumber").c_str(),&FEB[ih].HoldTimeStopNumber);


            nentries[ih] = FEBtree[ih]->GetEntries();
            cout<< "Number of spills "<< nentries[ih] <<endl;

            cout <<"FEB " <<ih<<" in process."<<endl;
            sFEBnum.str("");
            sFEBnum << ih;
            sFEB = "FEB_"+sFEBnum.str();
        
            FEBtreer[ih] = new TTree(sFEB.c_str(),sFEB.c_str()); 
    
            FEBtreer[ih]->Branch((sFEB+"_SN").c_str(),"vector<double>",&FEB[ih].FEBSN);
            FEBtreer[ih]->Branch((sFEB+"_SpillTag").c_str(),"vector<double>",&FEB[ih].SpillNum);
            FEBtreer[ih]->Branch((sFEB+"_SpillTime").c_str(),"vector<double>",&FEB[ih].SpillTime);
            FEBtreer[ih]->Branch((sFEB+"_SpillTimeGTrig").c_str(),"vector<double>",&FEB[ih].SpillTimeGTrig);
            FEBtreer[ih]->Branch((sFEB+"_GTrigTag").c_str(),"vector<double>",&FEB[ih].GTrigTag);
            FEBtreer[ih]->Branch((sFEB+"_GTrigTime").c_str(),"vector<double>",&FEB[ih].GTrigTime);
            FEBtreer[ih]->Branch((sFEB+"_hitsChannel").c_str(),"vector<double>",&FEB[ih].hitsChannel);
            FEBtreer[ih]->Branch((sFEB+"_hitAmpl").c_str(),"vector<double>",&FEB[ih].hitAmpl);
            FEBtreer[ih]->Branch((sFEB+"_hitAmplMatched").c_str(),"vector<double>",&FEB[ih].hitAmplMatched);
            FEBtreer[ih]->Branch((sFEB+"_hitLGAmpl").c_str(),"vector<double>",&FEB[ih].hitLGAmpl);
            FEBtreer[ih]->Branch((sFEB+"_hitLGAmplMatched").c_str(),"vector<double>",&FEB[ih].hitLGAmplMatched);
            FEBtreer[ih]->Branch((sFEB+"_hitLeadTime").c_str(),"vector<double>",&FEB[ih].hitLeadTime);
            FEBtreer[ih]->Branch((sFEB+"_hitTrailTime").c_str(),"vector<double>",&FEB[ih].hitTrailTime);
            FEBtreer[ih]->Branch((sFEB+"_hitTimeDif").c_str(),"vector<double>",&FEB[ih].hitTimeDif);
            FEBtreer[ih]->Branch((sFEB+"_hitTimefromSpill").c_str(),"vector<double>",&FEB[ih].hitTimefromSpill);
            FEBtreer[ih]->Branch((sFEB+"_SpillTrailTime").c_str(),"vector<double>",&FEB[ih].SpillTrailTime);
            FEBtreer[ih]->Branch((sFEB+"_AsicTemperature").c_str(),"vector<double>",&FEB[ih].AsicTemperature);
            FEBtreer[ih]->Branch((sFEB+"_FPGATemperature").c_str(),"vector<double>",&FEB[ih].FPGATemperature);
            FEBtreer[ih]->Branch((sFEB+"_GlobalHV").c_str(),"vector<double>",&FEB[ih].GlobalHV);
            FEBtreer[ih]->Branch((sFEB+"_BoardTemperature").c_str(),"vector<double>",&FEB[ih].BoardTemperature);
            FEBtreer[ih]->Branch((sFEB+"_BoardHumidity").c_str(),"vector<double>",&FEB[ih].BoardHumidity);
            FEBtreer[ih]->Branch((sFEB+"_HoldTimeStart").c_str(),"vector<double>",&FEB[ih].HoldTimeStart);
            FEBtreer[ih]->Branch((sFEB+"_HoldTimeStop").c_str(),"vector<double>",&FEB[ih].HoldTimeStop);
            FEBtreer[ih]->Branch((sFEB+"_HoldTimeStartNumber").c_str(),"vector<double>",&FEB[ih].HoldTimeStartNumber);
            FEBtreer[ih]->Branch((sFEB+"_HoldTimeStopNumber").c_str(),"vector<double>",&FEB[ih].HoldTimeStopNumber);

        
            std::vector<double> HitAmplForMathing[96][20];
            std::vector<double> HitLGAmplForMathing[96][20];
            std::vector<double> HitTimeForMathing[3];
            std::vector<double> HitToTForMathing[96][20][4];
            std::vector<double> L1HoldStartStop[2];
            std::vector<double> L1HoldStartStopNumber[2];
            
            
            for (int ik = 0; ik < nentries[ih]; ik++){
                for (int ich = 0; ich < 96; ++ich){
                    for (int im=0; im<20;im++){
                        HitToTForMathing[ich][im][0].clear();
                        HitToTForMathing[ich][im][1].clear();
                        HitToTForMathing[ich][im][2].clear();
                        HitToTForMathing[ich][im][3].clear();
                        HitAmplForMathing[ich][im].clear();
                        HitLGAmplForMathing[ich][im].clear();
                    }
                }
                for (int num = 0 ; num<2 ;num++){
                    HitTimeForMathing[num].clear();
                    L1HoldStartStop[num].clear();
                    L1HoldStartStopNumber[num].clear();
                }
                HitTimeForMathing[2].clear();
                
                
                FEBtree[ih]->GetEntry(ik);
                //cout<<"New spill N "<<FEB[ih].SpillNum->back()<< " " <<FEB[ih].HoldTimeStart->size()<<" "<<FEB[ih].HoldTimeStop->size()<<endl;
                if (FEB[ih].SpillTimeGTrig->back()!=-1 && FEB[ih].HoldTimeStart->size() && FEB[ih].HoldTimeStop->size()){
                    if (FEB[ih].HoldTimeStart->at(0) > FEB[ih].HoldTimeStop->at(0)){
                        L1HoldStartStop[0].push_back(0);
                        L1HoldStartStop[1].push_back(FEB[ih].HoldTimeStop->at(0));
                    } else {
                        L1HoldStartStop[0].push_back(0);
                        L1HoldStartStop[1].push_back(FEB[ih].HoldTimeStart->at(0));
                    }
                    for ( Int_t iev=0; iev < FEB[ih].HoldTimeStart->size(); iev++){
                        L1HoldStartStop[0].push_back(FEB[ih].HoldTimeStart->at(iev));
                        L1HoldStartStopNumber[0].push_back(FEB[ih].HoldTimeStopNumber->at(iev));
                        bool L1HoldStopEx = false;

                        for (int i=0; i < FEB[ih].HoldTimeStop->size(); i++){
                            if (FEB[ih].HoldTimeStop->at(i) > L1HoldStartStop[0].back() 
                            && (FEB[ih].HoldTimeStop->at(i) - L1HoldStartStop[0].back())<=4004){
                                L1HoldStartStop[1].push_back(FEB[ih].HoldTimeStop->at(i));
                                L1HoldStopEx = true;
                                break;
                            }
                        } 
                        if (!L1HoldStopEx){
                            if (iev + 1 < FEB[ih].HoldTimeStart->size() && (FEB[ih].HoldTimeStart->at(iev + 1) - L1HoldStartStop[0].back()) <= 4004){
                            L1HoldStartStop[1].push_back( FEB[ih].HoldTimeStart->at(iev + 1));
                            } else {
                            L1HoldStartStop[1].push_back(L1HoldStartStop[0].back() + 4024);
                            } 
                        }
                    }
                    auto itMax = max_element(FEB[ih].hitTimefromSpill->begin(),FEB[ih].hitTimefromSpill->end());

                    if (L1HoldStartStop[1].back() <= *itMax){
                        L1HoldStartStop[0].push_back(L1HoldStartStop[1].back());
                        L1HoldStartStop[1].push_back(*itMax);
                    }

                    if (L1HoldStartStop[0].size()!=L1HoldStartStop[1].size()){
                        //cout <<"New spill N "<<FEB[ih].SpillNum->back()<<" "<<L1HoldStartStop[0].size()<<" "<<L1HoldStartStop[1].size() <<endl;
                        for (int i = 0; i<L1HoldStartStop[0].size(); i++){
                            cout << L1HoldStartStop[0].at(i) << " ";
                        }
                        cout <<endl;
                        for (int i = 0; i<L1HoldStartStop[1].size(); i++){
                            cout << L1HoldStartStop[1].at(i) << " ";
                        }
                        cout <<endl<<endl;
                        return -1;
                    }

                    for ( Int_t iev=0; iev < FEB[ih].FEBSN->size(); iev++){
                        HitTimeForMathing[0].push_back(FEB[ih].hitsChannel->at(iev));
                        HitTimeForMathing[2].push_back(FEB[ih].hitTimefromSpill->at(iev));
                        int L1Num = -1 ;
                        int shift = 0;
                        for (int i = 0; i<L1HoldStartStop[0].size(); i++){
                            if ( i + 1 < L1HoldStartStop[0].size()){
                                if (HitTimeForMathing[2].back() >= L1HoldStartStop[0].at(i) - shift && HitTimeForMathing[2].back() <= L1HoldStartStop[0].at(i+1) + shift){
                                    L1Num = i;
                                    HitToTForMathing[(int)FEB[ih].hitsChannel->at(iev)][i][0].push_back(FEB[ih].hitTimeDif->at(iev));
                                    if (HitTimeForMathing[2].back() >= L1HoldStartStop[0].at(i) - shift && HitTimeForMathing[2].back() <= L1HoldStartStop[1].at(i) + shift) {
                                        HitToTForMathing[(int)FEB[ih].hitsChannel->at(iev)][i][3].push_back(FEB[ih].hitTimeDif->at(iev));
                                    } else {
                                        HitToTForMathing[(int)FEB[ih].hitsChannel->at(iev)][i][3].push_back(FEB[ih].hitTimeDif->at(iev));
                                    }
                                    break;
                                } 
                            } else {
                                if (HitTimeForMathing[2].back() >= L1HoldStartStop[0].at(i) - shift && HitTimeForMathing[2].back() <= L1HoldStartStop[1].at(i) + shift){
                                    L1Num = i;
                                    HitToTForMathing[(int)FEB[ih].hitsChannel->at(iev)][i][0].push_back(FEB[ih].hitTimeDif->at(iev));
                                    HitToTForMathing[(int)FEB[ih].hitsChannel->at(iev)][i][3].push_back(FEB[ih].hitTimeDif->at(iev));
                                    break;
                                } 
                            }
                        }
                        if (L1Num == - 1){
                            cout <<"Error in Spill "<< FEB[ih].SpillNum->back()<<" out "<< HitTimeForMathing[2].back()<<endl;
                            return -1;
                        }
                        HitTimeForMathing[1].push_back(L1Num);
                        if (FEB[ih].hitAmpl->at(iev)>0){
                            HitAmplForMathing[(int)FEB[ih].hitsChannel->at(iev)][L1Num].push_back(FEB[ih].hitAmpl->at(iev));
                            HitLGAmplForMathing[(int)FEB[ih].hitsChannel->at(iev)][L1Num].push_back(FEB[ih].hitLGAmpl->at(iev));
                        }
                    }

                    for (int ich = 0; ich < 96; ++ich){
                        for (int im = 0; im < L1HoldStartStop[0].size(); ++im){
                            if (HitAmplForMathing[ich][im].size() && HitToTForMathing[ich][im][3].size()){
                                auto it = max_element(std::begin(HitToTForMathing[ich][im][3]), std::end(HitToTForMathing[ich][im][3]));
                                //cout <<"Spill "<< FEB[ih].SpillNum->back()<<" "<< *it << " -- max " << std::distance(std::begin(HitToTForMathing[ich][im][3]), it)<<" -- position ";
                                for (int i = 0; i < HitToTForMathing[ich][im][0].size(); ++i){
                                    //cout << HitToTForMathing[ich][im][0].at(i)<< " ";
                                    if ( i == std::distance(std::begin(HitToTForMathing[ich][im][3]), it)){
                                        HitToTForMathing[ich][im][1].push_back(HitAmplForMathing[ich][im].at(0));
                                        HitToTForMathing[ich][im][2].push_back(HitLGAmplForMathing[ich][im].at(0));
                                        //cout << "<- that ";
                                    }   else {
                                        HitToTForMathing[ich][im][1].push_back(0);
                                        HitToTForMathing[ich][im][2].push_back(0);
                                    }
                                }
                                 //cout <<" ---- ch"<< ich <<" Amp:"<<HitAmplForMathing[ich][im].at(0)<< " ToT:"<<HitToTForMathing[ich][im][0].size() <<" L1Hold Number: "<<im << endl;

                            } else {
                                for (int i = 0; i < HitToTForMathing[ich][im][0].size(); ++i){
                                    HitToTForMathing[ich][im][1].push_back(0);
                                    HitToTForMathing[ich][im][2].push_back(0);
                                }
                            }
                        }  
                    }
                    //cout<< "Fill" <<endl;
                    for (int in = 0; in < FEB[ih].FEBSN->size(); in++){
                        int ch = (int)HitTimeForMathing[0].at(in);
                        int L1Hold = (int)HitTimeForMathing[1].at(in);
                        FEB[ih].hitAmplMatched.push_back( HitToTForMathing[ch][L1Hold][1].front());
                        FEB[ih].hitLGAmplMatched.push_back( HitToTForMathing[ch][L1Hold][2].front());
                        HitToTForMathing[ch][L1Hold][1].erase(HitToTForMathing[ch][L1Hold][1].begin());
                        HitToTForMathing[ch][L1Hold][2].erase(HitToTForMathing[ch][L1Hold][2].begin());
                    }
                } else {
                    for(int i = 0; i < FEB[ih].SpillTimeGTrig->size(); i++){
                        FEB[ih].hitLGAmplMatched.push_back(-1);
                        FEB[ih].hitAmplMatched.push_back(-1);
                    }
                }

                FEBtreer[ih]->Fill();
        
                FEB[ih].FEBSN->clear();
                FEB[ih].SpillNum->clear();
                FEB[ih].SpillTime->clear();
                FEB[ih].SpillTimeGTrig->clear();
                FEB[ih].hitsChannel->clear();
                FEB[ih].hitAmpl->clear();
                FEB[ih].hitAmplMatched.clear();
                FEB[ih].hitLeadTime->clear();
                FEB[ih].hitTrailTime->clear();
                FEB[ih].hitTimeDif->clear();
                FEB[ih].GTrigTag->clear();
                FEB[ih].GTrigTime->clear();
                FEB[ih].hitLGAmpl->clear();
                FEB[ih].hitLGAmplMatched.clear();
                FEB[ih].hitTimefromSpill->clear();
                FEB[ih].SpillTrailTime->clear();
                FEB[ih].AsicTemperature->clear();
                FEB[ih].FPGATemperature->clear();
                FEB[ih].GlobalHV->clear();
                FEB[ih].BoardTemperature->clear();
                FEB[ih].BoardHumidity->clear();
                FEB[ih].HoldTimeStart->clear();
                FEB[ih].HoldTimeStop->clear();
                FEB[ih].HoldTimeStartNumber->clear();
                FEB[ih].HoldTimeStopNumber->clear();
            }
            //cout << FEBtree[ih]->GetEntries()<<endl;
            FEBtreer[ih]-> Write("",TObject::kOverwrite);
            FEBtreer[ih]->Delete();

        }
    }
    FileInput->Close();
    wfile.Close();
    return 0;
}

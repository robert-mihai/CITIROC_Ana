#include <stdio.h>
#include <string.h>
#include <string>
#include <exception>
#include <fstream>
#include <vector>
#include "TFile.h"
#include "TDirectory.h"
#include "TSystem.h"
#include "TMacro.h"
#include <TTree.h>
#include <iostream>
#include "TClonesArray.h"
#include "TObject.h"
#include "Rtypes.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TStyle.h"

using namespace std;

//Function to get the directory of the input file in order to create output file in same directory
string GetLocation(string str)
{
  int i = str.rfind("_all");
  string way = str.substr(0,i);
  return way;
}

//Function to get the directory of the input file in order to create output files in same directory
string GetDir(string str)
{
  int i = str.rfind("/");
  string way = str.substr(0,i);
  return way;
}

//Function to check that the input file is indeed a _all_reconstructed.root file
bool CheckFile(string str)
{
  if (str.find("_all.root") != string::npos) return 0;
  return 1;
}

struct vectorsTree
{
  vector<double> *FEBSN;
  vector<double> *SpillTag;
  vector<double> *GTrigTag;
  vector<double> *GTrigTime;
  vector<double> *hitsChannel;
  vector<double> *hitAmpl;
  vector<double> *hitLGAmpl;
  vector<double> *hitLeadTime;
  vector<double> *hitTrailTime;
  vector<double> *hitTimeDif;
  vector<double> *SpillTime;
  vector<double> *SpillTimeGTrig;
  vector<double> *hitTimefromSpill;
  vector<double> *SpillTrailTime;
  vector<double> *AsicTemperature;
  vector<double> *FPGATemperature;
  vector<double> *GlobalHV;
  vector<double> *BoardTemperature;
  vector<double> *BoardHumidity;

};


int main (int argc, char **argv)
{
  //if (argc != 2) { printf("Enter source _all.root file    ./ButterflyPlots inputfile \n"); return EXIT_FAILURE; }
  //string sFileName(argv[1]);
  string sFileName ;
  vector<string> vFileNames;
  ifstream fList("all_root.list");
  while (!fList.eof()) {
    fList >> sFileName;
    cout << "sFileName: " <<sFileName << endl;
    vFileNames.push_back(sFileName);
  }

  //    vFileNames.pop_back();

  for (int i = 0; i< vFileNames.size();i++){
    cout << " The following file: " << vFileNames.at(i)<<endl;
  }

  //if (CheckFile(sFileName) == 1) { printf("Source must be an _all.root file \n"); return EXIT_FAILURE; }

  // Creating Histograms and Canvases_________________________________________________________________
  TH1D *Amplitude = new TH1D ("Ch","",100,0,100);
  Amplitude->SetTitle(" Amplitude of monitor hit (ToT) ; Amplitude [2.5 ns]; Counts");
  //TH1D *proximity = new TH1D("prox","",63,-31,32);
  TH1D *proximity = new TH1D("prox","",60,-30,30);
  proximity->SetTitle("channel proximity;Channel distance to monitor hit;Counts");
  TH1D *proximity_norm = new TH1D("prox","",32,0,32);
  proximity_norm->SetTitle("channel proximity;Channel distance to monitor hit;Counts");

  TH1D *baseline = new TH1D ("NBaseline_noise","",100,0,100);
  baseline->SetTitle("N baseline noise per monitor hit; N baseline noise per monitor hit;Counts");
  TH2D * bl_Amplitude = new TH2D("NB_Ch","",100,0,50,100,0,100);
  bl_Amplitude->SetTitle("N baseline noise vs monitor hit Amplitude;Monitor hit ToT [2.5 ns];N baseline noise");
  //TH2D *Amplitude_proximity = new TH2D("Ch_prox","",63,-31,32,100,0,1);
  TH2D *Amplitude_proximity = new TH2D("Ch_prox","",60,-30,30,100,0,1);
  Amplitude_proximity->SetTitle("Amplitude ratio vs channel proximity;Channel distance to monitor hit;Amplitude ratio");
  //TH2D *time_proximity = new TH2D("T_prox","",63,-31,32,200,-100,100);
  TH2D * time_proximity = new TH2D("T_prox","",60,-30,30,100,0,100);
  time_proximity->SetTitle("time delay vs channel proximity;Channel distance to monitor hit;Hit time delay [#times 2.5 ns]");
  TH2D *Ch0_behaviour = new TH2D("Ch0","",200,-100,100,300,0,300);
  Ch0_behaviour->SetTitle("Monitor Hit ch behaviour; Hit time delay; Amplitude [2.5 ns]" );

  TH2D *Channels = new TH2D("Channel_map","",96,0,96,96,0,96);
  Channels->SetTitle("Channel Map; Monitor hit channel; Noise hit channel" );

  TCanvas *c1 = new TCanvas("c1","c1", 2000, 900);
  TCanvas *c2 = new TCanvas("c2","c2", 800, 600);
  //__________________________________________________________________________________________________

  string foutDir;
  string createFolder;
  ostringstream foutPNGnum;
  ostringstream foutBunchnum;
  string foutPNG;
  for (vector<string>::iterator itFileName=vFileNames.begin(); itFileName != vFileNames.end(); itFileName++){
    sFileName = *itFileName;
    TFile *FileInput=new TFile(sFileName.c_str(),"read");
    cout<<"Reading "<<sFileName<<endl;

    //string rootFileOutput=GetLocation(sFileName.c_str());
    //rootFileOutput+="_ButterflyPlots.root";

    //TFile wfile(rootFileOutput.c_str(), "recreate");
    //cout<<rootFileOutput<<endl;

    // Specify directory for output Event Display PNG
    foutDir = GetDir(sFileName) + "/Baseline_noise_2/";
    createFolder ="mkdir -p ";
    createFolder +=  foutDir.c_str();
    system(createFolder.c_str());



    vectorsTree FEB;

    FEB.FEBSN=0;
    FEB.SpillTag=0;
    FEB.hitsChannel=0;
    FEB.hitAmpl=0;
    FEB.hitLeadTime=0;
    FEB.GTrigTag=0;
    FEB.GTrigTime=0;
    FEB.hitLGAmpl=0;
    FEB.hitTrailTime=0;
    FEB.hitTimeDif=0;
    FEB.SpillTime=0;
    FEB.SpillTimeGTrig=0;
    FEB.hitTimefromSpill=0;
    FEB.SpillTrailTime=0;
    FEB.AsicTemperature=0;
    FEB.FPGATemperature=0;
    FEB.GlobalHV=0;
    FEB.BoardTemperature=0;
    FEB.BoardHumidity=0;


    string sFEB = "FEB_1";
    TTree *FEBtree = (TTree*)FileInput->Get(sFEB.c_str());

    FEBtree->SetBranchAddress((sFEB+"_SN").c_str(),&FEB.FEBSN);
    FEBtree->SetBranchAddress((sFEB+"_SpillTag").c_str(),&FEB.SpillTag);
    FEBtree->SetBranchAddress((sFEB+"_GTrigTag").c_str(),&FEB.GTrigTag);
    FEBtree->SetBranchAddress((sFEB+"_GTrigTime").c_str(),&FEB.GTrigTime);
    FEBtree->SetBranchAddress((sFEB+"_hitsChannel").c_str(),&FEB.hitsChannel);
    FEBtree->SetBranchAddress((sFEB+"_hitAmpl").c_str(),&FEB.hitAmpl);
    FEBtree->SetBranchAddress((sFEB+"_hitLGAmpl").c_str(),&FEB.hitLGAmpl);
    FEBtree->SetBranchAddress((sFEB+"_hitLeadTime").c_str(),&FEB.hitLeadTime);
    FEBtree->SetBranchAddress((sFEB+"_hitTrailTime").c_str(),&FEB.hitTrailTime);
    FEBtree->SetBranchAddress((sFEB+"_hitTimeDif").c_str(),&FEB.hitTimeDif);
    FEBtree->SetBranchAddress((sFEB+"_SpillTime").c_str(),&FEB.SpillTime);
    FEBtree->SetBranchAddress((sFEB+"_SpillTimeGTrig").c_str(),&FEB.SpillTimeGTrig);
    FEBtree->SetBranchAddress((sFEB+"_hitTimefromSpill").c_str(),&FEB.hitTimefromSpill);
    FEBtree->SetBranchAddress((sFEB+"_SpillTrailTime").c_str(),&FEB.SpillTrailTime);
    FEBtree->SetBranchAddress((sFEB+"_AsicTemperature").c_str(),&FEB.AsicTemperature);
    FEBtree->SetBranchAddress((sFEB+"_FPGATemperature").c_str(),&FEB.FPGATemperature);
    FEBtree->SetBranchAddress((sFEB+"_GlobalHV").c_str(),&FEB.GlobalHV);
    FEBtree->SetBranchAddress((sFEB+"_BoardTemperature").c_str(),&FEB.BoardTemperature);
    FEBtree->SetBranchAddress((sFEB+"_BoardHumidity").c_str(),&FEB.BoardHumidity);

    cout<< "Number of Spills "<< FEBtree->GetEntries() <<endl;




    //loop over spills

    for (Int_t Spill = 0; Spill<FEBtree->GetEntries(); Spill++){
      FEBtree->GetEntry(Spill);
      if(FEB.SpillTag->empty()){
	cout<<"EMPTY SPILL"<<endl;
	continue;
      }



      Int_t Spilltag = FEB.SpillTag->back();
      //cout << "_Getting Spill Number " << Spilltag  << " of "<<FEBtree->GetEntries()<<"..."<<endl;

      int count_bl=0;
      bool notmaximum =false;

      //loop over spill hits to find the one with max amplitude
      for (Int_t hit1 = 0; hit1<FEB.SpillTag->size(); hit1++){
	if (FEB.SpillTag->size() >11) continue;
	//if ( 25 > FEB.hitTimeDif->at(hit1) || FEB.hitTimeDif->at(hit1) > 50  ) continue;
	
	//if ( FEB.hitTimeDif->at(hit1) < 25 ) continue;
	if ( FEB.hitTimeDif->at(hit1) >  50) continue;
	
	count_bl=0;
	notmaximum = false;
	//std::cout << "FEB.SpillTag->size() = " << FEB.SpillTag->size() << std::endl;
	//check if hit1 is maximum Amplitude on the ASIC
	
	/*	for (Int_t hit_check = 0; hit_check<FEB.SpillTag->size(); hit_check++){
		if (hit_check == hit1) continue;
	  
	  if (FEB.hitsChannel->at(hit1) != 64)    notmaximum = true;
	  }
	
	if (notmaximum) continue;
	*/
	
	if (FEB.hitsChannel->at(hit1) != 64) continue;	
	for(int hit2=0; hit2<FEB.SpillTag->size(); hit2++){
	  if (hit2 == hit1) continue;
	  
	  
	  if (FEB.hitTimefromSpill->at(hit2)-FEB.hitTimefromSpill->at(hit1)>0 && FEB.hitTimefromSpill->at(hit2)-FEB.hitTimefromSpill->at(hit1)<100){
	    count_bl ++;
	    Amplitude_proximity->Fill(FEB.hitsChannel->at(hit2)-FEB.hitsChannel->at(hit1),FEB.hitTimeDif->at(hit2)/FEB.hitTimeDif->at(hit1));
	    
	    time_proximity->Fill(FEB.hitsChannel->at(hit2)-FEB.hitsChannel->at(hit1),FEB.hitTimefromSpill->at(hit2)-FEB.hitTimefromSpill->at(hit1));
	    proximity->Fill(FEB.hitsChannel->at(hit2)-FEB.hitsChannel->at(hit1));
	    proximity_norm->Fill(abs(FEB.hitsChannel->at(hit2)-FEB.hitsChannel->at(hit1)));
	    Channels->Fill(FEB.hitsChannel->at(hit1),FEB.hitsChannel->at(hit2));
	    if(FEB.hitsChannel->at(hit2)-FEB.hitsChannel->at(hit1)==0){
	      Ch0_behaviour->Fill(FEB.hitTimefromSpill->at(hit2)-FEB.hitTimefromSpill->at(hit1),FEB.hitTimeDif->at(hit2));
	    }
	  }
	}
	
	Amplitude->Fill(FEB.hitTimeDif->at(hit1));
	baseline->Fill(count_bl);//count_bl is the number of hits which correspond to the 2.5 ns between two hits condition
	
	bl_Amplitude->Fill(FEB.hitTimeDif->at(hit1),count_bl);
	
      }
    }
    FileInput->Close();
  }

  proximity_norm->Scale(1/Amplitude->GetEntries());
  c2->cd();
  //proximity_norm->Draw("hist");
  //time_proximity->Draw("colz");
  Channels->Draw("colz");
  gPad -> SetLogz();
  //Ch0_behaviour->Draw("colz");


  c1->Divide(3,2);
  c1->cd(1);
  Amplitude->Draw("hist");
  c1->cd(2);
  baseline->Draw("hist");// y-axis: spills. x-axis: hit1-hit2_time < 2.5 ns
  gPad -> SetLogy();
  c1->cd(3);
  bl_Amplitude->Draw("colz");// the time difference for maximum amplitude hit vs
  gPad -> SetLogz();
  c1->cd(4);
  Amplitude_proximity->Draw("colz");
  gPad -> SetLogz();
  c1->cd(5);
  time_proximity->Draw("colz");
  gPad -> SetLogz();
  c1->cd(6);
  proximity->Draw("hist");

  foutPNG = foutDir + "crosstalk_all_ver_above300pe_All.png";
  c1->SaveAs(foutPNG.c_str());
  //foutPNG = foutDir + "crosstalk_ratiobelow20per_above300pe_All.C";
  //c1->SaveAs(foutPNG.c_str());
  foutPNG = foutDir + "crosstalk_all_ver_above300pe_channel_map.png";
  c2->SaveAs(foutPNG.c_str());
  foutPNG = foutDir + "crosstalk_all_ver_above300pe_channel_map.C";
  c2->SaveAs(foutPNG.c_str());

  cout<<"_Plotting 100% done"<<endl;



  return 0;

}

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

string GetLocation(string str)
{
     
    int i = str.rfind("_Slot_");
    string way = str.substr(0,i);  
    return way;
};

void gainPar (string sFEB, std::vector<double>* vec){
	ifstream gain(sFEB.c_str());
    cout << "Taking fit parrameters at "<< sFEB <<endl;
    if(!gain.is_open()) 
    {
      cout << Form("File B2-connection.map does not exist.") << '\n';
      exit(0);
    }
    int ch=0;
    if (gain.good()){
        string str;
        while(getline(gain, str)) {
            istringstream ss(str);
            double num;
            ss>>ch;
            while(ss >> num){
              vec[ch].push_back(num);;
            }
          }
        }
      gain.close();
}

bool ChannelExist(int FEBnum, int chNum){
    bool ChEx = false;
    if (FEBnum == 5 || FEBnum == 53){
        ChEx = true;
    } else if (FEBnum == 13 || FEBnum == 20 || FEBnum == 28 || FEBnum == 36 || FEBnum == 44 || FEBnum == 61 ){
        if ( chNum <64 ) {
            ChEx = true;
        }
    } else if (FEBnum == 21 || FEBnum == 29) {
        if ( (chNum < 8 && chNum != 3) || (chNum > 31 && chNum < 39)){
            ChEx = true;
        }
    } else {
        if ( chNum < 95 ){
            ChEx = true;
        }
    }
    return ChEx;
}

bool ChannelVer(int FEBnum){
    bool ChVer = false;
    if(FEBnum == 5 || FEBnum == 53 || FEBnum == 13 || FEBnum == 20 || FEBnum == 28 || FEBnum == 36 || FEBnum == 44 || FEBnum == 61 ) {
        ChVer = true;
    }
    return ChVer;
}


int main ()
{
    int FEBs[46] = {0,1,2,3,4,5,8,9,10,11,12,13,16,17,18,19,20,21,24,25,26,27,28,29,32,33,34,35,36,40,41,42,43,44,48,49,50,51,52,53,56,57,58,59,60,61};
    
    string rootFileOutput;
    rootFileOutput="../root_Calibration.root";
    TFile wfile(rootFileOutput.c_str(), "recreate");
    TH1F *GainSt[64][96];
    TH1F *GainResult = new TH1F("GainDiff","GainDiff",  100, -0.3, +0.3);
    TH1F *GainVert = new TH1F("GainVertical","GainVertical",  100, -0.3, +0.3);
    TH1F *GainHor = new TH1F("GainHor","GainHor",  100, -0.3, +0.3);

    TH1F *GainFirstChannels = new TH1F("GainBottomChannels","GainBottomChannels",  100, -0.3, +0.3);
    TH1F *GainLastChannels = new TH1F("GainTopChannels","GainTopChannels",  100, -0.3, +0.3);

    TF1 *f = new TF1("fit","gaus",-0.1,0.1);

    TF1 *f1 = new TF1("fit1","gaus",-0.03,0.0);
    TF1 *f2 = new TF1("fit2","gaus", 0.0,0.03);    

    ostringstream sFEBnum;
    ostringstream sMCRnum;
    ostringstream sSlotnum;
    ostringstream sChnum;
    string sFEB, sCh;
    string sFeb13Nov, sFeb18Nov, sFeb20Nov, sFeb27Nov;
    string sFeb4Dec;
    string sFeb10Jan, sFeb14Jan, sFeb16Jan, sFeb22Jan, sFeb27Jan;
    string oFEB;
    string sFeb5Feb;
    
    int Slot;
    int MCR;
    
    int numOfCalib = 11;
    vector<double> vgain[numOfCalib][96];
    for (int k = 0; k < numOfCalib; k++){
     	for (int ich = 0; ich<96; ich++){
     		vgain[k][ich].clear();
     	}
    }

    for (int iFEB = 0; iFEB<46; iFEB++) {
        Slot = FEBs[iFEB] % 8;
        MCR = FEBs[iFEB] / 8;
        sFEBnum.str("");
        sMCRnum.str("");
        sSlotnum.str("");
        sFEBnum << FEBs[iFEB];
        sMCRnum << MCR;
        sSlotnum << Slot;
        sFEB = "FEB_"+sFEBnum.str();

        sFeb13Nov = "../gain_data/temperature/Nov/13Nov_Tin24_3_Tout_27_0/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        sFeb18Nov = "../gain_data/temperature/Nov/18Nov_Tin27_2_Tout_24_2/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        sFeb20Nov = "../gain_data/temperature/Nov/20Nov_Tin27_4_Tout_24_1/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        sFeb27Nov = "../gain_data/temperature/Nov/27Nov/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        sFeb4Dec  = "../gain_data/temperature/4Dec/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        sFeb10Jan = "../gain_data/temperature/Jan/10Jan_Tin_23_2_Tout_25_3/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        sFeb14Jan = "../gain_data/temperature/Jan/14Jan_Tin25_8_Tout_23_6/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        sFeb16Jan = "../gain_data/temperature/Jan/16Jan_Tin_25_1_Tout_23_7/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        sFeb22Jan = "../gain_data/temperature/Jan/22Jan_Tin_25_3_Tout_23_6/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        sFeb27Jan = "../gain_data/temperature/Jan/27Jan_Tin_25_6_Tout_23_9/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        sFeb5Feb  = "../gain_data/temperature/Feb/5Feb_Tin_26_7_Tout_24_2/MCR_"+ sMCRnum.str() + "_Slot_" + sSlotnum.str() + "_gain.txt";
        gainPar(sFeb13Nov, vgain[0]);
        gainPar(sFeb18Nov, vgain[1]);
        gainPar(sFeb20Nov, vgain[2]);
        gainPar(sFeb27Nov, vgain[3]);
        gainPar(sFeb4Dec,  vgain[4]);
        gainPar(sFeb10Jan, vgain[5]);
        gainPar(sFeb14Jan, vgain[6]);
        gainPar(sFeb16Jan, vgain[7]);
        gainPar(sFeb22Jan, vgain[8]);
        gainPar(sFeb27Jan, vgain[9]);
        gainPar(sFeb5Feb, vgain[10]);

        TDirectory *FEB_Gain = wfile.mkdir(sFEB.c_str());

        for (Int_t ich=0; ich < 96;ich++){
        	if (ChannelExist(iFEB,ich)){
            	sChnum.str("");
            	sChnum << ich;
            	sCh =  "FEB_" + sFEBnum.str() + "_channel_" + sChnum.str();
            	GainSt[FEBs[iFEB]][ich]=new TH1F(sCh.c_str(),sCh.c_str(),  60, -0.3, +0.3);
            	double avr = 0;
            	for (int gainEnt = 0; gainEnt< numOfCalib; gainEnt++){
            		avr += vgain[gainEnt][ich].front();
            	}
            	avr = avr / numOfCalib;

            	for (int gainEnt = 0; gainEnt< numOfCalib; gainEnt++){
            		GainSt[FEBs[iFEB]][ich]->Fill((vgain[gainEnt][ich].front() - avr)/avr,1);
            		GainResult->Fill((vgain[gainEnt][ich].front() - avr)/avr,1);
                    if (ich < 4 && !ChannelVer(iFEB)){
                        GainFirstChannels->Fill((vgain[gainEnt][ich].front() - avr)/avr,1);
                    }
                    if (ich > 90 && !ChannelVer(iFEB)){
                        GainLastChannels->Fill((vgain[gainEnt][ich].front() - avr)/avr,1);
                    }
                    if (ChannelVer(iFEB)){
                        GainVert->Fill((vgain[gainEnt][ich].front() - avr)/avr,1);
                    } else {
                       GainHor->Fill((vgain[gainEnt][ich].front() - avr)/avr,1);
                    }
            	}
            	FEB_Gain->cd();
            	GainSt[FEBs[iFEB]][ich]->Write();
            	delete GainSt[FEBs[iFEB]][ich];

            }
        }
        for (int k = 0; k < numOfCalib; k++){
     		for (int ich = 0; ich<96; ich++){
     			vgain[k][ich].clear();
     		}
   		}
  }
  wfile.cd();
  GainResult->Fit("fit","MQER");
  GainHor->Fit("fit","MQER");
  GainVert->Fit("fit","MQER");
  GainResult->Write();
  GainVert->Write();
  GainHor->Write();
  GainFirstChannels->Fit("fit1","MQER");
  GainFirstChannels->Fit("fit2","MQER+");
  GainFirstChannels->Write();
  GainLastChannels->Fit("fit","MQER");
  GainLastChannels->Write();
  delete GainResult;
  delete GainHor;
  delete GainVert;
  wfile.Close();
  return 0;
}
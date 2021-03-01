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
    rootFileOutput="../root_Pedestals.root";
    TFile wfile(rootFileOutput.c_str(), "recreate");

    TH1F *PedestalsResult = new TH1F("PedestalPosition","PedestalPosition",  100, -100, +150);
    TH1F *PedestalsErrors = new TH1F("PedestalsErrors","PedestalsErrors",  100, -10, +12);

    TF1 *f = new TF1("fit","gaus",-0.1,0.1);

    ostringstream sFEBnum;
    ostringstream sMCRnum;
    ostringstream sSlotnum;
    ostringstream sChnum;
    string sFEB, sCh;
    string Pedestals,fouttxt;
    
    vector<double> vgain[64][96];
    for (int ich = 0; ich<96; ich++){
      for(int k = 0; k<64;k++){
        vgain[k][ich].clear();
      }
    }

    Pedestals = "../gain_data/pedestal/ListofPeds.txt";
        
    ifstream gain(Pedestals.c_str());
    int ch  = 0;
    int feb = 0;
    string str;
    while(getline(gain, str)) {
        istringstream ss(str);
        double num;
        ss>>feb;
        ss>>ch;
        while(ss >> num){
          if(ChannelExist(feb,ch))
            vgain[feb][ch].push_back(num);
            cout << vgain[feb][ch].back()<< " ";
        }
        cout <<endl;
    }
    gain.close();

    for (int k=0; k<64;k++){
      sFEBnum.str("");
      sFEBnum << k;
      fouttxt = "../gain_data/pedestal/FEB_" + sFEBnum.str() + "_Pedestals.txt";
      ofstream foutDat(fouttxt.c_str());
      for (int ich = 0; ich<96; ich++){
        if (ChannelExist(k,ich)){
          foutDat << ich << " "<< vgain[k][ich].at(0)<<" "<<vgain[k][ich].at(1)<<endl;
          if (vgain[k][ich].at(0)!=0 && vgain[k][ich].at(0)!=0){
            PedestalsResult->Fill(vgain[k][ich].at(0), 1);
            PedestalsErrors->Fill(vgain[k][ich].at(1), 1);
          }
        }
      }
      foutDat.close();
    }
  PedestalsResult->Write();
  PedestalsErrors->Write();
  wfile.Close();
  return 0;
}
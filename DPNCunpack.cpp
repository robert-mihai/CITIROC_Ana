/* This file is part of BabyMINDdaq software package. This software
 * package is designed for internal use for the Baby MIND detector
 * collaboration and is tailored for this use primarily.
 *
 * BabyMINDdaq is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BabyMINDdaq is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BabyMINDdaq.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

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
#include "MDfragmentBM.h"
#include "MDpartEventBM.h"
#include "MDargumentHandler.h"
#include "MDdataFile.h"

using namespace std;

string GetLocation(string str)
{
     
    int i = str.rfind("_Slot_");
    string way = str.substr(0,i);  
    return way;
}

struct vectorsTree
{
  vector<double> FEBSN;
  vector<double> SpillNum;
  vector<double> SpillTime;
  vector<double> SpillTimeGTrig;
  vector<double> GTrigTag;
  vector<double> GTrigTime;
  vector<double> hitsChannel;
  vector<double> hitAmpl;
  vector<double> hitLGAmpl;
  vector<double> hitLeadTime;
  vector<double> hitTrailTime;
  vector<double> hitTimeDif;
  vector<double> hitTimefromSpill;
  vector<double> SpillTrailTime;
 // vector<double> SpillTemperature;
  vector<double> AsicTemperature;
  vector<double> FPGATemperature;
  vector<double> GlobalHV;
  vector<double> BoardTemperature;
  vector<double> BoardHumidity;

  vector<double> HoldTimeStart;
  vector<double> HoldTimeStop;
  vector<double> HoldTimeStartNumber;
  vector<double> HoldTimeStopNumber;
};



char *dataBuff;
uint32_t* dataPtr;

int main( int argc, char **argv ) {
 string sFileName;
  
  vector<string> vFileNames;
  ifstream fList("febs_files_list.list");
  while (!fList.eof()) {
    fList >> sFileName;
    //cout << sFileName << endl;
    vFileNames.push_back(sFileName);
  }
  vFileNames.pop_back();
  
  for (int i = 0; i< vFileNames.size();i++){
    cout << vFileNames.at(i)<<endl;
  }
  
   vectorsTree FEB[65];
   
   string rootFileOutput=GetLocation(vFileNames[0].c_str());
  rootFileOutput+="_all.root";
  cout << rootFileOutput<<endl;
  
  TFile rfile(rootFileOutput.c_str(), "recreate");
  
  TTree* FEBtree[65];
  
  ostringstream sFEBnum;
  string sFEB;

  for (Int_t ih=0; ih<=64; ih++) {
        sFEBnum.str("");
        sFEBnum << ih;
        sFEB = "FEB_"+sFEBnum.str();
        FEBtree[ih] = new TTree(sFEB.c_str(),sFEB.c_str()); 
        
        FEBtree[ih]->Branch((sFEB+"_SN").c_str(),"vector<double>",&FEB[ih].FEBSN);
        FEBtree[ih]->Branch((sFEB+"_SpillTag").c_str(),"vector<double>",&FEB[ih].SpillNum);
        FEBtree[ih]->Branch((sFEB+"_SpillTime").c_str(),"vector<double>",&FEB[ih].SpillTime);
        FEBtree[ih]->Branch((sFEB+"_SpillTimeGTrig").c_str(),"vector<double>",&FEB[ih].SpillTimeGTrig);
        FEBtree[ih]->Branch((sFEB+"_GTrigTag").c_str(),"vector<double>",&FEB[ih].GTrigTag);
        FEBtree[ih]->Branch((sFEB+"_GTrigTime").c_str(),"vector<double>",&FEB[ih].GTrigTime);
        FEBtree[ih]->Branch((sFEB+"_hitsChannel").c_str(),"vector<double>",&FEB[ih].hitsChannel);
        FEBtree[ih]->Branch((sFEB+"_hitAmpl").c_str(),"vector<double>",&FEB[ih].hitAmpl);
        FEBtree[ih]->Branch((sFEB+"_hitLGAmpl").c_str(),"vector<double>",&FEB[ih].hitLGAmpl);
        FEBtree[ih]->Branch((sFEB+"_hitLeadTime").c_str(),"vector<double>",&FEB[ih].hitLeadTime);
        FEBtree[ih]->Branch((sFEB+"_hitTrailTime").c_str(),"vector<double>",&FEB[ih].hitTrailTime);
        FEBtree[ih]->Branch((sFEB+"_hitTimeDif").c_str(),"vector<double>",&FEB[ih].hitTimeDif);
        FEBtree[ih]->Branch((sFEB+"_hitTimefromSpill").c_str(),"vector<double>",&FEB[ih].hitTimefromSpill);
        FEBtree[ih]->Branch((sFEB+"_SpillTrailTime").c_str(),"vector<double>",&FEB[ih].SpillTrailTime);
        //FEBtree[ih]->Branch((sFEB+"_SpillTemperature").c_str(), "vector<double>",&FEB[ih].SpillTemperature);
        FEBtree[ih]->Branch((sFEB+"_AsicTemperature").c_str(),"vector<double>",&FEB[ih].AsicTemperature);
        FEBtree[ih]->Branch((sFEB+"_FPGATemperature").c_str(),"vector<double>",&FEB[ih].FPGATemperature);
        FEBtree[ih]->Branch((sFEB+"_GlobalHV").c_str(),"vector<double>",&FEB[ih].GlobalHV);
        FEBtree[ih]->Branch((sFEB+"_BoardTemperature").c_str(),"vector<double>",&FEB[ih].BoardTemperature);
        FEBtree[ih]->Branch((sFEB+"_BoardHumidity").c_str(),"vector<double>",&FEB[ih].BoardHumidity);
        FEBtree[ih]->Branch((sFEB+"_HoldTimeStart").c_str(),"vector<double>",&FEB[ih].HoldTimeStart);
        FEBtree[ih]->Branch((sFEB+"_HoldTimeStop").c_str(),"vector<double>",&FEB[ih].HoldTimeStop);
        FEBtree[ih]->Branch((sFEB+"_HoldTimeStartNumber").c_str(),"vector<double>",&FEB[ih].HoldTimeStartNumber);
        FEBtree[ih]->Branch((sFEB+"_HoldTimeStopNumber").c_str(),"vector<double>",&FEB[ih].HoldTimeStopNumber);

  }

  bool firstSpillTagExist = false;
  unsigned int firstSpillTag = 0;
  
  for (vector<string>::iterator itFileName=vFileNames.begin(); itFileName != vFileNames.end(); itFileName++) {
    sFileName = *itFileName;
    cout <<endl<< sFileName << endl;
    
    ifstream finData(sFileName.c_str());
    string stringBuf;
    string filepath;
    string filename;
  
  // The following shows how to use the MDargumentHandler class
  // to deal with the main arguments
  // Define the arguments
  MDargumentHandler argh("Example of unpacking application.");
  argh.AddArgument("help","print this message","h");
  argh.AddArgument("directory","path for the data file","d","<string>","." );
  argh.AddArgument("file","Name of a data file","f","<string>","mandatory");
  

  // Check the user arguments consistancy
  // All mandatory arguments should be provided and
  // There should be no extra arguments
  //if ( argh.ProcessArguments(argc, argv) ) {argh.Usage(); return -1;}

  // Treat arguments, obtain values to be used later
  if ( argh.GetValue("help") ) {argh.Usage(); return 0;}
  if ( argh.GetValue("directory", stringBuf) != MDARGUMENT_STATUS_OK ) return -1;
  filepath = stringBuf;
  if ( argh.GetValue("file", stringBuf) != MDARGUMENT_STATUS_OK ) return -1;
  filename = stringBuf;
  filename = sFileName;
  string rootFilename = sFileName;
 
  
  
  //TFile rfile("histos.root", "recreate");
      
 
  
  for (Int_t i=0;i<=64;i++){
    FEB[i].FEBSN.clear();
    FEB[i].SpillNum.clear();
    FEB[i].SpillTime.clear();
    FEB[i].SpillTimeGTrig.clear();
    FEB[i].hitsChannel.clear();
    FEB[i].hitAmpl.clear();
    FEB[i].hitLeadTime.clear();
    FEB[i].GTrigTag.clear();
    FEB[i].GTrigTime.clear();
    FEB[i].hitLGAmpl.clear();
    FEB[i].hitTrailTime.clear();
    FEB[i].hitTimeDif.clear();
    FEB[i].hitTimefromSpill.clear();
    FEB[i].SpillTrailTime.clear();
    //FEB[i].SpillTemperature.clear();
    FEB[i].AsicTemperature.clear();
    FEB[i].FPGATemperature.clear();
    FEB[i].GlobalHV.clear();
    FEB[i].BoardTemperature.clear();
    FEB[i].BoardHumidity.clear();

    FEB[i].HoldTimeStart.clear();
    FEB[i].HoldTimeStop.clear();
    FEB[i].HoldTimeStartNumber.clear();
    FEB[i].HoldTimeStopNumber.clear();
  }
  
  MDdateFile dfile(filename, filepath);
// Open the file and loop over events.
  Int_t BordID=0;
  char *eventBuffer;
  bool _previousSpillTagExist = false;
  unsigned int _previousSpillTag = 0;
  if ( dfile.open() ) { // There is a valid files to unpack
    dfile.init();

    int xEv(0);
    //int SpecTag = 3553910;
    int SpecTag = 319510;
    do { // Loop over all spills
      eventBuffer =  dfile.GetNextEvent();

      try {
        MDfragmentBM   spill;
	
        spill.SetPreviousSpill(_previousSpillTagExist,_previousSpillTag);
        spill.SetDataPtr(eventBuffer);
        MDpartEventBM *event;
        int nTr = spill.GetNumOfTriggers();
        BordID = (Int_t)spill.GetBoardId();
        
        for (int i=0; i<nTr; ++i) {
          event = spill.GetTriggerEventPtr(i);
          //event->Dump();
          for (int ich=0; ich<BM_FEB_NCHANNELS; ++ich) {
              int nlHits = 0;
              int ntHits = 0;
              nlHits = event->GetNLeadingEdgeHits(ich);
              for (unsigned int ih=0; ih<nlHits; ++ih) {
                  bool TrailTimeExist = false;
                  int IDevent = event->GetHitTimeId(ih, ich, 'l');
                  FEB[spill.GetBoardId()].FEBSN.push_back(spill.GetBoardId());
                  FEB[spill.GetBoardId()].SpillNum.push_back(spill.GetSpillTag());
		    _previousSpillTagExist = true;
                    _previousSpillTag = spill.GetSpillTag();
                    if (_previousSpillTag >= 65535)
                            _previousSpillTag = 32767;
                  FEB[spill.GetBoardId()].SpillTimeGTrig.push_back(spill.GetSpillTimeGTrig());
                  FEB[spill.GetBoardId()].SpillTime.push_back(spill.GetSpillTime());
                  FEB[spill.GetBoardId()].GTrigTag.push_back(event->GetTriggerTag());
                  FEB[spill.GetBoardId()].GTrigTime.push_back(event->GetTriggerTime());

                  /*if (event->GetHoldTimeStart() != -1) {
                    FEB[spill.GetBoardId()].HoldTimeStart.push_back(-4 * FEB[spill.GetBoardId()].SpillTimeGTrig.back() + 4000* ( FEB[spill.GetBoardId()].GTrigTime.back()) + 4*event->GetHoldTimeStart());
                  } else {
                    FEB[spill.GetBoardId()].HoldTimeStart.push_back(-1);
                  }
                  if (event->GetHoldTimeStop() != -1){
                    FEB[spill.GetBoardId()].HoldTimeStop.push_back(-4 * FEB[spill.GetBoardId()].SpillTimeGTrig.back() + 4000* ( FEB[spill.GetBoardId()].GTrigTime.back()) + 4*event->GetHoldTimeStop());
                  } else {
                    FEB[spill.GetBoardId()].HoldTimeStop.push_back(-1);
                  }*/
                  
                  FEB[spill.GetBoardId()].hitsChannel.push_back(ich);
		  FEB[spill.GetBoardId()].hitLeadTime.push_back(event->GetLeadingTime(ih, ich));
                  FEB[spill.GetBoardId()].hitTimefromSpill.push_back(-4 * FEB[spill.GetBoardId()].SpillTimeGTrig.back() + 4000* ( FEB[spill.GetBoardId()].GTrigTime.back()) + event->GetLeadingTime(ih, ich));

                  FEB[spill.GetBoardId()].SpillTrailTime.push_back(spill.GetSpillTrailTime() );
                  //FEB[spill.GetBoardId()].SpillTemperature.push_back(spill.GetSpillTrailTemp());
                  
                  ntHits = event->GetNTrailingEdgeHits(ich);
                  for(unsigned int ith=0; ith < ntHits; ith++){
                      if (IDevent==event->GetHitTimeId(ith, ich, 't') && TrailTimeExist==false && event->GetTrailingTime(ith, ich) >= FEB[spill.GetBoardId()].hitLeadTime.back()){
                          FEB[spill.GetBoardId()].hitTrailTime.push_back(event->GetTrailingTime(ith, ich));
                          FEB[spill.GetBoardId()].hitTimeDif.push_back(FEB[spill.GetBoardId()].hitTrailTime.back() - FEB[spill.GetBoardId()].hitLeadTime.back() );
                          TrailTimeExist = true;
                      }
                  }
                  if (TrailTimeExist==false){
                      if (i+1 <nTr){
                        event = spill.GetTriggerEventPtr(i+1);
                        ntHits = event->GetNTrailingEdgeHits(ich);
                        unsigned int ith=0;
                            while (TrailTimeExist==false && ith < ntHits){
                                if (IDevent==event->GetHitTimeId(ith, ich, 't')){
				  //std::cout << "GetHitTimeId" << event->GetHitTimeId(ith, ich, 't') << "  GetHitAmplitudeId: " << event-> GetHitAmplitudeId(ich, 'h') << endl;
                                    FEB[spill.GetBoardId()].hitTrailTime.push_back(event->GetTrailingTime(ith, ich));
                                    FEB[spill.GetBoardId()].hitTimeDif.push_back(FEB[spill.GetBoardId()].hitTrailTime.back() - FEB[spill.GetBoardId()].hitLeadTime.back() + 4000);
                                    TrailTimeExist = true;
                                }
                            ith++;
                            }
                        event = spill.GetTriggerEventPtr(i);
                      }
                  }
                  
                 if (TrailTimeExist==false){
                    FEB[spill.GetBoardId()].hitTrailTime.push_back(-1);
                    FEB[spill.GetBoardId()].hitTimeDif.push_back(-1);
                    TrailTimeExist = true;
                }
                    
                    
                  
                  
                  bool HGAmplExist = false;

		  if ( SpecTag-200 < event->GetTriggerTag() && event->GetTriggerTag() < SpecTag + 200){
		    cout << " " << std::endl;
		    cout << "i STAGE STARTS: GTrigTag "<< event->GetTriggerTag()<<endl;
		    cout << "   CHECK: IDevent == event-> GetHitAmplitudeId(ich, 'h') " << " IDevent= " << IDevent <<  "   event->GetHitAmplitudeId = "<<event-> GetHitAmplitudeId(ich, 'h') << endl;}
                  if (IDevent == event-> GetHitAmplitudeId(ich, 'h') && event-> GetHitAmplitude(ich, 'h') !=0  ){
		    FEB[spill.GetBoardId()].hitAmpl.push_back(event->GetHitAmplitude(ich, 'h'));
		    HGAmplExist = true;
		    if ( SpecTag-200 < event->GetTriggerTag() && event->GetTriggerTag() < SpecTag + 200){
		      
		      cout << "      GTrigTag: " << event->GetTriggerTag()<< " Rising: "<< event->GetLeadingTime(ih, ich) << endl;
		      
		      cout << "      !!!***!!!! Amplitude (" << event->GetHitAmplitude(ich, 'h') << ") pushed at i+0  !!!****!!!!" << endl;
		      
		    }
                  }
		  if (SpecTag-200 < event->GetTriggerTag() && event->GetTriggerTag() < SpecTag + 200){
		    cout << "i STAGE ENDS." <<endl;
		  }		  
		  
		  
                  if ( HGAmplExist == false){
		    if (i+1 <nTr){
		      event = spill.GetTriggerEventPtr(i+1);
		      if ( SpecTag-200 < event->GetTriggerTag() && event->GetTriggerTag() < SpecTag + 200) {
			cout << " " << std::endl;
			std::cout << "i+1 STAGE STARTS  "<< " GTrigTag: " << event->GetTriggerTag()  <<  std::endl;	
		      }	  
		      if (SpecTag-200 < event->GetTriggerTag() && event->GetTriggerTag() < SpecTag+200) {
			cout << "      ************ after GTrigTag Increment{ ************ " << endl;
			//cout << "      GTrigTag: " << event->GetTriggerTag()<< " Rising: "<< event->GetLeadingTime(ih, ich) << " IDevent " << IDevent << "  GetHitAmplitudeId: " <<  event-> GetHitAmplitudeId(ich, 'h') << endl;
			cout << "      GTrigTag: " << " IDevent " << IDevent << "  GetHitAmplitudeId: " <<  event-> GetHitAmplitudeId(ich, 'h') << endl;
			
			cout << "      ************ after GTrigTag Increment}************ " << endl;
		      }	  
		      if (event-> HGAmplitudeHitExists(ich)){
			if ( SpecTag-200 < event->GetTriggerTag() && event->GetTriggerTag() < SpecTag+200)  cout << "        HGAmplitudeExists on channel " << ich <<  std::endl;
			if (IDevent== event-> GetHitAmplitudeId(ich, 'h') ){
			  if ( SpecTag-200 < event->GetTriggerTag() && event->GetTriggerTag() < SpecTag+200) {
			    cout << "        CHECK: IDevent == event-> GetHitAmplitudeId(ich, 'h') " << " IDevent= " << IDevent <<  "   event->GetHitAmplitudeId = "<<event-> GetHitAmplitudeId(ich, 'h') << endl;
			    cout << "        !!!***!!!! Amplitude (" << event->GetHitAmplitude(ich, 'h') << ") pushed at i+1  !!!****!!!!" << endl;
			  }
			  FEB[spill.GetBoardId()].hitAmpl.push_back(event->GetHitAmplitude(ich, 'h'));
			  HGAmplExist = true;
			} else {
			  if ( SpecTag-200 < event->GetTriggerTag() && event->GetTriggerTag() < SpecTag+200) cout << "        Failed at IDevent == event -> GetHitAmplitudeId(ich, 'h')" << endl;
			  
			}
		      }
		      event = spill.GetTriggerEventPtr(i);
		      if ( SpecTag-200 < event->GetTriggerTag() && event->GetTriggerTag() < SpecTag+200)	cout << "i+1 STAGE ENDS" << endl;
		    }
                  }
		  
		  // here I have to add an if (i+2 < nTr) line which does the same thing as the block above but for two GTrigTag in advance
		  
		  /*
		    if ( HGAmplExist == false){
		    if (i+2 <nTr){
		    event = spill.GetTriggerEventPtr(i+2);
		    if (event-> HGAmplitudeHitExists(ich)){
		    if (IDevent==event-> GetHitAmplitudeId(ich, 'h')){
		    FEB[spill.GetBoardId()].hitAmpl.push_back(event->GetHitAmplitude(ich, 'h'));
		    HGAmplExist = true;
		    }
		    }
		    event = spill.GetTriggerEventPtr(i);
                    }
		    }
		  */
                  if (HGAmplExist==false){
		    FEB[spill.GetBoardId()].hitAmpl.push_back(0);
		    HGAmplExist = true;
                  }
                  
                  bool LGAmplExist = false;
                  if (IDevent==event-> GetHitAmplitudeId(ich, 'l') && event-> GetHitAmplitude(ich, 'l') !=0 ){
		    FEB[spill.GetBoardId()].hitLGAmpl.push_back(event->GetHitAmplitude(ich, 'l'));
		    LGAmplExist = true;
                  }
                  if ( LGAmplExist == false){
		    if (i+1 <nTr){
		      event = spill.GetTriggerEventPtr(i+1);
		      if (event-> LGAmplitudeHitExists(ich)){
			if (IDevent==event-> GetHitAmplitudeId(ich, 'l')){
			  FEB[spill.GetBoardId()].hitLGAmpl.push_back(event->GetHitAmplitude(ich, 'l'));
			  LGAmplExist = true;
			}
		      }
		      event = spill.GetTriggerEventPtr(i);
		    }
                  }
		  
		  //R.A. the same addition as for the HighGain 
		  /*
		    if ( LGAmplExist == false){
		    if (i+2 <nTr){
		    event = spill.GetTriggerEventPtr(i+2);
		    if (event-> LGAmplitudeHitExists(ich)){
		    if (IDevent==event-> GetHitAmplitudeId(ich, 'l')){
		    FEB[spill.GetBoardId()].hitLGAmpl.push_back(event->GetHitAmplitude(ich, 'l'));
		    LGAmplExist = true;
		    }
		    }
		    event = spill.GetTriggerEventPtr(i);
		    }
                  }
		  
		  */
		  
		  
                  if ( LGAmplExist == false){
		    FEB[spill.GetBoardId()].hitLGAmpl.push_back(0);
                  }
                  
		  if (event->GetAsicTemperature(ich)!=1)
                    FEB[spill.GetBoardId()].AsicTemperature.push_back(-((event->GetAsicTemperature(ich) -340) *(0.000822) / 0.006) + 34 );
		  else 
                    FEB[spill.GetBoardId()].AsicTemperature.push_back(-1);
		  
		  if (event->GetFPGATemperature()!=1)
                    FEB[spill.GetBoardId()].FPGATemperature.push_back(event->GetFPGATemperature() - 128);
                else
                    FEB[spill.GetBoardId()].FPGATemperature.push_back(-1);
                
              if (event->GetGlobalHV()!=1)
                    FEB[spill.GetBoardId()].GlobalHV.push_back(event->GetGlobalHV()*(0.000822)*(1+1000/41.2));
                else 
                    FEB[spill.GetBoardId()].GlobalHV.push_back(-1);
                
              if (event->GetBoardTemperature()!=1)
                    FEB[spill.GetBoardId()].BoardTemperature.push_back(-(event->GetBoardTemperature()*(0.000822) - 2.633)*1000/13.3);
                else
                    FEB[spill.GetBoardId()].BoardTemperature.push_back(-1);
                
              if (event->GetBoardHumidity()!=1)
                    FEB[spill.GetBoardId()].BoardHumidity.push_back((event->GetBoardHumidity()*(0.000822)/3.3 - 0.1515)/0.00636);
                else 
                    FEB[spill.GetBoardId()].BoardHumidity.push_back(-1);
                
              if (FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].SpillNum.size()          ||
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].hitsChannel.size()       || 
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].SpillTimeGTrig.size()    ||
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].hitAmpl.size()           || 
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].hitLeadTime.size()       || 
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].GTrigTag.size()          ||  
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].GTrigTime.size()         ||  
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].hitLGAmpl.size()         || 
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].hitTrailTime.size()      ||
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].hitTimeDif.size()        ||
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].hitTimefromSpill.size()  ||
                  FEB[spill.GetBoardId()].FEBSN.size() !=  FEB[spill.GetBoardId()].SpillTrailTime.size()) {
                  
                 cout <<FEB[spill.GetBoardId()].GTrigTag.back()<<endl;
                 cout <<"CRASH: " << FEB[spill.GetBoardId()].FEBSN.size()<< " " <<FEB[spill.GetBoardId()].SpillNum.size()<<" "<<FEB[spill.GetBoardId()].hitAmpl.size()<<" " <<FEB[spill.GetBoardId()].hitTrailTime.size()<<endl;
                 return 0;
                 }
                  
              }
          }
        }
        for (int i = 0 ; i< spill.GetL1HoldStart().size(); i++){
          FEB[spill.GetBoardId()].HoldTimeStart.push_back(spill.GetL1HoldStart().at(i) -4 * FEB[spill.GetBoardId()].SpillTimeGTrig.back() - 20);
        }
        for (int i = 0 ; i< spill.GetL1HoldStop().size(); i++){
          FEB[spill.GetBoardId()].HoldTimeStop.push_back(spill.GetL1HoldStop().at(i) -4 * FEB[spill.GetBoardId()].SpillTimeGTrig.back());
        }
        for (int i = 0 ; i< spill.GetL1HoldStartNumber().size(); i++){
          FEB[spill.GetBoardId()].HoldTimeStartNumber.push_back(spill.GetL1HoldStartNumber().at(i));
        }
        for (int i = 0 ; i< spill.GetL1HoldStopNumber().size(); i++){
          FEB[spill.GetBoardId()].HoldTimeStopNumber.push_back(spill.GetL1HoldStopNumber().at(i));
        }
      } catch (MDexception & lExc)  {
        std::cerr <<  lExc.GetDescription() << endl
                  << "Unpacking exception\n"
                  << "Spill skipped!\n\n"
                  << "Here it should fill with negative numbers. \n\n";
        if (_previousSpillTag==0){
          _previousSpillTag = firstSpillTag -1;
        }
        _previousSpillTag = _previousSpillTag + 1;
        FEB[BordID].FEBSN.push_back(BordID);
        FEB[BordID].SpillNum.push_back(_previousSpillTag);
        FEB[BordID].SpillTime.push_back(-1);
        FEB[BordID].SpillTimeGTrig.push_back(-1);
        FEB[BordID].hitsChannel.push_back(-1);
        FEB[BordID].hitAmpl.push_back(-1);
        FEB[BordID].hitLeadTime.push_back(-1);
        FEB[BordID].GTrigTag.push_back(-1);
        FEB[BordID].GTrigTime.push_back(-1);
        FEB[BordID].hitLGAmpl.push_back(-1);
        FEB[BordID].hitTrailTime.push_back(-1);
        FEB[BordID].hitTimeDif.push_back(-1);
        FEB[BordID].hitTimefromSpill.push_back(-1);
        FEB[BordID].SpillTrailTime.push_back(-1);
        //FEB[BordID].SpillTemperature.push_back(-1);
        FEB[BordID].AsicTemperature.push_back(-1);
        FEB[BordID].FPGATemperature.push_back(-1);
        FEB[BordID].GlobalHV.push_back(-1);
        FEB[BordID].BoardTemperature.push_back(-1);
        FEB[BordID].BoardHumidity.push_back(-1);

        FEB[BordID].HoldTimeStart.push_back(-1);
        FEB[BordID].HoldTimeStop.push_back(-1);
        FEB[BordID].HoldTimeStartNumber.push_back(-1);
        FEB[BordID].HoldTimeStopNumber.push_back(-1);

        if (_previousSpillTag >= 65535)
              _previousSpillTag = 32767;

      } catch(std::exception & lExc) {
        std::cerr << lExc.what() << std::endl
                  << "Standard exception\n"
                  << "Spill skipped!\n\n";
      } catch(...) {
        std::cerr << "Unknown exception occurred...\n"
                  << "Spill skipped!\n\n";
      }
     if (FEB[BordID].FEBSN.size()){
        cout<<"Number of events on FEB "<< BordID <<" is "<< FEB[BordID].FEBSN.size()<<endl;
        if (!firstSpillTagExist && FEBtree[BordID]->GetEntries() == 0){
            firstSpillTag = FEB[BordID].SpillNum.back();
            firstSpillTagExist =true;
            //cout << "First Spill " << firstSpillTag<<endl;
        }
        FEBtree[BordID]->Fill();
     } else {
        if (_previousSpillTag==0){
          _previousSpillTag = firstSpillTag -1;
        }
        _previousSpillTag = _previousSpillTag + 1;
        FEB[BordID].FEBSN.push_back(BordID);
        FEB[BordID].SpillNum.push_back(_previousSpillTag);
        FEB[BordID].SpillTime.push_back(-1);
        FEB[BordID].SpillTimeGTrig.push_back(-1);
        FEB[BordID].hitsChannel.push_back(-1);
        FEB[BordID].hitAmpl.push_back(-1);
        FEB[BordID].hitLeadTime.push_back(-1);
        FEB[BordID].GTrigTag.push_back(-1);
        FEB[BordID].GTrigTime.push_back(-1);
        FEB[BordID].hitLGAmpl.push_back(-1);
        FEB[BordID].hitTrailTime.push_back(-1);
        FEB[BordID].hitTimeDif.push_back(-1);
        FEB[BordID].hitTimefromSpill.push_back(-1);
        FEB[BordID].SpillTrailTime.push_back(-1);
        //FEB[BordID].SpillTemperature.push_back(-1);
        FEB[BordID].AsicTemperature.push_back(-1);
        FEB[BordID].FPGATemperature.push_back(-1);
        FEB[BordID].GlobalHV.push_back(-1);
        FEB[BordID].BoardTemperature.push_back(-1);
        FEB[BordID].BoardHumidity.push_back(-1);
        FEB[BordID].HoldTimeStart.push_back(-1);
        FEB[BordID].HoldTimeStop.push_back(-1);
        FEB[BordID].HoldTimeStartNumber.push_back(-1);
        FEB[BordID].HoldTimeStopNumber.push_back(-1);
        FEBtree[BordID]->Fill();
        if (_previousSpillTag >= 65535)
              _previousSpillTag = 32767;
     }
     
    FEB[BordID].FEBSN.clear();
    FEB[BordID].SpillNum.clear();
    FEB[BordID].SpillTime.clear();
    FEB[BordID].SpillTimeGTrig.clear();
    FEB[BordID].hitsChannel.clear();
    FEB[BordID].hitAmpl.clear();
    FEB[BordID].hitLeadTime.clear();
    FEB[BordID].hitTrailTime.clear();
    FEB[BordID].hitTimeDif.clear();
    FEB[BordID].GTrigTag.clear();
    FEB[BordID].GTrigTime.clear();
    FEB[BordID].hitLGAmpl.clear();
    FEB[BordID].hitTimefromSpill.clear();
    FEB[BordID].SpillTrailTime.clear();
    //FEB[BordID].SpillTemperature.clear();
    FEB[BordID].AsicTemperature.clear();
    FEB[BordID].FPGATemperature.clear();
    FEB[BordID].GlobalHV.clear();
    FEB[BordID].BoardTemperature.clear();
    FEB[BordID].BoardHumidity.clear();
    FEB[BordID].HoldTimeStart.clear();
    FEB[BordID].HoldTimeStop.clear();
    FEB[BordID].HoldTimeStartNumber.clear();
    FEB[BordID].HoldTimeStopNumber.clear();
    ++xEv;
    //} while (xEv < 130); // xEv is the number of spills.
    } while ( eventBuffer );
  }

  FEBtree[BordID]-> Write("",TObject::kOverwrite);
  cout << "Number of spills on FEB "<< BordID<< ": "<< FEBtree[BordID]->GetEntries()<<endl;
  FEBtree[BordID]->Delete();

  dfile.close();
  delete dataBuff;
  }
  rfile.Close();
  fList.close();
  return 0;
}

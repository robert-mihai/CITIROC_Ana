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
#include <TCanvas.h>

#include "MDdataWordBM.h"
#include "MDargumentHandler.h"

#include <iostream>
#include <sstream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <TTree.h>
#include <TRandom.h>
#include <TSpectrum.h>
#include <TVirtualFitter.h>
#include <TFile.h>
#include <TH1.h>
#include <TF1.h>
#include <TMath.h>
#include <TROOT.h>

using namespace std;

Int_t npeaks = 30;
Double_t fpeaks(Double_t *x, Double_t *par) {
  Double_t result = par[0]*exp(par[1]*x[0]);
   for (Int_t p=0;p<npeaks;p++) {
      Double_t norm  = par[3*p+2];
      Double_t mean  = par[3*p+3];
      Double_t sigma = par[3*p+4];
      result += norm*TMath::Gaus(x[0],mean,sigma);
   }
   return result;
}

struct Peak {
  Double_t Mean;
  Double_t Height;
  Double_t Sigma;
  Double_t nlg;
};

bool compareMean( const Peak &a, const Peak &b) {
  return a.Mean < b.Mean;
}

string GetDir(string str){
    int i = str.rfind("/");
    string way = str.substr(0,i+1);  
    return way;
}

string GetLocation(string str){
     
    int i = str.rfind("_Slot_");
    string way = str.substr(0,i);  
    return way;
}

string GetMCRnumber(string str) {
    int i = str.find("_MCR_");
    string mcr = str.substr(i+5,1);
    return mcr;
}

string GetSlotNumber(string str){
    int i = str.find("_Slot_");
    string slot = str.substr(i+6,1);
    return slot;
}

int main( int argc, char **argv ) {
  string stringBuf;
  
  string sFileName;
  
  vector<string> vFileNames;
  ifstream fList("febs_files_list.list");
  while (!fList.eof()) {
    fList >> sFileName;
    vFileNames.push_back(sFileName);
  }
  vFileNames.pop_back();

  for(int i = 0; i<vFileNames.size(); i++){
    cout << vFileNames.at(i) << endl;
  }
  
  TCanvas *c1 = new TCanvas("c1","",0,10,700,500);
  c1->SetLogy();

  Peak peak;
  vector<Peak> vPeaks;
  vector<Peak> vgPeaks;

  vector<Double_t> vSigmaPeak;
  vector<Double_t> vMeanPeak;
  vector<Double_t> vHeightPeak;

  Int_t FEB;
  Int_t ch;
  Double_t gain;
  Int_t nlocalgain;

  TTree *tCalibBM = new TTree("calibBM","calibBM");
  tCalibBM->Branch("FEB",&FEB ,"FEB/I");
  tCalibBM->Branch("ch",&ch,"ch/I");
  tCalibBM->Branch("gain",&gain,"gain/D");
  tCalibBM->Branch("vSigmaPeak",&vSigmaPeak);
  tCalibBM->Branch("vMeanPeak",&vMeanPeak);
  tCalibBM->Branch("vHeightPeak",&vHeightPeak);
  tCalibBM->Branch("npeaks",&npeaks,"npeaks/I");
  
  string rootFileOutput=GetLocation(vFileNames[0].c_str());
  rootFileOutput+="_channels_signal.root";
  TFile wfile(rootFileOutput.c_str(), "recreate");
  
  string filename;
  string filepath;
for (vector<string>::iterator itFileName=vFileNames.begin(); itFileName != vFileNames.end(); itFileName++) {
    sFileName = *itFileName;
    cout <<endl<< sFileName << endl;
    filename = sFileName;
    filepath = stringBuf;

  // The following shows how to use the MDargumentHandler class
  // to deal with the main arguments
  // Define the arguments
  MDargumentHandler argh("Example of unpacking application.");
  argh.AddArgument("directory","Path for a data file","d","<string>","." );
  argh.AddArgument("file","Name of a data file","f","<string>","mandatory");

  // Check the user arguments consistancy
  // All mandatory arguments should be provided and
  // There should be no extra arguments
  if ( argh.ProcessArguments(argc, argv) ) {argh.Usage(); return -1;}

  // Treat arguments, obtain values to be used later
  if ( argh.GetValue("help") ) {argh.Usage(); return 0;}
  if ( argh.GetValue("directory", stringBuf) != MDARGUMENT_STATUS_OK ) return -1;

  if ( argh.GetValue("file", stringBuf) != MDARGUMENT_STATUS_OK ) return -1;



  std::ifstream ifs(filename.c_str());
  if ( ifs.fail() ) {
    cerr << "Can not open file " << filepath << filename << endl;
    return 1;
  }


  string MCRnum = GetMCRnumber(filename.c_str());
  string Slotnum = GetSlotNumber(filename.c_str());
  // cout <<MCRnum<<" " << Slotnum<<endl;
 // return 0;
  string gainFileOutput=GetDir(vFileNames[0].c_str());
  gainFileOutput+="MCR_"+MCRnum +"_Slot_"+Slotnum +"_gain.txt";
  cout <<"Openning daq file for MCR: "<< MCRnum<<" Slot: "<<Slotnum<<endl<< gainFileOutput << endl;
  TDirectory *FEBdir = wfile.mkdir(("MCR_"+MCRnum+"_Slot_"+Slotnum).c_str());
  TCanvas c;
  FEB = 8*(std::stoi( MCRnum )) + std::stoi( Slotnum );
  TH1F *hFEBCH[96];
     ostringstream sChnum;
     string sCh;
     for (Int_t ih=0; ih < 96;ih++){
        sChnum.str("");
        sChnum << ih;
        sCh = "Channel_"+sChnum.str();
        hFEBCH[ih]=new TH1F(sCh.c_str(),sCh.c_str(),  701, 0, 700);
     }
     
  
  uint32_t* dataPtr = new uint32_t;

  int dwCount(0);
  while (!ifs.eof()) {
    ifs.read((char*)dataPtr, 4 );
    MDdataWordBM dw(dataPtr);
   // cout << dw << endl;
    switch (dw.GetDataType()) {
        case MDdataWordBM::ChargeMeas:
            if (dw.GetAmplitudeId()==2){
                hFEBCH[dw.GetChannelId()]->Fill(dw.GetAmplitude());
            }
            break;
        default:
            break;
    }
    ++dwCount;
  }
  
  ifs.close();
  
    Double_t averageGain = 34.; 
    Double_t rangeGain = averageGain/2.2; 
    
    Double_t peakWidth = 5;  
    Double_t rangePeaksMin = 40;
    Double_t rangePeaksMax = 500;

    Double_t par[1500];
    
    ofstream outGain(gainFileOutput.c_str());

    // Analysis of the channels spectrum for the FEB
    for (Int_t iCh=0; iCh<96; iCh++) {

      ch = iCh;
      gain = 0.;
      nlocalgain = 0;
      vgPeaks.clear();

      npeaks = 30;

      cout << " #channel = " << iCh << endl;

      // FIT the fingerplots
      TSpectrum *s = new TSpectrum(npeaks,3);    
      //Int_t nfound = s->Search(hClone,peakWidth,"new",0.001);
      Int_t nfound = s->Search(hFEBCH[iCh],peakWidth,"new",0.00000001);
      //cout << " nfound = " << nfound << endl;

      if (nfound>1) {

	double *xpeaks = s->GetPositionX();
	double *ypeaks = s->GetPositionY();

    //Double_t *xpeaks = s->GetPositionX();
	//Double_t *ypeaks = s->GetPositionY();
	
	Peak peak;
  Peak peak0;
  Peak peak1;
	vector<Peak> vPeaks;
	for (Int_t iPeak=1; iPeak<nfound; iPeak++) {
	  peak.Mean = xpeaks[iPeak];
	  peak.Height = ypeaks[iPeak];
	  vPeaks.push_back(peak);
	}

	sort(vPeaks.begin(),vPeaks.end(),compareMean);
	for (vector<Peak>::iterator it = vPeaks.begin(); it != vPeaks.end(); it++ ) {
	  peak = *it;
	  //cout << peak.Mean << " " << peak.Height << endl;
	}
	cout << endl;
    
	// Select peaks above 5
	vector<Peak> vTempPeaks;
	for (vector<Peak>::iterator it = vPeaks.begin(); it != vPeaks.end(); it++ ) {
	  peak = *it;
    peak0 = *(it + 1);
    peak1 = *(it - 1);
    int peakHeight =100;
    if (FEB == 21 || FEB == 29) {
      peakHeight =7;
      rangePeaksMin = 5;
      rangePeaksMax = 300;
      peakWidth = 7;  
    }
	  if (peak.Height>peakHeight && peak.Mean>rangePeaksMin && peak.Mean<rangePeaksMax && peak.Height>peak0.Height && peak.Height<=peak1.Height) {
          vTempPeaks.push_back(peak); 
          //cout<<vTempPeaks.size()<<" "<< peak.Mean<<" peak: "<<peak.Height<<" peak+1: "<<peak0.Height<<endl;
      }
	}
	vPeaks.clear();
	vPeaks = vTempPeaks;
    
	//cout << "Number selected peaks above 5 = " << vPeaks.size() << endl;
	sort(vPeaks.begin(),vPeaks.end(),compareMean);
	for (vector<Peak>::iterator it = vPeaks.begin(); it != vPeaks.end(); it++ ) {
	  peak = *it;
	  //cout << peak.Mean << " " << peak.Height << endl;
	}
	//cout << endl;

	if (vPeaks.size()>1) {
	  bool nextStep;
	  do {
	    vTempPeaks.clear();
	    //cout << "DOWHILE" << endl;
	    Peak peak0;
	    Int_t iPeak = 0;
	    for (vector<Peak>::iterator it = vPeaks.begin(); it != vPeaks.end(); it++ ) {
	      peak = *it;
	      if (iPeak == 0) peak0 = peak;
	      if (iPeak == 1) {
		//if (peak0.Height > peak.Height &&  abs(peak.Height/peak0.Height-0.29)<0.15 && abs(peak.Mean-peak0.Mean)-averageGain<rangeGain) {
        if (peak0.Height > peak.Height && abs(peak.Mean-peak0.Mean)-averageGain<rangeGain) {
        //if (abs(peak.Mean-peak0.Mean)-averageGain<rangeGain) {
		  vTempPeaks.push_back(peak0);
		  vTempPeaks.push_back(peak);
		} 
		else vTempPeaks.push_back(peak);	    
	      }
	      if (iPeak > 1) vTempPeaks.push_back(peak);
	      iPeak++;
	    }	
	    //cout << "sizes: " << vPeaks.size() << " " << vTempPeaks.size() << endl;
	    
	    nextStep = false;
	    if (vTempPeaks.size()<vPeaks.size()) nextStep = true;
	  
	    vPeaks.clear();
	    vPeaks = vTempPeaks;

	  } while(vPeaks.size()>1 && nextStep);	  
	 
	  for (vector<Peak>::iterator it = vPeaks.begin(); it != vPeaks.end(); it++ ) {
	    peak = *it;
	  //  cout << peak.Mean << " " << peak.Height << endl;
	  }
	  cout << endl;
	  
	  if (vPeaks.size()>1) {
	    // FIT background
	    
	    Peak p1 = vPeaks.front();
	    Peak p2 = vPeaks.back();
	    TF1 *fexpo = new TF1("fexpo","expo",p1.Mean-1.1*peakWidth,p2.Mean+1.5*peakWidth);
	    hFEBCH[iCh]->Fit("fexpo","NMQER");
	    par[0] = fexpo->GetParameter(0);
	    par[1] = fexpo->GetParameter(1);

	    // FIT
	    Double_t vpar[3];
	    npeaks = 0;
	    //	    vgPeaks.clear();
	    //	    vgPeaks = vPeaks;

	    for (vector<Peak>::iterator it = vPeaks.begin(); it != vPeaks.end(); it++ ) {
	      peak = *it;

	      /*
	      par[0] = par0expo;
	      par[1] = par1expo;
	      par[2] = peak.Height;
	      par[3] = peak.Mean;
	      par[4] = peakWidth;
	      npeaks = 1;
	      TF1 *fit = new TF1("fit",fpeaks,peak.Mean-2.*peakWidth,peak.Mean+2.*peakWidth,2+3*npeaks);
	      TVirtualFitter::Fitter(hFEBCH[iCh],2+3*npeaks);	      
	      fit->SetParameters(par);
	      fit->SetNpx(int((peak.Mean+1.5*peakWidth)-(peak.Mean-1.5*peakWidth)));
	      hFEBCH[iCh]->Fit("fit","MQER+");
	      */
	     
	      TF1 *fit = new TF1("fit","gaus",peak.Mean-1.4*peakWidth,peak.Mean+1.7*peakWidth);
	      hFEBCH[iCh]->Fit("fit","MQER+");
	      fit->GetParameters(&vpar[0]);
	      peak.Height = vpar[0];
	      peak.Mean = vpar[1];
	      peak.Sigma = vpar[2];
	      vgPeaks.push_back(peak);
 
	      par[3*npeaks+2] = vpar[0];
	      par[3*npeaks+3] = vpar[1];
	      par[3*npeaks+4] = vpar[2];
	      npeaks++;
	    }
	    //cout << endl;
	   // cout << "npeaks = " << npeaks << endl;
	    for (Int_t iPar=0; iPar<2+3*npeaks; iPar++) {
	      ///	      cout << iPar << " " << par[iPar] << endl;
	    }



	    /*
	    TF1 *fitPeaks = new TF1("fitPeaks",fpeaks,p1.Mean-1.*peakWidth,p2.Mean+1.*peakWidth,2+3*npeaks);
	    TVirtualFitter::Fitter(hFEBCH[iCh],2+3*npeaks);
	    fitPeaks->SetParameters(par);
	    fitPeaks->SetNpx(int((p2.Mean+1.5*peakWidth)-(p1.Mean-1.5*peakWidth)));
	    //	    fitPeaks->SetNpx(512);
	    hFEBCH[iCh]->Fit("fitPeaks","MQER");
	    */

	    gain = 0.;
	    // Gain calculation
	    if (npeaks>1) {
	      nlocalgain = 0;
	      Double_t gainLocal = 0.;
	      for (Int_t iGain=1; iGain<npeaks; iGain++) {
                gainLocal = par[3*iGain+3] - par[3*(iGain-1)+3];
                if (abs(averageGain-gainLocal)>rangeGain) break;
                gain += gainLocal;
                cout << iGain << " : " << par[3*(iGain-1)+3] << " " << par[3*iGain+3] << endl;
                nlocalgain++;
	      }
	      cout << "nLocalgain = " << nlocalgain << endl;
	      gain = gain/nlocalgain;
	      cout << "gain = " << gain << endl;
	      cout << "vPeaks.size() = " << vPeaks.size() << endl;
          outGain <<iCh<< " " << gain << " " << par[3] << " ";
          for (Int_t iGain=1; iGain<npeaks; iGain++) {
                gainLocal = par[3*iGain+3] - par[3*(iGain-1)+3];
                if (abs(averageGain-gainLocal)>rangeGain) break;
                outGain << par[3*iGain+3] << " ";
          }
          outGain <<endl;
	    }

	  } // if (vPeaks.size()>1)  after removing peaks from the left

	} // if (vPeaks.size()>1)  after selected peaks above 5
      
      } // if (nfound>1)
      cout << endl;

      FEBdir->cd(); 
      hFEBCH[iCh]->Draw();
      hFEBCH[iCh]->GetYaxis()->SetTitle("Number of events");
      hFEBCH[iCh]->GetXaxis()->SetTitle("HG ADC channels");
      hFEBCH[iCh]->Write(); 
      c1->Update();
      delete hFEBCH[iCh];

      cout << ch << endl;

      vSigmaPeak.clear();
      vMeanPeak.clear();
      vHeightPeak.clear();
      npeaks = vgPeaks.size();
      npeaks = nlocalgain+1;
      for (vector<Peak>::iterator it = vgPeaks.begin(); it != vgPeaks.end(); it++ ) {
	peak = *it;
	vSigmaPeak.push_back(peak.Sigma);
	vMeanPeak.push_back(peak.Mean);
	vHeightPeak.push_back(peak.Height);
      }
      tCalibBM->Fill();
      
      //return 0;
    }
    
  
 /* for (Int_t ih=0; ih < 96;ih++){
    if (hFEBCH[ih]->GetEntries()>1) {
        c.SetLogy();
        hFEBCH[ih]->GetYaxis()->SetTitle("Number of events");
        hFEBCH[ih]->GetXaxis()->SetTitle("ADC channels");
        hFEBCH[ih]->Write();
        delete hFEBCH[ih];
    }
  }*/
}
  wfile.cd();
  tCalibBM-> Write();
  wfile.Close();
  tCalibBM->Delete();
  return 0;
}



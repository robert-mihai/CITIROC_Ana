#include <stdio.h>
#include <string.h>
#include <exception>
#include <fstream>
#include "MDdataWordBM.h"
#include "MDargumentHandler.h"

using namespace std;

int main( int argc, char **argv ) {
  string stringBuf;
  int    intBuf;

  // The following shows how to use the MDargumentHandler class
  // to deal with the main arguments
  // Define the arguments
  MDargumentHandler argh("Example of unpacking application.");
  argh.AddArgument("help","print this message","h");
  argh.AddArgument("directory","Path for a data file","d","<string>","." );
  argh.AddArgument("file","Name of a data file","f","<string>","mandatory");
  argh.AddArgument("begin","Initial position in input file","b","<int>","0");
  argh.AddArgument("nwords","Number of data words to be processed","n","<int>","0");

  // Check the user arguments consistancy
  // All mandatory arguments should be provided and
  // There should be no extra arguments
  if ( argh.ProcessArguments(argc, argv) ) {argh.Usage(); return -1;}

  // Treat arguments, obtain values to be used later
  if ( argh.GetValue("help") ) {argh.Usage(); return 0;}

  if ( argh.GetValue("directory", stringBuf) != MDARGUMENT_STATUS_OK ) return -1;
  string filepath = stringBuf;

  if ( argh.GetValue("file", stringBuf) != MDARGUMENT_STATUS_OK ) return -1;
  string filename = stringBuf;

  if ( argh.GetValue("begin", intBuf) != MDARGUMENT_STATUS_OK ) return -1;
  int pos = intBuf*4;

  if ( argh.GetValue("nwords", intBuf) != MDARGUMENT_STATUS_OK ) return -1;
  int nWords = intBuf;

  std::ifstream ifs((filepath + "/" + filename).c_str());
  if ( ifs.fail() ) {
    cerr << "Can not open file " << filepath << filename << endl;
    return 1;
  }

  cout << "This code was created only for Spill search."<<endl;
  cout << "Please enter SpillTag number:"<< endl;
  double SpillTag;
  cin >> SpillTag;
  
  uint32_t* dataPtr = new uint32_t;
  ifs.seekg(pos);
  int dataNum = 0;
  int dwCount(0);
  while (!ifs.eof()) {
    ifs.read((char*)dataPtr, 4 );
    MDdataWordBM dw(dataPtr);
    dataNum++;
    
   
                    
    switch (dw.GetDataType()) {
        case MDdataWordBM::SpillHeader:
        if ( dw.GetSpillTag() == SpillTag){
            cout << "Word number " << dataNum << " " << dw << endl;
            for (int temp = 0; temp<2000;temp++ ){
                ifs.read((char*)dataPtr, 4 );
                MDdataWordBM dw(dataPtr);
                dataNum++;
                cout << "Word number " << dataNum << " " << dw << endl;
            }
            return 0;
        }
        break;
                        
        default:
        break;
    }
            

    ++dwCount;

    if (nWords && dwCount == nWords)
      break;
  }

  return 0;
}



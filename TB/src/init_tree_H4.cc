#include "../interface/init_tree_H4.h"
   
    void InitTree(TChain* nt)
    {
        nt->SetBranchAddress("evtNumber", &evtNumber, &b_evtNumber);
        nt->SetBranchAddress("evtTimeDist", &evtTimeDist, &b_evtTimeDist);
        nt->SetBranchAddress("evtTimeStart", &evtTimeStart, &b_evtTimeStart);
	//        nt->SetBranchAddress("evtTime", &evtTime, &b_evtTime);
	//        nt->SetBranchAddress("boardTriggerBit", &boardTriggerBit, &b_boardTriggerBit);
	//        nt->SetBranchAddress("triggerWord", &triggerWord, &b_triggerWord);
        nt->SetBranchAddress("nAdcChannels", &nAdcChannels, &b_nAdcChannels);
        nt->SetBranchAddress("adcBoard", adcBoard, &b_adcBoard);
        nt->SetBranchAddress("adcChannel", adcChannel, &b_adcChannel);
        nt->SetBranchAddress("adcData", adcData, &b_adcData);
        nt->SetBranchAddress("nTdcChannels", &nTdcChannels, &b_nTdcChannels);
        nt->SetBranchAddress("tdcBoard", tdcBoard, &b_tdcBoard);
        nt->SetBranchAddress("tdcChannel", tdcChannel, &b_tdcChannel);
        nt->SetBranchAddress("tdcData", tdcData, &b_tdcData);
        nt->SetBranchAddress("nDigiSamples", &nDigiSamples, &b_nDigiSamples);
        nt->SetBranchAddress("digiGroup", digiGroup, &b_digiGroup);
        nt->SetBranchAddress("digiChannel", digiChannel, &b_digiChannel);
        nt->SetBranchAddress("digiSampleIndex", digiSampleIndex, &b_digiSampleIndex);
        nt->SetBranchAddress("digiSampleValue", digiSampleValue, &b_digiSampleValue);

        nt->SetBranchAddress("spillNumber", &spillNumber, &b_spillNumber); 

    }

void InitTree2(TChain* nt2)
{
  nt2->SetBranchAddress("TDCreco", &TDCreco);//, &b_TDCreco); 
        nt2->SetBranchAddress("spillNumber", &spillNumber, &b_spillNumber); 
        nt2->SetBranchAddress("evtNumber", &evtNumber, &b_evtNumber);

}

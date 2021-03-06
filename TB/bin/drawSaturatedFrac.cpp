/*****************************************************************************************
    This program draws efficiency plots

****************************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

#include "TROOT.h"
#include "TSystem.h"
#include "TKey.h"
#include "TFile.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TProfile.h"
#include "TF1.h"
#include "TString.h"
#include "TCut.h"
#include "TMath.h"
#include "TApplication.h"
#include "TError.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TPad.h"
#include "TStyle.h"
#include "TMultiGraph.h"
#include "TLegend.h"

using namespace std;

int main(int argc, char** argv)
{

  std::string plot_type = argv[1];
    //"EffAll";
  //    std::string plot_type = "AngScanHigh";
  //  std::string plot_type = "scanX0_HVLow_50";
  //  std::string plot_type = "scanX0_HVLow_20";
  std::cout<<plot_type<<std::endl;

  TFile* inF_MiB3_ON;
  TFile* inF_MiB3_OFF;
  TFile* inF_enSEE;
  TFile* inF_ZStack1_ON;
  TFile* inF_ZStack1_OFF;
  TFile* inF_ZStack2_ON;
  TFile* inF_ZStack2_OFF;

  TFile* inF_MiB3;
  TFile* inF_ZStack1;
  TFile* inF_ZStack2;

  TMultiGraph *mg = new TMultiGraph();

  TLegend *legC;

  if(plot_type == "EffAll"){
    legC = new TLegend(0.15,0.65,0.35,0.85,NULL,"brNDC");

    inF_MiB3_ON = TFile::Open("plots/efficiency_studies/MiB3_HV_HVScan2.root");
    inF_MiB3_OFF = TFile::Open("plots/efficiency_studies/MiB3_HV_HVScan7.root");
    inF_enSEE = TFile::Open("plots/efficiency_studies/enSEE_HV_HVScan5.root");
    inF_ZStack1_ON = TFile::Open("plots/efficiency_studies/ZStack1_HV_HVScan1.root");
    inF_ZStack1_OFF = TFile::Open("plots/efficiency_studies/ZStack1_HV_HVScan8.root");
    inF_ZStack2_ON = TFile::Open("plots/efficiency_studies/ZStack2_HV_HVScan2.root");
    inF_ZStack2_OFF = TFile::Open("plots/efficiency_studies/ZStack2_HV_HVScan6.root");

    TGraphErrors* eff_MiB3_ON = (TGraphErrors*)inF_MiB3_ON->Get("frac_saturated");
    TGraphErrors* eff_MiB3_OFF = (TGraphErrors*)inF_MiB3_OFF->Get("frac_saturated");
    TGraphErrors* eff_enSEE = (TGraphErrors*)inF_enSEE->Get("frac_saturated");
    TGraphErrors* eff_ZStack1_ON = (TGraphErrors*)inF_ZStack1_ON->Get("frac_saturated");
    TGraphErrors* eff_ZStack1_OFF = (TGraphErrors*)inF_ZStack1_OFF->Get("frac_saturated");
    TGraphErrors* eff_ZStack2_ON = (TGraphErrors*)inF_ZStack2_ON->Get("frac_saturated");
    TGraphErrors* eff_ZStack2_OFF = (TGraphErrors*)inF_ZStack2_OFF->Get("frac_saturated");

    //settings
    eff_MiB3_ON->SetMarkerColor(kGreen+1);
    eff_MiB3_ON->SetLineColor(kGreen+1);
    eff_MiB3_OFF->SetMarkerColor(kGreen+1);
    eff_MiB3_OFF->SetLineColor(kGreen+1);
    eff_ZStack2_ON->SetMarkerColor(kBlue);
    eff_ZStack2_ON->SetLineColor(kBlue);
    eff_ZStack1_ON->SetMarkerColor(kRed);
    eff_ZStack1_ON->SetLineColor(kRed);
    eff_ZStack2_OFF->SetMarkerColor(kBlue);
    eff_ZStack2_OFF->SetLineColor(kBlue);
    eff_ZStack1_OFF->SetMarkerColor(kRed);
    eff_ZStack1_OFF->SetLineColor(kRed);
    eff_enSEE->SetMarkerColor(1);
    eff_enSEE->SetLineColor(1);
  //
    eff_MiB3_ON->SetMarkerStyle(20);
    eff_MiB3_ON->SetLineWidth(2);
    eff_MiB3_ON->SetMarkerSize(0.7);
    eff_MiB3_OFF->SetMarkerStyle(22);
    eff_MiB3_OFF->SetLineWidth(2);
    eff_ZStack2_ON->SetMarkerStyle(20);
    eff_ZStack2_ON->SetLineWidth(2);
    eff_ZStack2_ON->SetMarkerSize(0.7);
    eff_ZStack1_ON->SetMarkerStyle(20);
    eff_ZStack1_ON->SetLineWidth(2);
    eff_ZStack1_ON->SetMarkerSize(0.7);
    eff_ZStack2_OFF->SetMarkerStyle(22);
    eff_ZStack2_OFF->SetLineWidth(2);
    eff_ZStack1_OFF->SetMarkerStyle(22);
    eff_ZStack1_OFF->SetLineWidth(2);
    eff_enSEE->SetMarkerStyle(22);
    eff_enSEE->SetLineWidth(2);


    legC->SetTextFont(42);
    legC->SetTextSize(0.03);
    legC->SetFillColor(kWhite);
    legC->SetLineColor(kWhite);
    legC->SetShadowColor(kWhite);

    legC->AddEntry(eff_MiB3_ON, "MiB3 chevron-ON", "p");
    legC->AddEntry(eff_MiB3_OFF, "MiB3 chevron-OFF", "p");
    legC->AddEntry(eff_ZStack2_ON, "ZStack2 ON", "p");
    legC->AddEntry(eff_ZStack2_OFF, "ZStack2 OFF", "p");
    legC->AddEntry(eff_ZStack1_ON, "ZStack1 ON", "p");
    legC->AddEntry(eff_ZStack1_OFF, "ZStack1 OFF", "p");
    legC->AddEntry(eff_enSEE, "SEE OFF", "p");
  
    mg->Add(eff_MiB3_ON);
    mg->Add(eff_MiB3_OFF);
    mg->Add(eff_ZStack1_ON);
    mg->Add(eff_ZStack1_OFF);
    mg->Add(eff_ZStack2_OFF);
    mg->Add(eff_ZStack2_ON);
    mg->Add(eff_ZStack2_OFF);
    mg->Add(eff_enSEE);

    TCanvas* c = new TCanvas();
    gPad->SetTicks();
    char plot_name[100];
    std::string command = "if [ ! -e final_plots/ ] ; then mkdir final_plots ; fi";
    system(command.c_str());
    sprintf(plot_name, "final_plots/saturatedFrac_%s.pdf", plot_type.c_str());

    mg->Draw("AP");
    mg->GetXaxis()->SetRangeUser(-0.1,5.1);
    mg->GetXaxis()->SetTitle("HV (V)");
    mg->GetYaxis()->SetTitle("SaturatedFrac");
    mg->SetMaximum(100);
    mg->SetMinimum(0);
    mg->Draw("AP");  
    legC->Draw("same");

    c->Print(plot_name, "pdf");
    sprintf(plot_name, "final_plots/saturatedFrac_%s.png", plot_type.c_str());
    c->Print(plot_name, "png");

  }

  else {

    legC = new TLegend(0.15,0.70,0.3,0.85,NULL,"brNDC");

    TGraphErrors* eff_MiB3;
    TGraphErrors* eff_enSEE;
    TGraphErrors* eff_ZStack1;
    TGraphErrors* eff_ZStack2;

    if(plot_type == "AngScanHigh"){
      inF_MiB3 = TFile::Open("plots/efficiency_studies/MiB3_X0_AngScan_HVHigh.root");
      inF_enSEE = TFile::Open("plots/efficiency_studies/enSEE_X0_AngScan_HVHigh.root");
      inF_ZStack1 = TFile::Open("plots/efficiency_studies/ZStack1_X0_AngScan_HVHigh.root");
    }
    if(plot_type == "AngScanLow"){
      inF_MiB3 = TFile::Open("plots/efficiency_studies/MiB3_X0_AngScan_HVLow.root");
      inF_enSEE = TFile::Open("plots/efficiency_studies/enSEE_X0_AngScan_HVLow.root");
      inF_ZStack1 = TFile::Open("plots/efficiency_studies/ZStack1_X0_AngScan_HVLow.root");
    }
    
    if(plot_type == "scanX0_HVHigh_50"){
      inF_MiB3 = TFile::Open("plots/efficiency_studies/MiB3_X0_scanX0_HVHigh50GeV.root");
      inF_enSEE = TFile::Open("plots/efficiency_studies/enSEE_X0_scanX0_HVHigh50GeV.root");
      inF_ZStack2 = TFile::Open("plots/efficiency_studies/ZStack2_X0_scanX0_HVHigh50GeV.root");
      inF_ZStack1 = TFile::Open("plots/efficiency_studies/ZStack1_X0_scanX0_HVHigh50GeV.root");
    }
    if(plot_type == "scanX0_HVHigh_20"){
      inF_MiB3 = TFile::Open("plots/efficiency_studies/MiB3_X0_scanX0_HVHigh20GeV.root");
      inF_enSEE = TFile::Open("plots/efficiency_studies/enSEE_X0_scanX0_HVHigh20GeV.root");
      inF_ZStack2 = TFile::Open("plots/efficiency_studies/ZStack2_X0_scanX0_HVHigh20GeV.root");
      inF_ZStack1 = TFile::Open("plots/efficiency_studies/ZStack1_X0_scanX0_HVHigh20GeV.root");
    }
    if(plot_type == "scanX0_HVLow_50"){
      inF_MiB3 = TFile::Open("plots/efficiency_studies/MiB3_X0_scanX0_HVLow50GeV.root");
      inF_enSEE = TFile::Open("plots/efficiency_studies/enSEE_X0_scanX0_HVLow50GeV.root");
      inF_ZStack2 = TFile::Open("plots/efficiency_studies/ZStack2_X0_scanX0_HVLow50GeV.root");
      inF_ZStack1 = TFile::Open("plots/efficiency_studies/ZStack1_X0_scanX0_HVLow50GeV.root");
    }
    if(plot_type == "scanX0_HVLow_20"){
      inF_MiB3 = TFile::Open("plots/efficiency_studies/MiB3_X0_scanX0_HVLow20GeV.root");
      inF_enSEE = TFile::Open("plots/efficiency_studies/enSEE_X0_scanX0_HVLow20GeV.root");
      inF_ZStack2 = TFile::Open("plots/efficiency_studies/ZStack2_X0_scanX0_HVLow20GeV.root");
      inF_ZStack1 = TFile::Open("plots/efficiency_studies/ZStack1_X0_scanX0_HVLow20GeV.root");
    }
    
    
    eff_MiB3 = (TGraphErrors*)inF_MiB3->Get("frac_saturated");
    eff_enSEE = (TGraphErrors*)inF_enSEE->Get("frac_saturated");
    eff_ZStack1 = (TGraphErrors*)inF_ZStack1->Get("frac_saturated");
    if (plot_type=="scanX0_HVLow_20" || plot_type=="scanX0_HVHigh_20" || plot_type=="scanX0_HVHigh_50" || plot_type=="scanX0_HVLow_50") 
      eff_ZStack2 = (TGraphErrors*)inF_ZStack2->Get("frac_saturated");
    
    //settings
    eff_MiB3->SetMarkerColor(kGreen+1);
    eff_MiB3->SetLineColor(kGreen+1);
    if (plot_type=="scanX0_HVLow_20" || plot_type=="scanX0_HVHigh_20" || plot_type=="scanX0_HVHigh_50" || plot_type=="scanX0_HVLow_50") {
      eff_ZStack2->SetMarkerColor(kBlue);
      eff_ZStack2->SetLineColor(kBlue);
    }
    eff_ZStack1->SetMarkerColor(kRed);
    eff_ZStack1->SetLineColor(kRed);
    eff_enSEE->SetMarkerColor(1);
    eff_enSEE->SetLineColor(1);
    //
    eff_MiB3->SetMarkerStyle(20);
    eff_MiB3->SetLineWidth(2);
    eff_MiB3->SetMarkerSize(0.7);
    if (plot_type=="scanX0_HVLow_20" || plot_type=="scanX0_HVHigh_20" || plot_type=="scanX0_HVHigh_50" || plot_type=="scanX0_HVLow_50") {
      eff_ZStack2->SetMarkerStyle(20);
      eff_ZStack2->SetLineWidth(2);
      eff_ZStack2->SetMarkerSize(0.7);
    }
    eff_ZStack1->SetMarkerStyle(20);
    eff_ZStack1->SetLineWidth(2);
    eff_ZStack1->SetMarkerSize(0.7);
    eff_enSEE->SetMarkerStyle(20);
    eff_enSEE->SetLineWidth(2);
    eff_enSEE->SetMarkerSize(0.7);
    
    legC->SetTextFont(42);
    legC->SetTextSize(0.03);
    legC->SetFillColor(kWhite);
    legC->SetLineColor(kWhite);
    legC->SetShadowColor(kWhite);
        
    if(plot_type == "AngScanLow"){
      legC->AddEntry(eff_MiB3, "MiB3 chevron-OFF HV 3000", "p");
      legC->AddEntry(eff_ZStack1, "ZStack1 OFF HV 3000", "p");
      legC->AddEntry(eff_enSEE, "SEE OFF HV 1900", "p");
    }
    if(plot_type == "AngScanHigh"){
      legC->AddEntry(eff_MiB3, "MiB3 chevron-OFF HV 3200", "p");
      legC->AddEntry(eff_ZStack1, "ZStack1 OFF HV 3200", "p");
      legC->AddEntry(eff_enSEE, "SEE OFF HV 2200", "p");
    }

    if(plot_type == "scanX0_HVHigh_50" || plot_type == "scanX0_HVHigh_20"){
      legC->AddEntry(eff_MiB3, "MiB3 chevron-OFF HV 3200", "p");
      legC->AddEntry(eff_ZStack1, "ZStack1 OFF HV 3200", "p");
      legC->AddEntry(eff_ZStack2, "ZStack2 OFF HV 3200", "p");
      legC->AddEntry(eff_enSEE, "SEE OFF  HV 2200", "p");
    }

    if(plot_type == "scanX0_HVLow_50" || plot_type == "scanX0_HVLow_20"){
      legC->AddEntry(eff_MiB3, "MiB3 chevron-OFF HV 3000", "p");
      legC->AddEntry(eff_ZStack1, "ZStack1 OFF HV 3000", "p");
      legC->AddEntry(eff_ZStack2, "ZStack2 OFF HV 3000", "p");
      legC->AddEntry(eff_enSEE, "SEE OFF  HV 1900", "p");
    }

    mg->Add(eff_MiB3);
    mg->Add(eff_ZStack1);
    mg->Add(eff_enSEE);
    if (plot_type=="scanX0_HVLow_20" || plot_type=="scanX0_HVHigh_20" || plot_type=="scanX0_HVHigh_50" || plot_type=="scanX0_HVLow_50") 
      mg->Add(eff_ZStack2);

    TCanvas* c = new TCanvas();
    gPad->SetTicks();
    char plot_name[100];
    std::string command = "if [ ! -e final_plots/ ] ; then mkdir final_plots ; fi";
    system(command.c_str());
    sprintf(plot_name, "final_plots/saturatedFrac_%s.pdf", plot_type.c_str());

    mg->Draw("AP");
    if (plot_type=="scanX0_HVLow_20" || plot_type=="scanX0_HVHigh_20" || plot_type=="scanX0_HVHigh_50" || plot_type=="scanX0_HVLow_50") 
      {
	mg->GetXaxis()->SetRangeUser(-0.1,5.1);
	mg->GetXaxis()->SetTitle("X0");
	mg->GetYaxis()->SetTitle("SaturatedFrac");
	mg->SetTitle(plot_type.c_str());
      }
    else
      {
	mg->GetXaxis()->SetRangeUser(-0.1, 50);
	mg->GetXaxis()->SetTitle("Angle (degrees)");
	mg->GetYaxis()->SetTitle("SaturatedFrac");
	mg->SetTitle(plot_type.c_str());
      }

    mg->SetMaximum(100);
    mg->SetMinimum(0);
    mg->Draw("AP");  
    legC->Draw("same");

    c->Print(plot_name, "pdf");
    sprintf(plot_name, "final_plots/saturatedFrac_%s.png", plot_type.c_str());
    c->Print(plot_name, "png");
  }


  return 0;
}


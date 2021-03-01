void crosstalk_all_ver_above300pe_channel_map()
{
//=========Macro generated from canvas: c2/c2
//=========  (Fri Aug 28 16:24:41 2020) by ROOT version 6.17/01
   TCanvas *c2 = new TCanvas("c2", "c2",0,0,800,600);
   c2->SetHighLightColor(2);
   c2->Range(-12,-12,108,108);
   c2->SetFillColor(0);
   c2->SetBorderMode(0);
   c2->SetBorderSize(2);
   c2->SetLogz();
   c2->SetFrameBorderMode(0);
   c2->SetFrameBorderMode(0);
   
   TH2D *Channel_map = new TH2D("Channel_map","Channel Map",96,0,96,96,0,96);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("Channel_map");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 0      ");
   ptstats_LaTex = ptstats->AddText("Mean x =      0");
   ptstats_LaTex = ptstats->AddText("Mean y =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev x =      0");
   ptstats_LaTex = ptstats->AddText("Std Dev y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   Channel_map->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(Channel_map);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Channel_map->SetLineColor(ci);
   Channel_map->GetXaxis()->SetTitle(" Monitor hit channel");
   Channel_map->GetXaxis()->SetLabelFont(42);
   Channel_map->GetXaxis()->SetLabelSize(0.035);
   Channel_map->GetXaxis()->SetTitleSize(0.035);
   Channel_map->GetXaxis()->SetTitleOffset(1);
   Channel_map->GetXaxis()->SetTitleFont(42);
   Channel_map->GetYaxis()->SetTitle(" Noise hit channel");
   Channel_map->GetYaxis()->SetLabelFont(42);
   Channel_map->GetYaxis()->SetLabelSize(0.035);
   Channel_map->GetYaxis()->SetTitleSize(0.035);
   Channel_map->GetYaxis()->SetTitleFont(42);
   Channel_map->GetZaxis()->SetLabelFont(42);
   Channel_map->GetZaxis()->SetLabelSize(0.035);
   Channel_map->GetZaxis()->SetTitleSize(0.035);
   Channel_map->GetZaxis()->SetTitleOffset(1);
   Channel_map->GetZaxis()->SetTitleFont(42);
   Channel_map->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.3769347,0.9341608,0.6230653,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("Channel Map");
   pt->Draw();
   c2->Modified();
   c2->cd();
   c2->SetSelected(c2);
}

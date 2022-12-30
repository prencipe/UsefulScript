{

gROOT->SetStyle("Plain");
gStyle->SetOptStat(0);

TFile ff("./Dati123456-Bch.root");
TTree* mio = dynamic_cast<TTree*>(ff.Get("t1"));


TH1F *histo_a2=new TH1F("histo_a2","",17.5,4.1,4.8);
TH1F *histo_a3=new TH1F("histo_a3","",17.5,4.1,4.8);
TH1F *histo_a4=new TH1F("histo_a4","",17.5,4.1,4.8);
TH1F *histo_a5=new TH1F("histo_a5","",17.5,4.1,4.8);

TCut prob("TMath::Prob(BChi2,BNdof)>0.0001");
TCut mes("Mes>5.27");


mio->Draw("TMath::Sqrt(BM12)>>histo_a2",prob);


histo_a3.Fill(4.117,4.);
histo_a3.Fill(4.155,3.);
histo_a3.Fill(4.185,4.);
histo_a3.Fill(4.225,6.);
histo_a3.Fill(4.265,13.);
histo_a3.Fill(4.305,3.);
histo_a3.Fill(4.345,19.);
histo_a3.Fill(4.385,20.);
histo_a3.Fill(4.425,23.);
histo_a3.Fill(4.465,20.);
histo_a3.Fill(4.505,16.);
histo_a3.Fill(4.545,19.);
histo_a3.Fill(4.585,16.);
histo_a3.Fill(4.625,13.);
histo_a3.Fill(4.665,6.);
histo_a3.Fill(4.705,3.);
histo_a3.Fill(4.745,0.1);
histo_a3.Fill(4.8,0.);
histo_a3.Draw();

const Int_t n = 19;

Float_t x[n]  = {4.105,4.125,4.155,4.185,4.225,4.265,4.305,4.345,4.385,4.425,4.465,4.505,4.545,4.585,4.625,4.665,4.705,4.745,4.8};

Float_t y[n]  = {0.,9,7,7,5,16,11,10,9,9,14,8,10,6,5,6,10,0.1,0.1};
Float_t ey[n]  = {0.,3,3,3,3,4,3,3,3,3,4,3,4,3,3,3,4,4,0.1};
Float_t ex[n] = {0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01,0.01};

histo_a2.SetMaximum(45);
histo_a3.SetMaximum(45);
histo_a2.SetFillColor(22);
histo_a2.Draw();
histo_a3.SetFillColor(2);
histo_a3.Draw("same");
histo_a3.Draw("esame");
histo_a2.Draw("esame");
histo_a2.SetXTitle("J/#psi#phi mass (GeV/c^{2})");
histo_a3.SetXTitle("J/#psi#phi mass (GeV/c^{2})");
histo_a4.SetXTitle("J/#psi#phi mass (GeV/c^{2})");
histo_a5.SetXTitle("J/#psi#phi mass (GeV/c^{2})");
histo_a2.SetYTitle("Evt/40 MeV/c^{2}");
histo_a3.SetYTitle("Evt/40 MeV/c^{2}");
histo_a4.SetYTitle("Evt/40 MeV/c^{2}");
histo_a5.SetYTitle("Evt/40 MeV/c^{2}");


histo_a3.Draw("esame");
histo_a2.Draw("esame");

int contsigakaon;int contbkgakaon;
double contsigaother;
int j; int jj;

TCanvas c33;
for(jj=0; jj<100;jj++){
  contsigakaon=0;
  contsigaother=0;
  contsigakaon=histo_a3->GetBinContent(jj+1);
  contbkgakaon=histo_a2->GetBinContent(jj+1);
  contsigaother= contbkgakaon - contsigakaon;
  histo_a4->SetBinContent(jj+1,contsigaother);
}
histo_a4.SetMaximum(40);
histo_a4->SetLineColor(kRed);
histo_a4->Draw("AP");
histo_a4.SetLineColor(1);
histo_a4.SetFillColor(44);
histo_a5->SetMaximum(40);
histo_a5.Draw();
histo_a4->Draw("esame");
histo_a4.SetMaximum(40);
histo_a4.SetMinimum(0);

TCanvas *c1 = new TCanvas("c1","invariant mass after bkg subtraction",300,10,700,500);
TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
//gr->SetTitle("m_{12} (GeV/c^{2})");
gr->SetTitle("J/#psi#phi mass (GeV/c^{2}) after bkg subtraction");
//gr->SetXTitle("Evt/40 mass (GeV/c^{2})");
  gr->SetMaximum(40.);
  gr->SetLineColor(4); 
  gr->SetMarkerColor(1);
  //  gr->SetMarkerStyle(21);
  gr->SetMarkerStyle(1);
  gr->Draw("AP");
  c1->Update();




}

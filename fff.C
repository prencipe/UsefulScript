#define fff_cxx
#include "fff.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"

//gaussiana biforcata
Double_t fitglr(Double_t *x, Double_t *par){
  double fitval;
  if(x[0]<par[0]) fitval=par[3]*TMath::Exp((-0.5)*((x[0]-par[0])/par[1])*((x[0]-par[0])/par[1]));
  if(x[0]>=par[0]) fitval=par[3]*TMath::Exp((-0.5)*((x[0]-par[0])/par[2])*((x[0]-par[0])/par[2]));
  return fitval;
}


//doppia gaussiana
Double_t fitf1(Double_t *x, Double_t *par){
  Double_t arg = 0;
  Double_t pol2 = 0;
  arg=par[2]*TMath::Exp((-0.5)*((x[0]-par[0])/par[1])*((x[0]-par[0])/par[1]));
  pol2=par[5]*TMath::Exp((-0.5)*((x[0]-par[3])/par[4])*((x[0]-par[3])/par[4]));
  // pol3=par[8]*TMath::Exp((-0.5)*((x[0]-par[6])/par[7])*((x[0]-par[6])/par[7]));
  Double_t fitval=arg+pol2;
  return fitval;
}

//gaussiana+pol2
Double_t fitdepi(Double_t *x, Double_t *par){
  Double_t gau = 0;
  Double_t pol2 = 0;
  gau=par[2]*TMath::Exp((-0.5)*((x[0]-par[0])/par[1])*((x[0]-par[0])/par[1]));
  pol2=par[3]+par[4]*x[0]+par[5]*x[0]*x[0];
  Double_t fitval=pol2+gau;
  return fitval;
}
//Pol2
Double_t fitbkg2(Double_t *x, Double_t *par){
  Double_t pol2 = 0;
  pol2=par[0]+par[1]*x[0]+par[2]*x[0]*x[0];
  Double_t fitval=pol2;
  return fitval;
}
//Pol1
Double_t fitbkg1(Double_t *x, Double_t *par){
  Double_t pol1 = 0;
  pol1=par[0]+par[1]*x[0];
  Double_t fitval=pol1;
  return fitval;
}
//gaussiana
Double_t fitg(Double_t *x, Double_t *par){
  Double_t gau = 0;
  gau=par[2]*TMath::Exp((-0.5)*((x[0]-par[0])/par[1])*((x[0]-par[0])/par[1]));
  Double_t fitval=gau;
  return fitval;
}
void fff::Loop(int erase=0,int fit=0)
{

   if (fChain == 0) return;

   Int_t nentries = Int_t(fChain->GetEntries());

   Int_t nbytes = 0, nb = 0;

   int dd,dd0,ee;
   

   hfisher1=new TH1D("hfisher1","hfisher",100,-2,3);
   hfisher2=new TH1D("hfisher2","hfisher",100,-2,3);
   hfisher5=new TH1D("hfisher5","hfisher",100,-0.1,0.25);
   hdepi=new TH1D("hdepi","hdepi",100,-0.1,0.2);
   hbkg1=new TH1D("hbkg1","histo",100,-0.1,0.2);
   hbkg2=new TH1D("hbkg2","histo",100,-0.1,0.2);
   massaD0=new TH1D("massaD0","histo",100,1.8,1.93);
   massaKs=new TH1D("massaKs","histo",100,0.48,0.52);

   
   for (Int_t jentry=0; jentry<nentries;jentry++) {
      Int_t ientry = LoadTree(jentry); //in case of a TChain, ientry is the entry number in the current file
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      dd=0;dd0=0;ee=0;
 // //  //     //Tagli per la selezione dei dok
//       if(Mes <5.2|| Mes>5.29) continue;
//       if(fabs(De)>0.03) continue;
//       if(Cosalfa<0.99) continue;
//       if(Md0<1.8526 ||Md0>1.8766) continue;
//       if(Mks<0.48867 ||Mks>0.50667) continue;
//       if(Moddz>0.15) continue;
//       if(abs(Hemidiff)>8) continue;
//       if(Modcost>1) continue;
//       if((Lp0<0)|| (Lp0>7)) continue; 
//       if((Lp2<-1)||(Lp2>4)) continue;
//       if(Plep>2.5)continue;
//       if(Pk>2.5)continue;
//       if(Chktype<4||Chktype>5 )continue;
      
      
      //  //   //Tagli per la selezione di Eli
      if(Mes <5.2|| Mes>5.29) continue;
      //      if(fabs(De)>0.05) continue;
      if(De<-0.1||De>0.2) continue;
      if(Cosalfa<0.99) continue;
      if(Md0<1.8526 ||Md0>1.8766) continue;
      if(Mks<0.48867 ||Mks>0.50667) continue;
      if(Moddz>0.15) continue;
      if(abs(Hemidiff)>8) continue;
      if(Modcost>1) continue;
      if((Lp0<0)|| (Lp0>7)) continue; 
      if((Lp2<-1)||(Lp2>4)) continue;
      if(Plep>2.5)continue;
      if(Pk>2.5)continue;
      if(Chktype<1||Chktype>4 )continue;


      
      //B+->D0bar k+
      if(Ndbp==2){
	if(Idd1bp==-421 && Idd2bp==321)dd=1;
	if(Idd1bp==321 && Idd2bp==-421)dd=1;
      }
      
      //B-->D0 k-
      if(Ndbm==2){
	if(Idd1bm==421 && Idd2bm==-321)dd=1;
	if(Idd1bm==-321 && Idd2bm==421)dd=1;
      }
      
     // B+ -> D0bar Pi+
      if(Ndbp==2){
	if(Idd1bp==-421 && Idd2bp==211)ee=1;
	if(Idd2bp==-421 && Idd1bp==211)ee=1;
      }
      
      // B- -> D0 Pi-
      if(Ndbm==2){
	if(Idd1bm==421 && Idd2bm==-211)ee=1;
	if(Idd2bm==421 && Idd1bm==-211)ee=1;
      }
     
 //      // B+ -> D*0bar Pi+
      if(Ndbp==2){
	if(Idd1bp==-423 && Idd2bp==211)ee=1;
	if(Idd2bp==-423 && Idd1bp==211)ee=1;
      }

      // B- -> D*0 Pi-
      if(Ndbm==2){
      if(Idd1bm==423 && Idd2bm==-211)ee=1;
      if(Idd2bm==423 && Idd1bm==-211)ee=1;
      }
      
      //D0->KsPiPi
      if(Ndd0==3 && dd==1 ) {
	if(Idd1d0==211 && Idd2d0==-211 && Idd3d0==310)dd0=1;
	if(Idd1d0==211 && Idd3d0==-211 && Idd2d0==310)dd0=1;
	if(Idd2d0==211 && Idd1d0==-211 && Idd3d0==310)dd0=1;
	if(Idd2d0==211 && Idd3d0==-211 && Idd1d0==310)dd0=1;
	if(Idd3d0==211 && Idd1d0==-211 && Idd2d0==310)dd0=1;
	if(Idd3d0==211 && Idd2d0==-211 && Idd1d0==310)dd0=1;
	
	//	K0->KsKl
	if(Idd1d0==211 && Idd2d0==-211 && abs(Idd3d0)==311  && abs(Idd1k0)==310)dd0=1;
	if(Idd1d0==211 && Idd3d0==-211 && abs(Idd2d0)==311  && abs(Idd1k0)==310)dd0=1;
	if(Idd2d0==211 && Idd1d0==-211 && abs(Idd3d0)==311  && abs(Idd1k0)==310)dd0=1;
	if(Idd2d0==211 && Idd3d0==-211 && abs(Idd1d0)==311  && abs(Idd1k0)==310)dd0=1;
	if(Idd3d0==211 && Idd1d0==-211 && abs(Idd2d0)==311  && abs(Idd1k0)==310)dd0=1;
	if(Idd3d0==211 && Idd2d0==-211 && abs(Idd1d0)==311  && abs(Idd1k0)==310)dd0=1;      

      }
      //erase=20 attiva Kspipi
      if(erase==20){
	if(dd0!=1)continue;
      }
      
      //erase=1 toglie il segnale
      if(erase==1){
	if(dd==1 && dd0==1)continue;
      }
      //erase=2 attiva D0pi e D*pi
      if(erase==2){
	if(ee!=1)continue;
      }

      //erase=3 toglie D0pi e D*pi e il segnale
      if(erase==3){
	if(ee==1 ||(dd==1 && dd0==1))continue;
      }
           
      //erase=3 toglie D0pi e D*pi
      if(erase==4){
	if(ee==1 && dd0==1)continue;
      }

      char name[100];
      
      sprintf(name,"hfisher1");
      ((TH1D*)gDirectory->Get(name))->Fill(Fishera);
      sprintf(name,"hfisher2");
      ((TH1D*)gDirectory->Get(name))->Fill(Fishera);
      sprintf(name,"hdepi");
      ((TH1D*)gDirectory->Get(name))->Fill(De);
      sprintf(name,"hbkg1");
      ((TH1D*)gDirectory->Get(name))->Fill(De);
      sprintf(name,"hbkg2");
      ((TH1D*)gDirectory->Get(name))->Fill(De);
      sprintf(name,"massaD0");
      ((TH1D*)gDirectory->Get(name))->Fill(Md0);
   }

   float mmm=0;
   for(int i=1;i<100;i++){
     if(massaKs->GetBinContent(i)>mmm)mmm=massaKs->GetBinContent(i);
   }

   if(fit==1){
     TF1 *f3 = new TF1("fitglr",fitglr,1.88,1.92,4);
     f3->SetParameters( massaD0->GetMean(),massaD0->GetRMS(),massaD0->GetRMS(),mmm);
     f3->SetParNames("m","sl","sr","n");
     f3->SetParLimits(0,0.48,0.52);
     f3->SetParLimits(1,0.00001,2);
     f3->SetParLimits(2,0.00001,2);
     f3->SetParLimits(3,0,1000000);
     
   //f3->FixParameter(0,1.865);
   //f3->FixParameter(1,0.0059);
   //f3->FixParameter(2,0);
   //f3->FixParameter(3,0);
   //  TCanvas c1;

     massaD0->Draw("E");
     massaD0->Fit("fitglr","RMVE+","ep");
   }
    
   if(fit==2){
     TF1 *f2 = new TF1("fitf1",fitf1,1.82,1.92,6);
     f2->SetParameters( massaD0->GetMean(),massaKs->GetRMS(),mmm/2,massaD0->GetMean(),massaD0->GetRMS(),mmm/2);
     f2->SetParNames("m1","s1","n1","m2","s2","n2");
     f2->SetParLimits(0,1.82,1.92);
     f2->SetParLimits(1,0.00001,2);
     f2->SetParLimits(2,0,1000000);
     f2->SetParLimits(3,1.82,1.92);
     f2->SetParLimits(4,0.00001,2);
     f2->SetParLimits(5,0,1000000);

   
   //f2->FixParameter(0,1.865);
   //f2->FixParameter(1,0.0059);
   //f2->FixParameter(2,0);
   //f2->FixParameter(3,0);
   // TCanvas c2;
     massaD0->Draw("E");
     massaD0->Fit("fitf1","RMVE+","ep");
   }

   if(fit==3){
     TF1 *f4 = new TF1("fitdepi",fitdepi,-0.1,0.25,6);
     f4->SetParameters( hdepi->GetMean(),hdepi->GetRMS(),mmm,0,0);
     f4->SetParNames("m1","s1","n1","p0","p1","p2");
     f4->SetParLimits(0,-0.1,0.2);
     f4->SetParLimits(1,0.000001,1);
     f4->SetParLimits(2,0,1000000);
     f4->SetParLimits(3,-1000000,1000000);
     f4->SetParLimits(4,-1000000,1000000);
     f4->SetParLimits(5,-1000000,1000000);

   
   //f2->FixParameter(0,1.865);
   //f2->FixParameter(1,0.0059);
   //f2->FixParameter(2,0);
   //f2->FixParameter(3,0);
   // TCanvas c2;
     hdepi->Draw("E");
     hdepi->Fit("fitdepi","RMVE+","ep");
   }


   if(fit==4){
     TF1 *f5 = new TF1("fitbkg1",fitbkg1,-0.1,0.25,2);
     f5->SetParameters( 0,0);
     f5->SetParNames("p0","p1");
     f5->SetParLimits(0,-1000000,1000000);
     f5->SetParLimits(1,-1000000,1000000);
   
   //f2->FixParameter(0,1.865);
   //f2->FixParameter(1,0.0059);
   //f2->FixParameter(2,0);
   //f2->FixParameter(3,0);
   // TCanvas c2;
     hbkg1->Draw("E");
     hbkg1->Fit("fitbkg1","RMVE+","ep");
   }


   if(fit==5){
     TF1 *f6 = new TF1("fitbkg2",fitbkg1,-0.1,0.25,3);
     f6->SetParameters(0, 0,0);
     f6->SetParNames("p0","p1","p2");
     f6->SetParLimits(0,-1000000,1000000);
     f6->SetParLimits(1,-1000000,1000000);
     f6->SetParLimits(2,-1000000,1000000);
   //f2->FixParameter(0,1.865);
   //f2->FixParameter(1,0.0059);
   //f2->FixParameter(2,0);
   //f2->FixParameter(3,0);
   // TCanvas c2;
     hbkg2->Draw("E");
     hbkg2->Fit("fitbkg2","RMVE+","ep");
   }

   if(fit==6){
     TF1 *f7 = new TF1("fitg",fitg,-0.1,0.25,3);
     f7->SetParameters( massaD0->GetMean(),hfisher5->GetRMS(),mmm);
     f7->SetParNames("m","s","n");
     f7->SetParLimits(0,1.8,1.93);
     f7->SetParLimits(1,0.000001,1);
     f7->SetParLimits(2,0,1000000);
   
   //f2->FixParameter(0,1.865);
   //f2->FixParameter(1,0.0059);
   //f2->FixParameter(2,0);
   //f2->FixParameter(3,0);
   // TCanvas c2;
     massaD0->Draw("E");
     massaD0->Fit("fitg","RMVE+","ep");
   }




}

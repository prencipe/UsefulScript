{
gROOT->SetStyle("Plain");
gStyle->SetOptStat(0);

int nsig; int nbkg; int j,jj; int n=100;
int contsig[100]; int contbkg[100];
int contsiga;int contbkga;

TFile f("lep.root");
f.cd("Vars_6_deltaz_disc_CosTMax_LP0_LP2_PLEP_/all");

TH1F *histo_s=new TH1F("histo_s","fisher_6",100,-1.5.,1.5);
TH1F *histo_b=new TH1F("histo_b","fisher_6",100,-1.5,1.5);
 
sig->Project("histo_s","brSig.fisher");
bkgd->Project("histo_b","brBkgd.fisher");


nsig=histo_s->GetEntries();
nbkg=histo_b->GetEntries();
cout << nbkg <<endl << endl <<nsig << endl;

   for(j=0; j<100;j++){
     contsiga=0;
     for(jj=j;jj<100; jj++){
       contsiga=contsiga+histo_s->GetBinContent(jj+1);
     }
     contsig[j]=contsiga;
   }
   for(j=0; j<100;j++){
     contbkga=0;
     for(jj=j;jj<100; jj++){
       contbkga=contbkga+histo_b->GetBinContent(jj+1);
     }
     contbkg[j]=contbkga;
   }



TGraph *histo=new TGraph(n,contbkg,contsig);
histo->GetXaxis()->SetTitle("Nbkgd");
histo->GetYaxis()->SetTitle("Nsig");
histo->SetMarkerStyle(8);
histo->SetMarkerSize(.5);
histo->SetMarkerColor(4);
histo->SetTitle("Plot fisher");
//TCanvas c3;
//histo->Draw("AP");


TFile ff("kaon.root");
ff.cd("Vars_6_deltaz_disc_CosTMax_LP0_LP2_PK_/all");
 
TH1F *histo_s1=new TH1F("histo_s","fisher_6",100,-1.5.,1.5);
TH1F *histo_b1=new TH1F("histo_b","fisher_6",100,-1.5,1.5);

sig->Project("histo_s","brSig.fisher");
bkgd->Project("histo_b","brBkgd.fisher");

nsig=histo_s1->GetEntries();
nbkg=histo_b1->GetEntries();
cout << nbkg <<endl << endl <<nsig << endl;


for(j=0; j<100;j++){
  contsiga=0;
  for(jj=j;jj<100; jj++){
    contsiga=contsiga+histo_s1->GetBinContent(jj+1);
  }
  contsig[j]=contsiga;
}

for(j=0; j<100;j++){
  contbkga=0;
  for(jj=j;jj<100; jj++){
    contbkga=contbkga+histo_b1->GetBinContent(jj+1);
  }
  contbkg[j]=contbkga;
}


TGraph *histo1=new TGraph(n,contbkg,contsig);
histo1->GetXaxis()->SetTitle("Nbkgd");
histo1->GetYaxis()->SetTitle("Nsig");
histo1->SetMarkerStyle(8);
histo1->SetMarkerSize(.5);
histo1->SetMarkerColor(2);
histo1->SetTitle("Plot fisher");
//TCanvas c2;
//histo1->Draw("AP");


   TFile fff("other.root");
   fff.cd("Vars_5_deltaz_disc_CosTMax_LP0_LP2_/all");

   TH1F *histo_s2=new TH1F("histo_s","fisher_5",100,-1.5.,1.5);
   TH1F *histo_b2=new TH1F("histo_b","fisher_5",100,-1.5,1.5);

   sig->Project("histo_s","brSig.fisher");
   bkgd->Project("histo_b","brBkgd.fisher");


   nsig=histo_s2->GetEntries();
   nbkg=histo_b2->GetEntries();
   cout << nbkg <<endl << endl <<nsig << endl;


      for(j=0; j<100;j++){
     contsiga=0;
     for(jj=j;jj<100; jj++){
       contsiga=contsiga+histo_s2->GetBinContent(jj+1);
     }
     contsig[j]=contsiga;
   }
   for(j=0; j<100;j++){
     contbkga=0;
     for(jj=j;jj<100; jj++){
       contbkga=contbkga+histo_b2->GetBinContent(jj+1);
     }
     contbkg[j]=contbkga;
   }

   TGraph *histo2=new TGraph(n,contbkg,contsig);
   histo2->GetXaxis()->SetTitle("Nbkgd");
   histo2->GetYaxis()->SetTitle("Nsig");
   histo2->SetMarkerStyle(8);
   histo2->SetMarkerSize(.5);
   histo2->SetMarkerColor(8);
   histo2->SetTitle("Plot fisher");
//  TCanvas c3;
//  histo2->Draw("AP");

   TFile a("5var_udsc.root");
   a.cd("Vars_5_deltaz_disc_CosTMax_LegendreP0ChB_LegendreP2ChB_/all");

   TH1F *histo_s3=new TH1F("histo_s","fisher_5",100,-1.5.,1.5);
   TH1F *histo_b3=new TH1F("histo_b","fisher_5",100,-1.5,1.5);

   sig->Project("histo_s","brSig.fisher");
   bkgd->Project("histo_b","brBkgd.fisher");


   nsig=histo_s3->GetEntries();
   nbkg=histo_b3->GetEntries();
   cout << nbkg <<endl << endl <<nsig << endl;


      for(j=0; j<100;j++){
     contsiga=0;
     for(jj=j;jj<100; jj++){
       contsiga=contsiga+histo_s3->GetBinContent(jj+1);
     }
     contsig[j]=contsiga;
   }
   for(j=0; j<100;j++){
     contbkga=0;
     for(jj=j;jj<100; jj++){
       contbkga=contbkga+histo_b3->GetBinContent(jj+1);
     }
     contbkg[j]=contbkga;
   }

   TGraph *histo3=new TGraph(n,contbkg,contsig);
   histo3->GetXaxis()->SetTitle("Nbkgd");
   histo3->GetYaxis()->SetTitle("Nsig");
   histo3->SetMarkerStyle(8);
   histo3->SetMarkerSize(.5);
   histo3->SetMarkerColor(1);
   histo3->SetTitle("Plot fisher");
//  TCanvas c6;
//  histo3->Draw("AP");



TH1F *sumsig=new TH1F("sumsig","somma",100,-1.5.,1.5);
sumsig->Add(histo_s1,histo_s);
sumsig->Add(histo_s2,histo_s3);
TCanvas c4;
sumsig->Draw();
TH1F *sumbkg=new TH1F("sumbkg","somma",100,-1.5.,1.5);
sumbkg->Add(histo_b1,histo_b);
sumbkg->Add(histo_b2,histo_b3);
TCanvas c5;
sumbkg->Draw();


for(j=0; j<100;j++){
  contsiga=0;
  for(jj=j;jj<50; jj++){
    contsiga=contsiga+sumsig->GetBinContent(jj+1);
  }
  contsig[j]=contsiga;
}
for(j=0; j<100;j++){
  contbkga=0;
  for(jj=j;jj<50; jj++){
    contbkga=contbkga+sumbkg->GetBinContent(jj+1);
  }
  contbkg[j]=contbkga;
}

TGraph *histosum4=new TGraph(n,contbkg,contsig);
histosum4->GetXaxis()->SetTitle("Nbkgd");
histosum4->GetYaxis()->SetTitle("Nsig");
histosum4->SetMarkerStyle(8);
histosum4->SetMarkerSize(.5);
histosum4->SetMarkerColor(8);
histosum4->SetTitle("Somma categorie");
//TCanvas c6;
//histosum4->Draw("AP");

for(j=0; j<100;j++){
  contsiga=0;
  for(jj=j;jj<60; jj++){
    contsiga=contsiga+sumsig->GetBinContent(jj+1);
  }
  contsig[j]=contsiga;
}
for(j=0; j<100;j++){
  contbkga=0;
  for(jj=j;jj<60; jj++){
    contbkga=contbkga+sumbkg->GetBinContent(jj+1);
  }
  contbkg[j]=contbkga;
}

TGraph *histosum5=new TGraph(n,contbkg,contsig);
histosum5->GetXaxis()->SetTitle("Nbkgd");
histosum5->GetYaxis()->SetTitle("Nsig");
histosum5->SetMarkerStyle(8);
histosum5->SetMarkerSize(.5);
histosum5->SetMarkerColor(7);
histosum5->SetTitle("Somma categorie");
//TCanvas c6;
//histosum5->Draw("AP");


for(j=0; j<100;j++){
  contsiga=0;
  for(jj=j;jj<70; jj++){
    contsiga=contsiga+sumsig->GetBinContent(jj+1);
  }
  contsig[j]=contsiga;
}
for(j=0; j<100;j++){
  contbkga=0;
  for(jj=j;jj<70; jj++){
    contbkga=contbkga+sumbkg->GetBinContent(jj+1);
  }
  contbkg[j]=contbkga;
}

TGraph *histosum7=new TGraph(n,contbkg,contsig);
histosum7->GetXaxis()->SetTitle("Nbkgd");
histosum7->GetYaxis()->SetTitle("Nsig");
histosum7->SetMarkerStyle(8);
histosum7->SetMarkerSize(.5);
histosum7->SetMarkerColor(6);
histosum7->SetTitle("Somma categorie");
//TCanvas c6;
//histosum7->Draw("AP");



for(j=0; j<100;j++){
  contsiga=0;
  for(jj=j;jj<80; jj++){
    contsiga=contsiga+sumsig->GetBinContent(jj+1);
  }
  contsig[j]=contsiga;
}
for(j=0; j<100;j++){
  contbkga=0;
  for(jj=j;jj<80; jj++){
    contbkga=contbkga+sumbkg->GetBinContent(jj+1);
  }
  contbkg[j]=contbkga;
}


TGraph *histosum8=new TGraph(n,contbkg,contsig);
histosum8->GetXaxis()->SetTitle("Nbkgd");
histosum8->GetYaxis()->SetTitle("Nsig");
histosum8->SetMarkerStyle(8);
histosum8->SetMarkerSize(.5);
histosum8->SetMarkerColor(5);
histosum8->SetTitle("Somma categorie");
//TCanvas c6;
//histosum7->Draw("AP");



for(j=0; j<100;j++){
  contsiga=0;
  for(jj=j;jj<90; jj++){
    contsiga=contsiga+sumsig->GetBinContent(jj+1);
  }
  contsig[j]=contsiga;
}
for(j=0; j<100;j++){
  contbkga=0;
  for(jj=j;jj<90; jj++){
    contbkga=contbkga+sumbkg->GetBinContent(jj+1);
  }
  contbkg[j]=contbkga;
}


TGraph *histosum9=new TGraph(n,contbkg,contsig);
histosum9->GetXaxis()->SetTitle("Nbkgd");
histosum9->GetYaxis()->SetTitle("Nsig");
histosum9->SetMarkerStyle(8);
histosum9->SetMarkerSize(.5);
histosum9->SetMarkerColor(8);
histosum9->SetTitle("Somma categorie");
//TCanvas c6;
//histosum7->Draw("AP");



for(j=0; j<100;j++){
  contsiga=0;
  for(jj=j;jj<100; jj++){
    contsiga=contsiga+sumsig->GetBinContent(jj+1);
  }
  contsig[j]=contsiga;
}
for(j=0; j<100;j++){
  contbkga=0;
  for(jj=j;jj<100; jj++){
    contbkga=contbkga+sumbkg->GetBinContent(jj+1);
  }
  contbkg[j]=contbkga;
}


TGraph *histosum0=new TGraph(n,contbkg,contsig);
histosum0->GetXaxis()->SetTitle("Nbkgd");
histosum0->GetYaxis()->SetTitle("Nsig");
histosum0->SetMarkerStyle(8);
histosum0->SetMarkerSize(.5);
histosum0->SetMarkerColor(2);
histosum0->SetTitle("Somma categorie");
//TCanvas c6;
//histosum7->Draw("AP");



TCanvas c7;
TMultiGraph *multi = new TMultiGraph();
//multi->Add(histosum4);
multi->Add(histosum5);
multi->Add(histosum7);
multi->Add(histosum8);
multi->Add(histosum9);
multi->Add(histosum0);

multi->Add(histo);
multi->Draw("A*");
multi->GetXaxis()->SetTitle("Nbkg");
multi->GetYaxis()->SetTitle("Nsig");
multi->GetXaxis()->SetLimits(0,2200);
multi->GetYaxis()->SetLimits(0,2500);
multi->Draw("A*");

// c3.Divide(1,3);
// c3.cd(1);
// sum->Draw();
// c3.cd(2);
// histo_s->Draw();
// c3.cd(3);
// histo_s1->Draw();

}

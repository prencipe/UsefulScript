{
gROOT->SetStyle("Plain");
gStyle->SetOptStat(0);

int nsig; int nbkg; int j,jj; int n=100;
int contsigall[100]; int contbkgall[100];
int contsigall1[100]; int contbkgall1[100];
int contsigall2[100]; int contbkgall2[100];
int contsigall3[100]; int contbkgall3[100];
int contsigall4[100]; int contbkgall4[100];
int contsig[100]; int contbkg[100];
int contsiglep[100]; int contbkglep[100];
int contsigother[100]; int contbkgother[100];
int contsigother1[100]; int contbkgother1[100];
int contsigother2[100]; int contbkgother2[100];
int contsigother3[100]; int contbkgother3[100];
int contsigother4[100]; int contbkgother4[100];
int contsigkaon[100]; int contbkgkaon[100];
int contsigaall;int contbkgaall;
int contsigaall1;int contbkgaall1;
int contsigaall2;int contbkgaall2;
int contsigaall3;int contbkgaall3;
int contsigaall4;int contbkgaall4;
int contsiga;int contbkga;
int contsigalep;int contbkgalep;
int contsigakaon;int contbkgakaon;
int contsigaother;int contbkgaother;
int contsigaother1;int contbkgaother1;
int contsigaother2;int contbkgaother2;
int contsigaother3;int contbkgaother3;
int contsigaother4;int contbkgaother4;


TFile a("5var_udsc.root");
a.cd("Vars_5_deltaz_disc_CosTMax_LegendreP0ChB_LegendreP2ChB_/all");

TH1F *histo_s=new TH1F("histo_s","fisher_5",100,-1.5.,1.5);
TH1F *histo_b=new TH1F("histo_b","fisher_5",100,-1.5,1.5);

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
histo->SetMarkerColor(1);
histo->SetTitle("Plot fisher");

///////////////////////////////////////////////////////////////////
TFile f("lep.root");
f.cd("Vars_6_deltaz_disc_CosTMax_LP0_LP2_PLEP_/all");

TH1F *histo_slep=new TH1F("histo_slep","fisher_6",100,-1.5.,1.5);
TH1F *histo_blep=new TH1F("histo_blep","fisher_6",100,-1.5,1.5);
 
sig->Project("histo_slep","brSig.fisher");
bkgd->Project("histo_blep","brBkgd.fisher");

nsig=histo_slep->GetEntries();
nbkg=histo_blep->GetEntries();
cout << nbkg <<endl << endl <<nsig << endl;

for(j=0; j<100;j++){
  contsigalep=0;
  for(jj=j;jj<100; jj++){
    contsigalep=contsigalep+histo_slep->GetBinContent(jj+1);
  }
  contsiglep[j]=contsigalep;
}
for(j=0; j<100;j++){
  contbkgalep=0;
  for(jj=j;jj<100; jj++){
    contbkgalep=contbkgalep+histo_blep->GetBinContent(jj+1);
  }
  contbkglep[j]=contbkgalep;
}

TGraph *histolep=new TGraph(n,contbkglep,contsiglep);
histolep->GetXaxis()->SetTitle("Nbkgd");
histolep->GetYaxis()->SetTitle("Nsig");
histolep->SetMarkerStyle(8);
histolep->SetMarkerSize(.5);
histolep->SetMarkerColor(4);
histolep->SetTitle("Plot fisher");


/////////////////////////////////////////////////////////////////
TFile ff("kaon.root");
ff.cd("Vars_6_deltaz_disc_CosTMax_LP0_LP2_PK_/all");
 
TH1F *histo_sk=new TH1F("histo_sk","fisher_6",100,-1.5.,1.5);
TH1F *histo_bk=new TH1F("histo_bk","fisher_6",100,-1.5,1.5);

sig->Project("histo_sk","brSig.fisher");
bkgd->Project("histo_bk","brBkgd.fisher");

nsig=histo_sk->GetEntries();
nbkg=histo_bk->GetEntries();
cout << nbkg <<endl << endl <<nsig << endl;

for(j=0; j<100;j++){
  contsigakaon=0;
  for(jj=j;jj<100; jj++){
    contsigakaon=contsigakaon+histo_sk->GetBinContent(jj+1);
  }
  contsigkaon[j]=contsigakaon;
}

for(j=0; j<100;j++){
  contbkgakaon=0;
  for(jj=j;jj<100; jj++){
    contbkgakaon=contbkgakaon+histo_bk->GetBinContent(jj+1);
  }
  contbkgkaon[j]=contbkgakaon;
}


TGraph *histok=new TGraph(n,contbkgkaon,contsigkaon);
histok->GetXaxis()->SetTitle("Nbkgd");
histok->GetYaxis()->SetTitle("Nsig");
histok->SetMarkerStyle(8);
histok->SetMarkerSize(.5);
histok->SetMarkerColor(2);
histok->SetTitle("Plot fisher");

////////////////////////////////////////////////////
TFile fff("other.root");
fff.cd("Vars_5_deltaz_disc_CosTMax_LP0_LP2_/all");

TH1F *histo_so=new TH1F("histo_so","fisher_5",100,-1.5,1.5);
TH1F *histo_bo=new TH1F("histo_bo","fisher_5",100,-1.5,1.5);

sig->Project("histo_so","brSig.fisher");
bkgd->Project("histo_bo","brBkgd.fisher");


nsig=histo_so->GetEntries();
nbkg=histo_bo->GetEntries();
cout << nbkg <<endl << endl <<nsig << endl;


for(j=0; j<100;j++){
  contsigaother=0;
  for(jj=j;jj<100; jj++){
    contsigaother=contsigaother+histo_so->GetBinContent(jj+1);
  }
  contsigother[j]=contsigaother;
}
for(j=0; j<100;j++){
  contbkgaother=0;
  for(jj=j;jj<100; jj++){
    contbkgaother=contbkgaother+histo_bo->GetBinContent(jj+1);
  }
  contbkgother[j]=contbkgaother;
}

TGraph *histoo=new TGraph(n,contbkgother,contsigother);
histoo->GetXaxis()->SetTitle("Nbkgd");
histoo->GetYaxis()->SetTitle("Nsig");
histoo->SetMarkerStyle(8);
histoo->SetMarkerSize(.5);
histoo->SetMarkerColor(8);
histoo->SetTitle("Plot fisher");
//TCanvas c1;
//histoo->Draw("AP");

for(j=0; j<100;j++){
  contsigaother1=0;
  for(jj=j;jj<20; jj++){
    contsigaother1=contsigaother1+histo_so->GetBinContent(jj+1);
  }
  contsigother1[j]=contsigaother1;
}
for(j=0; j<100;j++){
  contbkgaother1=0;
  for(jj=j;jj<20; jj++){
    contbkgaother1=contbkgaother1+histo_bo->GetBinContent(jj+1);
  }
  contbkgother1[j]=contbkgaother1;
}

TGraph *histoo1=new TGraph(n,contbkgother1,contsigother1);
histoo1->GetXaxis()->SetTitle("Nbkgd");
histoo1->GetYaxis()->SetTitle("Nsig");
histoo1->SetMarkerStyle(8);
histoo1->SetMarkerSize(.5);
histoo1->SetMarkerColor(2);
histoo1->SetTitle("Plot fisher");
//TCanvas c2;
//histoo1->Draw("AP");


for(j=0; j<100;j++){
  contsigaother2=0;
  for(jj=j;jj<50; jj++){
    contsigaother2=contsigaother2+histo_so->GetBinContent(jj+1);
  }
  contsigother2[j]=contsigaother2;
}
for(j=0; j<100;j++){
  contbkgaother2=0;
  for(jj=j;jj<50; jj++){
    contbkgaother2=contbkgaother2+histo_bo->GetBinContent(jj+1);
  }
  contbkgother2[j]=contbkgaother2;
}

TGraph *histoo2=new TGraph(n,contbkgother2,contsigother2);
histoo2->GetXaxis()->SetTitle("Nbkgd");
histoo2->GetYaxis()->SetTitle("Nsig");
histoo2->SetMarkerStyle(8);
histoo2->SetMarkerSize(.5);
histoo2->SetMarkerColor(5);
histoo2->SetTitle("Plot fisher");
//TCanvas c3;
//histoo2->Draw("AP");


for(j=0; j<100;j++){
  contsigaother3=0;
  for(jj=j;jj<70; jj++){
    contsigaother3=contsigaother3+histo_so->GetBinContent(jj+1);
  }
  contsigother3[j]=contsigaother3;
}
for(j=0; j<100;j++){
  contbkgaother3=0;
  for(jj=j;jj<70; jj++){
    contbkgaother3=contbkgaother3+histo_bo->GetBinContent(jj+1);
  }
  contbkgother3[j]=contbkgaother3;
}

TGraph *histoo3=new TGraph(n,contbkgother3,contsigother3);
histoo3->GetXaxis()->SetTitle("Nbkgd");
histoo3->GetYaxis()->SetTitle("Nsig");
histoo3->SetMarkerStyle(8);
histoo3->SetMarkerSize(.5);
histoo3->SetMarkerColor(7);
histoo3->SetTitle("Plot fisher");
//TCanvas c4;
//histoo3->Draw("AP");


for(j=0; j<100;j++){
  contsigaother4=0;
  for(jj=j;jj<80; jj++){
    contsigaother4=contsigaother4+histo_so->GetBinContent(jj+1);
  }
  contsigother4[j]=contsigaother4;
}
for(j=0; j<100;j++){
  contbkgaother4=0;
  for(jj=j;jj<80; jj++){
    contbkgaother4=contbkgaother4+histo_bo->GetBinContent(jj+1);
  }
  contbkgother4[j]=contbkgaother4;
}

TGraph *histoo4=new TGraph(n,contbkgother4,contsigother4);
histoo4->GetXaxis()->SetTitle("Nbkgd");
histoo4->GetYaxis()->SetTitle("Nsig");
histoo4->SetMarkerStyle(8);
histoo4->SetMarkerSize(.5);
histoo4->SetMarkerColor(8);
histoo4->SetTitle("Plot fisher");
//TCanvas c5;
//histoo4->Draw("AP");

//////////////////////SOVRAPPOSIZIONE///////////////////////////
for(j=0;j<100;j++){
  contsigaall=0;
  contsigaall=contsigaall+contsigalep+contsigother[j]+contsigkaon[50];
  contsigall[j]=contsigaall;
  contbkgaall=0;
  contbkgaall=contbkgaall+contbkgalep+contbkgother[j]+contbkgkaon[50];
  contbkgall[j]=contbkgaall;
}

TGraph *histosum0=new TGraph(n,contbkgall,contsigall);
histosum0->GetXaxis()->SetTitle("Nbkgd");
histosum0->GetYaxis()->SetTitle("Nsig");
histosum0->SetMarkerStyle(8);
histosum0->SetMarkerSize(.5);
histosum0->SetMarkerColor(2);
histosum0->SetTitle("Somma categorie");
histosum0->SetMinimum(167);
histosum0->GetXaxis()->SetLimits(1230,10000);
TCanvas c7;
histosum0->Draw("AP");

for(j=0;j<100;j++){
  contsigaall1=0;
  contsigaall1=contsigaall1+contsigalep+contsigother1[j]+contsigkaon[50];
  contsigall1[j]=contsigaall1;
  contbkgaall1=0;
  contbkgaall1=contbkgaall1+contbkgalep+contbkgother1[j]+contbkgkaon[50];
  contbkgall1[j]=contbkgaall1;
}

TGraph *histosum1=new TGraph(n,contbkgall1,contsigall1);
histosum1->GetXaxis()->SetTitle("Nbkgd");
histosum1->GetYaxis()->SetTitle("Nsig");
histosum1->SetMarkerStyle(8);
histosum1->SetMarkerSize(.5);
histosum1->SetMarkerColor(3);
histosum1->SetTitle("Somma categorie");
histosum1->SetMinimum(167);
histosum1->GetXaxis()->SetLimits(1230,2000);
TCanvas c8;
histosum1->Draw("AP");


for(j=0;j<100;j++){
  contsigaall2=0;
  contsigaall2=contsigaall2+contsigalep+contsigother2[j]+contsigkaon[50];
  contsigall2[j]=contsigaall2;
  contbkgaall2=0;
  contbkgaall2=contbkgaall2+contbkgalep+contbkgother2[j]+contbkgkaon[50];
  contbkgall2[j]=contbkgaall2;
}

TGraph *histosum2=new TGraph(n,contbkgall2,contsigall2);
histosum2->GetXaxis()->SetTitle("Nbkgd");
histosum2->GetYaxis()->SetTitle("Nsig");
histosum2->SetMarkerStyle(8);
histosum2->SetMarkerSize(.5);
histosum2->SetMarkerColor(4);
histosum2->SetTitle("Somma categorie");
histosum2->SetMinimum(167);
histosum2->GetXaxis()->SetLimits(1230,8000);
TCanvas c9;
histosum2->Draw("AP");


for(j=0;j<100;j++){
  contsigaall3=0;
  contsigaall3=contsigaall3+contsigalep+contsigother3[j]+contsigkaon[50];
  contsigall3[j]=contsigaall3;
  contbkgaall3=0;
  contbkgaall3=contbkgaall3+contbkgalep+contbkgother3[j]+contbkgkaon[50];
  contbkgall3[j]=contbkgaall3;
}

TGraph *histosum3=new TGraph(n,contbkgall3,contsigall3);
histosum3->GetXaxis()->SetTitle("Nbkgd");
histosum3->GetYaxis()->SetTitle("Nsig");
histosum3->SetMarkerStyle(8);
histosum3->SetMarkerSize(.5);
histosum3->SetMarkerColor(6);
histosum3->SetTitle("Somma categorie");
histosum3->SetMinimum(167);
histosum3->GetXaxis()->SetLimits(1230,10000);
TCanvas c10;
histosum3->Draw("AP");


for(j=0;j<100;j++){
  contsigaall4=0;
  contsigaall4=contsigaall4+contsigalep+contsigother4[j]+contsigkaon[50];
  contsigall4[j]=contsigaall4;
  contbkgaall4=0;
  contbkgaall4=contbkgaall4+contbkgalep+contbkgother4[j]+contbkgkaon[50];
  contbkgall4[j]=contbkgaall4;
}

TGraph *histosum4=new TGraph(n,contbkgall4,contsigall4);
histosum4->GetXaxis()->SetTitle("Nbkgd");
histosum4->GetYaxis()->SetTitle("Nsig");
histosum4->SetMarkerStyle(8);
histosum4->SetMarkerSize(.5);
histosum4->SetMarkerColor(7);
histosum4->SetTitle("Somma categorie");
histosum4->SetMinimum(167);
histosum4->GetXaxis()->SetLimits(1230,10000);
TCanvas c11;
histosum4->Draw("AP");

//////////////////PLOT FINALE/////////////////////////////////

TCanvas c12;
TMultiGraph *multi = new TMultiGraph();
//multi->Add(histosum4);
multi->Add(histosum0);
multi->Add(histosum1);
multi->Add(histosum2);
multi->Add(histosum3);
multi->Add(histosum4);

multi->Add(histo);
multi->Draw("A*");
multi->GetXaxis()->SetTitle("Nbkg");
multi->GetYaxis()->SetTitle("Nsig");
multi->SetMinimum(167);
multi->GetXaxis()->SetLimits(1230,10000);
multi->Draw("A*");


}

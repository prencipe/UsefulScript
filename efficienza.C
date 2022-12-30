  {
    float contsig[100];float contbkg[100]; int j; int n=100;

    TFile bk1("mc_udscb_d0kkspipi5VAR.root");
    TFile sig1("mc_sig_d0kkspipi5VAR.root");
    //  TH1F *histo=new TH1F("histo","plot_eff",100,0.0,1.0);
    sig1.cd();
    sig1.cd("BRECO");
    //   TCanvas c1;
    //    h870->Draw();
    for(j=0; j<100;j++){
      contsig[j]=h870->GetBinContent(j+1);
      //    cout<<contsig[j]<<endl;
    }
    bk1.cd();
    bk1.cd("BRECO");
    //   TCanvas c2;
    //    h870->Draw();
    for(j=0; j<100;j++){
      contbkg[j]=h870->GetBinContent(j+1);
      //    cout<<contbkg[j]<<endl;
    }
    //histo->GetXaxis->SetTitle("segnale");
    //histo->GetYaxis()->SetTitle("fondo");
    
    
    TGraph *histo1=new TGraph(n,contsig,contbkg);
    histo1->GetXaxis()->SetTitle("fondo");
    histo1->GetYaxis()->SetTitle("segnale");
    histo1->SetMarkerStyle(8);
    histo1->SetMarkerSize(.5);
    histo1->SetMarkerColor(1);
    histo1->SetTitle("Plot efficienza");
    TCanvas c3;
    
    histo1->Draw("AP");

    
    
  }

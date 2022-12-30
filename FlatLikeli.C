//reduced ntuple

{

TFile f("../SJM_SP-3245_dk_Run4-10-dk-kpi.root");

TTree *theTree = (TTree*) f->Get("ntp1"); 

//A couple of variables - declared as floats, change if appropriate.
 Int_t nB, BLund, oneIdx, twoIdx, BIdx,one, two ;
 Int_t nD, DLund, DoneIdx, DtwoIdx, DIdx, Done, Dtwo ;
 Float_t coscandROE, cosROE, cosCM;
 Float_t hemidiff, Bcos, Bphi, Dmass;
 Float_t Mes, De, fish, L0, L2, Bmom ;


//Change the names of the branches if appropriate
 theTree->SetBranchAddress("nBch",&nB);
 theTree->SetBranchAddress("nD0",&nD);
 theTree->SetBranchAddress("BchLund",&BLund);
 theTree->SetBranchAddress("BchMCIdx",&BIdx);
 theTree->SetBranchAddress("BchmES",&Mes);
 theTree->SetBranchAddress("BchdeltaE",&De);
 theTree->SetBranchAddress("BchHemiChDiff", &hemidiff);
 //theTree->SetBranchAddress("MyFisher3",&fish);
 theTree->SetBranchAddress("BchdeltaE",&De);
 theTree->SetBranchAddress("Bchcosth",&Bcos);
 theTree->SetBranchAddress("Bchphi",&Bphi);
 theTree->SetBranchAddress("Bchp3",&Bmom);
 theTree->SetBranchAddress("BchL10",&L0);
 theTree->SetBranchAddress("BchL12",&L2);
 theTree->SetBranchAddress("BchcosThrustCandROE",&coscandROE);
 // theTree->SetBranchAddress("BchcosThrustROE",&cosROE);
 theTree->SetBranchAddress("BchcosthCM",&cosCM);
 theTree->SetBranchAddress("Bchd1Lund",&one);
 theTree->SetBranchAddress("Bchd2Lund",&two);
 theTree->SetBranchAddress("Bchd1Idx",&oneIdx);
 theTree->SetBranchAddress("Bchd2Idx",&twoIdx);
 theTree->SetBranchAddress("D0d1Lund",&Done);
 theTree->SetBranchAddress("D0d2Lund",&Dtwo);
 theTree->SetBranchAddress("D0d1Idx",&DoneIdx);
 theTree->SetBranchAddress("D0d2Idx",&DtwoIdx);
 theTree->SetBranchAddress("D0Lund",&DLund);
 theTree->SetBranchAddress("D0Mass",&Dmass);


 int i;
 ofstream ofdata("MC.txt");
 for (int i = 0; i < theTree->GetEntries(); i++) {
   // get the event
   theTree->GetEntry(i);
   cout <<"ECCOOOOOOOO"<<endl;   
   //   if(Mes>5.2&&Mes<5.29){
   if(BIdx>0){     ofdata << Mes<<endl;}
   
 }
}

/*
     &&De>-0.1&&De<0.1
      &&L0>1&&L0<8.
      &&L2>0.&&L2<5.
      //only D0K      &&abs(oneIdx)==421
      &&abs(twoIdx)==321
      &&abs(DoneIdx)==321
      &&abs(DtwoIdx)==211
      ){
     ofdata << Mes<<endl;
     //  ofdata << massa<<endl;
     //      ofdata << mes <<" "<< fish <<" "<< de <<" " <<p1 <<" "<< p2 <<" "<< p3<< endl;
     }*/
// }
//}



{
  //  TFile f("../NTP/Ntuples/DATIBch_41old.root");
      TFile f("../NTP/Ntuples/sig2841_ana41.root");
  //    TFile f("../NTP/Ntuples/UdscbBch_41new.root");
TTree *theTree = (TTree*) f->Get("t1"); //h12 or whatever the name of your ntuple is

//A couple of variables - declared as floats, change if appropriate.
 Float_t mes, de, fish, p1, p2, p3, l1, l2, Bmom, cos;
 Float_t phiM, JPMee, JPMmm,  phiMom, JPMom, KMom, m012;
 Float_t ep, em,  Ejp, Ek, kp, km, mpp, pp, pm, Ep, m013,m023;
 Float_t ln, mum, mup, aphi, a12, a23, a13;
//Change the names of the branches if appropriate
 theTree->SetBranchAddress("Mes",&mes);
 theTree->SetBranchAddress("MyFisher3",&fish);
 theTree->SetBranchAddress("DeltaE",&de);
 theTree->SetBranchAddress("px",&p1);
 theTree->SetBranchAddress("py",&p2);
 theTree->SetBranchAddress("pz",&p3);
 theTree->SetBranchAddress("L0",&l1);
 theTree->SetBranchAddress("L2",&l2);
 theTree->SetBranchAddress("L2norm",&ln);
 theTree->SetBranchAddress("phiMass",&phiM);
 theTree->SetBranchAddress("sMee",&JPMee);
 theTree->SetBranchAddress("sMmm",&JPMmm);
 theTree->SetBranchAddress("M13",&m013);
 theTree->SetBranchAddress("M23",&m023);
 theTree->SetBranchAddress("M12",&m012);
 theTree->SetBranchAddress("sMPP",&mpp);
 theTree->SetBranchAddress("PhiMomentum",&phiMom);
 theTree->SetBranchAddress("JPMomentum",&JPMom);
 theTree->SetBranchAddress("KchMomentum",&KMom);
 theTree->SetBranchAddress("BMomentum",&Bmom);
 theTree->SetBranchAddress("EJP",&Ejp);
 theTree->SetBranchAddress("EPhi",&Ep);
 theTree->SetBranchAddress("EKch",&Ek);
 theTree->SetBranchAddress("KpMomentum",&kp);
 theTree->SetBranchAddress("KmMomentum",&km);
 theTree->SetBranchAddress("Costh",&cos);
 theTree->SetBranchAddress("Angphi",&aphi);
 theTree->SetBranchAddress("PpMomentum",&pp);
 theTree->SetBranchAddress("PmMomentum",&pm);
 theTree->SetBranchAddress("ElecpMomentum",&ep);
 theTree->SetBranchAddress("ElecmMomentum",&em);
 theTree->SetBranchAddress("MupMomentum",&mup);
 theTree->SetBranchAddress("MumMomentum",&mum);
 theTree->SetBranchAddress("CosAlpha12",&a12);
 theTree->SetBranchAddress("CosAlpha23",&a23);
 theTree->SetBranchAddress("CosAlpha13",&a13);




 ofstream ofdata("MC.txt");
 for (int i = 0; i < theTree->GetEntries(); i++) {
   // get the event
   theTree->GetEntry(i);
   if(mes>5.2&&mes<5.29
      // &&l1>1.5&&l1<8.
      // &&l2>-2.&&l2<3.
      //&&ln>-0.4&&ln<0.565
      &&JPMee>2.97&&JPMee<3.14&&JPMmm<3.14&&JPMmm>3.056
      // &&kp>0.15&&km>0.15&&ep>0.&&em>0.&&mum>0.&&mup>0.
      //&&cos>0.96
      //TMath::Abs(aphi)<3.1
      // &&a12>-0.94&&a12<0.99&&a13>-0.56&&a13<0.99&&a23>-0.56&&a23<0.99
      ){
     ofdata << mes<<endl;
     
     //      ofdata << mes <<" "<< fish <<" "<< de <<" " <<p1 <<" "<< p2 <<" "<< p3<< endl;
   }
 }
}



#define likeli_cxx
#include "likeli.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "math"
//---------------------------------------------------------------------------
bool likeli::cut(){
  bool cut1,cut2,cut3,cut4,cut5,cut6,cut7,cut8,cut9,cut10,cut11,cut12,cut13,cutt;

  //  cut1 = (fabs(Mks-0.4977)<0.009);
  //  cut2 = (fabs(Md0-1.8645)<0.012);
  cut1 = (Md0>1.8526 && Mks<1.8766);
  cut2 = (Mks>0.48867 && Mks<0.50667);
  cut3 = (De>-0.1 && De<0.2);
  cut4 = (Mes>5.2 && Mes<5.29);
  cut5 = (Cosalfa>0.99);
  cut6 = (Chktype>=1 && Chktype<=4);
  cut7 = (Moddz<0.15);
  cut8 = (abs(Hemidiff)<8);
  cut9 = (Modcost<1);
  cut10 =(Lp0>0 && Lp0<7);
  cut11 =(Lp2>-1 && Lp2<4);
  cut12 =(Plep<2.5);
  cut13 =(Pk<2.5);


  cutt= cut1 && cut2 && cut3 && cut4 && cut5 && cut6 && cut7 && cut8 && cut9 && cut10 && cut11 && cut12 && cut13;
  return cutt;
}

//---------------------------------------------------------------------------

void likeli::Corr(int i, int j){
  if (fChain == 0) return;

  Int_t nentries = Int_t(fChain->GetEntries());

  Int_t nbytes = 0, nb = 0;

  double messum, desum, mesmed, demed, messig, desig;
  double messumq, desumq, mesmedq, demedq, mesdesum, mesdemed;
  double corr;
  double Var1, Var2;



  messum=0; desum=0; messumq=0; desumq=0; mesdesum=0;


  for (Int_t jentry=0; jentry<nentries;jentry++) {
    Int_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    if(!cut())continue;

    if(i==1)Var1=Mes;
    if(i==2)Var1=De;
    if(i==3)Var1=Fisher;
    if(j==1)Var2=Mes;
    if(j==2)Var2=De;
    if(j==3)Var2=Fisher;


    messum=messum+Var1;
    desum=desum+Var2;
    messumq=messumq+(Var1*Var1);
    desumq=desumq+(Var2*Var2);
    mesdesum=mesdesum+(Var1*Var2);

  }


  mesmed=messum/nentries;
  demed=desum/nentries;
  mesmedq=messumq/nentries;
  demedq=desumq/nentries;
  mesdemed=mesdesum/nentries;

  messig=sqrt(mesmedq-(mesmed*mesmed));
  desig=sqrt(demedq-(demed*demed));

  corr=(mesdemed-(mesmed*demed))/(messig*desig);

  cout<<"mesmed = "<<mesmed<<endl;
  cout<<"demed = "<<demed<<endl;
  cout<<"mesmedq = "<<mesmedq<<endl;
  cout<<"demedq = "<<demedq<<endl;
  cout<<"mesdemed = "<<mesdemed<<endl;
  cout<<"messig = "<<messig<<endl;
  cout<<"desig = "<<desig<<endl;
  cout<<"corr = "<<corr<<endl;

}
//-------------------------------------------------------------------------------------


void likeli::Loop(int erase=0)
{

   if (fChain == 0) return;

   ofstream file1;
//    ofstream file2;
//    ofstream file3;
//    ofstream file4;
//    ofstream file5;
//    ofstream file6;

   file1.open("file1.txt");
//    file2.open("file2.txt");
//    file3.open("file3.txt");
//    file4.open("file4.txt");
//    file5.open("file5.txt");
//    file6.open("file6.txt");

   Int_t nentries = Int_t(fChain->GetEntriesFast());

   Int_t nbytes = 0, nb = 0;
   for (Int_t jentry=0; jentry<nentries;jentry++) {
      Int_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //    if(!cut())continue;

      int  dd=0;int dd0=0;int ee=0;int ff=0;int hh=0;int gg=0; int aa;int  ddp=0;int  ddm=0;
      int  pp=0;int qq=0;int ss=0;int tt=0; int vv=0;int uu=0;int yy=0;int ww=0;int zz=0;

     int taglio10=0;int taglio11=0;int taglio12=0;int taglio13=0;int taglio14=0;int taglio15=0;
     int taglio20=0;int taglio21=0;int taglio22=0;int taglio23=0;int taglio24=0;int taglio25=0;
     int A; int B; int C; int D; int E; int taglio200=0;


      if(Mes <5.2|| Mes>5.29) continue;
      //if(fabs(De)>0.03) continue;
      if(De<-0.1||De>0.2) continue;
      if(Cosalfa<0.99) continue;
      if(Md0<1.8526||Md0>1.8766) continue;
      if(Mks<0.486 ||Mks>0.510) continue;
      if(Moddz>0.15) continue;
      if(abs(Hemidiff)>8) continue;
      if(Modcost>1) continue;
      if((Lp0<0)|| (Lp0>7)) continue; 
      if((Lp2<-1)||(Lp2>4)) continue;
      if(Plep>2.5)continue;
      if(Pk>2.5)continue;
      if(Chktype<1 || Chktype>4)continue;
      //  if(Chktype!=4)continue;
      
 //   //    //richiesta per fondo continuo e generico

      // //B+->D0bar k+
      if(Ndbp==2){
	if(Idd1bp==-421 && Idd2bp==321)dd=1;
	if(Idd1bp==321 && Idd2bp==-421)dd=1;
      }

      // //B-->D0 k-
      if(Ndbm==2){
	if(Idd1bm==421 && Idd2bm==-321)dd=1;
	if(Idd1bm==-321 && Idd2bm==421)dd=1;
      }

      //    // B+ -> D0bar Pi+
      if(Ndbp==2){
	if(Idd1bp==-421 && Idd2bp==211)ee=1;
	if(Idd2bp==-421 && Idd1bp==211)ee=1;
      }

      // B- -> D0 Pi-
      if(Ndbm==2){
	if(Idd1bm==421 && Idd2bm==-211)ee=1;
	if(Idd2bm==421 && Idd1bm==-211)ee=1;
      }

      //   //B+ -> D*0bar Pi+
      if(Ndbp==2){
	if(Idd1bp==-423 && Idd2bp==211)ff=1;
	if(Idd2bp==-423 && Idd1bp==211)ff=1;
      }

      //   // B- -> D*0 Pi-
      if(Ndbm==2){
      if(Idd1bm==423 && Idd2bm==-211)ff=1;

      if(Idd2bm==423 && Idd1bm==-211)ff=1;
      }
      

      //   //B+ -> D*0bar K+
      if(Ndbp==2){
	if(Idd1bp==-423 && Idd2bp==321)gg=1;
	if(Idd2bp==-423 && Idd1bp==321)gg=1;
      }

      //   // B- -> D*0 K-
      if(Ndbm==2){
      if(Idd1bm==423 && Idd2bm==-321)gg=1;

      if(Idd2bm==423 && Idd1bm==-321)gg=1;
      }

      //   //B+ -> D*0bar rho+
      if(Ndbp==2){
	if(Idd1bp==-423 && Idd2bp==213)hh=1;
	if(Idd2bp==-423 && Idd1bp==213)hh=1;
      }

      //   // B- -> D*0 rho-
      if(Ndbm==2){
      if(Idd1bm==423 && Idd2bm==-213)hh=1;

      if(Idd2bm==423 && Idd1bm==-213)hh=1;
      }
      
      //   //B+ -> D0bar rho+
      if(Ndbp==2){
	if(Idd1bp==-421 && Idd2bp==213)pp=1;
	if(Idd2bp==-421 && Idd1bp==213)pp=1;
      }

      //   // B- -> D0 rho-
      if(Ndbm==2){
      if(Idd1bm==421 && Idd2bm==-213)pp=1;
      if(Idd2bm==421 && Idd1bm==-213)pp=1;
      }


      //   //B+ -> D0bar a1+
      if(Ndbp==2){
	if(Idd1bp==-421 && Idd2bp==20213)qq=1;
	if(Idd2bp==-421 && Idd1bp==20213)qq=1;
      }

      //   // B- -> D0 a1-
      if(Ndbm==2){
      if(Idd1bm==421 && Idd2bm==-20213)qq=1;
      if(Idd2bm==421 && Idd1bm==-20213)qq=1;
      }

      //   //B+ -> D*0bar a1+
      if(Ndbp==2){
	if(Idd1bp==-423 && Idd2bp==20213)ss=1;
	if(Idd2bp==-423 && Idd1bp==20213)ss=1;
      }

      //   // B- -> D*0 a1-
      if(Ndbm==2){
      if(Idd1bm==423 && Idd2bm==-20213)ss=1;
      if(Idd2bm==423 && Idd1bm==-20213)ss=1;
      }

       //   //B+ -> D0bar b1+
      if(Ndbp==2){
	if(Idd1bp==-421 && Idd2bp==10213)tt=1;
	if(Idd2bp==-421 && Idd1bp==10213)tt=1;
      }

      //   // B- -> D0 b1-
      if(Ndbm==2){
      if(Idd1bm==421 && Idd2bm==-10213)tt=1;
      if(Idd2bm==421 && Idd1bm==-10213)tt=1;
      }


      //   //B+ -> D*0bar b1+
      if(Ndbp==2){
	if(Idd1bp==-423 && Idd2bp==10213)uu=1;
	if(Idd2bp==-423 && Idd1bp==10213)uu=1;
      }

      //   // B- -> D*0 b1-
      if(Ndbm==2){
      if(Idd1bm==423 && Idd2bm==-10213)uu=1;
      if(Idd2bm==423 && Idd1bm==-10213)uu=1;
      }

       //   //B+ -> D0bar K*+
      if(Ndbp==2){
	if(Idd1bp==-421 && Idd2bp==323)vv=1;
	if(Idd2bp==-421 && Idd1bp==323)vv=1;
      }

      //   // B- -> D0 K*-
      if(Ndbm==2){
      if(Idd1bm==421 && Idd2bm==-323)vv=1;
      if(Idd2bm==421 && Idd1bm==-323)vv=1;
      }


      //   //B+ -> D*0bar K*+
      if(Ndbp==2){
	if(Idd1bp==-423 && Idd2bp==323)zz=1;
	if(Idd2bp==-423 && Idd1bp==323)zz=1;
      }

      //   // B- -> D*0 K*-
      if(Ndbm==2){
      if(Idd1bm==423 && Idd2bm==-323)zz=1;
      if(Idd2bm==423 && Idd1bm==-323)zz=1;
      }

       //   //B+ -> D0bar +
      if(Ndbp==2){
	if(Idd1bp==-421 && Idd2bp==200211)yy=1;
	if(Idd2bp==-421 && Idd1bp==200211)yy=1;
      }

      //   // B- -> D0 -
      if(Ndbm==2){
      if(Idd1bm==421 && Idd2bm==-200211)yy=1;
      if(Idd2bm==421 && Idd1bm==-200211)yy=1;
      }


      //   //B+ -> D*0bar +
      if(Ndbp==2){
	if(Idd1bp==-423 && Idd2bp==200211)ww=1;
	if(Idd2bp==-423 && Idd1bp==200211)ww=1;
      }

      //   // B- -> D*0 -
      if(Ndbm==2){
      if(Idd1bm==423 && Idd2bm==-200211)ww=1;
      if(Idd2bm==423 && Idd1bm==-200211)ww=1;
      }

      //   // B- -> gamma D0 K-
      if(Ndbm==3){
      if(Idd1bm==22 && Idd2bm==421 && Idd3bm==-321 )dd=1;
      if(Idd1bm==22 && Idd2bm==-321 && Idd3bm==421)dd=1;
      if(Idd1bm==421 && Idd2bm==22 && Idd3bm==-321)dd=1;
      if(Idd1bm==421 && Idd2bm==-321 && Idd3bm==22)dd=1;
      if(Idd1bm==-321 && Idd2bm==421 && Idd3bm==22)dd=1;
      if(Idd1bm==-321 && Idd2bm==22 && Idd3bm==421)dd=1;
      }
      //   // B- -> gamma D0bar K-
      if(Ndbm==3){
      if(Idd1bm==22 && Idd2bm==-421 && Idd3bm==-321 )dd=1;
      if(Idd1bm==22 && Idd2bm==-321 && Idd3bm==-421)dd=1;
      if(Idd1bm==-421 && Idd2bm==22 && Idd3bm==-321)dd=1;
      if(Idd1bm==-421 && Idd2bm==-321 && Idd3bm==22)dd=1;
      if(Idd1bm==-321 && Idd2bm==-421 && Idd3bm==22)dd=1;
      if(Idd1bm==-321 && Idd2bm==22 && Idd3bm==-421)dd=1;
      }
      //   // B+ -> gamma D0bar K+
      if(Ndbm==3){
      if(Idd1bm==22 && Idd2bm==-421 && Idd3bm==321)dd=1;
      if(Idd1bm==22 && Idd2bm==321 && Idd3bm==-421)dd=1;
      if(Idd1bm==-421 && Idd2bm==22 && Idd3bm==321)dd=1;
      if(Idd1bm==-421 && Idd2bm==321 && Idd3bm==22)dd=1;
      if(Idd1bm==321 && Idd2bm==-421 && Idd3bm==22)dd=1;
      if(Idd1bm==321 && Idd2bm==22 && Idd3bm==-421)dd=1;
      }
      //   // B+ -> gamma D0 K+
      if(Ndbm==3){
      if(Idd1bm==22 && Idd2bm==421 && Idd3bm==321)dd=1;
      if(Idd1bm==22 && Idd2bm==321 && Idd3bm==421)dd=1;
      if(Idd1bm==421 && Idd2bm==22 && Idd3bm==321)dd=1;
      if(Idd1bm==421 && Idd2bm==321 && Idd3bm==22)dd=1;
      if(Idd1bm==321 && Idd2bm==421 && Idd3bm==22)dd=1;
      if(Idd1bm==321 && Idd2bm==22 && Idd3bm==421)dd=1;
      }
 //      //   // B- -> gamma D*0 K-
//       if(Ndbm==3){
//       if(Idd1bm==22 && Idd2bm==423 && Idd3bm==-321 )aa=1;
//       if(Idd1bm==22 && Idd2bm==-321 && Idd3bm==423)aa=1;
//       if(Idd1bm==423 && Idd2bm==22 && Idd3bm==-321)aa=1;
//       if(Idd1bm==423 && Idd2bm==-321 && Idd3bm==22)aa=1;
//       if(Idd1bm==-321 && Idd2bm==423 && Idd3bm==22)aa=1;
//       if(Idd1bm==-321 && Idd2bm==22 && Idd3bm==423)aa=1;
//       }

//       //   // B+ -> gamma D*0bar K+
//       if(Ndbm==3){
//       if(Idd1bm==22 && Idd2bm==-423 && Idd3bm==321)aa=1;
//       if(Idd1bm==22 && Idd2bm==321 && Idd3bm==-423)aa=1;
//       if(Idd1bm==-423 && Idd2bm==22 && Idd3bm==321)aa=1;
//       if(Idd1bm==-423 && Idd2bm==321 && Idd3bm==22)aa=1;
//       if(Idd1bm==321 && Idd2bm==-423 && Idd3bm==22)aa=1;
//       if(Idd1bm==321 && Idd2bm==22 && Idd3bm==-423)aa=1;
//       }
//       //   // B- -> gamma D0 pi-
//       if(Ndbm==3){
//       if(Idd1bm==22 && Idd2bm==421 && Idd3bm==-211)aa=1;
//       if(Idd1bm==22 && Idd2bm==-211 && Idd3bm==421)aa=1;
//       if(Idd1bm==421 && Idd2bm==22 && Idd3bm==-211)aa=1;
//       if(Idd1bm==421 && Idd2bm==-211 && Idd3bm==22)aa=1;
//       if(Idd1bm==-211 && Idd2bm==421 && Idd3bm==22)aa=1;
//       if(Idd1bm==-211 && Idd2bm==22 && Idd3bm==421)aa=1;
//       }

//       //   // B+ -> gamma D0bar pi+
//       if(Ndbm==3){
//       if(Idd1bm==22 && Idd2bm==-421 && Idd3bm==211)aa=1;
//       if(Idd1bm==22 && Idd2bm==211 && Idd3bm==-421)aa=1;
//       if(Idd1bm==-421 && Idd2bm==22 && Idd3bm==211)aa=1;
//       if(Idd1bm==-421 && Idd2bm==211 && Idd3bm==22)aa=1;
//       if(Idd1bm==211 && Idd2bm==-421 && Idd3bm==22)aa=1;
//       if(Idd1bm==211 && Idd2bm==22 && Idd3bm==-421)aa=1;
//       }
//      //   // B- -> gamma D*0 pi-
//       if(Ndbm==3){
//       if(Idd1bm==22 && Idd2bm==423 && Idd3bm==-211)aa=1;
//       if(Idd1bm==22 && Idd2bm==-211 && Idd3bm==423)aa=1;
//       if(Idd1bm==423 && Idd2bm==22 && Idd3bm==-211)aa=1;
//       if(Idd1bm==423 && Idd2bm==-211 && Idd3bm==22)aa=1;
//       if(Idd1bm==-211 && Idd2bm==423 && Idd3bm==22)aa=1;
//       if(Idd1bm==-211 && Idd2bm==22 && Idd3bm==423)aa=1;
//       }

//       //   // B+ -> gamma D*0bar pi+
//       if(Ndbm==3){
//       if(Idd1bm==22 && Idd2bm==-423 && Idd3bm==211)aa=1;
//       if(Idd1bm==22 && Idd2bm==211 && Idd3bm==-423)aa=1;
//       if(Idd1bm==-423 && Idd2bm==22 && Idd3bm==211)aa=1;
//       if(Idd1bm==-423 && Idd2bm==211 && Idd3bm==22)aa=1;
//       if(Idd1bm==211 && Idd2bm==-423 && Idd3bm==22)aa=1;
//       if(Idd1bm==211 && Idd2bm==22 && Idd3bm==-423)aa=1;
//       }

    // //   //D0->KsPiPi
      if(Ndd0==3){
	if(Idd1d0==310 && Idd2d0==-211 && Idd3d0==211)dd0=1;
	if(Idd1d0==310 && Idd2d0==211 && Idd3d0==-211)dd0=1;
	if(Idd1d0==211 && Idd2d0==310 && Idd3d0==-211)dd0=1;
	if(Idd1d0==-211 && Idd2d0==211 && Idd3d0==310)dd0=1;
	if(Idd1d0==211 && Idd2d0==-211 && Idd3d0==310)dd0=1;
	if(Idd1d0==-211 && Idd2d0==310 && Idd3d0==211)dd0=1;

	if(Idd1d0==211 && Idd2d0==-211 && abs(Idd3d0)==311  && abs(Idd1k0)==310)dd0=1;
	if(Idd1d0==211 && Idd3d0==-211 && abs(Idd2d0)==311  && abs(Idd1k0)==310)dd0=1;
	if(Idd2d0==211 && Idd1d0==-211 && abs(Idd3d0)==311  && abs(Idd1k0)==310)dd0=1;
	if(Idd2d0==211 && Idd3d0==-211 && abs(Idd1d0)==311  && abs(Idd1k0)==310)dd0=1;
	if(Idd3d0==211 && Idd1d0==-211 && abs(Idd2d0)==311  && abs(Idd1k0)==310)dd0=1;
	if(Idd3d0==211 && Idd2d0==-211 && abs(Idd1d0)==311  && abs(Idd1k0)==310)dd0=1; 

      }
      if(Ndd0==4){
	if(Idd1d0==310 && Idd2d0==-211 && Idd3d0==211 && Idd3d0==22)dd0=1;
	if(Idd1d0==310 && Idd2d0==211 && Idd3d0==-211 && Idd3d0==22)dd0=1;
	if(Idd1d0==211 && Idd2d0==310 && Idd3d0==-211 && Idd3d0==22)dd0=1;
	if(Idd1d0==-211 && Idd2d0==211 && Idd3d0==310 && Idd3d0==22)dd0=1;
	if(Idd1d0==211 && Idd2d0==-211 && Idd3d0==310 && Idd3d0==22)dd0=1;
	if(Idd1d0==-211 && Idd2d0==310 && Idd3d0==211 && Idd3d0==22)dd0=1;

	if(Idd1d0==310 && Idd2d0==-211 && Idd3d0==22 && Idd3d0==211)dd0=1;
	if(Idd1d0==310 && Idd2d0==211 && Idd3d0==22 && Idd3d0==-211)dd0=1;
	if(Idd1d0==211 && Idd2d0==-211 && Idd3d0==22 && Idd3d0==310)dd0=1;
	if(Idd1d0==-211 && Idd2d0==-211 && Idd3d0==22 && Idd3d0==310)dd0=1;
	if(Idd1d0==211 && Idd2d0==310 && Idd3d0==22 && Idd3d0==-211)dd0=1;
	if(Idd1d0==-211 && Idd2d0==310 && Idd3d0==22 && Idd3d0==211)dd0=1;


	if(Idd1d0==310 && Idd2d0==22 && Idd3d0==-211 && Idd3d0==211)dd0=1;
	if(Idd1d0==310 && Idd2d0==22 && Idd3d0==211 && Idd3d0==-211)dd0=1;
	if(Idd1d0==211 && Idd2d0==22 && Idd3d0==-211 && Idd3d0==310)dd0=1;
	if(Idd1d0==-211 && Idd2d0==22 && Idd3d0==211 && Idd3d0==310)dd0=1;
	if(Idd1d0==211 && Idd2d0==22 && Idd3d0==310 && Idd3d0==-211)dd0=1;
	if(Idd1d0==-211 && Idd2d0==22 && Idd3d0==310 && Idd3d0==211)dd0=1;

	if(Idd1d0==22 && Idd2d0==310 && Idd3d0==-211 && Idd3d0==211)dd0=1;
	if(Idd1d0==22 && Idd2d0==310 && Idd3d0==211 && Idd3d0==-211)dd0=1;
	if(Idd1d0==22 && Idd2d0==211 && Idd3d0==-211 && Idd3d0==310)dd0=1;
	if(Idd1d0==22 && Idd2d0==-211 && Idd3d0==211 && Idd3d0==310)dd0=1;
	if(Idd1d0==22 && Idd2d0==211 && Idd3d0==310 && Idd3d0==-211)dd0=1;
	if(Idd1d0==22 && Idd2d0==-211 && Idd3d0==310 && Idd3d0==211)dd0=1; 

      }

      // Tagli sulla massa del D0

 
      if(Md0>1.81 && Md0<1.92)taglio10=1;
      if(Md0>1.834 &&  Md0<1.894)taglio11=1;
      if(Md0>1.839 && Md0<1.889)taglio12=1;
      if(Md0>1.844 && Md0<1.884)taglio13=1;
      if(Md0>1.849 && Md0<1.879)taglio14=1;
      if(Md0>1.8526 && Md0<1.8766)taglio15=1;


      // Tagli sulla massa del Ks

      if(Mks>0.485 && Mks<0.515)taglio200=1;
      if(Mks>0.48 && Mks<0.516)taglio20=1;
      if(Mks>0.483 && Mks<0.513)taglio21=1;
      if(Mks>0.486 && Mks<0.51)taglio22=1;
      if(Mks>0.48867 && Mks<0.5066)taglio23=1;
      if(Mks>0.489 && Mks<0.507)taglio24=1;
      if(Mks>0.492 && Mks<0.504)taglio25=1;
  
      // Selezione sui kaoni
      
      if(Chktype>=1 && Chktype<=4)A=1;
      if(Chktype>=2 && Chktype<=4)B=1;
      if(Chktype>=3 && Chktype<=4)C=1;
      if(Chktype==4)D=1;
      if(Chktype>=1 && Chktype<=5)E=1;

      //erase=0; non applica nessun limite di decadimento.

      //erase=1 toglie il segnale
      if(erase==1){
	if(dd==1 && dd0==1)continue;
      }
            
      //erase=2 attiva D0pi
      if(erase==2){
	if(ee!=1)continue;
      }
     
      //erase=3 attiva D*pi
      if(erase==3){
	if(ff!=1)continue;
      }
      //erase=4 attiva D0pi e D*pi e toglie sig 
      if(erase==4){
	if(ee!=1 || ff!=1 || (dd==1 && dd0==1))continue;
      }
      //erase=5 toglie D0pi e D*pi + il segnale D0K
      if(erase==5){
	if(ee==1 || ff==1|| (dd==1&& dd0==1))continue;
      }
           
      //erase=6 toglie D0pi e D*pi 
      if(erase==6){
	if(ee==1 || ff==1)continue;
      }

      //erase=7 toglie D(*)Pi, D(*)rho, D(*)a1, D*0K, D(*)K*
      if(erase==7){
	if(ee==1 || ff==1 || gg==1 || hh==1 || pp==1 || qq==1 || ss==1 || dd==1)continue;
      }

      //erase=8 toglie D(*)Pi, D(*)rho, D(*)a1, D(*)K*, D*0K e il segnale D0K(KsPiPi)
      if(erase==8){
	if(dd0==1){
	  if(ee==1 || ff==1 || gg==1 || hh==1 || pp==1 || qq==1 || ss==1 || vv==1 || zz==1 || dd==1)continue;
	     }
	}
      //dd==1 && dd0==1

      //////////Conteggi

      //erase=11: attiva  D*rho 
      if(erase==11){
	if(hh!=1)continue;
      }

      //erase=12: attiva D0rho 
      if(erase==12){
	if(pp!=1)continue;
      }

      //erase=13: attiva D*0a1 
      if(erase==13){
	if(ss!=1)continue;
      }


      //erase=14: attiva D0a1
      if(erase==14){
	if(qq!=1)continue;
      }
      //erase=15: attiva D*0K 
      if(erase==15){
	if(gg!=1)continue;
      }

      //erase=16: attiva D0b1 
      if(erase==16){
	if(tt!=1)continue;
      }

      //erase=17: attiva D*0b1 
      if(erase==17){
	if(uu!=1)continue;
      }

      //erase=18: attiva D0K* 
      if(erase==18){
	if(vv!=1)continue;
      }

      //erase=19: attiva D*0K* 
      if(erase==19){
	if(zz!=1)continue;
      }

      //erase=20: attiva D0K1 
      if(erase==20){
	if(yy!=1)continue;
      }
      //erase=21: attiva D*0K1 
      if(erase==21){
	if(ww!=1)continue;
      }
      //erase=22: attiva D0K e tolgo il Kspipi, quindi tutto il D0K tranne il sig 
      if(erase==22){
	if(dd!=1 || (dd==1 && dd0==1))continue;
      }

      //erase=23: attiva tutti i fondi, tranne D0Pi,D0K:D0rho,D*rho,D0a1,D*a1,D*K,D0K*,D*K*
      if(erase==23){
	if(hh!=1 && pp!=1 && ss!=1 && qq!=1 && gg!=1 && vv!=1 && zz!=1 && (dd!=1 || dd0!=1))continue;
      }
      //erase=100  il segnale +
      if(erase==100){
	if(ddp!=1 || dd0!=1)continue;
      }
      //erase=200  il segnale -
      if(erase==200){
	if(ddm!=1 || dd0!=1)continue;
      }
      //erase=300  il segnale 
      if(erase==300){
	if(dd!=1 || dd0!=1)continue;
      }

      ///////////////////////////////////////////////////////////////////////////////
   
   //    if(A==1){
		      //if(taglio11==1 && taglio200==1){
		      //    if((hh==1 || 1==pp || ss==1 || qq==1 || gg==1 || vv==1 || zz==1) && dd0==1)){
	file1<<Mes<<" "<<De<<" "<<Fishera<<" "<<Ptrkx<<" "<<Ptrky<<" "<<Ptrkz<<endl;
	//  }
// 		      file1<<Idd1bm<<" "<<Idd2bm<<" "<<Idd3bm<<" "<<Idd4bm<<" "<<Idd1d0<<" "<<Idd2d0<<" "<<Idd3d0<<" "<<endl<<Idd1bp<<" "<<Idd2bp<<" "<<Idd3bp<<" "<<Idd4bp<<endl<<"......................"<<endl;
	//   }
//       if(C==1){
//        if(taglio12==1 && taglio200==1){
// 	 file2<<Mes<<" "<<De<<" "<<Fishera<<" "<<Ptrkx<<" "<<Ptrky<<" "<<Ptrkz<<endl;
//        }
// //       if(D==1){
//        if(taglio13==1 && taglio200==1){
// 	 file3<<Mes<<" "<<De<<" "<<Fishera<<" "<<Ptrkx<<" "<<Ptrky<<" "<<Ptrkz<<endl;
//        }
// //       if(D==1){
//        if(taglio14==1 && taglio200==1){
// 	 file4<<Mes<<" "<<De<<" "<<Fishera<<" "<<Ptrkx<<" "<<Ptrky<<" "<<Ptrkz<<endl;
//        }
	  
//        //if(cutMKS==5){
// 		     if(taglio11==1 && taglio200==1){
// 		       file5<<Mes<<" "<<De<<" "<<Fishera<<" "<<Ptrkx<<" "<<Ptrky<<" "<<Ptrkz<<endl;
// 		     }
// 		     if(taglio15==1 && taglio25==1){
// 		       file6<<Mes<<" "<<De<<" "<<Fishera<<" "<<Ptrkx<<" "<<Ptrky<<" "<<Ptrkz<<endl;
// 		     }
		     
   }
   file1.close();
//    file2.close();
//    file3.close();
//    file4.close();
//    file5.close();
//    file6.close();

}

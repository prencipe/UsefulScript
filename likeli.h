//////////////////////////////////////////////////////////
//   This class has been automatically generated 
//     (Tue Apr 27 18:53:05 2004 by ROOT version3.05/07)
//   from TTree h666/DOK
//   found on file: tagliultimi_udsc.root
//////////////////////////////////////////////////////////


#ifndef likeli_h
#define likeli_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class likeli {
   public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
//Declaration of leaves types
   Float_t         Mes;
   Float_t         De;
   Float_t         Thch;
   Float_t         Sthch;
   Float_t         Dircdp;
   Float_t         Fisher;
   Float_t         Ptrk;
   Float_t         Ptrkx;
   Float_t         Ptrky;
   Float_t         Ptrkz;
   Float_t         Cosalfa;
   Float_t         Mkspip;
   Float_t         Mpippim;
   Float_t         Mkspim;
   Float_t         Idmcd0;
   Float_t         Idmck;
   Float_t         Idmcks;
   Float_t         Idmcpip;
   Float_t         Idmcpim;
   Float_t         Ndbp;
   Float_t         Idd1bp;
   Float_t         Idd2bp;
   Float_t         Idd3bp;
   Float_t         Idd4bp;
   Float_t         Ndbm;
   Float_t         Idd1bm;
   Float_t         Idd2bm;
   Float_t         Idd3bm;
   Float_t         Idd4bm;
   Float_t         Btype;
   Float_t         D0mcass;
   Float_t         Ndd0;
   Float_t         Idd1d0;
   Float_t         Idd2d0;
   Float_t         Idd3d0;
   Float_t         Idd4d0;
   Float_t         Idd1k0;
   Float_t         Md0;
   Float_t         Mks;
   Float_t         Moddz;
   Float_t         Hemidiff;
   Float_t         Modcost;
   Float_t         Lp0;
   Float_t         Lp2;
   Float_t         Plep;
   Float_t         Pk;
   Float_t         Mtag;
   Float_t         Elitag;
   Float_t         Chk;
   Float_t         Evtype;
   Float_t         Chi2ks;
   Float_t         Chktype;
   Float_t         Mks2;
   Float_t         Fisherk;
   Float_t         Fishera;
   Float_t         Fisherl;
   Float_t         Fishero;
   Float_t         nuovofisher;

//List of branches
   TBranch        *b_Mes;   //!
   TBranch        *b_De;   //!
   TBranch        *b_Thch;   //!
   TBranch        *b_Sthch;   //!
   TBranch        *b_Dircdp;   //!
   TBranch        *b_Fisher;   //!
   TBranch        *b_Ptrk;   //!
   TBranch        *b_Ptrkx;   //!
   TBranch        *b_Ptrky;   //!
   TBranch        *b_Ptrkz;   //!
   TBranch        *b_Cosalfa;   //!
   TBranch        *b_Mkspip;   //!
   TBranch        *b_Mpippim;   //!
   TBranch        *b_Mkspim;   //!
   TBranch        *b_Idmcd0;   //!
   TBranch        *b_Idmck;   //!
   TBranch        *b_Idmcks;   //!
   TBranch        *b_Idmcpip;   //!
   TBranch        *b_Idmcpim;   //!
   TBranch        *b_Ndbp;   //!
   TBranch        *b_Idd1bp;   //!
   TBranch        *b_Idd2bp;   //!
   TBranch        *b_Idd3bp;   //!
   TBranch        *b_Idd4bp;   //!
   TBranch        *b_Ndbm;   //!
   TBranch        *b_Idd1bm;   //!
   TBranch        *b_Idd2bm;   //!
   TBranch        *b_Idd3bm;   //!
   TBranch        *b_Idd4bm;   //!
   TBranch        *b_Btype;   //!
   TBranch        *b_D0mcass;   //!
   TBranch        *b_Ndd0;   //!
   TBranch        *b_Idd1d0;   //!
   TBranch        *b_Idd2d0;   //!
   TBranch        *b_Idd3d0;   //!
   TBranch        *b_Idd4d0;   //!
   TBranch        *b_Idd1k0;   //!
   TBranch        *b_Md0;   //!
   TBranch        *b_Mks;   //!
   TBranch        *b_Moddz;   //!
   TBranch        *b_Hemidiff;   //!
   TBranch        *b_Modcost;   //!
   TBranch        *b_Lp0;   //!
   TBranch        *b_Lp2;   //!
   TBranch        *b_Plep;   //!
   TBranch        *b_Pk;   //!
   TBranch        *b_Mtag;   //!
   TBranch        *b_Elitag;   //!
   TBranch        *b_Chk;   //!
   TBranch        *b_Evtype;   //!
   TBranch        *b_Chi2ks;   //!
   TBranch        *b_Chktype;   //!
   TBranch        *b_Mks2;   //!
   TBranch        *b_Fisherk;   //!
   TBranch        *b_Fishera;   //!
   TBranch        *b_Fisherl;   //!
   TBranch        *b_Fishero;   //!
   TBranch        *b_nuovofisher;   //!

   likeli(TTree *tree=0);
   ~likeli();
   Int_t  Cut(Int_t entry);
   Int_t  GetEntry(Int_t entry);
   Int_t  LoadTree(Int_t entry);
   void   Init(TTree *tree);
   void   Loop();
   Bool_t Notify();
   void   Show(Int_t entry = -1);
};

#endif

#ifdef likeli_cxx
likeli::likeli(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("sigMHS.root");
      if (!f) {
         f = new TFile("sigMHS.root");
         f->cd("sigMHS.root:/BRECO");
      }
      tree = (TTree*)gDirectory->Get("h666");

   }
   Init(tree);
}

likeli::~likeli()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t likeli::GetEntry(Int_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Int_t likeli::LoadTree(Int_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Int_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->IsA() != TChain::Class()) return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void likeli::Init(TTree *tree)
{
//   Set branch addresses
   if (tree == 0) return;
   fChain    = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Mes",&Mes);
   fChain->SetBranchAddress("De",&De);
   fChain->SetBranchAddress("Thch",&Thch);
   fChain->SetBranchAddress("Sthch",&Sthch);
   fChain->SetBranchAddress("Dircdp",&Dircdp);
   fChain->SetBranchAddress("Fisher",&Fisher);
   fChain->SetBranchAddress("Ptrk",&Ptrk);
   fChain->SetBranchAddress("Ptrkx",&Ptrkx);
   fChain->SetBranchAddress("Ptrky",&Ptrky);
   fChain->SetBranchAddress("Ptrkz",&Ptrkz);
   fChain->SetBranchAddress("Cosalfa",&Cosalfa);
   fChain->SetBranchAddress("Mkspip",&Mkspip);
   fChain->SetBranchAddress("Mpippim",&Mpippim);
   fChain->SetBranchAddress("Mkspim",&Mkspim);
   fChain->SetBranchAddress("Idmcd0",&Idmcd0);
   fChain->SetBranchAddress("Idmck",&Idmck);
   fChain->SetBranchAddress("Idmcks",&Idmcks);
   fChain->SetBranchAddress("Idmcpip",&Idmcpip);
   fChain->SetBranchAddress("Idmcpim",&Idmcpim);
   fChain->SetBranchAddress("Ndbp",&Ndbp);
   fChain->SetBranchAddress("Idd1bp",&Idd1bp);
   fChain->SetBranchAddress("Idd2bp",&Idd2bp);
   fChain->SetBranchAddress("Idd3bp",&Idd3bp);
   fChain->SetBranchAddress("Idd4bp",&Idd4bp);
   fChain->SetBranchAddress("Ndbm",&Ndbm);
   fChain->SetBranchAddress("Idd1bm",&Idd1bm);
   fChain->SetBranchAddress("Idd2bm",&Idd2bm);
   fChain->SetBranchAddress("Idd3bm",&Idd3bm);
   fChain->SetBranchAddress("Idd4bm",&Idd4bm);
   fChain->SetBranchAddress("Btype",&Btype);
   fChain->SetBranchAddress("D0mcass",&D0mcass);
   fChain->SetBranchAddress("Ndd0",&Ndd0);
   fChain->SetBranchAddress("Idd1d0",&Idd1d0);
   fChain->SetBranchAddress("Idd2d0",&Idd2d0);
   fChain->SetBranchAddress("Idd3d0",&Idd3d0);
   fChain->SetBranchAddress("Idd4d0",&Idd4d0);
   fChain->SetBranchAddress("Idd1k0",&Idd1k0);
   fChain->SetBranchAddress("Md0",&Md0);
   fChain->SetBranchAddress("Mks",&Mks);
   fChain->SetBranchAddress("Moddz",&Moddz);
   fChain->SetBranchAddress("Hemidiff",&Hemidiff);
   fChain->SetBranchAddress("Modcost",&Modcost);
   fChain->SetBranchAddress("Lp0",&Lp0);
   fChain->SetBranchAddress("Lp2",&Lp2);
   fChain->SetBranchAddress("Plep",&Plep);
   fChain->SetBranchAddress("Pk",&Pk);
   fChain->SetBranchAddress("Mtag",&Mtag);
   fChain->SetBranchAddress("Elitag",&Elitag);
   fChain->SetBranchAddress("Chk",&Chk);
   fChain->SetBranchAddress("Evtype",&Evtype);
   fChain->SetBranchAddress("Chi2ks",&Chi2ks);
   fChain->SetBranchAddress("Chktype",&Chktype);
   fChain->SetBranchAddress("Mks2",&Mks2);
   fChain->SetBranchAddress("Fisherk",&Fisherk);
   fChain->SetBranchAddress("Fishera",&Fishera);
   fChain->SetBranchAddress("Fisherl",&Fisherl);
   fChain->SetBranchAddress("Fishero",&Fishero);

   Notify();
}

Bool_t likeli::Notify()
{
   // Called when loading a new file.
   // Get branch pointers.
   b_Mes = fChain->GetBranch("Mes");
   b_De = fChain->GetBranch("De");
   b_Thch = fChain->GetBranch("Thch");
   b_Sthch = fChain->GetBranch("Sthch");
   b_Dircdp = fChain->GetBranch("Dircdp");
   b_Fisher = fChain->GetBranch("Fisher");
   b_Ptrk = fChain->GetBranch("Ptrk");
   b_Ptrkx = fChain->GetBranch("Ptrkx");
   b_Ptrky = fChain->GetBranch("Ptrky");
   b_Ptrkz = fChain->GetBranch("Ptrkz");
   b_Cosalfa = fChain->GetBranch("Cosalfa");
   b_Mkspip = fChain->GetBranch("Mkspip");
   b_Mpippim = fChain->GetBranch("Mpippim");
   b_Mkspim = fChain->GetBranch("Mkspim");
   b_Idmcd0 = fChain->GetBranch("Idmcd0");
   b_Idmck = fChain->GetBranch("Idmck");
   b_Idmcks = fChain->GetBranch("Idmcks");
   b_Idmcpip = fChain->GetBranch("Idmcpip");
   b_Idmcpim = fChain->GetBranch("Idmcpim");
   b_Ndbp = fChain->GetBranch("Ndbp");
   b_Idd1bp = fChain->GetBranch("Idd1bp");
   b_Idd2bp = fChain->GetBranch("Idd2bp");
   b_Idd3bp = fChain->GetBranch("Idd3bp");
   b_Idd4bp = fChain->GetBranch("Idd4bp");
   b_Ndbm = fChain->GetBranch("Ndbm");
   b_Idd1bm = fChain->GetBranch("Idd1bm");
   b_Idd2bm = fChain->GetBranch("Idd2bm");
   b_Idd3bm = fChain->GetBranch("Idd3bm");
   b_Idd4bm = fChain->GetBranch("Idd4bm");
   b_Btype = fChain->GetBranch("Btype");
   b_D0mcass = fChain->GetBranch("D0mcass");
   b_Ndd0 = fChain->GetBranch("Ndd0");
   b_Idd1d0 = fChain->GetBranch("Idd1d0");
   b_Idd2d0 = fChain->GetBranch("Idd2d0");
   b_Idd3d0 = fChain->GetBranch("Idd3d0");
   b_Idd4d0 = fChain->GetBranch("Idd4d0");
   b_Idd1k0 = fChain->GetBranch("Idd1k0");
   b_Md0 = fChain->GetBranch("Md0");
   b_Mks = fChain->GetBranch("Mks");
   b_Moddz = fChain->GetBranch("Moddz");
   b_Hemidiff = fChain->GetBranch("Hemidiff");
   b_Modcost = fChain->GetBranch("Modcost");
   b_Lp0 = fChain->GetBranch("Lp0");
   b_Lp2 = fChain->GetBranch("Lp2");
   b_Plep = fChain->GetBranch("Plep");
   b_Pk = fChain->GetBranch("Pk");
   b_Mtag = fChain->GetBranch("Mtag");
   b_Elitag = fChain->GetBranch("Elitag");
   b_Chk = fChain->GetBranch("Chk");
   b_Evtype = fChain->GetBranch("Evtype");
   b_Chi2ks = fChain->GetBranch("Chi2ks");
   b_Chktype = fChain->GetBranch("Chktype");
   b_Mks2 = fChain->GetBranch("Mks2");
   b_Fisherk = fChain->GetBranch("Fisherk");
   b_Fishera = fChain->GetBranch("Fishera");
   b_Fisherl = fChain->GetBranch("Fisherl");
   b_Fishero = fChain->GetBranch("Fishero");

   return kTRUE;
}

void likeli::Show(Int_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t likeli::Cut(Int_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef likeli_cxx


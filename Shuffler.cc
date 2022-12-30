/////////////////////////////////////////////////
  //                                            //
    //          shuffler v 1.3                //
  //                                            //
/////////////////////////////////////////////////

#include <stdio.h>              // Standard I/O.
#include <stdlib.h>             // Standard Lib.
#include <fstream.h>            // Stream I/O

   int       j=0,k=0,n=0;
   long      i=0;
   char      line[255];          // Buffer di lettura
   bool      messageOut=true;    // Messaggi su video... meglio di si
   bool      verboseOut=false;   // Tutto in output su video... meglio di no
   bool      FilesStillOpen=true;

////////////////////////////////////////////////////////////
         //     Stampa l'help del programma      //
////////////////////////////////////////////////////////////
void print_help()
{
     cout<< endl ;
     cout<< "Usage: shuffler nfile file1 file2 [file3...] Outputfile "<< endl;
     cout<< "or     shuffler nfile file1 file2 [file3...] Outputfile 
nBlock1 nBlock2 [...] "<< endl;
     cout<< endl ;
     cout<< " nfile ................ is number of input files " <<endl;
     cout<< " file1 file2 .......... are input file names " <<endl;
     cout<< " OutputFile  .......... is output file name " <<endl;
     cout<< " nBlock1 nBlock2 ...... are the number of block of input 
file1,2 ..." << endl;
     cout<< endl ;
}

/////////////////////////////////////////////////////////
// Qui verifica se il numero dei parametri e' valido   //
//             ... senno' esce                         //
/////////////////////////////////////////////////////////
int verifica_parametri(int argc , char *argv[])
{
   if (argc==1) {print_help(); return 1;}
   int nFile=atoi(argv[1]);

   if (! ((argc-3)==nFile || (argc-3)==(2 * nFile)) ){
       print_help();
       cout<< "Wrong number of files/parameters  " << nFile << "/"<< argc 
<< endl << endl;
       return 2;
   }
  // Syntax error
   if (argc<4) { print_help(); return 1;  }
   // Ok
   return 0;
}


////////////////////////////////////////////////////////////
//                         MAIN                           //
////////////////////////////////////////////////////////////

int main(int argc , char *argv[])
{

   // Verifica i parametri passati (da finire, ma ok)

   if (!verifica_parametri(argc ,argv)==0) {return 1;}

   int       nFile           = atoi(argv[1]);
   int*      lenBlocco       = new int[nFile+1];
   int*      nBlocchi        = new int[nFile+1];
   char*     nomeFileInput[255];  // MAX 255 file di input
   char*     nomeFileOutput  = "Output2.txt";
   ifstream* ifile           = new ifstream[nFile+1];
   ofstream  ofile1;
   int       lenHeader=6;        // Len del header completo

   // Assegna i parametri alle variabili

   for (n=1;n<=nFile;n++) {nomeFileInput[n]=argv[n+1];nBlocchi[n]=1;}
   nomeFileOutput =argv[nFile+2];

   if (argc > nFile+3) {
       for (n=1;n<=nFile;n++) {nBlocchi[n]=atoi(argv[nFile+2+n]);}
   }

   if (messageOut==true) { cout << endl;
       cout << "Number of files ..... " << nFile << endl ;
       for (n=1;n<=nFile;n++) {
       cout << "file input # " <<n <<" ...... " << nomeFileInput[n] << endl ;
       cout << "n Blocchi  # " <<n <<" ...... " << nBlocchi[n] << endl ;
       }
       cout << "file Output ......... " << nomeFileOutput << endl ;
   }


   for (n=1;n<=nFile;n++) {ifile[n].open(nomeFileInput[n]);}
   ofile1.open(nomeFileOutput);  // 1^ file di output

   // ----------------------------------------------------------- //
   //  Legge l'header e lo copia dal file input1 al file output1  //
   // ----------------------------------------------------------- //

   for (n=1;n<=nFile;n++) {
        ifile[n].getline(line,255);
        lenBlocco[n]= atoi(line);
   }

   lenBlocco[0]=lenBlocco[1];     lenHeader= lenBlocco[0]+1;
   ofile1 <<lenBlocco[0];
   for (i=1; i<=lenBlocco[0]; i++) {  // copia i nomi delle variabili
        if (verboseOut) {cout<< i << "  " << line << endl ;};
        ifile[1].getline(line,255);
        ofile1 << endl << line ;
        for (n=2;n<=nFile;n++){ifile[n].getline(line,255);}
    }


   // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
       //  Copia dai file di input al file output1  //
   // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

    FilesStillOpen=true;   // Mi dice se ci sono ancora files aperti,
    while (FilesStillOpen) {

        for (n=1; n <= nFile; n++)                 // Per ogni file
           for (k=0; k < nBlocchi[n]; k++)         // Per ogni blocco
               for (j=0; j <lenBlocco[n]; j++)     // Per ogni variabile
                   if (ifile[n].eof()==0) {        // Se non e' finito il file
                       ifile[n].getline(line,255); // Legge dall'n-esimo file
                       ofile1 <<endl <<line ;      // Copia Dati sul file 
di Output
                       if (verboseOut) {cout<< i << "." << j << "  " << 
line << endl ;}
                   }
        if (verboseOut) i++;

        //  Controlla se ci sono ancora files aperti su cui lavorare
        FilesStillOpen=false;
        for (n=1; n <= nFile; n++)
             if (ifile[n].eof()==0) {FilesStillOpen=true;}

    }

    if (messageOut==true){   cout << "*** DONE ***" << endl << endl ;}
    return 0;
}

#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include <TRandom.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <Riostream.h>
#include <math.h>

void render19(char *name="NOTHING", char *rootFile="render19.root")
{

 printf("The argument is %s\n", name);
 printf("The second argument is %s\n", rootFile);

TFile *f = new TFile(rootFile,"UPDATE");

TTree *render19 = new TTree("render19","Tree data");

render19->Write("render19",TObject::kOverwrite);


Int_t d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16;

Int_t dect1,dect2,dect3,dect4,dect5,dect6,dect7,dect8,dect9,dect10,dect11,dect12,dect13,dect14,dect15,dect16;

  double rs1,rs2,rs3,rs4,rs5,rs6,rs7,rs8,rs9,rs10,rs11,rs12,rs13, rs14,rs15,rs16;

	Double_t Adect1,Adect2,Adect3,Adect4,Adect5,Adect6,Adect7,Adect8,Adect9,Adect10,Adect11,Adect12,Adect13,Adect14,Adect15,Adect16,max;

	Double_t xarribatodos,yarribatodos, abajotodos;

  Double_t xarribatodosa,yarribatodosa, abajotodosa;
  int pointList1,pointList2;
	Double_t  xt, yt,xPrada,yPrada;

	Double_t posdetx1,posdetx2,posdetx3,posdetx4,posdetx5,posdetx6,posdetx7,posdetx8,posdetx9,posdetx10,posdetx11,posdetx12,posdetx13,posdetx14,posdetx15,posdetx16;
	Double_t posdety1,posdety2,posdety3,posdety4,posdety5,posdety6,posdety7,posdety8,posdety9,posdety10,posdety11,posdety12,posdety13,posdety14,posdety15,posdety16;


	Int_t BIASmax, BIASmin;

	BIASmax=5000;

	BIASmin=50;

  long long size=16;




//Posiciones de los Detectores
  Double_t Adetvec[16],normVec[16],AdetvecPrada[16];

  Double_t posdetxvec[16] = {79.35, 49.35, 34.35, 2.5, 0., 2.5, 34.35, 49.35, 79.35, 109.35, 124.35, 156.35, 158.7, 156.2, 124.35, 109.35};

  Double_t posdetyvec[16] = {0., 0., 0., 2.5, 35.0, 67.5, 70., 70., 70., 70., 70., 67.5, 35., 2.5, 0., 0.};

  float inda[16];


render19->Branch("ADetector1render19",&Adect1,"Adect1/D");
render19->Branch("ADetector2render19",&Adect2,"Adect2/D");
render19->Branch("ADetector3render19",&Adect3,"Adect3/D");
render19->Branch("ADetector4render19",&Adect4,"Adect4/D");
render19->Branch("ADetector5render19",&Adect5,"Adect5/D");
render19->Branch("ADetector6render19",&Adect6,"Adect6/D");
render19->Branch("ADetector7render19",&Adect7,"Adect7/D");
render19->Branch("ADetector8render19",&Adect8,"Adect8/D");
render19->Branch("ADetector9render19",&Adect9,"Adect9/D");
render19->Branch("ADetector10render19",&Adect10,"Adect10/D");
render19->Branch("ADetector11render19",&Adect11,"Adect11/D");
render19->Branch("ADetector12render19",&Adect12,"Adect12/D");
render19->Branch("ADetector13render19",&Adect13,"Adect13/D");
render19->Branch("ADetector14render19",&Adect14,"Adect14/D");
render19->Branch("ADetector15render19",&Adect15,"Adect15/D");
render19->Branch("ADetector16render19",&Adect16,"Adect16/D");


render19->Branch("xtrender19",&xt,"xt/D");
render19->Branch("ytrender19",&yt,"yt/D");

render19->Branch("xPradarender19",&xPrada,"xPrada/D");
render19->Branch("yPradarender19",&yPrada,"yPrada/D");

// Detectores Externo

	Int_t DetectorExt1, DetectorExt2;
	Int_t d1ext, d2ext;
	Int_t ADetectorExt1, ADetectorExt2;
	Int_t BIASminext, BIASmaxext;
	Double_t ADectExt1, ADectExt2;


/*render19->Branch("DetectorExt1render19",&DetectorExt1,"DetectorExt1/I");
render19->Branch("DetectorExt2render19",&DetectorExt2,"DetectorExt2/I");
render19->Branch("ADetectorExt1render19",&ADetectorExt1,"ADetectorExt1/I");
render19->Branch("ADetectorExt2render19",&ADetectorExt2,"ADetectorExt2/I");*/


	BIASminext=0;
	BIASmaxext=4000;

//PRADA Declarations

int m,n,counter;
double minDiff,diff,sum,treshold;
minDiff = 100;
treshold = 0.15;


	Int_t cuentasIFS;

render19->Branch("cuentasIFS",&cuentasIFS,"cuentasIFS/I");

//read the points list
printf("read plist");

int k = 0;
float pointListM[10833][2];
float pointListEvent[2];

FILE *pointList;
pointList = fopen("pointList.txt","r");
while(!feof(pointList)&&k<10833)  {

  fscanf(pointList,"%i %i",&pointList1, &pointList2);

  pointListEvent[0]=pointList1;
  pointListEvent[1]=pointList2;

  for (int h=0; h<2; h++){
    pointListM[k][h]=pointListEvent[h];
    }
    k++;
}

//Read the data base
printf("read database");


int j = 0;
double relSigsM[10833][16];
double relSigEvent[16];

FILE *relSigs;
relSigs = fopen("relSigs.txt","r");
while(!feof(relSigs)&&j<10833)  {

  fscanf(relSigs,"%lf %lf %lf %lf %lf %lf %lf %lf",&rs1,&rs2,&rs3,&rs4,&rs5,&rs6,&rs7,&rs8);
  fscanf(relSigs,"%lf %lf %lf %lf %lf %lf %lf %lf",&rs9,&rs10,&rs11,&rs12,&rs13,&rs14,&rs15,&rs16);

  relSigEvent[0]=rs1;
  relSigEvent[1]=rs2;
  relSigEvent[2]=rs3;
  relSigEvent[3]=rs4;
  relSigEvent[4]=rs5;
  relSigEvent[5]=rs6;
  relSigEvent[6]=rs7;
  relSigEvent[7]=rs8;
  relSigEvent[8]=rs9;
  relSigEvent[9]=rs10;
  relSigEvent[10]=rs11;
  relSigEvent[11]=rs12;
  relSigEvent[12]=rs13;
  relSigEvent[13]=rs14;
  relSigEvent[14]=rs15;
  relSigEvent[15]=rs16;

  for (int i=0; i<=15; i++){
    relSigsM[j][i]=relSigEvent[i];
    }

    j++;
}

FILE *out;
out=fopen(name,"r");
printf("opening %s\n",name);
int count = 0;
int count1 = 0;
int count2 = 0;
while(!feof(out))  {

	//fscanf(out,"%d %d",&d1ext, &d2ext);
	fscanf(out,"%d %d %d %d %d %d %d %d",&d1,&d2,&d3,&d4,&d5,&d6,&d7,&d8);
	fscanf(out,"%d %d %d %d %d %d %d %d",&d9,&d10,&d11,&d12,&d13,&d14,&d15,&d16);
	count1=0;

  AdetvecPrada[0]=d1;
  AdetvecPrada[1]=d2;
  AdetvecPrada[2]=d3;
  AdetvecPrada[3]=d4;
  AdetvecPrada[4]=d5;
  AdetvecPrada[5]=d6;
  AdetvecPrada[6]=d7;
  AdetvecPrada[7]=d8;
  AdetvecPrada[8]=d9;
  AdetvecPrada[9]=d10;
  AdetvecPrada[10]=d11;
  AdetvecPrada[11]=d12;
  AdetvecPrada[12]=d13;
  AdetvecPrada[13]=d14;
  AdetvecPrada[14]=d15;
  AdetvecPrada[15]=d16;
//External Detectors
/*
		DetectorExt1=0;
		ADetectorExt1=0;
        if (d1ext<BIASmaxext && d1ext>BIASminext) {

		DetectorExt1=d1ext;
		ADetectorExt1=(1*DetectorExt1)+0;
	}


		DetectorExt2=0;
		ADetectorExt2=0;
	if (d2ext<BIASmaxext && d2ext>BIASminext) {

		DetectorExt2=d2ext;
		ADetectorExt2=(1*DetectorExt2)+0;

	}
*/

 //Normalization of Event
max=0;
 //TMath::Sort(size,Adetvec,inda,kTRUE);
for (i = 0; i < 16; i++) {
  if(AdetvecPrada[i]>AdetvecPrada[int(max)])
    max = i ;
    //printf("%f \n", Adetvec[int(max)]);
}

//printf("max= %f \n", Adetvec[int(max)]);
 //max=inda[0];
 for (int i=0; i<16; i++){
           normVec[i]= AdetvecPrada[i]/AdetvecPrada[int(max)];
           //printf("\n%f / %f = %f  ",AdetvecPrada[i],AdetvecPrada[int(max)],normVec[i]);
       }
/*
//PRADA
minDiff=100;
m=0;
int ot=0;
    for(n=0;n<=15;n++)
        if (normVec[n]>treshold)
            ot++;
if(ot>=4 && ot<=6){
count ++;
for(m=0;m<10833;m++)
{
  sum = 0;
  for(n=0;n<=15;n++)
    {
    if(normVec[n]>treshold)
        {

        diff=normVec[n]-relSigsM[m][n];
        diff *= diff;
        sum += diff;
        //printf("sum diff  = %i \n", sum); printf(" %f - %f = %f\n", normVec[n],relSigsM[m][n],diff);
        }
      //printf("%i,%i: Under treshold  ",m,n);
    }
    //printf("\nActual sum %f  ",sum );
  if (sum<minDiff)
  {
    minDiff = sum;
    counter = m;
    //printf("\nTotal diff: %f and %i,%i with m as %i\n",minDiff,pointListM[counter][0],pointListM[counter][1],m);
  }
}*/
int m;
float riDiff,leDiff,doDiff,upDiff,onDiff;
onDiff = 2;
riDiff = 1;
leDiff = 1;
doDiff = 1;
upDiff = 1;
m = 5417;
//Condicion de no ser un minimo
while (onDiff > riDiff || onDiff > leDiff || onDiff > doDiff|| onDiff > upDiff)
{
      //Incerse positive well inizialization
      riDiff = 100;
      leDiff = 100;
      doDiff = 100;
      upDiff = 100;

      //Obtencion de la diferencia actual
      onDiff = 0;
      for(n=0;n<=15;n++)
      {
          if(normVec[n]>treshold)
          {
              diff=normVec[n]-relSigsM[m][n];
              diff *= diff;
              onDiff += diff;
          }
      }

      //Obtencion de la diferencia izquierda
      if(m%157 != 0)
      {
          leDiff = 0;
          for(n=0;n<=15;n++)
          {
              if(normVec[n]>treshold)
              {
                  diff=normVec[n]-relSigsM[m-1][n];
                  diff *= diff;
                  leDiff += diff;
              }
          }
      }

      //Obtencion de la diferencia derecha
      if(m%157 != 156)
      {
          riDiff = 0;
          for(n=0;n<=15;n++)
          {
              if(normVec[n]>treshold)
              {
                  diff=normVec[n]-relSigsM[m+1][n];
                  diff *= diff;
                  riDiff += diff;
              }
          }
      }

      //Obtencion de la diferencia superior
      if(m/157 != 156)
      {
          upDiff = 0;
          for(n=0;n<=15;n++)
          {
              if(normVec[n]>treshold)
              {
                  diff=normVec[n]-relSigsM[m-1][n];
                  diff *= diff;
                  upDiff += diff;
              }
          }
      }

      //Obtencion de la diferencia inferior
      if(m/157 != 0)
      {
          doDiff = 0;
          for(n=0;n<=15;n++)
          {
              if(normVec[n]>treshold)
              {
                  diff=normVec[n]-relSigsM[m-1][n];
                  diff *= diff;
                  doDiff += diff;
              }
          }
      }
      //Actualize m state
      if(onDiff >= leDiff)
        m--;
      else
      {
        if(onDiff >= riDiff)
          m++;
        else
        {
          if(onDiff >= doDiff)
            m-157;
          else
          {
            if(onDiff >= upDiff)
              m+157;
          }
        }
      }

}

xPrada=pointListM[counter][0];
yPrada=pointListM[counter][1];
 printf("\nPosition: %i,%i\n",xPrada,yPrada);
	cuentasIFS=count1;
render19->Fill();
}
}

cout << "\nThe Number of Events is: " << count <<endl;

fclose(out);

f->Write("",TObject::kOverwrite);


}

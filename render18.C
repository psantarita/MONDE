#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TTree.h"
#include <TRandom.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <Riostream.h>

void render18(char *name="NOTHING", char *rootFile="render18.root")
{

 printf("The argument is %s\n", name);
 printf("The second argument is %s\n", rootFile);

TFile *f = new TFile(rootFile,"UPDATE");

TTree *render18 = new TTree("render18","Tree data");

render18->Write("render18",TObject::kOverwrite);


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
  Double_t Adetvec[16],normVec[16];

  Double_t posdetxvec[16] = {79.35, 49.35, 34.35, 2.5, 0., 2.5, 34.35, 49.35, 79.35, 109.35, 124.35, 156.35, 158.7, 156.2, 124.35, 109.35};

  Double_t posdetyvec[16] = {0., 0., 0., 2.5, 35.0, 67.5, 70., 70., 70., 70., 70., 67.5, 35., 2.5, 0., 0.};

  float inda[16];


render18->Branch("ADetector1render18",&Adect1,"Adect1/D");
render18->Branch("ADetector2render18",&Adect2,"Adect2/D");
render18->Branch("ADetector3render18",&Adect3,"Adect3/D");
render18->Branch("ADetector4render18",&Adect4,"Adect4/D");
render18->Branch("ADetector5render18",&Adect5,"Adect5/D");
render18->Branch("ADetector6render18",&Adect6,"Adect6/D");
render18->Branch("ADetector7render18",&Adect7,"Adect7/D");
render18->Branch("ADetector8render18",&Adect8,"Adect8/D");
render18->Branch("ADetector9render18",&Adect9,"Adect9/D");
render18->Branch("ADetector10render18",&Adect10,"Adect10/D");
render18->Branch("ADetector11render18",&Adect11,"Adect11/D");
render18->Branch("ADetector12render18",&Adect12,"Adect12/D");
render18->Branch("ADetector13render18",&Adect13,"Adect13/D");
render18->Branch("ADetector14render18",&Adect14,"Adect14/D");
render18->Branch("ADetector15render18",&Adect15,"Adect15/D");
render18->Branch("ADetector16render18",&Adect16,"Adect16/D");


render18->Branch("xtrender18",&xt,"xt/D");
render18->Branch("ytrender18",&yt,"yt/D");

render18->Branch("xPradarender18",&xPrada,"xPrada/D");
render18->Branch("yPradarender18",&yPrada,"yPrada/D");

// Detectores Externo

	Int_t DetectorExt1, DetectorExt2;
	Int_t d1ext, d2ext;
	Int_t ADetectorExt1, ADetectorExt2;
	Int_t BIASminext, BIASmaxext;
	Double_t ADectExt1, ADectExt2;


render18->Branch("DetectorExt1render18",&DetectorExt1,"DetectorExt1/I");
render18->Branch("DetectorExt2render18",&DetectorExt2,"DetectorExt2/I");
render18->Branch("ADetectorExt1render18",&ADetectorExt1,"ADetectorExt1/I");
render18->Branch("ADetectorExt2render18",&ADetectorExt2,"ADetectorExt2/I");


	BIASminext=0;
	BIASmaxext=4000;

//PRADA Declarations

int m,n,counter;
double minDiff,diff,sum,treshold;
minDiff = 100;
treshold = 0.15;


	Int_t cuentasIFS;

render18->Branch("cuentasIFS",&cuentasIFS,"cuentasIFS/I");

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
Double_t relSigEvent[16];

FILE *relSigs;
relSigs = fopen("relSigs.txt","r");
while(!feof(relSigs)&&j<10833)  {

  fscanf(relSigs,"%lf %lf %lf
  %lf %lf %lf %lf %lf",&rs1,&rs2,&rs3,&rs4,&rs5,&rs6,&rs7,&rs8);
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
	count+=1;
	count1=0;
  if ( !d1 == 0 ) {
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

// MONDE detectors

	for (int i=0; i<16; i++){

            Adetvec[i]=0;

        }

		dect1=0;
		Adect1=0;
	//if (d1<BIASmax && d1>BIASmin) {
  if (true) {

		count1+=1;
		dect1=d1;
		Adect1=(1.0*dect1)+0;
		Adetvec[0] = Adect1;


	}

	  dect2=0;
		Adect2=0;
	//if (d2<BIASmax && d2>BIASmin) {
  if (true) {
		count1+=1;
		dect2=d2;
		Adect2=(1.0*dect2)+0;
		Adetvec[1] = Adect2;

	}
		dect3=0;
		Adect3=0;
	//if (d3<BIASmax && d3>BIASmin) {
    if (true) {
		count1+=1;
		dect3=d3;
		Adect3=(1.0*dect3)+0;
		Adetvec[2] = Adect3;

	}

		dect4=0;
		Adect4=0;
	//if (d4<BIASmax && d4>BIASmin) {
  if (true) {
		count1+=1;
		dect4=d4;
		Adect4=(1.0*dect4)-0;
		Adetvec[3] = Adect4;



	}
		dect5=0;
		Adect5=0;
	//if (d5<BIASmax && d5>BIASmin) {
  if (true) {
		count1+=1;
		dect5=d5;
		Adect5=(1.0*dect5)+0;
		Adetvec[4] = Adect5;



	}
		dect6=0;
		Adect6=0;
	//if (d6<BIASmax && d6>BIASmin) {
  if (true) {
		count1+=1;
		dect6=d6;
		Adect6=(1.0*dect6)-0;
		Adetvec[5] = Adect6;


	}
		dect7=0;
		Adect7=0;
	//if (d7<BIASmax && d7>BIASmin) {
  if (true) {
		count1+=1;
		dect7=d7;
		Adect7=(1.0*dect7)+0;
		Adetvec[6] = Adect7;

	}
		dect8=0;
		Adect8=0;
	//if (d8<BIASmax && d8>BIASmin) {
  if (true) {
		count1+=1;
		dect8=d8;
		Adect8=(1.0*dect8)+0;
		Adetvec[7] = Adect8;

	}

		dect9=0;
		Adect9=0;
	//if (d9<BIASmax && d9>BIASmin) {
  if (true) {
		count1+=1;
		dect9=d9;
		Adect9=(1.0*dect9)+0;
		Adetvec[8] = Adect9;



	}
		dect10=0;
		Adect10=0;
	//if (d10<BIASmax && d10>BIASmin) {
  if (true) {
		count1+=1;
		dect10=d10;
		Adect10=(1.0*dect10)+0;
		Adetvec[9] = Adect10;



	}
		dect11=0;
		Adect11=0;
	//if (d11<BIASmax && d11>BIASmin) {
  if (true) {
		count1+=1;
		dect11=d11;
		Adect11=(1.0*dect11)+0;
		Adetvec[10] = Adect11;


	}
		dect12=0;
		Adect12=0;
	//if (d12<BIASmax && d12>BIASmin) {
  if (true) {
		count1+=1;
		dect12=d12;
		Adect12=(1.0*dect12)+0;
		Adetvec[11] = Adect12;



	}
		dect13=0;
		Adect13=0;
	//if (d13<BIASmax && d13>BIASmin) {
  if (true) {
		count1+=1;
		dect13=d13;
		Adect13=(1.0*dect13)+0;
		Adetvec[12] = Adect13;
	}
		dect14=0;
		Adect14=0;
	//if (d14<BIASmax && d14>BIASmin) {
  if (true) {
		count1+=1;
		dect14=d14;
		Adect14=(1.0*dect14)+0;
		Adetvec[13] = Adect14;

	}
		dect15=0;
		Adect15=0;
	//if (d15<BIASmax && d15>BIASmin) {
  if (true) {
		count1+=1;
		dect15=d15;
		Adect15=(1.0*dect15)+0;
		Adetvec[14] = Adect15;


	}
		dect16=0;
		Adect16=0;

	//if (d16<BIASmax && d16>BIASmin) {
  if (true) {
		count1+=1;
		dect16=d16;
		Adect16=(1.0*dect16)+0;
		Adetvec[15] = Adect16;
	}

 //Normalization of Event
max=0;
 //TMath::Sort(size,Adetvec,inda,kTRUE);
for (i = 0; i < 16; i++) {
  if(Adetvec[i]>Adetvec[int(max)])
    max = i;
}

//printf("\nMax element: %f",max);
 //max=inda[0];
 for (int i=0; i<16; i++){
           normVec[i]= Adetvec[i]/Adetvec[int(max)];
           //printf("\n%f / %f = %f  ",Adetvec[i],Adetvec[int(max)],normVec[i]);
       }

//PRADA
minDiff=100;
m=0;
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
      //  printf("%i,%i: Over treshold with ",m,n);
          //printf(" %f - %f = %f\n", normVec[n],relSigsM[m][n],diff);
        }
        //printf("\n\n");
    //else
      //printf("%i,%i: Under treshold  ",m,n);
    }
    //printf("\nActual sum %f  ",sum );
  if (sum<minDiff)
  {
    minDiff = sum;
    counter = m;
    //printf("\nTotal diff: %f and %i,%i with m as %i\n",minDiff,pointListM[counter][0],pointListM[counter][1],m);
  }
}
xPrada=pointListM[counter][0];
yPrada=pointListM[counter][1];

// printf("\nPosition: %i,%i\n",xPrada,yPrada);


	cuentasIFS=count1;

	xarribatodos=0;
	yarribatodos=0;
	abajotodos=0;
	xt=0;
	yt=0;


// Anger Position


if(cuentasIFS>=2){

	for (int i=0; i<16; i++){

				xarribatodos += posdetxvec[i]*Adetvec[i];
				yarribatodos += posdetyvec[i]*Adetvec[i];
				abajotodos += Adetvec[i];

			}

			xt= (xarribatodos/abajotodos);
			yt= (yarribatodos/abajotodos);

	}

render18->Fill();


}

}

cout << "\nThe Number of Events is: " << count <<endl;

fclose(out);

f->Write("",TObject::kOverwrite);


}

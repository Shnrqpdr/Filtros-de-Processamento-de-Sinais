#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TAM 1024

void windowing(int kernel, double *RealAxis, double *ImaginaryAxis) {

    int i, j, k, index; 
	double *time;
	
	time = (double*) malloc( TAM*sizeof(double)); 

	for( i=0; i < TAM; i++) {

    	index = i + kernel/2;
        
  	    if(index > TAM-1){
		    index = index - TAM;
		}
		
		time[index] = RealAxis[i];
		RealAxis[i] = 0;	
		ImaginaryAxis[i] = 0;		
    }
    
    for( i=0; i < TAM; i++) {
        RealAxis[i] = time[i];
    }
	
	for( i=0; i < TAM; i++) {
        if( i <= kernel) {
			      RealAxis[i] = RealAxis[i]*(0.54 - 0.46*cos((2.*M_PI*i)/kernel)); 
		}  
		else {	
       	    RealAxis[i] = 0;
		        ImaginaryAxis[i] = 0;	
		}	
	}
}

void fourierTransform(double *RealAxis, double *ImaginaryAxis) {

    int i, j, k, m, l, le, le2, aux;
    double  tr, ti, ur, ui, sr, si;

    m = (int)(log(TAM)/log(2));
    
    j = TAM/2;
	
    for( i=1; i < TAM-2; i++)
    {
        if(i < j)
        {
            tr = RealAxis[j];
			      ti = ImaginaryAxis[j];
			      RealAxis[j] = RealAxis[i];
			      ImaginaryAxis[j] = ImaginaryAxis[i];
			      RealAxis[i] = tr;
			      ImaginaryAxis[i] = ti;		
		    }
		    
		    k = TAM/2;
		    
		    while(k <= j)
		    {
            j = j - k;
			      k = k/2;
		    }
		    
		    j = j + k;
	  }

	  for( l=1; l<=m; l++)
	  {
        le = (int)pow(2,l); 
		    le2 = le/2;
		    ur = 1;
		    ui = 0;
		    sr = cos(M_PI/(double)le2); 
		    si = (-1)*sin(M_PI/(double)le2); 
		    
		    for( j=1; j <= le2; j++)
		    {
            for( i=j-1; i <= TAM-1; i=i+le)
            {
                aux = i + le2;	
				        tr = RealAxis[aux]*ur - ImaginaryAxis[aux]*ui;
				        ti = RealAxis[aux]*ui + ImaginaryAxis[aux]*ur;
				        RealAxis[aux] = RealAxis[i] - tr;
				        ImaginaryAxis[aux] = ImaginaryAxis[i] - ti;
				        RealAxis[i] = RealAxis[i] + tr;
			         	ImaginaryAxis[i] = ImaginaryAxis[i] + ti;		
			      }	
			      
			      tr = ur;
			      ur = tr*sr - ui*si;
			      ui = tr*si + ui*sr;
        }
    }
}

void main() {

	int i, j, kernel = 500;
	double *RealAxis, *ImaginaryAxis, *MX;
	double *time;
	
	RealAxis = (double *)calloc(TAM, sizeof(double));
	ImaginaryAxis = (double *)calloc(TAM, sizeof(double));
	MX = (double *)calloc(TAM, sizeof(double));
	time = (double *)calloc(TAM, sizeof(double));
	
	FILE *inputFile, *fourierFile, *kernelFile, *outputFile;
	
	inputFile = fopen("seno5.txt", "r+");
	fourierFile = fopen("fourier.dat", "w+");
	kernelFile = fopen("kernel.dat", "w+");
	outputFile = fopen("MX.dat", "w+");

	fprintf(fourierFile, "RX\tIX\n");
	fprintf(kernelFile, "RX\tIX\n");
	fprintf(outputFile, "RX\tIX\n");
	
	for(i = 0; i < TAM/2; i++)
		fscanf(inputFile, "%lf\t%lf", &RealAxis[i], &ImaginaryAxis[i]);
		
	fourierTransform(RealAxis, ImaginaryAxis);
	
	for(i = 0; i < TAM; i++){
	
		RealAxis[i] /= TAM;
		ImaginaryAxis[i] /= -1*TAM;
	}
	
	for(i = 0; i < TAM; i++)
		fprintf(fourierFile, "%d %lf\n", i, sqrt(pow(RealAxis[i],2) + pow(ImaginaryAxis[i],2)));
	
	
	windowing(kernel, RealAxis, ImaginaryAxis);
	
	for(i = 0; i < TAM/2; i++)
		fprintf(kernelFile, "%d %lf\n", i, sqrt(pow(RealAxis[i],2) + pow(ImaginaryAxis[i],2)));
	
	fourierTransform(RealAxis, ImaginaryAxis);
	
	for(i = 0; i < TAM/2; i++){
	
		MX[i] = 2*sqrt(pow(RealAxis[i],2) + pow(ImaginaryAxis[i],2));
		time[i] = (double) i/(double) TAM;
		fprintf(outputFile, "%lf %lf\n", time[i],MX[i]);
	}
}






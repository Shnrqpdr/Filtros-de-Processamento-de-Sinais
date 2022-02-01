#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void seno(int x, char name[]) {

    FILE *file;

    file=fopen(name, "w");

    fprintf(file, "i\tseno\n");

    for(double i = 0; i <= 0.5; i = i + 0.0001){
        fprintf(file, "%f %f\n", i, (1.0/4.0)*(sin((2*x + 20)*i)) + 0.28);
    }

}

void main(int argc, char *argv[]) {

    seno(atoi(argv[1]), argv[2]);

}
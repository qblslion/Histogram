#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include "classHistogram.h"
using namespace std;

histogram::histogram()
{
    memset(H,0,sizeof(H));
}

histogram::~histogram()
{

}

void histogram::getHistogram(){
    unsigned int i;
    FILE* f=fopen("D:\\histogram.xls","wb");
    for(i=0;i<width*height;i++){
        H[img5[i]]++;
    }

    for(i=0;i<256;i++){
        fprintf(f,"%d\n",H[i]);
        printf("%d ",H[i]);
    }
}

void histogram::histogramFun(){
    grayFun();
    getHistogram();
}

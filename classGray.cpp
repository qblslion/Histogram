#include<iostream>
#include<cstdlib>
#include<cstdio>
#include"classGray.h"
using namespace std;

gray::gray():BMP(){
    img4=new unsigned char[n+1];
    img5=new unsigned char[n+1];
    temp=new unsigned char[n+1];

}

gray::~gray(){
    delete img4;
    delete img5;
    delete temp;
}

void gray::changeGray(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight){
			int i,j;
			for(i=0;i<ImgWidth*ImgHeight;i++){
                        char temp=(unsigned char)((img2[i*3]*11+img2[i*3+1]*59+img2[i*3+2]*30)/100);
                        img3[i]=temp;
            }
}

 void gray::grayFun(){
            allFun();
            copyImg(img4,width,height);
			changeGray(img4,img5,width,height);//从img4->img5的灰度转换
            SaveBipFile(img5,width*height*3,6);
}

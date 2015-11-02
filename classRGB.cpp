#include<iostream>
#include<cstdlib>
#include"classRGB.h"
using namespace std;

son::son():BMP(){
}

son::~son(){
}

void son::Red(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight){
			for(int i=0;i<ImgWidth*ImgHeight*3;i+=3){
				img3[i]=img2[i];
				img3[i+1]=0;
				img3[i+2]=0;
		}
}
void son::Green(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight){
			for(int i=0;i<ImgWidth*ImgHeight*3;i+=3){
				img3[i]=0;
				img3[i+1]=img2[i+1];
				img3[i+2]=0;
		}
}
void son::Blue(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight){
			for(int i=0;i<ImgWidth*ImgHeight*3;i+=3){
				img3[i]=0;
				img3[i+1]=0;
				img3[i+2]=img2[i+2];
		}
}
void son::Yellow(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight){
			for(int i=0;i<ImgWidth*ImgHeight*3;i+=3){
				img3[i]=img2[i];
				img3[i+1]=img2[i+1];
				img3[i+2]=0;
		}
}
void son::Magenta(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight){
			for(int i=0;i<ImgWidth*ImgHeight*3;i+=3){
				img3[i]=img2[i];
				img3[i+1]=0;
				img3[i+2]=img2[i+2];
		}
}
void son::Cyan(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight){
			for(int i=0;i<ImgWidth*ImgHeight*3;i+=3){
				img3[i]=0;
				img3[i+1]=img2[i+1];
				img3[i+2]=img2[i+2];
		}
}

void son::sonFun(){
    allFun();
	SaveBipFile(img2,width*height*3,8);

	//红色
	Red(img2,img3,width,height);
	SaveBipFile(img3,width*height*3,0);

	//绿色
	Green(img2,img3,width,height);
	SaveBipFile(img3,width*height*3,1);

	//蓝色
	Blue(img2,img3,width,height);
	SaveBipFile(img3,width*height*3,2);

	//黄色
	Yellow(img2,img3,width,height);
	SaveBipFile(img3,width*height*3,3);

	//品红
	Magenta(img2,img3,width,height);
	SaveBipFile(img3,width*height*3,4);

	//青色
	Cyan(img2,img3,width,height);
	SaveBipFile(img3,width*height*3,5);

}

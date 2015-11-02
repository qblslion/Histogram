#include<cstdlib>
#include<fstream>
#include<iostream>
#include "classParent.h"
using namespace std;

BMP::BMP(){
	PrintBMPHead();
    PrintBMPInfo();

    n=getSize();
	width=getWidth();
	height=getHeight();
    img=new unsigned char[n+1];
	img2=new unsigned char[n+1];
	img3=new unsigned char[n+1];
}
BMP::~BMP(){
	delete img;
	delete img2;
	delete img3;
}

int BMP::getWidth(){
	return MyInfo.ImageWidth;
}

int BMP::getHeight(){
	return MyInfo.ImageHeight;
}

int BMP::getSize(){
    return Myheader.FileSize-54;
}

void BMP::PrintBMPHead(){
		FILE *mybmp;//1：定义文件指针
		mybmp=fopen(FILEPATH,"r");//2：打开文件：文件指针指向磁盘文件缓冲区，通过移动指针来实现对文件的操作
		//3：文件处理
		fread(&Myheader.B,1,1,mybmp);
		fread(&Myheader.M,1,1,mybmp);
		fread(&Myheader.FileSize,1,4,mybmp);
		fread(&Myheader.Reserved1,1,4,mybmp);
		fread(&Myheader.HeaderLength,1,4,mybmp);

		printf("FileType:\t\t%c %c P \n",Myheader.B,Myheader.M);
		printf("FileSize:\t\t%ld bytes\n",Myheader.FileSize);
		printf("HeaderLength:\t\t%ld \n",Myheader.HeaderLength);
		//4：关闭文件
		fclose(mybmp);

	}

void BMP::PrintBMPInfo()
		{
			FILE *mybmp;//1：定义文件指针
			mybmp=fopen(FILEPATH,"r");

			fseek(mybmp,14,0);//指针移动控制函数 fseek(文件指针,offset,from);
			fread(&MyInfo.InfoSize,1,4,mybmp);
			fread(&MyInfo.ImageWidth,1,4,mybmp);
			fread(&MyInfo.ImageHeight,1,4,mybmp);
			fread(&MyInfo.Level,1,2,mybmp);
			fread(&MyInfo.ColorDepth,1,2,mybmp);
			fread(&MyInfo.Compress,1,4,mybmp);
			fread(&MyInfo.PixelBytes,1,4,mybmp);
			fread(&MyInfo.horizon,1,4,mybmp);
			fread(&MyInfo.vertical,1,4,mybmp);
			fread(&MyInfo.offset1,1,4,mybmp);
			fread(&MyInfo.offset2,1,4,mybmp);

			printf("InfoSize:\t\t%ld\n",MyInfo.InfoSize);
			printf("ImageWidth:\t\t%ld\n",MyInfo.ImageWidth);
			printf("ImageHeight:\t\t%ld\n",MyInfo.ImageHeight);
			printf("Height*Width:\t\t%ld\n",MyInfo.ImageHeight*MyInfo.ImageWidth);
			printf("Level:\t\t%ld\n",MyInfo.Level);
			printf("ColorDepth:\t\t%ld\n",MyInfo.ColorDepth);
			printf("PixelBytes:\t\t%ld\n",MyInfo.PixelBytes);

			fclose(mybmp);

		}

void BMP::ReadBidata(unsigned char* img){
			FILE *mybmp;//1：定义文件指针
			unsigned int i;

			mybmp=fopen(FILEPATH,"rb");
			fseek(mybmp,54,0);
			for(i=0;i<n;i++)
				img[i]=fgetc(mybmp);//字符方式文件读写函数:fgetc()和fputc()

			fclose(mybmp);
		}

void BMP::ReadBidata02(unsigned char* img,unsigned char* img2){//delete zeros
			//copy imag to img2 and delete the plused zeros
			unsigned int i,_i=0;
			unsigned _img_w;

			_img_w=MyInfo.ImageWidth*3;
			if((_img_w%4)!=0)
				_img_w=((MyInfo.ImageWidth*3)/4+1)*4;//补0

			for(i=0;i<(Myheader.FileSize-54)/_img_w*_img_w;i++){
				if(i%_img_w<MyInfo.ImageWidth*3){
					img2[_i]=img[i];
					_i++;
				}
			}

		}

void BMP::InvertImg(unsigned char* img){
			unsigned char temp;
			unsigned int i,j,x,y;
			//unsigned int data_size;
			x=MyInfo.ImageWidth*3;//一行有多少个像素
			y=MyInfo.ImageHeight;//一列有多少个像素

			//从高度中间点把所有的像素点以高度中线对调
			for(j=0;j<y/2;j++){
				for(i=0;i<x;i++){
					temp=img[i+x*j];
					img[i+x*j]=img[i+x*(y-j-1)];
					img[i+x*(y-j-1)]=temp;
				}
			}

		}

void BMP::SaveBipFile(unsigned char* img2,unsigned int data_size,unsigned int t){
		unsigned int i;
		if(t==0){
			FILE *f=fopen("D:\\f0_red.raw","wb");
			for(i=0;i<data_size;i++){
				fputc(img2[i],f);
			}
			fclose(f);
		}
		else if(t==1){
			FILE *f=fopen("D:\\f1_green.raw","wb");
			for(i=0;i<data_size;i++){
				fputc(img2[i],f);
			}
			fclose(f);
		}
		else if(t==2){
			FILE *f=fopen("D:\\f2_blue.raw","wb");
			for(i=0;i<data_size;i++){
				fputc(img2[i],f);
			}
			fclose(f);
		}
		else if(t==3){
			FILE *f=fopen("D:\\f3_yellow.raw","wb");
			for(i=0;i<data_size;i++){
				fputc(img2[i],f);
			}
			fclose(f);
		}
		else if(t==4){
			FILE *f=fopen("D:\\f4_magenta.raw","wb");
			for(i=0;i<data_size;i++){
				fputc(img2[i],f);
			}
			fclose(f);
		}
		else if(t==5){
			FILE *f=fopen("D:\\f5_cyan.raw","wb");
			for(i=0;i<data_size;i++){
				fputc(img2[i],f);
			}
			fclose(f);
		}

		else if(t==6){
			FILE *f=fopen("D:\\gray.raw","wb");
			for(i=0;i<data_size;i++){
				fputc(img2[i],f);
			}
			fclose(f);
		}

		else if(t==7){
            FILE *f=fopen("D:\\histogram.raw","wb");
            for(i=0;i<data_size;i++){
                fputc(img2[i],f);
            }
		}

		else{
			FILE *f=fopen("D:\\original.raw","wb");
			for(i=0;i<data_size;i++){
				fputc(img2[i],f);
			}
			fclose(f);
		}

}

void BMP::invertBR(unsigned char *img,unsigned long ImgWidth,unsigned long ImgHeight){
	int i;
	unsigned char temp;

	for(i=0;i<ImgWidth*ImgHeight*3;i+=3){
		temp=img[i];
		img[i]=img[i+2];
		img[i+2]=temp;
	}
}


void BMP::copyImg(unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight){
    int i;
    for(i=0;i<ImgWidth*ImgHeight*3;i++){
        img3[i]=img2[i];
    }
}

void BMP::allFun(){
	ReadBidata(img);
	/*
	FILE *p=fopen("D:\\bitmap01.raw","wb");//打开二进制文件进行只写
	for(i=0;i<data_size;i++){
		fwrite(&img[i],sizeof(unsigned char),1,p);//数据块方式文件读写函数fread()和fwrite(),二进制
	}*/

	ReadBidata02(img,img2);
	/*FILE *f=fopen("D:\\bitmap02.raw","wb");
	for(i=0;i<data_size;i++){
		fwrite(&img2[i],sizeof(unsigned char),1,f);
	}*/

	InvertImg(img2);

	/*FILE *ff=fopen("D:\\bitmap03.raw","wb");
	for(i=0;i<data_size;i++){
		fwrite(&img2[i],sizeof(unsigned char),1,ff);
	}*/

	//bgr和rgb互转
	invertBR(img,width,height);
	/*
	FILE *BR=fopen("D:\\bitmap05.raw","wb");
		for(i=0;i<data_size;i++){
			fwrite(&img[i],sizeof(unsigned char),1,BR);
	}

	fclose(p);
	fclose(f);
	fclose(ff);
	fclose(BR);*/
}


#ifndef CLASSPARENT_H
#define CLASSPARENT_H
#include"Structdef.h"
class BMP{
	private:
		BMPFileHeader Myheader;
		BMPFileInfo MyInfo;

	public:
		BMP();
		~BMP();
		int getSize();
		int getWidth();
		int getHeight();
		void PrintBMPHead();
		void PrintBMPInfo();
		void ReadBidata(unsigned char* img);//��ȡbmp
		void ReadBidata02(unsigned char* img,unsigned char* img2);//ȥ��0
		void InvertImg(unsigned char* img);//��ת
		void invertBR(unsigned char *img,unsigned long ImgWidth,unsigned long ImgHeight);//bgr��rgb��ת
		void SaveBipFile(unsigned char* img2,unsigned int data_size,unsigned int t);
		void copyImg(unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight);
		void allFun();

	protected:
		unsigned char* img;
		unsigned char* img2;
		unsigned char* img3;
		unsigned int n;
		unsigned int width;
		unsigned int height;
};

#endif // CLASSDEF_H_INCLUDED

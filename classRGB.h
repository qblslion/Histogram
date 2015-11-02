#ifndef CLASSRGB_H
#define CLASSRRGB_H
#include"classParent.h"
class son:public BMP{
	public:
		son();
		~son();
		//void SaveBipFile(unsigned char* img2,unsigned int data_size,unsigned int t);
		void Red(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight);
		void Green(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight);
		void Blue(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight);
		void Yellow(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight);
		void Magenta(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight);
		void Cyan(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight);
		void sonFun();
	protected:

};


#endif // CLASSSON_H_INCLUDED

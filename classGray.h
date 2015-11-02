#ifndef CLASSGRAY_H
#define CLASSGRAY_H
#include"classParent.h"

class gray:public BMP{
	protected:
		unsigned char* img4;
		unsigned char* img5;
		unsigned char* temp;
	public:
		gray();
		virtual ~gray();
		void changeGray(unsigned char*img2,unsigned char*img3,unsigned int ImgWidth,unsigned int ImgHeight);
		virtual void grayFun();
};


#endif // CLASSGRAY_H_INCLUDED

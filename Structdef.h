#ifndef STRUCTDEF_H
#define STRUCTDEF_H

#define FILEPATH "D:\\bitmap01.bmp"
typedef struct _BMPFileHeader{
	unsigned char B;
	unsigned char M;
	unsigned long FileSize;
	unsigned long Reserved1;
	unsigned long HeaderLength;

}BMPFileHeader;

typedef struct _BMPFileInfo{
	//typedef为C语言关键字，作用是为一种数据类型定义一个新名字, 简化一些比较复杂的类型声明
	unsigned short InfoSize;
	unsigned long ImageWidth;
	unsigned long ImageHeight;
	unsigned short Level;
	unsigned short ColorDepth;
	unsigned long Compress;
	unsigned long PixelBytes;
	unsigned long horizon;
	unsigned long vertical;
	unsigned long offset1;
	unsigned long offset2;
}BMPFileInfo;//这里BMPFileInfo就是struct _BMPFileInfo的别名
             //如果没有typedef，就要写成struct _BMPFileInfo BMPFileInfo来声明

#endif // STRUCTDEF_H_INCLUDED

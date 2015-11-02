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
	//typedefΪC���Թؼ��֣�������Ϊһ���������Ͷ���һ��������, ��һЩ�Ƚϸ��ӵ���������
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
}BMPFileInfo;//����BMPFileInfo����struct _BMPFileInfo�ı���
             //���û��typedef����Ҫд��struct _BMPFileInfo BMPFileInfo������

#endif // STRUCTDEF_H_INCLUDED

#include<iostream>
#include<stdlib.h>
#include "classParent.h"
#include "classRGB.h"
#include "classGray.h"
#include "classHistogram.h"
using namespace std;
int main(){
	son sonbmp;
	sonbmp.sonFun();
	//gray graybmp;
	//graybmp.grayFun();
	histogram hisbmp;
	hisbmp.histogramFun();

	return 0;
}
/* struct��typedef struct :
   http://blog.csdn.net/kobesdu/article/details/38110415

   �ļ�����299ҳ */
//��0 б��.
//BMP:B G R
//PS:G R B

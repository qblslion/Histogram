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
/* struct和typedef struct :
   http://blog.csdn.net/kobesdu/article/details/38110415

   文件处理：299页 */
//有0 斜的.
//BMP:B G R
//PS:G R B

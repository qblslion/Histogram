#ifndef CLASSHISTOGRAM_H
#define CLASSHISTOGRAM_H
#include"classGray.h"
const int maxn=256;
class histogram:public gray{
    protected:
        int H[maxn];

    public:
        histogram();
        ~histogram();
        void getHistogram();
        void histogramFun();

};

#endif // HISTOGRAM_H

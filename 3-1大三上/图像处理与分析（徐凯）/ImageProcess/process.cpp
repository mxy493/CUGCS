#include "process.h"


QImage imageInverse(const QImage &srcImage)
{
    QImage resultImage(srcImage.size(),QImage::Format_Indexed8);
   // QImage resultImage(srcImage);
    //首先建立新图像的colorTable
    QVector<QRgb> colorTableVec;
    for(int i=0;i<256;i++)
    {
        colorTableVec.push_back(qRgb(255-i,255-i,255-i));
    }
    resultImage.setColorTable(colorTableVec);
////为了避免对每一个像素进行计算，所以直接建立一个数组，进行索引
//    int pixelMap[256];
//    for(int i=0;i<256;i++)
//    {
//        pixelMap[i]=255-i;
//    }
    //然后对图像的每一个像素进行修改
    for(int i=0;i<resultImage.width();i++)
    {
        for(int j=0;j<resultImage.height();j++)
        {
            //由于colorTable经过了处理，所以直接采用rgb的索引就好了
            uint index=srcImage.pixelColor(i,j).red();//灰度图像三个通道数值一致，所以这里取红色
            resultImage.setPixel(i,j,index);
        }
    }
    return resultImage;
}

MyImage imageInverse(const MyImage &srcImage)
{
    MyImage resultImage(srcImage.width(),srcImage.height());
    //由于建立新图像的时候已经修改了ColorTable，所以这里不使用，改用索引
    unsigned int indexArry[256];
    for(int i=0;i<256;i++)
    {
        indexArry[i]=255-i;
    }
    for(int i=0;i<resultImage.width();i++)
    {
        for(int j=0;j<resultImage.height();j++)
        {
            unsigned int index=indexArry[srcImage.getPixelColor(i,j).rgbBlue];
            resultImage.setPixelIndex(i,j,index);
        }
    }
    return resultImage;
}


QImage gamaProcess(const QImage &srcImage, double gama)
{
    QImage resultImage(srcImage.size(),QImage::Format_Indexed8);
    //同样首先建立新图像的colorTable
    QVector<QRgb> colorTableVec;
    for(int i=0;i<256;i++)
    {
        //int grayValue=((c*pow(i,gama))>255)?255:(c*pow(i,gama));
//        int grayValue=pow(i,gama);
//上面的写法有错，似乎应该考虑采用压缩的办法，另外这种写法和书上的图的函数曲线也不一样

        double r=(double)i/255.0;
        int grayValue=pow(r,gama)*255+0.5;
       // cout<<grayValue<<endl;
        colorTableVec.push_back(qRgb(grayValue,grayValue,grayValue));
    }
    resultImage.setColorTable(colorTableVec);
    for(int i=0;i<resultImage.width();i++)
    {
        for(int j=0;j<resultImage.height();j++)
        {
            //由于colorTable经过了处理，所以直接采用rgb的索引就好了
            uint index=srcImage.pixelColor(i,j).red();//灰度图像三个通道数值一致，所以这里取红色
#if OUT_RGB
            cout<<index<<"  ";
#endif
            resultImage.setPixel(i,j,index);
        }
#if OUT_RGB
            cout<<endl;
#endif
    }
    return resultImage;
}

MyImage gamaProcess(const MyImage &srcImage, double gama)
{
    MyImage resultImage(srcImage.width(),srcImage.height());
    //同样的，设置索引
    unsigned indexArry[256];
    for(int i=0;i<256;i++)
    {
        double r=(double)i/255.0;
        indexArry[i]=pow(r,gama)*255+0.5;
        //indexArry[i]
    }
    for(int i=0;i<resultImage.width();i++)
    {
        for(int j=0;j<resultImage.height();j++)
        {
            unsigned int index=indexArry[srcImage.getPixelColor(i,j).rgbBlue];
            resultImage.setPixelIndex(i,j,index);
            //cout<<index<<"   ";
        }
        //cout<<endl;
    }

    return resultImage;
}


QImage histoEqalizate(const QImage &srcImage)
{
    QImage resultImage(srcImage.size(),QImage::Format_Indexed8);
    //同样的，首先准备建立新的图像的colorTable
    QVector<QRgb> colorTableVec;
    //统计原图像中各个像素值的频数
    int usage[256];
    for(int i=0;i<256;i++)
    {
        usage[i]=0;
    }
    for(int i=0;i<srcImage.width();i++)
    {
        for(int j=0;j<srcImage.height();j++)
        {
            uint index=srcImage.pixelColor(i,j).red();
            //cout<<index<<"  ";
            //colorTable中对应的索引元素值加一就好了
            usage[index]++;
        }
    }
    //计算像素总数
    double totalPixel=srcImage.width()*srcImage.height();
    //然后计算每一个像素的输出灰度值s
    double pr=0;//用于记录当前已经算出的频率的和，避免多次计算
    for(int i=0;i<256;i++)
    {
        //每个灰度值对应的灰度值为灰度值最大数乘当前灰度值累积的频率
        double r=usage[i]/totalPixel;
       // cout<<usageVec[i]<<" ";
        pr+=r;
        int grayValue=255*pr+0.5;
        cout<<grayValue<<" ";
        colorTableVec.push_back(qRgb(grayValue,grayValue,grayValue));
    }
    resultImage.setColorTable(colorTableVec);
    for(int i=0;i<resultImage.width();i++)
    {
        for(int j=0;j<resultImage.height();j++)
        {
            //由于colorTable经过了处理，所以直接采用rgb的索引就好了
            uint index=srcImage.pixelColor(i,j).red();//灰度图像三个通道数值一致，所以这里取红色
#if OUT_RGB
            cout<<index<<"  ";
#endif
            resultImage.setPixel(i,j,index);
        }
#if OUT_RGB
            cout<<endl;
#endif
    }
    return resultImage;
}

MyImage histoEqalizate(const MyImage &srcImage)
{
    MyImage resultImage(srcImage.width(),srcImage.height());
    unsigned int indexArry[256];
    //统计原图像中各个像素值的频数
    int usage[256];
    for(int i=0;i<256;i++)
    {
        usage[i]=0;
    }
    for(int i=0;i<srcImage.width();i++)
    {
        for(int j=0;j<srcImage.height();j++)
        {
            unsigned int index=srcImage.getPixelColor(i,j).rgbBlue;
            //cout<<index<<"  ";
            //colorTable中对应的索引元素值加一就好了
            usage[index]++;
        }
    }
    //计算像素总数
    double totalPixel=srcImage.width()*srcImage.height();
    //然后计算每一个像素的输出灰度值s
    double pr=0;//用于记录当前已经算出的频率的和，避免多次计算
    for(int i=0;i<256;i++)
    {
        //每个灰度值对应的灰度值为灰度值最大数乘当前灰度值累积的频率
        double r=usage[i]/totalPixel;
       // cout<<usageVec[i]<<" ";
        pr+=r;
        int grayValue=255*pr+0.5;
        //cout<<grayValue<<" ";
        indexArry[i]=grayValue;
    }
    for(int i=0;i<resultImage.width();i++)
    {
        for(int j=0;j<resultImage.height();j++)
        {

            unsigned int index=srcImage.getPixelColor(i,j).rgbBlue;
#if OUT_RGB
            cout<<index<<"  ";
#endif
            resultImage.setPixelIndex(i,j,indexArry[index]);
        }
#if OUT_RGB
            cout<<endl;
#endif
    }
    return resultImage;
}


QImage gaussianBlur(const QImage &srcImage, int size, double sigma)
{
    int total;
    double **mask=gaussMask(total,size,sigma);
    //建立二维数组，用于方便计算新图像的值
    int **imageArry=new int*[srcImage.height()+size-1];
    for(int i=0;i<srcImage.height()+size-1;i++)
    {
        imageArry[i]=new int[srcImage.width()+size-1];
    }
    //进行初始化操作
    //首先将拓展的边缘部分置为0
    for(int i=0;i<(size-1)/2;i++)
    {
        for(int j=0;j<srcImage.width()+size-1;j++)
        {
            imageArry[i][j]=0;
            imageArry[srcImage.height()+size-2-i][j]=0;
        }
    }
    for(int i=(size-1)/2;i<srcImage.height()+(size-1)/2;i++)
    {
        for(int j=0;j<(size-1)/2;j++)
        {
            imageArry[i][j]=0;
            imageArry[i][srcImage.width()+size-2-j]=0;
        }
        for(int j=(size-1)/2;j<srcImage.width()+(size-1)/2;j++)
        {
            //imageArry[i][j]=srcImage.pixelColor(i-0.5*(size-1),j-0.5*(size-1)).red();
            imageArry[i][j]=srcImage.pixelColor(j-0.5*(size-1),i-0.5*(size-1)).red();
        }
    }
//    for(int i=0;i<srcImage.height()+size-1;i++)
//    {
//        for(int j=0;j<srcImage.width()+size-1;j++)
//        {
//            cout<<imageArry[i][j]<<"  ";
//        }
//        cout<<endl;
//    }
    //建立新图像
    QImage resultImage(srcImage.size(),QImage::Format_Indexed8);
    QVector<QRgb> colorTableVec;
    for(int i=0;i<256;i++)
    {
        colorTableVec.push_back(qRgb(i,i,i));
    }
    resultImage.setColorTable(colorTableVec);
    //计算新图像的灰度值
    for(int i=0;i<resultImage.height();i++)
    {
        for(int j=0;j<resultImage.width();j++)
        {
            double temp=0;
            for(int index_i=0;index_i<size;index_i++)
            {
                for(int index_j=0;index_j<size;index_j++)
                {
                    temp+=mask[index_i][index_j]*imageArry[i+index_i][j+index_j];
                }
            }
            int grayValue=temp/total+0.5;
            //cout<<grayValue<<endl;
            resultImage.setPixel(j,i,grayValue);
            //cout<<i<<"  "<<j;
        }
    }

    //删除申请的动态数组
    for(int i=0;i<size;i++)
    {
        delete[] mask[i];
    }
    delete[] mask;
    for(int i=0;i<srcImage.height()+size-1;i++)
    {
        delete[] imageArry[i];
    }
    delete[] imageArry;
    return resultImage;


}

MyImage gaussianBlur(const MyImage &srcImage, int size, double sigma)
{
    int total;
    double **mask=gaussMask(total,size,sigma);
    //建立二维数组，用于方便计算新图像的值
    int **imageArry=new int*[srcImage.height()+size-1];
    for(int i=0;i<srcImage.height()+size-1;i++)
    {
        imageArry[i]=new int[srcImage.width()+size-1];
    }
    //进行初始化操作
    //首先将拓展的边缘部分置为0
    for(int i=0;i<(size-1)/2;i++)
    {
        for(int j=0;j<srcImage.width()+size-1;j++)
        {
            imageArry[i][j]=0;
            imageArry[srcImage.height()+size-2-i][j]=0;
        }
    }
    for(int i=(size-1)/2;i<srcImage.height()+(size-1)/2;i++)
    {
        for(int j=0;j<(size-1)/2;j++)
        {
            imageArry[i][j]=0;
            imageArry[i][srcImage.width()+size-2-j]=0;
        }
        for(int j=(size-1)/2;j<srcImage.width()+(size-1)/2;j++)
        {
            //imageArry[i][j]=srcImage.pixelColor(i-0.5*(size-1),j-0.5*(size-1)).red();
            imageArry[i][j]=srcImage.getPixelColor(j-0.5*(size-1),i-0.5*(size-1)).rgbBlue;
        }
    }
//    for(int i=0;i<srcImage.height()+size-1;i++)
//    {
//        for(int j=0;j<srcImage.width()+size-1;j++)
//        {
//            cout<<imageArry[i][j]<<"  ";
//        }
//        cout<<endl;
//    }
    //建立新图像
    MyImage resultImage(srcImage.width(),srcImage.height());
    //计算新图像的灰度值
    for(int i=0;i<resultImage.height();i++)
    {
        for(int j=0;j<resultImage.width();j++)
        {
            double temp=0;
            for(int index_i=0;index_i<size;index_i++)
            {
                for(int index_j=0;index_j<size;index_j++)
                {
                    temp+=mask[index_i][index_j]*imageArry[i+index_i][j+index_j];
                }
            }
            int grayValue=temp/total+0.5;
            //cout<<grayValue<<endl;
            resultImage.setPixelIndex(j,i,grayValue);
            //cout<<i<<"  "<<j;
        }
    }

    //删除申请的动态数组
    for(int i=0;i<size;i++)
    {
        delete[] mask[i];
    }
    delete[] mask;
    for(int i=0;i<srcImage.height()+size-1;i++)
    {
        delete[] imageArry[i];
    }
    delete[] imageArry;
    return resultImage;


}

double **gaussMask(int &total,int size, double sigma)
{
    total=0;
    double **mask=new double*[size];
    for(int i=0;i<size;i++)
    {
        mask[i]=new double[size];
    }
    //释放
//    for(int i=0;i<size;i++)
//    {
//        delete[] mask[i];
//    }
//    delete[] mask;
    //计算模板系数值
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            int x=i-(size-1)/2;
            int y=j-(size-1)/2;
            mask[i][j]=exp(-(x*x+y*y)/(2*sigma*sigma));
            //cout<<mask[i][j]<<" ";
        }
        //cout<<endl;
    }
    //然后归一化
    double r=1/mask[0][0];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            mask[i][j]=(int)(mask[i][j]*r);
            total+=mask[i][j];
            //cout<<mask[i][j]<<"  ";
        }
        //cout<<endl;
    }
    return mask;
}

QImage laplaceProcess(const QImage &srcImage)
{
    double mask[3][3]={{0,1,0},
                       {1,-4,1},
                       {0,1,0}};
    //建立二维数组，用于方便计算新图像的值
    int **imageArry=new int*[srcImage.height()+2];
    for(int i=0;i<srcImage.height()+2;i++)
    {
        imageArry[i]=new int[srcImage.width()+2];
    }
    //进行初始化操作
    //首先将拓展的边缘部分置为0
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<srcImage.width()+2;j++)
        {
            imageArry[i][j]=0;
            imageArry[srcImage.height()+1-i][j]=0;
        }
    }
    for(int i=1;i<srcImage.height()+1;i++)
    {
        for(int j=0;j<1;j++)
        {
            imageArry[i][j]=0;
            imageArry[i][srcImage.width()+1-j]=0;
        }
        for(int j=1;j<srcImage.width()+1;j++)
        {
            //imageArry[i][j]=srcImage.pixelColor(i-0.5*(size-1),j-0.5*(size-1)).red();
            imageArry[i][j]=srcImage.pixelColor(j-1,i-1).red();
        }
    }
//    for(int i=0;i<srcImage.height()+2;i++)
//    {
//        for(int j=0;j<srcImage.width()+2;j++)
//        {
//            cout<<imageArry[i][j]<<"  ";
//        }
//        cout<<endl;
//    }
    //建立新图像
    QImage resultImage(srcImage.size(),QImage::Format_Indexed8);
    //cout<<resultImage.height()<<"  "<<resultImage.width()<<endl;
    QVector<QRgb> colorTableVec;
    for(int i=0;i<256;i++)
    {
        colorTableVec.push_back(qRgb(i,i,i));
    }
    resultImage.setColorTable(colorTableVec);
    //计算新图像的灰度值
    for(int i=0;i<resultImage.height();i++)
    {
        for(int j=0;j<resultImage.width();j++)
        {
            int temp=0;
            for(int index_i=0;index_i<3;index_i++)
            {
                for(int index_j=0;index_j<3;index_j++)
                {
                    temp+=mask[index_i][index_j]*imageArry[i+index_i][j+index_j];
                }
            }
            //int grayValue=temp;
            if(temp<0)
            {
                temp=0;
            }
            if(temp>255)
            {
                temp=255;
            }
            int grayValue=temp+srcImage.pixelColor(j,i).red();
            if(grayValue<0)
            {
                grayValue=0;
            }
            if(grayValue>255)
            {
                grayValue=255;
            }
            //cout<<grayValue<<endl;
            //cout<<i<<"  "<<j<<endl;
            resultImage.setPixel(j,i,grayValue);
           // cout<<i<<"  "<<j<<endl;
        }
    }
    // cout<<"************************";
    //删除申请的动态数组
    for(int i=0;i<srcImage.height()+2;i++)
    {
        delete[] imageArry[i];
    }
    delete[] imageArry;
    return resultImage;
}

MyImage laplaceProcess(const MyImage &srcImage)
{
    double mask[3][3]={{0,1,0},
                       {1,-4,1},
                       {0,1,0}};
    //建立二维数组，用于方便计算新图像的值
    int **imageArry=new int*[srcImage.height()+2];
    for(int i=0;i<srcImage.height()+2;i++)
    {
        imageArry[i]=new int[srcImage.width()+2];
    }
    //进行初始化操作
    //首先将拓展的边缘部分置为0
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<srcImage.width()+2;j++)
        {
            imageArry[i][j]=0;
            imageArry[srcImage.height()+1-i][j]=0;
        }
    }
    for(int i=1;i<srcImage.height()+1;i++)
    {
        for(int j=0;j<1;j++)
        {
            imageArry[i][j]=0;
            imageArry[i][srcImage.width()+1-j]=0;
        }
        for(int j=1;j<srcImage.width()+1;j++)
        {
            //imageArry[i][j]=srcImage.pixelColor(i-0.5*(size-1),j-0.5*(size-1)).red();
            //imageArry[i][j]=srcImage.pixelColor(j-1,i-1).red();
            imageArry[i][j]=srcImage.getPixelColor(j-1,i-1).rgbBlue;
        }
    }
//    for(int i=0;i<srcImage.height()+2;i++)
//    {
//        for(int j=0;j<srcImage.width()+2;j++)
//        {
//            cout<<imageArry[i][j]<<"  ";
//        }
//        cout<<endl;
//    }
    //建立新图像
    MyImage resultImage(srcImage.width(),srcImage.height());
    //cout<<resultImage.height()<<"  "<<resultImage.width()<<endl;
    //计算新图像的灰度值
    for(int i=0;i<resultImage.height();i++)
    {
        for(int j=0;j<resultImage.width();j++)
        {
            int temp=0;
            for(int index_i=0;index_i<3;index_i++)
            {
                for(int index_j=0;index_j<3;index_j++)
                {
                    temp+=mask[index_i][index_j]*imageArry[i+index_i][j+index_j];
                }
            }
            //int grayValue=temp;
            if(temp<0)
            {
                temp=0;
            }
            if(temp>255)
            {
                temp=255;
            }
            //int grayValue=temp+srcImage.pixelColor(j,i).red();
            int grayValue=srcImage.getPixelColor(j,i).rgbBlue-temp;
            if(grayValue<0)
            {
                grayValue=0;
            }

            //cout<<grayValue<<endl;
            //cout<<i<<"  "<<j<<endl;
            //resultImage.setPixel(j,i,grayValue);
            resultImage.setPixelIndex(j,i,grayValue);
           // cout<<i<<"  "<<j<<endl;
        }
    }
    //cout<<"************************";
    //删除申请的动态数组
    for(int i=0;i<srcImage.height()+2;i++)
    {
        delete[] imageArry[i];
    }
    delete[] imageArry;
    return resultImage;
}


#ifndef MYIMAGE_H
#define MYIMAGE_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;


//存储文件头结构
struct BMPHead
{
    unsigned int fileTag=0x424d;//文件标识符，用于判断是不是BMP文件，需要为0x424d,2字节
    unsigned int imageFileSize;//图像文件大小,4字节
    unsigned int resvered0=0;//保留字，2字节，为零
    unsigned int resvered1=0;//保留字，2字节，为零
    unsigned int offBit=1078;//4字节，文件起始位置到图像像素数据的字节偏移量
};
//BMP信息头结构体
struct BMPInfo
{
    unsigned int    infoSize=40;    //4字节，INFO结构体大小
    int             imageWidth=0;    //4字节，图像宽度（以像素为单位）
    int             imageHeight=0;    //4字节，图像高度，有正负之分，判断图形是正还是倒立
    unsigned int    imageColorPlanes=1;    //2字节，图像数据平面，BMP存储RGB数据，因此总为1
    unsigned int    bitCount=8;         //2字节，图像像素位数
    unsigned int    imageCompression=0;     //4字节，0：不压缩，1：RLE8，2：RLE4
    unsigned int    rawImageSize=0;       //4字节，4字节对齐的图像数据大小 This is the size of the raw bitmap data; (wiki)
     int            imageXPelsPerMeter=11797;   //4字节，用象素/米表示的水平分辨率
     int            imageYPelsPerMeter=11797;   //4字节，用象素/米表示的垂直分辨率
    unsigned int   imageColorTableIndexUsed=0;          //4字节，实际使用的调色板索引数，0：使用所有的调色板索引
    unsigned int   imageColorImportant=0;     //4字节，重要的调色板索引数，0：所有的调色板索引都重要
};
//颜色
struct MyRGB
{
    unsigned int rgbBlue;
    unsigned int rgbGreen;
    unsigned int rgbRed;

    unsigned int rgbResvered=0;
    MyRGB()=default;
    MyRGB(int r,int g,int b)
    {
        rgbRed=r;
        rgbBlue=b;
        rgbGreen=g;
        rgbResvered=0;
    }
};

class MyImage
{
public:
    MyImage()=default;
    MyImage(string filePath);//通过文件路径初始化
    MyImage(const MyImage& srcImage);
    //建立一幅大小为width*height的8位灰度图
    MyImage(unsigned int width,unsigned int height);
    ~MyImage();
    //获得(x,y)处的RGB颜色，坐标系原点在图像左上角，向右为X正方向，向下为Y正方向
    MyRGB getPixelColor(unsigned int x,unsigned int y)const;
    //获得索引
    unsigned getPixelIndex(unsigned int x,unsigned int y)const;
    //设置索引
    bool setPixelIndex(unsigned int x,unsigned int y,unsigned int index);
    //获得图像宽度
    int width()const{return imageInfo.imageWidth;}
    //获得图像高度
    int height()const{return imageInfo.imageHeight;}
    //从给定路径载入图像
    bool load(string filePath);
    //将数据清空
    void clearData();
    //设置颜色表
    void setColorTalbe(const vector<MyRGB> &colorTableVec);
    bool writeFile(string fileName);
    //判断是否空
    bool isNullImage()const{return isNull;}
    //判断是否倒立
    bool isInverseImage()const{return isInverse;}
    MyImage& operator =(const MyImage& srcImage);
private:
    BMPHead imageHead;
    BMPInfo imageInfo;
    vector<MyRGB> colorTable;//颜色表
    unsigned int** pixel=nullptr;//像素数据
    bool isNull=true;//用于判断图像是不是空的，空的则不能访问
    //用于判断图像是不是倒立的，说明图像存储是从上到下还是从下到上的，大多数BMP图像时倒立的，高度为正值
    bool isInverse=true;
};

#endif // MYIMAGE_H

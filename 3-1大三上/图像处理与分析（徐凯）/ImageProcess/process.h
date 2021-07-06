#ifndef PROCESS_H
#define PROCESS_H
#include <math.h>
#include <iostream>
#include <QColor>
#include <QImage>
#include <QVector>
#include "myimage.h"
#define OUT_RGB false

using namespace std;

//*****************对图像进行灰度变换的函数集
//图像反转函数，由于只处理8位图像，所以灰度范围是0-255
QImage imageInverse(const QImage &srcImage);
MyImage imageInverse(const MyImage& srcImage);

//处理伽马变换的函数,参数分别是原图像，s=c*r^γ中的γ
QImage gamaProcess(const QImage &srcImage, double gama=1);
MyImage gamaProcess(const MyImage &srcImage,double gama=1);

//*****************进行图像的直方图处理的函数集
//对图像进行直方图均衡化
QImage histoEqalizate(const QImage &srcImage);
MyImage histoEqalizate(const MyImage &srcImage);

//*****************对图像进行平滑操作的函数集
//对图像进行线性滤波，采用高斯模板,后面两个参数是模板大小和高斯函数中的σ
QImage gaussianBlur(const QImage &srcImage,int size,double sigma=0.8);
//生成高斯模板的函数,参数：所得模板权值和，模板大小，高斯函数中的σ
double** gaussMask(int &total,int size,double sigma=0.8);
MyImage gaussianBlur(const MyImage &srcImage,int size,double sigma=0.8);


//采用拉普拉斯算子进行锐化处理
QImage laplaceProcess(const QImage &srcImage);
MyImage laplaceProcess(const MyImage &srcImage);
#endif // PROCESS_H

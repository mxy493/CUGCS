#include "myimage.h"

MyImage::MyImage(string filePath)
{
    fstream imageFile(filePath,ios::binary|ios::in);
    if(!imageFile.is_open())
    {
        cout<<"打开文件失败"<<endl;
        return;
    }
    //首先读取头部信息，14字节
    char headArry[14];
    imageFile.read(headArry,14);
    //读取文件标识符，需要2字节
    imageHead.fileTag=headArry[1]|headArry[0]<<8;
    if(imageHead.fileTag==0x424D)
    {
        cout<<"该文件是BMP文件"<<endl;

    }//1480
    //然后读取文件大小信息，4个字节，为2345
    //imageHead.imageSize=/*(((headArry[5]<<8)|headArry[4])<<8)|*/(headArry[2]|headArry[3]<<8);
    // imageHead.imageSize=headArry[3]*256+headArry[2];
 //    unsigned hB1=headArry[5];
 //    unsigned hB2=headArry[4];
 //    unsigned lB1=(unsigned char)headArry[3];
//    unsigned lB2=(unsigned char)headArry[2];
//    imageHead.imageSize=lB2^lB1<<8;
    imageHead.imageFileSize=(unsigned char)headArry[5]<<24|(unsigned char)headArry[4]<<16|(unsigned char)headArry[3]<<8|(unsigned char)headArry[2];
    //cout<<imageHead.imageSize<<endl;
    //保留字为0，忽略，读取字节偏移量，4个字节
    imageHead.offBit=(unsigned char)headArry[13]<<24|(unsigned char)headArry[12]<<16|(unsigned char)headArry[11]<<8|(unsigned char)headArry[10];

    //然后读取40个字节的信息头文件
    imageFile.seekg(14);
    char infoArry[40];
    imageFile.read(infoArry,40);
    //首先读取4个字节的信息头大小
    imageInfo.infoSize=(unsigned char)infoArry[3]<<24|(unsigned char)infoArry[2]<<16|(unsigned char)infoArry[1]<<8|(unsigned char)infoArry[0];
    //cout<<"infoSize"<<imageInfo.infoSize<<endl;
    //然后4个字节的图像宽度信息
    //imageInfo.imageWidth=(unsigned char)infoArry[7]<<24|(unsigned char)infoArry[6]<<16|(unsigned char)infoArry[5]<<8|(unsigned char)infoArry[4];
    imageInfo.imageWidth=infoArry[7]<<24|infoArry[6]<<16|infoArry[5]<<8|infoArry[4];
    //4个字节的图图像高度信息，并判断图像时正还是倒立的
    imageInfo.imageHeight=infoArry[11]<<24|infoArry[10]<<16|infoArry[9]<<8|infoArry[8];
    if(imageInfo.imageHeight<0)
    {
        isInverse=false;
    }
    //读取两个字节的颜色数据平面，应该为1
    imageInfo.imageColorPlanes=(unsigned char)infoArry[13]<<8|(unsigned char)infoArry[12];
    if(imageInfo.imageColorPlanes!=1)
     {
        return;
    }
    //读取两个字节的比特位数据
    imageInfo.bitCount=(unsigned char)infoArry[15]<<8|(unsigned char)infoArry[14];
    //读取四个字节的图像压缩方式
    imageInfo.imageCompression=(unsigned char)infoArry[19]<<24|(unsigned char)infoArry[18]<<16|(unsigned char)infoArry[17]<<8|(unsigned char)infoArry[16];
    //读取四个字节的图像大小，字节为单位
    imageInfo.rawImageSize=(unsigned char)infoArry[23]<<24|(unsigned char)infoArry[22]<<16|(unsigned char)infoArry[21]<<8|(unsigned char)infoArry[20];
    //读取四字节的水平分辨率大小
    imageInfo.imageXPelsPerMeter=(unsigned char)infoArry[27]<<24|(unsigned char)infoArry[26]<<16|(unsigned char)infoArry[25]<<8|(unsigned char)infoArry[24];
    //四字节的垂直分辨率大小
    imageInfo.imageYPelsPerMeter=(unsigned char)infoArry[31]<<24|(unsigned char)infoArry[30]<<16|(unsigned char)infoArry[29]<<8|(unsigned char)infoArry[28];
    //读取使用调色板索引数
    imageInfo.imageColorTableIndexUsed=(unsigned char )infoArry[35]<<24|(unsigned char)infoArry[34]<<16|(unsigned char)infoArry[33]<<8|(unsigned char)infoArry[32];
    //调色板重要索引数
    imageInfo.imageColorImportant=(unsigned char)infoArry[39]<<24|(unsigned char)infoArry[38]<<16|(unsigned char)infoArry[37]<<8|(unsigned char)infoArry[36];

    //读取颜色表，顺序为蓝绿红）0X00
    imageFile.seekg(54);
    unsigned lenthOfColorTable=0;//颜色表字节长度
    if(imageInfo.bitCount<9)
    {
        //使用了颜色表，进行读取
        //unsigned lenth=2<<(imageInfo.bitCount+2);
        lenthOfColorTable=pow(2,imageInfo.bitCount+2);
        char* colorArry=new char[lenthOfColorTable];
        imageFile.read(colorArry,lenthOfColorTable);
        for(int i=0;i<lenthOfColorTable;i+=4)
        {
            MyRGB rgb;
            rgb.rgbBlue=(unsigned char)colorArry[i];
            rgb.rgbGreen=(unsigned char)colorArry[i+1];
            rgb.rgbRed=(unsigned char)colorArry[i+2];
            colorTable.push_back(rgb);
        }
        delete[] colorArry;
    }
    //然后读取像素数据。
    //首先建立动态数组用于存储，
    pixel=new unsigned*[imageInfo.imageHeight];
    for(int i=0;i<imageInfo.imageWidth;i++)
    {
        pixel[i]=new unsigned[imageInfo.imageHeight]();
    }
    //然后从内存读取
    if(isInverse)
    {
        //按行读取，注意需要4字节对齐
        //首先计算这一行像素所用字节数
        int realBytes=imageInfo.imageWidth*imageInfo.bitCount/8;
        //然后获得内存中应该读取的字节数
        int bytesCount=(realBytes+3)/4*4;
        //建立存储数组
        char *pixelPerLineArry=new char[bytesCount];
        for(int i=0;i<abs(imageInfo.imageHeight);i++)
        {
            //将这一行数据读出
            imageFile.seekg(54+lenthOfColorTable+i*bytesCount);
            imageFile.read(pixelPerLineArry,bytesCount);
            //先只读8位图像
            unsigned int index_i=abs(imageInfo.imageHeight)-i-1;
            for(int j=0;j<realBytes;j++)
            {
                pixel[index_i][j]=(unsigned char)pixelPerLineArry[j];
                //cout<<pixel[index_i][j]<<" ";
            }
            //cout<<endl;

        }
        delete[] pixelPerLineArry;
    }
    isNull=false;
    imageFile.close();
}

MyImage::~MyImage()
{
    //释放申请的动态数组
    for(int i=0;i<imageInfo.imageWidth;i++)
    {
        delete[] pixel[i];
    }
    delete[] pixel;
}

MyImage::MyImage(const MyImage &srcImage)
{
    imageHead=srcImage.imageHead;
    imageInfo=srcImage.imageInfo;
    setColorTalbe(srcImage.colorTable);
    isNull=srcImage.isNullImage();
    isInverse=srcImage.isInverseImage();
    pixel=new unsigned*[imageInfo.imageHeight];
    for(int i=0;i<imageInfo.imageWidth;i++)
    {
        pixel[i]=new unsigned[imageInfo.imageHeight]();
    }
    for(int i=0;i<imageInfo.imageHeight;i++)
    {

        for(int j=0;j<imageInfo.imageHeight;j++)
        {
            pixel[i][j]=srcImage.getPixelIndex(j,i);
        }
    }
}

MyImage::MyImage(unsigned int width, unsigned int height)
{
    //首先申请内存
    pixel=new unsigned*[width];
    for(int i=0;i<width;i++)
    {
        pixel[i]=new unsigned[height];
    }
    //然后修改相应的信息
    //首先添加颜色表
    for(int i=0;i<256;i++)
    {
        colorTable.push_back(MyRGB(i,i,i));
    }
    //修改大小
    imageInfo.imageWidth=width;
    imageInfo.imageHeight=height;
    int realBytes=imageInfo.imageWidth*imageInfo.bitCount/8;
    int bytesCountPerLine=(realBytes+3)/4*4;
    imageInfo.rawImageSize=imageInfo.imageHeight*bytesCountPerLine+2;
    imageHead.offBit=1078;
    imageHead.imageFileSize=imageInfo.rawImageSize+1078;
    isNull=false;
}

 MyRGB MyImage:: getPixelColor(unsigned int x,unsigned int y)const
 {
    if(x<abs(imageInfo.imageWidth)&&y<abs(imageInfo.imageHeight))
    {
        return colorTable[pixel[y][x]];
    }
 }

 unsigned MyImage::getPixelIndex(unsigned int x, unsigned int y)const
 {
     if(x<abs(width())&&y<abs(height()))
     {
         return pixel[y][x];
     }
 }

 bool MyImage::setPixelIndex(unsigned int x, unsigned int y,unsigned int index)
 {
     if(x<abs(width())&&y<abs(height()))
     {
         pixel[y][x]=index;
         return true;
     }
     return false;
 }

 bool MyImage::load(string filePath)
 {
     fstream imageFile(filePath,ios::in|ios::binary);
     if(!imageFile.is_open())
     {
         cout<<"打开文件失败"<<endl;
         return false;
     }
     clearData();
     //首先读取头部信息，14字节
     char headArry[14];
     imageFile.read(headArry,14);
     //读取文件标识符，需要2字节
     imageHead.fileTag=headArry[1]|headArry[0]<<8;
     if(imageHead.fileTag==0x424D)
     {
         cout<<"该文件是BMP文件"<<endl;

     }//1480
     //然后读取文件大小信息，4个字节，为2345
     //imageHead.imageSize=/*(((headArry[5]<<8)|headArry[4])<<8)|*/(headArry[2]|headArry[3]<<8);
     // imageHead.imageSize=headArry[3]*256+headArry[2];
  //    unsigned hB1=headArry[5];
  //    unsigned hB2=headArry[4];
  //    unsigned lB1=(unsigned char)headArry[3];
 //    unsigned lB2=(unsigned char)headArry[2];
 //    imageHead.imageSize=lB2^lB1<<8;
     imageHead.imageFileSize=(unsigned char)headArry[5]<<24|(unsigned char)headArry[4]<<16|(unsigned char)headArry[3]<<8|(unsigned char)headArry[2];
     //cout<<imageHead.imageSize<<endl;
     //保留字为0，忽略，读取字节偏移量，4个字节
     imageHead.offBit=(unsigned char)headArry[13]<<24|(unsigned char)headArry[12]<<16|(unsigned char)headArry[11]<<8|(unsigned char)headArry[10];

     //然后读取40个字节的信息头文件
     imageFile.seekg(14);
     char infoArry[40];
     imageFile.read(infoArry,40);
     //首先读取4个字节的信息头大小
     imageInfo.infoSize=(unsigned char)infoArry[3]<<24|(unsigned char)infoArry[2]<<16|(unsigned char)infoArry[1]<<8|(unsigned char)infoArry[0];
     //cout<<"infoSize"<<imageInfo.infoSize<<endl;
     //然后4个字节的图像宽度信息
     //imageInfo.imageWidth=(unsigned char)infoArry[7]<<24|(unsigned char)infoArry[6]<<16|(unsigned char)infoArry[5]<<8|(unsigned char)infoArry[4];
     imageInfo.imageWidth=infoArry[7]<<24|infoArry[6]<<16|infoArry[5]<<8|infoArry[4];
     //4个字节的图图像高度信息，并判断图像时正还是倒立的
     imageInfo.imageHeight=infoArry[11]<<24|infoArry[10]<<16|infoArry[9]<<8|infoArry[8];
     if(imageInfo.imageHeight<0)
     {
         isInverse=false;
     }
     //读取两个字节的颜色数据平面，应该为1
     imageInfo.imageColorPlanes=(unsigned char)infoArry[13]<<8|(unsigned char)infoArry[12];
     if(imageInfo.imageColorPlanes!=1)
      {
         return false;
     }
     //读取两个字节的比特位数据
     imageInfo.bitCount=(unsigned char)infoArry[15]<<8|(unsigned char)infoArry[14];
     //读取四个字节的图像压缩方式
     imageInfo.imageCompression=(unsigned char)infoArry[19]<<24|(unsigned char)infoArry[18]<<16|(unsigned char)infoArry[17]<<8|(unsigned char)infoArry[16];
     //读取四个字节的图像大小，字节为单位
     imageInfo.rawImageSize=(unsigned char)infoArry[23]<<24|(unsigned char)infoArry[22]<<16|(unsigned char)infoArry[21]<<8|(unsigned char)infoArry[20];
     //读取四字节的水平分辨率大小
     imageInfo.imageXPelsPerMeter=(unsigned char)infoArry[27]<<24|(unsigned char)infoArry[26]<<16|(unsigned char)infoArry[25]<<8|(unsigned char)infoArry[24];
     //四字节的垂直分辨率大小
     imageInfo.imageYPelsPerMeter=(unsigned char)infoArry[31]<<24|(unsigned char)infoArry[30]<<16|(unsigned char)infoArry[29]<<8|(unsigned char)infoArry[28];
     //读取使用调色板索引数
     imageInfo.imageColorTableIndexUsed=(unsigned char)infoArry[35]<<24|(unsigned char)infoArry[34]<<16|(unsigned char)infoArry[33]<<8|(unsigned char)infoArry[32];
     //调色板重要索引数
     imageInfo.imageColorImportant=(unsigned char)infoArry[39]<<24|(unsigned char)infoArry[38]<<16|(unsigned char)infoArry[37]<<8|(unsigned char)infoArry[36];

     //读取颜色表，顺序为蓝绿红）0X00
     imageFile.seekg(54);
     unsigned lenthOfColorTable=0;//颜色表字节长度
     colorTable.clear();
     if(imageInfo.bitCount<9)
     {
         //使用了颜色表，进行读取
         //unsigned lenth=2<<(imageInfo.bitCount+2);
         lenthOfColorTable=pow(2,imageInfo.bitCount+2);
         //char* colorArry=new char[lenthOfColorTable];
         char colorArry[1024];
         imageFile.read(colorArry,lenthOfColorTable);
         for(int i=0;i<lenthOfColorTable;i+=4)
         {
             MyRGB rgb;
             rgb.rgbBlue=(unsigned char)colorArry[i];
             rgb.rgbGreen=(unsigned char)colorArry[i+1];
             rgb.rgbRed=(unsigned char)colorArry[i+2];
             colorTable.push_back(rgb);
         }
         //delete[] colorArry;
     }
     //然后读取像素数据。
     //首先建立动态数组用于存储，
     pixel=new unsigned*[imageInfo.imageHeight];
     for(int i=0;i<imageInfo.imageWidth;i++)
     {
         pixel[i]=new unsigned[imageInfo.imageHeight]();
     }
     //然后从内存读取
     if(isInverse)
     {
         //按行读取，注意需要4字节对齐
         //首先计算这一行像素所用字节数
         int realBytes=imageInfo.imageWidth*imageInfo.bitCount/8;
         //然后获得内存中应该读取的字节数
         int bytesCount=(realBytes+3)/4*4;
         //建立存储数组
         char *pixelPerLineArry=new char[bytesCount];
         for(int i=0;i<abs(imageInfo.imageHeight);i++)
         {
             //将这一行数据读出
             imageFile.seekg(54+lenthOfColorTable+i*bytesCount);
             imageFile.read(pixelPerLineArry,bytesCount);
             //先只读8位图像
             unsigned int index_i=abs(imageInfo.imageHeight)-i-1;
             for(int j=0;j<realBytes;j++)
             {
                 pixel[index_i][j]=(unsigned char)pixelPerLineArry[j];
                 //cout<<pixel[index_i][j]<<" ";
             }
            // cout<<endl;

         }
         delete[] pixelPerLineArry;
     }
     imageFile.close();
     isNull=false;
     return true;
 }

 void MyImage::clearData()
 {
     if(imageInfo.imageWidth!=0)
     {
         for(int i=0;i<imageInfo.imageWidth;i++)
         {
             delete[] pixel[i];
         }
         delete[] pixel;
         isNull=true;
     }

 }
void MyImage::setColorTalbe(const vector<MyRGB> &colorTableVec)
{
    colorTable.clear();
    for(int i=0;i<colorTableVec.size();i++)
    {
        colorTable.push_back(colorTableVec[i]);
    }
}

bool MyImage::writeFile(string fileName)
{
    //fstream outFile(fileName,ios::trunc|ios::out);
    fstream outFile(fileName,ios::out| ios::binary);
    if(!outFile.is_open())
    {
        return false;
    }
    //首先写文件头
    char headArry[14];
    headArry[0]='B';
    headArry[1]='M';
    for(int i=0;i<4;i++)
    {
        headArry[i+2]=(imageHead.imageFileSize>>(i*8))&0xFF;
        headArry[i+6]=0;
        headArry[i+10]=(imageHead.offBit>>(i*8))&0xFF;
    }
    outFile.write(headArry,14);
    //然后写信息头
    char infoArry[40];
    for(int i=0;i<4;i++)
    {
        infoArry[i]=(imageInfo.infoSize>>(i*8))&0xFF;
        //只存储为倒立的图像
        infoArry[i+4]=(abs(imageInfo.imageWidth)>>(i*8))&0xFF;
        infoArry[i+8]=(abs(imageInfo.imageHeight)>>(i*8))&0xFF;
        infoArry[i+16]=(imageInfo.imageCompression>>(i*8))&0xFF;
        infoArry[i+20]=(imageInfo.rawImageSize>>(i*8))&0xFF;
        infoArry[i+24]=(imageInfo.imageXPelsPerMeter>>(i*8))&0xFF;
        infoArry[i+28]=(imageInfo.imageYPelsPerMeter>>(i*8))&0xFF;
        infoArry[i+32]=(imageInfo.imageColorTableIndexUsed>>(i*8))&0xFF;
        infoArry[i+36]=(imageInfo.imageColorImportant>>(i*8))&0xFF;
    }
    for(int i=0;i<2;i++)
    {
        infoArry[i+12]=(imageInfo.imageColorPlanes>>(i*8))&0xFF;
        infoArry[i+14]=(imageInfo.bitCount>>(i*8))&0xFF;
    }
    //outFile.seekp(outFile.tellp());
    outFile.write(infoArry,40);
    //调色板数据
    unsigned lenthOfColorTable=0;//颜色表字节长度
    if(imageInfo.bitCount<9)
    {
        //使用了颜色表
        //unsigned lenth=2<<(imageInfo.bitCount+2);
        lenthOfColorTable=pow(2,imageInfo.bitCount+2);
        //char* colorArry=new char[lenthOfColorTable];
        char colorArry[1024];
        //for(int i=0;i<colorTable.size();i++)
        for(int i=0;i<256;i++)
        {
            colorArry[i*4]=colorTable[i].rgbBlue&0xff;
            colorArry[i*4+1]=colorTable[i].rgbGreen&0xff;
            colorArry[i*4+2]=colorTable[i].rgbRed&0xff;
            colorArry[i*4+3]=0b00000000;
//            if(i==10)
//            {
//                colorArry[0]=0x0A;
//                colorArry[1]=0x0A;
//                colorArry[2]=0x0A;
//            }
//            else
//            {
//                colorArry[0]=colorTable[i].rgbBlue;
//                colorArry[1]=colorTable[i].rgbGreen;
//                colorArry[2]=colorTable[i].rgbRed;
//            }

//            colorArry[3]=0b00000000;
           // outFile.write(colorArry,4);
//              colorArry[0]=i;
//              outFile.write(colorArry,1);
//              outFile.write(colorArry,1);
//              outFile.write(colorArry,1);
//              outFile.write("0",1);
        }
        outFile.write(colorArry,lenthOfColorTable);
        //delete[] colorArry;
    }
    //处理位图数据区
//    outFile.close();
//    return true;
    //按行读取，注意需要4字节对齐
    //首先计算这一行像素所用字节数
    int realBytes=imageInfo.imageWidth*imageInfo.bitCount/8;
    //然后获得内存中应该读取的字节数
    int bytesCount=(realBytes+3)/4*4;
    //建立存储数组
    char *pixelPerLineArry=new char[bytesCount];
    for(int i=0;i<abs(imageInfo.imageHeight);i++)
    {
        //将这一行数据读出
        // imageFile.seekg(54+lenthOfColorTable+i*bytesCount);
        // imageFile.read(pixelPerLineArry,bytesCount);
        //先只读8位图像
        unsigned int index_i=abs(imageInfo.imageHeight)-i-1;
        int temp;
        for(int j=0;j<realBytes;j++)
        {
            //pixel[index_i][j]=(unsigned char)pixelPerLineArry[j];
            pixelPerLineArry[j]=pixel[index_i][j]&0xff;
            temp=pixel[index_i][j];
        }
        for(int j=realBytes;j<bytesCount;j++)
        {
            pixelPerLineArry[j]=0;
        }
        outFile.write(pixelPerLineArry,bytesCount);
        //cout<<endl;

    }
    delete[] pixelPerLineArry;
    //补两个字节的空白
    char endArry[2]={0b00000000,0b00000000};
    outFile.write(endArry,2);
    outFile.close();
    return true;

}

MyImage& MyImage::operator =(const MyImage& srcImage)
{
    this->imageHead=srcImage.imageHead;
    this->imageInfo=srcImage.imageInfo;
    this->setColorTalbe(srcImage.colorTable);
    this->isNull=srcImage.isNullImage();
    this->isInverse=srcImage.isInverseImage();
    this->pixel=new unsigned*[imageInfo.imageHeight];
    for(int i=0;i<imageInfo.imageWidth;i++)
    {
        this->pixel[i]=new unsigned[imageInfo.imageHeight]();
    }
    for(int i=0;i<imageInfo.imageHeight;i++)
    {

        for(int j=0;j<imageInfo.imageHeight;j++)
        {
            this->pixel[i][j]=srcImage.getPixelIndex(j,i);
        }
    }
    return *this;
}

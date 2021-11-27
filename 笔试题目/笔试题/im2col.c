#include <bits/stdc++.h>
using namespace std;

void im2col_cpu(float* data_im,int channels,int height,
  int width,int ksize,
  int stride,int pad,float *data_cal);
/*
 *从输入的多通道数组im中获取指定的行、列、通道数处的元素值
 *im-输入，所有数据都存成一个一维数据，例如对于3通道而言，每一个通道按行存储，三通道依次再合并成一行
 *height 每一通道的高度（输入图像的真正高度，补0之前）
 *width
 *channels 输入im的通道数，比如彩色通道为3通道，之后每一次卷积的输入的通道数等于上一层卷积核的个数
 *row 要提取的元素所在的行(二维图像补0之后的行数)
 *col
 *channel 要提取的元素所在的通道
 *pad 图像左右上下各补0的长度(四个方向补0的长度一样)
 *@return float类型数据，为im中channel通道，row-pad行，col-pad列处的元素值，高，宽；
 而row与col则是补0之后，元素所在的行列，因此要准确获取im的元素值，首先要减去pad以获取真实的行列数
 */
float im2col_get_pixel(float *im,int height,int width,int channels,int row,int col,
                         int channel,int pad)
{
   row-=pad;
   col-=pad;
   if(col<0||col<0||row>=height||col>=width) return 0;
   return im[col+width*(row+height*channel)];
}

/*将图片转为便于计算的数组格式，这是直接从caffe移植过来的
 *data_im 输入图像
 *channels 输入图像的通道数
 *ksize 卷积核尺寸
 *stride 步幅
 * pad 补0的个数
 * data_col 相当于输出，为进行格式化重排后的输入图像数据
 */
 void im2col_cpu(float*data_im,int channels,int height,int width,
                 int ksize,int stride,int pad,float* data_col)
 {
   int c,h,w;
   int height_col = (height+2*pad-ksize)/stride + 1;
   int width_col = (width+2*pad-ksize)/stride + 1;
   int channels_col = channels*ksize*ksize;
   for(c=0;c<channels_col;c++){
     int w_offset = c%ksize;
     int h_offset = (c/ksize)%ksize;
     int c_im = c/ksize/ksize;
     for(h=0;h<height_col;h++){
       for(w=0;w<width_col;w++){
         int im_row = h_offset+h*stride;
         int im_col = w_offset+w*stride;
         int col_index = (c*height_col+h)*width_col+w;
         data_col[col_index]=im2col_get_pixel(data_im,height,width,channels,im_row,im_col,c_im,pad);
       }
     }
   }
 }

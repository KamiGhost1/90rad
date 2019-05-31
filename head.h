#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef _bmp_str_
#define _bmp_str_

#pragma pack(push,1)
typedef struct {
   unsigned short bfType; 
   unsigned int   bfSize; 
   unsigned short    bfReserved1; 
   unsigned short    bfReserved2; 
   unsigned int   bfOffBits; 
}BMPFILEHEADER;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct BMP {
   unsigned int  bi_Size; 
   unsigned int   bi_Width; 
   unsigned int   bi_Height; 
   unsigned short   bi_Planes; 
   unsigned short   bi_BitCount; 
   unsigned int  bi_Compression; 
   unsigned int  bi_SizeImage; 
   int   bi_X; 
   int   bi_Y; 
   unsigned int  bi_ClrUsed; 
   unsigned int  bi_ClrImportant; 
}BMPINFOHEADER;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct COLOR_pix {
    char R,G,B;
}COLOR;
#pragma pack(pop)
#endif

FILE *FOpen(int C, char **V);
void IRead(FILE *f, COLOR **RGB, int height, int width);
void IWrite(FILE *f, COLOR **RGB, int height, int width);
void rotate(COLOR **RGB, int height, int width);
void zerkalo(COLOR **RGB, int height, int width);
COLOR **createColor(int height, int width);
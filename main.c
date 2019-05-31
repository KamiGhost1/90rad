#include "head.h"
#define BMP 19778

int main(int C, char **V){
    FILE *input = FOpen(C, V);
    if(!input) return 2;
    BMPFILEHEADER fh;
    BMPINFOHEADER ih;
    COLOR **image;
    fread(&fh, sizeof(BMPFILEHEADER),1,input);
    if(fh.bfType != BMP){
        printf("file is not BMP!\n");
        return 3;
    }
    fread(&ih, sizeof(BMPINFOHEADER),1,input);
    if (ih.bi_Width != ih.bi_Height){
        printf("Error! hight not equal width!\n");
        printf("%d\n%d\n",ih.bi_Height,ih.bi_Width);
        return 5;
    }
    fseek(input,fh.bfOffBits,SEEK_SET);
    image=createColor(ih.bi_Height,ih.bi_Width);
    IRead(input, image, ih.bi_Height, ih.bi_Width);
    rotate(image, ih.bi_Height,ih.bi_Width);
    fseek(input,fh.bfOffBits,SEEK_SET);
    IWrite(input, image, ih.bi_Height, ih.bi_Width);
    fclose(input);
    free(image);
    printf("image rotated!\n");
    return 0;
}
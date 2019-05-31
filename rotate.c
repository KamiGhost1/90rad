#include "head.h"
FILE *FOpen(int C, char **V){
    if (C!=3){
        printf("incorrect command. example: test.exe -i file.bmp\n");
        return NULL;
    }
    if(C==3){
        if(!strcmp(V[1], "-i")){
            FILE *input = fopen(V[2],"rb+");
            if (input == NULL){
                printf("file not found!\n");
                return NULL;
            }
            return input;
        }
        printf("incorrect command. example: test.exe -i file.bmp\n");
        return NULL;
    }
}


void IRead(FILE *f, COLOR **RGB, int height, int width){
    int i,j;
    for (i = 0; i<height; i++){
        for (j = 0; j<width; j++){
            fread(&RGB[i][j], sizeof(COLOR),1,f);
        }
    }
}


void IWrite(FILE *f, COLOR **RGB, int height, int width){
    int i,j;
    for (i = 0; i<height; i++){
        for (j = 0; j<width; j++){
            fwrite(&RGB[i][j], sizeof(COLOR),1,f);
        }
    }
}


/*void zerkalo(COLOR **RGB, int height, int width){
    int i,j,p;
    COLOR tmp;
    for (i=0;i<height;i++){
        p=0;
        for (j=0;j<width/2;j++){
            tmp = RGB[i][j];
            RGB[i][j]=RGB[i][height-p];
            RGB[i][height-p]=tmp;
            p++;
        }
    }
}*/
void rotate(COLOR **RGB, int height, int width){
    int i,j;
    COLOR **tmp;
    tmp=createColor(height, width);
    for (i=0;i<height;i++){
        for (j=0;j<width;j++){
            tmp[i][j]=RGB[i][j];
        }
    }
    for (i=0;i<height;i++){
        for (j=0;j<width;j++){
            RGB[j][height-i-1]=tmp[i][j];
        }
    }
    free(tmp);
}

COLOR **createColor(int height, int width){
    int i;
    COLOR **rgb;
    rgb = (COLOR**)malloc(height * sizeof(COLOR*));
	for ( i = 0; i < height; i++) {
		rgb[i] = (COLOR*)malloc(width * sizeof(COLOR));
	}
    return rgb;
}
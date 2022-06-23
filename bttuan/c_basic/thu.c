#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct sinhvien
{
    char hoten[20];
    char mssv[10];
    char email[50];
}SINHVIEN;
int main()
{
    SINHVIEN *SV;
    FILE *fptr;
    fptr=fopen("file.txt","r");
    fscanf(fptr,"%s",&SV.hoten);
    fscanf(fptr,"%s",&SV.mssv);
    fscanf(fptr,"%s",&SV.email);
    printf( "%s %s %s",SV.hoten, SV.mssv, SV.email);
    fclose(fptr);
}
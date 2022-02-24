#include<stdio.h>
#include<stdlib.h>

int main() {
    int num, *pathNum;

    num = 10;
    pathNum = &num;

    printf("\nnumero: %d", num);
    printf("\ndirecion de memoria: %p", &num);

    printf("\nnumero %d", *pathNum);
    printf("\ndirecion de memoria %p", &pathNum);

    return 0;
}
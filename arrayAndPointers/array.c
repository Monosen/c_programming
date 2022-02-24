#include<stdio.h>
#include<stdlib.h>

int main(){
    int nums[] = {1,2,3,4,5};
    int *pathNums;

    // pathNums = &nums[0];
    pathNums = nums;

    for (int i = 0; i < 5; i++)
    {
        printf("\narray number %d index [%d]", *pathNums++, i);
    }

    return 0;
}
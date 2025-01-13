#include <stdio.h>

int main (){
    int arr [5] = {10,20,30,40,50};
    int *ptr = arr;

    printf("arr: %p\n",arr);
    printf("arr: %d\n",*arr);
    printf("ptr: %p\n",ptr);
    printf("ptr: %d\n",*ptr);

    return 0;
}
#include <stdio.h>

int main(){
    int num = 10;
    void* ptr = &num;
    
    printf("num value by ptr: %d\n",*(int*)ptr);
    return 0;
}
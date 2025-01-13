#include <stdio.h>

int main(){
    char char_arr[3] = {'A','B','C'};
    int int_arr[3] = {10,20,30};

    printf("char_arr[0]: %c\n",*char_arr);
    printf("char_arr[1]: %c\n",*(char_arr +1));
    
    printf("int_arr[0]: %d\n",*int_arr);
    printf("int_arr[1]: %d\n",*(int_arr+1));

    return 0;
}
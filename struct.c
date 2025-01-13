#include <stdio.h>

struct Person
{
    char name[30];
    int age;
};


int main(){
    struct Person person1 = {"John",25};

    printf("Name: %s\n",person1.name);
    printf("Name: %d\n",person1.age);
    return 0;
}
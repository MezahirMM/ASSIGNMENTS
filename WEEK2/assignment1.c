#include <stdio.h>

void int_swap(int*, int*);

int main(){

int a, b;

a = 50;
b = 100;

printf("Before changing a=%d, b=%d\n",a,b);

int_swap(&a,&b);

printf("After changing a=%d, b=%d",a,b);

return 0;
}

void int_swap(int *val1, int *val2){

int num;

num = *val1;
*val1 = *val2;
*val2 = num;
}

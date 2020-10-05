#include "stdio.h"

void swapStrings(char **destination, char **source);           

int main(){
    char *str1 = "The Neighbourhood";
    char *str2 = "Arctic Monkeys";
    
    printf("Before:\n");
    printf("str1: %s, str2: %s\n",str1,str2);
    swapStrings(&str1,&str2);
    printf("After:\n");
    printf("str1: %s, str2: %s\n",str1,str2);

    return 0;
}

void swapStrings(char **destination, char **source){
    // swaps contents of two strings
    char *temp;
    
    temp = *destination;
    *destination = *source;
    *source = temp;
}


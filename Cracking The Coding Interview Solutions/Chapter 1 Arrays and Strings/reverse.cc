/*
Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)

by    : Varun Thakur
Dated : 25-02-2018
*/
#include<stdio.h>

void reverse(char *str);

int main(void){

    char str[] = "test_string";
    reverse(str);
    printf("%s",str);
   
   return 0;
}

void reverse(char *str){
    char *end = str;
    char tmp;
    if(str){
        
        while(*end)
            end++;
        
        --end;
        
        while(str<end){
            tmp = *str;
            *str++ = *end; // *str = *end; str++;
            *end-- = tmp;  // *end = tmp; end--;
        }
    }
}
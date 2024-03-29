#include <stdio.h>
int my_strlen(char * p){
    int num = 0;
    while(*p++ && ++num){
        ;
    }
    return num;
}
int main(){
    char arr1[] = "smzy";
    int num = my_strlen(arr1);
    printf("%d\n",num);
}
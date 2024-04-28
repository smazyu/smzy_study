//
// Created by 20212 on 2024/4/29.
//

#include <stdio.h>
struct S{
    char arr[10];
    int num;
    float sc;
};
int main(){
    struct S s= {"abcdef",10,5.5f};
//"../C_study/day_37/txt.data"
    FILE*pf = fopen("../C_study/day_37/txt.data","r");
    if(pf == NULL){
        perror("fopen");
        return 1;
    }
//    fprintf(pf,"%s %d %f",s.arr,s.num,s.sc);
    fscanf(pf,"%s %d %f",s.arr,&(s.num),&(s.sc));

    //program output file writing
    fclose(pf);
    pf = NULL;
    return 0;
}
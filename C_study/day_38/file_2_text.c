#include <stdio.h>

//
// Created by 20212 on 2024/4/29.
//
//struct S{
//    char arr[10];
//    int age;
//    float f;
//};
//int main(){
//    struct S s = {"hello",10,5.5f};
//    struct S tmp = {0};
//    char buf[100] = {0};
//    //sprintf convert a formatted data into a string
//    sprintf(buf,"%s %d %f",s.arr,s.age,s.f);
//    sscanf(buf,"%s %d %f",tmp.arr,&(tmp.age),&(tmp.f));
//    printf("%s\n",tmp.arr);
//}
////allocated
//int main(){
//    FILE* pf = fopen("../C_study/day_37/txt.data","r");
//    if(pf == NULL){
//        perror(fopen);
//        return 1;
//    }
//    //read file
//    int st = fgetc(pf);
//    printf("%c\n",st);
//    fseek(pf,-1,SEEK_CUR);
//    //SEEK_CUR current location
//    st = fgetc(pf);
//    printf("%c\n",st);
//    st = fgetc(pf);
//    //Let the file pointer point to the starting position
//    //remind
//    printf("%c\n",st);
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}
int main(){
    int a = 10000;
    FILE* pf = fopen("../C_study/day_37/txt.data","wb");
}
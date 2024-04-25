#include "contact.h"
void InitContact(Contact *pc){
    pc -> sz = 0;
    //memset() 内存设置
    //data是数组名，指向首元素空间的地址
    memset(pc -> data,0,sizeof(pc -> data));
}
void AddContact(Contact *pc){
    if(pc -> sz == MAX){
        printf("通讯录已满，无法添加");
        return;
    }
    //增加一个人的信息
    printf("请输入名字>");
    scanf("%s",pc -> data[pc->sz].name);//name是一个数组，所以不需要取地址
    printf("请输入年龄>");
    scanf("%d",&(pc -> data[pc -> sz].age));
    printf("请输入性别>");
    scanf("%s",pc -> data[pc->sz].sex);
    printf("请输入电话>");
    scanf("%s",pc -> data[pc->sz].tele);
    printf("请输入地址>");
    scanf("%s",pc -> data[pc->sz].addr);
    pc -> sz ++;
    printf("添加成功\n");
}
void PrintContact(const Contact *pc){
    int i = 0;
    //打印标题
    printf("%10s\t%10s\t%10s\t%12s\t%10s\t\n","名字","年龄","性别","电话","地址");
    for(i = 0;i < pc -> sz;i++){
        printf("%10s\t%10d\t%10s\t%12s\t%10s\t\n",
               pc ->data[i].name,
               pc ->data[i].age,
               pc -> data[i].sex,
               pc -> data[i].tele,
               pc -> data[i].addr
        );
    }
}
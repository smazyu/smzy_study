//
// Created by 20212 on 2024/5/24.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 100
#define MAX_BOOKS 100

typedef struct Book {
    char num[14];
    char name[NAME_LEN];
    float price;
    struct Book* next;
} Book;

typedef struct {
    Book* head;
    int size;
} BookList;

void initBookList(BookList* list) {
    list->head = NULL;
    list->size = 0;
}

void insertBook(BookList* list, const char* num, const char* name, float price) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (!newBook) {
        printf("内存分配失败，无法插入新书。\n");
        return;
    }
    strncpy(newBook->num, num, 14);
    strncpy(newBook->name, name, NAME_LEN);
    newBook->price = price;
    newBook->next = list->head;
    list->head = newBook;
    list->size++;
    printf("Book插入成功。\n");
}

void deleteBook(BookList* list, const char* num) {
    Book* current = list->head;
    Book* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->num, num) == 0) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            list->size--;
            printf("Book 通过num %s 删除成功。\n", num);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("没有书本被找到。\n");
}

void findBookByNum(BookList* list, const char* num) {
    Book* current = list->head;
    while (current != NULL) {
        if (strcmp(current->num, num) == 0) {
            printf("通过num找到book: num: %s, name: %s, price: %.2f\n",
                   current->num, current->name, current->price);
            return;
        }
        current = current->next;
    }
    printf("没有通过num找到.\n");
}

void printBooks(BookList* list) {
    Book* current = list->head;
    while (current != NULL) {
        printf("num: %s, name: %s, price: %.2f\n", current->num, current->name, current->price);
        current = current->next;
    }
}

void readBooksFromFile(BookList* list, const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        printf("无法打开文件 %s。\n", filepath);
        return;
    }
    char num[14], name[NAME_LEN];
    float price;
    while (fscanf(file, "%s %s %f", num, name, &price) == 3) {
        insertBook(list, num, name, price);
    }
    fclose(file);
}

void inputBookInfo(BookList* list) {
    char num[14], name[NAME_LEN];
    float price;
    printf("请输入图书编号: ");
    scanf("%s", num);
    printf("请输入图书名称: ");
    scanf("%s", name);
    printf("请输入图书价格: ");
    scanf("%f", &price);
    insertBook(list, num, name, price);
}

void getValue(BookList* list) {
    char num[14];
    printf("请输入要查询的图书编号: ");
    scanf("%s", num);
    findBookByNum(list, num);
}

void insert(BookList* list) {
    inputBookInfo(list);
}

void delete(BookList* list) {
    char num[14];
    printf("请输入要删除的图书编号: ");
    scanf("%s", num);
    deleteBook(list, num);
}

void output(BookList* list) {
    printf("打印图书信息：\n");
    printBooks(list);
}

void menu() {
    printf("************************************\n");
    printf("*******  1.插入图书          *********\n");
    printf("*******  2.删除图书          *********\n");
    printf("*******  3.查找图书          *********\n");
    printf("*******  4.输出图书信息      *********\n");
    printf("*******  5.从文件导入图书    *********\n");
    printf("*******  0.退出              *********\n");
    printf("************************************\n");
}

void function(BookList* list) {
    int input = 0;
    do {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch(input) {
            case 1:
                printf("插入图书\n");
                insert(list);
                break;
            case 2:
                printf("删除图书\n");
                delete(list);
                break;
            case 3:
                printf("查找图书\n");
                getValue(list);
                break;
            case 4:
                printf("输出图书信息\n");
                output(list);
                break;
            case 5:
                printf("从文件导入图书\n");
                readBooksFromFile(list, "E:\\GitHub\\smzy_study\\homework\\2\\book.txt");
                break;
            case 0:
                printf("退出\n");
                break;
            default:
                printf("输入错误，请重试\n");
                break;
        }
    } while(input != 0);
}

int main() {
    BookList list;
    initBookList(&list);
    function(&list);
    return 0;
}

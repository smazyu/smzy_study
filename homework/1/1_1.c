#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define NAME_LEN 100

typedef struct {
    char num[14];
    char name[NAME_LEN];
    float price;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int size;
} BookList;

void initBookList(BookList* list) {
    list->size = 0;
}

void readBooksFromFile(BookList* list, const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        printf("无法打开文件 %s。\n", filepath);
        return;
    }
    while (fscanf(file, "%s\t%[^\t]\t%f", list->books[list->size].num, list->books[list->size].name, &list->books[list->size].price) != EOF) {
        if (++list->size >= MAX_BOOKS) {
            printf("书籍列表已满，无法加载更多书籍。\n");
            break;
        }
    }
    fclose(file);
}

void insertBook(BookList* list, const char* num, const char* name, float price) {
    if (list->size >= MAX_BOOKS) {
        printf("书籍列表已满，无法插入新书。\n");
        return;
    }
    strncpy(list->books[list->size].num, num, sizeof(list->books[list->size].num) - 1);
    strncpy(list->books[list->size].name, name, sizeof(list->books[list->size].name) - 1);
    list->books[list->size].price = price;
    list->size++;
    printf("Book插入成功。\n");
}

void deleteBook(BookList* list, const char* num) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->books[i].num, num) == 0) {
            for (int j = i; j < list->size - 1; j++) {
                list->books[j] = list->books[j + 1];
            }
            list->size--;
            printf("Book 通过num %s 删除成功。\n", num);
            return;
        }
    }
    printf("没有书本被找到。\n");
}

void findBookByNum(BookList* list, const char* num) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->books[i].num, num) == 0) {
            printf("通过num找到book: num: %s, name: %s, price: %.2f\n", list->books[i].num, list->books[i].name, list->books[i].price);
            return;
        }
    }
    printf("没有通过num找到.\n");
}

void getBook(BookList* list, const char* input_str) {
    char num[14] = "", name[NAME_LEN] = "";
    float price = 0.0f;
    int result = sscanf(input_str, "%s %s %f", num, name, &price);

    for (int i = 0; i < list->size; i++) {
        int num_match = (result > 0) && strcmp(list->books[i].num, num) == 0;
        int name_match = (result > 1) && strcmp(list->books[i].name, name) == 0;
        int price_match = (result > 2) && (list->books[i].price == price);

        if (num_match || name_match || price_match) {
            printf("找到 book: num: %s, name: %s, price: %.2f\n", list->books[i].num, list->books[i].name, list->books[i].price);
            return;
        }
    }
    printf("没有发现书本。\n");
}

void printBooks(const BookList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("num: %s, name: %s, price: %.2f\n", list->books[i].num, list->books[i].name, list->books[i].price);
    }
}

void menu() {
    printf("************************************\n");
    printf("*******  1.从文件读出图书信息  *********\n");
    printf("*******  2.插入图书          *********\n");
    printf("*******  3.通过num删除图书    *********\n");
    printf("*******  4.通过num找到图书    *********\n");
    printf("*******  5.打印图书          *********\n");
    printf("*******  0.退出              *********\n");
    printf("************************************\n");
}

void handleUserInput(BookList* list) {
    int input;
    do {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        getchar();  // consume the newline character
        char num[14], name[NAME_LEN];
        float price;
        char input_str[256];
        switch (input) {
            case 1: {
                printf("从文件读出图书信息\n");
                char filepath[256];
                printf("请输入文件路径:>");
                scanf("%s", filepath);
                readBooksFromFile(list, filepath);
                break;
            }
            case 2:
                printf("请输入num:>");
                scanf("%s", num);
                printf("请输入name:>");
                scanf(" %[^\n]", name);  // allow spaces in name
                printf("请输入price:>");
                scanf("%f", &price);
                insertBook(list, num, name, price);
                break;
            case 3:
                printf("请输入num:>");
                scanf("%s", num);
                deleteBook(list, num);
                break;
            case 4:
                printf("请输入num:>");
                scanf("%s", num);
                findBookByNum(list, num);
                break;
            case 5:
                printBooks(list);
                break;
            case 0:
                printf("退出\n");
                break;
            default:
                printf("输入错误，请重试\n");
                break;
        }
    } while (input != 0);
}

int main() {
    BookList list;
    initBookList(&list);
    handleUserInput(&list);
    return 0;
}

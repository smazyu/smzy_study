#include <stdio.h>
#include <string.h>

int main() {
    char str[10];
    str = "abc\0";
    
    printf("str: %s\n", str); // 输出: str: abc

    return 0;
}

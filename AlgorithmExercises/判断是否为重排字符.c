#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool CheckPermutation(const char* s1, const char* s2) {
    if (strlen(s1) != strlen(s2)) {
        return false;
    }
    int count1[256] = {0};
    int count2[256] = {0};
    for (int i = 0; s1[i] != '\0'; i++) {
        count1[(unsigned char)s1[i]]++;
    }
    for (int i = 0; s2[i] != '\0'; i++) {
        count2[(unsigned char)s2[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}
//
// Created by 20212 on 24-9-25.
//
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    void characterOccurrences(int chr,int *char_occur){
        if(chr >= 'a' && chr <= 'z'){
            char_occur[chr - 'a'] ++;
        }
    }
    int firstUniqChar(string s) {
        int char_occur[26] = {0};
        for(auto c: s) {
            characterOccurrences(c,char_occur);
        }
        for(int i = 0;i < s.size();i++) {
            if(char_occur[s[i] - 'a'] == 1) {
                return i;
            }else {
                return -1;
            }
        }
    }
};
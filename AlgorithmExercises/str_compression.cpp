class Solution {
public:
    string compressString(string S) {
        string comp_str;
        int r = 0, l = 0, n = S.size();
        while (l < n) {
            while(r < n && S[l] == S[r]){
                r++;}
            comp_str += S[l] + to_string(r - l);
            l = r;
        }
        // return S.size() > comp_str.size() ? comp_str : S;
        return comp_str.size() >= S.size() ? S : comp_str;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int maxlen = 0;

        for(int i = 0;i < s.size();i++){
            // 回文串為奇數(擇一發生)
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > maxlen){
                    maxlen = r - l + 1;
                    res = s.substr(l, maxlen);
                }
                l --;
                r ++;
            }

            // 回文串為偶數(擇一發生)
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > maxlen){
                    maxlen = r - l + 1;
                    res = s.substr(l, maxlen);
                }
                l --;
                r ++;
            }

        }
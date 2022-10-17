class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l<r){
            while(l < r && isalnum(s[l]) == 0){
                l += 1;
            }
            while(l < r && isalnum(s[r]) == 0){
                r -= 1;
            }
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l += 1;
            r -= 1;
        }
        return true;
    }

    // char check(char s){
    //     int k = s;//k為char s的10進位
    //     //0~9，A~Z，a~z
    //     if ((k >= 48 && k <= 57) or (k >= 65 && k <= 90) or (k >= 97 && k <= 122)){
    //         return s;
    //     }
    // }
};
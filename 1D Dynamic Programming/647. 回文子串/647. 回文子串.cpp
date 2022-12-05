class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i = 0;i < s.size(); i++){
            // 奇
            res += check(s, i, i);
            // 偶
            res += check(s, i, i + 1);
        }

        return res;
    }

private:
    int check(string s, int l, int r){
        int count = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            count++;
            l--;
            r++;
        }

        return count;
    }

};

// 參考最长回文子串優化
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        return count(s, res);
    }

private:
    int count(string s, int cnt) {

        for(int i = 0; i < s.size(); i++){

            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                cnt++;
                l--;
                r++;
            }

            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                cnt++;
                l--;
                r++;
            }
        }
        return cnt;
    }

};
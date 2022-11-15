class Solution {
public:
    string minWindow(string s, string t) {
        // 求最小window，左while，右for，透過左右指針與s.substr(l_p,r_p)取解
        unordered_map<char, int> debt;

        for(int i = 0; i < t.length(); i++){
            debt[t[i]]++;
        }

        // 計數器，若debt[] = 0時+1，若counter = temp時可能為解
        int counter = 0;
        int temp = debt.size();

        // 左指針
        int l_p = 0;

        // 解答
        int min_len = INT_MAX;
        string min_s = "";

        // 右指針
        for(int r_p = 0; r_p < s.length(); r_p++){
            char ch = s[r_p];
            r_p++;
            // 若ch非我們在意的字元，skip
            for (int i = 0; i < debt.size(); i++) {
                if(debt.find(ch) == debt.end()){
                    continue;
                }
            }
            // ch為我們在意的字元
            debt[ch]--;
            if(debt[ch] == 0){
                counter++;
            }
            // 可能為解，移動左指針
            while(counter == debt.size() && l_p <= r_p){
                cout<<l_p<<r_p<<endl;
                // 更新解答
                int cur_len = r_p - l_p;
                if(cur_len < min_len){
                    min_len =  cur_len;
                    min_s = s.substr(l_p, min_len);
                    cout<<min_s<<endl;
                }

                char ch = s[l_p];
                l_p++;
                // 若ch非我們在意的字元，skip
                for (int i = 0; i < debt.size(); i++) {
                    if(debt.find(ch) == debt.end()){
                        continue;
                    }
                }
                // ch為我們在意的字元
                debt[ch]++;
                if(debt[ch] == 1){
                    counter--;
                }            
            }

        }

        if(cur_len == INT_MAX){
            return "";
        }
        return min_s;
    }
};
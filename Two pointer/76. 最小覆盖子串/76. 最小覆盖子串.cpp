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

        for(int r_p = 0; r_p < s.length(); r_p++){
            char ch = s[r_p];
            cout<< ch << endl;



        }




        return "aaa";
    }
};
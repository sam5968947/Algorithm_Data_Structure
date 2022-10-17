class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        vector<int> temp(26);
        //長度相同
        for(int i = 0; i < s.size(); i++){
            temp[int(s[i])-97] ++;
            temp[int(t[i])-97] --;
        }
        for(int j = 0; j < 26; j++){
            if(temp[j] != 0){
                return false;
            }
        }
        return true;
    }
};
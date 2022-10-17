class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string , vector<string>> map;
        for(int i = 0; i < strs.size(); i++){
            string k = getkey(strs[i]);
            map[k].push_back(strs[i]);
        }

        for (auto it = map.begin(); it != map.end(); it++) {
            res.push_back((*it).second);
        }        
    return res;
    }

    string getkey(string str){
        vector<int> temp(26);
        string key = "";
        for(int i = 0; i < str.size(); i++){
            //char與char以10進位相減
            temp[str[i] - 'a']++;
        }
        //依序排列
        for(int i = 0; i < temp.size(); i++){
            key += to_string(temp[i] + 'a');
        }
        return key;
    }
};
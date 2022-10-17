class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;//數字 : 次數
        vector<vector<int>> cnt(nums.size()+1);//k[次數] = [數字...]，不存在0次
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
                m[nums[i]]++;
        }

        for(auto it = m.begin(); it != m.end(); it++) {
            // cout << "數字: " << it->first << ", 次數: " << it->second << "\n";
            cnt[it->second].push_back(it->first);
        }

        for(int j = cnt.size()-1; j > 0; j--){
            for(int k2 = 0; k2 < cnt[j].size(); k2++){
                res.push_back(cnt[j][k2]);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if (dic.find(nums[i]) != dic.end()){
                res.push_back(dic[nums[i]]);
                res.push_back(i);
                break;
            }
            int diff = target- nums[i];
            dic[diff] = i;
        }
        return res;
    }
};
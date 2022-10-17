class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        for(int i = 0; i < nums.size(); i++){
            //找到重複
            if(myset.find(nums[i]) != myset.end()){
                return true;
            }
            myset.insert(nums[i]);
        }
        return false;
    }
};
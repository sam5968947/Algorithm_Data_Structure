class Solution {

public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> range1(nums.begin(), nums.end()-1);
        vector<int> range2(nums.begin() + 1, nums.end());

        return max(helper(range1), helper(range2));
    }

private:
    int helper(vector<int> nums){
        int pre = 0, cur = 0;
        int next;

        for(int i = 0; i < nums.size(); i++){
            next = max(nums[i] + pre, cur);
            pre = cur;
            cur = next;
        }
        return cur;
    }

};
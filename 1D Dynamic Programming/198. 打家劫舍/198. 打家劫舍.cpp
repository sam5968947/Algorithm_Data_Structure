class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        if(l == 0) return 0;
        if(l == 1) return nums[0];

        vector<int> rob(l,0);
        rob[0] = nums[0];
        rob[1] = max(nums[0], nums[1]);

        for(int i = 2; i < l; i++){
            rob[i] = max(rob[i-1], rob[i-2] + nums[i]);
        }

        return rob[l-1];
    }
};

// 優化版
class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0;
        int cur = 0;
        int next;

        for(int i = 0; i < nums.size(); i++){
            next = max(nums[i] + pre, cur);
            pre = cur;
            cur = next;
        }

        return cur;
    }
};
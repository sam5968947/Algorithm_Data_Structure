// 方法1 : 複製一組由0~len(nums)的list，並與原list相減
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();//最後一個數字
        for(int i = 0; i < nums.size();i++){
            res += (i - nums[i]);
        }
        return res;
    }
};

// 位運算XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for(int i = 0; i < nums.size(); i++){
            res ^= i^ (nums[i]);
        }

        return res;
    }
};
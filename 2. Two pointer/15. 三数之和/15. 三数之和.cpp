class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n<3){
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            if(nums[i]>0){
                break;
            }
            // 確保i不重複
            if(i>0 && nums[i-1] == nums[i]){
                continue;
            }
            int l = i+1;
            int r = n-1;
            while(l < r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum == 0){
                    res.push_back({nums[i],nums[l],nums[r]});
                    //確保無重複解
                    while(l < r && nums[l]==nums[l+1]){
                        l++;
                    }
                    while(l < r && nums[r]==nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }
                else if(sum < 0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
    return res;
    }
};
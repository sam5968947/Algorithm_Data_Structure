class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,1);
        int temp1 = 1;
        int temp2 = 1;
        for(int i = 0; i < n; i++){
            cout<< i <<endl;
            res[i] = res[i]*temp1;
            temp1 = temp1*nums[i];
        }
        for(int j = n-1; j >= 0; j--){
            res[j] = res[j]*temp2;
            temp2 = temp2*nums[j];
        }
        return res;
    }
};
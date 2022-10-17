class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size()-1;
        while(l<r){
            int l_value = height[l];
            int r_value = height[r];
            res = max(res, min(l_value, r_value)*(r-l));
            if(l_value < r_value){
                l += 1;
            }
            else{
                r -= 1;
            }
        }
        return res;
    }
};
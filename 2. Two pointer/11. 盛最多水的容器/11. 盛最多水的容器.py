class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        res = 0
        while l < r:
            l_value = height[l]
            r_value = height[r]
            res = max(min(l_value, r_value)*(r - l), res)
            if l_value < r_value:
                l += 1
            else:
                r -= 1
        return res
'''
方法2:透過XOR，res ^= i ^ nums[i]
ex:[3,0,1]-->res = 3^(0^3)^(1^0)^(2^1) = (3^3)^(1^1)^(0^0)^2 = 2
'''

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = len(nums)
        for i in range(len(nums)):
            res ^= i ^ nums[i]
        return res
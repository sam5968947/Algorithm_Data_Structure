class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1]*len(nums)
        temp1 = 1
        for i in range(len(nums)):
            res[i] = res[i]*temp1
            temp1 = temp1*nums[i]
        # print(res)
        temp2 = 1
        for j in range(len(nums)-1,-1,-1):  
            res[j] = res[j]*temp2
            temp2 = temp2*nums[j]
        return res
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:return nums[0]
        return max(self.helper(nums[:-1]), self.helper(nums[1:]))

    def helper(self, nums):
        pre, cur = 0, 0

        #pre代表rob[i-2]、cur代表rob[i-1]
        for n in nums:
            next = max(pre + n, cur)
            pre = cur
            cur = next
        return cur
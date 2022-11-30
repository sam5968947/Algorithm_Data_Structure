class Solution:
    def rob(self, nums: List[int]) -> int:
        l = len(nums)
        if l == 0:return 0
        if l == 1:return nums[0]

        rob = [0] * l
        rob[0] = nums[0]
        rob[1] = max(nums[0], nums[1])

        for i in range(2, l):
            rob[i] = max(rob[i-1], rob[i-2] + nums[i])

        return rob[l-1]
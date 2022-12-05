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

# 優化版
class Solution:
    def rob(self, nums: List[int]) -> int:
        # 相等於方法1的rob[i-2]
        pre = 0
        # 相等於方法1的rob[i-1]
        cur = 0

        for num in nums:
            # 最高金額
            next = max(num + pre, cur)
            pre = cur
            cur = next
        
        return cur
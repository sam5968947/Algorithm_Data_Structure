class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:return 0
        set_nums = set(nums)
        res = 1
        for num in nums:
            if (num - 1) not in set_nums:
                length = 1
                while (num + length) in set_nums:
                    length += 1
                    res = max(res, length)
        return res
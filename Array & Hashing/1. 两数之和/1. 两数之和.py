class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i, v in enumerate(nums):
            if v in dic:
                return [dic[v], i]
            temp = target - v#補數為key, index為value。後續若有數等於補數時即找到答案
            dic[temp] = i
        return []
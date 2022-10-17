class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = []
        dic = {}#數字:次數
        cnt = [[] for k in range(len(nums)+1)]#index = 次數，cnt[index] = 數字
        for num in nums:
            dic[num] = 1+dic.get(num,0)
        for key, value in dic.items():
            cnt[value].append(key)  
        for l in range(len(cnt)-1,0,-1):
            for j in cnt[l]:
                res.append(j)
                if len(res) == k:
                    return res
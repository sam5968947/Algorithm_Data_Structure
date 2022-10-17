class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []
        dic = {}
        for i, sub_s in enumerate(strs):
            count = [0]*26
            for s in sub_s:
                count[ord(s)-97] += 1
            if tuple(count) not in dic:
                dic[tuple(count)] = []
            dic[tuple(count)].append(sub_s)
        for k in dic.values():
            res.append(k)
        return res
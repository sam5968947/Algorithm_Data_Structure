class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #ord("a") = 97，依此類推...
        temp1 = [0]*26
        temp2 = [0]*26
        for sub_s in s:
            temp1[ord(sub_s) - 97] += 1
        for sub_t in t:
            temp2[ord(sub_t) - 97] += 1
        return temp1 == temp2
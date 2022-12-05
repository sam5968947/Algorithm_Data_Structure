class Solution:
    def countSubstrings(self, s: str) -> int:
        res = 0
        for i in range(len(s)):
            res += self.check(i, i, s)
            res += self.check(i, i + 1, s)
        
        return res

    def check(self, l, r, s):
        count = 0
        while l >= 0 and r < len(s) and s[l] == s[r]:
            count += 1
            l -= 1
            r += 1
        
        return count

# python解法1(參考最长回文子串優化)
class Solution:
    def countSubstrings(self, s: str) -> int:
        return self.count(s, 0)
    
    def count(self, s, cnt):

        for i in range(len(s)):
            # 偶數，注意此處不是判斷s的長度，而是判斷"回文串的長度是奇或偶數"
            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                cnt += 1
                l -= 1
                r += 1
            # 奇數
            l, r = i, i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                cnt += 1
                l -= 1
                r += 1      

        return cnt
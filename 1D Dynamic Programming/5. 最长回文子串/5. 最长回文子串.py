class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        maxlen = 0

        for i in range(len(s)):
            # 偶數，注意此處不是判斷s的長度，而是判斷"回文串的長度是奇或偶數"
            # if len(s) % 2 == 0:
            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                temp_len = r - l + 1
                if temp_len > maxlen:
                    res = s[l : r + 1]
                    maxlen = temp_len
                l -= 1
                r += 1
            # 奇數
            # else:
            l, r = i, i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                temp_len = r - l + 1
                if temp_len > maxlen:
                    res = s[l : r + 1]
                    maxlen = temp_len
                l -= 1
                r += 1      

        return res
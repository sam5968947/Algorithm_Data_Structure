class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s)-1
        while l<r:
            while l<r and (self.check(s[l]) is None):
                l+=1
            while l<r and (self.check(s[r]) is None):
                r-=1
            print(l, r)
            if s[l].lower() != s[r].lower():
                return False
            l+=1
            r-=1
        return True
        
    def check(self, sub_s):
        if (ord("A") <= ord(sub_s) <= ord("Z")) or \
        (ord("a") <= ord(sub_s) <= ord("z")) or \
        (ord("0") <= ord(sub_s) <= ord("9")):
            return sub_s
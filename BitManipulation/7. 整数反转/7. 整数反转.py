class Solution:
    def reverse(self, x: int) -> int:
        res = 0
        last = 0
        p_or_m = True if x > 0 else False
        x = abs(x)
        while (x != 0):
            tmp = x % 10 #取尾數
            res = res * 10 + tmp #答案為上次答案*10 + 此次尾數
            x = x // 10

        if(res > 2147483647 or res < -2147483648):
            return 0

        if p_or_m: 
            return res
        else:
            return -res
class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        while n:
            #取餘等於1代表尾數存在1
            if n % 2 == 1:
                res+=1
            #所有語都支持位運算
            n = n >> 1
            print(n)
        return res
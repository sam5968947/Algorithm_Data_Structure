class Solution:
    def countBits(self, n: int) -> List[int]:
        res = []
        for i in range(n+1):
            res.append(self.hammingWeight(i))
        return res

    def hammingWeight(self, n: int) -> int:
        res = 0
        while n:
            #取餘等於1代表尾數存在1
            if n % 2 == 1:
                res+=1
            #所有語都支持位運算
            n = n >> 1
        return res
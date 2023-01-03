class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            bit = 1 & (n >> i)
            # 2進制與10進制處理方式不同
            # res = res*10 + bit
            # bit由左往右推(31-i)位
            res += bit << (31 - i)
        
        return res
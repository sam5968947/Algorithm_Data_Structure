class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for(int i = 0; i < 32; i++){
            // 取最左數
            uint32_t bit = 1 & (n >> i);
            // bit由左往右推(31-i)位
            res += bit << (31 - i);
        }

        return res;
    }
};
class Solution {
public:
    int hammingWeight(uint32_t n) {

        int cnt = 0;
        for(int i = 0; i < 32; i++){
            cnt += 1 & n;
            n = n >> 1;
        }

        return cnt;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
    /*
    n&(n-1)作用：將n的二進製表示中的最低位為1的改為0，先看一個簡單的例子：
    n = 10100(二進制），則(n-1) = 10011 ==》n&(n-1) = 10000
    可以看到原本最低位為1的那位變為0。
    */    
    int cnt = 0;

    while(n != 0){
        n = n&(n - 1);
        cnt++;
    }

    return cnt;
    }
};
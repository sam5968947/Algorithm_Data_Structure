class Solution {
private:
    int hammingweight(int num){
        int cnt = 0;

        while(num != 0){
            num = num&(num - 1);
            cnt++;
        }

        return cnt;
    }

public:
    vector<int> countBits(int n) {
    /*
    n&(n-1)作用：將n的二進製表示中的最低位為1的改為0，先看一個簡單的例子：
    n = 10100(二進制），則(n-1) = 10011 ==》n&(n-1) = 10000
    可以看到原本最低位為1的那位變為0。
    */
    vector<int> res;

    for(int i = 0; i < n + 1; i++){
        res.push_back(hammingweight(i));
    }

    return res;
    }
};
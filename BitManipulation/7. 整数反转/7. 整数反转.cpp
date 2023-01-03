class Solution {
public:
    int reverse(int x) {
        bool p_or_n = x > 0 ? true : false;
        long long res = 0; //避免x溢出

        // x不需處理絕對值問題
        while(x != 0){
            int tmp = x % 10;
            res = res*10 + tmp;
            x = x/10;
        }

        if(res > 2147483647 || res < -2147483648){
            return 0;
        }

        return res;
    }
};
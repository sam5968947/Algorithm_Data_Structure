class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # 題目求最小視窗-->右每次走1(for)，左盡可能往右走(while)
        debt = {}
        for k in t:
            debt[k] = 1 + debt.get(k, 0)

        # 計數器，注意僅當debt[k]為0時counter才+1，當全為可能為答案
        counter = 0

        # 左指針
        l_p = 0

        # 解答與最小長度初始化
        min_s = None
        min_len = float("inf")

        for r_p in range(len(s)):
            # ------------------------------------------------------------
            ch = s[r_p]
            r_p += 1
            # 若ch非我們在意的字元，skip
            if ch not in debt:
                continue

            # ch為t內存在的字元
            debt[ch] -= 1
            if debt[ch] == 0:
                counter += 1
            # ------------------------------------------------------------
            # 滿足答案條件
            while counter == len(debt) and l_p <= r_p:
                # 更新答案
                cur_len = r_p - l_p
                if cur_len < min_len:
                    min_len = cur_len
                    min_s = s[l_p : r_p]
                
                # 同上虛線，稍作修改
                ch = s[l_p]
                l_p += 1
                if ch not in debt:
                    continue
                debt[ch] += 1
                if debt[ch] == 1:
                    counter -= 1
        
        return min_s if min_s is not None else ""
class Solution {
public:
    int Sum_Solution(int n) {
        // 利用 && 的短路原理 复杂度O（n）
        int ans = n;
        ans && (ans += Sum_Solution(n-1));
        return ans;
        /*
        bool a[n][n+1];
        return sizeof(a)>>1;
        */
    }
};

// 题目描述
// 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

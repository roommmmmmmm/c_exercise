// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

class Solution {
public:
    int jumpFloor(int number) {

        if(number == 1 || number == 2){
            return number;
        }
   	    // 第一阶和第二阶考虑过了，初始当前台阶为第三阶，向后迭代
        // 思路：当前台阶的跳法总数=当前台阶后退一阶的台阶的跳法总数+当前台阶后退二阶的台阶的跳法总数
        int jumpSum = 0; // 当前台阶的跳法总数
        int jumpSumBackStep1 = 2; // 当前台阶后退一阶的台阶的跳法总数(初始值当前台阶是第3阶)
        int jumpSumBackStep2 = 1; // 当前台阶后退二阶的台阶的跳法总数(初始值当前台阶是第3阶)

        for(int i = 3; i <= number; i++){
            jumpSum = jumpSumBackStep1 + jumpSumBackStep2;
            jumpSumBackStep2 = jumpSumBackStep1; // 后退一阶在下一次迭代变为后退两阶
            jumpSumBackStep1 = jumpSum; // 当前台阶在下一次迭代变为后退一阶
        }
        return jumpSum;
    }
};

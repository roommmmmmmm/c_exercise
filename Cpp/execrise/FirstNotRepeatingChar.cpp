class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unsigned int hash[256] = {0};
        if(str.length() <= 0) return -1;
        //第一次循环用hash表记录出现次数
        for(int i = 0;i < str.length();i++){
            hash[(int)str[i]]++;
        }
        //二次遍历直接访问hash表
        for(int i = 0; i< str.length();i++){
            if(hash[(int)str[i]] == 1)
                return i;
        }
        return -1;
    }
};
// 题目描述
// 在一个字符串(1<=字符串长度<=10000，全部由大小写字母组成)中找到第一个只出现一次的字符,并返回它的位置

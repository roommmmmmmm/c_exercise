class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty() || num1 == NULL || num2 == NULL) return ;

        map<int,int> imap;

        map<int,int>::iterator it;

        for(vector<int>::size_type i = 0; i < data.size() ;i++){
            imap[data[i]]++;
        }

        int k = 0;

        for(it = imap.begin();it !=imap.end();it++){
            if(it->second == 1){
                if(k == 0){
                    num1[0] = it ->first;
                    k++;
                }
                if(k == 1) {
                    num2[0] = it->first;
                }
            }
        }
    }
};
// 题目描述
// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

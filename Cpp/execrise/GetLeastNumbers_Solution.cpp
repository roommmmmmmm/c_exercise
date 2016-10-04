class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        // 全排列 ac
        /*vector<int> result;

        if(k > input.size()) return result;

        sort(input.begin(),input.end());
        for(int i =0; i< k; i++)
            result.push_back(input[i]);

        return result;*/

        vector<int> result;

        if(k > input.size()) return result;

        for(int i=0; i< k; i++){
			heapSort(input,i,input.size());
            result.push_back(input[i]);
        }
        return result;
    }
private:
    void heapSort(vector<int> &input, int root, int end){
        for(int j = end - 1; j>= root;j--){
            int parent = (j+root-1)/2;
            if(input[parent] > input[j]){
                int temp = input[j];
                input[j]  = input[parent];
                input[parent] = temp;
            }
        }
    }
};



// 题目描述
// 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

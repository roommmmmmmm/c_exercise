// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
// NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) return -1;

        for(int i = 0;i < rotateArray.size() - 1 ; i++){
            if(rotateArray[i] > rotateArray[i+1])
                return rotateArray[i + 1];
        }
        return rotateArray[0];
    }
};
// 思路
// 1.数组为空
// 2.部分旋转，例如由（1,2,3,4,5）旋转为（3,4,5,1,2），此时只需要遍历数组，找到当前数比前面的数小的数即可。
// 3.完全旋转，例如由（1,2,3,4,5）旋转为（1,2,3,4,5），此时第一个数最小。

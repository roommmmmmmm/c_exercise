// 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 
class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
       int m,n,x,y;
        m = array.size();//行数
        n = array[0].size();//列数
        x=m-1;y=0;//坐标定在左下角
        while(x>=0 && y<=n-1){
          if(target<array[x][y]){
                       x--;//遇小上移
                 }
          else if(target>array[x][y]){
                       y++;//遇大右移
                 }
          else {
               return true;
             }
      }
       return false;
    }
};

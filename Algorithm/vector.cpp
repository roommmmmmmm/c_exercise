#include <iostream>
#include <cstring>
using namespace std;
class Vector{
private:
  int size,length;
  int *data;
public:
  //构造函数
  Vector(int input_size){
    size = input_size; //初始化长度
    length = 0;
    data = new int[size];//分配内存
  }
  //析构函数
  ~Vector(){
    delete[] data; //处理内存
  }
  /*
  * @param int loc 代表插入的起始位置
  * @param int value 代表插入的值
  */
  bool insert(int loc , int value){
    // 判断插入位置如果小于0或者位置大于顺序表长度
    if( loc < 0 || loc > length ){
    return false;
    }
    //长度是否大于顺序表长度
    if(length >= size){
        //return false;
        expand();
    }
    for ( int i = length; i > loc; --i) {
      data[i] = data[i-1];
    }
    data[loc] = value;
    length++;
    return true;
  }
  /*
   * 进行扩容操作
   */
  void expand(){
    int *old_data=data;
    size = size * 2;
    data = new int[size];
    for (int i = 0; i < length; i++) {
      data[i] = old_data[i];
    }
    delete[] old_data;
  }
  /*
   * 查找顺序表中的元素，查到以后返回下表
   */
  int search(int value){
    for (int i = 0; i < length; i++) {
      if (data[i] == value) {
        return i;
      }
    }
    return -1;
  }
  bool remove(int index){
    if (index < 0 || index >= length) {
      return false;
    }
    for (int i = index + 1; i < length; i++) {
      data[i-1] = data[i];
    }
    length--;
    return true;
  }
  void print() {
    for (int i = 0; i < length; i++) {
      if(i>0){
        cout<<" ";
      }
      cout<<data[i];
    }
    cout<<endl;
  }
};
int main() {
  Vector a(2);
  cout << a.insert(1,0) << endl;
  cout << a.insert(0,1) << endl;
  cout << a.insert(2,1) << endl;
  cout << a.insert(1,2) << endl;
  cout << a.insert(0,3) << endl;
  cout << a.insert(2,3) << endl;
  cout << a.remove(2,3) << endl;
  cout << a.search(4) << endl;
  cout << a.search(1) << endl;
  return 0;
}

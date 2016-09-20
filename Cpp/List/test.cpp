#include <iostream>
#include <cstring>
using namespace std;
class Vector{
private:
  int size,length;
  int *data;
public:
  Vector(int input_size){
    size = input_size;
    length = 0;
    data = new int[size];
  }
  ~Vector(){
    delete[] data;
  }
  //插入操作
  bool insert(int loc, int value){
    if(loc < 0 || loc > length){
      return false;
    }
    if(length >= size ){
      return false;
    }
    for (int i = length; i > loc; --i) {
      data[i] = data[i-1];
    }
    data[loc] = value;
    length++;
    return true;
  }
  //搜索操作
  int search(int value){
    for(int i = 0; i<length;++i){
      if(data[i] == value){
        return i;
      }
    }
    return -1;
  }
  //删除操作
  bool remove(int index){
    if(index <0 || index >= length){
      return false;
    }
    for(int i = index+1;i<length;++i){
      data[i-1] =data[i];
    }
    length = length-1;
    return true;
  }
  //遍历
  void output(){
    for(int i = 0;i < length;i++){
      if(i > 0){
        cout << " ";
      }
      cout << data[i];
    }
    cout << endl;
  }
  int get_data(int index){
    if(index < 0 || index >= length)
      return -1;
    else
      return data[index];
  }
};
int main() {
  int m,k,num;
  cin >> m >> k;
  Vector a(m);
  for (int i = 0; i < m; i++) {
    cin >> num ;
    a.insert(i,num);
  }
  for(int i = 0;i<k;i++){
    int temp = a.get_data(0);
    a.remove(0);
    a.insert(m -1 ,temp);
  }
  a.output();
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> // sort, max_element, random_shuffle, remove_if, lower_bound
#include <functional> // greater, bind2nd

int main(int argc, char const *argv[]) {
  int arr[4] ={1,2,3,4};

  std::vector<int> foo(arr,arr+4);
  foo.push_back(5);
  foo.push_back(6);
  foo.push_back(7);
  foo.push_back(8);
  foo.push_back(9);
  foo.push_back(10);
  // 此时的向量内容为 {1, 2, 3, 4, 5, 6, 7, 8}
  // 随机移动元素
  random_shuffle(foo.begin(),foo.end());
  random_shuffle(foo.begin(),foo.end());

  std::vector<int>::const_iterator largest = max_element(foo.begin(),foo.end());
  std::cout << "当前最大的元素是：" << *largest << std::endl;
  std::cout << "它的索引位置是：" << largest - foo.begin() << std::endl;
  //std::cout << foo.size() << std::endl;
  sort(foo.begin(),foo.end()); // 排序元素

  std::vector<int>::const_iterator index = lower_bound(foo.begin(),foo.end(),4);
  std::cout << "要查找的元素下标是：" << index - foo.begin() << std::endl;

  foo.clear();
  //迭代器
  for(std::vector<int>::const_iterator it = foo.begin(); it != foo.end();++it){
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}

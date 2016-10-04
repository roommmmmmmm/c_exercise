#include <iostream>
#include <vector>
#include <algorithm> // sort, max_element, random_shuffle, remove_if, lower_bound
#include <functional> // greater, bind2nd

int main(int argc, char const *argv[]) {
  std::vector<int> foo(3,10);

  //迭代器
  for(std::vector<int>::const_iterator it = foo.begin(); it != foo.end();++it){
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}

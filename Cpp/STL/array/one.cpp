#include <iostream>
#include <array>
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include <algorithm>

namespace ClassFoo{
  void PrintIntArray(std::array<int,10> &a,const char *pre) {
    std::array<int,10>::iterator it;
    std::cout << pre ;
    for(it = a.begin();it != a.end();it++){
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
  int RandomNumber(){
    return (std::rand()%100);
  }

  void ArrayExample(){
    std::array<int,10> foo;

    //随机生成数组
    std::srand(unsigned(std::time(0)));
    std::generate(foo.begin(),foo.end(),RandomNumber);

    PrintIntArray(foo,"随机生成的数组：");
    //排序
    std::sort(foo.begin(),foo.end());
    PrintIntArray(foo,"排序后的数组：");

    //翻转
    std::reverse(foo.begin(),foo.end());
    PrintIntArray(foo,"翻转后的数组：");

    //值返回
    std::cout << "数组大小:" << foo.size() << std::endl;
    std::cout << "数组最大值:" << foo.max_size() << std::endl;

    //最大值和最小值
    std::cout << "最大值:" << *std::max_element(foo.begin(),foo.end()) << std::endl;
    std::cout << "最小值:" << *std::min_element(foo.begin(),foo.end()) << std::endl;

    std::array<int,0> bar;
    std::cout << "foo是否为空:" << std::boolalpha << foo.empty() << std::endl;
    std::cout << "bar是否为空:" << std::boolalpha << bar.empty() << std::endl;

    //修改元素的内容
    foo[0] = 111;
    std::cout << "修改第一个元素为：" << foo.at(0) << std::endl;
    PrintIntArray(foo,"修改后的数组：");
    //用0填充
    foo.fill(1);
    PrintIntArray(foo,"填充后的数组：");
    // front、back 返回的分别是对第一个或最后一个元素的引用
    foo.front() = 7;
    foo.back() = 13;
    PrintIntArray(foo,"修改第一个及最后一个元素后的数组：");
  }
}

int main(int argc, char const *argv[]) {
  ClassFoo::ArrayExample();
  return 0;
}

#include <iostream>
#include <map>
#include <algorithm>

namespace ClassFoo{
  void PrintMap(std::map<int,double> &m, const char *pre) {
    std::map<int,double>::iterator it;
    std::cout << pre;
    for(it = m.begin(); it != m.end();it++){
      std::cout << "(" << it->first << "," << it->second << ")";
    }
    std::cout << std::endl;
  }

  void MapExample() {
    std::map<int, double> foo;

    //普通插入
    foo.insert(std::map<int, double>::value_type(1,33.2));
    // 带暗示插入，std::pair<int,double>等价于上述的
    // std::map<int,double>::value_type
    foo.insert(foo.end(),std::pair<int,double>(2,35.8));
    // 插入一个范围
    std::map<int,double> bar;
    bar.insert(std::map<int,double>::value_type(3, 36.4));
    bar.insert(std::map<int,double>::value_type(4, 37.8));
    bar.insert(std::map<int,double>::value_type(5, 35.4));
    foo.insert(bar.begin(),bar.end());

    PrintMap(foo,"插入元素后的foo：");

    std::map<int, double>::iterator it;
    it = foo.find(4);
    if (it != foo.end()) {
      std::cout << "foo.find(4):";
      std::cout << "(" << it->first << "," << it->second << ")" << std::endl;
    }
    // 删除上述找到的元素
    if( it != foo.end() )
    {
        foo.erase(it);
    }
    PrintMap(foo,"删除主键为4的元素后的foo：");
    // 遍历删除主键为2的元素
    for(it = foo.begin();it != foo.end();it++){
      //遍历删除主键等于2
      //注意，删除元素会使迭代范围发生变化
      if (it->first == 2) {
        foo.erase(it);
        break;
      }
    }
  PrintMap(foo,"删除主键为2的元素后的foo：");

  foo.clear();
  PrintMap(foo,"清空元素后的foo:");  
  }
}
int main()
{
    ClassFoo::MapExample();
    return 0;
}

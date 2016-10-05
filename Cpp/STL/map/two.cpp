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

    //放置插入
    foo.emplace(6,38.1);
    // 带暗示的放置插入
    std::map<int, double>::iterator it;
    it = foo.find(5);
    foo.emplace_hint(it,7,36.4);
    foo.emplace_hint(foo.end(),8,36.4);
    PrintMap(foo,"插入元素后的foo：");

    // 修改指定键值的元素值
    foo.at(5) = 100.22;
    PrintMap(foo,"修改指定键值后的foo：");

    // 查找指定主键元素
    it = foo.find(4);
    if (it != foo.end()) {
      std::cout << "foo.find(4)：";
      std::cout << "(" << it->first << "," << it->second << ")"
    << std::endl;
    }
    // 删除找到的元素
    if (it != foo.end()) {
      foo.erase(it);
    }
    PrintMap(foo,"删除指定键值后的foo：");
    // 遍历删除指定主键的元素
    for(it = foo.begin();it != foo.end();it++){
        //遍历删除主键等于2
        //注意，删除元素会使迭代范围发生变化
        if(it->first == 2)
        {
            foo.erase(it);
            break;
        }
    }
    PrintMap(foo,"删除指定键值后的foo：");
    foo.clear();
    PrintMap(foo,"清空后的foo：");

  }
}
int main()
{
    ClassFoo::MapExample();
    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  std::vector<string> foo;

  foo.push_back("a");
  foo.push_back("b");
  foo.push_back("c");

  cout << "循环下标访问:" << endl;
  for(vector<string>::size_type i=0; i < foo.size(); ++i){
    std::cout << foo[i] << std::endl;
  }

  cout << "常量迭代器访问:" << endl;
  vector<string>::const_iterator cii;
  for(cii=foo.begin(); cii!=foo.end(); ++cii){
      cout << *cii << endl;
  }

  cout << "倒序访问:" << endl;
  vector<string>::reverse_iterator rii;
  for(rii=foo.rbegin(); rii!=foo.rend(); ++rii){
      cout << *rii << endl;
  }

  return 0;
}

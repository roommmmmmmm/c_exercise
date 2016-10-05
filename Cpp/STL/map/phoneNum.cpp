#include <iostream>
#include <map>
#include <algorithm>
#include <string>

namespace ClassFoo{
  using namespace std;

  class name {
  private:
    string str;
  public:
    //name(){}
    name (string s) { str = s;}
    string get() {return str;}
  };

  bool operator<(name a,name b){
    return a.get() < b.get();
  }

  class phoneNum{
  private:
    string str;
  public:
    //phoneNum(){ }
    phoneNum(string s) { str = s;}
    string get() { return str; }
  };

  void MapExample() {
    std::map<name, phoneNum> directory;

    directory.insert(pair<name, phoneNum>(name("A"), phoneNum("555-1111")));
    directory.insert(pair<name, phoneNum>(name("B"), phoneNum("555-2222")));
    directory.insert(pair<name, phoneNum>(name("C"), phoneNum("555-3333")));
    directory.insert(pair<name, phoneNum>(name("D"), phoneNum("555-4444")));

    map<name, phoneNum>::iterator p;

    p = directory.find(name("A"));
    if(p != directory.end())
        cout << "A的电话号码为： " <<  p->second.get() << endl;
    else
        cout << "未发现A的电话号码" <<endl;
    }
}
int main()
{
    ClassFoo::MapExample();
    return 0;
}

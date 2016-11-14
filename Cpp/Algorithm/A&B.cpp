#include <iostream>
#include <string>
using namespace std;
/**
 * 有一个字母A，第一秒输出A，第二秒A变成B。
 * A变成B，B变成AB。
 * 要求，输入时间，输出字符串
 */

int main(int argc, char const *argv[]) {
    int num;
    cin >> num;
    if (num < 1)
        return 1;
    string a = "A";
    string b = "B";
    if (num == 1) {
        cout << a << endl;
    }else if (num == 2) {
        cout << b << endl;
    }
    int i;
    for ( i = 0; i < num; i++) {
        string temp = b;
        b = a + b;
        a = temp;
    }
    cout << b << endl;
    return 0;
}

#include<iostream>
using namespace std;

int fun(int num);
int main(){
    int num;
    cin >> num;
    cout << fun(num) << endl;
    return 0;
}

int fun(int num){
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    return fun(num - 1) + fun(num - 2);
}

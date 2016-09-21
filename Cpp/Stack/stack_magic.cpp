#include<iostream>
#include<string>
#include<cassert>
using namespace std;
template<class Type> class Stack {
private:
    Type *urls;
    int max_size, top_index;
public:
    Stack(int length_input) {
        urls = new Type[length_input];
        max_size = length_input;
        top_index = -1;
    }
    ~Stack() {
        delete[] urls;
    }
    bool push(const Type &element) {
        if (top_index >= max_size - 1) {
            return false;
        }
        top_index++;
        urls[top_index] = element;
        return true;
    }
    bool pop() {
        if (top_index < 0) {
            return false;
        }
        top_index--;
        return true;
    }
    Type top() {
        assert(top_index >= 0);
        return urls[top_index];
    }
    bool empty(){
        if(top_index < 0){
            return true;
        }else{
            return false;
        }
    }
};


int main() {
    int N;
    int a[100], m=0,e;
    cin >> N;
    Stack<int> stack(N);
    for (int i = 0; i < N; i++) {
        int opr;
        cin >> opr;
        a[i] = opr;
    }
    for(int i=1;i<=N;i++){
        stack.push(i);
        while( !stack.empty() ){
            e = stack.top();
            if( e == a[m] ){
                stack.pop();
                m++;
            }else{
                break;
            }
        }
    }
    if( stack.empty() ){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}

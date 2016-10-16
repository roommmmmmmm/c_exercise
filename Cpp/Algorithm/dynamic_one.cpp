#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 *
 */
int Decode_num(string &str){
    std::vector<int> vec(str.size(),1);
    if (str.size() < 2) {
        return 1;
    }
    if (str[0] = '1' || (str[0] == '2' && str[1]<= '6')) {
        vec[1] = 2;
    }
    int i , tmp;
    for ( i = 2; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            vec[i] = vec[i-1];
        }else{
            return 0;
        }
        tmp = str[i-1] - '0';
        tmp = tmp * 10 + str[i] - '0';
        if (str[i-1] != '0' && tmp <=26) {
            vec[i] += vec[i-2];
        }
    }
    return vec[str.size()-1];
}
int main(int argc, char const *argv[]) {
    string str("1231725");
    std::cout << Decode_num(str) << std::endl;
    return 0;
}

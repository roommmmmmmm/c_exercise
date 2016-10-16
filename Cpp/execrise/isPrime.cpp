#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(long n){
    if (n==2)
        return true;
    int i;
    for ( i = 2; i <= sqrt(n); i++) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[]) {
    long n;
    cin >> n;
    std::cout << isPrime(n) << std::endl;
    return 0;
}

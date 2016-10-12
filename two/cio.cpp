#include <iostream>

using namespace std;

template <typename T>
T abs(T x){
	return x < 0 ? -x : x ;
}

int main(int argc, char const *argv[]) {
	int n = 5;
	double d = -5.5;
	std::cout << abs(n) << std::endl;
	std::cout << abs(d) << std::endl;
	return 0;
	
}

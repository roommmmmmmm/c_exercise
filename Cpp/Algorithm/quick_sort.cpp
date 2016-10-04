#include<iostream>
using namespace std;
void Qsort(int *a, int low, int high);

int main(){
	int a[] = {57,68,59,2,555,86,97,67,33,63,21};
	Qsort(a,0,sizeof(a)/sizeof(a[0])-1);
	for(int i = 0; i< sizeof(a)/sizeof(a[0]);i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
void Qsort(int *a , int low, int high){
	if(low >= high) return ;

	int first = low;
	int last = high;
	int key = a[first];

	while(first < last){
		while(first < last && a[last] >= key){
			--last;
		}

		a[first] = a[last];

		while(first < last && a[first] <= key){
			++first;
		}
		a[last] = a[first];
	}
	a[first] = key;
	Qsort(a,low,first-1);
	Qsort(a,first+1,high);
}

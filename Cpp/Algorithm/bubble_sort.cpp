#include<iostream>
using namespace std;

void bubble_sort(int *a, int count);

int main(){
	int a[] = {2,5,9,44,67,32,66};
	bubble_sort(a,7);
	for(int i = 0; i < 7; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

void bubble_sort(int *a, int count){
	int temp;
	for(int i = 1; i < count ; i++){
		for(int j = count -1; j>= i; j--){
			if(a[j] < a[j-1]){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
}

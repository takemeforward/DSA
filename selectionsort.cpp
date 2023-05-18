#include <iostream>
using namespace std;
int main(){
	int arr[] = {1,7,9,2,3,0,-2};
	int n = 7;
	for(int i = 0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			if(arr[j]<arr[i]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for(int i = 0; i<n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
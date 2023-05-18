#include <iostream>
using namespace std;
int countCall = 0;
int BinarySearch(int arr[], int s, int e, int key){
	countCall++;
	int mid = s/2+e/2;
	if(s>e){
		return -1;
	}
	if(arr[mid]==key){
		return mid;
	}else if(key>arr[mid]){
		return BinarySearch(arr, mid+1, e, key);
	}else{
		return BinarySearch(arr, s, e-1, key);
	}
	return -1;
}
int main(){
	int odd[] = {1 ,4 , 7, 24, 27, 55, 100};
	int key = 55;
	int index = BinarySearch(odd, 0, 6, key);

	cout << index << endl;
	cout << countCall << endl;
	return 0;
}
#include <iostream>
using namespace std;
int main(){

	int odd[] = {1 ,4 , 7,7,7,7, 24, 100};

	int s = 0;
	int e = 8;
	int key = 7;
	int mid;
	while(s<=e){
		mid = (s+e)/2;

		if(odd[mid]==key){
			cout << mid; break;
		}else if(key>odd[mid]){
			s = mid+1;
		}else{
			e = mid-1;
		}
	}
	return 0;
}
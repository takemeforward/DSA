#include <iostream>
using namespace std;

int main(){
	int n = 5;

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(j>n-i+1){
				cout << "*";
			}else{
				cout << j;
			}
		}
		for(int j = n; j>0; j--){
			if(j>n-i+1){
				cout << "*";
			}else{
				cout << j;
			}
		}
		cout << endl;
	}
	return 0;
}
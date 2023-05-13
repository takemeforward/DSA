#include <iostream>
using namespace std;

int main(){

	int n = 4;
	int count;
	for(int i = 1; i<=n; i++){
		count = i;
		for(int j = 0; j<n; j++){
			if(j>=i-1){
				cout << count;
				count++;
			}else{
				cout << " ";
			}

		}
		cout << endl;
	}

	
	return 0;
}
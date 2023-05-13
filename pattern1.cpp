#include <iostream>
using namespace std;

int main(){

	int n = 5;

	int count;

	for(int i = 1; i<=n; i++){
		count = i;
		for(int j = 0; j<i; j++){
			
			cout << count << " ";
			count--;
		}
		cout << endl;
	}
	
	return 0;
}
#include <iostream>
using namespace std;

int main(){

	int n = 3;

	char ch;

	for(int i = 0; i<n; i++){
		ch = 'A';
		for(int j = 0; j<n; j++){
			cout << ch << " ";
			ch++;
		}
		cout << endl;
		
	}
	
	return 0;
}
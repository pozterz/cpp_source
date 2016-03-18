#include<iostream>
using namespace std;
int main(){
	enum tid{
		N = 'N',E = 'E',S,W
	};
	
	char c = N+1;
	cout << c;

	return 0;
}

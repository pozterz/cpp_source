#include<iostream>
using namespace std;
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int max = (b-a)>=(c-b)?(b-a):(c-b);
	cout << max-1;
	
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	long long int a,b;
	while(cin >> a >> b){
		if(a>b) swap(a,b);
		cout << b - a << endl;
	}
	return 0;
}

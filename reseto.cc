#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	int even[n+1];
	int odd[n+1];
	for(int i = 0; i <= n; i+=2){
		even[i] = 2+i;
		odd[i] = 2+i+1;
	}
	for(int i = 0; i <= n; i+=2){
		cout << odd[i] << " ";
	}
}

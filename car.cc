#include<iostream>
#include<map>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	map<int,int> c,freq,sum;
	int m;
	for(int i = 0; i < n; i++){
		cin >> m;
		freq[m] += 1;
	}
	sum[0] = freq[0];
	map<int,int>::iterator it;
	for(it = freq.begin(); it != freq.end(); it++){
		cout << it->second();
	}
	for(int i = 0; i < n; i++){
		if(sum[i] >= k) cout << i << endl;
	}
}

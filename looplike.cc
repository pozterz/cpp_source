#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int c[10001] = {0};
	cin >> n;
	for(int i = 0; i < n; i++){
		int m;
		cin >> m;
		c[m] += 1;
	}
	int max = *max_element(c,c+10001);
	for(int i = 0;i < 10001; i++){
		if(c[i] == max)
			cout << i << " ";
	}
}

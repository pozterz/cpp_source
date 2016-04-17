#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int x[3];
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x[0] >> x[1] >> x[2];
		sort(x,x+3);
		cout << "Case " << i << ": " << x[1] << endl;
	}
	
	return 0;	
}

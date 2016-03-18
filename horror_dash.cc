#include<iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	int i = t;
	while(t--){
		int n;
		cin >> n;
		int max = 0;
		while(n--){
			int x;
			cin >> x;
			max = x>max?x:max;
		}
		cout << "Case " << i-t << ": " << max << endl;
		
	}
	return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v;
		
		for(int i = 1; i <= n; i++){
			v.push_back(i);
		}
		
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			if(i > 1) cout << " ";
			cout << v[x];
			v.erase(v.begin()+x);
		}
		
		v.clear();
		cout << endl;
	}
	return 0;
}

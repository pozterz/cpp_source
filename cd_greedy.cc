#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	
	int n;
	while(cin >> n){
		vector<int> v;
		int x;
		cin >> x;
		while(x--){
			int num;
			cin >> num;
			v.push_back(num);
		}
		vector<int> v_cp = v;
		sort(v_cp.begin(),v_cp.end(),cmp);
		int sum = 0;
		for(int i = 0; i < v_cp.size();i++){
			for(int j = 1; j < v_cp.size();j++){
				if(v_cp[i]+)
			}
		}
	}
	
	
	return 0;
}

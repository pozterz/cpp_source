#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		if(n == 0) break;
		while(1){
			stack<int> st;
			vector<int> v;
			int x;
			cin >> x;
			if(x == 0){ cout << endl; break; }
			v.push_back(x);
			for(int i = 0; i < n-1; i++){
				cin >> x;
				v.push_back(x);
			}
			int i = 0;
			for(int j = 1; j <= n; j++){
				st.push(j);
				if(!st.empty()){
					while(st.top() == v[i]){
						st.pop();
						i++;
						if(st.empty()) break;
					}
				}
			}
			if(st.empty())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			v.clear();
		}

	}
	return 0;
}

/*** Uva username : pozterz ***/
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
bool calst(stack<int> st,int n,int x[]){
	sort(x,x+n);
	while(!st.empty()){
		
	}
	
	for(int i = 0; i < n; i++) if(x[i] != 1)
		return false;
	return true;
}
int main(){
	while(1){
		int n;
		cin >> n;
		if(n == 0) break;
	
		while(1){
			bool ans;
			stack<int> s;
			int i;
			int x[n+1];
		 	for(i = 0; i < n; i++){
		 		cin >> x[i];
				if(x[i] == 0){
			 		cout << endl; break;
			 	}
			 	s.push(x[i]);
		 	}
			if(i == n){
				ans = calst(s,n,x);
				if(ans) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
			else
				break;
		}

	}
	
	
}

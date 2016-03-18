#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int main(){
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		stack<int> st;
		while(x--){
			int num;
			cin >> num;
			st.push(num);	
		}
		
		
		
		int maxx = 0;
		int count = 0;
		while(!st.empty()){
			if(st.top() > maxx)
				count++;
			maxx = max(st.top(),maxx);
			st.pop();
		}
		
		cout << "Case " << i << ": " << count << endl;
	}
	
	return 0;
}

#include<iostream>
#include<stack>
using namespace std;

int main(){
	
	string str;
	int n;

	bool ans;
	cin >> n;
	while(n--){
		cin >> str;	
		stack<char> box;
		for(int i =0 ; i < str.size(); i++){
			if(str[i] == '(' || str[i] == '[')
				box.push(str[i]);
			else{
				if(box.size() == 0) ans = false;
				else if( (str[i] == ')' && box.top() == '(') || (str[i] == ']' && box.top() == '[' )){
					box.pop();
					ans = true;
				}
				else ans = false;
			}
		}
		
		if(ans) cout << "YES" << endl;
		else cout << "No" << endl;
		
	}	
	
	return 0;
}


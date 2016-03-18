#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	int n;
	cin >> n;
	while(n--){
		stack<char> c;
		string x;
		cin >> x;
		int i = 0, score = 0;
		while(x[i] != '\0'){
			if(x[i] == 'O'){
				c.push(x[i]);
			}
			else if(x[i] == 'X'){
				while(!c.empty()){
					score += c.size();
					c.pop();
				}
			}
			
			i++;
		}
		if(!c.empty()){
			while(!c.empty()){
				score += c.size();
				c.pop();
			}
		}
		cout << score << endl;
		
	}
	
	return 0;
}

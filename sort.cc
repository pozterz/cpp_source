#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<functional>
using namespace std;
char ch;

	struct arr{
		string a;
		bool b;
		int c;
		double d;
		int e;
		bool operator< (const arr &s) const{
			switch(ch){
				case 'A': return this->a < s.a;
				case 'B': return this->b < s.b;
				case 'C': return this->c < s.c;
				case 'D': return this->d < s.d;
				case 'E': return this->e < s.e;
				default: return false;
			}
		}
	};
int main(){
	int n;
	cin >> n;
	vector<arr> v;
	for(int i = 0; i < n; i++){
		arr tmp;
		cin >> tmp.a >> tmp.b >> tmp.c >> tmp.d >> tmp.e;
		v.push_back(tmp);
	}
	vector<arr> tmp_v = v;
	int m;
	while(cin >> m){
		stack<char> s;
		if(m == 0) break;
		char tmpp;
		while(m--){
			cin >> tmpp;
			s.push(tmpp);
		}
		while(!s.empty()){
			ch = s.top();
			stable_sort(v.begin(),v.end());
			s.pop();
		}
		for(vector<arr>::iterator it = v.begin(); it != v.end(); it++)
			cout << (*it).a << endl;
		cout << endl;
		v = tmp_v;
	}
	return 0;
	exit(EXIT_SUCCESS);
}

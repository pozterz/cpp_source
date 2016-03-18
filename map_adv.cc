#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){

	int n;
	cin >> n;
	map<int,string> m;
	while(n--){
		string val;
		int key;
		cin >> val >> key;
		m[key] = val;
	}
	int l,h;
	cin >> l >> h;
	map<int,string>::iterator it = m.lower_bound(l);
	for(; it != m.upper_bound(h); it++){
		cout << it->second << endl;
	}

	return 0;
}

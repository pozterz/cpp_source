#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;
int main(){
	// babelfish | map
	map<string,string> m;
	
	while(1){
		string s;
		getline(cin,s);
		if(s.size() == 0) break;
		stringstream ss(s);
		string a,b;
		ss >> a >> b;
		m[b] = a;
	}

	while(1){
		string str;
		cin >> str;
		if(str.size() == 0) break;
		if(m.count(str))
			cout << m[str] << endl;
		else
			cout << "eh" << endl;
	}
	
	
	return 0;
}

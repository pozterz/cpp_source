#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){

	int n;
	cin >> n;
	map<double,string> m;
	while(n--){
		string val;
		double key;
		cin >> key >> val;
		m[key] = val;
	}
	
	double l,h;
	cin >> h >> l;
	map<double,string>::iterator it = m.lower_bound(h);

	if(l > 0.0){
		for(; it != m.upper_bound(h+l); it++){
			cout << it->second << endl;
		}
	}else{
		for(; it != m.upper_bound(h-l); it--){
			cout << it->second << endl;
		}
	}
	

	return 0;
}

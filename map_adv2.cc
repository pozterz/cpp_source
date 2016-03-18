#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;

int main(){
	typedef pair<int,int> pa;
	int n;
	cin >> n;
	
	map<pa,string> m;
	
	while(n--){
		string val;
		int x;
		int y;
		cin >> val >> x >> y;
		m[make_pair(x,y)] = val;
	}
	
	
	int l,h,r;
	cin >> l >> h >> r;
	map<pair<int,int>,string>::iterator it = m.lower_bound(make_pair(l-r,h-r));
	for(; it != m.upper_bound(make_pair(l+r,h+r)); it++){
		if( (it->first.first >= l-r && it->first.first <= l+r) && (it->first.second >= h-r && it->first.second <= h+r) ){	
			cout << it->second << " ";
			cout << "("<< it->first.first << "),(";
			cout << it->first.second << ")"<< endl;
		}
	} 

	return 0;
}

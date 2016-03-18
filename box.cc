#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
	typedef vector<bool> v;
	int w,h;
	map<int,v> m;
	
	while(cin >> w >> h){
		if( (w < 1 && w > 10000) || (h < 1 && h > 10000)) continue;
		bool status = true;
		if(w == h) status = false;
		if(m[w].size() > 4) status = false;
		if(m[h].size() > 4) status = false;
		//cout << m[w].size() << endl;
		//cout << m[h].size() << endl;
		m[w].push_back(true);
		m[h].push_back(true);
		if(m.size() > 4) status = false;
		for(int i = 0 ; i < 5; i++){
			cin >> w >> h;
			if((w == h)) status = false;
			if( (w < 1 && w > 10000) || (h < 1 && h > 10000) ) continue;
			if(m[w].size() > 4) status = false;
			if(m[h].size() > 4) status = false;
			//cout << m[w].size() << endl;
			//cout << m[h].size() << endl;
			m[w].push_back(true);
			m[h].push_back(true);
			if(m.size() > 4) status = false;		
		}
	
			
		map<int,v>::iterator it = m.begin();
		for(; it != m.end(); it++){	
			//cout << it->first << endl;
		//	cout << it->second.size() << endl;	
			if(it->second.size() != 4) status = false;
		}
		m.clear();
		if(status) cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;
	}

	
	return 0;
}

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	// ferry loading 3 | queue
	int tc;
	cin >> tc;
	while(tc--){
		
		int n,t,m;
		cin >> n >> t >> m;
		queue<int> q[2];
		vector<int> v;
		
		for(int i = 0; i < m; i++){
			int in;
			string s;
			cin >> in >> s;
			if(s == "left"){
				q[0].push(i);
			}else
				q[1].push(i);
			v.push_back(in);
		}
		vector<int> result = v;
		int curtime = 0;
		int curside = 0;
		
		while( !q[0].empty() || !q[1].empty()){
			int next = 0;
			if(q[0].empty())
				next = v[q[1].front()];
			else if(q[1].empty())
				next = v[q[0].front()];
			else
				next = min(v[q[0].front()],v[q[1].front()]);
			
			curtime = max(curtime,next);
			int count = 0;
			
			while( !q[curside].empty() && (curtime >= v[q[curside].front()]) && count < n ){
				result[q[curside].front()] = curtime+t;
				q[curside].pop();
				count++;	
			}
			
			curtime += t;
			curside ^= 1;
			
		}
		
		vector<int>::iterator it = result.begin();
		for(; it != result.end(); it++)
			cout << *it << endl;
			
		if(tc >= 1) cout << endl;
		v.clear();
		result.clear();
	}
	
	return 0;
}

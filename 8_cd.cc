#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	// cd | set
	int n,m;
	cin >> n >> m;
	while(1){
		if(n == 0 && m == 0) break;
		set<int> nset;
		set<int> mset;
		set<int> ans;
		int tmp;
		while(n--){
			cin >> tmp;
			nset.insert(tmp);
		}
		while(m--){
			cin >> tmp;
			mset.insert(tmp);
		}
		set_intersection(nset.begin(),nset.end(),mset.begin(),mset.end(),insert_iterator<set<int> >(ans,ans.begin()));	
		cin >> n >> m;	
		cout << ans.size() << endl;	
	}

	
	
	return 0;
}

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	
	int n,m;
	cin >> n >> m;
	while(1){
		if(n == 0 && m == 0) break;
		vector<int> nset;
		set<int> mset;
		int tmp;
		while(n--){
			cin >> tmp;
			nset.push_back(tmp);
		}
		while(m--){
			cin >> tmp;
			mset.insert(tmp);
		}
	//	set_intersection(nset.begin(),nset.end(),mset.begin(),mset.end(),insert_iterator<set<int> >(ans,ans.begin()));
		vector<int>::iterator it = nset.begin();
		int count = 0;
		while(it != nset.end()){
			if(mset.count(*it)) count++;
			it++;
		}
		cin >> n >> m;
		if(n == 0 && m == 0){
			cout << count << endl;
			break;	
		}
		cout << count << endl;	
	}

	
	
	return 0;
}

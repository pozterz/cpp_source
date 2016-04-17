/****************************/
/*							*/
/*  Uva Username : pozterz	*/
/*							*/
/****************************/
#include<iostream>
#include<vector>
using namespace std;
int main(){
	// jolly jumper | 
	int n;
	while(cin >> n){
		vector<int> num;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			num.push_back(x);
		}

		vector<int>::iterator h = num.begin();
		vector<bool> ans(n,false);
		for( ; h != num.end()-1 ; ){
			int f = *h;
			++h;
			int sub = f-*h;
			if(sub < 0){
				if( ((sub*-1) <= n-1) && ans[(sub*-1)] == false)
					ans[(sub*-1)] = true;
			}
			else{
				if(sub <= n-1 && ans[sub] == false)
					ans[sub] = true;
			}
		}
		vector<bool>::iterator y = ans.begin();
		int s = 0;
		for(; y != ans.end(); y++){
			if(*y) s++;
		}
//		cout << s << endl;
		if(s == n-1)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
		ans.clear();
		num.clear();
	}

}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	int n;
	cin >> n;
	vector<int> v;
	while(n--){
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end(),cmp);
	int count = 0;
	int sum = 0;	
	for(vector<int>::iterator h = v.begin(); h != v.end(); h++){
		if(*h < 20000) sum += *h;
		else if( (*h >= 20000 && *h <= 32000 ) && count < 2) {
			sum += *h;
			count++;
		}
	}
	cout << sum << endl;
	
	return 0;
}

#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main(){
	// set 
	set<int> s1;
	set<int> s2;
	int n;
	for(int i = 0; i < 10; i++){
		cin >> n;
		s1.insert(n);
	}
	for(int i = 0; i < 10; i++){
		cin >> n;
		s2.insert(n);
	}
	set<int> s3;
	set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<set<int> >(s3,s3.begin()));
	set<int>::iterator it = s3.begin();
	for(; it != s3.end(); it++)
		cout << *it << " ";
	return 0;
}

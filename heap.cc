#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	int n[] = {2,5,1,9,8,4,3,0,7,6};
	priority_queue<int> q;
	for(int i = 0; i < 10; i++)
		q.push(n[i]);
		
	while(!q.empty()){
		cout << q.top() << " ";
		q.pop();	
	}
	cout << endl;
	
	priority_queue<int,vector<int>,greater<int> > q2;
	for(int i = 0; i < 10; i++)
		q2.push(n[i]);
		
	
	while(!q2.empty()){
		cout << q2.top() << " ";
		q2.pop();	
	}
	
	return 0;
}

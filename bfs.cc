#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>
#define N 8
using namespace std;

int a[8][8] ={
	   /*A B C D E F G H I J K */  
		{0,1,0,1,0,0,0,0},
		{1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0},
		{1,0,0,0,0,1,0,1},
		{0,0,0,0,0,0,0,1},
		{0,0,0,1,0,0,1,0},
		{0,0,1,0,0,1,0,0},
		{0,0,0,1,1,0,0,0},
	};
// bfs
vector<bool> visited;
vector<int> ans;
queue<int> q;
int bfs(int start){
	visited.assign(8,false);
	q.push(start);
	visited[start] = true;
	ans.push_back(start);
	
	while(!q.empty()){
		int u = q.front();
		
		for(int i = 0; i < N ; i++){
			if(a[u][i] && !visited[i]){
				ans.push_back(i);
				visited[i] = true;
				q.push(i);	
			}
		}
		
		q.pop();
	}
	
}
int main(){
	
	bfs(6);
	
	for(int i = 0; i < N; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}

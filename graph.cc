#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int a[11][11] ={
	   /*A B C D E F G H I J K */  
		{0,1,1,0,0,1,0,0,0,0,0},
		{0,0,0,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0},
		{0,0,1,0,0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,1,0,1,0},
	};
int bfs(int s);
int main(){
	
	bfs(0);
	
	return 0;
}
int bfs(int s){
	map<int,string> color;
	for(int i = 0; i < 11; i++){
		color[i] = "WHITE";	
	}
	
	queue<int> q;
	color[s] = "GRAY";
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		cout << char(q.front()+'A') << " ";
		q.pop();
		color[u] = "BLACK";
		for(int i = 0; i < 11; i++){
			if(a[u][i] == 1 && color[i] == "WHITE"){
				q.push(i);
				color[i] = "GRAY";
			}
				
		}	
	}
	
}

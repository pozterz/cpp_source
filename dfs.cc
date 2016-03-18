#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
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
	map<int,string> color;
int dfs(int s);
int main(){
	
	for(int i = 0; i < 11; i++){
		color[i] = "WHITE";	
	}
	dfs(0);
	
	return 0;
}
int dfs(int s){
	color[s] = "GRAY";
	for(int i = 0; i < 11; i++){
		if(a[s][i] == 1 && color[i] == "WHITE"){
			cout << char(s+'A') << " ";
			dfs(i);	
		}	
		color[s] = "BLACK";
	}
	
}

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<int,vector<int>,greater<int> > W;
vector<int> val;
vector<int> wt;

int knapsack(int m,int ww){
	int sum = 0;
	int Ans[1001][31];
	int maxw = W.top();
	for(int i = 0; i <= m; i++){
			cout << i << " ";
		for(int j = 0; j <= maxw; j++){
			if(i == 0 || j == 0){
				Ans[i][j] = 0;
			}
			else if(j < wt[i])
				Ans[i][j] = Ans[i-1][j];
			else{
				Ans[i][j] = max(Ans[i-1][j],val[i]+Ans[i-1][j-wt[i]]);
			}
			cout << Ans[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i = 0; i < ww; i++) sum+= Ans[m][MW[i]]
	return sum;
	
}
int main(){
	int n;
	int Wi;
	int m;
	cin >> n;
	while(n--){
		cin >> m;
		for(int i = 0; i < m; i++){
			int weight,value;
			cin >> value >> weight;
			val.push_back(value);
			wt.push_back(weight);
		}
		
		cin >> Wi;
		for(int i = 0; i < Wi; i++){
			int Ww;
			cin >> Ww;
			W.push(Ww);
		}
		cout << knapsack(m,Wi);
	}
	
	
   	
	
	return 0;
}

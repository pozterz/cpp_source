#include<iostream>
#include<vector>
#include<algorithm>
#define N 5
using namespace std;
int knapsack(int x[N],int w[N],int W){
	int Ans[N+1][W+1];
	
	for(int i = 0; i <= N; i++){
			cout << i << " ";
		for(int j = 0; j <= W; j++){
			if(i == 0 || j == 0){
				Ans[i][j] = 0;
			}
			else if(j < w[i])
				Ans[i][j] = Ans[i-1][j];
			else{
				Ans[i][j] = max(Ans[i-1][j],x[i]+Ans[i-1][j-w[i]]);
			}
			cout << Ans[i][j] << " ";
		}
		cout << endl;
	}
	
	return Ans[N][W];
	
}
int main(){
	
	int val[] = {20, 30, 66,40,60};
    int wt[] = {2, 2, 3,4,5};
    int W = 10;
   	cout << knapsack(val, wt, W);
    return 0;
	
	return 0;
}

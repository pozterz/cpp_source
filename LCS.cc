#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
// LCS Longest Common Subsequence
int A[1001][1001] = {0};
int main(){
	
	string s1,s2;
	while(getline(cin,s1)){
		getline(cin,s2);
		int m = s1.length();
		int n = s2.length();
		
		
		for(int i = 0; i <= m ; i++) A[i][0] = 0;
		for(int i = 0; i <= n ; i++) A[0][i] = 0;
		
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				if( s1[i-1] == s2[j-1] ){
					A[i][j] = A[i-1][j-1]+1;
				}else{
					A[i][j] = max(A[i-1][j],A[i][j-1]);
				}
			}
		}
	
		cout << A[m][n] << endl;	
	}
	
}

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	int type[5] ={50,25,10,5,1};
	
	int n,tmp;
	while(cin >> n){
		int arr[n+1][5];

		for(int i = 0; i < 5; i++) arr[0][i] = 1;

		for(int i = 1; i < n+1; i++){
			for(int j = 0; j < 5; j++){
				int x = (i-type[j] >= 0)? arr[i-type[j]][j]:0;
				int y = (j >= 1)? arr[i][j-1]:0;
				arr[i][j] = x + y;
			}
		}
		for(int i = 1; i < n+1; i++){
			for(int j = 0; j < 5; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
		cout << arr[n][4] << endl;
	}
	return 0;
}

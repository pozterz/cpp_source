#include<iostream>
using namespace std;
int main(){
	
	char arr[100][100] = {'0'};
	int n,m;
	int c=0;
	while(cin >> n >> m){
		c++;
		if(n == 0 && m == 0) break;
		int i,j;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				char tmp;
				cin >> tmp;
				if(tmp == '*'){
					if(arr[i][j-1] != '*')
						static_cast<char>(arr[i][j-1] + 1);
						
					arr[i][j] = '*';
					
					if(arr[i][j+1] != '*')
						arr[i][j+1]+=1;
						
					if(arr[i-1][j-1] != '*')
						arr[i-1][j-1]+=1;
						
					if(arr[i-1][j] != '*')
						arr[i-1][j]+=1;
						
					if(arr[i-1][j+1] != '*')
						arr[i-1][j+1]+=1;
						
					if(arr[i+1][j-1] != '*')
						arr[i+1][j-1]+=1;
						
					if(arr[i+1][j] != '*')
						arr[i+1][j]+=1;
						
					if(arr[i+1][j+1] != '*')
						arr[i+1][j+1]+=1;
				}
			}
		}
		cout << "Field #" << c << ":" << endl;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				cout << arr[i][j];
			}
			cout << endl;
		}
		
	}
	
	return 0;
}


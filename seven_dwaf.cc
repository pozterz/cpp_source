#include<iostream>
#include<algorithm>

using namespace std;
int main(){
	int c[10],tmp[10];
	for(int i = 0; i < 9; i++){
		cin >> c[i];
		tmp[i] = c[i];
	}
	sort(c,c+10);
	int sum = 0;
	int i = 0;
	int dw[10] = {0};
	while(sum < 100){
		sum+=c[i];
		dw[i] = c[i];
		i++;
	}
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(tmp[i] == dw[j]){
				cout << dw[j] << endl;
				break;
			}
		}
		
	}
}

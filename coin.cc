#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	int type[5] ={50,25,10,5,1};
	
	int n,tmp;
	while(cin >> n){
		int count = 0;
		tmp = n;
		int x = 0;
		bool fr;
		for(int i = 0; i < 5; i++){
			n = tmp;
			int yy = x;
			fr = true;
			for(int j = yy; j < 5; j++){
				if(n-type[j] >= 0){
					if(fr){
						x = j;
						fr = false;
					}
				//	if(n-type[j] >= 0)
						n -= type[j];
				//	cout << "ty" << type[j] << endl;
					j-=1;
				
					cout << "---" << n << endl;
					if( n == 0) count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}

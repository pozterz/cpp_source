#include<iostream>
using namespace std;
int main(){
	
	int n;
	cin >> n;
	string s;
	//cin >> s;
	int i,j;
	for(i = 0,j = 0; j < n; j++,i++){
		if(i == 3) i = 0;
		char c = 'A'+i;
		cout  << c << ", ";
		//cout <<" C%i =" << c << endl << endl;
	}
	cout << endl;
	for(i = 0,j = 0; j < n; j++,i++){
		if(i == 3) i = 0;
		char c;
		if(j%2 == 0) c = 'B';
		else if(j%2 != 0){
			cout << i << ", ";
			continue;
		}
		cout  << c << ", ";
	}
	return 0;
}

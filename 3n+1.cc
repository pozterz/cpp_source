#include<iostream>
#include<algorithm>
using namespace std;
int fm(int i,int j){
	if(j <= 1)
		return 1;
	if(j%2)
		return 1+fm(i,(j*3)+1);
	else
		return 1+fm(i,j/2);
}
int m(int i, int j,int maxx){
	int a = 0;
	int x;
	for(x = j; x >= i; x--){
		a = fm(i,x);
		maxx = max(a,maxx);
	}
	return maxx;
}

int main(){
	
	int i,j;
	int tmpi,tmpj;
	int tmp;
	while(cin >> i >> j){
		tmpi = i;
		tmpj = j;
		if(i > j){
			tmp = i;
			i = j;
			j = tmp;
		}
		cout << tmpi << " " << tmpj << " " << m(i,j,0) << endl;
	}
	
	return 0;
}

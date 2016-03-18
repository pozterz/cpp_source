#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int x[] ={9 ,1 ,9 ,9 ,8 ,2 ,7 ,3 ,7 ,9 ,4 ,9 ,1 ,5 ,3 ,6 ,3 ,2 ,3 ,1 ,8 ,1 ,4 ,1 ,7 ,2 ,9 ,7 ,2, 8, 7};
	sort(x,x+31);
	for(int i =0 ; i < 31; i++)
		cout << x[i] << " ";\

}


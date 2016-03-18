#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<iomanip>
#define MAX 110
using namespace std;
double x[MAX] ={0}, y[MAX] = {0};
bool p[MAX] = {0};

double prim(double x[],double y[],int N){
	int count = 1;
	double weight = 0;
	double min,len,dx,dy;
	int min_index;
	
	p[0] = true;
	
	while(count < N){
		min = -1.0;
		for(int i = 0; i < N; i++)
			if(p[i])
				for(int j = 0; j < N; j++)
					if(!p[j]){
						dx = x[i] - x[j];
						dy = y[i] - y[j];
						len = sqrt( (dx*dx) + (dy*dy));
						if(min == -1.0 || len < min){
							min = len;
							min_index = j;
						}
					}
			p[min_index] = 1;
			weight += min;
			count++;
	}
	return weight;
}
int main(){
	
	int tc,tmp;
	cin >> tc;
	string s;
	getline(cin,s);
	while(tc--){
		int N;
		cin >> N;
		double ans;
		for(int i = 0; i < N; i++){
			cin >> x[i] >> y[i];
		}
		cout << endl;
		ans = prim(x,y,N);
		cout << setprecision(2) << fixed << ans << endl;
	}
	
	return 0;
}

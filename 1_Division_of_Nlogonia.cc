#include<iostream>
using namespace std;
int main(){
	int n;
	pair<int,int> coord,point;
	while(1){
		cin >> n;
		if(n == 0) break;
		cin >> coord.first >> coord.second;
		while(n--){
			cin >> point.first >> point.second;
			if( point.first == coord.first || point.second == coord.second )
				cout << "divisa";
			else if( point.first < coord.first && point.second > coord.second )
				cout << "NO";
			else if( point.first < coord.first && point.second < coord.second )
				cout << "SO";
			else if( point.first > coord.first && point.second > coord.second )
				cout << "NE";
			else if( point.first > coord.first && point.second < coord.second )
				cout << "SE";
		
			cout << endl;
		}	
	}

	
	return 0;
}

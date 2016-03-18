#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
class unf{
	private:
		int *id;
		string *name;
		int *size;
		string root(int i,string a){
			if(i != id[i]){
				id[i] = id[id[i]];
				i = id[i];
			}
		}
	public:
		unf(int N){
			id = new int[N];
			name = new string[N];
			size = new int[N];
			for(int i =0 ; i < N; i++){
				size[i] = 1;
				id[i] = i;
				name[i] = "";
			}
		}

};
int main(){
	int n;
	cin >> n;
	unf q = unf(n);
	string s;
	string st;
	string nd;
	getline(cin,s);
	stringstream ss(s);
	ss >> st >> nd;
	
	
	return 0;
}

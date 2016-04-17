#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;

class WQUPC{
	private:
		int *id,*sz, size;
		int root(int i){
			while( i != id[i] ){
				id[i] = id[id[i]];
				i = id[i];
			}
			return i;
		}
	public:
		WQUPC(int N){
			id = new int[N];
			sz = new int[N];
			size = N;
			for(int i = 0; i < N; i++){
				id[i] = i;
				sz[i] = 1;
			}
		}
		bool find( int p , int q ){
			return root(p) == root(q);
		}
		void unite(int p , int q){
			int x = root(p);
			int y = root(q);
			if(sz[x] < sz[y]){
				id[x] = y;
				sz[y] += sz[x];
			}
			else{
				id[y] = x;
				sz[x] += sz[y];
			}
		}
};
int main(){
	ios_base::sync_with_stdio(false);
	int N;
	int tc;
	cin >> tc;
	while(tc--){
		cin >> N;
		WQUPC uf(N + 1);
		char op;
		int success,fail;
		success = 0;
		fail = 0;
		string s8;
		getline(cin,s8);
		while(1){
			string s;
			getline(cin,s);
			if(s.size() == 0) break;
			stringstream ss(s);
			int p,q;
			ss >> op >> p >> q;
			if(op == 'c'){
				uf.unite(p,q);
			}
			else if(op == 'q'){
				if(uf.find(p,q))
					success++;
				else
					fail++;
			}
			else break;
		}
		cout << success << "," << fail << endl;
		if( tc >= 1 ) cout << endl;
}
	exit(EXIT_SUCCESS);
}

#include<iostream>
#include<algorithm>
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
			for(int i = 0; i <= N; i++){
				id[i] = i;
				sz[i] = 1;
			}
		}
		int largest(int N){
			return *max_element(sz,sz+N);
		}
		bool find(int p,int q){
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
	int N,M;
	int tc;
	cin >> tc;
	while(tc--){
		cin >> N >> M;
		WQUPC uf(N + 1);
		for(int i = 0 ; i < M; i++){
			int p,q;
			cin >> p >> q;
			if(!uf.find(p,q))
				uf.unite(p,q);
		}	
		cout << uf.largest(N-1) << endl;
	}

}

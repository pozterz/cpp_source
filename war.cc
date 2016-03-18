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
			for(int i = 1; i <= N; i++){
				id[i] = i;
			}
		}
		bool find(int p,int q){
			return root(p) == root(q);
		}
		void set_size(int N,int i,int s){
				sz[i] = s;
		}
		int unite(int p , int q){
			int x = root(p);
			int y = root(q);
			int ans;
			if(sz[x] < sz[y]){
				id[x] = y;
				sz[y] += (sz[x]/2);
				sz[x] -= (sz[x]/2);
				ans = x;
			}
			else{
				id[y] = x;
				sz[x] += (sz[y]/2);
				sz[y] -= (sz[y]/2);
				ans = y;
			}
			
			return root(ans);
		}
};
int main(){
	ios_base::sync_with_stdio(false);
	int N,M;
	cin >> N >> M;
	WQUPC uf(N + 1);
	for(int i = 1 ; i <= N; i++){
		int s;
		cin >> s;
		uf.set_size(N,i,s);
	}
	for(int i = 0 ; i < M; i++){
		int p,q;
		cin >> p >> q;
		if(!uf.find(p,q))
			cout << uf.unite(p,q) << endl;
		else cout << "-1" << endl;
	}	
}

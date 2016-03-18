#include<iostream>
using namespace std;

class q_union{
	private:
	int *id,*sz,size;
	int root(int i){
		while(i != id[i]){
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
	
	public:
		q_union(int N){
			id = new int[N],size = N;
			sz = new int[N];
			for(int i = 1; i <= N; i++){
				sz[i] = 1;
				id[i] = i;
			}
			
		}
		bool find(int p , int q){
			return root(p) == root(q);
		}
		void unite(int p,int q){
			int x = root(p);
			int y = root(q);
			if(sz[x] > sz[y]){
				id[x] = y;
				sz[y] += sz[x];
			}
			else{
				id[y] = x;
				sz[x] += sz[y];
			}
		}
		void print(int N){
			cout << "i     ";
			for(int i = 1; i <= N; i++){
				cout << i << " ";  
			}
			cout << endl;
			cout << "id[i] ";
			for(int i = 1; i <= N; i++){
				cout << id[i] << " ";  
			}
			cout << endl;
			cout << "sz[i] ";
			for(int i = 1; i <= N; i++){
				cout << sz[i] << " ";  
			}
			cout << endl;
		}
};
int main(){
	q_union q = q_union(11);
	q.print(10);
	cout << endl;
	q.unite(9,1);
	q.print(10);
	cout << endl;
	cout << q.find(1,9);
}

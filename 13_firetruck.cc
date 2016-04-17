#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
int countt = 0;
int n;
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
		void reset(int n){
			for(int i = 1; i <= n; i++){
				sz[i] = 1;
				id[i] = i;
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
q_union q(21);
// ´fire truck | dfs + union find
void dfs(vector<vector<int> > edge,int current, list<int> ans,vector<bool> visited){
	if(current == n){
		// print list
		list<int>::iterator it = ans.begin();
		for(; it != ans.end(); it++){
			cout << *it << " ";
		}
		cout << n;
		cout << endl;
		countt++;
	}else{
		if(q.find(current,n)){
			if(!visited[current]){
				visited[current] = true;
				ans.push_back(current);
				for(int adj = 0; adj < int(edge[current].size()); adj++){
					dfs(edge,edge[current][adj],ans,visited);
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	int e,v;
	int x = 1;
	vector<vector <int> > edges;
	vector<bool> visited;
	
	bool status = false;
	while(cin >> n){
		visited.assign(21,false);
		edges.assign(21,vector<int>());
		list<int> ans;
		countt = 0;
		int max = 0;
		
		while(cin >> e && cin >> v){
			if(e == 0 && v == 0){
				break;
			}else{
				edges[e].push_back(v);
				edges[v].push_back(e);
				q.unite(e,v);
			}
			max = e>max?e:max;
			max = v>max?v:max;
		}
		
		for(int i = 0; i < max; i++){
			if(i != n)
				sort(edges[i].begin(),edges[i].end());
		}

		cout << "CASE " << x << ":" << endl;
		dfs(edges,1,ans,visited);
		cout << "There are " << countt << " routes from the firestation to streetcorner "<< n <<"." <<endl;
		x++;
		q.reset(21);
	}
	
	
	
	return 0;
}

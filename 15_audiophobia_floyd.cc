#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
typedef pair<int,int> ii;
//Union find
class Unf{
	private:
		vector<int> id;
		vector<int> size;
		int root(int i){
			while(i != id[i]){
				id[i] = id[id[i]];
				i = id[i];
			}
			return i;
		}
	public:
		Unf(int n){
			size.assign(n,1);
			for(int i = 0; i <= n; i++){
				id.push_back(i);
			}
		}
		bool find(int p,int q){
			return root(p) == root(q);
		}
		void unite(int p,int q){
			int x = root(p);
			int y = root(q);
			if(size[x] < size[y]){
				size[y] += size[x];
				id[x] = y;
			}else{
				size[x] += size[y];
				id[y] = x;
			}
		}
};
int main(){
	// audiophobia | Floyd Warshall+Kruskal
	int vertex,edge,q;
	int ccc = 1;
	bool ff = false;
	while(cin >> vertex >> edge >> q){
		if(!vertex && !edge && !q) break;
		else if(ff){
			cout << endl;
		}
		Unf unf(vertex);
		vector<pair<int , ii> > Edgelist;
		vector<pair<int , ii> > MST;
		int v,u,w;
		while(edge--){
			cin >> u >> v >> w;
			Edgelist.push_back(make_pair(w,make_pair(u,v)));	
		}
	
		int max_mst = 0;
		sort(Edgelist.begin(),Edgelist.end());
		for(int i = 0; i < Edgelist.size(); i++){
			pair<int , ii> front = Edgelist[i];
			int W = front.first;
			int U = front.second.first;
			int V = front.second.second;
			if(!unf.find(U,V)){
				unf.unite(U,V);
				MST.push_back(Edgelist[i]);
			}
		}
	
		vector<pair<int,int> > edges[vertex+1];
		int graph[vertex+1][vertex+1];
		
		for(int i = 1; i <= vertex; i++){
			for (int j = 1; j <= vertex; j++)
				graph[i][j] = INT_MAX;
			graph[i][i] = 0;
		}
		
		for(int i = 0; i < MST.size(); i++){
			pair<int , ii> front = MST[i];
			int W = front.first;
			int U = front.second.first;
			int V = front.second.second;
			graph[U][V] = W;
			graph[V][U] = W;
		}
		
		for (int k = 1; k <= vertex; ++k){
			for(int i = 1; i <= vertex; ++i){
				for (int j = 1; j <= vertex; ++j)
					graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
			}
		}
		
		cout << "Case #" << ccc << endl;
		while(q--){
			int s,end;
			cin >> s >> end;
			if(graph[s][end] == INT_MAX)
				cout << "no path" << endl;
			else
				cout << graph[s][end] << endl;
		}
		ccc++;
		ff = true;
	}
}

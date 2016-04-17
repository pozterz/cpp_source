#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

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
			size.assign(n+1,1);
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
// audiophobia | MST | Kruskal
typedef pair<int,int> ii;
int main(){
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
				// make mst list | max_mst cost
				max_mst += W;
				MST.push_back(Edgelist[i]);
			}
		}
	
		vector<pair<int,int> > edges[vertex+1];
		
		for(int i = 0; i < MST.size(); i++){
			pair<int , ii> front = MST[i];
			int W = front.first;
			int U = front.second.first;
			int V = front.second.second;
			edges[U].push_back(make_pair(V,W));
			edges[V].push_back(make_pair(U,W));
		}
		cout << "Case #" << ccc << endl;
		while(q--){
		//	max_mst = 0;
			vector<bool> visited;
			vector<int> weight;
			visited.assign(vertex+1,false);
			weight.assign(vertex+1, 0);
			int s,end;
			cin >> s >> end;
			bool status = false;
			
			// bfs
			queue<int> que;
			que.push(s);
		
			while(!que.empty()){
				int current = que.front();
				que.pop();
				if(current == end){
					status = true;
					break;
				}
				if(!visited[current]){
					visited[current] = true;
					for(size_t i = 0; i < edges[current].size(); i++){
						int adj = edges[current][i].first;
						//cout << "w : "<< edges[current][i].second << endl;
						// max_mst = edges[current][i].second>max_mst?edges[current][i].second:max_mst;
						weight[adj] = max(edges[current][i].second, weight[current]);
						que.push(adj);
					}
				}	
			}
			
			if(status){
				cout << weight[end] << endl;
			}else{
				cout << "no path" << endl;
			}
		}
		ccc++;
		ff = true;
	}
}

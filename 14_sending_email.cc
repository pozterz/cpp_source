#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#define INF 9999999
using namespace std;
typedef pair<int, int> ii;
int main(){
	// sending email | dijkstra shortest path
	int c;
	cin >> c;
	for(int i = 1; i <= c; i++){
		int n,m,S,T;
		cin >> n >> m >> S >> T;
		priority_queue<ii, vector<ii> , greater<ii> > q;
		vector<int> dist;
		vector<pair<int,int> > edges[n];
		dist.assign(n,INF);

			while(m--){
				int u,v,w;
				cin >> u >> v >> w;
				edges[u].push_back(make_pair(v,w));
				edges[v].push_back(make_pair(u,w));
			}
	
			q.push(make_pair(0, S));
			dist[S] = 0;
			while(!q.empty()){
				int current = q.top().second;
				q.pop();
				for(size_t k = 0; k < edges[current].size(); k++){
					int next = edges[current][k].first;
					int next_W = edges[current][k].second;
					if(dist[next] > dist[current]+next_W){
						dist[next] = dist[current] + next_W;
						q.push(make_pair(dist[next], next));
					}
				}
			}
				
		if(dist[S]+dist[T] >= INF)
			cout << "Case #" << i << ": unreachable" << endl;
		else
			cout << "Case #" << i << ": " << dist[S]+dist[T] << endl;
			
	}
	return 0;
}

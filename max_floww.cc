// internet bandwidth | Max flow 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int maxFlow(vector<vii> AdjList, int s, int t);

int main()
{
	vector<vii> AdjList;
	
	int V;
	int n;
	int nw = 1;
	bool fr = false;
	while(cin >> V){
		if(V == 0) break;
	
		++V;
		AdjList.assign(V, vii());
		int s,t,c;
		cin >> s >> t >> c;
		for(int i = 0; i < c; i++){
			int begin,to,capa;
			cin >> begin >> to >> capa;
		//	cout << begin << " : " << "added " << endl;
			AdjList[begin].push_back(make_pair(capa,to));
			AdjList[to].push_back(make_pair(capa,begin));
		}
		cout << "Network " << nw++ << endl;
		cout << "The bandwidth is "<< maxFlow(AdjList, s, t)<< "." << endl;
		cout << endl;
	}

	
	return 0;
}

int maxFlow(vector<vii> AdjList, int s, int t)
{
	int maxflow = 0;
	int V = AdjList.size();
	int residual[V][V];
	
	// Create residual matrix
	memset(residual, 0, sizeof residual);
	for (int u = 0; u < V; u++)
	{
		for (size_t k = 0; k < AdjList[u].size(); k++)
		{
			int v = AdjList[u][k].second;
			int w = AdjList[u][k].first;
			
			residual[u][v] += w;
			//residual[v][u] = w;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
		}
	}
	
	// Edmonds-Karp
	while(1)
	{
		vector<bool> visited;
		vector<int> parent;
		vector<int> bottleneck;
		
		visited.assign(V, false);
		parent.assign(V, -1);
		bottleneck.assign(V, INT_MAX);
		
		// BFS + save path + propagate bottleneck
		queue<int> q;
		q.push(s);
		visited[s] = true;
		
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			
			if (u == t) break; // found the sink node
			
			for (size_t k = 0; k < AdjList[u].size(); k++)
			{
				int v = AdjList[u][k].second;
				int availableFlow = residual[u][v];
				
				if ((availableFlow > 0) && (!visited[v]))
				{
					visited[v] = true;
					parent[v] = u;
					bottleneck[v] = min(bottleneck[u], availableFlow);
					
					q.push(v);
				}
			}
		}
		
		// No more way
		if (!visited[t] || bottleneck[t] == 0)
			break;
		
		// propagate bottleneck
		int k = t;
		while (parent[k] != -1)
		{
		//	cout << k << " <- ";
			residual[parent[k]][k] -= bottleneck[t];
			residual[k][parent[k]] += bottleneck[t];
			
			k = parent[k];
		}
	//	cout << " Bottleneck = " << bottleneck[t] << "\n";
		
		// accumulate flow
		maxflow += bottleneck[t];
	}
	
	return maxflow;
}

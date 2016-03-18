#include<iostream>
#include<climits>
#define INF -1
#define N 5
using namespace std;
int G[N+1][N+1] = { {0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},				
			};
int p[N] = {0};
int minq(int q[],bool mstSet[]){
	int min = INT_MAX, min_index;
	for(int i = 0; i < N; i++){
		if(mstSet[i] == false && q[i] < min)
			min = q[i] , min_index = i;
	}
	return min_index;
}
void prim(int Graph[N+1][N+1],int start){
	int q[N];
	bool mstSet[N];
	
	for(int i = 0; i < N-1; i++){
		 q[i] = INT_MAX;
		 mstSet[i] = false;
	}

	
	q[start] = 0;
	p[start] = -1;
	
	for(int i = 0; i < N-1; i++){
		int u = minq(q,mstSet);
		
		mstSet[u] = true;
		
		for(int v = 0; v < N; v++){
			if(Graph[u][v] && mstSet[v] == false && Graph[u][v] < q[v] )
				p[v] = u,q[v] = Graph[u][v];
		
		}
	}

}
int main(){
	
	prim(G,0);
	cout << "Edge   Weight " << endl;
  	for (int i = 1; i < N; i++)
      cout << p[i] << "-"  << i << "    " <<  G[i][p[i]] << endl;
	return 0;
}

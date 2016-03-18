#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	int c; //case
	int n; // number of car
	int t; // time
	int m; // number of input
	int time[1000];
	int ttime[1000];
	int timein;
	int next;
	int timenow;
	int sidenow;
	int count;
	string s;
	queue<int> q[2];	
	cin >> c;
	while(c--)
	{
		cin >> n >> t >> m;
		timenow = 0;
		sidenow = 0;
		for(int i = 0 ; i < m ; i++)
		{
			cin >> timein >> s;
			time[i] = timein;
			if(s == "left")
				q[0].push(i);
			else
				q[1].push(i);
		}
		
		while( !q[0].empty() || !q[1].empty() )
		{
			if(q[0].empty())
				next = time[q[1].front()];
			else if(q[1].empty())
				next = time[q[0].front()];
			else
				next = min(time[q[0].front()],time[q[1].front()]);
			
			timenow = max(timenow, next);
			count = 0;
		
			while( !q[sidenow].empty() && time[q[sidenow].front()] <= timenow && count < n)
			{
					ttime[q[sidenow].front()] = timenow + t;
					q[sidenow].pop();
					count++;
			}
			timenow += t;
			if(sidenow == 1)
				sidenow = 0;
			else
				sidenow++;
		}
		for(int j = 0 ; j < m ; j++)
			cout << ttime[j] << endl;
		if(c)
			cout << endl;
	}
	
	return 0;
}


#include<iostream>
#include<queue>
#include<sstream>
#include<string>
using namespace std;
// argus || heap
struct st{
	int id;
	int period;
	int time;

	bool operator> (const st& s) const
	{
		if (this->time != s.time)
			return this->time > s.time;
		else
			return this->id > s.id;
	}
};

int main(){
	string s;
	priority_queue<st, vector<st> ,greater<st> > q; // min heap

	while(1){
		getline(cin,s);
		if(s.size() <= 1) break;
		stringstream ss(s);
		int id,period;
		string t;
		ss >> t >> id >> period;
		st s;
		s.id = id;
		s.period = period;
		s.time = period;
		if(t.compare("Register") == 0){
			q.push(s);
		}
		else if(t.compare("#") == 0)
			break;
	}
	int n;
	cin >> n;
	while(n--){
		cout << q.top().id << endl;
		st tmp;
		tmp = q.top();
		tmp.time += tmp.period;
		q.pop();
		q.push(tmp);
	}

	return 0;
}

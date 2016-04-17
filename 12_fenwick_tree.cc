#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
 // potentiometers | Fenwick tree | binary index tree
class Fwtree{
	private:
		vector<int> fw;
		inline int LSOne(int s){
			return s & (-s);
		}
	public:
		Fwtree(){}
		Fwtree(int n){
			fw.assign(n+1,0);
		}
		int rsq(int b){
			int sum = 0;
			while(b > 0){
				sum += fw[b];
				b -= LSOne(b);
			}
			return sum;
		}
		int rsq(int a,int b){
			return rsq(b) - (a <= 1 ? 0:rsq(a-1));
		}
		void adjust(int k, int v){
			while(k < fw.size()){
				fw[k] += v;
				k += LSOne(k);
			}
		}
		void set(int k,int v){
			int diff = v - rsq(k,k);
			adjust(k,diff);
		}
};

int main(){
	
	int n;
	int xn = 1;
	bool fr = true;
	while(1){
		cin >> n;
		if(n == 0) break;
		if(!fr && n != 0){
			cout << endl;
		}
		
		Fwtree fw(n);
		int num;
		for(int i = 1; i <= n; i++){
			cin >> num;
			fw.set(i,num);
		}
		
		cout << "Case " << xn << ":" <<endl;
		while(1){
			string s;
			getline(cin,s);
			if(s != "END"){
				string cm;
				int x,y;
				stringstream ss(s);
				ss >> cm >> x >> y;
				if(cm == "M" && x <= y){
					cout << fw.rsq(x,y) << endl;
				}else if(cm == "S"){
					fw.set(x,y);
				}
			}else break;
		}
		xn++;
		fr = false;
	}
	
	return 0;
}

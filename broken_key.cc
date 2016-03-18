#include<iostream>
#include<list>
using namespace std;
int main(){
	string s;
	while(cin >> s){
		list<char> ch;
		int i = 0;
		list<char>::iterator h = ch.begin();		
		while(s[i] != '\0'){
			if(s[i] == '[')
				h = ch.begin();
			else if(s[i] == ']')
				h = ch.end();
			else
				ch.insert(h,s[i]);
			i++;
		}
		h = ch.begin();
		for(; h != ch.end(); ++h)
			cout << *h;
		cout << endl;
	}

	return 0;
}

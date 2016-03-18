#include<iostream>
#include<cstring>
#include<map>
using namespace std;
int main(){
	string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
	string mir = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	
	map<char,char> alphabet;
	for(int i = 0; i < alp.size(); i++){
		alphabet[alp[i]] = mir[i];
	}
	
	int n;
	char str[21];
	bool palin,mirror;
	
	while(cin >> str){
		
		n = strlen(str);
		palin = mirror = 1;
		for(int i = 0; i < n/2; i++){
			if(str[i] != str[n-1-i]) palin = 0;
			if(str[n-1-i] != alphabet[str[i]]) mirror = 0;
		}
		
		if(palin  && mirror ) cout << str << " -- is a mirrored palindrome.\n\n";
		else if( palin && !mirror ) cout << str << " -- is a regular palindrome.\n\n";
		else if( !palin && mirror ) cout << str << " -- is a mirrored string.\n\n";
		else cout << str << " -- is not a palindrome.\n\n";
		
	}
	return 0;
}

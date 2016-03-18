#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;
int main(){
	
	map<string,int> tree;
	int n;
	char ss[35];
	scanf("%d\n\n",&n);
	
	int x = 0;
	while(n--){
		int tt=0;
		while(gets(ss)){		
			if(!strlen(ss)) break;
			
			if(!tree.count(ss)){
				tree[ss] = 1;
			}else{
				tree[ss] += 1;
			}
			tt++;
		}
		
		map<string,int>::iterator it = tree.begin();
		for(; it != tree.end(); it++)
			printf("%s %.4lf\n",(*it).first.data(),((double)(*it).second/(double)tt)*100);
		
		
		if(n > 0){
			printf("\n");
			tree.clear();	
		}
	}
	
	return 0;
}

#include<iostream>
#include<list>
using namespace std;
int n,m,x,y,col[100000];
bool flag;
list<int> spa[100000];
void search(int go){
	if(flag==1)return;
	for(list<int>::iterator i=spa[go].begin();i!=spa[go].end();i++){
		if(flag==1)return;		
		else if(col[*i]==col[go]){
			flag=1;
			break;
		}
		else if(col[*i])continue;
		else {
			col[*i]=3-col[go];
			search(*i);
		}		
	}
	return;
}
int main(){
	while(scanf("%d",&n)&&n){
		scanf("%d",&m);
		for(int i=0;i<n;i++){			
			spa[i].clear();
			col[i]=0;
		}
		flag=0;
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			spa[x].push_back(y);
			spa[y].push_back(x);
		}
		for(int i=0;i<n;i++){
			if(!col[i]){
				col[i]=1;			
				search(i);
				if(flag==1)break;
			}			
		}
		if(flag==1)printf("RAINBOW.\n");
		else printf("NORMAL.\n");
	}
}

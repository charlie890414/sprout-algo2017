#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;
list<int> quex,quey;
int step[100][100]={0};
bool flag=0,ck=0;
int movex[]={1,0,0,-1},
	movey[]={0,1,-1,0},
	n;
void search(string map[],int x,int y){
	if(flag==1)return;
	for(int i=0;i<4;i++){
		if(map[x+movex[i]][y+movey[i]]=='.'){
			map[x+movex[i]][y+movey[i]]='u';
			step[x+movex[i]][y+movey[i]]=step[x][y]+1;
			quex.push_back(x+movex[i]);
			quey.push_back(y+movey[i]);
		}
		else if(map[x+movex[i]][y+movey[i]]=='@'&&flag==0){
			printf("%d\n",step[x][y]+1);
			flag=1;
		}
	}
	while(!quex.empty()){
		if(flag==1)return;
		int xx=quex.front(),yy=quey.front();
		quex.pop_front();
		quey.pop_front();
		search(map,xx,yy);		
	}
}
int main(){
	while(scanf("%d",&n)){
		if(n==0)break;
		flag=0;
		ck=0;
		quex.clear();
		quey.clear();
		string map[n];
		for(int i=0;i<n;i++){
			cin>>map[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<map[i].size();j++){
				if(map[i][j]=='K'){	
					step[i][j]=0;	
					search(map,i,j);
					ck=1;
					break;
				}
			}
			if(ck==1)break;
		}
		if(flag==0)printf("= =\"\n");
	}
}

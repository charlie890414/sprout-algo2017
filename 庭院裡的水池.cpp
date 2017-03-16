#include<iostream>
using namespace std;
int movex[]={1,0,0,-1},
	movey[]={0,1,-1,0},
	ans,h,w;
void search(string map[],int x,int y){
	map[x][y]='#';
	for(int i=0;i<4;i++){
		int xx=x+movex[i],yy=y+movey[i];
		if(xx>=0&&xx<h&&yy>=0&&yy<w){
			if(map[xx][yy]!='#'){
				search(map,xx,yy);
			}	
		}
	}
	return;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>h>>w;
		string map[h];
		ans=0;		
		for(int i=0;i<h;i++){
			cin>>map[i];
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(map[i][j]!='#'){
					ans++;
					search(map,i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
}

#include<iostream>
#include<vector>
using namespace std;
int ans;
struct node{
	bool used=0;
	vector<int> rode;
};
void count(node map[],int n){
	if(map[n].used)return;
	map[n].used=1;
	for(int i=0;i<map[n].rode.size();i++){
		count(map,map[n].rode[i]); 
	}
	return;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		node map[n];
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			map[x].rode.push_back(y);
			map[y].rode.push_back(x);
		}
		ans=0;
		for(int i=0;i<n;i++){		
			if(map[i].used==1)continue;
			count(map,i);
			ans++;			
		}
		printf("%d\n",ans);
	}
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    vector<int> in;
    int son=-1,max=0,up;
    bool used=0;
};
int t,n,a,b;
int counted(node node[],int i,int up){
	int sum=0;
	node[i].up=up;
	for(int j=0;j<node[i].in.size();j++){
		if(node[i].in[j]!=node[i].up){
			sum+=counted(node,node[i].in[j],i);
			node[i].son=sum;			
		}
    }
    return sum+1;
}
bool rootcount(node node[],int i){
	int mx=0,spa;
	for(int j=0;j<node[i].in.size();j++){
		if(node[i].in[j]!=node[i].up){
			spa=node[node[i].in[j]].son+1;
			mx=max(mx,spa);
		}	
    }
    node[i].max=mx;
    if(max(node[i].max,n-node[i].son-1)<=n/2)return true;
    else return false;    
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		node node[n];
        node[0].used=1;
        for(int i=0;i<n-1;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            node[x].in.push_back(y);
            node[y].in.push_back(x);
        }
		counted(node,0,-1);
		for(int i=0;i<n;i++){
			if(rootcount(node,i)){
				printf("%d\n",i);
				break;
			}
		}
		
	}
}

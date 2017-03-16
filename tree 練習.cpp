#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int sum;
struct node{
    vector<int>point;
    int sum=1;
    bool used=0;
};
int counted(node node[],int i){
    for(int j=0;j<node[i].point.size();j++){
       node[i].sum+=counted(node,node[i].point[j]);
    }
    return node[i].sum;
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        node node[n];
        queue<int>quex,quey;
        node[0].used=1;
        for(int i=0;i<n-1;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            quex.push(x);
			quey.push(y);
        }		
        while(!quex.empty()){
        	int x=quex.front(),y=quey.front();
        	if(node[y].used==1){
                node[y].point.push_back(x);
            	node[x].used=1;
            }
            else if(node[x].used==1){
                node[x].point.push_back(y);                 
            	node[y].used=1;
            }
            else{
            	quex.push(x);
				quey.push(y);	
			}
        	quex.pop();
        	quey.pop();
		}
		counted(node,0);
        for(int i=0;i<n;i++){            
            printf("node %d: %d\n",i,node[i].sum);
        }
    }
}

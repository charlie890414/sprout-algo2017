#include<iostream>
#include<vector>
using namespace std;
struct node{
    vector<int> in;
    int sum=-1;
};
int counted(node node[],int i){        
	if(node[i].sum!=-1)return node[i].sum;
	int sum=1;
    for(int j=0;j<node[i].in.size();j++){
       sum+=counted(node,node[i].in[j]);
    }    
    node[i].sum=sum;
    return sum;
}
int main(){
    int q,t,n,m,x,y;
    scanf("%d" ,&t);
    while(t--){
        scanf("%d %d" ,&m ,&n);
        node node[m+1];
        for(int i=0;i<n;i++){
            scanf("%d %d" ,&x ,&y);
            node[x].in.push_back(y);
        }
        scanf("%d" ,&q);
        for(int i=0;i<q;i++){
        	scanf("%d" ,&x);
            counted(node,x);
            printf("%d\n",node[x].sum);
        }
    }
}

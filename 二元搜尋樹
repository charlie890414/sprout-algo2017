#include<iostream>
using namespace std;
struct node{
	int left=-1,
		right=-1;
};
void push(node node[],int n,int root){
	if(n>root){
		if(node[root].right==-1)node[root].right=n;
		else push(node,n,node[root].right);
	}
	else if(n<root){
		if(node[root].left==-1)node[root].left=n;
		else push(node,n,node[root].left);
	}
}
void counted(node node[],int root){
	if(node[root].left!=-1)counted(node,node[root].left);
	if(node[root].right!=-1)counted(node,node[root].right);
	cout<<root<<endl;
}
int main(){
	int n,root;
	node node[100000];
	scanf("%d",&root);
	while(scanf("%d",&n)!=EOF){
		push(node,n,root);
	}
//	for(int i=0;i<8;i++){
//		cin>>n;
//		push(node,n,root);
//	}
//	cout<<endl;
	counted(node,root);
}

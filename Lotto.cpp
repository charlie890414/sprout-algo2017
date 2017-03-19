#include<iostream>
#include<vector>
using namespace std;
int k,space[13];
vector<int>ans;
void print(){
	for(int i=0;i<5;i++){
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[5]);
	ans.pop_back();
	return;
}
void search(int i,int deep){
	ans.push_back(space[i]);
	if(deep==6){
		print();
		deep--;
		return;
	}
	else {
		deep++;
		for(int j=i+1;j<k;j++){
			search(j,deep);
		}	
		deep--;
		ans.pop_back();
		return;
	}	
}
int main(){
	int j=0;
	while(scanf("%d",&k)&&k){
		if(j++)printf("\n");
		ans.clear();
		for(int i=0;i<k;i++){
			scanf("%d",&space[i]);
		}
		for(int i=0;i<k;i++){
			search(i,1);
		}
	}
}

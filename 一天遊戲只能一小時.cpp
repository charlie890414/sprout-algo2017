#include<iostream>
#include<sstream>
#include<list>
using namespace std;
int main(){
	int n,m,i,j;
	string check;
	scanf("%d %d",&n,&m);
		list<int>que[n];
		for(int k=0;k<=m;k++){
			string move;
			getline(cin, move);
			istringstream sin(move);
			sin>>check>>i>>j;
			if(check=="ADD"){
				que[i-1].push_back(j);
			}
			else if(check=="LEAVE"){
				if(que[i-1].empty())printf("queue %d is empty!\n",i);
				else que[i-1].pop_front();
			}
			else if(check=="JOIN"){
				que[j-1].splice(que[j-1].end(),que[i-1]);				
			}
		}
		for(int i=0;i<n;i++){
			printf("queue %d:",i+1);
			if(que[i].empty())printf(" empty");
			else for(list<int>::iterator k=que[i].begin();k!=que[i].end();k++){
				printf(" %d",*k);
			}
			printf("\n");
		}
		
}

#include<iostream>
#include<list>
using namespace std;
int group[1000000];
int main(){
	int n,count=1,gs;
	while(cin>>n){
		fill(group,group+1000000,-1);
		for(gs=0;gs<n;gs++){
			int t,people;
			scanf("%d",&t);
			for(int j=0;j<t;j++){
				scanf("%d",&people);
				group[people]=gs;
			}
		}
		printf("Line #%d\n",count);count++;
		int group_in_line[gs]={0};
		list<int> line;
		list<int>::iterator it[gs];
		string move;
		while(cin>>move){
			if(move=="ENQUEUE"){
				int people;
				scanf("%d",&people);
				int gp=group[people];
				if(gp>=0){
					if(group_in_line[gp]==0){
						line.push_back(people);
						it[gp]=--line.end();
					}
					else it[gp]=line.insert(++it[gp],people);
					group_in_line[gp]++;
				}
				else line.push_back(people);
			}
			else if(move=="DEQUEUE"){
				printf("%d\n",*line.begin());
				group_in_line[group[*line.begin()]]--;
				line.erase(line.begin());
			}
			else if(move=="STOP")break;
		}
	}
}

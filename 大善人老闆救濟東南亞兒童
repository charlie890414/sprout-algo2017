#include<iostream>
#include <list>
using namespace std;
int main(){	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		list<int> space;
		list<int> last;
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int temp;
			scanf("%d",&temp);
			last.push_back(temp);
		}
		for(int p=1;p<=m;p++){
			space.push_back(p);
			while((space.back()==last.front())&&!last.empty()&&!space.empty()){
				last.pop_front();
				space.pop_back();
			}
		}
		if(!last.empty()&&!space.empty())cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
		
	}
}

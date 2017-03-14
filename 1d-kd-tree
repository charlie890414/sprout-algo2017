#include<iostream>
#include<set>
#include <algorithm>
using namespace std;
int main(){
	int n;
	set<int> node;
	scanf("%d" ,&n);
	while(n--){
		string a;
		int b;
		cin>>a>>b;
		if(a=="insert"){
			node.insert(b);
		}
		else if(a=="delete"){
			node.erase(node.find(b));
		}
		else if(a=="query"){
			if(node.count(b))printf("%d\n",b);
			else {
				set<int>::iterator low,up;
  				low=--node.lower_bound(b);
  				up=node.upper_bound(b);
  				if(abs(*low-b)>abs(*up-b)){
  					printf("%d\n",*up);
				}
				else if(abs(*low-b)<abs(*up-b)){
  					printf("%d\n",*low);
				}
				else printf("%d %d\n",*low ,*up);
			}
		}
	}
}

#include<iostream>
#include<algorithm>
using namespace std;
struct num{
	int e=0,c=0;
};
bool compare(num x,num y){
    return x.e> y.e;
}
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		num num[n];
		for(int i=0;i<n;i++){
			scanf("%d %d",&num[i].c,&num[i].e);
		}
		sort(num,num+n,compare);
		int time=0,ctime=0;
		for (int i=0;i<n;i++){
            ctime+=num[i].c;
            if(time<ctime+num[i].e)time=ctime+num[i].e;
        }
        printf("%d\n",time);
	}
}


#include<iostream>
#include<algorithm>
using namespace std;
long long int t,n,k,a[10000],b[10000],c[10000],v[10000];
bool check(long long int ans){
	int start=0,win=0;
	for (int i=0;i<n;i++){
		v[i]=a[i]+b[i]*ans;
	}		
	sort(v,v+n);
	for (int i=0;i<n;++i){
		while (v[start]<=c[i]){
			start++;
			if(start>=n)break;
		}
		if(start>=n)break;
		win++;
		start++;
		if(win>=k)return true;
	}
	return false;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;		
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
		}
		for(int i=0;i<n;i++){
			cin>>c[i];
		}
		sort(c,c+n);
		long long int ans=100000000,front=0,last=ans;
		if (!check(ans)){
				cout<<-1<<"\n";
				continue;
		}
		while (front<=last){			
			long long int mid=(front+last)/2;
			if (check(mid)){
				if(ans>mid)ans=mid;
				last=mid-1;
			}
			else
				front=mid+1;
		}
		cout<<ans<<"\n";
	}
}


#include<iostream>
#include<cmath>
using namespace std;
int t,n;
double a[10],b[10],c[10];
double S(double time){
	double max=0;
	for(int i=0;i<n;i++){
		if(a[i]*pow((time-b[i]),2)+c[i]>max)max=a[i]*pow((time-b[i]),2)+c[i];	
	}
	return max;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lf %lf %lf",&a[i],&b[i],&c[i]);
		}
		double a=0,b,c,d=300;
		for(int i=0;i<100;++i){
			b=(d-a)/3+a;
			c=d-(d-a)/3;
            if(S(a)<S(b)&&S(b)<S(c)&&S(c)<S(d))d=c;
            else if(S(a)>S(b)&&S(b)>S(c)&&S(c)>S(d))a=b;			
            else if(S(a)>S(b)&&S(b)>S(c)&&S(c)>S(d))a=b;
            else if(S(a)>S(b)&&S(b)<S(c)&&S(c)<S(d))d=c;
            else {
            	a=b;
				d=c;
			}
        }
        printf("%.5lf\n",S(a));
	}
}


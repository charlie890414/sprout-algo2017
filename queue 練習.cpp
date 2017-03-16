#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){	
		int space[n];
		int first=0,last=0;	
    	for(int i=0;i<n;i++){
    		int a;
    		cin>>a;
    		if(a==1){
    			int b;
    			cin>>b;
    			space[last]=b;
    			last++;
			}
    		else if(a==2){
    			if(first==last)cout<<"empty!"<<endl;
    			else{
    				cout<<space[first]<<endl;
    				first++;
				}
			}
		}
	}
}

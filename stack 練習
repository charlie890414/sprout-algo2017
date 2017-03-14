#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){	
		int space[n];
		int top=0;	
    	for(int i=0;i<n;i++){
    		int a;
    		cin>>a;
    		if(a==1){
    			int b;
    			cin>>b;
    			space[top]=b;
    			top++;
			}
    		else if(a==2){
    			if(top==0)cout<<"empty!"<<endl;
    			else{
    				top--;
    				cout<<space[top]<<endl;    				
				}
			}
		}
	}
}

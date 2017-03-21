#include<iostream>
#include<cstring>
using namespace std;
string input;
char map[9][9];
bool ck(){
	int p[9];
	fill(p,p+9,9);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			p[map[i][j]-49]-=1;
		}
	}
	for(int j=0;j<9;j++){
		if(p[j]>0)return false;
	}
	return true;
}
bool check(int x,int y,char num){
	for(int i=0;i<9;i++){
  		if(map[x][i]==num)return false;
  	}  
  	for(int i=0;i<9;i++){
  		if(map[i][y]==num)return false;
	}
  	int blockx=x/3*3,blocky=y/3*3;
  	for(int i=0;i<3;i++){
  		for(int j=0;j<3;j++){
  			if(map[blockx+i][blocky+j]==num)return false;
		}
	}  	  
  	return true;
}
bool search(int wh){
	int x=wh/9,y=wh%9;		 
	if(wh==81)return true;
	if(map[x][y]!='.')return search(wh+1);
	for(int i=0;i<9;i++){
        char num=49+i;        
        if(check(x,y,num)){        	
		    map[x][y]=num;
            if(search(wh+1))return true;            
			map[x][y]='.';
        }
    }
    return false;
}
int main(){
	cin.tie(NULL); 
	while(cin>>input&&input!="end"){
		int k=0;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				map[i][j]=input[k];
				k++;			
			}				
		}
		if(search(0)&&ck()){
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					cout<<map[i][j];
				}
			}
			cout<<"\n";
		}
		else cout<<"No solution.\n";
	}
	return 0;
}


#include<iostream>
using namespace std;
int main(){
	int one,two,three,four,five,six;
	while(cin>>one>>two>>three>>four>>five>>six){
		if(one==0&&two==0&&three==0&&four==0&&five==0&&six==0)return 0;
		int box=six;
		if(five>0){
			box+=five;
			one-=11*five;
		}
		if(four>0){
			box+=four;
			two-=5*four;
		}
		box+=(three/4); 
		if(three%4)box++;
		switch(three%4){ 
        case 0: break;
        case 1:
            two-=5;
            one-=7;
            break;
        case 2:
            two-=3;
            one-=6;
            break;
        case 3:
            two-=1;
            one-=5;
            break;
        }
        if (two>0){   
            box+=two/9;
			if(two%9) box++;
            one-=36-(two%9)*4;
        }
        else if (two<0){
        	one+=two*4;
		}        
        if (one>0){   
            box+=(one/36); 
			if(one%36) box++;
        }
        cout<<box<<'\n';
	}
}


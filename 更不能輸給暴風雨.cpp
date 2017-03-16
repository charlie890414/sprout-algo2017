#include<list>
void solve(int N,int order[]){
	std::list<int> first;
	std::list<int> second;
	std::list<int> third;
	std::list<int> last;
	for(int i=0;i<N;i++){
		last.push_back(order[i]);
	}
	for(int i=1;i<=N;i++){
		first.push_back(i);
	}
	while(!first.empty()){
		if(first.front()==last.front()){
			first.pop_front();
			last.pop_front();
			push_train();
			move_station_1_to_2();
			pop_train();
		}
		else {
			second.push_back(first.front());
			first.pop_front();
			push_train();
		}
	}
	temp:while(!second.empty()){
		if(second.back()==last.front()){
			second.pop_back(); 
			last.pop_front();
			move_station_1_to_2();
			pop_train();
		}
		else {
			third.push_back(second.back());
			second.pop_back(); 
			move_station_1_to_2();
		}
	}
	while(!third.empty()){
		if(third.back()==last.front()){
			third.pop_back(); 
			last.pop_front();
			pop_train();
		}
		else {
			second.push_back(third.back());
			third.pop_back(); 
			move_station_2_to_1();
		}
	}
	if(!third.empty()||!second.empty())goto temp;
	if(!last.empty())no_solution();
};

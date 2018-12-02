#include<bits/stdc++.h>

using namespace std;

class Process{

public:
	int id;
	int b_time;
	int w_time;
	int t_time;
	int pos;
	
	Process(int id, int b){
		this->id = id;
		this->b_time = b;
	}
	
};

void prioritize(vector<Process> &p, vector<int> &order){
	for(int i=0; i<p.size(); i++){
		p[i].pos = (int) (find(order.begin(), order.end(), p[i].id) - order.begin());
	}
}

bool compSjf(Process &p, Process &q){
	if(p.b_time == q.b_time){
		return p.pos < q.pos;
	}
	return p.b_time < q.b_time;
}

bool compFcfs(Process &p, Process &q){
	return p.pos < q.pos;
}

void findWaitingTime(vector<Process>& p){
	
    p[0].w_time = 0;
    for(int  i=1; i<p.size(); i++)
        p[i].w_time =  p[i-1].b_time + p[i-1].w_time;
}

void findTurnAroundTime(vector<Process>& p){
    for(int  i=0; i<p.size(); i++)
        p[i].t_time = p[i].b_time + p[i].w_time;
}

void grantt(vector<Process> &p, int tw_time, int tt_time){
	
	cout << endl << "processes  "<< " burst time  " << " waiting time  " << " turn around time" << endl;

    for(int  i=0; i<p.size(); i++){
        tw_time += p[i].w_time;
        tt_time += p[i].t_time;
        cout << "   " << p[i].id << "\t\t" << p[i].b_time <<"\t    " << p[i].w_time <<"\t\t  " << p[i].t_time << endl;
    }
	cout << "gantt chart:" << endl;
	for(int i=0; i<p.size()-1; i++){
		cout << "(" << p[i].w_time << ")p" << p[i].id;
		for(int j=0; j<p[i].b_time; j++){
			cout << "-";
		}
	}
	cout << "(" << p[p.size()-1].w_time << ")p" << p[p.size()-1].id << endl;
 
    cout << "average waiting time = " << (float)tw_time / (float)p.size() << endl;
    cout << "average turn around time = " << (float)tt_time / (float)p.size() << endl;
	cout << endl;
}

void granttq(queue< pair<int, int> > &q){
	
	cout << "\ngantt chart:\n" << endl;
	int time = 0;
	while(!q.empty()){
		cout << "(" << time << ")" << q.front().first;
		for(int i=0; i<q.front().second; i++){
			cout << "-";
		}
		time += q.front().second;
		q.pop();
	}
	cout << endl;
}

void fcfs(vector<Process>& p){
	
	sort(p.begin(), p.end(), compFscs);
	int tw_time = 0;
	int tt_time = 0;
    findWaitingTime(p);
    findTurnAroundTime(p);
	grantt(p, tw_time, tt_time);
}

void sjf(vector<Process> &p){
	
	sort(p.begin(), p.end(), compSjf);
	int tw_time = 0;
	int tt_time = 0;
    findWaitingTime(p);
    findTurnAroundTime(p);
	grantt(p, tw_time, tt_time);
}

void roundRobin(vector<Process> &p, int roundTime){
	
	sort(p.begin(), p.end(), compSjf);
	queue< pair<int, int> > q; 
	while(true){
		int cnt = 0;
		for(int i=0; i<p.size(); i++){
			if(p[i].b_time > 0){
				if(p[i].b_time > roundTime){
					q.push( make_pair(p[i].id, roundTime) );
					p[i].b_time -= roundTime;
				}
				else{
					q.push( make_pair(p[i].id, p[i].b_time) );
					p[i].b_time = 0;
				}
			}
			else{
				cnt++;
			}
		}
		if(cnt == p.size()){
			break;
		}
	}
	
	granttq(q);
	
}

int main(){
	
	cout << "number of processes:" << endl;
	int n;
	cin >> n;
	vector<Process> _p;
	int id, b_time;
	for(int i=0; i<n; i++){
		cin >> id >> b_time;
		_p.push_back(Process(id, b_time));
	}
	
	cout << "enter the process order:" << endl;
	vector<int> order(n);	
	for(int i=0; i<n; i++){
		cin >> order[i];
	}

	prioritize(_p, order);	
	
//	fcfs(_p);
//	
//	sjf(_p);
	
	cout << "enter the round time:" << endl;
	int r;
	cin >> r;
	roundRobin(_p, r);
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
 
class Process
{
public:
   int pid;
   int bt;
};

class Order
{
public:
   int ord;
   int bt;
};
 
/*bool comparison(Process a, Process b)
{
     return (a.bt < b.bt);
}*/

bool cmp(Order a, Order b)
{
     return (a.bt < b.bt);
}

void findWaitingTime(Order orde[], int n, int wt[])
{
    wt[0] = 0;
 
    for (int i = 1; i < n ; i++ )
        wt[i] = orde[i-1].bt + wt[i-1] ;
}
 
void findTurnAroundTime(Order orde[], int n, int wt[], int tat[])
{

    for (int i = 0; i < n ; i++)
        tat[i] = orde[i].bt + wt[i];
}

void ganttChart(Order orde[], int n, int wt[]){
	cout << endl << endl;  
	for(int i = 0; i < n; i++){
		//int ord = order[i];
		cout << "P[" << orde[i].ord << "]";  
		int w = wt[i+1];
		for(int j = 0; j < w; j++){
			cout << "-";
		}
		//if(i == n - 1)
			//cout << "P[" << ord << "]";		
	}
	
	cout << endl;
	
	for(int i = 0; i < n; i++){
		int w = wt[i];
		for(int j = 0; j <= w+1; j++){
			cout << " ";
		}
		cout << w;	
	}
	
}
 
void findavgTime(Order orde[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    findWaitingTime(orde, n, wt);
 
    findTurnAroundTime(orde, n, wt, tat);
 
    cout << "\nProcesses "<< "Order" << " Burst time "<< " Waiting time " << " Turn around time\n";
 
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        //cout << " " << proc[i].pid << "\t\t"<< proc[i].bt << "\t " << wt[i]<< "\t\t " << tat[i] <<endl;
        cout << "P["<< i+1 << "]" << "\t" << "P[" << orde[i].ord <<"]"<< "\t\t" << orde[i].bt << "\t\t" << wt[orde[i].ord] << "\t\t " << tat[orde[i].ord]  << "\t\t" << endl;
    }
 
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
    
    ganttChart(orde, n, wt);
}
 
int main()
{
    
    int n;
    cout << "Number of process: " << endl;
    cin >> n;
    Process proc[n];
	Order orde[n];
    cout << endl << "Process & Burst Time: " << endl;
    for(int i = 0; i < n; i++){
    	cin >> proc[i].pid >> proc[i].bt;
	}
	cout << endl << "Order" << endl;
	for(int i = 0; i< n; i++){
    	cin >> orde[i].ord;
    	orde[i].bt = proc[orde[i].ord-1].bt;
	}
 	
	sort(orde, orde + n, cmp);	
 	
    findavgTime(orde, n);
    return 0;
}

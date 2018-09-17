#include<iostream>
using namespace std;
 
void findWaitingTime(int order[], int n, int bt[], int wt[])
{
    wt[0] = 0;
 
    for (int  i = 1; i < n ; i++ ){
		int ord = order[i-1];
		wt[i] =  bt[ord-1] + wt[i-1] ;
	}
}
 
void findTurnAroundTime(int order[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void ganttChart(int order[], int n, int wt[]){
	cout << endl << endl;  
	for(int i = 0; i < n; i++){
		int ord = order[i];
		cout << "P[" << ord << "]";  
		int w = wt[ord-1];
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

void findavgTime(int order[], int n, int bt[])
{
    int wt[n], tat[n];
 
    findWaitingTime(order, n, bt, wt);
 
    findTurnAroundTime(order, n, bt, wt, tat);
 
    cout << "Processes " << "Order " << " Burst Time "  << " Waiting Time " << " Turn-Around Time\n";
    int total_wt = 0, total_tat = 0;
    for (int i = 0 ; i < n ; i++)
    {
    	int ord = order[i];
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "P["<< i+1 << "]" << "\t" << "P[" << ord <<"]"<< "\t\t" << bt[i] << "\t\t" << wt[ord] << "\t\t " << tat[ord]  << "\t\t" << endl;
    }
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
         
	ganttChart(order, n, wt);
}

int main()
{
    int n;
    cout << "Number of process: " << endl;
    cin >> n;
    int processes[n], burst_time[n], order[n];
    cout << endl << "Process ID's: " << endl;
    for(int i = 0; i < n; i++){
    	cin >> processes[i];
	}
	cout << endl << "Order" << endl;
	for(int i = 0; i< n; i++){
    	cin >> order[i];
	}
 	cout << endl << "Burst time of all processes: " << endl;

    for(int i = 0; i< n; i++){
    	cin >> burst_time[i];
	}
 
    findavgTime(order, n, burst_time);
 
    return 0;
}

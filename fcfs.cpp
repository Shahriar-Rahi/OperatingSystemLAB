#include<iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;
 
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}
 
void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{

    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void ganttChart(int processes[], int n, int wt[]){
	cout << endl << endl;  
	for(int i = 1; i < n; i++){
		cout << "P[" << i << "]";  
		int w = wt[i];
		for(int j = 0; j < w; j++){
			cout << "-";
		}
		if(i == n - 1)
			cout << "P[" << i+1 << "]";		
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
 
void findavgTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    findWaitingTime(processes, n, bt, wt);
 
    findTurnAroundTime(processes, n, bt, wt, tat);
 
    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";
 
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
         
    ganttChart(processes, n, wt);
}

 
int main()
{
    int processes[] = { 1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
 
    int  burst_time[] = {10, 5, 8};
 
    findavgTime(processes, n,  burst_time);
    return 0;
}

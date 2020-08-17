#include<bits/stdc++.h> 
using namespace std; 
  
struct Process 
{ 
    int ccode;  // course code
    int duration;   // class duration 
    int priority; // Priority 
}; 
  
// Function to sort the classes to highest priority 
bool comparison(Process a, Process b) 
{ 
    return (a.priority > b.priority); 
}  
  
// Function to find the waiting time for all 
// classes
void findWaitingTime(Process proc[], int n, 
                     int wt[]) 
{ 
    // waiting time for first process is 0 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  proc[i-1].duration + wt[i-1] ; 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime( Process proc[], int n, int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int  i = 0; i < n ; i++) 
        tat[i] = proc[i].duration + wt[i]; 
} 
  
//Function to calculate average time 
void findavgTime(Process proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    //Function to find waiting time of all classes
    findWaitingTime(proc, n, wt); 
  
    //Function to find turn around time for all classes 
    findTurnAroundTime(proc, n, wt, tat); 
  
    //Display classes along with all details 
    cout << "\nCourse code  "<< " Duration  "<< " Priority  "
         << " Waiting time  " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn 
    // around time 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << proc[i].ccode << "\t\t"
        << proc[i].duration <<"\t    "<< proc[i].priority <<"\t\t "
        << wt[i] <<"\t\t  " << tat[i] <<endl;
    } 
  
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
} 
  
void priorityScheduling(Process proc[], int n) 
{ 
    // Sort classes schedule by priority 
    sort(proc, proc + n, comparison); 
  
    cout<< "\nOrder in which classes gets executed based on highest to lowest priority\n"; 
    for (int  i = 0 ; i <  n; i++) 
        cout << proc[i].ccode <<" " ; 
  
    findavgTime(proc, n); 
} 
  
// Driver code 
int main() 
{ 
    Process proc[] =  {{2201,3,2}, {3401, 2, 3}, {1103, 1,1}}; 
    int n = sizeof proc / sizeof proc[0]; 
    priorityScheduling(proc, n); 
    return 0; 
} 
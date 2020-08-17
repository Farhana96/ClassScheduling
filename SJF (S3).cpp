//SJF
#include <bits/stdc++.h> 
using namespace std; 
  
struct Process { 
    int ccode; // Process ID 
    int duration; // course code
    int priority;  //priority
}; 

bool comparison(Process a, Process b)
{
    return (a.duration < b.duration);
}

// Function to find the waiting time for all 
// processes 
void findWaitingTime(Process proc[], int n, int wt[]) 
{ 
    int rt[n]; 
  
    // Copy the burst time into rt[] 
    for (int i = 0; i < n; i++) 
        rt[i] = proc[i].duration; 
  
    int complete = 0, t = 0, minm = INT_MAX; 
    int shortest = 0, finish_time; 
    bool check = false; 
  
    // Process until all processes gets 
    // completed 
    while (complete != n) { 
  
        // Find process with minimum 
        // remaining time among the 
        // processes that arrives till the 
        // current time` 
        for (int j = 0; j < n; j++) { 
            if ((proc[j].priority <= t) && 
            (rt[j] < minm) && rt[j] > 0) { 
                minm = rt[j]; 
                shortest = j; 
                check = true; 
            } 
        } 
  
        if (check == false) { 
            t++; 
            continue; 
        } 
  
        // Reduce remaining time by one 
        rt[shortest]--; 
  
        // Update minimum 
        minm = rt[shortest]; 
        if (minm == 0) 
            minm = INT_MAX; 
  
        // If a process gets completely 
        // executed 
        if (rt[shortest] == 0) { 
  
            // Increment complete 
            complete++; 
            check = false; 
  
            // Find finish time of current 
            // process 
            finish_time = t + 1; 
  
            // Calculate waiting time 
            wt[shortest] = finish_time - 
                        proc[shortest].duration - 
                        proc[shortest].priority; 
  
            if (wt[shortest] < 0) 
                wt[shortest] = 0; 
        } 
        // Increment time 
        t++; 
    } 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n; i++) 
        tat[i] = proc[i].duration + wt[i]; 
} 
  
// Function to calculate average time 
void findavgTime(Process proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, 
                    total_tat = 0; 
  
    // Function to find waiting time of all 
    // processes 
    findWaitingTime(proc, n, wt); 
  
    // Function to find turn around time for 
    // all processes 
    findTurnAroundTime(proc, n, wt, tat); 
  
    // Display processes along with all 
    // details 
cout << "\nCourse code  " << "Priority  "<< " Duration  "<< " Waiting time  " << " Turn around time\n";
    // Calculate total waiting time and 
    // total turnaround time 
    for (int i = 0; i < n; i++) { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << proc[i].ccode << "\t\t"<< proc[i].priority <<"\t   "
            << proc[i].duration << "\t\t" << wt[i] 
            << "\t\t" << tat[i] << endl; 
    } 
  
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
}
// Driver code 
int main() 
{ 
    Process proc[] = { {2201,3,2}, {3401, 2,3}, {1103, 1,1} }; 
    int n = sizeof(proc) / sizeof(proc[0]); 
  
    // sorting classes based on class duration
    sort(proc, proc + n, comparison);
 
    cout << "\nOrder in which classes gets executed based on class duration\n";
    for (int i = 0 ; i < n; i++)
    {
        cout << proc[i].ccode <<" ";
    }
    
    findavgTime(proc, n); 
    return 0; 
} 
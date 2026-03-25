// OS Homework 1 - Round Robin Scheduling


//          DEADLINE : 25TH MARCH 2026
/*
    GROUP 8:
    - MEMBER 1: MOHAMMED ABDUL HARIS - U23100877
    - MEMBER 2: HYDYR BABAMURADOV - U22200809
    - MEMBER 3: MUHAMMAD AZHAR - U23102421
    - MEMBER 4: FARIS MUNADHIL AHMED ALAGHA - U23104246
    - MEMBER 5: AKHMAD SAMIR MOSSAVI - U23102307
*/

#include <iostream>
using namespace std;

int main(){

    // ----- Member 1 : Input & Validation ----- Hydyr

    int burstTime[10], prcs, quantum;
    int arrivalTime = 0; // we are assuming all processes arrive at time 0 as per the assignment instructions


    do
    {
        cout << "\nEnter No of Processes: "; // gets the number of processes to be scheduled, must be between 1 and 10
        cin >> prcs;
        cout << endl;
        if (prcs < 1 || prcs > 10)
            cout << "Invalid! Number of processes must be between 1 and 10.\n";
    } while (prcs < 1 || prcs > 10);

    

    for (int i = 0; i < prcs; i++) // for each process, get the burst time (CPU time needed), must be greater than 0
    {
        do
        {
            cout << "P[" << (i + 1) << "]: ";
            cin >> burstTime[i];
            cout << endl;
            if (burstTime[i] <= 0)
                cout << "Invalid! Burst time must be greater than 0.\n";
        } while (burstTime[i] <= 0);
    }


    do
    {
        cout << "Enter Time Quantum: "; // gets the time quantum (time slot for each process), must be greater than 0
        cin >> quantum;
        if (quantum <= 0)
            cout << "Invalid! Time quantum must be greater than 0.\n";
    } while (quantum <= 0);


    // ----- Member 2 : Round Robin Logic -----  Mohammed Abdul Haris

    int remainingTime[10];  // remaining burst time per process
    int completionTime[10]; // time at which each process completes execution
    int currentTime = 0;    // keeps track of the total elapsed CPU time, used to calculate completion times for each process
    bool done = false;

    // Initialize remaining times
    for (int i = 0; i < prcs; i++)
        remainingTime[i] = burstTime[i];

    // Round Robin Scheduling works by giving each process a fixed time quantum in a cyclic order.
    // If a process does not finish within the given quantum, it is paused and moved to the back of the queue.
    // This continues until all processes have completed execution.
    while (!done)
    {
        done = true; // this flag will be set to false if we find any process that still has remaining burst time, initially we assume all processes are done

        for (int i = 0; i < prcs; i++)
        {
            if (remainingTime[i] > 0) // if there is still burst time left for this process that means it's not done
            {
                done = false; // so we flag the variable to false to indicate we still have processes to execute

                if (remainingTime[i] > quantum) // if remaining time is greater than the quantum, we cant execute the process in one go, 
                                                // so we execute it for one quantum and then put it back in the queue
                {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                }
                else
                { // if remaining time is less than or equal to the quantum, we can execute the process in one go and it will finish
                    currentTime += remainingTime[i];
                    remainingTime[i] = 0;
                    completionTime[i] = currentTime; // Record finish time
                }
            }
        }
    }


    // ----- Member 3 :  Turnaround Time  -----  Azhar

    int turnaroundTime[10];     // turnaround time per process (time from arrival to completion)
    for (int i = 0; i < prcs; i++) {
        turnaroundTime[i] = completionTime[i] - arrivalTime;
    }


    // ----- Member 4 :  Waiting Time Calculation & Averages -----  Faris

    int waitingTime[10];        

    double totalWaitTime = 0;
    double totalTurnaroundTime = 0;

    for (int i = 0; i < prcs; i++) {
        waitingTime[i] = turnaroundTime[i] - burstTime[i]; // waiting time for each process (time spent waiting in the ready queue, calculated as turnaround time - burst time)
        
        totalWaitTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    double avgWaitTime = totalWaitTime/prcs;    // average waiting time across all processes
    double avgTurnaroundTime = totalTurnaroundTime/prcs; // average turnaround time across all processes


    // ----- Member 5 : Output Formatting -----  Ahmad

    // cout << "\n=====  Result =====\n";
    // cout << "\nProcess\t\tBurst Time\tCompletion Time\t\tTurnaround Time\t\tWaiting Time\n";
    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";

    for (int i = 0; i < prcs; i++)
    {
        cout <<(i + 1) << "\t\t"
             << burstTime[i] << "\t\t"
             //  << completionTime[i] << "\t\t\t"
             << waitingTime[i] << "\t\t"
             << turnaroundTime[i] << "\n";
    }

    cout << "Average Waiting Time: " << avgWaitTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
    cout<<endl;

    return 0;
}

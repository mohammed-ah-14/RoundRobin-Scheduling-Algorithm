// OS Homework 1 - Round Robin Scheduling
// TODO


//          DEADLINE : 25TH MARCH 2026
/*  
    Group 8: 
    - Member 1: Mohammed Abdul Haris - U23100877
    - Member 2: Hydyr Babamuradov - U22200809
    - Member 3: Muhammad Azhar - U23102421
    - Member 4: [Name] - [ID]
    - Member 5: [Name] - [ID]
*/
 

#include <iostream>
using namespace std;

// ----- Member 1 : Input & Validation ----- Hydyr
// void getInput(int burstTime[], int &n, int &quantum)
// {
//     // Get number of processes with validation
//     do
//     {
//         cout << "Enter number of processes (1-10): ";
//         cin >> n;
//         if (n < 1 || n > 10)
//             cout << "Invalid! Number of processes must be between 1 and 10.\n";
//     } while (n < 1 || n > 10);

//     // Get burst time for each process with validation
//     for (int i = 0; i < n; i++)
//     {
//         do
//         {
//             cout << "Enter burst time for process P" << (i + 1) << ": ";
//             cin >> burstTime[i];
//             if (burstTime[i] <= 0)
//                 cout << "Invalid! Burst time must be greater than 0.\n";
//         } while (burstTime[i] <= 0);
//     }

//     // Get time quantum with validation
//     do
//     {
//         cout << "Enter time quantum: ";
//         cin >> quantum;
//         if (quantum <= 0)
//             cout << "Invalid! Time quantum must be greater than 0.\n";
//     } while (quantum <= 0);
// }

int main(){

    // ----- Member 1 : Input & Validation ----- Hydyr

    int burstTime[10], prcs, quantum;
    int arrivalTime = 0; // we are assuming all processes arrive at time 0 for simplicity

    do
    {
        cout << "Enter number of processes (1-10): ";
        cin >> prcs;
        if (prcs < 1 || prcs > 10)
            cout << "Invalid! Number of processes must be between 1 and 10.\n";
    } while (prcs < 1 || prcs > 10);

    for (int i = 0; i < prcs; i++)
    {
        do
        {
            cout << "Enter burst time for process P" << (i + 1) << ": ";
            cin >> burstTime[i];
            if (burstTime[i] <= 0)
                cout << "Invalid! Burst time must be greater than 0.\n";
        } while (burstTime[i] <= 0);
    }

    // Get time quantum with validation
    do
    {
        cout << "Enter time quantum: ";
        cin >> quantum;
        if (quantum <= 0)
            cout << "Invalid! Time quantum must be greater than 0.\n";
    } while (quantum <= 0);

    // ----- Member 2 : Round Robin Logic -----  Mohammed Haris

    int remainingTime[10];  // remaining burst time per process
    int completionTime[10]; // Azhar and Faris use this to calculate waiting and turnaround times
    int currentTime = 0;    // current time on the CPU clock
    bool done = false;

    // Initialize remaining times
    for (int i = 0; i < prcs; i++)
        remainingTime[i] = burstTime[i];

    // Keep cycling through processes until all are done
    while (!done)
    {
        done = true; // Assume all are done

        for (int i = 0; i < prcs; i++)
        {
            if (remainingTime[i] > 0) // Process still has CPU work left
            {
                done = false; // At least one process is not done yet

                if (remainingTime[i] > quantum)
                {
                    // Process runs for a full quantum, then goes back to queue
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                }
                else
                {
                    // Process finishes within this quantum slot
                    currentTime += remainingTime[i];
                    remainingTime[i] = 0;
                    completionTime[i] = currentTime; // Record finish time
                }
            }
        }
    }

    
    /*.     FOR AZHAR AND FARIS -- FORMULA TO CALCULATE WAITING AND TURNAROUND TIMES.

        turnaroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i]    = turnaroundTime[i] - burstTime[i]; using this formula only becuase of the assumption that all processes arrive at time 0.
    */

    // ----- Member 3 :  Turnaround Time  -----  Azhar

    // ----- Member 4 :  Waiting Time Calculation & Averages -----  Faris

    // ----- Member 5 : Output Formatting -----  Ahmad

    return 0;
}

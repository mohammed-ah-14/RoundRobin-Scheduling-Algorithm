// ----- Member 1 : Input & Validation ----- Hydyr

void getInput(int burstTime[], int &n, int &quantum) 
{ 
    // Get number of processes with validation
    do {
        cout << "Enter number of processes (1-10): ";
        cin >> n;
        if (n < 1 || n > 10)
            cout << "Invalid! Number of processes must be between 1 and 10.\n";
    } while (n < 1 || n > 10);
 
    // Get burst time for each process with validation
    for (int i = 0; i < n; i++) {
        do {
            cout << "Enter burst time for process P" << (i + 1) << ": ";
            cin >> burstTime[i];
            if (burstTime[i] <= 0)
                cout << "Invalid! Burst time must be greater than 0.\n";
        } while (burstTime[i] <= 0);
    }
 
    // Get time quantum with validation
    do {
        cout << "Enter time quantum: ";
        cin >> quantum;
        if (quantum <= 0)
            cout << "Invalid! Time quantum must be greater than 0.\n";
    } while (quantum <= 0);
}

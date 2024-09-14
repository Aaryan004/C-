#include <bits/stdc++.h>
using namespace std;

class Process {
public:
	int pid; // Process ID
	int bt; // Burst Time
	int art; // Arrival Time
};

// Function to find the waiting time for all
// processes
void findWaitingTime(Process proc[], int n, int wt[]) {
    int rt[n];
    for (int i = 0; i < n; i++) {
        rt[i] = proc[i].bt;
    }
    int complete = 0, t = 0;
    while (complete != n) {
        int shortest = -1;
        int minm = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (proc[i].art <= t && rt[i] < minm && rt[i] > 0) {
                minm = rt[i];
                shortest = i;
            }
        }
        if (shortest == -1) {
            t++;
            continue;
        }
        rt[shortest]--;
        if (rt[shortest] == 0) {
            complete++;
            wt[shortest] = t + 1 - proc[shortest].bt - proc[shortest].art;
            if (wt[shortest] < 0) wt[shortest] = 0;
        }
        t++;
    }
}

void findavgTime(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }
    cout << "P\tB\tWT\tTAT" << endl;
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].bt << "\t" << wt[i] << "\t" << tat[i] << endl;
    }
    cout << "Average Waiting Time: " << (float)total_wt / (float)n << endl;
    cout << "Average TurnAround Time: " << (float)total_tat / (float)n << endl;
}

int main()
{
	Process proc[] = { { 1, 6, 2 }, { 2, 2, 5 },
					{ 3, 8, 1 }, { 4, 3, 0}, {5, 4, 4} };
	int n = sizeof(proc) / sizeof(proc[0]);

	findavgTime(proc, n);
	return 0;
}

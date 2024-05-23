#include <stdio.h>

// priority scheduling NON-PREEMPTIVE

int main() {
    int n;
    printf("Enter the number of processes: ");

    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], pri[n], wt[n];
    char name[n][3];

    printf("Enter the name of the process, arrival time, priority, burst time:\n"); 

    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d %d", name[i], &at[i], &pri[i], &bt[i]);
    }
    
    // sorting according to the priority

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (pri[i] > pri[j]) {
                int temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = ct[i];
                ct[i] = ct[j];
                ct[j] = temp;

                for (int k = 0; k < 3; ++k) {
                    char tmp = name[i][k];
                    name[i][k] = name[j][k];
                    name[j][k] = tmp;
                }
            }
            else if (pri[i] == pri[j]) {
                if (at[i] > at[j]) {
                    int temp = at[i];
                    at[i] = at[j];
                    at[j] = temp;

                    temp = bt[i];
                    bt[i] = bt[j];
                    bt[j] = temp;

                    temp = ct[i];
                    ct[i] = ct[j];
                    ct[j] = temp;

                    for (int k = 0; k < 3; ++k) {
                        char tmp = name[i][k];
                        name[i][k] = name[j][k];
                        name[j][k] = tmp;
                    }
    
                }
            }
        }
    }

    int clock = 0;
    int completed = 0;
    int done[n];
    for (int i = 0; i < n; ++i) done[i] = 0;
    
    while(completed < n) {
        int temp = clock;
        for (int i = 0; i < n; ++i) {
            if (at[i] <= clock && !done[i]) {
                ct[i] = clock + bt[i];
                clock = ct[i];
                done[i] = 1;
                completed++;
                break;
            }
        }
        if (clock == temp) clock++;
    }


    // sorting according to name

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (name[i][1] > name[j][1]) {
                int temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = ct[i];
                ct[i] = ct[j];
                ct[j] = temp;

                for (int k = 0; k < 3; ++k) {
                    char tmp = name[i][k];
                    name[i][k] = name[j][k];
                    name[j][k] = tmp;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    
    printf("Process\t\tPriority\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n", name[i], pri[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

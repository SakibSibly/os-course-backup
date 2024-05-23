#include <stdio.h>

int main() {
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], pri[n], ct[n], tat[n], wt[n];
    char name[n][3];

    printf("Enter the corresponding name, arrival time, burst time and priority:\n");

    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d %d", name[i], &at[i], &bt[i], &pri[i]);
    }

    // sorting according to the priority
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // sorting criteria for the output
            if (pri[i] > pri[j]) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = ct[i];
                ct[i] = ct[j];
                ct[j] = temp;

                temp = tat[i];
                tat[i] = tat[j];
                tat[j] = temp;

                temp = wt[i];
                wt[i] = wt[j];
                wt[j] = temp;

                for (int k = 0; k < 3; ++k) {
                    char tmp = name[i][k];
                    name[i][k] = name[j][k];
                    name[j][k] = tmp;
                }
            }
        }
    }

    int clock = 0;
    int done[n];
    for (int i = 0; i < n; ++i) {
        done[i] = 0;
    }
    int completed = 0;


    while(completed < n) {
        int temp = clock;
        for (int i = 0; i < n; ++i) {
            if (at[i] <= clock && !done[i]) {
                ct[i] = clock + bt[i];
                clock = ct[i];
                completed++;
                done[i] = 1;
                break;
            }
        }
        if (clock == temp) {
            clock++;
        }
    }

    for (int i = 0; i < n; ++i) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

// sorting on the basis of process number

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // sorting criteria for the output
            if (name[i][1] > name[j][1]) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;
                
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = ct[i];
                ct[i] = ct[j];
                ct[j] = temp;

                temp = tat[i];
                tat[i] = tat[j];
                tat[j] = temp;

                temp = wt[i];
                wt[i] = wt[j];
                wt[j] = temp;

                for (int k = 0; k < 3; ++k) {
                    char tmp = name[i][k];
                    name[i][k] = name[j][k];
                    name[j][k] = tmp;
                }
            }
        }
    }

    printf("Processes\tPriority\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n", name[i], pri[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
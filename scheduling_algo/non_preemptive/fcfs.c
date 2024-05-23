#include <stdio.h>

int main() {
    printf("Enter the number of processes: ");
    int n;
    scanf("%d", &n);
    printf("Enter their coresponding name, arrival time and burst time:\n");
    char name[n][3];
    int at[n], bt[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d", name[i], &at[i], &bt[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (at[i] > at[j]) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                char tmp;
                for (int k = 0; k < 3; ++k) {
                    tmp = name[i][k];
                    name[i][k] = name[j][k];
                    name[j][k] = tmp;
                }
            }
        }
    }

    int temp = 0;
    int ct[n], tat[n], wt[n];

    for (int i = 0; i < n; ++i) {
        if (temp < at[i]) temp = at[i];
        ct[i] = temp + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        temp = ct[i];
    }
    
    printf("Process\t\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\t\t%d\t%d\t%d\t%d\t%d\n", name[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

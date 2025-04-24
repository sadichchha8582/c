#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[5];
    int deadline;
    int profit;
} Job;

int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

int findMaxDeadline(Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    }
    return max;
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = findMaxDeadline(jobs, n);
    int slot[maxDeadline];
    char jobOrder[maxDeadline][5];
    memset(slot, 0, sizeof(slot));

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
    
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                strcpy(jobOrder[j], jobs[i].id);
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected job sequence for max profit:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i])
            printf("%s ", jobOrder[i]);
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    printf("Enter job details (ID Deadline Profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d:\n", i + 1);
        printf("ID: ");
        scanf("%s", jobs[i].id);
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}

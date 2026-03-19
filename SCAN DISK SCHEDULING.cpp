#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, size, i, j;
    int request[100];
    int totalSeek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    // Sort requests
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(request[j] > request[j + 1]) {
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }

    int index;
    for(i = 0; i < n; i++) {
        if(request[i] >= head) {
            index = i;
            break;
        }
    }

    // Move towards higher end
    for(i = index; i < n; i++) {
        totalSeek += abs(request[i] - head);
        head = request[i];
    }

    // Go to end
    totalSeek += abs((size - 1) - head);
    head = size - 1;

    // Move back
    for(i = index - 1; i >= 0; i--) {
        totalSeek += abs(request[i] - head);
        head = request[i];
    }

    printf("Total Seek Time = %d\n", totalSeek);
    return 0;
}

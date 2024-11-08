#include <iostream>
using namespace std;

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    // Initialize all allocations as -1 (indicating no allocation)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Process each process and find a suitable block
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            // Check if block j is large enough to accommodate process i
            if (blockSize[j] >= processSize[i]) {
                // Find the smallest suitable block
                if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j]) {
                    bestIdx = j;
                }
            }
        }

        // If a suitable block was found, allocate it
        if (bestIdx != -1) {
            allocation[i] = bestIdx;              // Allocate block to process
            blockSize[bestIdx] -= processSize[i]; // Reduce available memory in this block
        }
    }

    // Print the results
    cout << "Process No.\tProcess Size\tBlock no." << endl;
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << allocation[i] + 1 << endl;
        } else {
            cout << "Not Allocated" << endl;
        }
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    bestFit(blockSize, m, processSize, n);

    return 0;
}

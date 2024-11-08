#include <iostream>
using namespace std;

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    // Initialize all allocations as -1 (indicating no allocation)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Process each process
    for (int i = 0; i < n; i++) {
        int worstIdx = -1; // Index of the largest suitable block

        // Find the largest block that can accommodate process i
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        // If a suitable block was found
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i]; // Allocate memory
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

    worstFit(blockSize, m, processSize, n);

    return 0;
}

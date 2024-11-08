#include <iostream>
using namespace std;

void nextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    // Initialize all allocations as -1 (indicating no allocation)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    int j = 0; // Start from the beginning of the block array

    // Process each process
    for (int i = 0; i < n; i++) {
        // Loop through blocks starting from the last allocated position
        int start = j;
        do {
            // Check if block j is large enough to accommodate process i
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;
                blockSize[j] -= processSize[i]; // Reduce available memory in this block
                j = (j + 1) % m; // Move to the next block for the next allocation
                break;
            }
            // Move to the next block in a circular fashion
            j = (j + 1) % m;
        } while (j != start); // Stop if we've looped back to the start position
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

    nextFit(blockSize, m, processSize, n);

    return 0;
}

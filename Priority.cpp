#include <bits/stdc++.h>
using namespace std;

struct Process {
    string pid;
    int arrivalTime;
    int burstTime;
    int priority;
};

void printGanttChart(vector<pair<string, int>>& gantt_chart) {
    cout << "Gantt Chart:\n";
    
    // Print process names with equal spacing
    for (auto& entry : gantt_chart) {
        cout << "| " << entry.first << "\t";
    }
    cout << "|\n";

    // Print timeline with equal spacing
    for (auto& entry : gantt_chart) {
        cout << entry.second << "\t";
    }
    cout << endl;
}

void Priority(vector<Process> processes) {
    int time = 0;
    vector<pair<string, int>> gantt_chart;

    sort(processes.begin(), processes.end(), [](Process &a, Process &b) {
        return a.arrivalTime < b.arrivalTime;
    });

    while (!processes.empty()) {
        vector<Process*> available_process;
        for (auto& process : processes) {
            if (process.arrivalTime <= time) {
                available_process.push_back(&process);
            }
        }
        
        if (available_process.empty()) {
            time++;
            continue;
        }

        auto current_process = min_element(available_process.begin(), available_process.end(), [](Process *a, Process *b) {
            return a->priority < b->priority;
        });

        gantt_chart.push_back({(*current_process)->pid, time});
        time += (*current_process)->burstTime;

        processes.erase(remove_if(processes.begin(), processes.end(), [&](Process &p) {
            return p.pid == (*current_process)->pid;
        }), processes.end());
    }

    gantt_chart.push_back({"END", time});
    printGanttChart(gantt_chart);
}

int main() {
    vector<Process> processes = {
        {"P1", 0, 4, 2},
        {"P2", 1, 3, 1},
        {"P3", 2, 2, 3},
        {"P4", 3, 1, 4}
    };
    
    Priority(processes);
    return 0;
}

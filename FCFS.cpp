#include<bits/stdc++.h>
using namespace std;
struct Process{
    string pid;
    int arrivalTime;
    int burstTime;
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
void FCFS(vector<Process> processes){
    int time=0;
    vector<pair<string,int>> gantt_chart;
    sort(processes.begin(),processes.end(),[](Process &a,Process & b){
        return a.arrivalTime<b.arrivalTime;
    });
    for(auto &process:processes){
        if(time<process.arrivalTime){
            time=process.arrivalTime;
        }
        gantt_chart.emplace_back(process.pid,time);
        time+=process.burstTime;
    }
    gantt_chart.emplace_back("END",time);
    printGanttChart(gantt_chart);
}
int main(){
    vector<Process> processes={
        {"P1",5,0},
        {"P2",3,2},
        {"P3",8,3},
        {"P4",6,5}
    };
    FCFS(processes);
    return 0;
}
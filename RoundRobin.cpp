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
void RoundRobin(vector<Process> processes,int quantam){
    int time=0;
    vector<pair<string,int>> gantt_chart;
    queue<Process*> process_queue;
    for(auto &process:processes){
        process_queue.push(&process);
    }
    while(!process_queue.empty()){
        auto curr_process=process_queue.front();
        process_queue.pop();
        gantt_chart.emplace_back(curr_process->pid,time);
        if(curr_process->burstTime>quantam){
            time+=quantam;
            curr_process->burstTime-=quantam;
            process_queue.push(curr_process);
        }
        else{
            time+=curr_process->burstTime;
            curr_process->burstTime=0;
        }
    }
    gantt_chart.emplace_back("END",time);
    printGanttChart(gantt_chart);
}
int main(){
    vector<Process> processes={
        {"P1",0,5},
        {"P2",1,4},
        {"P3",2,2},
        {"P4",4,1}
    };
    RoundRobin(processes,2);
    return 0;
}
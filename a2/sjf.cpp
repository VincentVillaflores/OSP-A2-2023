#include <iostream>
#include "ReadDataFile.h"
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc != 2){
        std::cerr<<"Error: Datafile is required!"<<std::endl;
        return EXIT_FAILURE;
    }
    else{
        std::deque<pcb> queue = ReadDataFile::ReadThisDataFile(argv[1]);
        std::sort(queue.begin(), queue.end(), [](const pcb& a, const pcb& b) {
            if (a.getBurstTime() == b.getBurstTime()) {
                return a.getID() < b.getID();
            }
            return a.getBurstTime() < b.getBurstTime();
        });

        int numOfProceses = queue.size();
        osp2023::time_type timeElapsed = 0;
        osp2023::time_type totalWaiting = 0;
        osp2023::time_type totalResponse = 0;
        osp2023::time_type totalTurnaround = 0;

        while (!queue.empty()){
            pcb currProcess = queue.front();
            queue.pop_front();

            // waiting time is time elapsed because the process had been waiting in the ready queue 
            osp2023::time_type waitingTime = timeElapsed;

            // response time is just time elapsed because all processes arrive at 0
            osp2023::time_type responseTime = timeElapsed;

            // simulate the process
            timeElapsed += currProcess.getBurstTime();

            // turnaround time is just time elapsed after the process because all processes arrive at 0
            osp2023::time_type turnaroundTime = timeElapsed;

            // print process information
            std::cout << "Process ID: " << currProcess.getID() << std::endl;
            std::cout << "Process Burst Time: " << currProcess.getBurstTime() << std::endl;
            std::cout << "Process Waiting Time: " << waitingTime << std::endl;
            std::cout << "Process Response Time: " << responseTime << std::endl;
            std::cout << "Process Turnaround Time: " << turnaroundTime << std::endl;

            // used to calculate average at the end
            totalWaiting += waitingTime;
            totalResponse += responseTime;
            totalTurnaround += turnaroundTime;
        }

        std::cout << "Average Waiting Time: " << totalWaiting/numOfProceses << std::endl;
        std::cout << "Average Response Time: " << totalResponse/numOfProceses << std::endl;
        std::cout << "Average Turnaround Time: " << totalTurnaround/numOfProceses << std::endl;

        return EXIT_SUCCESS;
    }
}

#include <iostream>
#include "ReadDataFile.h"
#include <algorithm>

int main(int argc, char* argv[]) {
    int quantum = 0;
    try {
        quantum = std::stoi(argv[1]);
    } catch (std::invalid_argument const &e) {
        std::cerr << "Bad input for quantum: std::invalid_argument thrown" << std::endl;
        exit(EXIT_FAILURE);
    } catch (std::out_of_range const &e) {
        std::cerr << "Integer overflow in quantum: std::out_of_range thrown" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (argc != 3){
        std::cerr << "Error: correct input is ./rr [quantum] [datafile]!" << std::endl;
        return EXIT_FAILURE;
    }
    else if (quantum < pcb::MIN_DURATION || quantum > pcb::MAX_DURATION){
        std::cerr << "Error: Invalid quantum! Must be between 10 and 100!" << std::endl;
        return EXIT_FAILURE;
    }
    else{
        std::deque<pcb> queue = ReadDataFile::ReadThisDataFile(argv[2]);

        int numOfProceses = queue.size();
        osp2023::time_type timeElapsed = 0;
        osp2023::time_type totalWaiting = 0;
        osp2023::time_type totalResponse = 0;
        osp2023::time_type totalTurnaround = 0;

        while (!queue.empty()){
            pcb currProcess = queue.front();
            queue.pop_front();

            // waiting time is time elapsed - the last time the process was in the cpu (initially set to 0)
            osp2023::time_type waitingTime = timeElapsed - currProcess.getPreviousTimeInCPU();
            currProcess.addWaitingTime(waitingTime);
            
            // response time is only set on the first time process is in cpu
            if (currProcess.getResponseTime() == osp2023::time_not_set){
                // response time is just time elapsed because all processes arrive at 0
                currProcess.setResponseTime(timeElapsed);
            }
            
            osp2023::time_type timeRemaining = currProcess.getBurstTime() - currProcess.getTimeUsed();

            //simulate quantum
            if (timeRemaining <= quantum){
                timeElapsed += timeRemaining;
                currProcess.addTimeUsed(timeRemaining);

                // process has finished time remaining for process is less than or equal to quantum
                // turnaround time is just time elapsed after the process because all processes arrive at 0
                currProcess.setTurnaroundTime(timeElapsed);

                // print process information
                std::cout << "Process ID: " << currProcess.getID() << std::endl;
                std::cout << "Process Burst Time: " << currProcess.getBurstTime() << std::endl;
                std::cout << "Process Waiting Time: " << currProcess.getWaitingTime() << std::endl;
                std::cout << "Process Response Time: " << currProcess.getResponseTime() << std::endl;
                std::cout << "Process Turnaround Time: " << currProcess.getTurnaroundTime() << std::endl;

                // used to calculate average at the end
                totalWaiting += currProcess.getWaitingTime();
                totalResponse += currProcess.getResponseTime();
                totalTurnaround += currProcess.getTurnaroundTime();


            }
            else {
                timeElapsed += quantum;
                currProcess.addTimeUsed(quantum);

                queue.push_back(currProcess);
            } 
        }

        std::cout << "Average Waiting Time: " << totalWaiting/numOfProceses << std::endl;
        std::cout << "Average Response Time: " << totalResponse/numOfProceses << std::endl;
        std::cout << "Average Turnaround Time: " << totalTurnaround/numOfProceses << std::endl;

        return EXIT_SUCCESS;
    }
}

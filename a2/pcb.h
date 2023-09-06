#include "types.h"

#pragma once  // tells the compiler to only include this file once
              /**
 * the process control block - represents a process that needs to be executed in
 * our simulator. Please note the I used some custom types of osp2023::time_type
 * and osp2023::id_type. these are just aliases to long integers but they are
 * more meaningful type names, hinting at how they will be used. Please see
 * their definitions in types.h.
 **/
class pcb {
    // the unique process id
    osp2023::id_type id;

    // the burst time for the process
    osp2023::time_type burstTime;

    // Turnaround time amount of time to execute a particular task from submission to finish
    osp2023::time_type turnaroundTime;

    // Waiting time amount of time a process has been waiting in the ready queue
    osp2023::time_type waitingTime;

    // Response time amount of time it takes from when a request was submitted until the first response is produced 
    osp2023::time_type responseTime;

    // the time that has been used so far for this process
    osp2023::time_type time_used;

    // what time was this process last on the cpu?
    osp2023::time_type previousTimeInCPU;

   public:
    pcb(osp2023::id_type id, osp2023::time_type burstTime)
        : id(id), burstTime(burstTime), turnaroundTime(0), waitingTime(0), responseTime(0), time_used(0), previousTimeInCPU(0) {}

    // max and min duration for a process in our system.
    static constexpr osp2023::time_type MAX_DURATION = 100;
    static constexpr osp2023::time_type MIN_DURATION = 10;

    osp2023::id_type getID() const {
        return id;
    }

    osp2023::time_type getBurstTime() const {
        return burstTime;
    }

    osp2023::time_type getTurnaroundTime(){
        return turnaroundTime;
    }

    void setTurnaroundTime(osp2023::time_type t){
        turnaroundTime = t;
    }

    osp2023::time_type getWaitingTime(){
        return waitingTime;
    }

    void setWaitingTime(osp2023::time_type t){
        waitingTime = t;
    }

    osp2023::time_type getResponseTime(){
        return responseTime;
    }

    void setResponseTime(osp2023::time_type t){
        responseTime = t;
    }

    osp2023::time_type getPreviousTimeInCPU(){
        return previousTimeInCPU;
    }

    void setPreviousTimeInCPU(osp2023::time_type t){
        previousTimeInCPU = t;
    }

    osp2023::time_type getTimeUsed(){
        return time_used;
    }

    void addTimeUsed(osp2023::time_type t){
        time_used += t;
    }
};

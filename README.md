# OSP-A2-2023

Understanding scheduling is an important skill to have in terms of understanding how operating
system decides which processes use the CUP and how long they get to use them.
Your task in this assignment is to develop a scheduling simulator in C++.

We have provided a random data creator (~e70949/shared/osp2023/creator) to generate input
data for your program. More details can be found at section “About the Generated Data” in page 5.
Given the CUP burst time (in milliseconds) per process, you are going to build a scheduling
simulator in C++ for the following scheduling algorithms on a single CPU system.
• First-In First-Out (FIFO)
• Shortest Job First (SJF)
• Round Robin (RR)

At the completion of the program, your scheduling simulator will display the following stats:
• Average turnaround time – this is the time from when a process is enqueued (first added to the
ready queue) until the process completes.
• Average waiting time – how long on average each process spends waiting in the ready queue.
• Average response time – how long on average each process spends waiting in the ready queue
until the first response is produced.

To help you with this we have provided a PCB (process control block) class that contains information
about an individual process and its progress. The following is a recommended design for your
program:
• A launcher/driver .cpp that parses command line arguments.
• A simulator class that runs the simulation.
• A loader class to load data from the input file.
• A PCB class. You can modify it as needed.

# Ch8 Scheduling: The Multi-Level Feedback Queue

## Contents

Virtualization

- Ch8 Scheduling: The Multi-Level Feedback Queue

    - 8.1 MLFQ: Basic Rules

    - 8.2 Attempt #1: How to Change Priority

        - Example 1: A Single Long-Running Job

        - Example 2: Along Came a Short Job

        - Example 3: What about I/O

        - Problems with Our Current MLFQ

    - 8.3 Attempt #2: The Priority Boost

    - 8.4 Attempt #3: Better Accounting

    - 8.5 Tuning MLFQ and Other Issues

## Homework (Simulation)

### Questions

#### 1

```sh
$ ./mlfq.py -s 0 -n 2 -j 2 -m 10 -M 0
Here is the list of inputs:
OPTIONS jobs 2
OPTIONS queues 2
OPTIONS allotments for queue  1 is   1
OPTIONS quantum length for queue  1 is  10
OPTIONS allotments for queue  0 is   1
OPTIONS quantum length for queue  0 is  10
OPTIONS boost 0
OPTIONS ioTime 5
OPTIONS stayAfterIO False
OPTIONS iobump False


For each job, three defining characteristics are given:
  startTime : at what time does the job enter the system
  runTime   : the total CPU time needed by the job to finish
  ioFreq    : every ioFreq time units, the job issues an I/O
              (the I/O takes ioTime units to complete)

Job List:
  Job  0: startTime   0 - runTime   8 - ioFreq   0
  Job  1: startTime   0 - runTime   4 - ioFreq   0

Compute the execution trace for the given workloads.
If you would like, also compute the response and turnaround
times for each of the jobs.

Use the -c flag to get the exact results when you are finished.
```

```
Execution Trace:

[ time 0 ] JOB BEGINS by JOB 0
[ time 0 ] JOB BEGINS by JOB 1
[ time 0 ] Run JOB 0 at PRIORITY 2 [ TICKS 9 ALLOT 1 TIME 7 (of 8) ]
[ time 1 ] Run JOB 0 at PRIORITY 2 [ TICKS 8 ALLOT 1 TIME 6 (of 8) ]
[ time 2 ] Run JOB 0 at PRIORITY 2 [ TICKS 7 ALLOT 1 TIME 5 (of 8) ]
[ time 3 ] Run JOB 0 at PRIORITY 2 [ TICKS 6 ALLOT 1 TIME 4 (of 8) ]
[ time 4 ] Run JOB 0 at PRIORITY 2 [ TICKS 5 ALLOT 1 TIME 3 (of 8) ]
[ time 5 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 2 (of 8) ]
[ time 6 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 1 (of 8) ]
[ time 7 ] Run JOB 0 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 0 (of 8) ]
[ time 8 ] FINISHED JOB 0
[ time 8 ] Run JOB 1 at PRIORITY 2 [ TICKS 9 ALLOT 1 TIME 3 (of 4) ]
[ time 9 ] Run JOB 1 at PRIORITY 2 [ TICKS 8 ALLOT 1 TIME 2 (of 4) ]
[ time 10 ] Run JOB 1 at PRIORITY 2 [ TICKS 7 ALLOT 1 TIME 1 (of 4) ]
[ time 11 ] Run JOB 1 at PRIORITY 2 [ TICKS 6 ALLOT 1 TIME 0 (of 4) ]
[ time 12 ] FINISHED JOB 1

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround 8
  Job  1: startTime   0 - response   8 - turnaround 12

  Avg  1: startTime n/a - response 4.00 - turnaround 10.00
```

```sh
$ ./mlfq.py -s 0 -n 2 -j 2 -m 20 -M 0
Here is the list of inputs:
OPTIONS jobs 2
OPTIONS queues 2
OPTIONS allotments for queue  1 is   1
OPTIONS quantum length for queue  1 is  10
OPTIONS allotments for queue  0 is   1
OPTIONS quantum length for queue  0 is  10
OPTIONS boost 0
OPTIONS ioTime 5
OPTIONS stayAfterIO False
OPTIONS iobump False


For each job, three defining characteristics are given:
  startTime : at what time does the job enter the system
  runTime   : the total CPU time needed by the job to finish
  ioFreq    : every ioFreq time units, the job issues an I/O
              (the I/O takes ioTime units to complete)

Job List:
  Job  0: startTime   0 - runTime  17 - ioFreq   0
  Job  1: startTime   0 - runTime   8 - ioFreq   0

Compute the execution trace for the given workloads.
If you would like, also compute the response and turnaround
times for each of the jobs.

Use the -c flag to get the exact results when you are finished.
```

```
Execution Trace:

[ time 0 ] JOB BEGINS by JOB 0
[ time 0 ] JOB BEGINS by JOB 1
[ time 0 ] Run JOB 0 at PRIORITY 2 [ TICKS 9 ALLOT 1 TIME 16 (of 17) ]
[ time 1 ] Run JOB 0 at PRIORITY 2 [ TICKS 8 ALLOT 1 TIME 15 (of 17) ]
[ time 2 ] Run JOB 0 at PRIORITY 2 [ TICKS 7 ALLOT 1 TIME 14 (of 17) ]
[ time 3 ] Run JOB 0 at PRIORITY 2 [ TICKS 6 ALLOT 1 TIME 13 (of 17) ]
[ time 4 ] Run JOB 0 at PRIORITY 2 [ TICKS 5 ALLOT 1 TIME 12 (of 17) ]
[ time 5 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 11 (of 17) ]
[ time 6 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 10 (of 17) ]
[ time 7 ] Run JOB 0 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 9 (of 17) ]
[ time 8 ] Run JOB 0 at PRIORITY 2 [ TICKS 1 ALLOT 1 TIME 8 (of 17) ]
[ time 9 ] Run JOB 0 at PRIORITY 2 [ TICKS 0 ALLOT 1 TIME 7 (of 17) ]
[ time 10 ] Run JOB 1 at PRIORITY 2 [ TICKS 8 ALLOT 1 TIME 7 (of 8) ]
[ time 11 ] Run JOB 1 at PRIORITY 2 [ TICKS 8 ALLOT 1 TIME 6 (of 8) ]
[ time 12 ] Run JOB 1 at PRIORITY 2 [ TICKS 7 ALLOT 1 TIME 5 (of 8) ]
[ time 13 ] Run JOB 1 at PRIORITY 2 [ TICKS 6 ALLOT 1 TIME 4 (of 8) ]
[ time 14 ] Run JOB 1 at PRIORITY 2 [ TICKS 5 ALLOT 1 TIME 3 (of 8) ]
[ time 15 ] Run JOB 1 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 2 (of 8) ]
[ time 16 ] Run JOB 1 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 1 (of 8) ]
[ time 17 ] Run JOB 1 at PRIORITY 2 [ TICKS 2 ALLOT 1 TIME 0 (of 8) ]
[ time 18 ] FINISHED JOB 1
[ time 18 ] Run JOB 0 at PRIORITY 2 [ TICKS 9 ALLOT 1 TIME 6 (of 17) ]
[ time 19 ] Run JOB 0 at PRIORITY 2 [ TICKS 8 ALLOT 1 TIME 5 (of 17) ]
[ time 20 ] Run JOB 0 at PRIORITY 2 [ TICKS 7 ALLOT 1 TIME 4 (of 17) ]
[ time 21 ] Run JOB 0 at PRIORITY 2 [ TICKS 6 ALLOT 1 TIME 3 (of 17) ]
[ time 22 ] Run JOB 0 at PRIORITY 2 [ TICKS 5 ALLOT 1 TIME 2 (of 17) ]
[ time 23 ] Run JOB 0 at PRIORITY 2 [ TICKS 4 ALLOT 1 TIME 1 (of 17) ]
[ time 24 ] Run JOB 0 at PRIORITY 2 [ TICKS 3 ALLOT 1 TIME 0 (of 17) ]
[ time 25 ] FINISHED JOB 0

Final statistics:
  Job  0: startTime   0 - response   0 - turnaround 25
  Job  1: startTime   0 - response   10 - turnaround 18

  Avg  1: startTime n/a - response 5.00 - turnaround 21.50
```

#### 2

##### Figure 8.2

```sh
$ ./mlfq.py -n 3 -q 10 -l 0,200,0
```

##### Figure 8.3

```sh
$ ./mlfq.py -n 3 -q 10 -l 0,200,0:100,20,0
```

##### Figure 8.4

```sh
$ ./mlfq.py -n 3 -q 10 -i 5 -l 0,200,0:50,30,1 -S
```

##### Figure 8.5

```sh
$ ./mlfq.py -n 3 -q 10 -i 5 -l 0,200,0:100,50,5:100,50,5 -S
```

```sh
$ ./mlfq.py -n 3 -q 10 -B 50 -i 5 -l 0,200,0:100,50,5:100,50,5 -S
```

##### Figure 8.6

```sh
$ ./mlfq.py -n 3 -q 10 -i 1 -l 0,200,0:80,90,9 -S
```

```sh
$ ./mlfq.py -n 3 -q 10 -i 1 -l 0,200,0:80,90,9
```

##### Figure 8.7

```sh
$ ./mlfq.py -n 3 -a 2 -Q 10,20,40 -j 2 -M 0
```

#### 3

- Set the number of queues 1.

#### 4

```sh
$ ./mlfq.py -n 2 -q 100 -i 1 -l 0,200,99:0,200,0 -S -I
```

#### 5

- Since a longrunning job initially gets 10ms, It should boost every 200ms.

#### 6

```sh
$ ./mlfq.py -n 2 -q 100 -i 1 -l 0,200,99:0,200,0 -S
```

```sh
$ ./mlfq.py -n 2 -q 100 -i 1 -l 0,200,99:0,200,0 -S -I
```

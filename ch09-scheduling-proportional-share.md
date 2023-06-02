# Ch9 Scheduling: Proportional Share

## Contents

Virtualization

- Ch9 Lottery Scheduling

    - 9.1 Basic Concept: Tickets Represent Your Share

    - 9.2 Ticket Mechanixms

    - 9.3 Implementation

    - 9.4 An Example

    - 9.5 How to Assigne Tickets?

    - 9.6 Stride Scheduling

    - 9.7 The Linux Completely Fair Scheduler (CFS)

        - Basic Operation

        -  Weighting (Niceness)

        - Using Red-Black Trees

        - Dealing with I/O and Sleeping Processe

        - Other CFS Fun

    - 9.8 Summary

## Homework (Simulation)

### Questions

#### 1

##### Random seed 1

```sh
$ ./lottery.py -s 1 -j 3
ARG jlist 
ARG jobs 3
ARG maxlen 10
ARG maxticket 100
ARG quantum 1
ARG seed 1

Here is the job list, with the run time of each job: 
  Job 0 ( length = 1, tickets = 84 )
  Job 1 ( length = 7, tickets = 25 )
  Job 2 ( length = 4, tickets = 44 )


Here is the set of random numbers you will need (at most):
Random 651593
Random 788724
Random 93859
Random 28347
Random 835765
Random 432767
Random 762280
Random 2106
Random 445387
Random 721540
Random 228762
Random 945271
```

```
Random 651593 -> Winning ticket 119 (of 153) -> Run 2
  Jobs:  (  job:0 timeleft:1 tix:84 ) (  job:1 timeleft:7 tix:25 ) (* job:2 timeleft:4 tix:44 )
Random 788724 -> Winning ticket 9 (of 153) -> Run 0
  Jobs:  (* job:0 timeleft:1 tix:84 ) (  job:1 timeleft:7 tix:25 ) (  job:2 timeleft:3 tix:44 )
--> JOB 0 DONE at time 2
Random 93859 -> Winning ticket 19 (of 69) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:7 tix:25 ) (  job:2 timeleft:3 tix:44 )
Random 28347 -> Winning ticket 57 (of 69) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:6 tix:25 ) (* job:2 timeleft:3 tix:44 )
Random 835765 -> Winning ticket 37 (of 69) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:6 tix:25 ) (* job:2 timeleft:2 tix:44 )
Random 432767 -> Winning ticket 68 (of 69) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:6 tix:25 ) (* job:2 timeleft:1 tix:44 )
--> JOB 2 DONE at time 6
Random 762280 -> Winning ticket 5 (of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:6 tix:25 ) ( job:2 timeleft:0 tix:---)
Random 2106 -> Winning ticket 6 (of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:5 tix:25 ) ( job:2 timeleft:0 tix:---)
Random 445387 -> Winning ticket 12 (of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:4 tix:25 ) ( job:2 timeleft:0 tix:---)
Random 721540 -> Winning ticket 15 (of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:3 tix:25 ) ( job:2 timeleft:0 tix:---)
Random 228762 -> Winning ticket 12 (of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:2 tix:25 ) ( job:2 timeleft:0 tix:---)
Random 945271 -> Winning ticket 21 (of 25) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:1 tix:25 ) ( job:2 timeleft:0 tix:---)
--> JOB 1 DONE at time 12
```

##### Random seed 2

```sh
$ ./lottery.py -s 2 -j 3
ARG jlist 
ARG jobs 3
ARG maxlen 10
ARG maxticket 100
ARG quantum 1
ARG seed 2

Here is the job list, with the run time of each job: 
  Job 0 ( length = 9, tickets = 94 )
  Job 1 ( length = 8, tickets = 73 )
  Job 2 ( length = 6, tickets = 30 )


Here is the set of random numbers you will need (at most):
Random 605944
Random 606802
Random 581204
Random 158383
Random 430670
Random 393532
Random 723012
Random 994820
Random 949396
Random 544177
Random 444854
Random 268241
Random 35924
Random 27444
Random 464894
Random 318465
Random 380015
Random 891790
Random 525753
Random 560510
Random 236123
Random 23858
Random 325143
```

```
Random 605944 -> Winning ticket 169 (of 197) -> Run 2
  Jobs:  (  job:0 timeleft:9 tix:94 ) (  job:1 timeleft:8 tix:73 ) (* job:2 timeleft:6 tix:30 )
Random 606802 -> Winning ticket 42 (of 197) -> Run 0
  Jobs:  (* job:0 timeleft:9 tix:94 ) (  job:1 timeleft:8 tix:73 ) (  job:2 timeleft:5 tix:30 )
Random 581204 -> Winning ticket 54 (of 197) -> Run 0
  Jobs:  (* job:0 timeleft:8 tix:94 ) (  job:1 timeleft:8 tix:73 ) (  job:2 timeleft:5 tix:30 )
Random 158383 -> Winning ticket 192 (of 197) -> Run 2
  Jobs:  (  job:0 timeleft:7 tix:94 ) (  job:1 timeleft:8 tix:73 ) (* job:2 timeleft:5 tix:30 )
Random 430670 -> Winning ticket 28 (of 197) -> Run 0
  Jobs:  (* job:0 timeleft:7 tix:94 ) (  job:1 timeleft:8 tix:73 ) (  job:2 timeleft:4 tix:30 )
Random 393532 -> Winning ticket 123 (of 197) -> Run 1
  Jobs:  (  job:0 timeleft:6 tix:94 ) (* job:1 timeleft:8 tix:73 ) (  job:2 timeleft:4 tix:30 )
Random 723012 -> Winning ticket 22 (of 197) -> Run 0
  Jobs:  (* job:0 timeleft:6 tix:94 ) (  job:1 timeleft:7 tix:73 ) (  job:2 timeleft:4 tix:30 )
Random 994820 -> Winning ticket 167 (of 197) -> Run 2
  Jobs:  (  job:0 timeleft:5 tix:94 ) (  job:1 timeleft:7 tix:73 ) (* job:2 timeleft:4 tix:30 )
Random 949396 -> Winning ticket 53 (of 197) -> Run 0
  Jobs:  (* job:0 timeleft:5 tix:94 ) (  job:1 timeleft:7 tix:73 ) (  job:2 timeleft:3 tix:30 )
Random 544177 -> Winning ticket 63 (of 197) -> Run 0
  Jobs:  (* job:0 timeleft:4 tix:94 ) (  job:1 timeleft:7 tix:73 ) (  job:2 timeleft:3 tix:30 )
Random 444854 -> Winning ticket 28 (of 197) -> Run 0
  Jobs:  (* job:0 timeleft:3 tix:94 ) (  job:1 timeleft:7 tix:73 ) (  job:2 timeleft:3 tix:30 )
Random 268241 -> Winning ticket 124 (of 197) -> Run 1
  Jobs:  (  job:0 timeleft:2 tix:94 ) (* job:1 timeleft:7 tix:73 ) (  job:2 timeleft:3 tix:30 )
Random 35924 -> Winning ticket 70 (of 197) -> Run 0
  Jobs:  (* job:0 timeleft:2 tix:94 ) (  job:1 timeleft:6 tix:73 ) (  job:2 timeleft:3 tix:30 )
Random 27444 -> Winning ticket 61 (of 197) -> Run 0
  Jobs:  (* job:0 timeleft:1 tix:94 ) (  job:1 timeleft:6 tix:73 ) (  job:2 timeleft:3 tix:30 )
--> JOB 0 DONE at time 14
Random 464894 -> Winning ticket 55 (of 103) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:6 tix:73 ) (  job:2 timeleft:3 tix:30 )
Random 318465 -> Winning ticket 92 (of 103) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:5 tix:73 ) (* job:2 timeleft:3 tix:30 )
Random 380015 -> Winning ticket 48 (of 103) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:5 tix:73 ) (  job:2 timeleft:2 tix:30 )
Random 891790 -> Winning ticket 16 (of 103) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:4 tix:73 ) (  job:2 timeleft:2 tix:30 )
Random 525753 -> Winning ticket 41 (of 103) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:3 tix:73 ) (  job:2 timeleft:2 tix:30 )
Random 560510 -> Winning ticket 87 (of 103) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:2 tix:73 ) (* job:2 timeleft:2 tix:30 )
Random 236123 -> Winning ticket 47 (of 103) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:2 tix:73 ) (  job:2 timeleft:1 tix:30 )
Random 23858 -> Winning ticket 65 (of 103) -> Run 1
  Jobs:  (  job:0 timeleft:0 tix:---) (* job:1 timeleft:1 tix:73 ) (  job:2 timeleft:1 tix:30 )
--> JOB 1 DONE at time 22
Random 325143 -> Winning ticket 3 (of 103) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:0 tix:---) (* job:2 timeleft:1 tix:30 )
--> JOB 2 DONE at time 23
```

##### Random seed 3

```sh
$ ./lottery.py -s 3 -j 3
ARG jlist 
ARG jobs 3
ARG maxlen 10
ARG maxticket 100
ARG quantum 1
ARG seed 3

Here is the job list, with the run time of each job: 
  Job 0 ( length = 2, tickets = 54 )
  Job 1 ( length = 3, tickets = 60 )
  Job 2 ( length = 6, tickets = 6 )


Here is the set of random numbers you will need (at most):
Random 13168
Random 837469
Random 259354
Random 234331
Random 995645
Random 470263
Random 836462
Random 476353
Random 639068
Random 150616
Random 634861
```

[13168, 837469, 259354, 234331, 995645, 470263, 836462, 476353, 639068, 150616, 634861]

```
Random 13168 -> Winning ticket 88 (of 120) -> Run 1
  Jobs:  (  job:0 timeleft:2 tix:54 ) (* job:1 timeleft:3 tix:60 ) (  job:2 timeleft:6 tix:6  )
Random 837469 -> Winning ticket 109 (of 120) -> Run 1
  Jobs:  (  job:0 timeleft:2 tix:54 ) (* job:1 timeleft:2 tix:60 ) (  job:2 timeleft:6 tix:6  )
Random 259354 -> Winning ticket 34 (of 120) -> Run 0
  Jobs:  (* job:0 timeleft:2 tix:54 ) (  job:1 timeleft:1 tix:60 ) (  job:2 timeleft:6 tix:6  )
Random 234331 -> Winning ticket 91 (of 120) -> Run 1
  Jobs:  (  job:0 timeleft:1 tix:54 ) (* job:1 timeleft:1 tix:60 ) (  job:2 timeleft:6 tix:6  )
--> JOB 1 DONE at time 4
Random 995645 -> Winning ticket 5 (of 60) -> Run 0
  Jobs:  (* job:0 timeleft:1 tix:54 ) (  job:1 timeleft:0 tix:---) (  job:2 timeleft:6 tix:6  )
--> JOB 0 DONE at time 5
Random 470263 -> Winning ticket 1 (of 6) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:0 tix:---) (* job:2 timeleft:6 tix:6  )
Random 836462 -> Winning ticket 2 (of 6) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:0 tix:---) (* job:2 timeleft:5 tix:6  )
Random 476353 -> Winning ticket 1 (of 6) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:0 tix:---) (* job:2 timeleft:4 tix:6  )
Random 639068 -> Winning ticket 2 (of 6) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:0 tix:---) (* job:2 timeleft:3 tix:6  )
Random 150616 -> Winning ticket 4 (of 6) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:0 tix:---) (* job:2 timeleft:2 tix:6  )
Random 634861 -> Winning ticket 1 (of 6) -> Run 2
  Jobs:  (  job:0 timeleft:0 tix:---) (  job:1 timeleft:0 tix:---) (* job:2 timeleft:1 tix:6  )
--> JOB 2 DONE at time 11
```

#### 2

```sh
$ ./lottery.py -s 1 -l 10:1,10:100
ARG jlist 10:1,10:100
ARG jobs 3
ARG maxlen 10
ARG maxticket 100
ARG quantum 1
ARG seed 1

Here is the job list, with the run time of each job: 
  Job 0 ( length = 10, tickets = 1 )
  Job 1 ( length = 10, tickets = 100 )


Here is the set of random numbers you will need (at most):
Random 134364
Random 847434
Random 763775
Random 255069
Random 495435
Random 449491
Random 651593
Random 788724
Random 93859
Random 28347
Random 835765
Random 432767
Random 762280
Random 2106
Random 445387
Random 721540
Random 228762
Random 945271
Random 901428
Random 30590
```

[134364, 847434, 763775, 255069, 495435, 449491, 651593, 788724, 93859, 28347, 835765, 432767, 762280, 2106, 445387, 721540, 228762, 945271, 901428, 30590]

```
Random 134364 -> Winning ticket 34 (of 101) -> Run 1
  Jobs:  (  job:0 timeleft:10 tix:1  ) (* job:1 timeleft:10 tix:100)
Random 847434 -> Winning ticket 44 (of 101) -> Run 1
  Jobs:  (  job:0 timeleft:10 tix:1  ) (* job:1 timeleft:9 tix:100)
Random 763775 -> Winning ticket 13 (of 101) -> Run 1
  Jobs:  (  job:0 timeleft:10 tix:1  ) (* job:1 timeleft:8 tix:100)
Random 255069 -> Winning ticket 44 (of 101) -> Run 1
  Jobs:  (  job:0 timeleft:10 tix:1  ) (* job:1 timeleft:7 tix:100)
Random 495435 -> Winning ticket 30 (of 101) -> Run 1
  Jobs:  (  job:0 timeleft:10 tix:1  ) (* job:1 timeleft:6 tix:100)
Random 449491 -> Winning ticket 41 (of 101) -> Run 1
  Jobs:  (  job:0 timeleft:10 tix:1  ) (* job:1 timeleft:5 tix:100)
Random 651593 -> Winning ticket 42 (of 101) -> Run 1
  Jobs:  (  job:0 timeleft:10 tix:1  ) (* job:1 timeleft:4 tix:100)
Random 788724 -> Winning ticket 15 (of 101) -> Run 1
  Jobs:  (  job:0 timeleft:10 tix:1  ) (* job:1 timeleft:3 tix:100)
Random 93859 -> Winning ticket 30 (of 101) -> Run 1
  Jobs:  (  job:0 timeleft:10 tix:1  ) (* job:1 timeleft:2 tix:100)
Random 28347 -> Winning ticket 67 (of 101) -> Run 1
  Jobs:  (  job:0 timeleft:10 tix:1  ) (* job:1 timeleft:1 tix:100)
--> JOB 1 DONE at time 10
Random 835765 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:  (* job:0 timeleft:10 tix:1  ) (  job:1 timeleft:0 tix:---)
Random 432767 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:  (* job:0 timeleft:9 tix:1  ) (  job:1 timeleft:0 tix:---)
Random 762280 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:  (* job:0 timeleft:8 tix:1  ) (  job:1 timeleft:0 tix:---)
Random 2106 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:  (* job:0 timeleft:7 tix:1  ) (  job:1 timeleft:0 tix:---)
Random 445387 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:  (* job:0 timeleft:6 tix:1  ) (  job:1 timeleft:0 tix:---)
Random 721540 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:  (* job:0 timeleft:5 tix:1  ) (  job:1 timeleft:0 tix:---)
Random 228762 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:  (* job:0 timeleft:4 tix:1  ) (  job:1 timeleft:0 tix:---)
Random 945271 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:  (* job:0 timeleft:3 tix:1  ) (  job:1 timeleft:0 tix:---)
Random 901428 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:  (* job:0 timeleft:2 tix:1  ) (  job:1 timeleft:0 tix:---)
Random 30590 -> Winning ticket 0 (of 1) -> Run 0
  Jobs:  (* job:0 timeleft:1 tix:1  ) (  job:1 timeleft:0 tix:---)
--> JOB 0 DONE at time 20
```

- In the random seed 1, job 0 doesn't run before job 1 completes. But the longer the length, the closer to $1/101 \times 100 = 0.99\%$ the chance for job0 to run.

- A ticket imbalance makes unfairness.

#### 3

##### Random seed 1

```sh
$ ./lottery.py -s 1 -l 100:100,100:100 -c
ARG jlist 100:100,100:100
ARG jobs 3
ARG maxlen 10
ARG maxticket 100
ARG quantum 1
ARG seed 1

Here is the job list, with the run time of each job: 
  Job 0 ( length = 100, tickets = 100 )
  Job 1 ( length = 100, tickets = 100 )


** Solutions **

Random 134364 -> Winning ticket 164 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:100 tix:100 )  (* job:1 timeleft:100 tix:100 ) 
Random 847434 -> Winning ticket 34 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:100 tix:100 )  (  job:1 timeleft:99 tix:100 ) 
Random 763775 -> Winning ticket 175 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:99 tix:100 )  (* job:1 timeleft:99 tix:100 ) 
Random 255069 -> Winning ticket 69 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:99 tix:100 )  (  job:1 timeleft:98 tix:100 ) 
Random 495435 -> Winning ticket 35 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:98 tix:100 )  (  job:1 timeleft:98 tix:100 ) 
Random 449491 -> Winning ticket 91 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:97 tix:100 )  (  job:1 timeleft:98 tix:100 ) 
Random 651593 -> Winning ticket 193 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:96 tix:100 )  (* job:1 timeleft:98 tix:100 ) 
Random 788724 -> Winning ticket 124 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:96 tix:100 )  (* job:1 timeleft:97 tix:100 ) 
Random 93859 -> Winning ticket 59 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:96 tix:100 )  (  job:1 timeleft:96 tix:100 ) 
Random 28347 -> Winning ticket 147 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:95 tix:100 )  (* job:1 timeleft:96 tix:100 ) 
Random 835765 -> Winning ticket 165 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:95 tix:100 )  (* job:1 timeleft:95 tix:100 ) 
Random 432767 -> Winning ticket 167 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:95 tix:100 )  (* job:1 timeleft:94 tix:100 ) 
Random 762280 -> Winning ticket 80 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:95 tix:100 )  (  job:1 timeleft:93 tix:100 ) 
Random 2106 -> Winning ticket 106 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:94 tix:100 )  (* job:1 timeleft:93 tix:100 ) 
Random 445387 -> Winning ticket 187 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:94 tix:100 )  (* job:1 timeleft:92 tix:100 ) 
Random 721540 -> Winning ticket 140 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:94 tix:100 )  (* job:1 timeleft:91 tix:100 ) 
Random 228762 -> Winning ticket 162 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:94 tix:100 )  (* job:1 timeleft:90 tix:100 ) 
Random 945271 -> Winning ticket 71 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:94 tix:100 )  (  job:1 timeleft:89 tix:100 ) 
Random 901428 -> Winning ticket 28 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:93 tix:100 )  (  job:1 timeleft:89 tix:100 ) 
Random 30590 -> Winning ticket 190 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:92 tix:100 )  (* job:1 timeleft:89 tix:100 ) 
Random 25445 -> Winning ticket 45 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:92 tix:100 )  (  job:1 timeleft:88 tix:100 ) 
Random 541413 -> Winning ticket 13 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:91 tix:100 )  (  job:1 timeleft:88 tix:100 ) 
Random 939150 -> Winning ticket 150 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:90 tix:100 )  (* job:1 timeleft:88 tix:100 ) 
Random 381204 -> Winning ticket 4 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:90 tix:100 )  (  job:1 timeleft:87 tix:100 ) 
Random 216599 -> Winning ticket 199 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:89 tix:100 )  (* job:1 timeleft:87 tix:100 ) 
Random 422116 -> Winning ticket 116 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:89 tix:100 )  (* job:1 timeleft:86 tix:100 ) 
Random 29040 -> Winning ticket 40 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:89 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 221691 -> Winning ticket 91 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:88 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 437888 -> Winning ticket 88 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:87 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 495812 -> Winning ticket 12 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:86 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 233084 -> Winning ticket 84 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:85 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 230866 -> Winning ticket 66 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:84 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 218781 -> Winning ticket 181 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:83 tix:100 )  (* job:1 timeleft:85 tix:100 ) 
Random 459603 -> Winning ticket 3 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:83 tix:100 )  (  job:1 timeleft:84 tix:100 ) 
Random 289781 -> Winning ticket 181 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:82 tix:100 )  (* job:1 timeleft:84 tix:100 ) 
Random 21489 -> Winning ticket 89 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:82 tix:100 )  (  job:1 timeleft:83 tix:100 ) 
Random 837578 -> Winning ticket 178 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:81 tix:100 )  (* job:1 timeleft:83 tix:100 ) 
Random 556454 -> Winning ticket 54 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:81 tix:100 )  (  job:1 timeleft:82 tix:100 ) 
Random 642295 -> Winning ticket 95 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:80 tix:100 )  (  job:1 timeleft:82 tix:100 ) 
Random 185906 -> Winning ticket 106 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:79 tix:100 )  (* job:1 timeleft:82 tix:100 ) 
Random 992544 -> Winning ticket 144 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:79 tix:100 )  (* job:1 timeleft:81 tix:100 ) 
Random 859947 -> Winning ticket 147 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:79 tix:100 )  (* job:1 timeleft:80 tix:100 ) 
Random 120890 -> Winning ticket 90 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:79 tix:100 )  (  job:1 timeleft:79 tix:100 ) 
Random 332695 -> Winning ticket 95 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:78 tix:100 )  (  job:1 timeleft:79 tix:100 ) 
Random 721485 -> Winning ticket 85 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:77 tix:100 )  (  job:1 timeleft:79 tix:100 ) 
Random 711192 -> Winning ticket 192 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:76 tix:100 )  (* job:1 timeleft:79 tix:100 ) 
Random 936441 -> Winning ticket 41 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:76 tix:100 )  (  job:1 timeleft:78 tix:100 ) 
Random 422107 -> Winning ticket 107 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:75 tix:100 )  (* job:1 timeleft:78 tix:100 ) 
Random 830036 -> Winning ticket 36 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:75 tix:100 )  (  job:1 timeleft:77 tix:100 ) 
Random 670306 -> Winning ticket 106 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:74 tix:100 )  (* job:1 timeleft:77 tix:100 ) 
Random 303368 -> Winning ticket 168 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:74 tix:100 )  (* job:1 timeleft:76 tix:100 ) 
Random 587581 -> Winning ticket 181 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:74 tix:100 )  (* job:1 timeleft:75 tix:100 ) 
Random 882479 -> Winning ticket 79 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:74 tix:100 )  (  job:1 timeleft:74 tix:100 ) 
Random 846198 -> Winning ticket 198 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:73 tix:100 )  (* job:1 timeleft:74 tix:100 ) 
Random 505284 -> Winning ticket 84 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:73 tix:100 )  (  job:1 timeleft:73 tix:100 ) 
Random 589002 -> Winning ticket 2 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:72 tix:100 )  (  job:1 timeleft:73 tix:100 ) 
Random 34525 -> Winning ticket 125 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:71 tix:100 )  (* job:1 timeleft:73 tix:100 ) 
Random 242740 -> Winning ticket 140 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:71 tix:100 )  (* job:1 timeleft:72 tix:100 ) 
Random 797405 -> Winning ticket 5 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:71 tix:100 )  (  job:1 timeleft:71 tix:100 ) 
Random 414314 -> Winning ticket 114 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:70 tix:100 )  (* job:1 timeleft:71 tix:100 ) 
Random 173007 -> Winning ticket 7 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:70 tix:100 )  (  job:1 timeleft:70 tix:100 ) 
Random 548799 -> Winning ticket 199 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:69 tix:100 )  (* job:1 timeleft:70 tix:100 ) 
Random 703041 -> Winning ticket 41 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:69 tix:100 )  (  job:1 timeleft:69 tix:100 ) 
Random 674486 -> Winning ticket 86 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:68 tix:100 )  (  job:1 timeleft:69 tix:100 ) 
Random 374703 -> Winning ticket 103 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:67 tix:100 )  (* job:1 timeleft:69 tix:100 ) 
Random 438962 -> Winning ticket 162 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:67 tix:100 )  (* job:1 timeleft:68 tix:100 ) 
Random 508426 -> Winning ticket 26 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:67 tix:100 )  (  job:1 timeleft:67 tix:100 ) 
Random 778443 -> Winning ticket 43 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:66 tix:100 )  (  job:1 timeleft:67 tix:100 ) 
Random 520938 -> Winning ticket 138 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:65 tix:100 )  (* job:1 timeleft:67 tix:100 ) 
Random 393255 -> Winning ticket 55 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:65 tix:100 )  (  job:1 timeleft:66 tix:100 ) 
Random 489694 -> Winning ticket 94 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:64 tix:100 )  (  job:1 timeleft:66 tix:100 ) 
Random 29574 -> Winning ticket 174 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:63 tix:100 )  (* job:1 timeleft:66 tix:100 ) 
Random 43487 -> Winning ticket 87 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:63 tix:100 )  (  job:1 timeleft:65 tix:100 ) 
Random 703382 -> Winning ticket 182 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:62 tix:100 )  (* job:1 timeleft:65 tix:100 ) 
Random 983188 -> Winning ticket 188 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:62 tix:100 )  (* job:1 timeleft:64 tix:100 ) 
Random 593184 -> Winning ticket 184 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:62 tix:100 )  (* job:1 timeleft:63 tix:100 ) 
Random 393600 -> Winning ticket 0 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:62 tix:100 )  (  job:1 timeleft:62 tix:100 ) 
Random 170349 -> Winning ticket 149 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:61 tix:100 )  (* job:1 timeleft:62 tix:100 ) 
Random 502239 -> Winning ticket 39 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:61 tix:100 )  (  job:1 timeleft:61 tix:100 ) 
Random 982077 -> Winning ticket 77 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:60 tix:100 )  (  job:1 timeleft:61 tix:100 ) 
Random 770523 -> Winning ticket 123 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:59 tix:100 )  (* job:1 timeleft:61 tix:100 ) 
Random 539617 -> Winning ticket 17 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:59 tix:100 )  (  job:1 timeleft:60 tix:100 ) 
Random 860290 -> Winning ticket 90 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:58 tix:100 )  (  job:1 timeleft:60 tix:100 ) 
Random 232176 -> Winning ticket 176 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:57 tix:100 )  (* job:1 timeleft:60 tix:100 ) 
Random 513772 -> Winning ticket 172 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:57 tix:100 )  (* job:1 timeleft:59 tix:100 ) 
Random 952468 -> Winning ticket 68 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:57 tix:100 )  (  job:1 timeleft:58 tix:100 ) 
Random 577795 -> Winning ticket 195 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:56 tix:100 )  (* job:1 timeleft:58 tix:100 ) 
Random 459132 -> Winning ticket 132 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:56 tix:100 )  (* job:1 timeleft:57 tix:100 ) 
Random 269279 -> Winning ticket 79 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:56 tix:100 )  (  job:1 timeleft:56 tix:100 ) 
Random 547996 -> Winning ticket 196 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:55 tix:100 )  (* job:1 timeleft:56 tix:100 ) 
Random 957117 -> Winning ticket 117 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:55 tix:100 )  (* job:1 timeleft:55 tix:100 ) 
Random 5709 -> Winning ticket 109 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:55 tix:100 )  (* job:1 timeleft:54 tix:100 ) 
Random 783656 -> Winning ticket 56 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:55 tix:100 )  (  job:1 timeleft:53 tix:100 ) 
Random 820486 -> Winning ticket 86 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:54 tix:100 )  (  job:1 timeleft:53 tix:100 ) 
Random 886180 -> Winning ticket 180 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:53 tix:100 )  (* job:1 timeleft:53 tix:100 ) 
Random 740504 -> Winning ticket 104 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:53 tix:100 )  (* job:1 timeleft:52 tix:100 ) 
Random 809140 -> Winning ticket 140 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:53 tix:100 )  (* job:1 timeleft:51 tix:100 ) 
Random 518678 -> Winning ticket 78 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:53 tix:100 )  (  job:1 timeleft:50 tix:100 ) 
Random 561358 -> Winning ticket 158 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:52 tix:100 )  (* job:1 timeleft:50 tix:100 ) 
Random 426091 -> Winning ticket 91 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:52 tix:100 )  (  job:1 timeleft:49 tix:100 ) 
Random 56123 -> Winning ticket 123 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:51 tix:100 )  (* job:1 timeleft:49 tix:100 ) 
Random 870011 -> Winning ticket 11 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:51 tix:100 )  (  job:1 timeleft:48 tix:100 ) 
Random 569999 -> Winning ticket 199 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:50 tix:100 )  (* job:1 timeleft:48 tix:100 ) 
Random 199839 -> Winning ticket 39 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:50 tix:100 )  (  job:1 timeleft:47 tix:100 ) 
Random 504720 -> Winning ticket 120 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:49 tix:100 )  (* job:1 timeleft:47 tix:100 ) 
Random 484925 -> Winning ticket 125 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:49 tix:100 )  (* job:1 timeleft:46 tix:100 ) 
Random 356790 -> Winning ticket 190 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:49 tix:100 )  (* job:1 timeleft:45 tix:100 ) 
Random 346078 -> Winning ticket 78 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:49 tix:100 )  (  job:1 timeleft:44 tix:100 ) 
Random 538479 -> Winning ticket 79 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:48 tix:100 )  (  job:1 timeleft:44 tix:100 ) 
Random 623490 -> Winning ticket 90 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:47 tix:100 )  (  job:1 timeleft:44 tix:100 ) 
Random 612453 -> Winning ticket 53 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:46 tix:100 )  (  job:1 timeleft:44 tix:100 ) 
Random 458147 -> Winning ticket 147 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:45 tix:100 )  (* job:1 timeleft:44 tix:100 ) 
Random 27975 -> Winning ticket 175 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:45 tix:100 )  (* job:1 timeleft:43 tix:100 ) 
Random 229605 -> Winning ticket 5 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:45 tix:100 )  (  job:1 timeleft:42 tix:100 ) 
Random 177211 -> Winning ticket 11 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:44 tix:100 )  (  job:1 timeleft:42 tix:100 ) 
Random 584461 -> Winning ticket 61 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:43 tix:100 )  (  job:1 timeleft:42 tix:100 ) 
Random 861009 -> Winning ticket 9 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:42 tix:100 )  (  job:1 timeleft:42 tix:100 ) 
Random 798439 -> Winning ticket 39 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:41 tix:100 )  (  job:1 timeleft:42 tix:100 ) 
Random 797098 -> Winning ticket 98 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:40 tix:100 )  (  job:1 timeleft:42 tix:100 ) 
Random 816438 -> Winning ticket 38 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:39 tix:100 )  (  job:1 timeleft:42 tix:100 ) 
Random 255294 -> Winning ticket 94 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:38 tix:100 )  (  job:1 timeleft:42 tix:100 ) 
Random 841745 -> Winning ticket 145 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:37 tix:100 )  (* job:1 timeleft:42 tix:100 ) 
Random 673114 -> Winning ticket 114 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:37 tix:100 )  (* job:1 timeleft:41 tix:100 ) 
Random 83234 -> Winning ticket 34 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:37 tix:100 )  (  job:1 timeleft:40 tix:100 ) 
Random 16690 -> Winning ticket 90 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:36 tix:100 )  (  job:1 timeleft:40 tix:100 ) 
Random 14559 -> Winning ticket 159 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:35 tix:100 )  (* job:1 timeleft:40 tix:100 ) 
Random 755587 -> Winning ticket 187 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:35 tix:100 )  (* job:1 timeleft:39 tix:100 ) 
Random 249559 -> Winning ticket 159 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:35 tix:100 )  (* job:1 timeleft:38 tix:100 ) 
Random 109488 -> Winning ticket 88 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:35 tix:100 )  (  job:1 timeleft:37 tix:100 ) 
Random 624802 -> Winning ticket 2 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:34 tix:100 )  (  job:1 timeleft:37 tix:100 ) 
Random 344423 -> Winning ticket 23 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:33 tix:100 )  (  job:1 timeleft:37 tix:100 ) 
Random 69515 -> Winning ticket 115 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:32 tix:100 )  (* job:1 timeleft:37 tix:100 ) 
Random 159625 -> Winning ticket 25 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:32 tix:100 )  (  job:1 timeleft:36 tix:100 ) 
Random 527380 -> Winning ticket 180 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:31 tix:100 )  (* job:1 timeleft:36 tix:100 ) 
Random 168145 -> Winning ticket 145 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:31 tix:100 )  (* job:1 timeleft:35 tix:100 ) 
Random 272914 -> Winning ticket 114 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:31 tix:100 )  (* job:1 timeleft:34 tix:100 ) 
Random 711590 -> Winning ticket 190 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:31 tix:100 )  (* job:1 timeleft:33 tix:100 ) 
Random 454702 -> Winning ticket 102 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:31 tix:100 )  (* job:1 timeleft:32 tix:100 ) 
Random 322002 -> Winning ticket 2 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:31 tix:100 )  (  job:1 timeleft:31 tix:100 ) 
Random 473771 -> Winning ticket 171 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:30 tix:100 )  (* job:1 timeleft:31 tix:100 ) 
Random 23634 -> Winning ticket 34 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:30 tix:100 )  (  job:1 timeleft:30 tix:100 ) 
Random 386557 -> Winning ticket 157 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:29 tix:100 )  (* job:1 timeleft:30 tix:100 ) 
Random 420919 -> Winning ticket 119 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:29 tix:100 )  (* job:1 timeleft:29 tix:100 ) 
Random 188039 -> Winning ticket 39 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:29 tix:100 )  (  job:1 timeleft:28 tix:100 ) 
Random 108761 -> Winning ticket 161 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:28 tix:100 )  (* job:1 timeleft:28 tix:100 ) 
Random 899819 -> Winning ticket 19 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:28 tix:100 )  (  job:1 timeleft:27 tix:100 ) 
Random 510116 -> Winning ticket 116 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:27 tix:100 )  (* job:1 timeleft:27 tix:100 ) 
Random 209091 -> Winning ticket 91 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:27 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 605649 -> Winning ticket 49 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:26 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 817040 -> Winning ticket 40 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:25 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 20818 -> Winning ticket 18 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:24 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 17864 -> Winning ticket 64 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:23 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 146461 -> Winning ticket 61 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:22 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 718836 -> Winning ticket 36 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:21 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 160227 -> Winning ticket 27 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:20 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 704606 -> Winning ticket 6 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:19 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 678176 -> Winning ticket 176 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:18 tix:100 )  (* job:1 timeleft:26 tix:100 ) 
Random 544702 -> Winning ticket 102 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:18 tix:100 )  (* job:1 timeleft:25 tix:100 ) 
Random 220599 -> Winning ticket 199 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:18 tix:100 )  (* job:1 timeleft:24 tix:100 ) 
Random 975595 -> Winning ticket 195 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:18 tix:100 )  (* job:1 timeleft:23 tix:100 ) 
Random 797811 -> Winning ticket 11 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:18 tix:100 )  (  job:1 timeleft:22 tix:100 ) 
Random 516600 -> Winning ticket 0 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:17 tix:100 )  (  job:1 timeleft:22 tix:100 ) 
Random 223196 -> Winning ticket 196 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:16 tix:100 )  (* job:1 timeleft:22 tix:100 ) 
Random 648507 -> Winning ticket 107 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:16 tix:100 )  (* job:1 timeleft:21 tix:100 ) 
Random 394898 -> Winning ticket 98 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:16 tix:100 )  (  job:1 timeleft:20 tix:100 ) 
Random 575846 -> Winning ticket 46 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:15 tix:100 )  (  job:1 timeleft:20 tix:100 ) 
Random 321246 -> Winning ticket 46 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:14 tix:100 )  (  job:1 timeleft:20 tix:100 ) 
Random 630948 -> Winning ticket 148 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:13 tix:100 )  (* job:1 timeleft:20 tix:100 ) 
Random 58785 -> Winning ticket 185 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:13 tix:100 )  (* job:1 timeleft:19 tix:100 ) 
Random 298606 -> Winning ticket 6 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:13 tix:100 )  (  job:1 timeleft:18 tix:100 ) 
Random 967904 -> Winning ticket 104 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:18 tix:100 ) 
Random 875535 -> Winning ticket 135 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:17 tix:100 ) 
Random 306386 -> Winning ticket 186 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:16 tix:100 ) 
Random 858515 -> Winning ticket 115 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:15 tix:100 ) 
Random 310363 -> Winning ticket 163 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:14 tix:100 ) 
Random 939289 -> Winning ticket 89 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:12 tix:100 )  (  job:1 timeleft:13 tix:100 ) 
Random 743842 -> Winning ticket 42 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:11 tix:100 )  (  job:1 timeleft:13 tix:100 ) 
Random 416172 -> Winning ticket 172 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:100 )  (* job:1 timeleft:13 tix:100 ) 
Random 252358 -> Winning ticket 158 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:100 )  (* job:1 timeleft:12 tix:100 ) 
Random 8480 -> Winning ticket 80 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:10 tix:100 )  (  job:1 timeleft:11 tix:100 ) 
Random 878718 -> Winning ticket 118 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:9 tix:100 )  (* job:1 timeleft:11 tix:100 ) 
Random 37916 -> Winning ticket 116 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:9 tix:100 )  (* job:1 timeleft:10 tix:100 ) 
Random 819414 -> Winning ticket 14 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:9 tix:100 )  (  job:1 timeleft:9 tix:100 ) 
Random 962202 -> Winning ticket 2 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:8 tix:100 )  (  job:1 timeleft:9 tix:100 ) 
Random 570281 -> Winning ticket 81 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:7 tix:100 )  (  job:1 timeleft:9 tix:100 ) 
Random 171517 -> Winning ticket 117 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:6 tix:100 )  (* job:1 timeleft:9 tix:100 ) 
Random 867781 -> Winning ticket 181 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:6 tix:100 )  (* job:1 timeleft:8 tix:100 ) 
Random 973776 -> Winning ticket 176 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:6 tix:100 )  (* job:1 timeleft:7 tix:100 ) 
Random 704023 -> Winning ticket 23 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:6 tix:100 )  (  job:1 timeleft:6 tix:100 ) 
Random 508874 -> Winning ticket 74 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:5 tix:100 )  (  job:1 timeleft:6 tix:100 ) 
Random 377969 -> Winning ticket 169 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:4 tix:100 )  (* job:1 timeleft:6 tix:100 ) 
Random 346931 -> Winning ticket 131 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:4 tix:100 )  (* job:1 timeleft:5 tix:100 ) 
Random 205761 -> Winning ticket 161 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:4 tix:100 )  (* job:1 timeleft:4 tix:100 ) 
Random 674153 -> Winning ticket 153 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:4 tix:100 )  (* job:1 timeleft:3 tix:100 ) 
Random 432950 -> Winning ticket 150 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:4 tix:100 )  (* job:1 timeleft:2 tix:100 ) 
Random 194118 -> Winning ticket 118 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:4 tix:100 )  (* job:1 timeleft:1 tix:100 ) 
--> JOB 1 DONE at time 196
Random 104424 -> Winning ticket 24 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:4 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 665958 -> Winning ticket 58 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:3 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 296072 -> Winning ticket 72 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:2 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 499800 -> Winning ticket 0 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:1 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
--> JOB 0 DONE at time 200
```

- job1 is done earlier than job0.

- $F = 196/200 = 0.980$

##### Random seed 2

```sh
$ ./lottery.py -s 2 -l 100:100,100:100 -c
ARG jlist 100:100,100:100
ARG jobs 3
ARG maxlen 10
ARG maxticket 100
ARG quantum 1
ARG seed 2

Here is the job list, with the run time of each job: 
  Job 0 ( length = 100, tickets = 100 )
  Job 1 ( length = 100, tickets = 100 )


** Solutions **

Random 956035 -> Winning ticket 35 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:100 tix:100 )  (  job:1 timeleft:100 tix:100 ) 
Random 947828 -> Winning ticket 28 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:99 tix:100 )  (  job:1 timeleft:100 tix:100 ) 
Random 56551 -> Winning ticket 151 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:98 tix:100 )  (* job:1 timeleft:100 tix:100 ) 
Random 84872 -> Winning ticket 72 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:98 tix:100 )  (  job:1 timeleft:99 tix:100 ) 
Random 835499 -> Winning ticket 99 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:97 tix:100 )  (  job:1 timeleft:99 tix:100 ) 
Random 735970 -> Winning ticket 170 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:96 tix:100 )  (* job:1 timeleft:99 tix:100 ) 
Random 669731 -> Winning ticket 131 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:96 tix:100 )  (* job:1 timeleft:98 tix:100 ) 
Random 308136 -> Winning ticket 136 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:96 tix:100 )  (* job:1 timeleft:97 tix:100 ) 
Random 605944 -> Winning ticket 144 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:96 tix:100 )  (* job:1 timeleft:96 tix:100 ) 
Random 606802 -> Winning ticket 2 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:96 tix:100 )  (  job:1 timeleft:95 tix:100 ) 
Random 581204 -> Winning ticket 4 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:95 tix:100 )  (  job:1 timeleft:95 tix:100 ) 
Random 158383 -> Winning ticket 183 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:94 tix:100 )  (* job:1 timeleft:95 tix:100 ) 
Random 430670 -> Winning ticket 70 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:94 tix:100 )  (  job:1 timeleft:94 tix:100 ) 
Random 393532 -> Winning ticket 132 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:93 tix:100 )  (* job:1 timeleft:94 tix:100 ) 
Random 723012 -> Winning ticket 12 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:93 tix:100 )  (  job:1 timeleft:93 tix:100 ) 
Random 994820 -> Winning ticket 20 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:92 tix:100 )  (  job:1 timeleft:93 tix:100 ) 
Random 949396 -> Winning ticket 196 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:91 tix:100 )  (* job:1 timeleft:93 tix:100 ) 
Random 544177 -> Winning ticket 177 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:91 tix:100 )  (* job:1 timeleft:92 tix:100 ) 
Random 444854 -> Winning ticket 54 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:91 tix:100 )  (  job:1 timeleft:91 tix:100 ) 
Random 268241 -> Winning ticket 41 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:90 tix:100 )  (  job:1 timeleft:91 tix:100 ) 
Random 35924 -> Winning ticket 124 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:89 tix:100 )  (* job:1 timeleft:91 tix:100 ) 
Random 27444 -> Winning ticket 44 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:89 tix:100 )  (  job:1 timeleft:90 tix:100 ) 
Random 464894 -> Winning ticket 94 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:88 tix:100 )  (  job:1 timeleft:90 tix:100 ) 
Random 318465 -> Winning ticket 65 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:87 tix:100 )  (  job:1 timeleft:90 tix:100 ) 
Random 380015 -> Winning ticket 15 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:86 tix:100 )  (  job:1 timeleft:90 tix:100 ) 
Random 891790 -> Winning ticket 190 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:85 tix:100 )  (* job:1 timeleft:90 tix:100 ) 
Random 525753 -> Winning ticket 153 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:85 tix:100 )  (* job:1 timeleft:89 tix:100 ) 
Random 560510 -> Winning ticket 110 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:85 tix:100 )  (* job:1 timeleft:88 tix:100 ) 
Random 236123 -> Winning ticket 123 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:85 tix:100 )  (* job:1 timeleft:87 tix:100 ) 
Random 23858 -> Winning ticket 58 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:85 tix:100 )  (  job:1 timeleft:86 tix:100 ) 
Random 325143 -> Winning ticket 143 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:84 tix:100 )  (* job:1 timeleft:86 tix:100 ) 
Random 136697 -> Winning ticket 97 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:84 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 510224 -> Winning ticket 24 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:83 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 998684 -> Winning ticket 84 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:82 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 674480 -> Winning ticket 80 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:81 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 181843 -> Winning ticket 43 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:80 tix:100 )  (  job:1 timeleft:85 tix:100 ) 
Random 893572 -> Winning ticket 172 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:79 tix:100 )  (* job:1 timeleft:85 tix:100 ) 
Random 796760 -> Winning ticket 160 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:79 tix:100 )  (* job:1 timeleft:84 tix:100 ) 
Random 734402 -> Winning ticket 2 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:79 tix:100 )  (  job:1 timeleft:83 tix:100 ) 
Random 906594 -> Winning ticket 194 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:78 tix:100 )  (* job:1 timeleft:83 tix:100 ) 
Random 762886 -> Winning ticket 86 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:78 tix:100 )  (  job:1 timeleft:82 tix:100 ) 
Random 789748 -> Winning ticket 148 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:77 tix:100 )  (* job:1 timeleft:82 tix:100 ) 
Random 353787 -> Winning ticket 187 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:77 tix:100 )  (* job:1 timeleft:81 tix:100 ) 
Random 980977 -> Winning ticket 177 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:77 tix:100 )  (* job:1 timeleft:80 tix:100 ) 
Random 961901 -> Winning ticket 101 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:77 tix:100 )  (* job:1 timeleft:79 tix:100 ) 
Random 161184 -> Winning ticket 184 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:77 tix:100 )  (* job:1 timeleft:78 tix:100 ) 
Random 754004 -> Winning ticket 4 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:77 tix:100 )  (  job:1 timeleft:77 tix:100 ) 
Random 715151 -> Winning ticket 151 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:76 tix:100 )  (* job:1 timeleft:77 tix:100 ) 
Random 461407 -> Winning ticket 7 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:76 tix:100 )  (  job:1 timeleft:76 tix:100 ) 
Random 530356 -> Winning ticket 156 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:75 tix:100 )  (* job:1 timeleft:76 tix:100 ) 
Random 490014 -> Winning ticket 14 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:75 tix:100 )  (  job:1 timeleft:75 tix:100 ) 
Random 924832 -> Winning ticket 32 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:74 tix:100 )  (  job:1 timeleft:75 tix:100 ) 
Random 500841 -> Winning ticket 41 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:73 tix:100 )  (  job:1 timeleft:75 tix:100 ) 
Random 831525 -> Winning ticket 125 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:72 tix:100 )  (* job:1 timeleft:75 tix:100 ) 
Random 353924 -> Winning ticket 124 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:72 tix:100 )  (* job:1 timeleft:74 tix:100 ) 
Random 882851 -> Winning ticket 51 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:72 tix:100 )  (  job:1 timeleft:73 tix:100 ) 
Random 899701 -> Winning ticket 101 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:71 tix:100 )  (* job:1 timeleft:73 tix:100 ) 
Random 461012 -> Winning ticket 12 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:71 tix:100 )  (  job:1 timeleft:72 tix:100 ) 
Random 567705 -> Winning ticket 105 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:70 tix:100 )  (* job:1 timeleft:72 tix:100 ) 
Random 920331 -> Winning ticket 131 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:70 tix:100 )  (* job:1 timeleft:71 tix:100 ) 
Random 723773 -> Winning ticket 173 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:70 tix:100 )  (* job:1 timeleft:70 tix:100 ) 
Random 486609 -> Winning ticket 9 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:70 tix:100 )  (  job:1 timeleft:69 tix:100 ) 
Random 221811 -> Winning ticket 11 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:69 tix:100 )  (  job:1 timeleft:69 tix:100 ) 
Random 324667 -> Winning ticket 67 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:68 tix:100 )  (  job:1 timeleft:69 tix:100 ) 
Random 699572 -> Winning ticket 172 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:67 tix:100 )  (* job:1 timeleft:69 tix:100 ) 
Random 166069 -> Winning ticket 69 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:67 tix:100 )  (  job:1 timeleft:68 tix:100 ) 
Random 907941 -> Winning ticket 141 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:66 tix:100 )  (* job:1 timeleft:68 tix:100 ) 
Random 268137 -> Winning ticket 137 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:66 tix:100 )  (* job:1 timeleft:67 tix:100 ) 
Random 911378 -> Winning ticket 178 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:66 tix:100 )  (* job:1 timeleft:66 tix:100 ) 
Random 309563 -> Winning ticket 163 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:66 tix:100 )  (* job:1 timeleft:65 tix:100 ) 
Random 957362 -> Winning ticket 162 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:66 tix:100 )  (* job:1 timeleft:64 tix:100 ) 
Random 706206 -> Winning ticket 6 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:66 tix:100 )  (  job:1 timeleft:63 tix:100 ) 
Random 504249 -> Winning ticket 49 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:65 tix:100 )  (  job:1 timeleft:63 tix:100 ) 
Random 517748 -> Winning ticket 148 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:64 tix:100 )  (* job:1 timeleft:63 tix:100 ) 
Random 651415 -> Winning ticket 15 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:64 tix:100 )  (  job:1 timeleft:62 tix:100 ) 
Random 587945 -> Winning ticket 145 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:63 tix:100 )  (* job:1 timeleft:62 tix:100 ) 
Random 311844 -> Winning ticket 44 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:63 tix:100 )  (  job:1 timeleft:61 tix:100 ) 
Random 207818 -> Winning ticket 18 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:62 tix:100 )  (  job:1 timeleft:61 tix:100 ) 
Random 511892 -> Winning ticket 92 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:61 tix:100 )  (  job:1 timeleft:61 tix:100 ) 
Random 934155 -> Winning ticket 155 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:60 tix:100 )  (* job:1 timeleft:61 tix:100 ) 
Random 623265 -> Winning ticket 65 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:60 tix:100 )  (  job:1 timeleft:60 tix:100 ) 
Random 75375 -> Winning ticket 175 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:59 tix:100 )  (* job:1 timeleft:60 tix:100 ) 
Random 820400 -> Winning ticket 0 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:59 tix:100 )  (  job:1 timeleft:59 tix:100 ) 
Random 725950 -> Winning ticket 150 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:58 tix:100 )  (* job:1 timeleft:59 tix:100 ) 
Random 907654 -> Winning ticket 54 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:58 tix:100 )  (  job:1 timeleft:58 tix:100 ) 
Random 191402 -> Winning ticket 2 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:57 tix:100 )  (  job:1 timeleft:58 tix:100 ) 
Random 744783 -> Winning ticket 183 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:56 tix:100 )  (* job:1 timeleft:58 tix:100 ) 
Random 58758 -> Winning ticket 158 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:56 tix:100 )  (* job:1 timeleft:57 tix:100 ) 
Random 652910 -> Winning ticket 110 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:56 tix:100 )  (* job:1 timeleft:56 tix:100 ) 
Random 273100 -> Winning ticket 100 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:56 tix:100 )  (* job:1 timeleft:55 tix:100 ) 
Random 226616 -> Winning ticket 16 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:56 tix:100 )  (  job:1 timeleft:54 tix:100 ) 
Random 875492 -> Winning ticket 92 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:55 tix:100 )  (  job:1 timeleft:54 tix:100 ) 
Random 106266 -> Winning ticket 66 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:54 tix:100 )  (  job:1 timeleft:54 tix:100 ) 
Random 522363 -> Winning ticket 163 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:53 tix:100 )  (* job:1 timeleft:54 tix:100 ) 
Random 853943 -> Winning ticket 143 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:53 tix:100 )  (* job:1 timeleft:53 tix:100 ) 
Random 244832 -> Winning ticket 32 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:53 tix:100 )  (  job:1 timeleft:52 tix:100 ) 
Random 210479 -> Winning ticket 79 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:52 tix:100 )  (  job:1 timeleft:52 tix:100 ) 
Random 880582 -> Winning ticket 182 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:51 tix:100 )  (* job:1 timeleft:52 tix:100 ) 
Random 422918 -> Winning ticket 118 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:51 tix:100 )  (* job:1 timeleft:51 tix:100 ) 
Random 716961 -> Winning ticket 161 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:51 tix:100 )  (* job:1 timeleft:50 tix:100 ) 
Random 31873 -> Winning ticket 73 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:51 tix:100 )  (  job:1 timeleft:49 tix:100 ) 
Random 362357 -> Winning ticket 157 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:50 tix:100 )  (* job:1 timeleft:49 tix:100 ) 
Random 171881 -> Winning ticket 81 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:50 tix:100 )  (  job:1 timeleft:48 tix:100 ) 
Random 672766 -> Winning ticket 166 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:49 tix:100 )  (* job:1 timeleft:48 tix:100 ) 
Random 82903 -> Winning ticket 103 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:49 tix:100 )  (* job:1 timeleft:47 tix:100 ) 
Random 954563 -> Winning ticket 163 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:49 tix:100 )  (* job:1 timeleft:46 tix:100 ) 
Random 25344 -> Winning ticket 144 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:49 tix:100 )  (* job:1 timeleft:45 tix:100 ) 
Random 729424 -> Winning ticket 24 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:49 tix:100 )  (  job:1 timeleft:44 tix:100 ) 
Random 21144 -> Winning ticket 144 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:48 tix:100 )  (* job:1 timeleft:44 tix:100 ) 
Random 255690 -> Winning ticket 90 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:48 tix:100 )  (  job:1 timeleft:43 tix:100 ) 
Random 813355 -> Winning ticket 155 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:47 tix:100 )  (* job:1 timeleft:43 tix:100 ) 
Random 157118 -> Winning ticket 118 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:47 tix:100 )  (* job:1 timeleft:42 tix:100 ) 
Random 183738 -> Winning ticket 138 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:47 tix:100 )  (* job:1 timeleft:41 tix:100 ) 
Random 691496 -> Winning ticket 96 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:47 tix:100 )  (  job:1 timeleft:40 tix:100 ) 
Random 385566 -> Winning ticket 166 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:46 tix:100 )  (* job:1 timeleft:40 tix:100 ) 
Random 43161 -> Winning ticket 161 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:46 tix:100 )  (* job:1 timeleft:39 tix:100 ) 
Random 990002 -> Winning ticket 2 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:46 tix:100 )  (  job:1 timeleft:38 tix:100 ) 
Random 151420 -> Winning ticket 20 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:45 tix:100 )  (  job:1 timeleft:38 tix:100 ) 
Random 36269 -> Winning ticket 69 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:44 tix:100 )  (  job:1 timeleft:38 tix:100 ) 
Random 344201 -> Winning ticket 1 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:43 tix:100 )  (  job:1 timeleft:38 tix:100 ) 
Random 615240 -> Winning ticket 40 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:42 tix:100 )  (  job:1 timeleft:38 tix:100 ) 
Random 742460 -> Winning ticket 60 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:41 tix:100 )  (  job:1 timeleft:38 tix:100 ) 
Random 113115 -> Winning ticket 115 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:40 tix:100 )  (* job:1 timeleft:38 tix:100 ) 
Random 337214 -> Winning ticket 14 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:40 tix:100 )  (  job:1 timeleft:37 tix:100 ) 
Random 30810 -> Winning ticket 10 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:39 tix:100 )  (  job:1 timeleft:37 tix:100 ) 
Random 448653 -> Winning ticket 53 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:38 tix:100 )  (  job:1 timeleft:37 tix:100 ) 
Random 765970 -> Winning ticket 170 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:37 tix:100 )  (* job:1 timeleft:37 tix:100 ) 
Random 739947 -> Winning ticket 147 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:37 tix:100 )  (* job:1 timeleft:36 tix:100 ) 
Random 902021 -> Winning ticket 21 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:37 tix:100 )  (  job:1 timeleft:35 tix:100 ) 
Random 755662 -> Winning ticket 62 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:36 tix:100 )  (  job:1 timeleft:35 tix:100 ) 
Random 862446 -> Winning ticket 46 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:35 tix:100 )  (  job:1 timeleft:35 tix:100 ) 
Random 705345 -> Winning ticket 145 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:34 tix:100 )  (* job:1 timeleft:35 tix:100 ) 
Random 472779 -> Winning ticket 179 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:34 tix:100 )  (* job:1 timeleft:34 tix:100 ) 
Random 225527 -> Winning ticket 127 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:34 tix:100 )  (* job:1 timeleft:33 tix:100 ) 
Random 660829 -> Winning ticket 29 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:34 tix:100 )  (  job:1 timeleft:32 tix:100 ) 
Random 316306 -> Winning ticket 106 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:33 tix:100 )  (* job:1 timeleft:32 tix:100 ) 
Random 102049 -> Winning ticket 49 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:33 tix:100 )  (  job:1 timeleft:31 tix:100 ) 
Random 447822 -> Winning ticket 22 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:32 tix:100 )  (  job:1 timeleft:31 tix:100 ) 
Random 874763 -> Winning ticket 163 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:31 tix:100 )  (* job:1 timeleft:31 tix:100 ) 
Random 127536 -> Winning ticket 136 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:31 tix:100 )  (* job:1 timeleft:30 tix:100 ) 
Random 584956 -> Winning ticket 156 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:31 tix:100 )  (* job:1 timeleft:29 tix:100 ) 
Random 392952 -> Winning ticket 152 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:31 tix:100 )  (* job:1 timeleft:28 tix:100 ) 
Random 514803 -> Winning ticket 3 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:31 tix:100 )  (  job:1 timeleft:27 tix:100 ) 
Random 143829 -> Winning ticket 29 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:30 tix:100 )  (  job:1 timeleft:27 tix:100 ) 
Random 959732 -> Winning ticket 132 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:29 tix:100 )  (* job:1 timeleft:27 tix:100 ) 
Random 259096 -> Winning ticket 96 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:29 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 606078 -> Winning ticket 78 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:28 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 419755 -> Winning ticket 155 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:27 tix:100 )  (* job:1 timeleft:26 tix:100 ) 
Random 18033 -> Winning ticket 33 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:27 tix:100 )  (  job:1 timeleft:25 tix:100 ) 
Random 557950 -> Winning ticket 150 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:26 tix:100 )  (* job:1 timeleft:25 tix:100 ) 
Random 140569 -> Winning ticket 169 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:26 tix:100 )  (* job:1 timeleft:24 tix:100 ) 
Random 56781 -> Winning ticket 181 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:26 tix:100 )  (* job:1 timeleft:23 tix:100 ) 
Random 33556 -> Winning ticket 156 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:26 tix:100 )  (* job:1 timeleft:22 tix:100 ) 
Random 161165 -> Winning ticket 165 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:26 tix:100 )  (* job:1 timeleft:21 tix:100 ) 
Random 95872 -> Winning ticket 72 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:26 tix:100 )  (  job:1 timeleft:20 tix:100 ) 
Random 635076 -> Winning ticket 76 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:25 tix:100 )  (  job:1 timeleft:20 tix:100 ) 
Random 508259 -> Winning ticket 59 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:24 tix:100 )  (  job:1 timeleft:20 tix:100 ) 
Random 983467 -> Winning ticket 67 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:23 tix:100 )  (  job:1 timeleft:20 tix:100 ) 
Random 934131 -> Winning ticket 131 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:22 tix:100 )  (* job:1 timeleft:20 tix:100 ) 
Random 994526 -> Winning ticket 126 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:22 tix:100 )  (* job:1 timeleft:19 tix:100 ) 
Random 232474 -> Winning ticket 74 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:22 tix:100 )  (  job:1 timeleft:18 tix:100 ) 
Random 444697 -> Winning ticket 97 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:21 tix:100 )  (  job:1 timeleft:18 tix:100 ) 
Random 250781 -> Winning ticket 181 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:20 tix:100 )  (* job:1 timeleft:18 tix:100 ) 
Random 591237 -> Winning ticket 37 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:20 tix:100 )  (  job:1 timeleft:17 tix:100 ) 
Random 624164 -> Winning ticket 164 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:19 tix:100 )  (* job:1 timeleft:17 tix:100 ) 
Random 800208 -> Winning ticket 8 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:19 tix:100 )  (  job:1 timeleft:16 tix:100 ) 
Random 709499 -> Winning ticket 99 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:18 tix:100 )  (  job:1 timeleft:16 tix:100 ) 
Random 256609 -> Winning ticket 9 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:17 tix:100 )  (  job:1 timeleft:16 tix:100 ) 
Random 423017 -> Winning ticket 17 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:16 tix:100 )  (  job:1 timeleft:16 tix:100 ) 
Random 526190 -> Winning ticket 190 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:15 tix:100 )  (* job:1 timeleft:16 tix:100 ) 
Random 4824 -> Winning ticket 24 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:15 tix:100 )  (  job:1 timeleft:15 tix:100 ) 
Random 35499 -> Winning ticket 99 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:14 tix:100 )  (  job:1 timeleft:15 tix:100 ) 
Random 408726 -> Winning ticket 126 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:13 tix:100 )  (* job:1 timeleft:15 tix:100 ) 
Random 111175 -> Winning ticket 175 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:13 tix:100 )  (* job:1 timeleft:14 tix:100 ) 
Random 723770 -> Winning ticket 170 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:13 tix:100 )  (* job:1 timeleft:13 tix:100 ) 
Random 240865 -> Winning ticket 65 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:13 tix:100 )  (  job:1 timeleft:12 tix:100 ) 
Random 99773 -> Winning ticket 173 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:12 tix:100 ) 
Random 181760 -> Winning ticket 160 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:11 tix:100 ) 
Random 231525 -> Winning ticket 125 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:10 tix:100 ) 
Random 217353 -> Winning ticket 153 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:9 tix:100 ) 
Random 520736 -> Winning ticket 136 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:8 tix:100 ) 
Random 464403 -> Winning ticket 3 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:12 tix:100 )  (  job:1 timeleft:7 tix:100 ) 
Random 309726 -> Winning ticket 126 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:11 tix:100 )  (* job:1 timeleft:7 tix:100 ) 
Random 641759 -> Winning ticket 159 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:11 tix:100 )  (* job:1 timeleft:6 tix:100 ) 
Random 212449 -> Winning ticket 49 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:11 tix:100 )  (  job:1 timeleft:5 tix:100 ) 
Random 906563 -> Winning ticket 163 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:100 )  (* job:1 timeleft:5 tix:100 ) 
Random 963117 -> Winning ticket 117 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:100 )  (* job:1 timeleft:4 tix:100 ) 
Random 728931 -> Winning ticket 131 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:100 )  (* job:1 timeleft:3 tix:100 ) 
Random 433734 -> Winning ticket 134 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:100 )  (* job:1 timeleft:2 tix:100 ) 
Random 511501 -> Winning ticket 101 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:100 )  (* job:1 timeleft:1 tix:100 ) 
--> JOB 1 DONE at time 190
Random 581076 -> Winning ticket 76 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:10 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 51234 -> Winning ticket 34 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:9 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 418016 -> Winning ticket 16 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:8 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 525065 -> Winning ticket 65 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:7 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 181225 -> Winning ticket 25 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:6 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 93786 -> Winning ticket 86 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:5 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 802656 -> Winning ticket 56 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:4 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 366184 -> Winning ticket 84 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:3 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 519210 -> Winning ticket 10 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:2 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
Random 921451 -> Winning ticket 51 (of 100) -> Run 0
  Jobs:
 (* job:0 timeleft:1 tix:100 )  (  job:1 timeleft:0 tix:--- ) 
--> JOB 0 DONE at time 200
```

- job1 is done earlier than job0.

- $F = 190/200 = 0.950$

##### Random seed 3

```sh
$ ./lottery.py -s 3 -l 100:100,100:100 -c
ARG jlist 100:100,100:100
ARG jobs 3
ARG maxlen 10
ARG maxticket 100
ARG quantum 1
ARG seed 3

Here is the job list, with the run time of each job: 
  Job 0 ( length = 100, tickets = 100 )
  Job 1 ( length = 100, tickets = 100 )


** Solutions **

Random 237964 -> Winning ticket 164 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:100 tix:100 )  (* job:1 timeleft:100 tix:100 ) 
Random 544229 -> Winning ticket 29 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:100 tix:100 )  (  job:1 timeleft:99 tix:100 ) 
Random 369955 -> Winning ticket 155 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:99 tix:100 )  (* job:1 timeleft:99 tix:100 ) 
Random 603920 -> Winning ticket 120 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:99 tix:100 )  (* job:1 timeleft:98 tix:100 ) 
Random 625720 -> Winning ticket 120 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:99 tix:100 )  (* job:1 timeleft:97 tix:100 ) 
Random 65528 -> Winning ticket 128 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:99 tix:100 )  (* job:1 timeleft:96 tix:100 ) 
Random 13168 -> Winning ticket 168 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:99 tix:100 )  (* job:1 timeleft:95 tix:100 ) 
Random 837469 -> Winning ticket 69 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:99 tix:100 )  (  job:1 timeleft:94 tix:100 ) 
Random 259354 -> Winning ticket 154 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:98 tix:100 )  (* job:1 timeleft:94 tix:100 ) 
Random 234331 -> Winning ticket 131 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:98 tix:100 )  (* job:1 timeleft:93 tix:100 ) 
Random 995645 -> Winning ticket 45 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:98 tix:100 )  (  job:1 timeleft:92 tix:100 ) 
Random 470263 -> Winning ticket 63 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:97 tix:100 )  (  job:1 timeleft:92 tix:100 ) 
Random 836462 -> Winning ticket 62 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:96 tix:100 )  (  job:1 timeleft:92 tix:100 ) 
Random 476353 -> Winning ticket 153 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:95 tix:100 )  (* job:1 timeleft:92 tix:100 ) 
Random 639068 -> Winning ticket 68 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:95 tix:100 )  (  job:1 timeleft:91 tix:100 ) 
Random 150616 -> Winning ticket 16 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:94 tix:100 )  (  job:1 timeleft:91 tix:100 ) 
Random 634861 -> Winning ticket 61 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:93 tix:100 )  (  job:1 timeleft:91 tix:100 ) 
Random 868046 -> Winning ticket 46 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:92 tix:100 )  (  job:1 timeleft:91 tix:100 ) 
Random 523181 -> Winning ticket 181 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:91 tix:100 )  (* job:1 timeleft:91 tix:100 ) 
Random 741252 -> Winning ticket 52 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:91 tix:100 )  (  job:1 timeleft:90 tix:100 ) 
Random 671412 -> Winning ticket 12 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:90 tix:100 )  (  job:1 timeleft:90 tix:100 ) 
Random 64031 -> Winning ticket 31 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:89 tix:100 )  (  job:1 timeleft:90 tix:100 ) 
Random 758231 -> Winning ticket 31 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:88 tix:100 )  (  job:1 timeleft:90 tix:100 ) 
Random 591100 -> Winning ticket 100 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:87 tix:100 )  (* job:1 timeleft:90 tix:100 ) 
Random 301267 -> Winning ticket 67 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:87 tix:100 )  (  job:1 timeleft:89 tix:100 ) 
Random 31011 -> Winning ticket 11 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:86 tix:100 )  (  job:1 timeleft:89 tix:100 ) 
Random 865528 -> Winning ticket 128 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:85 tix:100 )  (* job:1 timeleft:89 tix:100 ) 
Random 472749 -> Winning ticket 149 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:85 tix:100 )  (* job:1 timeleft:88 tix:100 ) 
Random 718824 -> Winning ticket 24 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:85 tix:100 )  (  job:1 timeleft:87 tix:100 ) 
Random 878813 -> Winning ticket 13 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:84 tix:100 )  (  job:1 timeleft:87 tix:100 ) 
Random 714130 -> Winning ticket 130 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:83 tix:100 )  (* job:1 timeleft:87 tix:100 ) 
Random 921099 -> Winning ticket 99 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:83 tix:100 )  (  job:1 timeleft:86 tix:100 ) 
Random 394963 -> Winning ticket 163 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:82 tix:100 )  (* job:1 timeleft:86 tix:100 ) 
Random 800909 -> Winning ticket 109 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:82 tix:100 )  (* job:1 timeleft:85 tix:100 ) 
Random 444621 -> Winning ticket 21 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:82 tix:100 )  (  job:1 timeleft:84 tix:100 ) 
Random 935587 -> Winning ticket 187 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:81 tix:100 )  (* job:1 timeleft:84 tix:100 ) 
Random 878867 -> Winning ticket 67 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:81 tix:100 )  (  job:1 timeleft:83 tix:100 ) 
Random 97454 -> Winning ticket 54 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:80 tix:100 )  (  job:1 timeleft:83 tix:100 ) 
Random 135968 -> Winning ticket 168 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:79 tix:100 )  (* job:1 timeleft:83 tix:100 ) 
Random 216987 -> Winning ticket 187 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:79 tix:100 )  (* job:1 timeleft:82 tix:100 ) 
Random 965481 -> Winning ticket 81 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:79 tix:100 )  (  job:1 timeleft:81 tix:100 ) 
Random 436162 -> Winning ticket 162 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:78 tix:100 )  (* job:1 timeleft:81 tix:100 ) 
Random 626648 -> Winning ticket 48 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:78 tix:100 )  (  job:1 timeleft:80 tix:100 ) 
Random 301026 -> Winning ticket 26 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:77 tix:100 )  (  job:1 timeleft:80 tix:100 ) 
Random 507243 -> Winning ticket 43 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:76 tix:100 )  (  job:1 timeleft:80 tix:100 ) 
Random 385866 -> Winning ticket 66 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:75 tix:100 )  (  job:1 timeleft:80 tix:100 ) 
Random 350910 -> Winning ticket 110 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:74 tix:100 )  (* job:1 timeleft:80 tix:100 ) 
Random 585074 -> Winning ticket 74 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:74 tix:100 )  (  job:1 timeleft:79 tix:100 ) 
Random 584252 -> Winning ticket 52 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:73 tix:100 )  (  job:1 timeleft:79 tix:100 ) 
Random 904202 -> Winning ticket 2 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:72 tix:100 )  (  job:1 timeleft:79 tix:100 ) 
Random 681982 -> Winning ticket 182 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:71 tix:100 )  (* job:1 timeleft:79 tix:100 ) 
Random 928946 -> Winning ticket 146 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:71 tix:100 )  (* job:1 timeleft:78 tix:100 ) 
Random 856401 -> Winning ticket 1 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:71 tix:100 )  (  job:1 timeleft:77 tix:100 ) 
Random 990990 -> Winning ticket 190 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:70 tix:100 )  (* job:1 timeleft:77 tix:100 ) 
Random 671274 -> Winning ticket 74 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:70 tix:100 )  (  job:1 timeleft:76 tix:100 ) 
Random 163099 -> Winning ticket 99 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:69 tix:100 )  (  job:1 timeleft:76 tix:100 ) 
Random 860638 -> Winning ticket 38 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:68 tix:100 )  (  job:1 timeleft:76 tix:100 ) 
Random 964633 -> Winning ticket 33 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:67 tix:100 )  (  job:1 timeleft:76 tix:100 ) 
Random 904696 -> Winning ticket 96 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:66 tix:100 )  (  job:1 timeleft:76 tix:100 ) 
Random 569108 -> Winning ticket 108 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:65 tix:100 )  (* job:1 timeleft:76 tix:100 ) 
Random 713817 -> Winning ticket 17 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:65 tix:100 )  (  job:1 timeleft:75 tix:100 ) 
Random 211125 -> Winning ticket 125 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:64 tix:100 )  (* job:1 timeleft:75 tix:100 ) 
Random 831608 -> Winning ticket 8 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:64 tix:100 )  (  job:1 timeleft:74 tix:100 ) 
Random 573532 -> Winning ticket 132 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:63 tix:100 )  (* job:1 timeleft:74 tix:100 ) 
Random 284957 -> Winning ticket 157 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:63 tix:100 )  (* job:1 timeleft:73 tix:100 ) 
Random 63460 -> Winning ticket 60 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:63 tix:100 )  (  job:1 timeleft:72 tix:100 ) 
Random 853943 -> Winning ticket 143 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:62 tix:100 )  (* job:1 timeleft:72 tix:100 ) 
Random 989807 -> Winning ticket 7 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:62 tix:100 )  (  job:1 timeleft:71 tix:100 ) 
Random 88518 -> Winning ticket 118 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:61 tix:100 )  (* job:1 timeleft:71 tix:100 ) 
Random 800596 -> Winning ticket 196 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:61 tix:100 )  (* job:1 timeleft:70 tix:100 ) 
Random 410462 -> Winning ticket 62 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:61 tix:100 )  (  job:1 timeleft:69 tix:100 ) 
Random 150765 -> Winning ticket 165 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:60 tix:100 )  (* job:1 timeleft:69 tix:100 ) 
Random 293891 -> Winning ticket 91 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:60 tix:100 )  (  job:1 timeleft:68 tix:100 ) 
Random 768792 -> Winning ticket 192 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:59 tix:100 )  (* job:1 timeleft:68 tix:100 ) 
Random 872767 -> Winning ticket 167 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:59 tix:100 )  (* job:1 timeleft:67 tix:100 ) 
Random 44190 -> Winning ticket 190 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:59 tix:100 )  (* job:1 timeleft:66 tix:100 ) 
Random 614533 -> Winning ticket 133 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:59 tix:100 )  (* job:1 timeleft:65 tix:100 ) 
Random 44940 -> Winning ticket 140 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:59 tix:100 )  (* job:1 timeleft:64 tix:100 ) 
Random 718441 -> Winning ticket 41 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:59 tix:100 )  (  job:1 timeleft:63 tix:100 ) 
Random 330954 -> Winning ticket 154 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:58 tix:100 )  (* job:1 timeleft:63 tix:100 ) 
Random 880906 -> Winning ticket 106 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:58 tix:100 )  (* job:1 timeleft:62 tix:100 ) 
Random 980636 -> Winning ticket 36 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:58 tix:100 )  (  job:1 timeleft:61 tix:100 ) 
Random 505420 -> Winning ticket 20 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:57 tix:100 )  (  job:1 timeleft:61 tix:100 ) 
Random 998509 -> Winning ticket 109 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:56 tix:100 )  (* job:1 timeleft:61 tix:100 ) 
Random 309670 -> Winning ticket 70 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:56 tix:100 )  (  job:1 timeleft:60 tix:100 ) 
Random 76970 -> Winning ticket 170 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:55 tix:100 )  (* job:1 timeleft:60 tix:100 ) 
Random 599763 -> Winning ticket 163 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:55 tix:100 )  (* job:1 timeleft:59 tix:100 ) 
Random 31377 -> Winning ticket 177 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:55 tix:100 )  (* job:1 timeleft:58 tix:100 ) 
Random 197385 -> Winning ticket 185 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:55 tix:100 )  (* job:1 timeleft:57 tix:100 ) 
Random 407936 -> Winning ticket 136 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:55 tix:100 )  (* job:1 timeleft:56 tix:100 ) 
Random 610467 -> Winning ticket 67 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:55 tix:100 )  (  job:1 timeleft:55 tix:100 ) 
Random 156199 -> Winning ticket 199 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:54 tix:100 )  (* job:1 timeleft:55 tix:100 ) 
Random 42435 -> Winning ticket 35 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:54 tix:100 )  (  job:1 timeleft:54 tix:100 ) 
Random 867779 -> Winning ticket 179 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:53 tix:100 )  (* job:1 timeleft:54 tix:100 ) 
Random 313830 -> Winning ticket 30 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:53 tix:100 )  (  job:1 timeleft:53 tix:100 ) 
Random 958660 -> Winning ticket 60 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:52 tix:100 )  (  job:1 timeleft:53 tix:100 ) 
Random 896660 -> Winning ticket 60 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:51 tix:100 )  (  job:1 timeleft:53 tix:100 ) 
Random 377789 -> Winning ticket 189 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:50 tix:100 )  (* job:1 timeleft:53 tix:100 ) 
Random 460410 -> Winning ticket 10 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:50 tix:100 )  (  job:1 timeleft:52 tix:100 ) 
Random 520073 -> Winning ticket 73 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:49 tix:100 )  (  job:1 timeleft:52 tix:100 ) 
Random 643889 -> Winning ticket 89 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:48 tix:100 )  (  job:1 timeleft:52 tix:100 ) 
Random 595650 -> Winning ticket 50 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:47 tix:100 )  (  job:1 timeleft:52 tix:100 ) 
Random 559261 -> Winning ticket 61 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:46 tix:100 )  (  job:1 timeleft:52 tix:100 ) 
Random 620126 -> Winning ticket 126 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:45 tix:100 )  (* job:1 timeleft:52 tix:100 ) 
Random 940622 -> Winning ticket 22 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:45 tix:100 )  (  job:1 timeleft:51 tix:100 ) 
Random 507027 -> Winning ticket 27 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:44 tix:100 )  (  job:1 timeleft:51 tix:100 ) 
Random 431191 -> Winning ticket 191 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:43 tix:100 )  (* job:1 timeleft:51 tix:100 ) 
Random 720311 -> Winning ticket 111 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:43 tix:100 )  (* job:1 timeleft:50 tix:100 ) 
Random 237635 -> Winning ticket 35 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:43 tix:100 )  (  job:1 timeleft:49 tix:100 ) 
Random 301087 -> Winning ticket 87 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:42 tix:100 )  (  job:1 timeleft:49 tix:100 ) 
Random 977798 -> Winning ticket 198 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:41 tix:100 )  (* job:1 timeleft:49 tix:100 ) 
Random 521127 -> Winning ticket 127 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:41 tix:100 )  (* job:1 timeleft:48 tix:100 ) 
Random 548431 -> Winning ticket 31 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:41 tix:100 )  (  job:1 timeleft:47 tix:100 ) 
Random 11457 -> Winning ticket 57 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:40 tix:100 )  (  job:1 timeleft:47 tix:100 ) 
Random 415210 -> Winning ticket 10 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:39 tix:100 )  (  job:1 timeleft:47 tix:100 ) 
Random 579965 -> Winning ticket 165 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:38 tix:100 )  (* job:1 timeleft:47 tix:100 ) 
Random 20052 -> Winning ticket 52 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:38 tix:100 )  (  job:1 timeleft:46 tix:100 ) 
Random 615798 -> Winning ticket 198 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:37 tix:100 )  (* job:1 timeleft:46 tix:100 ) 
Random 632181 -> Winning ticket 181 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:37 tix:100 )  (* job:1 timeleft:45 tix:100 ) 
Random 60080 -> Winning ticket 80 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:37 tix:100 )  (  job:1 timeleft:44 tix:100 ) 
Random 627341 -> Winning ticket 141 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:36 tix:100 )  (* job:1 timeleft:44 tix:100 ) 
Random 466250 -> Winning ticket 50 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:36 tix:100 )  (  job:1 timeleft:43 tix:100 ) 
Random 679282 -> Winning ticket 82 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:35 tix:100 )  (  job:1 timeleft:43 tix:100 ) 
Random 352577 -> Winning ticket 177 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:34 tix:100 )  (* job:1 timeleft:43 tix:100 ) 
Random 706950 -> Winning ticket 150 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:34 tix:100 )  (* job:1 timeleft:42 tix:100 ) 
Random 738035 -> Winning ticket 35 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:34 tix:100 )  (  job:1 timeleft:41 tix:100 ) 
Random 22182 -> Winning ticket 182 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:33 tix:100 )  (* job:1 timeleft:41 tix:100 ) 
Random 60576 -> Winning ticket 176 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:33 tix:100 )  (* job:1 timeleft:40 tix:100 ) 
Random 676020 -> Winning ticket 20 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:33 tix:100 )  (  job:1 timeleft:39 tix:100 ) 
Random 963306 -> Winning ticket 106 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:32 tix:100 )  (* job:1 timeleft:39 tix:100 ) 
Random 251122 -> Winning ticket 122 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:32 tix:100 )  (* job:1 timeleft:38 tix:100 ) 
Random 456312 -> Winning ticket 112 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:32 tix:100 )  (* job:1 timeleft:37 tix:100 ) 
Random 592672 -> Winning ticket 72 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:32 tix:100 )  (  job:1 timeleft:36 tix:100 ) 
Random 320025 -> Winning ticket 25 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:31 tix:100 )  (  job:1 timeleft:36 tix:100 ) 
Random 363955 -> Winning ticket 155 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:30 tix:100 )  (* job:1 timeleft:36 tix:100 ) 
Random 312670 -> Winning ticket 70 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:30 tix:100 )  (  job:1 timeleft:35 tix:100 ) 
Random 369154 -> Winning ticket 154 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:29 tix:100 )  (* job:1 timeleft:35 tix:100 ) 
Random 595622 -> Winning ticket 22 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:29 tix:100 )  (  job:1 timeleft:34 tix:100 ) 
Random 300404 -> Winning ticket 4 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:28 tix:100 )  (  job:1 timeleft:34 tix:100 ) 
Random 377160 -> Winning ticket 160 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:27 tix:100 )  (* job:1 timeleft:34 tix:100 ) 
Random 772274 -> Winning ticket 74 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:27 tix:100 )  (  job:1 timeleft:33 tix:100 ) 
Random 26921 -> Winning ticket 121 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:26 tix:100 )  (* job:1 timeleft:33 tix:100 ) 
Random 569258 -> Winning ticket 58 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:26 tix:100 )  (  job:1 timeleft:32 tix:100 ) 
Random 735173 -> Winning ticket 173 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:25 tix:100 )  (* job:1 timeleft:32 tix:100 ) 
Random 310017 -> Winning ticket 17 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:25 tix:100 )  (  job:1 timeleft:31 tix:100 ) 
Random 222538 -> Winning ticket 138 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:24 tix:100 )  (* job:1 timeleft:31 tix:100 ) 
Random 803808 -> Winning ticket 8 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:24 tix:100 )  (  job:1 timeleft:30 tix:100 ) 
Random 238695 -> Winning ticket 95 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:23 tix:100 )  (  job:1 timeleft:30 tix:100 ) 
Random 187394 -> Winning ticket 194 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:22 tix:100 )  (* job:1 timeleft:30 tix:100 ) 
Random 435234 -> Winning ticket 34 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:22 tix:100 )  (  job:1 timeleft:29 tix:100 ) 
Random 698067 -> Winning ticket 67 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:21 tix:100 )  (  job:1 timeleft:29 tix:100 ) 
Random 101841 -> Winning ticket 41 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:20 tix:100 )  (  job:1 timeleft:29 tix:100 ) 
Random 321966 -> Winning ticket 166 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:19 tix:100 )  (* job:1 timeleft:29 tix:100 ) 
Random 333753 -> Winning ticket 153 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:19 tix:100 )  (* job:1 timeleft:28 tix:100 ) 
Random 833539 -> Winning ticket 139 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:19 tix:100 )  (* job:1 timeleft:27 tix:100 ) 
Random 438431 -> Winning ticket 31 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:19 tix:100 )  (  job:1 timeleft:26 tix:100 ) 
Random 855536 -> Winning ticket 136 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:18 tix:100 )  (* job:1 timeleft:26 tix:100 ) 
Random 169284 -> Winning ticket 84 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:18 tix:100 )  (  job:1 timeleft:25 tix:100 ) 
Random 336710 -> Winning ticket 110 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:17 tix:100 )  (* job:1 timeleft:25 tix:100 ) 
Random 650233 -> Winning ticket 33 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:17 tix:100 )  (  job:1 timeleft:24 tix:100 ) 
Random 884899 -> Winning ticket 99 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:16 tix:100 )  (  job:1 timeleft:24 tix:100 ) 
Random 451102 -> Winning ticket 102 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:15 tix:100 )  (* job:1 timeleft:24 tix:100 ) 
Random 225028 -> Winning ticket 28 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:15 tix:100 )  (  job:1 timeleft:23 tix:100 ) 
Random 120919 -> Winning ticket 119 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:14 tix:100 )  (* job:1 timeleft:23 tix:100 ) 
Random 529628 -> Winning ticket 28 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:14 tix:100 )  (  job:1 timeleft:22 tix:100 ) 
Random 190803 -> Winning ticket 3 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:13 tix:100 )  (  job:1 timeleft:22 tix:100 ) 
Random 806778 -> Winning ticket 178 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:12 tix:100 )  (* job:1 timeleft:22 tix:100 ) 
Random 838477 -> Winning ticket 77 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:12 tix:100 )  (  job:1 timeleft:21 tix:100 ) 
Random 183586 -> Winning ticket 186 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:11 tix:100 )  (* job:1 timeleft:21 tix:100 ) 
Random 278592 -> Winning ticket 192 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:11 tix:100 )  (* job:1 timeleft:20 tix:100 ) 
Random 807227 -> Winning ticket 27 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:11 tix:100 )  (  job:1 timeleft:19 tix:100 ) 
Random 641937 -> Winning ticket 137 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:10 tix:100 )  (* job:1 timeleft:19 tix:100 ) 
Random 806258 -> Winning ticket 58 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:10 tix:100 )  (  job:1 timeleft:18 tix:100 ) 
Random 345283 -> Winning ticket 83 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:9 tix:100 )  (  job:1 timeleft:18 tix:100 ) 
Random 129689 -> Winning ticket 89 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:8 tix:100 )  (  job:1 timeleft:18 tix:100 ) 
Random 291943 -> Winning ticket 143 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:7 tix:100 )  (* job:1 timeleft:18 tix:100 ) 
Random 793862 -> Winning ticket 62 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:7 tix:100 )  (  job:1 timeleft:17 tix:100 ) 
Random 271174 -> Winning ticket 174 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:6 tix:100 )  (* job:1 timeleft:17 tix:100 ) 
Random 346354 -> Winning ticket 154 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:6 tix:100 )  (* job:1 timeleft:16 tix:100 ) 
Random 416906 -> Winning ticket 106 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:6 tix:100 )  (* job:1 timeleft:15 tix:100 ) 
Random 419771 -> Winning ticket 171 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:6 tix:100 )  (* job:1 timeleft:14 tix:100 ) 
Random 409522 -> Winning ticket 122 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:6 tix:100 )  (* job:1 timeleft:13 tix:100 ) 
Random 920613 -> Winning ticket 13 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:6 tix:100 )  (  job:1 timeleft:12 tix:100 ) 
Random 155998 -> Winning ticket 198 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:5 tix:100 )  (* job:1 timeleft:12 tix:100 ) 
Random 4661 -> Winning ticket 61 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:5 tix:100 )  (  job:1 timeleft:11 tix:100 ) 
Random 943268 -> Winning ticket 68 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:4 tix:100 )  (  job:1 timeleft:11 tix:100 ) 
Random 879979 -> Winning ticket 179 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:3 tix:100 )  (* job:1 timeleft:11 tix:100 ) 
Random 986914 -> Winning ticket 114 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:3 tix:100 )  (* job:1 timeleft:10 tix:100 ) 
Random 434352 -> Winning ticket 152 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:3 tix:100 )  (* job:1 timeleft:9 tix:100 ) 
Random 950162 -> Winning ticket 162 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:3 tix:100 )  (* job:1 timeleft:8 tix:100 ) 
Random 927378 -> Winning ticket 178 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:3 tix:100 )  (* job:1 timeleft:7 tix:100 ) 
Random 222090 -> Winning ticket 90 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:3 tix:100 )  (  job:1 timeleft:6 tix:100 ) 
Random 745523 -> Winning ticket 123 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:2 tix:100 )  (* job:1 timeleft:6 tix:100 ) 
Random 836699 -> Winning ticket 99 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:2 tix:100 )  (  job:1 timeleft:5 tix:100 ) 
Random 662987 -> Winning ticket 187 (of 200) -> Run 1
  Jobs:
 (  job:0 timeleft:1 tix:100 )  (* job:1 timeleft:5 tix:100 ) 
Random 519015 -> Winning ticket 15 (of 200) -> Run 0
  Jobs:
 (* job:0 timeleft:1 tix:100 )  (  job:1 timeleft:4 tix:100 ) 
--> JOB 0 DONE at time 196
Random 289042 -> Winning ticket 42 (of 100) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- )  (* job:1 timeleft:4 tix:100 ) 
Random 341069 -> Winning ticket 69 (of 100) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- )  (* job:1 timeleft:3 tix:100 ) 
Random 227466 -> Winning ticket 66 (of 100) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- )  (* job:1 timeleft:2 tix:100 ) 
Random 68067 -> Winning ticket 67 (of 100) -> Run 1
  Jobs:
 (  job:0 timeleft:0 tix:--- )  (* job:1 timeleft:1 tix:100 ) 
--> JOB 1 DONE at time 200
```

- job1 is done earlier than job0.

- $F = 196/200 = 0.980$

##### 4

- When the random is 1

    - and the quantum size 1, $F = 196/200 = 0.980$

    - and the quantum size 5, $F = 190/200 = 0.950$

    - and the quantum size 10, $F = 160/200 = 0.800$

    - and the quantum size 15, $F = 180/210 = 0.857$

    - and the quantum size 20, $F = 180/200 = 0.900$

    - and the quantum size 25, $F = 150/200 = 0.750$

- As the quantum size increases, $F$ far from 1, or unfairness grows.

#### 5

- Check the turnaround time.

- A strid scheduler will show high fairness even with a small job length.

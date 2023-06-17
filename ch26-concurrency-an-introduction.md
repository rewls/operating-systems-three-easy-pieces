# Ch26 Concurrency: An Introduction

## Contents

Concurrency

- Ch26 Concurrency: An Introduction

    - 26.1 Why Use Threads?

    - 26.2 An Example: Thread Creation

    - 26.3 Why It Gets Worse: Shared Data

    - 26.4 The Heart of the Problem: Uncontrolled Scheduling

    - 26.5 The Wish for Atomicity

    - 26.6 One More Problem: Waiting for Another

    - 26.7 Summary: Why in OS Class?

## Howork (Simulation)

### Questions

#### 1

```sh
$ ./x86.py -p loop.s -t 1 -i 100 -R dx
ARG seed 0
ARG numthreads 1
ARG program loop.s
ARG interrupt frequency 100
ARG interrupt randomness False
ARG argv 
ARG load address 1000
ARG memsize 128
ARG memtrace 
ARG regtrace dx
ARG cctrace False
ARG printstats False
ARG verbose False

   dx          Thread 0         
    ?   
    ?   1000 sub  $1,%dx
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   1003 halt
```

- In `loop.s`, `dx` is a loop value and if `dx` is greater than or equals to 0 after subtracting `dx` by 1 the loop take places.

- Since the loop take places 1 time, the default value of `dx` register is 0 and also actually 0 in `x86.py`

- Thus the operations looks like this:

```sh
   dx          Thread 0         
    0   
   -1   1000 sub  $1,%dx
   -1   1001 test $0,%dx
   -1   1002 jgte .top
   -1   1003 halt
```

#### 2

```sh
$ ./x86.py -p loop.s -t 2 -i 100 -a dx=3,dx=3 -R dx
ARG seed 0
ARG numthreads 2
ARG program loop.s
ARG interrupt frequency 100
ARG interrupt randomness False
ARG argv dx=3,dx=3
ARG load address 1000
ARG memsize 128
ARG memtrace 
ARG regtrace dx
ARG cctrace False
ARG printstats False
ARG verbose False

   dx          Thread 0                Thread 1         
    ?   
    ?   1000 sub  $1,%dx
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   1000 sub  $1,%dx
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   1000 sub  $1,%dx
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   1000 sub  $1,%dx
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   1003 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?                            1000 sub  $1,%dx
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?                            1000 sub  $1,%dx
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?                            1000 sub  $1,%dx
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?                            1000 sub  $1,%dx
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?                            1003 halt
```

```sh
   dx          Thread 0                Thread 1         
    3   
    2   1000 sub  $1,%dx
    2   1001 test $0,%dx
    2   1002 jgte .top
    1   1000 sub  $1,%dx
    1   1001 test $0,%dx
    1   1002 jgte .top
    0   1000 sub  $1,%dx
    0   1001 test $0,%dx
    0   1002 jgte .top
   -1   1000 sub  $1,%dx
   -1   1001 test $0,%dx
   -1   1002 jgte .top
   -1   1003 halt
    3   ----- Halt;Switch -----  ----- Halt;Switch -----  
    2                            1000 sub  $1,%dx
    2                            1001 test $0,%dx
    2                            1002 jgte .top
    1                            1000 sub  $1,%dx
    1                            1001 test $0,%dx
    1                            1002 jgte .top
    0                            1000 sub  $1,%dx
    0                            1001 test $0,%dx
    0                            1002 jgte .top
   -1                            1000 sub  $1,%dx
   -1                            1001 test $0,%dx
   -1                            1002 jgte .top
   -1                            1003 halt
```

- Although multiple threads exists, calculations run as we expected because the interrupt frequency is sufficiently large in this case.

- There is no race because of the sufficiently large interrupt frequency.

#### 3

- As the interrupt frequency change, what thread will end first changes.

##### Random seed 0

```sh
$ ./x86.py -p loop.s -t 2 -i 3 -r -a dx=3,dx=3 -R dx
ARG seed 0
ARG numthreads 2
ARG program loop.s
ARG interrupt frequency 3
ARG interrupt randomness True
ARG argv dx=3,dx=3
ARG load address 1000
ARG memsize 128
ARG memtrace 
ARG regtrace dx
ARG cctrace False
ARG printstats False
ARG verbose False

   dx          Thread 0                Thread 1         
    ?   
    ?   1000 sub  $1,%dx
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 sub  $1,%dx
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1000 sub  $1,%dx
    ?   1001 test $0,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1002 jgte .top
    ?   1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1003 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?                            1000 sub  $1,%dx
    ?                            1001 test $0,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1002 jgte .top
    ?                            1003 halt
```

```sh
   dx          Thread 0                Thread 1         
    3   
    2   1000 sub  $1,%dx
    2   1001 test $0,%dx
    2   1002 jgte .top
    3   ------ Interrupt ------  ------ Interrupt ------  
    2                            1000 sub  $1,%dx
    2                            1001 test $0,%dx
    2                            1002 jgte .top
    2   ------ Interrupt ------  ------ Interrupt ------  
    1   1000 sub  $1,%dx
    1   1001 test $0,%dx
    2   ------ Interrupt ------  ------ Interrupt ------  
    1                            1000 sub  $1,%dx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1002 jgte .top
    0   1000 sub  $1,%dx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1001 test $0,%dx
    1                            1002 jgte .top
    0   ------ Interrupt ------  ------ Interrupt ------  
    0   1001 test $0,%dx
    0   1002 jgte .top
   -1   1000 sub  $1,%dx
    1   ------ Interrupt ------  ------ Interrupt ------  
    0                            1000 sub  $1,%dx
   -1   ------ Interrupt ------  ------ Interrupt ------  
   -1   1001 test $0,%dx
   -1   1002 jgte .top
    0   ------ Interrupt ------  ------ Interrupt ------  
    0                            1001 test $0,%dx
    0                            1002 jgte .top
   -1   ------ Interrupt ------  ------ Interrupt ------  
   -1   1003 halt
    0   ----- Halt;Switch -----  ----- Halt;Switch -----  
   -1                            1000 sub  $1,%dx
   -1                            1001 test $0,%dx
   -1   ------ Interrupt ------  ------ Interrupt ------  
   -1                            1002 jgte .top
   -1                            1003 halt
```

##### Random seed 1

```sh
$ ./x86.py -p loop.s -t 2 -i 3 -r -a dx=3,dx=3 -R dx -s 1
ARG seed 1
ARG numthreads 2
ARG program loop.s
ARG interrupt frequency 3
ARG interrupt randomness True
ARG argv dx=3,dx=3
ARG load address 1000
ARG memsize 128
ARG memtrace 
ARG regtrace dx
ARG cctrace False
ARG printstats False
ARG verbose False

   dx          Thread 0                Thread 1         
    ?   
    ?   1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 sub  $1,%dx
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1000 sub  $1,%dx
    ?   1001 test $0,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 sub  $1,%dx
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1000 sub  $1,%dx
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1003 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?                            1003 halt
```

```sh
   dx          Thread 0                Thread 1         
    3   
    2   1000 sub  $1,%dx
    3   ------ Interrupt ------  ------ Interrupt ------  
    2                            1000 sub  $1,%dx
    2                            1001 test $0,%dx
    2                            1002 jgte .top
    2   ------ Interrupt ------  ------ Interrupt ------  
    2   1001 test $0,%dx
    2   1002 jgte .top
    1   1000 sub  $1,%dx
    2   ------ Interrupt ------  ------ Interrupt ------  
    1                            1000 sub  $1,%dx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1001 test $0,%dx
    1   1002 jgte .top
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1001 test $0,%dx
    1                            1002 jgte .top
    1   ------ Interrupt ------  ------ Interrupt ------  
    0   1000 sub  $1,%dx
    0   1001 test $0,%dx
    1   ------ Interrupt ------  ------ Interrupt ------  
    0                            1000 sub  $1,%dx
    0                            1001 test $0,%dx
    0                            1002 jgte .top
    0   ------ Interrupt ------  ------ Interrupt ------  
    0   1002 jgte .top
    0   ------ Interrupt ------  ------ Interrupt ------  
   -1                            1000 sub  $1,%dx
    0   ------ Interrupt ------  ------ Interrupt ------  
   -1   1000 sub  $1,%dx
   -1   1001 test $0,%dx
   -1   1002 jgte .top
   -1   ------ Interrupt ------  ------ Interrupt ------  
   -1                            1001 test $0,%dx
   -1                            1002 jgte .top
   -1   ------ Interrupt ------  ------ Interrupt ------  
   -1   1003 halt
   -1   ----- Halt;Switch -----  ----- Halt;Switch -----  
   -1                            1003 halt
```

##### Random seed 2

```sh
./x86.py -p loop.s -t 2 -i 3 -r -a dx=3,dx=3 -R dx -s 2
ARG seed 2
ARG numthreads 2
ARG program loop.s
ARG interrupt frequency 3
ARG interrupt randomness True
ARG argv dx=3,dx=3
ARG load address 1000
ARG memsize 128
ARG memtrace 
ARG regtrace dx
ARG cctrace False
ARG printstats False
ARG verbose False

   dx          Thread 0                Thread 1         
    ?   
    ?   1000 sub  $1,%dx
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 sub  $1,%dx
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1001 test $0,%dx
    ?                            1002 jgte .top
    ?                            1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1001 test $0,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1001 test $0,%dx
    ?   1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1002 jgte .top
    ?                            1000 sub  $1,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1003 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?                            1001 test $0,%dx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1002 jgte .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1003 halt
```

```sh
   dx          Thread 0                Thread 1         
    3   
    2   1000 sub  $1,%dx
    2   1001 test $0,%dx
    2   1002 jgte .top
    3   ------ Interrupt ------  ------ Interrupt ------  
    2                            1000 sub  $1,%dx
    2                            1001 test $0,%dx
    2                            1002 jgte .top
    2   ------ Interrupt ------  ------ Interrupt ------  
    1   1000 sub  $1,%dx
    2   ------ Interrupt ------  ------ Interrupt ------  
    1                            1000 sub  $1,%dx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1001 test $0,%dx
    1   1002 jgte .top
    0   1000 sub  $1,%dx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1001 test $0,%dx
    1                            1002 jgte .top
    0                            1000 sub  $1,%dx
    0   ------ Interrupt ------  ------ Interrupt ------  
    0   1001 test $0,%dx
    0   1002 jgte .top
   -1   1000 sub  $1,%dx
    0   ------ Interrupt ------  ------ Interrupt ------  
    0                            1001 test $0,%dx
   -1   ------ Interrupt ------  ------ Interrupt ------  
   -1   1001 test $0,%dx
   -1   1002 jgte .top
    0   ------ Interrupt ------  ------ Interrupt ------  
    0                            1002 jgte .top
   -1                            1000 sub  $1,%dx
   -1   ------ Interrupt ------  ------ Interrupt ------  
   -1   1003 halt
   -1   ----- Halt;Switch -----  ----- Halt;Switch -----  
   -1                            1001 test $0,%dx
   -1   ------ Interrupt ------  ------ Interrupt ------  
   -1                            1002 jgte .top
   -1   ------ Interrupt ------  ------ Interrupt ------  
   -1                            1003 halt
```

#### 4

```sh
$ ./x86.py -p looping-race-nolock.s -t 1 -M 2000
ARG seed 0
ARG numthreads 1
ARG program looping-race-nolock.s
ARG interrupt frequency 50
ARG interrupt randomness False
ARG argv 
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace 
ARG cctrace False
ARG printstats False
ARG verbose False

 2000          Thread 0         
    ?   
    ?   1000 mov 2000, %ax
    ?   1001 add $1, %ax
    ?   1002 mov %ax, 2000
    ?   1003 sub  $1, %bx
    ?   1004 test $0, %bx
    ?   1005 jgt .top
    ?   1006 halt
```

- In the file `looping-race-nolock.s`, the shared variable is accessed, the loop continues until `bx` is less than 0 by subtracting 1 from `bx`.

- In the above output, since the thread terminates just after subtracting 1 from `bx`, we know that the default value of `bx` is set to 0.

- However, sicne I am not aware of the default value at address 2000, I reffered to `x86.py` to determine the default value, which turned out to be 0.

- Thus, a solution to the problem is as follows.

```sh
 2000          Thread 0         
    0   
    0   1000 mov 2000, %ax
    0   1001 add $1, %ax
    1   1002 mov %ax, 2000
    1   1003 sub  $1, %bx
    1   1004 test $0, %bx
    1   1005 jgt .top
    1   1006 halt
```

#### 5

```sh
$ ./x86.py -p looping-race-nolock.s -t2 -abx=3 -M 2000
ARG seed 0
ARG numthreads 2
ARG program looping-race-nolock.s
ARG interrupt frequency 50
ARG interrupt randomness False
ARG argv bx=3
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace 
ARG cctrace False
ARG printstats False
ARG verbose False

 2000          Thread 0                Thread 1         
    ?   
    ?   1000 mov 2000, %ax
    ?   1001 add $1, %ax
    ?   1002 mov %ax, 2000
    ?   1003 sub  $1, %bx
    ?   1004 test $0, %bx
    ?   1005 jgt .top
    ?   1000 mov 2000, %ax
    ?   1001 add $1, %ax
    ?   1002 mov %ax, 2000
    ?   1003 sub  $1, %bx
    ?   1004 test $0, %bx
    ?   1005 jgt .top
    ?   1000 mov 2000, %ax
    ?   1001 add $1, %ax
    ?   1002 mov %ax, 2000
    ?   1003 sub  $1, %bx
    ?   1004 test $0, %bx
    ?   1005 jgt .top
    ?   1006 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?                            1000 mov 2000, %ax
    ?                            1001 add $1, %ax
    ?                            1002 mov %ax, 2000
    ?                            1003 sub  $1, %bx
    ?                            1004 test $0, %bx
    ?                            1005 jgt .top
    ?                            1000 mov 2000, %ax
    ?                            1001 add $1, %ax
    ?                            1002 mov %ax, 2000
    ?                            1003 sub  $1, %bx
    ?                            1004 test $0, %bx
    ?                            1005 jgt .top
    ?                            1000 mov 2000, %ax
    ?                            1001 add $1, %ax
    ?                            1002 mov %ax, 2000
    ?                            1003 sub  $1, %bx
    ?                            1004 test $0, %bx
    ?                            1005 jgt .top
    ?                            1006 halt
```

- Since we set the default value of `bx` to 3 in the command option, The loop body executes three times until `bx` becomes 0 by subtracting 1 from it.

- Here is a solution to the problem and, final value of `value` is 6 as seen in the following.

```sh
 2000          Thread 0                Thread 1         
    0   
    0   1000 mov 2000, %ax
    0   1001 add $1, %ax
    1   1002 mov %ax, 2000
    1   1003 sub  $1, %bx
    1   1004 test $0, %bx
    1   1005 jgt .top
    1   1000 mov 2000, %ax
    1   1001 add $1, %ax
    2   1002 mov %ax, 2000
    2   1003 sub  $1, %bx
    2   1004 test $0, %bx
    2   1005 jgt .top
    2   1000 mov 2000, %ax
    2   1001 add $1, %ax
    3   1002 mov %ax, 2000
    3   1003 sub  $1, %bx
    3   1004 test $0, %bx
    3   1005 jgt .top
    3   1006 halt
    3   ----- Halt;Switch -----  ----- Halt;Switch -----  
    3                            1000 mov 2000, %ax
    3                            1001 add $1, %ax
    4                            1002 mov %ax, 2000
    4                            1003 sub  $1, %bx
    4                            1004 test $0, %bx
    4                            1005 jgt .top
    4                            1000 mov 2000, %ax
    4                            1001 add $1, %ax
    5                            1002 mov %ax, 2000
    5                            1003 sub  $1, %bx
    5                            1004 test $0, %bx
    5                            1005 jgt .top
    5                            1000 mov 2000, %ax
    5                            1001 add $1, %ax
    6                            1002 mov %ax, 2000
    6                            1003 sub  $1, %bx
    6                            1004 test $0, %bx
    6                            1005 jgt .top
    6                            1006 halt
```

#### 6

- The timing of the interrupt matters because the interrupt frequency is not sufficiently large to allow enough time for the code to update the shared variable. This causes a race condition during the update of the shared variable `value`, resulting in different final values depending on when a interrupt occurs.

- The critical section is the code to update the shared variable.

##### Random seed 0

```sh
$ ./x86.py -p looping-race-nolock.s -t 2 -M 2000 -i 4 -r -s 0
ARG seed 0
ARG numthreads 2
ARG program looping-race-nolock.s
ARG interrupt frequency 4
ARG interrupt randomness True
ARG argv 
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace 
ARG cctrace False
ARG printstats False
ARG verbose False

 2000          Thread 0                Thread 1         
    ?   
    ?   1000 mov 2000, %ax
    ?   1001 add $1, %ax
    ?   1002 mov %ax, 2000
    ?   1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 mov 2000, %ax
    ?                            1001 add $1, %ax
    ?                            1002 mov %ax, 2000
    ?                            1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1004 test $0, %bx
    ?   1005 jgt .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1004 test $0, %bx
    ?                            1005 jgt .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1006 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?                            1006 halt
```

```sh
 2000          Thread 0                Thread 1         
    0   
    0   1000 mov 2000, %ax
    0   1001 add $1, %ax
    1   1002 mov %ax, 2000
    1   1003 sub  $1, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1000 mov 2000, %ax
    1                            1001 add $1, %ax
    2                            1002 mov %ax, 2000
    2                            1003 sub  $1, %bx
    2   ------ Interrupt ------  ------ Interrupt ------  
    2   1004 test $0, %bx
    2   1005 jgt .top
    2   ------ Interrupt ------  ------ Interrupt ------  
    2                            1004 test $0, %bx
    2                            1005 jgt .top
    2   ------ Interrupt ------  ------ Interrupt ------  
    2   1006 halt
    2   ----- Halt;Switch -----  ----- Halt;Switch -----  
    2                            1006 halt
```

##### Random seed 1

```sh
$ ./x86.py -p looping-race-nolock.s -t 2 -M 2000 -i 4 -r -s 1
ARG seed 1
ARG numthreads 2
ARG program looping-race-nolock.s
ARG interrupt frequency 4
ARG interrupt randomness True
ARG argv 
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace 
ARG cctrace False
ARG printstats False
ARG verbose False

 2000          Thread 0                Thread 1         
    ?   
    ?   1000 mov 2000, %ax
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 mov 2000, %ax
    ?                            1001 add $1, %ax
    ?                            1002 mov %ax, 2000
    ?                            1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1001 add $1, %ax
    ?   1002 mov %ax, 2000
    ?   1003 sub  $1, %bx
    ?   1004 test $0, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1004 test $0, %bx
    ?                            1005 jgt .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1005 jgt .top
    ?   1006 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1006 halt
```

```
 2000          Thread 0                Thread 1         
    0   
    0   1000 mov 2000, %ax
    0   ------ Interrupt ------  ------ Interrupt ------  
    0                            1000 mov 2000, %ax
    0                            1001 add $1, %ax
    1                            1002 mov %ax, 2000
    1                            1003 sub  $1, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1001 add $1, %ax
    1   1002 mov %ax, 2000
    1   1003 sub  $1, %bx
    1   1004 test $0, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1004 test $0, %bx
    1                            1005 jgt .top
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1005 jgt .top
    1   1006 halt
    1   ----- Halt;Switch -----  ----- Halt;Switch -----  
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1006 halt
```

##### Random seed 2

```sh
$ ./x86.py -p looping-race-nolock.s -t 2 -M 2000 -i 4 -r -s 2
ARG seed 2
ARG numthreads 2
ARG program looping-race-nolock.s
ARG interrupt frequency 4
ARG interrupt randomness True
ARG argv 
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace 
ARG cctrace False
ARG printstats False
ARG verbose False

 2000          Thread 0                Thread 1         
    ?   
    ?   1000 mov 2000, %ax
    ?   1001 add $1, %ax
    ?   1002 mov %ax, 2000
    ?   1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 mov 2000, %ax
    ?                            1001 add $1, %ax
    ?                            1002 mov %ax, 2000
    ?                            1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1004 test $0, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1004 test $0, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1005 jgt .top
    ?   1006 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?                            1005 jgt .top
    ?                            1006 halt
```

```
 2000          Thread 0                Thread 1         
    0   
    0   1000 mov 2000, %ax
    0   1001 add $1, %ax
    1   1002 mov %ax, 2000
    1   1003 sub  $1, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1000 mov 2000, %ax
    1                            1001 add $1, %ax
    2                            1002 mov %ax, 2000
    2                            1003 sub  $1, %bx
    2   ------ Interrupt ------  ------ Interrupt ------  
    2   1004 test $0, %bx
    2   ------ Interrupt ------  ------ Interrupt ------  
    2                            1004 test $0, %bx
    2   ------ Interrupt ------  ------ Interrupt ------  
    2   1005 jgt .top
    2   1006 halt
    2   ----- Halt;Switch -----  ----- Halt;Switch -----  
    2                            1005 jgt .top
    2                            1006 halt
```

#### 7

- The program yields the correct answer when the interrupt interval is set to 3 or greater, as this interval provides sufficient time for the code to update the shared variable.

##### Interrupt interval 1

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=1 -t 2 -M 2000 -i 1
ARG seed 0
ARG numthreads 2
ARG program looping-race-nolock.s
ARG interrupt frequency 1
ARG interrupt randomness False
ARG argv bx=1
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace 
ARG cctrace False
ARG printstats False
ARG verbose False

 2000          Thread 0                Thread 1         
    ?   
    ?   1000 mov 2000, %ax
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 mov 2000, %ax
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1001 add $1, %ax
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1001 add $1, %ax
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1002 mov %ax, 2000
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1002 mov %ax, 2000
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1004 test $0, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1004 test $0, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1005 jgt .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1005 jgt .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1006 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1006 halt
```

```sh
 2000          Thread 0                Thread 1         
    0   
    0   1000 mov 2000, %ax
    0   ------ Interrupt ------  ------ Interrupt ------  
    0                            1000 mov 2000, %ax
    0   ------ Interrupt ------  ------ Interrupt ------  
    0   1001 add $1, %ax
    0   ------ Interrupt ------  ------ Interrupt ------  
    0                            1001 add $1, %ax
    0   ------ Interrupt ------  ------ Interrupt ------  
    1   1002 mov %ax, 2000
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1002 mov %ax, 2000
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1003 sub  $1, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1003 sub  $1, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1004 test $0, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1004 test $0, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1005 jgt .top
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1005 jgt .top
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1006 halt
    1   ----- Halt;Switch -----  ----- Halt;Switch -----  
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1006 halt
```

##### Interrupt interval 2

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=1 -t 2 -M 2000 -i 2
ARG seed 0
ARG numthreads 2
ARG program looping-race-nolock.s
ARG interrupt frequency 2
ARG interrupt randomness False
ARG argv bx=1
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace 
ARG cctrace False
ARG printstats False
ARG verbose False

 2000          Thread 0                Thread 1         
    ?   
    ?   1000 mov 2000, %ax
    ?   1001 add $1, %ax
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 mov 2000, %ax
    ?                            1001 add $1, %ax
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1002 mov %ax, 2000
    ?   1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1002 mov %ax, 2000
    ?                            1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1004 test $0, %bx
    ?   1005 jgt .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1004 test $0, %bx
    ?                            1005 jgt .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1006 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?                            1006 halt
```

```sh
 2000          Thread 0                Thread 1         
    0   
    0   1000 mov 2000, %ax
    0   1001 add $1, %ax
    0   ------ Interrupt ------  ------ Interrupt ------  
    0                            1000 mov 2000, %ax
    0                            1001 add $1, %ax
    0   ------ Interrupt ------  ------ Interrupt ------  
    1   1002 mov %ax, 2000
    1   1003 sub  $1, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1002 mov %ax, 2000
    1                            1003 sub  $1, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1004 test $0, %bx
    1   1005 jgt .top
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1004 test $0, %bx
    1                            1005 jgt .top
    1   ------ Interrupt ------  ------ Interrupt ------  
    1   1006 halt
    1   ----- Halt;Switch -----  ----- Halt;Switch -----  
    1                            1006 halt
```

##### Interrupt interval 3

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=1 -t 2 -M 2000 -i 3
ARG seed 0
ARG numthreads 2
ARG program looping-race-nolock.s
ARG interrupt frequency 3
ARG interrupt randomness False
ARG argv bx=1
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace 
ARG cctrace False
ARG printstats False
ARG verbose False

 2000          Thread 0                Thread 1         
    ?   
    ?   1000 mov 2000, %ax
    ?   1001 add $1, %ax
    ?   1002 mov %ax, 2000
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 mov 2000, %ax
    ?                            1001 add $1, %ax
    ?                            1002 mov %ax, 2000
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1003 sub  $1, %bx
    ?   1004 test $0, %bx
    ?   1005 jgt .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1003 sub  $1, %bx
    ?                            1004 test $0, %bx
    ?                            1005 jgt .top
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1006 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?                            1006 halt
```

```sh
 2000          Thread 0                Thread 1         
    0   
    0   1000 mov 2000, %ax
    0   1001 add $1, %ax
    1   1002 mov %ax, 2000
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1000 mov 2000, %ax
    1                            1001 add $1, %ax
    2                            1002 mov %ax, 2000
    2   ------ Interrupt ------  ------ Interrupt ------  
    2   1003 sub  $1, %bx
    2   1004 test $0, %bx
    2   1005 jgt .top
    2   ------ Interrupt ------  ------ Interrupt ------  
    2                            1003 sub  $1, %bx
    2                            1004 test $0, %bx
    2                            1005 jgt .top
    2   ------ Interrupt ------  ------ Interrupt ------  
    2   1006 halt
    2   ----- Halt;Switch -----  ----- Halt;Switch -----  
    2                            1006 halt
```

##### Interrupt interval 4

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=1 -t 2 -M 2000 -i 4
ARG seed 0
ARG numthreads 2
ARG program looping-race-nolock.s
ARG interrupt frequency 4
ARG interrupt randomness False
ARG argv bx=1
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace 
ARG cctrace False
ARG printstats False
ARG verbose False

 2000          Thread 0                Thread 1         
    ?   
    ?   1000 mov 2000, %ax
    ?   1001 add $1, %ax
    ?   1002 mov %ax, 2000
    ?   1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1000 mov 2000, %ax
    ?                            1001 add $1, %ax
    ?                            1002 mov %ax, 2000
    ?                            1003 sub  $1, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?   1004 test $0, %bx
    ?   1005 jgt .top
    ?   1006 halt
    ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?                            1004 test $0, %bx
    ?   ------ Interrupt ------  ------ Interrupt ------  
    ?                            1005 jgt .top
    ?                            1006 halt
```

```sh
 2000          Thread 0                Thread 1         
    0   
    0   1000 mov 2000, %ax
    0   1001 add $1, %ax
    1   1002 mov %ax, 2000
    1   1003 sub  $1, %bx
    1   ------ Interrupt ------  ------ Interrupt ------  
    1                            1000 mov 2000, %ax
    1                            1001 add $1, %ax
    2                            1002 mov %ax, 2000
    2                            1003 sub  $1, %bx
    2   ------ Interrupt ------  ------ Interrupt ------  
    2   1004 test $0, %bx
    2   1005 jgt .top
    2   1006 halt
    2   ----- Halt;Switch -----  ----- Halt;Switch -----  
    2                            1004 test $0, %bx
    2   ------ Interrupt ------  ------ Interrupt ------  
    2                            1005 jgt .top
    2                            1006 halt
```

#### 8

- When we set the interrupt interval to a multiple of 3, the program print a correct outcome.

- Otherwise, interrupt occurs between the code to update the shared variable, resulting in a different final value depending on when interrupts occur.

- Additionally, if the interrupt interval is long enough to cover the entire execution time of the code that updates the shared variable, which amounts to $6 \times 100 - 3 = 597$, the program will yeild a correct outcome. However, from a scheduling perspective, this impacts the response time, making it significantly worse.

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=100 -t 2 -M 2000 -i 1 -c | tail -n 30
   99                            1005 jgt .top
   99   ------ Interrupt ------  ------ Interrupt ------  
   99   1000 mov 2000, %ax
   99   ------ Interrupt ------  ------ Interrupt ------  
   99                            1000 mov 2000, %ax
   99   ------ Interrupt ------  ------ Interrupt ------  
   99   1001 add $1, %ax
   99   ------ Interrupt ------  ------ Interrupt ------  
   99                            1001 add $1, %ax
   99   ------ Interrupt ------  ------ Interrupt ------  
  100   1002 mov %ax, 2000
  100   ------ Interrupt ------  ------ Interrupt ------  
  100                            1002 mov %ax, 2000
  100   ------ Interrupt ------  ------ Interrupt ------  
  100   1003 sub  $1, %bx
  100   ------ Interrupt ------  ------ Interrupt ------  
  100                            1003 sub  $1, %bx
  100   ------ Interrupt ------  ------ Interrupt ------  
  100   1004 test $0, %bx
  100   ------ Interrupt ------  ------ Interrupt ------  
  100                            1004 test $0, %bx
  100   ------ Interrupt ------  ------ Interrupt ------  
  100   1005 jgt .top
  100   ------ Interrupt ------  ------ Interrupt ------  
  100                            1005 jgt .top
  100   ------ Interrupt ------  ------ Interrupt ------  
  100   1006 halt
  100   ----- Halt;Switch -----  ----- Halt;Switch -----  
  100   ------ Interrupt ------  ------ Interrupt ------  
  100                            1006 halt
```

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=100 -t 2 -M 2000 -i 2 -c | tail -n 30
   99                            1002 mov %ax, 2000
   99                            1003 sub  $1, %bx
   99   ------ Interrupt ------  ------ Interrupt ------  
   99   1004 test $0, %bx
   99   1005 jgt .top
   99   ------ Interrupt ------  ------ Interrupt ------  
   99                            1004 test $0, %bx
   99                            1005 jgt .top
   99   ------ Interrupt ------  ------ Interrupt ------  
   99   1000 mov 2000, %ax
   99   1001 add $1, %ax
   99   ------ Interrupt ------  ------ Interrupt ------  
   99                            1000 mov 2000, %ax
   99                            1001 add $1, %ax
   99   ------ Interrupt ------  ------ Interrupt ------  
  100   1002 mov %ax, 2000
  100   1003 sub  $1, %bx
  100   ------ Interrupt ------  ------ Interrupt ------  
  100                            1002 mov %ax, 2000
  100                            1003 sub  $1, %bx
  100   ------ Interrupt ------  ------ Interrupt ------  
  100   1004 test $0, %bx
  100   1005 jgt .top
  100   ------ Interrupt ------  ------ Interrupt ------  
  100                            1004 test $0, %bx
  100                            1005 jgt .top
  100   ------ Interrupt ------  ------ Interrupt ------  
  100   1006 halt
  100   ----- Halt;Switch -----  ----- Halt;Switch -----  
  100                            1006 halt
```

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=100 -t 2 -M 2000 -i 3 -c | tail -n 30
  197                            1001 add $1, %ax
  198                            1002 mov %ax, 2000
  198   ------ Interrupt ------  ------ Interrupt ------  
  198   1003 sub  $1, %bx
  198   1004 test $0, %bx
  198   1005 jgt .top
  198   ------ Interrupt ------  ------ Interrupt ------  
  198                            1003 sub  $1, %bx
  198                            1004 test $0, %bx
  198                            1005 jgt .top
  198   ------ Interrupt ------  ------ Interrupt ------  
  198   1000 mov 2000, %ax
  198   1001 add $1, %ax
  199   1002 mov %ax, 2000
  199   ------ Interrupt ------  ------ Interrupt ------  
  199                            1000 mov 2000, %ax
  199                            1001 add $1, %ax
  200                            1002 mov %ax, 2000
  200   ------ Interrupt ------  ------ Interrupt ------  
  200   1003 sub  $1, %bx
  200   1004 test $0, %bx
  200   1005 jgt .top
  200   ------ Interrupt ------  ------ Interrupt ------  
  200                            1003 sub  $1, %bx
  200                            1004 test $0, %bx
  200                            1005 jgt .top
  200   ------ Interrupt ------  ------ Interrupt ------  
  200   1006 halt
  200   ----- Halt;Switch -----  ----- Halt;Switch -----  
  200                            1006 halt
```

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=100 -t 2 -M 2000 -i 4 -c | tail -n 30
  148   1003 sub  $1, %bx
  148   ------ Interrupt ------  ------ Interrupt ------  
  148                            1000 mov 2000, %ax
  148                            1001 add $1, %ax
  149                            1002 mov %ax, 2000
  149                            1003 sub  $1, %bx
  149   ------ Interrupt ------  ------ Interrupt ------  
  149   1004 test $0, %bx
  149   1005 jgt .top
  149   1000 mov 2000, %ax
  149   1001 add $1, %ax
  149   ------ Interrupt ------  ------ Interrupt ------  
  149                            1004 test $0, %bx
  149                            1005 jgt .top
  149                            1000 mov 2000, %ax
  149                            1001 add $1, %ax
  149   ------ Interrupt ------  ------ Interrupt ------  
  150   1002 mov %ax, 2000
  150   1003 sub  $1, %bx
  150   1004 test $0, %bx
  150   1005 jgt .top
  150   ------ Interrupt ------  ------ Interrupt ------  
  150                            1002 mov %ax, 2000
  150                            1003 sub  $1, %bx
  150                            1004 test $0, %bx
  150                            1005 jgt .top
  150   ------ Interrupt ------  ------ Interrupt ------  
  150   1006 halt
  150   ----- Halt;Switch -----  ----- Halt;Switch -----  
  150                            1006 halt
```

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=100 -t 2 -M 2000 -i 5 -c | tail -n 30
  158                            1000 mov 2000, %ax
  158                            1001 add $1, %ax
  158   ------ Interrupt ------  ------ Interrupt ------  
  159   1002 mov %ax, 2000
  159   1003 sub  $1, %bx
  159   1004 test $0, %bx
  159   1005 jgt .top
  159   1000 mov 2000, %ax
  159   ------ Interrupt ------  ------ Interrupt ------  
  159                            1002 mov %ax, 2000
  159                            1003 sub  $1, %bx
  159                            1004 test $0, %bx
  159                            1005 jgt .top
  159                            1000 mov 2000, %ax
  159   ------ Interrupt ------  ------ Interrupt ------  
  159   1001 add $1, %ax
  160   1002 mov %ax, 2000
  160   1003 sub  $1, %bx
  160   1004 test $0, %bx
  160   1005 jgt .top
  160   ------ Interrupt ------  ------ Interrupt ------  
  160                            1001 add $1, %ax
  160                            1002 mov %ax, 2000
  160                            1003 sub  $1, %bx
  160                            1004 test $0, %bx
  160                            1005 jgt .top
  160   ------ Interrupt ------  ------ Interrupt ------  
  160   1006 halt
  160   ----- Halt;Switch -----  ----- Halt;Switch -----  
  160                            1006 halt
```

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=100 -t 2 -M 2000 -i 6 -c | tail -n 30
  196   1001 add $1, %ax
  197   1002 mov %ax, 2000
  197   1003 sub  $1, %bx
  197   1004 test $0, %bx
  197   1005 jgt .top
  197   ------ Interrupt ------  ------ Interrupt ------  
  197                            1000 mov 2000, %ax
  197                            1001 add $1, %ax
  198                            1002 mov %ax, 2000
  198                            1003 sub  $1, %bx
  198                            1004 test $0, %bx
  198                            1005 jgt .top
  198   ------ Interrupt ------  ------ Interrupt ------  
  198   1000 mov 2000, %ax
  198   1001 add $1, %ax
  199   1002 mov %ax, 2000
  199   1003 sub  $1, %bx
  199   1004 test $0, %bx
  199   1005 jgt .top
  199   ------ Interrupt ------  ------ Interrupt ------  
  199                            1000 mov 2000, %ax
  199                            1001 add $1, %ax
  200                            1002 mov %ax, 2000
  200                            1003 sub  $1, %bx
  200                            1004 test $0, %bx
  200                            1005 jgt .top
  200   ------ Interrupt ------  ------ Interrupt ------  
  200   1006 halt
  200   ----- Halt;Switch -----  ----- Halt;Switch -----  
  200                            1006 halt
```

```sh
$ ./x86.py -p looping-race-nolock.s -a bx=100 -t 2 -M 2000 -i 597 -c | tail -n 30
  196                            1001 add $1, %ax
  197                            1002 mov %ax, 2000
  197                            1003 sub  $1, %bx
  197                            1004 test $0, %bx
  197                            1005 jgt .top
  197                            1000 mov 2000, %ax
  197                            1001 add $1, %ax
  198                            1002 mov %ax, 2000
  198                            1003 sub  $1, %bx
  198                            1004 test $0, %bx
  198                            1005 jgt .top
  198                            1000 mov 2000, %ax
  198                            1001 add $1, %ax
  199                            1002 mov %ax, 2000
  199                            1003 sub  $1, %bx
  199                            1004 test $0, %bx
  199                            1005 jgt .top
  199                            1000 mov 2000, %ax
  199                            1001 add $1, %ax
  200                            1002 mov %ax, 2000
  200   ------ Interrupt ------  ------ Interrupt ------  
  200   1003 sub  $1, %bx
  200   1004 test $0, %bx
  200   1005 jgt .top
  200   1006 halt
  200   ----- Halt;Switch -----  ----- Halt;Switch -----  
  200                            1003 sub  $1, %bx
  200                            1004 test $0, %bx
  200                            1005 jgt .top
  200                            1006 halt
```

#### 9

```sh
$ ./x86.py -p wait-for-me.s -a ax=1,ax=0 -R ax -M 2000
ARG seed 0
ARG numthreads 2
ARG program wait-for-me.s
ARG interrupt frequency 50
ARG interrupt randomness False
ARG argv ax=1,ax=0
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace ax
ARG cctrace False
ARG printstats False
ARG verbose False

 2000      ax          Thread 0                Thread 1         
    ?       ?   
    ?       ?   1000 test $1, %ax
    ?       ?   1001 je .signaller
    ?       ?   1006 mov  $1, 2000
    ?       ?   1007 halt
    ?       ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?       ?                            1000 test $1, %ax
    ?       ?                            1001 je .signaller
    ?       ?                            1002 mov  2000, %cx
    ?       ?                            1003 test $1, %cx
    ?       ?                            1004 jne .waiter
    ?       ?                            1005 halt
```

```sh
 2000      ax          Thread 0                Thread 1         
    0       1   
    0       1   1000 test $1, %ax
    0       1   1001 je .signaller
    1       1   1006 mov  $1, 2000
    1       1   1007 halt
    1       0   ----- Halt;Switch -----  ----- Halt;Switch -----  
    1       0                            1000 test $1, %ax
    1       0                            1001 je .signaller
    1       0                            1002 mov  2000, %cx
    1       0                            1003 test $1, %cx
    1       0                            1004 jne .waiter
    1       0                            1005 halt
```

- First, in thread 0 with `ax` whose value is 1, the value at location 200 is set to 1. Second, in thread 1 with `ax` whose value is 0, the value at location 2000 is compared with 1 and terminates if they are not the same.

- We can observe that what code run depends on the value of `ax`, and a thread where `ax`=0 terminates only after a thread where `ax`=1 runs.

#### 10

- A thread where `ax` is 1 doesn't terminates alone. Thus it runs infinitely until a thread where `ax` is 0 updates the value at location 2000 to 1.

```sh
$ ./x86.py -p wait-for-me.s -a ax=0,ax=1 -R ax -M 2000
ARG seed 0
ARG numthreads 2
ARG program wait-for-me.s
ARG interrupt frequency 50
ARG interrupt randomness False
ARG argv ax=0,ax=1
ARG load address 1000
ARG memsize 128
ARG memtrace 2000
ARG regtrace ax
ARG cctrace False
ARG printstats False
ARG verbose False

 2000      ax          Thread 0                Thread 1         
    ?       ?   
    ?       ?   1000 test $1, %ax
    ?       ?   1001 je .signaller
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   ------ Interrupt ------  ------ Interrupt ------  
    ?       ?                            1000 test $1, %ax
    ?       ?                            1001 je .signaller
    ?       ?                            1006 mov  $1, 2000
    ?       ?                            1007 halt
    ?       ?   ----- Halt;Switch -----  ----- Halt;Switch -----  
    ?       ?   1002 mov  2000, %cx
    ?       ?   1003 test $1, %cx
    ?       ?   1004 jne .waiter
    ?       ?   1005 halt
```

```sh
 2000      ax          Thread 0                Thread 1         
    0       0   
    0       0   1000 test $1, %ax
    0       0   1001 je .signaller
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       0   1002 mov  2000, %cx
    0       0   1003 test $1, %cx
    0       0   1004 jne .waiter
    0       1   ------ Interrupt ------  ------ Interrupt ------  
    0       1                            1000 test $1, %ax
    0       1                            1001 je .signaller
    1       1                            1006 mov  $1, 2000
    1       1                            1007 halt
    1       0   ----- Halt;Switch -----  ----- Halt;Switch -----  
    1       0   1002 mov  2000, %cx
    1       0   1003 test $1, %cx
    1       0   1004 jne .waiter
    1       0   1005 halt
```

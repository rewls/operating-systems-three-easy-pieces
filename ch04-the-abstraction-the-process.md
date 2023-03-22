# Ch4 The Abstraction: The Process

## Homework (Simulation)

### Questions

#### 1

$$
{10 \over 10} \times 100 = 100 \%
$$

|Time|PID: 0|PID: 1|CPU|IOs|
|-|-|-|-|-|
|1|RUN:cpu|READY|1| |
|2|RUN:cpu|READY|1| |
|3|RUN:cpu|READY|1| |
|4|RUN:cpu|READY|1| |
|5|RUN:cpu|READY|1| |
|6|DONE|RUN:cpu|1| |
|7|DONE|RUN:cpu|1| |
|8|DONE|RUN:cpu|1| |
|9|DONE|RUN:cpu|1| |
|10|DONE|RUN:cpu|1| |

#### 2

- 4(cpu) + 1(io) + 5(BLOCKED, IO_LENGTH default) + 1(io_done) = 11

#### 3

|Time|PID: 0|PID: 1|CPU|IOs|
|-|-|-|-|-|
|1|RUN:io|READY|1| |
|2|BLOCKED|RUN:cpu|1|1|
|3|BLOCKED|RUN:cpu|1|1|
|4|BLOCKED|RUN:cpu|1|1|
|5|BLOCKED|RUN:cpu|1|1|
|6|BLOCKED|DONE| |1|
|7|RUN:io_done|DONE|1| |

- IO가 먼저 실행되어 process가 BLOCKED 상태가 되면 다른 process로 switch하여 실행할 수 있어 두 process를 실행하는 시간이 1(io) + 4(cpu) + 1(BLOCKED) + 1(io_done) = 7로 줄어든다.

#### 4

|Time|PID: 0|PID: 1|CPU|IOs|
|-|-|-|-|-|
|1|RUN:io|READY|1| |
|2|BLOCKED|READY| |1|
|3|BLOCKED|READY| |1|
|4|BLOCKED|READY| |1|
|5|BLOCKED|READY| |1|
|6|BLOCKED|READY| |1|
|7|RUN:io_done|READY|1| |
|8|DONE|RUN:cpu|1| |
|9|DONE|RUN:cpu|1| |
|10|DONE|RUN:cpu|1| |
|11|DONE|RUN:cpu|1| |

- IO가 실행되고 process가 BLOCKED 상태가 돼도 다른 process로 switch하지 않고 process 0이 끝난 후 switch한다.

#### 5

|Time|PID: 0|PID: 1|CPU|IOs|
|-|-|-|-|-|
|1|RUN:io|READY|1| |
|2|BLOCKED|RUN:cpu|1|1|
|3|BLOCKED|RUN:cpu|1|1|
|4|BLOCKED|RUN:cpu|1|1|
|5|BLOCKED|RUN:cpu|1|1|
|6|BLOCKED|DONE| |1|
|7|RUN:io_done|DONE|1| |

- IO가 실행되고 process가 BLOCKED 상태가 되면 다른 process로 switch하한다.

#### 6

```sh
Time        PID: 0        PID: 1        PID: 2        PID: 3           CPU           IOs
  1         RUN:io         READY         READY         READY             1          
  2        BLOCKED       RUN:cpu         READY         READY             1             1
  3        BLOCKED       RUN:cpu         READY         READY             1             1
  4        BLOCKED       RUN:cpu         READY         READY             1             1
  5        BLOCKED       RUN:cpu         READY         READY             1             1
  6        BLOCKED       RUN:cpu         READY         READY             1             1
  7*         READY          DONE       RUN:cpu         READY             1          
  8          READY          DONE       RUN:cpu         READY             1          
  9          READY          DONE       RUN:cpu         READY             1          
 10          READY          DONE       RUN:cpu         READY             1          
 11          READY          DONE       RUN:cpu         READY             1          
 12          READY          DONE          DONE       RUN:cpu             1          
 13          READY          DONE          DONE       RUN:cpu             1          
 14          READY          DONE          DONE       RUN:cpu             1          
 15          READY          DONE          DONE       RUN:cpu             1          
 16          READY          DONE          DONE       RUN:cpu             1          
 17    RUN:io_done          DONE          DONE          DONE             1          
 18         RUN:io          DONE          DONE          DONE             1          
 19        BLOCKED          DONE          DONE          DONE                           1
 20        BLOCKED          DONE          DONE          DONE                           1
 21        BLOCKED          DONE          DONE          DONE                           1
 22        BLOCKED          DONE          DONE          DONE                           1
 23        BLOCKED          DONE          DONE          DONE                           1
 24*   RUN:io_done          DONE          DONE          DONE             1          
 25         RUN:io          DONE          DONE          DONE             1          
 26        BLOCKED          DONE          DONE          DONE                           1
 27        BLOCKED          DONE          DONE          DONE                           1
 28        BLOCKED          DONE          DONE          DONE                           1
 29        BLOCKED          DONE          DONE          DONE                           1
 30        BLOCKED          DONE          DONE          DONE                           1
 31*   RUN:io_done          DONE          DONE          DONE             1          

Stats: Total Time 31
Stats: CPU Busy 21 (67.74%)
Stats: IO Busy  15 (48.39%)
```

- 첫번째 IO가 실행되고 다른 process들의 instruction이 모두 실행된 후 다음 IO가 실행된다.

- 다른 process가 모두 실행된 후 다음 IO가 실행되어 BLOCKED 상태가 될 때 자원이 낭비된다.

#### 7

```sh
Time        PID: 0        PID: 1        PID: 2        PID: 3           CPU           IOs
  1         RUN:io         READY         READY         READY             1          
  2        BLOCKED       RUN:cpu         READY         READY             1             1
  3        BLOCKED       RUN:cpu         READY         READY             1             1
  4        BLOCKED       RUN:cpu         READY         READY             1             1
  5        BLOCKED       RUN:cpu         READY         READY             1             1
  6        BLOCKED       RUN:cpu         READY         READY             1             1
  7*   RUN:io_done          DONE         READY         READY             1          
  8         RUN:io          DONE         READY         READY             1          
  9        BLOCKED          DONE       RUN:cpu         READY             1             1
 10        BLOCKED          DONE       RUN:cpu         READY             1             1
 11        BLOCKED          DONE       RUN:cpu         READY             1             1
 12        BLOCKED          DONE       RUN:cpu         READY             1             1
 13        BLOCKED          DONE       RUN:cpu         READY             1             1
 14*   RUN:io_done          DONE          DONE         READY             1          
 15         RUN:io          DONE          DONE         READY             1          
 16        BLOCKED          DONE          DONE       RUN:cpu             1             1
 17        BLOCKED          DONE          DONE       RUN:cpu             1             1
 18        BLOCKED          DONE          DONE       RUN:cpu             1             1
 19        BLOCKED          DONE          DONE       RUN:cpu             1             1
 20        BLOCKED          DONE          DONE       RUN:cpu             1             1
 21*   RUN:io_done          DONE          DONE          DONE             1          

Stats: Total Time 21
Stats: CPU Busy 21 (100.00%)
Stats: IO Busy  15 (71.43%)
```

- IO가 끝나면 바로 다음 IO가 실행되면 BLOCKED 상태일 때의 자원을 활용할 수 있으므로 자원을 효율적으로 사용할 수 있다.

#### 8

- default: `SWITCH_ON_IO`, `IO_RUN_LATER`

##### a

```sh
$ ./process-run.py -s 1 -l 3:50,3:50
Produce a trace of what would happen when you run these processes:
Process 0
  cpu
  io
  io_done
  io
  io_done

Process 1
  cpu
  cpu
  cpu

Important behaviors:
  System will switch when the current process is FINISHED or ISSUES AN IO
  After IOs, the process issuing the IO will run LATER (when it is its turn)
```

- `-I IO_RUN_LATER`, `-I IO_RUN_IMMEDIATE`, or `-S SWITCH_ON_IO`

    |Time|PID: 0|PID: 1|CPU|IOs|
    |-|-|-|-|-|
    |1|RUN:cpu|READY|1| |
    |2|RUN:io|READY|1| |
    |3|BLOCKED|RUN:cpu|1|1|
    |4|BLOCKED|RUN:cpu|1|1|
    |5|BLOCKED|RUN:cpu|1|1|
    |6|BLOCKED|DONE| |1|
    |7|BLOCKED|DONE| |1|
    |8|RUN:io_done|DONE|1| |
    |9|RUN:io|DONE|1| |
    |10|BLOCKED|DONE| |1|
    |11|BLOCKED|DONE| |1|
    |12|BLOCKED|DONE| |1|
    |13|BLOCKED|DONE| |1|
    |14|BLOCKED|DONE| |1|
    |15|RUN:io_done|DONE|1| |

    - Stats: Total Time 15

    - Stats: CPU Busy 8 (53.33%)

    - Stats: IO Busy 10 (66.67%)

- `-S SWITCH_ON_END`

    |Time|PID: 0|PID: 1|CPU|IOs|
    |-|-|-|-|-|
    |1|RUN:cpu|READY|1| |
    |2|RUN:io|READY|1| |
    |3|BLOCKED|READY| |1|
    |4|BLOCKED|READY| |1|
    |5|BLOCKED|READY| |1|
    |6|BLOCKED|READY| |1|
    |7|BLOCKED|READY| |1|
    |8|RUN:io_done|READY|1| |
    |9|RUN:io|READY|1| |
    |10|BLOCKED|READY| |1|
    |11|BLOCKED|READY| |1|
    |12|BLOCKED|READY| |1|
    |13|BLOCKED|READY| |1|
    |14|BLOCKED|READY| |1|
    |15|RUN:io_done|READY|1| |
    |16|DONE|RUN:cpu|1| |
    |17|DONE|RUN:cpu|1| |
    |18|DONE|RUN:cpu|1| |

    - Stats: Total Time 18

    - Stats: CPU Busy 8 (44.44%)

    - Stats: IO Busy 10 (55.56%)

##### b

```sh
$ ./process-run.py -s 2 -l 3:50,3:50
Produce a trace of what would happen when you run these processes:
Process 0
  io
  io_done
  io
  io_done
  cpu

Process 1
  cpu
  io
  io_done
  io
  io_done

Important behaviors:
  System will switch when the current process is FINISHED or ISSUES AN IO
  After IOs, the process issuing the IO will run LATER (when it is its turn)
```

- `-I IO_RUN_LATER`, `-I IO_RUN_IMMEDIATE`, or `-S SWITCH_ON_IO`

    |Time|PID: 0|PID: 1|CPU|IOs|
    |-|-|-|-|-|
    |1|RUN:io|READY|1| |
    |2|BLOCKED|RUN:cpu|1|1|
    |3|BLOCKED|RUN:io|1|1|
    |4|BLOCKED|BLOCKED| |2|
    |5|BLOCKED|BLOCKED| |2|
    |6|BLOCKED|BLOCKED| |2|
    |7|RUN:io_done|BLOCKED|1|1|
    |8|RUN:io|BLOCKED|1|1|
    |9|BLOCKED|RUN:io_done|1|1|
    |10|BLOCKED|RUN:io|1|1|
    |11|BLOCKED|BLOCKED| |2|
    |12|BLOCKED|BLOCKED| |2|
    |13|BLOCKED|BLOCKED| |2|
    |14|RUN:io_done|BLOCKED|1|1|
    |15|RUN:cpu|BLOCKED|1|1|
    |16|DONE|RUN:io_done|1| |

    - Stats: Total Time 16

    - Stats: CPU Busy 10 (62.50%)

    - Stats: IO Busy 14 (87.50%)

- `-S SWITCH_ON_END`

    |Time|PID: 0|PID: 1|CPU|IOs|
    |-|-|-|-|-|
    |1|RUN:io|READY|1| |
    |2|BLOCKED|READY| |1|
    |3|BLOCKED|READY| |1|
    |4|BLOCKED|READY| |1|
    |5|BLOCKED|READY| |1|
    |6|BLOCKED|READY| |1|
    |7|RUN:io_done|READY|1| |
    |8|RUN:io|READY|1| |
    |9|BLOCKED|READY| |1|
    |10|BLOCKED|READY| |1|
    |11|BLOCKED|READY| |1|
    |12|BLOCKED|READY| |1|
    |13|BLOCKED|READY| |1|
    |14|RUN:io_done|READY|1| |
    |15|RUN:cpu|READY|1| |
    |16|DONE|RUN:cpu|1| |
    |17|DONE|RUN:io|1| |
    |18|DONE|BLOCKED| |1|
    |19|DONE|BLOCKED| |1|
    |20|DONE|BLOCKED| |1|
    |21|DONE|BLOCKED| |1|
    |22|DONE|BLOCKED| |1|
    |23|DONE|RUN:io_done|1| |
    |24|DONE|RUN:io|1| |
    |25|DONE|BLOCKED| |1|
    |26|DONE|BLOCKED| |1|
    |27|DONE|BLOCKED| |1|
    |28|DONE|BLOCKED| |1|
    |29|DONE|BLOCKED| |1|
    |30|DONE|RUN:io_done|1| |

    - Stats: Total Time 30

    - Stats: CPU Busy 10 (33.33%)

    - Stats: IO Busy 20 (66.67%)

##### c

```sh
$ ./process-run.py -s 3 -l 3:50,3:50
Produce a trace of what would happen when you run these processes:
Process 0
  cpu
  io
  io_done
  cpu

Process 1
  io
  io_done
  io
  io_done
  cpu

Important behaviors:
  System will switch when the current process is FINISHED or ISSUES AN IO
  After IOs, the process issuing the IO will run LATER (when it is its turn)
```

- `-I IO_RUN_LATER` or `-S SWITCH_ON_IO`

    |Time|PID: 0|PID: 1|CPU|IOs|
    |-|-|-|-|-|
    |1|RUN:cpu|READY|1| |
    |2|RUN:io|READY|1| |
    |3|BLOCKED|RUN:io|1|1|
    |4|BLOCKED|BLOCKED| |2|
    |5|BLOCKED|BLOCKED| |2|
    |6|BLOCKED|BLOCKED| |2|
    |7|BLOCKED|BLOCKED| |2|
    |8|RUN:io_done|BLOCKED|1|1|
    |9|RUN:cpu|READY|1| |
    |10|DONE|RUN:io_done|1| |
    |11|DONE|RUN:io|1| |
    |12|DONE|BLOCKED| |1|
    |13|DONE|BLOCKED| |1|
    |14|DONE|BLOCKED| |1|
    |15|DONE|BLOCKED| |1|
    |16|DONE|BLOCKED| |1|
    |17|DONE|RUN:io_done|1| |
    |18|DONE|RUN:cpu|1| |

    - Stats Total Time 18

    - Stats CPU Busy 9 (50.00%)

    - Stats: IO Busy 11 (61.11%)

- `-I IO_RUN_IMMEDIATE`

    |Time|PID: 0|PID: 1|CPU|IOs|
    |-|-|-|-|-|
    |1|RUN:cpu|READY|1| |
    |2|RUN:io|READY|1| |
    |3|BLOCKED|RUN:io|1|1|
    |4|BLOCKED|BLOCKED| |2|
    |5|BLOCKED|BLOCKED| |2|
    |6|BLOCKED|BLOCKED| |2|
    |7|BLOCKED|BLOCKED| |2|
    |8|RUN:io_done|BLOCKED|1|1|
    |9|READY|RUN:io_done|1| |
    |10|READY|RUN:io|1| |
    |11|RUN:cpu|BLOCKED|1|1|
    |12|DONE|BLOCKED| |1|
    |13|DONE|BLOCKED| |1|
    |14|DONE|BLOCKED| |1|
    |15|DONE|BLOCKED| |1|
    |16|DONE|RUN:io_done|1| |
    |17|DONE|RUN:cpu|1| |

    - Stats Total Time 17

    - Stats CPU Busy 9 (52.94%)

    - Stats: IO Busy 11 (64.71%)

- `-S SWITCH_ON_END`

    |Time|PID: 0|PID: 1|CPU|IOs|
    |-|-|-|-|-|
    |1|RUN:cpu|READY|1| |
    |2|RUN:io|READY|1| |
    |3|BLOCKED|READY| |1|
    |4|BLOCKED|READY| |1|
    |5|BLOCKED|READY| |1|
    |6|BLOCKED|READY| |1|
    |7|BLOCKED|READY| |1|
    |8|RUN:io_done|READY|1| |
    |9|RUN:cpu|READY|1| |
    |10|DONE|RUN:io|1| |
    |11|DONE|BLOCKED| |1|
    |12|DONE|BLOCKED| |1|
    |13|DONE|BLOCKED| |1|
    |14|DONE|BLOCKED| |1|
    |15|DONE|BLOCKED| |1|
    |16|DONE|RUN:io_done|1| |
    |17|DONE|RUN:io|1| |
    |18|DONE|BLOCKED| |1|
    |19|DONE|BLOCKED| |1|
    |20|DONE|BLOCKED| |1|
    |21|DONE|BLOCKED| |1|
    |22|DONE|BLOCKED| |1|
    |23|DONE|RUN:io_done|1| |
    |24|DONE|RUN:cpu|1| |

    - Stats Total Time 24

    - Stats CPU Busy 9 (37.50%)

    - Stats: IO Busy 15 (62.50%)


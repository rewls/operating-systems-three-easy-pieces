# Ch17 Free-Space Management

## Contents

Virtualization

- Ch17 Free-Space Management

    - 17.1 Assumptions

    - 17.2 Low-levle Mechanisms

        - Splitting and Coalescing

        - Tracking the Size of Allocated Regions

        - Embedding a Free List

        - Growing the Heap

    - 17.3 Basic Strategies

        - Best Fit

        - Worst Fit

        - First Fit

        - Next Fit

        - Examples

    - 17.4 Other Approaches

        - Segregated Lists

        - Buddy Allocation

        - Other Ideas

    - 17.5 Summary

## Homework (Simulation)

### Questions

#### 1

```sh
$ ./malloc.py -n 10 -H 0 -p BEST -s 0
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy BEST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute False

ptr[0] = Alloc(3) returned ?
List? 

Free(ptr[0])
returned ?
List? 

ptr[1] = Alloc(5) returned ?
List? 

Free(ptr[1])
returned ?
List? 

ptr[2] = Alloc(8) returned ?
List? 

Free(ptr[2])
returned ?
List? 

ptr[3] = Alloc(8) returned ?
List? 

Free(ptr[3])
returned ?
List? 

ptr[4] = Alloc(2) returned ?
List? 

ptr[5] = Alloc(7) returned ?
List? 
```

```sh
ptr[0] = Alloc(3) returned 1000 (searched 1 element)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0]) returned 0
Free List [ Size 2 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:97 ]

ptr[1] = Alloc(5) returned 1003 (searched 2 elements)
Free List [ Size 2 ]: [ addr:1000 sz:3 ] [ addr:1008 sz:92 ]

Free(ptr[1]) returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:92 ]

ptr[2] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1016 sz:84 ]

Free(ptr[2]) returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[3] = Alloc(8) returned 1008 (searched 4 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1016 sz:84 ]

Free(ptr[3]) returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[4] = Alloc(2) returned 1000 (searched 4 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ] [ addr:1003 sz:5 ] [ addr:1008 sz:8 ] [ addr:1016 sz:84 ]

ptr[5] = Alloc(7) returned 1008 (searched 4 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ] [ addr:1003 sz:5 ] [ addr:1015 sz:1 ] [ addr:1016 sz:84 ]
```

- The free list is being splited without coalescing.

#### 2

```sh
$ ./malloc.py -n 10 -H 0 -p WORST -s 0 -c
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy WORST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList
compute True

ptr[0] = Alloc(3) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1003 sz:97 ]

ptr[1] = Alloc(5) returned 1003 (searched 2 elements)
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1008 sz:92 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:92 ]

ptr[2] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[3] = Alloc(8) returned 1016 (searched 4 elements)
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1024 sz:76 ]

Free(ptr[3])
returned 0
Free List [ Size 5 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1024 sz:76 ]

ptr[4] = Alloc(2) returned 1024 (searched 5 elements)
Free List [ Size 5 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1026 sz:74 ]

ptr[5] = Alloc(7) returned 1026 (searched 5 elements)
Free List [ Size 5 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1033 sz:67 ]
```

- Comparing with the best fit strategy, the worst fit strategy splits the chunk more, but the minimum size of chunk is larger.

#### 3

```sh
$ ./malloc.py -n 10 -H 0 -p FIRST -s 0 -c
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy FIRST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute True

ptr[0] = Alloc(3) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1003 sz:97 ]

ptr[1] = Alloc(5) returned 1003 (searched 2 elements)
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1008 sz:92 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:92 ]

ptr[2] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[3] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[3])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[4] = Alloc(2) returned 1000 (searched 1 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[5] = Alloc(7) returned 1008 (searched 3 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1015 sz:1 ][ addr:1016 sz:84 ]
```

- The result using the first fit is equal to using the best fit. But using the first fit takes less seach time.

#### 4

```sh
$ ./malloc.py -n 10 -H 0 -p FIRST -l ADDRSORT -C -s 0 -c
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy FIRST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute True

ptr[0] = Alloc(3) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1003 sz:97 ]

ptr[1] = Alloc(5) returned 1003 (searched 2 elements)
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1008 sz:92 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:92 ]

ptr[2] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[3] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[3])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[4] = Alloc(2) returned 1000 (searched 1 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[5] = Alloc(7) returned 1008 (searched 3 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1015 sz:1 ][ addr:1016 sz:84 ]
```

```sh
$ ./malloc.py -n 10 -H 0 -p FIRST -l SIZESORT+ -C -s 0 -c
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy FIRST
listOrder SIZESORT+
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute True

ptr[0] = Alloc(3) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1003 sz:97 ]

ptr[1] = Alloc(5) returned 1003 (searched 2 elements)
Free List [ Size 2 ]: [ addr:1000 sz:3 ][ addr:1008 sz:92 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:92 ]

ptr[2] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[3] = Alloc(8) returned 1008 (searched 3 elements)
Free List [ Size 3 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1016 sz:84 ]

Free(ptr[3])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:3 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[4] = Alloc(2) returned 1000 (searched 1 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1008 sz:8 ][ addr:1016 sz:84 ]

ptr[5] = Alloc(7) returned 1008 (searched 3 elements)
Free List [ Size 4 ]: [ addr:1002 sz:1 ][ addr:1003 sz:5 ][ addr:1015 sz:1 ][ addr:1016 sz:84 ]
```

```sh
$ ./malloc.py -n 10 -H 0 -p FIRST -l SIZESORT- -s 0 -c
seed 0
size 100
baseAddr 1000
headerSize 0
alignment -1
policy FIRST
listOrder SIZESORT-
coalesce False
numOps 10
range 10
percentAlloc 50
allocList 
compute True

ptr[0] = Alloc(3) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:97 ]

Free(ptr[0])
returned 0
Free List [ Size 2 ]: [ addr:1003 sz:97 ][ addr:1000 sz:3 ]

ptr[1] = Alloc(5) returned 1003 (searched 1 elements)
Free List [ Size 2 ]: [ addr:1008 sz:92 ][ addr:1000 sz:3 ]

Free(ptr[1])
returned 0
Free List [ Size 3 ]: [ addr:1008 sz:92 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

ptr[2] = Alloc(8) returned 1008 (searched 1 elements)
Free List [ Size 3 ]: [ addr:1016 sz:84 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

Free(ptr[2])
returned 0
Free List [ Size 4 ]: [ addr:1016 sz:84 ][ addr:1008 sz:8 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

ptr[3] = Alloc(8) returned 1016 (searched 1 elements)
Free List [ Size 4 ]: [ addr:1024 sz:76 ][ addr:1008 sz:8 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

Free(ptr[3])
returned 0
Free List [ Size 5 ]: [ addr:1024 sz:76 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

ptr[4] = Alloc(2) returned 1024 (searched 1 elements)
Free List [ Size 5 ]: [ addr:1026 sz:74 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]

ptr[5] = Alloc(7) returned 1026 (searched 1 elements)
Free List [ Size 5 ]: [ addr:1033 sz:67 ][ addr:1008 sz:8 ][ addr:1016 sz:8 ][ addr:1003 sz:5 ][ addr:1000 sz:3 ]
```

- When we take the order sorted by the size of free chunk decreasing, the search time is minimized. However, the size of free list increases.

- Sorting the free list by address of the free chunk, coalescing becomes easier, and fragmentation tends to be reduced thus the search time could be reduced although in the above example coalescing was not applied.

#### 5

```sh
$ ./malloc.py -n 1000 -c | grep "returned -1" -n
(omitted)
```

```sh
$ ./malloc.py -n 1000 -c | grep "returned -1" -n | 
177
```

- Since each chunk is split into smaller sizes over time, larger allocation requests would fail over time.

```sh
$ ./malloc.py -n 1000 -l SIZESORT+ -c | grep Size | cut -d ':' -f 1 | sort | uniq
Free List [ Size 1 ]
Free List [ Size 10 ]
Free List [ Size 11 ]
Free List [ Size 12 ]
Free List [ Size 13 ]
Free List [ Size 14 ]
Free List [ Size 15 ]
Free List [ Size 16 ]
Free List [ Size 17 ]
Free List [ Size 18 ]
Free List [ Size 19 ]
Free List [ Size 2 ]
Free List [ Size 20 ]
Free List [ Size 21 ]
Free List [ Size 22 ]
Free List [ Size 23 ]
Free List [ Size 24 ]
Free List [ Size 25 ]
Free List [ Size 26 ]
Free List [ Size 27 ]
Free List [ Size 28 ]
Free List [ Size 29 ]
Free List [ Size 3 ]
Free List [ Size 30 ]
Free List [ Size 31 ]
Free List [ Size 32 ]
Free List [ Size 33 ]
Free List [ Size 34 ]
Free List [ Size 35 ]
Free List [ Size 4 ]
Free List [ Size 5 ]
Free List [ Size 6 ]
Free List [ Size 7 ]
Free List [ Size 8 ]
Free List [ Size 9 ]
headerSize 0
```

```sh
$ ./malloc.py -n 1000 -l ADDRSORT -C -c | grep Size | cut -d ':' -f 1 | sort | uniq
Free List [ Size 1 ]
Free List [ Size 2 ]
Free List [ Size 3 ]
Free List [ Size 4 ]
Free List [ Size 5 ]
Free List [ Size 6 ]
Free List [ Size 7 ]
Free List [ Size 8 ]
headerSize 0
```

- With coalescing, the number of elements of the free list becomes much smaller than without coalescing.

```sh
$ ./malloc.py -n 1000 -p FIRST -l ADDRSORT -C -c | grep Size | cut -d ':' -f 1 | sort | uniq
Free List [ Size 1 ]
Free List [ Size 2 ]
Free List [ Size 3 ]
Free List [ Size 4 ]
Free List [ Size 5 ]
Free List [ Size 6 ]
Free List [ Size 7 ]
Free List [ Size 8 ]
headerSize 0
```

```sh
$ ./malloc.py -n 1000 -p FIRST -l SIZESORT- -C -c | grep Size | cut -d ':' -f 1 | sort | uniq
Free List [ Size 1 ]
Free List [ Size 10 ]
Free List [ Size 100 ]
Free List [ Size 11 ]
Free List [ Size 12 ]
Free List [ Size 13 ]
Free List [ Size 14 ]
Free List [ Size 15 ]
Free List [ Size 16 ]
Free List [ Size 17 ]
Free List [ Size 18 ]
Free List [ Size 19 ]
Free List [ Size 2 ]
Free List [ Size 20 ]
Free List [ Size 21 ]
Free List [ Size 22 ]
Free List [ Size 23 ]
Free List [ Size 24 ]
Free List [ Size 25 ]
Free List [ Size 26 ]
Free List [ Size 27 ]
Free List [ Size 28 ]
Free List [ Size 29 ]
Free List [ Size 3 ]
Free List [ Size 30 ]
Free List [ Size 31 ]
Free List [ Size 32 ]
Free List [ Size 33 ]
Free List [ Size 34 ]
Free List [ Size 35 ]
Free List [ Size 36 ]
Free List [ Size 37 ]
Free List [ Size 38 ]
Free List [ Size 39 ]
Free List [ Size 4 ]
Free List [ Size 40 ]
Free List [ Size 41 ]
Free List [ Size 42 ]
Free List [ Size 43 ]
Free List [ Size 44 ]
Free List [ Size 45 ]
Free List [ Size 46 ]
Free List [ Size 47 ]
Free List [ Size 48 ]
Free List [ Size 49 ]
Free List [ Size 5 ]
Free List [ Size 50 ]
Free List [ Size 51 ]
Free List [ Size 52 ]
Free List [ Size 53 ]
Free List [ Size 54 ]
Free List [ Size 55 ]
Free List [ Size 56 ]
Free List [ Size 57 ]
Free List [ Size 58 ]
Free List [ Size 59 ]
Free List [ Size 6 ]
Free List [ Size 60 ]
Free List [ Size 61 ]
Free List [ Size 62 ]
Free List [ Size 63 ]
Free List [ Size 64 ]
Free List [ Size 65 ]
Free List [ Size 66 ]
Free List [ Size 67 ]
Free List [ Size 68 ]
Free List [ Size 69 ]
Free List [ Size 7 ]
Free List [ Size 70 ]
Free List [ Size 71 ]
Free List [ Size 72 ]
Free List [ Size 73 ]
Free List [ Size 74 ]
Free List [ Size 75 ]
Free List [ Size 76 ]
Free List [ Size 77 ]
Free List [ Size 78 ]
Free List [ Size 79 ]
Free List [ Size 8 ]
Free List [ Size 80 ]
Free List [ Size 81 ]
Free List [ Size 82 ]
Free List [ Size 83 ]
Free List [ Size 84 ]
Free List [ Size 85 ]
Free List [ Size 86 ]
Free List [ Size 87 ]
Free List [ Size 88 ]
Free List [ Size 89 ]
Free List [ Size 9 ]
Free List [ Size 90 ]
Free List [ Size 91 ]
Free List [ Size 92 ]
Free List [ Size 93 ]
Free List [ Size 94 ]
Free List [ Size 95 ]
Free List [ Size 96 ]
Free List [ Size 97 ]
Free List [ Size 98 ]
Free List [ Size 99 ]
headerSize 0
```

```sh
$ ./malloc.py -n 1000 -p FIRST -l SIZESORT+ -C -c | grep Size | cut -d ':' -f 1 | sort | uniq
Free List [ Size 1 ]
Free List [ Size 10 ]
Free List [ Size 11 ]
Free List [ Size 12 ]
Free List [ Size 13 ]
Free List [ Size 14 ]
Free List [ Size 15 ]
Free List [ Size 16 ]
Free List [ Size 17 ]
Free List [ Size 18 ]
Free List [ Size 19 ]
Free List [ Size 2 ]
Free List [ Size 20 ]
Free List [ Size 21 ]
Free List [ Size 22 ]
Free List [ Size 23 ]
Free List [ Size 24 ]
Free List [ Size 25 ]
Free List [ Size 26 ]
Free List [ Size 27 ]
Free List [ Size 28 ]
Free List [ Size 29 ]
Free List [ Size 3 ]
Free List [ Size 30 ]
Free List [ Size 31 ]
Free List [ Size 32 ]
Free List [ Size 33 ]
Free List [ Size 4 ]
Free List [ Size 5 ]
Free List [ Size 6 ]
Free List [ Size 7 ]
Free List [ Size 8 ]
Free List [ Size 9 ]
headerSize 0
```

- The ordering of list matters when we use the first fit.

- The first fit tends to split the front of the list. Sorting the list by address is helpful to clean these chunk by coalescing. On the other hand, sorting by size in descending order makes search fastest but the number of elements of the list becomes much more.

#### 6

```sh
$ ./malloc.py -n 100 -P 1 -c | grep "Alloc(" | wc -l
50
```

```sh
$ ./malloc.py -n 100 -P 100 -c | grep "Alloc(" | wc -l
100
```

- If the percent allocated fraction to higher than 50, the allocation occurs more often.

- When we set it close to 100, most of operation is allocations.

- Setting it close to 0, the half of the total operation is allocations and the rest half is frees.

#### 7

```sh
$ ./malloc.py -S 5 -A +1,+1,+1,+1,+1,-0,-1,-2,-3,-4 -c
seed 0
size 5
baseAddr 1000
headerSize 0
alignment -1
policy BEST
listOrder ADDRSORT
coalesce False
numOps 10
range 10
percentAlloc 50
allocList +1,+1,+1,+1,+1,-0,-1,-2,-3,-4
compute True

ptr[0] = Alloc(1) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1001 sz:4 ]

ptr[1] = Alloc(1) returned 1001 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1002 sz:3 ]

ptr[2] = Alloc(1) returned 1002 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:2 ]

ptr[3] = Alloc(1) returned 1003 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1004 sz:1 ]

ptr[4] = Alloc(1) returned 1004 (searched 1 elements)
Free List [ Size 0 ]: 

Free(ptr[0])
returned 0
Free List [ Size 1 ]: [ addr:1000 sz:1 ]

Free(ptr[1])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:1 ][ addr:1001 sz:1 ]

Free(ptr[2])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:1 ][ addr:1001 sz:1 ][ addr:1002 sz:1 ]

Free(ptr[3])
returned 0
Free List [ Size 4 ]: [ addr:1000 sz:1 ][ addr:1001 sz:1 ][ addr:1002 sz:1 ][ addr:1003 sz:1 ]

Free(ptr[4])
returned 0
Free List [ Size 5 ]: [ addr:1000 sz:1 ][ addr:1001 sz:1 ][ addr:1002 sz:1 ][ addr:1003 sz:1 ][ addr:1004 sz:1 ]
```

```sh
$ ./malloc.py -S 5 -l SIZESORT- -C -A +1,+1,+1,+1,+1,-0,-2,-4 -c
seed 0
size 5
baseAddr 1000
headerSize 0
alignment -1
policy BEST
listOrder SIZESORT-
coalesce True
numOps 10
range 10
percentAlloc 50
allocList +1,+1,+1,+1,+1,-0,-2,-4
compute True

ptr[0] = Alloc(1) returned 1000 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1001 sz:4 ]

ptr[1] = Alloc(1) returned 1001 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1002 sz:3 ]

ptr[2] = Alloc(1) returned 1002 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1003 sz:2 ]

ptr[3] = Alloc(1) returned 1003 (searched 1 elements)
Free List [ Size 1 ]: [ addr:1004 sz:1 ]

ptr[4] = Alloc(1) returned 1004 (searched 1 elements)
Free List [ Size 0 ]: 

Free(ptr[0])
returned 0
Free List [ Size 1 ]: [ addr:1000 sz:1 ]

Free(ptr[2])
returned 0
Free List [ Size 2 ]: [ addr:1000 sz:1 ][ addr:1002 sz:1 ]

Free(ptr[4])
returned 0
Free List [ Size 3 ]: [ addr:1000 sz:1 ][ addr:1002 sz:1 ][ addr:1004 sz:1 ]
```

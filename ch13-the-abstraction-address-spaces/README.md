# Ch13 The Abstraction: Address Spaces

## Contents

Virtualization

- Ch13 The Abstraction: Address Spaces

    - 13.1 Early Systems

    - 13.2 Multiprogramming and Time Sharing

    - 13.3 The Address Space

    - 13.4 Goals

    - 13.5 Summary

## Homework (Code)

### Questions

#### 2

```sh
$ free -h
               total        used        free      shared  buff/cache   available
Mem:            13Gi       1.5Gi        11Gi       6.0Mi       934Mi        11Gi
Swap:          4.0Gi          0B       4.0Gi
```

- I have 16GB memory, but `free` shows the total memory is `13Gi`.

#### 3

- `memory-user.c`

#### 4

- While running `memory-user` program, the memory usage totals increase

- When we kill the `memory-user` program the usage goes back to normal.

- When we use really large amounts of memory, swap memory would be used after all memory used.

#### 7

- There are also the vvar, vdso and vsyscall.

#### 8

- As the amount of memory used increases, the size of the heap also increases.

# Ch14 Interlude: Memory API

## Contents

Virtualization

- Ch14 Interlude: Memory API

    - 14.1 Types of Memory

    - 14.2 The `malloc()` Call

    - 14.3 The `free()` Call

    - 14.4 Common Errors

        - Forgetting to Allocate Memory

        - Not Allocating Enough Memory

        - Forgetting to Initialize Allocated Memory

        - Forgetting to Free Memory

        - Freeing Memory Before You are Done with It

        - Calling `free()` Incorrectly

        - Summary

    - 14.5 Underlying OS Support

    - 14.6 Other Calls

    - 14.7 Summary

## Homework (Codem

### Questions

#### 1

```sh
$ ./null 
Segmentation fault (core dumped)
```

#### 2

```
$ gdb null
...
(gdb) run
...
Program received signal SIGSEGV, Segmentation fault.
main () at null.c:8
8           printf("x: %d\n", *x);
(gdb)
```

#### 3

```sh
$ valgrind --leack-check=yes ./null
==2653== Memcheck, a memory error detector
==2653== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==2653== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==2653== Command: ./null
==2653==
==2653== Invalid read of size 4
==2653==    at 0x10913D: main (null.c:8)
==2653==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==2653==
==2653==
==2653== Process terminating with default action of signal 11 (SIGSEGV): dumping core
==2653==  Access not within mapped region at address 0x0
==2653==    at 0x10913D: main (null.c:8)
==2653==  If you believe this happened as a result of a stack
==2653==  overflow in your program's main thread (unlikely but
==2653==  possible), you can try to increase the size of the
==2653==  main thread stack using the --main-stacksize= flag.
==2653==  The main thread stack size used in this run was 8388608.
==2653==
==2653== HEAP SUMMARY:
==2653==     in use at exit: 0 bytes in 0 blocks
==2653==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==2653==
==2653== All heap blocks were freed -- no leaks are possible
==2653==
==2653== For lists of detected and suppressed errors, rerun with: -s
==2653== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```

- A pointer was referenced without allocating memory.

#### 4

- `forget-free.c`

```sh
$ gcc forget-free.c -o forget-free -g
$ ./forget-free
$
```

- This program runs without a problem.


```sh
$ gdb forget-free
...
(gdb) run
...
[Inferior 1 (process 8296) exited normally]
(gdb)
```

- When this program runs by `gdb`, process exited normally.

```sh
$ valgrind --leak-check=yes ./forget-free
valgrind --leak-check=yes ./forget-free
==9141== Memcheck, a memory error detector
==9141== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==9141== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==9141== Command: ./forget-free
==9141==
==9141==
==9141== HEAP SUMMARY:
==9141==     in use at exit: 4 bytes in 1 blocks
==9141==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==9141==
==9141== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==9141==    at 0x4841848: malloc (vg_replace_malloc.c:431)
==9141==    by 0x109146: main (forget-free.c:7)
==9141==
==9141== LEAK SUMMARY:
==9141==    definitely lost: 4 bytes in 1 blocks
==9141==    indirectly lost: 0 bytes in 0 blocks
==9141==      possibly lost: 0 bytes in 0 blocks
==9141==    still reachable: 0 bytes in 0 blocks
==9141==         suppressed: 0 bytes in 0 blocks
==9141==
==9141== For lists of detected and suppressed errors, rerun with: -s
==9141== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

- `valgrind` shows there are memory leaks.

#### 5

- `out-of-index.c`

```
$ gcc out-of-index.c -o out-of-index
$ ./out-of-index
$
``` 

- This program run without a problem.

```sh
$ valgrind --leak-check=yes ./out-of-index
==9183== Memcheck, a memory error detector
==9183== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==9183== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==9183== Command: ./out-of-index
==9183==
==9183== Invalid write of size 4
==9183==    at 0x109169: main (out-of-index.c:11)
==9183==  Address 0x4a501d0 is 0 bytes after a block of size 400 alloc'd
==9183==    at 0x4841848: malloc (vg_replace_malloc.c:431)
==9183==    by 0x10915A: main (out-of-index.c:9)
==9183==
==9183==
==9183== HEAP SUMMARY:
==9183==     in use at exit: 0 bytes in 0 blocks
==9183==   total heap usage: 1 allocs, 1 frees, 400 bytes allocated
==9183==
==9183== All heap blocks were freed -- no leaks are possible
==9183==
==9183== For lists of detected and suppressed errors, rerun with: -s
==9183== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

- `valgrind` shows there is an invalide write of size 4

#### 6

- `dangling.c`

```sh
$ gcc
$ ./dangling
1516703103
$
```

- The program ran without problem and print garbage value.

```sh
$ valgrind --leak-check=yes ./dangling
==3414== Memcheck, a memory error detector
==3414== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==3414== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==3414== Command: ./dangling
==3414==
==3414== Invalid read of size 4
==3414==    at 0x10916F: main (dangling-pointer.c:13)
==3414==  Address 0x4a50040 is 0 bytes inside a block of size 400 free'd
==3414==    at 0x484412F: free (vg_replace_malloc.c:974)
==3414==    by 0x10916E: main (dangling-pointer.c:11)
==3414==  Block was alloc'd at
==3414==    at 0x4841848: malloc (vg_replace_malloc.c:431)
==3414==    by 0x109163: main (dangling-pointer.c:9)
==3414==
0
==3414==
==3414== HEAP SUMMARY:
==3414==     in use at exit: 0 bytes in 0 blocks
==3414==   total heap usage: 2 allocs, 2 frees, 1,424 bytes allocated
==3414==
==3414== All heap blocks were freed -- no leaks are possible
==3414==
==3414== For lists of detected and suppressed errors, rerun with: -s
==3414== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

- When we use `valgrind`, it shows there is invalid read of size 4.

#### 7

- `free-somthing.c`

```sh
$ ./free-somthing
free(): invalid pointer
Aborted (core dumped)
$
```

- We can compile this program but the error occurs at runtime.

- Using `gdb` is helpful to find where the error occurs.

##### 8

- `vector.c`

- Comparing to a linked list, a vector can random access but inserting and deleting items is difficult.

```sh
$ valgrind --leak-check=yes ./vector
==9327== Memcheck, a memory error detector
==9327== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==9327== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==9327== Command: ./vector
==9327==
item 1: 1, item 2: 2
==9327==
==9327== HEAP SUMMARY:
==9327==     in use at exit: 0 bytes in 0 blocks
==9327==   total heap usage: 3 allocs, 3 frees, 1,036 bytes allocated
==9327==
==9327== All heap blocks were freed -- no leaks are possible
==9327==
==9327== For lists of detected and suppressed errors, rerun with: -s
==9327== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

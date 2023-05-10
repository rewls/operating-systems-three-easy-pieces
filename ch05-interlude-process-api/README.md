# Ch5 Interlude: Process API

## Contents

Virtualization

- Ch5 Interlude: Process APi

    - 5.1 The `fork()` System Call

    - 5.2 The `wait()` System Call

    - 5.3 Finally, The `exec()` System Call

    - 5.4 Why? Motivating The API

    - 5.5 Process Control And Users

    - 5.6 Useful Tools

## Homework (Simulation)

### Questions

#### 1

- We can guess as follow.

```

ARG seed 10
ARG fork_percentage 0.7
ARG actions 5
ARG action_list 
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve False

                           Process Tree:
                               a

Action: a forks b
Process Tree?
                               a
                               └── b
Action: a forks c
Process Tree?
                               a          
                               ├── b
                               └── c
Action: c EXITS
Process Tree?
                               a
                               └── b
Action: a forks d
Process Tree?
                               a          
                               ├── b
                               └── d
Action: a forks e
Process Tree?
                               a          
                               ├── b
                               ├── d
                               └── e
```

#### 2

- In lower `fork_percentage`, the resulting final process tree is simple because after process is created it will exit soon.

- In higher `fork_percentage`, the resulting final process tree becomes complex because process life becomes long.

#### 3

```

ARG seed -1
ARG fork_percentage 0.7
ARG actions 5
ARG action_list 
ARG show_tree True
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve False

                           Process Tree:
                               a

Action?
                               a
                               └── b
Action: a forks b
Action?
                               a
                               └── b
                                   └── c
Action: b forks c
Action?
                               a
                               └── b
                                   ├── c
                                   └── d
Action: b forks d
Action?
                               a
                               └── b
                                   ├── c
                                   └── d
                                       └── e
Action: d forks e
Action?
                               a
                               └── b
                                   ├── c
                                   ├── d
                                   │   └── e
                                   └── f
Action: b forks f
```

#### 4

- We can guess as follow.

```

ARG seed -1
ARG fork_percentage 0.7
ARG actions 5
ARG action_list a+b,b+c,c+d,c+e,c-
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve False

                           Process Tree:
                               a

Action: a forks b
Process Tree?
                               a
                               └── b
Action: b forks c
Process Tree?
                               a
                               └── b
                                   └── c
Action: c forks d
Process Tree?
                               a
                               └── b
                                   └── c
                                       └── d
Action: c forks e
Process Tree?
                               a
                               └── b
                                   └── c
                                       ├── d
                                       └── e
Action: c EXITS
Process Tree?
                               a
                               └── b
```

- But in `Action: c EXITS` the results is as follow.

```
                               a
                               ├── b
                               ├── d
                               └── e
```

- I think, although `c` exits child processes of `c` is still running, so the parent of child processes is changed to the root process `a`.

- If we use the `-R` flag, the result is as follow.

```

ARG seed -1
ARG fork_percentage 0.7
ARG actions 5
ARG action_list a+b,b+c,c+d,c+e,c-
ARG show_tree False
ARG just_final False
ARG leaf_only False
ARG local_reparent True
ARG print_style fancy
ARG solve True

                           Process Tree:
                               a

Action: a forks b
                               a
                               └── b
Action: b forks c
                               a
                               └── b
                                   └── c
Action: c forks d
                               a
                               └── b
                                   └── c
                                       └── d
Action: c forks e
                               a
                               └── b
                                   └── c
                                       ├── d
                                       └── e
Action: c EXITS
                               a
                               └── b
                                   ├── d
                                   └── e
```

- In this case, the parent of child processes is changed to the parent of `c`.

#### 5

```
ARG seed 1
ARG fork_percentage 0.7
ARG actions 5
ARG action_list 
ARG show_tree False
ARG just_final True
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve False

                           Process Tree:
                               a

Action: a forks b
Action: a forks c
Action: c forks d
Action: a forks e
Action: c EXITS

                        Final Process Tree?
                               a
                               ├── b
                               ├── e
                               └── d

```

```
ARG seed 2
ARG fork_percentage 0.7
ARG actions 5
ARG action_list 
ARG show_tree False
ARG just_final True
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve False

                           Process Tree:
                               a

Action: a forks b
Action: b EXITS
Action: a forks c
Action: c forks d
Action: a forks e

                        Final Process Tree?
                               a
                               ├── c
                               │   └── d
                               └── e
```

```
ARG seed 3
ARG fork_percentage 0.7
ARG actions 5
ARG action_list 
ARG show_tree False
ARG just_final True
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve False

                           Process Tree:
                               a

Action: a forks b
Action: b forks c
Action: a forks d
Action: d forks e
Action: b forks f

                        Final Process Tree?
                               a
                               ├── b
                               │   ├── c
                               │   └── f
                               └── d
                                   └── e

```

#### 6

```
ARG seed 11
ARG fork_percentage 0.7
ARG actions 5
ARG action_list 
ARG show_tree True
ARG just_final True
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve False

                           Process Tree:
                               a

Action?
Action: a forks b
Action?
Action: b forks c
Action?
Action: b forks d
Action?
Action: d forks e
Action?
Action: b forks f

                        Final Process Tree:
                               a
                               └── b
                                   ├── c
                                   ├── d
                                   │   └── e
                                   └── f
```

- We don't know the order of actions but in this case the number of actions is equal to the number of child process of the root process so actions themselves is determined.

```
ARG seed 11
ARG fork_percentage 0.6
ARG actions 5
ARG action_list 
ARG show_tree True
ARG just_final True
ARG leaf_only False
ARG local_reparent False
ARG print_style fancy
ARG solve False

                           Process Tree:
                               a

Action?
Action?
Action?
Action?
Action?

                        Final Process Tree:
                               a
                               ├── b
                               │   └── c
                               └── e
```

- In this case the number of actions is different from the number of child processes of the root process, so we can't determine the actions. Because we don't know what process was forked by what process.

## Homework (Code)

### Questions

#### 1

- `01.c`

- The value of the variable in the child process is the same as previously set.

- When both the child and parent change the value of `x`, the value changes independently in each. Since each of the parent and child has its own address space, changing values in each does not affect each other.

#### 2

- `02.c`

- Both the child and parent can access the file descriptor.

- Writing is done in nondeterministic order. I think writing at the same time actually does not happen because scheduler determines the order.

#### 3

- `03.c`

- We can ensure that the child process always prints first without calling `wait()` in the parent.

- One of the solutions is using `kill()` and `signal()`.  

#### 4

- `04.c`

```
$ man exec.3
```

#### 5

- `05.c`

- `wait()` returns child process pid.

- If we use `wait()` in the child, it returns -1 and `ECHILD` error occurs.

#### 6

- `06.c`

- When we want to specify the pid to wait and options, `waitpid()` is useful.

#### 7

- `07.c`

- `printf()` write output to stdout, the standard output stream. If we close standard output, we cannot write to stdout. But return value is the number of characters we want to print in that the output error doesn't occur.

#### 8

- `08.c`

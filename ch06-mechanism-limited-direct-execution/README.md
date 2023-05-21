# Ch6 Mechanism: Limited Direct Execution

## Contents

Virtualization

- Ch6 Mechanism: Limited Direct Execution

    - 6.1 Basic Techniue: Limited Direct Execution

    - 6.2 Problem #1: Restricted Operations

    - 6.3 Problem #2: Switching Between Processes

        - A Cooperative Approach: Wait for System Calls

        - A Non-Cooperative Approach: The OS Takes Control

        - Saving and Restoring Context

    - 6.4 Worried about Concurrency?

## Homework (Measurement)

- `measure-system-call-cost.c`

- In my system, the cost of a system call is about 145 ns and the cost of a context switch is about 1.26 ms.

- `lat_ctx` in `lmbench` is used to measure the cost of a context switch.

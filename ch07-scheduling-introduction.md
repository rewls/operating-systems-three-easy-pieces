# Ch7 Scheduling: Introduction

## Contents

Virtualization

- Ch7 Scheduling: Introduction

    - 7.1 Workload Assumptions

    - 7.2 Scheduling Metrics

    - 7.3 First In, First Out (FIFO)

    - 7.4 Shortest Job First (SJF)

    - 7.5 Shortest Time-to-Completion First (STCF)

    - 7.6 A New Metric: Response Time

    - 7.7 Round Robin

    - 7.8 Incorporating I/O

    - 7.9 No More Oracle

## Homework (Simulation)

### Questions

#### 1

- FIFO

```
Execution trace:
  [time   0] Run job 0 for 200.00 secs (DONE at 200.00)
  [time 200] Run job 1 for 200.00 secs (DONE at 400.00)
  [time 400] Run job 2 for 200.00 secs (DONE at 600.00)

Final statistics:
  Job   0 -- Response:   0.00  Turnaround 200.00  Wait   0.00
  Job   1 -- Response: 200.00  Turnaround 400.00  Wait 200.00
  Job   2 -- Response: 400.00  Turnaround 600.00  Wait 400.00

  Average -- Response: 200.00  Turnaround 400.00  Wait 200.00
```

- SJF

```
Execution trace:
  [time   0] Run job 0 for 200.00 secs (DONE at 200.00)
  [time 200] Run job 1 for 200.00 secs (DONE at 400.00)
  [time 400] Run job 2 for 200.00 secs (DONE at 600.00)

Final statistics:
  Job   0 -- Response:   0.00  Turnaround 200.00  Wait   0.00
  Job   1 -- Response: 200.00  Turnaround 400.00  Wait 200.00
  Job   2 -- Response: 400.00  Turnaround 600.00  Wait 400.00

  Average -- Response: 200.00  Turnaround 400.00  Wait 200.00
```

#### 2

- FIFO

```
Execution trace:
  [time   0] Run job 0 for 100.00 secs (DONE at 100.00)
  [time 100] Run job 1 for 200.00 secs (DONE at 300.00)
  [time 300] Run job 2 for 300.00 secs (DONE at 600.00)

Final statistics:
  Job   0 -- Response:   0.00  Turnaround 100.00  Wait   0.00
  Job   1 -- Response: 100.00  Turnaround 300.00  Wait 100.00
  Job   2 -- Response: 300.00  Turnaround 600.00  Wait 300.00

  Average -- Response: 133.33  Turnaround 333.33  Wait 133.33
```

- SJF

```
Execution trace:
  [time   0] Run job 0 for 100.00 secs (DONE at 100.00)
  [time 100] Run job 1 for 200.00 secs (DONE at 300.00)
  [time 300] Run job 2 for 300.00 secs (DONE at 600.00)

Final statistics:
  Job   0 -- Response:   0.00  Turnaround 100.00  Wait   0.00
  Job   1 -- Response: 100.00  Turnaround 300.00  Wait 100.00
  Job   2 -- Response: 300.00  Turnaround 600.00  Wait 300.00

  Average -- Response: 133.33  Turnaround 333.33  Wait 133.33
```

#### 3

<details>
<summary>Answer</summary>
<div markdown=1>
<pre>
Execution trace:
  [time   0] Run job 0 for   1.00 secs (DONE at   1.00)
  [time   1] Run job 1 for   1.00 secs (DONE at   2.00)
  [time   2] Run job 2 for   1.00 secs (DONE at   3.00)
  [time   3] Run job 0 for   1.00 secs (DONE at   4.00)
  [time   4] Run job 1 for   1.00 secs (DONE at   5.00)
  [time   5] Run job 2 for   1.00 secs (DONE at   6.00)
  [time   6] Run job 0 for   1.00 secs (DONE at   7.00)
  [time   7] Run job 1 for   1.00 secs (DONE at   8.00)
  [time   8] Run job 2 for   1.00 secs (DONE at   9.00)
  [time   9] Run job 0 for   1.00 secs (DONE at  10.00)
  [time  10] Run job 1 for   1.00 secs (DONE at  11.00)
  [time  11] Run job 2 for   1.00 secs (DONE at  12.00)
  [time  12] Run job 0 for   1.00 secs (DONE at  13.00)
  [time  13] Run job 1 for   1.00 secs (DONE at  14.00)
  [time  14] Run job 2 for   1.00 secs (DONE at  15.00)
  [time  15] Run job 0 for   1.00 secs (DONE at  16.00)
  [time  16] Run job 1 for   1.00 secs (DONE at  17.00)
  [time  17] Run job 2 for   1.00 secs (DONE at  18.00)
  [time  18] Run job 0 for   1.00 secs (DONE at  19.00)
  [time  19] Run job 1 for   1.00 secs (DONE at  20.00)
  [time  20] Run job 2 for   1.00 secs (DONE at  21.00)
  [time  21] Run job 0 for   1.00 secs (DONE at  22.00)
  [time  22] Run job 1 for   1.00 secs (DONE at  23.00)
  [time  23] Run job 2 for   1.00 secs (DONE at  24.00)
  [time  24] Run job 0 for   1.00 secs (DONE at  25.00)
  [time  25] Run job 1 for   1.00 secs (DONE at  26.00)
  [time  26] Run job 2 for   1.00 secs (DONE at  27.00)
  [time  27] Run job 0 for   1.00 secs (DONE at  28.00)
  [time  28] Run job 1 for   1.00 secs (DONE at  29.00)
  [time  29] Run job 2 for   1.00 secs (DONE at  30.00)
  [time  30] Run job 0 for   1.00 secs (DONE at  31.00)
  [time  31] Run job 1 for   1.00 secs (DONE at  32.00)
  [time  32] Run job 2 for   1.00 secs (DONE at  33.00)
  [time  33] Run job 0 for   1.00 secs (DONE at  34.00)
  [time  34] Run job 1 for   1.00 secs (DONE at  35.00)
  [time  35] Run job 2 for   1.00 secs (DONE at  36.00)
  [time  36] Run job 0 for   1.00 secs (DONE at  37.00)
  [time  37] Run job 1 for   1.00 secs (DONE at  38.00)
  [time  38] Run job 2 for   1.00 secs (DONE at  39.00)
  [time  39] Run job 0 for   1.00 secs (DONE at  40.00)
  [time  40] Run job 1 for   1.00 secs (DONE at  41.00)
  [time  41] Run job 2 for   1.00 secs (DONE at  42.00)
  [time  42] Run job 0 for   1.00 secs (DONE at  43.00)
  [time  43] Run job 1 for   1.00 secs (DONE at  44.00)
  [time  44] Run job 2 for   1.00 secs (DONE at  45.00)
  [time  45] Run job 0 for   1.00 secs (DONE at  46.00)
  [time  46] Run job 1 for   1.00 secs (DONE at  47.00)
  [time  47] Run job 2 for   1.00 secs (DONE at  48.00)
  [time  48] Run job 0 for   1.00 secs (DONE at  49.00)
  [time  49] Run job 1 for   1.00 secs (DONE at  50.00)
  [time  50] Run job 2 for   1.00 secs (DONE at  51.00)
  [time  51] Run job 0 for   1.00 secs (DONE at  52.00)
  [time  52] Run job 1 for   1.00 secs (DONE at  53.00)
  [time  53] Run job 2 for   1.00 secs (DONE at  54.00)
  [time  54] Run job 0 for   1.00 secs (DONE at  55.00)
  [time  55] Run job 1 for   1.00 secs (DONE at  56.00)
  [time  56] Run job 2 for   1.00 secs (DONE at  57.00)
  [time  57] Run job 0 for   1.00 secs (DONE at  58.00)
  [time  58] Run job 1 for   1.00 secs (DONE at  59.00)
  [time  59] Run job 2 for   1.00 secs (DONE at  60.00)
  [time  60] Run job 0 for   1.00 secs (DONE at  61.00)
  [time  61] Run job 1 for   1.00 secs (DONE at  62.00)
  [time  62] Run job 2 for   1.00 secs (DONE at  63.00)
  [time  63] Run job 0 for   1.00 secs (DONE at  64.00)
  [time  64] Run job 1 for   1.00 secs (DONE at  65.00)
  [time  65] Run job 2 for   1.00 secs (DONE at  66.00)
  [time  66] Run job 0 for   1.00 secs (DONE at  67.00)
  [time  67] Run job 1 for   1.00 secs (DONE at  68.00)
  [time  68] Run job 2 for   1.00 secs (DONE at  69.00)
  [time  69] Run job 0 for   1.00 secs (DONE at  70.00)
  [time  70] Run job 1 for   1.00 secs (DONE at  71.00)
  [time  71] Run job 2 for   1.00 secs (DONE at  72.00)
  [time  72] Run job 0 for   1.00 secs (DONE at  73.00)
  [time  73] Run job 1 for   1.00 secs (DONE at  74.00)
  [time  74] Run job 2 for   1.00 secs (DONE at  75.00)
  [time  75] Run job 0 for   1.00 secs (DONE at  76.00)
  [time  76] Run job 1 for   1.00 secs (DONE at  77.00)
  [time  77] Run job 2 for   1.00 secs (DONE at  78.00)
  [time  78] Run job 0 for   1.00 secs (DONE at  79.00)
  [time  79] Run job 1 for   1.00 secs (DONE at  80.00)
  [time  80] Run job 2 for   1.00 secs (DONE at  81.00)
  [time  81] Run job 0 for   1.00 secs (DONE at  82.00)
  [time  82] Run job 1 for   1.00 secs (DONE at  83.00)
  [time  83] Run job 2 for   1.00 secs (DONE at  84.00)
  [time  84] Run job 0 for   1.00 secs (DONE at  85.00)
  [time  85] Run job 1 for   1.00 secs (DONE at  86.00)
  [time  86] Run job 2 for   1.00 secs (DONE at  87.00)
  [time  87] Run job 0 for   1.00 secs (DONE at  88.00)
  [time  88] Run job 1 for   1.00 secs (DONE at  89.00)
  [time  89] Run job 2 for   1.00 secs (DONE at  90.00)
  [time  90] Run job 0 for   1.00 secs (DONE at  91.00)
  [time  91] Run job 1 for   1.00 secs (DONE at  92.00)
  [time  92] Run job 2 for   1.00 secs (DONE at  93.00)
  [time  93] Run job 0 for   1.00 secs (DONE at  94.00)
  [time  94] Run job 1 for   1.00 secs (DONE at  95.00)
  [time  95] Run job 2 for   1.00 secs (DONE at  96.00)
  [time  96] Run job 0 for   1.00 secs (DONE at  97.00)
  [time  97] Run job 1 for   1.00 secs (DONE at  98.00)
  [time  98] Run job 2 for   1.00 secs (DONE at  99.00)
  [time  99] Run job 0 for   1.00 secs (DONE at 100.00)
  [time 100] Run job 1 for   1.00 secs (DONE at 101.00)
  [time 101] Run job 2 for   1.00 secs (DONE at 102.00)
  [time 102] Run job 0 for   1.00 secs (DONE at 103.00)
  [time 103] Run job 1 for   1.00 secs (DONE at 104.00)
  [time 104] Run job 2 for   1.00 secs (DONE at 105.00)
  [time 105] Run job 0 for   1.00 secs (DONE at 106.00)
  [time 106] Run job 1 for   1.00 secs (DONE at 107.00)
  [time 107] Run job 2 for   1.00 secs (DONE at 108.00)
  [time 108] Run job 0 for   1.00 secs (DONE at 109.00)
  [time 109] Run job 1 for   1.00 secs (DONE at 110.00)
  [time 110] Run job 2 for   1.00 secs (DONE at 111.00)
  [time 111] Run job 0 for   1.00 secs (DONE at 112.00)
  [time 112] Run job 1 for   1.00 secs (DONE at 113.00)
  [time 113] Run job 2 for   1.00 secs (DONE at 114.00)
  [time 114] Run job 0 for   1.00 secs (DONE at 115.00)
  [time 115] Run job 1 for   1.00 secs (DONE at 116.00)
  [time 116] Run job 2 for   1.00 secs (DONE at 117.00)
  [time 117] Run job 0 for   1.00 secs (DONE at 118.00)
  [time 118] Run job 1 for   1.00 secs (DONE at 119.00)
  [time 119] Run job 2 for   1.00 secs (DONE at 120.00)
  [time 120] Run job 0 for   1.00 secs (DONE at 121.00)
  [time 121] Run job 1 for   1.00 secs (DONE at 122.00)
  [time 122] Run job 2 for   1.00 secs (DONE at 123.00)
  [time 123] Run job 0 for   1.00 secs (DONE at 124.00)
  [time 124] Run job 1 for   1.00 secs (DONE at 125.00)
  [time 125] Run job 2 for   1.00 secs (DONE at 126.00)
  [time 126] Run job 0 for   1.00 secs (DONE at 127.00)
  [time 127] Run job 1 for   1.00 secs (DONE at 128.00)
  [time 128] Run job 2 for   1.00 secs (DONE at 129.00)
  [time 129] Run job 0 for   1.00 secs (DONE at 130.00)
  [time 130] Run job 1 for   1.00 secs (DONE at 131.00)
  [time 131] Run job 2 for   1.00 secs (DONE at 132.00)
  [time 132] Run job 0 for   1.00 secs (DONE at 133.00)
  [time 133] Run job 1 for   1.00 secs (DONE at 134.00)
  [time 134] Run job 2 for   1.00 secs (DONE at 135.00)
  [time 135] Run job 0 for   1.00 secs (DONE at 136.00)
  [time 136] Run job 1 for   1.00 secs (DONE at 137.00)
  [time 137] Run job 2 for   1.00 secs (DONE at 138.00)
  [time 138] Run job 0 for   1.00 secs (DONE at 139.00)
  [time 139] Run job 1 for   1.00 secs (DONE at 140.00)
  [time 140] Run job 2 for   1.00 secs (DONE at 141.00)
  [time 141] Run job 0 for   1.00 secs (DONE at 142.00)
  [time 142] Run job 1 for   1.00 secs (DONE at 143.00)
  [time 143] Run job 2 for   1.00 secs (DONE at 144.00)
  [time 144] Run job 0 for   1.00 secs (DONE at 145.00)
  [time 145] Run job 1 for   1.00 secs (DONE at 146.00)
  [time 146] Run job 2 for   1.00 secs (DONE at 147.00)
  [time 147] Run job 0 for   1.00 secs (DONE at 148.00)
  [time 148] Run job 1 for   1.00 secs (DONE at 149.00)
  [time 149] Run job 2 for   1.00 secs (DONE at 150.00)
  [time 150] Run job 0 for   1.00 secs (DONE at 151.00)
  [time 151] Run job 1 for   1.00 secs (DONE at 152.00)
  [time 152] Run job 2 for   1.00 secs (DONE at 153.00)
  [time 153] Run job 0 for   1.00 secs (DONE at 154.00)
  [time 154] Run job 1 for   1.00 secs (DONE at 155.00)
  [time 155] Run job 2 for   1.00 secs (DONE at 156.00)
  [time 156] Run job 0 for   1.00 secs (DONE at 157.00)
  [time 157] Run job 1 for   1.00 secs (DONE at 158.00)
  [time 158] Run job 2 for   1.00 secs (DONE at 159.00)
  [time 159] Run job 0 for   1.00 secs (DONE at 160.00)
  [time 160] Run job 1 for   1.00 secs (DONE at 161.00)
  [time 161] Run job 2 for   1.00 secs (DONE at 162.00)
  [time 162] Run job 0 for   1.00 secs (DONE at 163.00)
  [time 163] Run job 1 for   1.00 secs (DONE at 164.00)
  [time 164] Run job 2 for   1.00 secs (DONE at 165.00)
  [time 165] Run job 0 for   1.00 secs (DONE at 166.00)
  [time 166] Run job 1 for   1.00 secs (DONE at 167.00)
  [time 167] Run job 2 for   1.00 secs (DONE at 168.00)
  [time 168] Run job 0 for   1.00 secs (DONE at 169.00)
  [time 169] Run job 1 for   1.00 secs (DONE at 170.00)
  [time 170] Run job 2 for   1.00 secs (DONE at 171.00)
  [time 171] Run job 0 for   1.00 secs (DONE at 172.00)
  [time 172] Run job 1 for   1.00 secs (DONE at 173.00)
  [time 173] Run job 2 for   1.00 secs (DONE at 174.00)
  [time 174] Run job 0 for   1.00 secs (DONE at 175.00)
  [time 175] Run job 1 for   1.00 secs (DONE at 176.00)
  [time 176] Run job 2 for   1.00 secs (DONE at 177.00)
  [time 177] Run job 0 for   1.00 secs (DONE at 178.00)
  [time 178] Run job 1 for   1.00 secs (DONE at 179.00)
  [time 179] Run job 2 for   1.00 secs (DONE at 180.00)
  [time 180] Run job 0 for   1.00 secs (DONE at 181.00)
  [time 181] Run job 1 for   1.00 secs (DONE at 182.00)
  [time 182] Run job 2 for   1.00 secs (DONE at 183.00)
  [time 183] Run job 0 for   1.00 secs (DONE at 184.00)
  [time 184] Run job 1 for   1.00 secs (DONE at 185.00)
  [time 185] Run job 2 for   1.00 secs (DONE at 186.00)
  [time 186] Run job 0 for   1.00 secs (DONE at 187.00)
  [time 187] Run job 1 for   1.00 secs (DONE at 188.00)
  [time 188] Run job 2 for   1.00 secs (DONE at 189.00)
  [time 189] Run job 0 for   1.00 secs (DONE at 190.00)
  [time 190] Run job 1 for   1.00 secs (DONE at 191.00)
  [time 191] Run job 2 for   1.00 secs (DONE at 192.00)
  [time 192] Run job 0 for   1.00 secs (DONE at 193.00)
  [time 193] Run job 1 for   1.00 secs (DONE at 194.00)
  [time 194] Run job 2 for   1.00 secs (DONE at 195.00)
  [time 195] Run job 0 for   1.00 secs (DONE at 196.00)
  [time 196] Run job 1 for   1.00 secs (DONE at 197.00)
  [time 197] Run job 2 for   1.00 secs (DONE at 198.00)
  [time 198] Run job 0 for   1.00 secs (DONE at 199.00)
  [time 199] Run job 1 for   1.00 secs (DONE at 200.00)
  [time 200] Run job 2 for   1.00 secs (DONE at 201.00)
  [time 201] Run job 0 for   1.00 secs (DONE at 202.00)
  [time 202] Run job 1 for   1.00 secs (DONE at 203.00)
  [time 203] Run job 2 for   1.00 secs (DONE at 204.00)
  [time 204] Run job 0 for   1.00 secs (DONE at 205.00)
  [time 205] Run job 1 for   1.00 secs (DONE at 206.00)
  [time 206] Run job 2 for   1.00 secs (DONE at 207.00)
  [time 207] Run job 0 for   1.00 secs (DONE at 208.00)
  [time 208] Run job 1 for   1.00 secs (DONE at 209.00)
  [time 209] Run job 2 for   1.00 secs (DONE at 210.00)
  [time 210] Run job 0 for   1.00 secs (DONE at 211.00)
  [time 211] Run job 1 for   1.00 secs (DONE at 212.00)
  [time 212] Run job 2 for   1.00 secs (DONE at 213.00)
  [time 213] Run job 0 for   1.00 secs (DONE at 214.00)
  [time 214] Run job 1 for   1.00 secs (DONE at 215.00)
  [time 215] Run job 2 for   1.00 secs (DONE at 216.00)
  [time 216] Run job 0 for   1.00 secs (DONE at 217.00)
  [time 217] Run job 1 for   1.00 secs (DONE at 218.00)
  [time 218] Run job 2 for   1.00 secs (DONE at 219.00)
  [time 219] Run job 0 for   1.00 secs (DONE at 220.00)
  [time 220] Run job 1 for   1.00 secs (DONE at 221.00)
  [time 221] Run job 2 for   1.00 secs (DONE at 222.00)
  [time 222] Run job 0 for   1.00 secs (DONE at 223.00)
  [time 223] Run job 1 for   1.00 secs (DONE at 224.00)
  [time 224] Run job 2 for   1.00 secs (DONE at 225.00)
  [time 225] Run job 0 for   1.00 secs (DONE at 226.00)
  [time 226] Run job 1 for   1.00 secs (DONE at 227.00)
  [time 227] Run job 2 for   1.00 secs (DONE at 228.00)
  [time 228] Run job 0 for   1.00 secs (DONE at 229.00)
  [time 229] Run job 1 for   1.00 secs (DONE at 230.00)
  [time 230] Run job 2 for   1.00 secs (DONE at 231.00)
  [time 231] Run job 0 for   1.00 secs (DONE at 232.00)
  [time 232] Run job 1 for   1.00 secs (DONE at 233.00)
  [time 233] Run job 2 for   1.00 secs (DONE at 234.00)
  [time 234] Run job 0 for   1.00 secs (DONE at 235.00)
  [time 235] Run job 1 for   1.00 secs (DONE at 236.00)
  [time 236] Run job 2 for   1.00 secs (DONE at 237.00)
  [time 237] Run job 0 for   1.00 secs (DONE at 238.00)
  [time 238] Run job 1 for   1.00 secs (DONE at 239.00)
  [time 239] Run job 2 for   1.00 secs (DONE at 240.00)
  [time 240] Run job 0 for   1.00 secs (DONE at 241.00)
  [time 241] Run job 1 for   1.00 secs (DONE at 242.00)
  [time 242] Run job 2 for   1.00 secs (DONE at 243.00)
  [time 243] Run job 0 for   1.00 secs (DONE at 244.00)
  [time 244] Run job 1 for   1.00 secs (DONE at 245.00)
  [time 245] Run job 2 for   1.00 secs (DONE at 246.00)
  [time 246] Run job 0 for   1.00 secs (DONE at 247.00)
  [time 247] Run job 1 for   1.00 secs (DONE at 248.00)
  [time 248] Run job 2 for   1.00 secs (DONE at 249.00)
  [time 249] Run job 0 for   1.00 secs (DONE at 250.00)
  [time 250] Run job 1 for   1.00 secs (DONE at 251.00)
  [time 251] Run job 2 for   1.00 secs (DONE at 252.00)
  [time 252] Run job 0 for   1.00 secs (DONE at 253.00)
  [time 253] Run job 1 for   1.00 secs (DONE at 254.00)
  [time 254] Run job 2 for   1.00 secs (DONE at 255.00)
  [time 255] Run job 0 for   1.00 secs (DONE at 256.00)
  [time 256] Run job 1 for   1.00 secs (DONE at 257.00)
  [time 257] Run job 2 for   1.00 secs (DONE at 258.00)
  [time 258] Run job 0 for   1.00 secs (DONE at 259.00)
  [time 259] Run job 1 for   1.00 secs (DONE at 260.00)
  [time 260] Run job 2 for   1.00 secs (DONE at 261.00)
  [time 261] Run job 0 for   1.00 secs (DONE at 262.00)
  [time 262] Run job 1 for   1.00 secs (DONE at 263.00)
  [time 263] Run job 2 for   1.00 secs (DONE at 264.00)
  [time 264] Run job 0 for   1.00 secs (DONE at 265.00)
  [time 265] Run job 1 for   1.00 secs (DONE at 266.00)
  [time 266] Run job 2 for   1.00 secs (DONE at 267.00)
  [time 267] Run job 0 for   1.00 secs (DONE at 268.00)
  [time 268] Run job 1 for   1.00 secs (DONE at 269.00)
  [time 269] Run job 2 for   1.00 secs (DONE at 270.00)
  [time 270] Run job 0 for   1.00 secs (DONE at 271.00)
  [time 271] Run job 1 for   1.00 secs (DONE at 272.00)
  [time 272] Run job 2 for   1.00 secs (DONE at 273.00)
  [time 273] Run job 0 for   1.00 secs (DONE at 274.00)
  [time 274] Run job 1 for   1.00 secs (DONE at 275.00)
  [time 275] Run job 2 for   1.00 secs (DONE at 276.00)
  [time 276] Run job 0 for   1.00 secs (DONE at 277.00)
  [time 277] Run job 1 for   1.00 secs (DONE at 278.00)
  [time 278] Run job 2 for   1.00 secs (DONE at 279.00)
  [time 279] Run job 0 for   1.00 secs (DONE at 280.00)
  [time 280] Run job 1 for   1.00 secs (DONE at 281.00)
  [time 281] Run job 2 for   1.00 secs (DONE at 282.00)
  [time 282] Run job 0 for   1.00 secs (DONE at 283.00)
  [time 283] Run job 1 for   1.00 secs (DONE at 284.00)
  [time 284] Run job 2 for   1.00 secs (DONE at 285.00)
  [time 285] Run job 0 for   1.00 secs (DONE at 286.00)
  [time 286] Run job 1 for   1.00 secs (DONE at 287.00)
  [time 287] Run job 2 for   1.00 secs (DONE at 288.00)
  [time 288] Run job 0 for   1.00 secs (DONE at 289.00)
  [time 289] Run job 1 for   1.00 secs (DONE at 290.00)
  [time 290] Run job 2 for   1.00 secs (DONE at 291.00)
  [time 291] Run job 0 for   1.00 secs (DONE at 292.00)
  [time 292] Run job 1 for   1.00 secs (DONE at 293.00)
  [time 293] Run job 2 for   1.00 secs (DONE at 294.00)
  [time 294] Run job 0 for   1.00 secs (DONE at 295.00)
  [time 295] Run job 1 for   1.00 secs (DONE at 296.00)
  [time 296] Run job 2 for   1.00 secs (DONE at 297.00)
  [time 297] Run job 0 for   1.00 secs (DONE at 298.00)
  [time 298] Run job 1 for   1.00 secs (DONE at 299.00)
  [time 299] Run job 2 for   1.00 secs (DONE at 300.00)
  [time 300] Run job 1 for   1.00 secs (DONE at 301.00)
  [time 301] Run job 2 for   1.00 secs (DONE at 302.00)
  [time 302] Run job 1 for   1.00 secs (DONE at 303.00)
  [time 303] Run job 2 for   1.00 secs (DONE at 304.00)
  [time 304] Run job 1 for   1.00 secs (DONE at 305.00)
  [time 305] Run job 2 for   1.00 secs (DONE at 306.00)
  [time 306] Run job 1 for   1.00 secs (DONE at 307.00)
  [time 307] Run job 2 for   1.00 secs (DONE at 308.00)
  [time 308] Run job 1 for   1.00 secs (DONE at 309.00)
  [time 309] Run job 2 for   1.00 secs (DONE at 310.00)
  [time 310] Run job 1 for   1.00 secs (DONE at 311.00)
  [time 311] Run job 2 for   1.00 secs (DONE at 312.00)
  [time 312] Run job 1 for   1.00 secs (DONE at 313.00)
  [time 313] Run job 2 for   1.00 secs (DONE at 314.00)
  [time 314] Run job 1 for   1.00 secs (DONE at 315.00)
  [time 315] Run job 2 for   1.00 secs (DONE at 316.00)
  [time 316] Run job 1 for   1.00 secs (DONE at 317.00)
  [time 317] Run job 2 for   1.00 secs (DONE at 318.00)
  [time 318] Run job 1 for   1.00 secs (DONE at 319.00)
  [time 319] Run job 2 for   1.00 secs (DONE at 320.00)
  [time 320] Run job 1 for   1.00 secs (DONE at 321.00)
  [time 321] Run job 2 for   1.00 secs (DONE at 322.00)
  [time 322] Run job 1 for   1.00 secs (DONE at 323.00)
  [time 323] Run job 2 for   1.00 secs (DONE at 324.00)
  [time 324] Run job 1 for   1.00 secs (DONE at 325.00)
  [time 325] Run job 2 for   1.00 secs (DONE at 326.00)
  [time 326] Run job 1 for   1.00 secs (DONE at 327.00)
  [time 327] Run job 2 for   1.00 secs (DONE at 328.00)
  [time 328] Run job 1 for   1.00 secs (DONE at 329.00)
  [time 329] Run job 2 for   1.00 secs (DONE at 330.00)
  [time 330] Run job 1 for   1.00 secs (DONE at 331.00)
  [time 331] Run job 2 for   1.00 secs (DONE at 332.00)
  [time 332] Run job 1 for   1.00 secs (DONE at 333.00)
  [time 333] Run job 2 for   1.00 secs (DONE at 334.00)
  [time 334] Run job 1 for   1.00 secs (DONE at 335.00)
  [time 335] Run job 2 for   1.00 secs (DONE at 336.00)
  [time 336] Run job 1 for   1.00 secs (DONE at 337.00)
  [time 337] Run job 2 for   1.00 secs (DONE at 338.00)
  [time 338] Run job 1 for   1.00 secs (DONE at 339.00)
  [time 339] Run job 2 for   1.00 secs (DONE at 340.00)
  [time 340] Run job 1 for   1.00 secs (DONE at 341.00)
  [time 341] Run job 2 for   1.00 secs (DONE at 342.00)
  [time 342] Run job 1 for   1.00 secs (DONE at 343.00)
  [time 343] Run job 2 for   1.00 secs (DONE at 344.00)
  [time 344] Run job 1 for   1.00 secs (DONE at 345.00)
  [time 345] Run job 2 for   1.00 secs (DONE at 346.00)
  [time 346] Run job 1 for   1.00 secs (DONE at 347.00)
  [time 347] Run job 2 for   1.00 secs (DONE at 348.00)
  [time 348] Run job 1 for   1.00 secs (DONE at 349.00)
  [time 349] Run job 2 for   1.00 secs (DONE at 350.00)
  [time 350] Run job 1 for   1.00 secs (DONE at 351.00)
  [time 351] Run job 2 for   1.00 secs (DONE at 352.00)
  [time 352] Run job 1 for   1.00 secs (DONE at 353.00)
  [time 353] Run job 2 for   1.00 secs (DONE at 354.00)
  [time 354] Run job 1 for   1.00 secs (DONE at 355.00)
  [time 355] Run job 2 for   1.00 secs (DONE at 356.00)
  [time 356] Run job 1 for   1.00 secs (DONE at 357.00)
  [time 357] Run job 2 for   1.00 secs (DONE at 358.00)
  [time 358] Run job 1 for   1.00 secs (DONE at 359.00)
  [time 359] Run job 2 for   1.00 secs (DONE at 360.00)
  [time 360] Run job 1 for   1.00 secs (DONE at 361.00)
  [time 361] Run job 2 for   1.00 secs (DONE at 362.00)
  [time 362] Run job 1 for   1.00 secs (DONE at 363.00)
  [time 363] Run job 2 for   1.00 secs (DONE at 364.00)
  [time 364] Run job 1 for   1.00 secs (DONE at 365.00)
  [time 365] Run job 2 for   1.00 secs (DONE at 366.00)
  [time 366] Run job 1 for   1.00 secs (DONE at 367.00)
  [time 367] Run job 2 for   1.00 secs (DONE at 368.00)
  [time 368] Run job 1 for   1.00 secs (DONE at 369.00)
  [time 369] Run job 2 for   1.00 secs (DONE at 370.00)
  [time 370] Run job 1 for   1.00 secs (DONE at 371.00)
  [time 371] Run job 2 for   1.00 secs (DONE at 372.00)
  [time 372] Run job 1 for   1.00 secs (DONE at 373.00)
  [time 373] Run job 2 for   1.00 secs (DONE at 374.00)
  [time 374] Run job 1 for   1.00 secs (DONE at 375.00)
  [time 375] Run job 2 for   1.00 secs (DONE at 376.00)
  [time 376] Run job 1 for   1.00 secs (DONE at 377.00)
  [time 377] Run job 2 for   1.00 secs (DONE at 378.00)
  [time 378] Run job 1 for   1.00 secs (DONE at 379.00)
  [time 379] Run job 2 for   1.00 secs (DONE at 380.00)
  [time 380] Run job 1 for   1.00 secs (DONE at 381.00)
  [time 381] Run job 2 for   1.00 secs (DONE at 382.00)
  [time 382] Run job 1 for   1.00 secs (DONE at 383.00)
  [time 383] Run job 2 for   1.00 secs (DONE at 384.00)
  [time 384] Run job 1 for   1.00 secs (DONE at 385.00)
  [time 385] Run job 2 for   1.00 secs (DONE at 386.00)
  [time 386] Run job 1 for   1.00 secs (DONE at 387.00)
  [time 387] Run job 2 for   1.00 secs (DONE at 388.00)
  [time 388] Run job 1 for   1.00 secs (DONE at 389.00)
  [time 389] Run job 2 for   1.00 secs (DONE at 390.00)
  [time 390] Run job 1 for   1.00 secs (DONE at 391.00)
  [time 391] Run job 2 for   1.00 secs (DONE at 392.00)
  [time 392] Run job 1 for   1.00 secs (DONE at 393.00)
  [time 393] Run job 2 for   1.00 secs (DONE at 394.00)
  [time 394] Run job 1 for   1.00 secs (DONE at 395.00)
  [time 395] Run job 2 for   1.00 secs (DONE at 396.00)
  [time 396] Run job 1 for   1.00 secs (DONE at 397.00)
  [time 397] Run job 2 for   1.00 secs (DONE at 398.00)
  [time 398] Run job 1 for   1.00 secs (DONE at 399.00)
  [time 399] Run job 2 for   1.00 secs (DONE at 400.00)
  [time 400] Run job 1 for   1.00 secs (DONE at 401.00)
  [time 401] Run job 2 for   1.00 secs (DONE at 402.00)
  [time 402] Run job 1 for   1.00 secs (DONE at 403.00)
  [time 403] Run job 2 for   1.00 secs (DONE at 404.00)
  [time 404] Run job 1 for   1.00 secs (DONE at 405.00)
  [time 405] Run job 2 for   1.00 secs (DONE at 406.00)
  [time 406] Run job 1 for   1.00 secs (DONE at 407.00)
  [time 407] Run job 2 for   1.00 secs (DONE at 408.00)
  [time 408] Run job 1 for   1.00 secs (DONE at 409.00)
  [time 409] Run job 2 for   1.00 secs (DONE at 410.00)
  [time 410] Run job 1 for   1.00 secs (DONE at 411.00)
  [time 411] Run job 2 for   1.00 secs (DONE at 412.00)
  [time 412] Run job 1 for   1.00 secs (DONE at 413.00)
  [time 413] Run job 2 for   1.00 secs (DONE at 414.00)
  [time 414] Run job 1 for   1.00 secs (DONE at 415.00)
  [time 415] Run job 2 for   1.00 secs (DONE at 416.00)
  [time 416] Run job 1 for   1.00 secs (DONE at 417.00)
  [time 417] Run job 2 for   1.00 secs (DONE at 418.00)
  [time 418] Run job 1 for   1.00 secs (DONE at 419.00)
  [time 419] Run job 2 for   1.00 secs (DONE at 420.00)
  [time 420] Run job 1 for   1.00 secs (DONE at 421.00)
  [time 421] Run job 2 for   1.00 secs (DONE at 422.00)
  [time 422] Run job 1 for   1.00 secs (DONE at 423.00)
  [time 423] Run job 2 for   1.00 secs (DONE at 424.00)
  [time 424] Run job 1 for   1.00 secs (DONE at 425.00)
  [time 425] Run job 2 for   1.00 secs (DONE at 426.00)
  [time 426] Run job 1 for   1.00 secs (DONE at 427.00)
  [time 427] Run job 2 for   1.00 secs (DONE at 428.00)
  [time 428] Run job 1 for   1.00 secs (DONE at 429.00)
  [time 429] Run job 2 for   1.00 secs (DONE at 430.00)
  [time 430] Run job 1 for   1.00 secs (DONE at 431.00)
  [time 431] Run job 2 for   1.00 secs (DONE at 432.00)
  [time 432] Run job 1 for   1.00 secs (DONE at 433.00)
  [time 433] Run job 2 for   1.00 secs (DONE at 434.00)
  [time 434] Run job 1 for   1.00 secs (DONE at 435.00)
  [time 435] Run job 2 for   1.00 secs (DONE at 436.00)
  [time 436] Run job 1 for   1.00 secs (DONE at 437.00)
  [time 437] Run job 2 for   1.00 secs (DONE at 438.00)
  [time 438] Run job 1 for   1.00 secs (DONE at 439.00)
  [time 439] Run job 2 for   1.00 secs (DONE at 440.00)
  [time 440] Run job 1 for   1.00 secs (DONE at 441.00)
  [time 441] Run job 2 for   1.00 secs (DONE at 442.00)
  [time 442] Run job 1 for   1.00 secs (DONE at 443.00)
  [time 443] Run job 2 for   1.00 secs (DONE at 444.00)
  [time 444] Run job 1 for   1.00 secs (DONE at 445.00)
  [time 445] Run job 2 for   1.00 secs (DONE at 446.00)
  [time 446] Run job 1 for   1.00 secs (DONE at 447.00)
  [time 447] Run job 2 for   1.00 secs (DONE at 448.00)
  [time 448] Run job 1 for   1.00 secs (DONE at 449.00)
  [time 449] Run job 2 for   1.00 secs (DONE at 450.00)
  [time 450] Run job 1 for   1.00 secs (DONE at 451.00)
  [time 451] Run job 2 for   1.00 secs (DONE at 452.00)
  [time 452] Run job 1 for   1.00 secs (DONE at 453.00)
  [time 453] Run job 2 for   1.00 secs (DONE at 454.00)
  [time 454] Run job 1 for   1.00 secs (DONE at 455.00)
  [time 455] Run job 2 for   1.00 secs (DONE at 456.00)
  [time 456] Run job 1 for   1.00 secs (DONE at 457.00)
  [time 457] Run job 2 for   1.00 secs (DONE at 458.00)
  [time 458] Run job 1 for   1.00 secs (DONE at 459.00)
  [time 459] Run job 2 for   1.00 secs (DONE at 460.00)
  [time 460] Run job 1 for   1.00 secs (DONE at 461.00)
  [time 461] Run job 2 for   1.00 secs (DONE at 462.00)
  [time 462] Run job 1 for   1.00 secs (DONE at 463.00)
  [time 463] Run job 2 for   1.00 secs (DONE at 464.00)
  [time 464] Run job 1 for   1.00 secs (DONE at 465.00)
  [time 465] Run job 2 for   1.00 secs (DONE at 466.00)
  [time 466] Run job 1 for   1.00 secs (DONE at 467.00)
  [time 467] Run job 2 for   1.00 secs (DONE at 468.00)
  [time 468] Run job 1 for   1.00 secs (DONE at 469.00)
  [time 469] Run job 2 for   1.00 secs (DONE at 470.00)
  [time 470] Run job 1 for   1.00 secs (DONE at 471.00)
  [time 471] Run job 2 for   1.00 secs (DONE at 472.00)
  [time 472] Run job 1 for   1.00 secs (DONE at 473.00)
  [time 473] Run job 2 for   1.00 secs (DONE at 474.00)
  [time 474] Run job 1 for   1.00 secs (DONE at 475.00)
  [time 475] Run job 2 for   1.00 secs (DONE at 476.00)
  [time 476] Run job 1 for   1.00 secs (DONE at 477.00)
  [time 477] Run job 2 for   1.00 secs (DONE at 478.00)
  [time 478] Run job 1 for   1.00 secs (DONE at 479.00)
  [time 479] Run job 2 for   1.00 secs (DONE at 480.00)
  [time 480] Run job 1 for   1.00 secs (DONE at 481.00)
  [time 481] Run job 2 for   1.00 secs (DONE at 482.00)
  [time 482] Run job 1 for   1.00 secs (DONE at 483.00)
  [time 483] Run job 2 for   1.00 secs (DONE at 484.00)
  [time 484] Run job 1 for   1.00 secs (DONE at 485.00)
  [time 485] Run job 2 for   1.00 secs (DONE at 486.00)
  [time 486] Run job 1 for   1.00 secs (DONE at 487.00)
  [time 487] Run job 2 for   1.00 secs (DONE at 488.00)
  [time 488] Run job 1 for   1.00 secs (DONE at 489.00)
  [time 489] Run job 2 for   1.00 secs (DONE at 490.00)
  [time 490] Run job 1 for   1.00 secs (DONE at 491.00)
  [time 491] Run job 2 for   1.00 secs (DONE at 492.00)
  [time 492] Run job 1 for   1.00 secs (DONE at 493.00)
  [time 493] Run job 2 for   1.00 secs (DONE at 494.00)
  [time 494] Run job 1 for   1.00 secs (DONE at 495.00)
  [time 495] Run job 2 for   1.00 secs (DONE at 496.00)
  [time 496] Run job 1 for   1.00 secs (DONE at 497.00)
  [time 497] Run job 2 for   1.00 secs (DONE at 498.00)
  [time 498] Run job 1 for   1.00 secs (DONE at 499.00)
  [time 499] Run job 2 for   1.00 secs (DONE at 500.00)
  [time 500] Run job 2 for   1.00 secs (DONE at 501.00)
  [time 501] Run job 2 for   1.00 secs (DONE at 502.00)
  [time 502] Run job 2 for   1.00 secs (DONE at 503.00)
  [time 503] Run job 2 for   1.00 secs (DONE at 504.00)
  [time 504] Run job 2 for   1.00 secs (DONE at 505.00)
  [time 505] Run job 2 for   1.00 secs (DONE at 506.00)
  [time 506] Run job 2 for   1.00 secs (DONE at 507.00)
  [time 507] Run job 2 for   1.00 secs (DONE at 508.00)
  [time 508] Run job 2 for   1.00 secs (DONE at 509.00)
  [time 509] Run job 2 for   1.00 secs (DONE at 510.00)
  [time 510] Run job 2 for   1.00 secs (DONE at 511.00)
  [time 511] Run job 2 for   1.00 secs (DONE at 512.00)
  [time 512] Run job 2 for   1.00 secs (DONE at 513.00)
  [time 513] Run job 2 for   1.00 secs (DONE at 514.00)
  [time 514] Run job 2 for   1.00 secs (DONE at 515.00)
  [time 515] Run job 2 for   1.00 secs (DONE at 516.00)
  [time 516] Run job 2 for   1.00 secs (DONE at 517.00)
  [time 517] Run job 2 for   1.00 secs (DONE at 518.00)
  [time 518] Run job 2 for   1.00 secs (DONE at 519.00)
  [time 519] Run job 2 for   1.00 secs (DONE at 520.00)
  [time 520] Run job 2 for   1.00 secs (DONE at 521.00)
  [time 521] Run job 2 for   1.00 secs (DONE at 522.00)
  [time 522] Run job 2 for   1.00 secs (DONE at 523.00)
  [time 523] Run job 2 for   1.00 secs (DONE at 524.00)
  [time 524] Run job 2 for   1.00 secs (DONE at 525.00)
  [time 525] Run job 2 for   1.00 secs (DONE at 526.00)
  [time 526] Run job 2 for   1.00 secs (DONE at 527.00)
  [time 527] Run job 2 for   1.00 secs (DONE at 528.00)
  [time 528] Run job 2 for   1.00 secs (DONE at 529.00)
  [time 529] Run job 2 for   1.00 secs (DONE at 530.00)
  [time 530] Run job 2 for   1.00 secs (DONE at 531.00)
  [time 531] Run job 2 for   1.00 secs (DONE at 532.00)
  [time 532] Run job 2 for   1.00 secs (DONE at 533.00)
  [time 533] Run job 2 for   1.00 secs (DONE at 534.00)
  [time 534] Run job 2 for   1.00 secs (DONE at 535.00)
  [time 535] Run job 2 for   1.00 secs (DONE at 536.00)
  [time 536] Run job 2 for   1.00 secs (DONE at 537.00)
  [time 537] Run job 2 for   1.00 secs (DONE at 538.00)
  [time 538] Run job 2 for   1.00 secs (DONE at 539.00)
  [time 539] Run job 2 for   1.00 secs (DONE at 540.00)
  [time 540] Run job 2 for   1.00 secs (DONE at 541.00)
  [time 541] Run job 2 for   1.00 secs (DONE at 542.00)
  [time 542] Run job 2 for   1.00 secs (DONE at 543.00)
  [time 543] Run job 2 for   1.00 secs (DONE at 544.00)
  [time 544] Run job 2 for   1.00 secs (DONE at 545.00)
  [time 545] Run job 2 for   1.00 secs (DONE at 546.00)
  [time 546] Run job 2 for   1.00 secs (DONE at 547.00)
  [time 547] Run job 2 for   1.00 secs (DONE at 548.00)
  [time 548] Run job 2 for   1.00 secs (DONE at 549.00)
  [time 549] Run job 2 for   1.00 secs (DONE at 550.00)
  [time 550] Run job 2 for   1.00 secs (DONE at 551.00)
  [time 551] Run job 2 for   1.00 secs (DONE at 552.00)
  [time 552] Run job 2 for   1.00 secs (DONE at 553.00)
  [time 553] Run job 2 for   1.00 secs (DONE at 554.00)
  [time 554] Run job 2 for   1.00 secs (DONE at 555.00)
  [time 555] Run job 2 for   1.00 secs (DONE at 556.00)
  [time 556] Run job 2 for   1.00 secs (DONE at 557.00)
  [time 557] Run job 2 for   1.00 secs (DONE at 558.00)
  [time 558] Run job 2 for   1.00 secs (DONE at 559.00)
  [time 559] Run job 2 for   1.00 secs (DONE at 560.00)
  [time 560] Run job 2 for   1.00 secs (DONE at 561.00)
  [time 561] Run job 2 for   1.00 secs (DONE at 562.00)
  [time 562] Run job 2 for   1.00 secs (DONE at 563.00)
  [time 563] Run job 2 for   1.00 secs (DONE at 564.00)
  [time 564] Run job 2 for   1.00 secs (DONE at 565.00)
  [time 565] Run job 2 for   1.00 secs (DONE at 566.00)
  [time 566] Run job 2 for   1.00 secs (DONE at 567.00)
  [time 567] Run job 2 for   1.00 secs (DONE at 568.00)
  [time 568] Run job 2 for   1.00 secs (DONE at 569.00)
  [time 569] Run job 2 for   1.00 secs (DONE at 570.00)
  [time 570] Run job 2 for   1.00 secs (DONE at 571.00)
  [time 571] Run job 2 for   1.00 secs (DONE at 572.00)
  [time 572] Run job 2 for   1.00 secs (DONE at 573.00)
  [time 573] Run job 2 for   1.00 secs (DONE at 574.00)
  [time 574] Run job 2 for   1.00 secs (DONE at 575.00)
  [time 575] Run job 2 for   1.00 secs (DONE at 576.00)
  [time 576] Run job 2 for   1.00 secs (DONE at 577.00)
  [time 577] Run job 2 for   1.00 secs (DONE at 578.00)
  [time 578] Run job 2 for   1.00 secs (DONE at 579.00)
  [time 579] Run job 2 for   1.00 secs (DONE at 580.00)
  [time 580] Run job 2 for   1.00 secs (DONE at 581.00)
  [time 581] Run job 2 for   1.00 secs (DONE at 582.00)
  [time 582] Run job 2 for   1.00 secs (DONE at 583.00)
  [time 583] Run job 2 for   1.00 secs (DONE at 584.00)
  [time 584] Run job 2 for   1.00 secs (DONE at 585.00)
  [time 585] Run job 2 for   1.00 secs (DONE at 586.00)
  [time 586] Run job 2 for   1.00 secs (DONE at 587.00)
  [time 587] Run job 2 for   1.00 secs (DONE at 588.00)
  [time 588] Run job 2 for   1.00 secs (DONE at 589.00)
  [time 589] Run job 2 for   1.00 secs (DONE at 590.00)
  [time 590] Run job 2 for   1.00 secs (DONE at 591.00)
  [time 591] Run job 2 for   1.00 secs (DONE at 592.00)
  [time 592] Run job 2 for   1.00 secs (DONE at 593.00)
  [time 593] Run job 2 for   1.00 secs (DONE at 594.00)
  [time 594] Run job 2 for   1.00 secs (DONE at 595.00)
  [time 595] Run job 2 for   1.00 secs (DONE at 596.00)
  [time 596] Run job 2 for   1.00 secs (DONE at 597.00)
  [time 597] Run job 2 for   1.00 secs (DONE at 598.00)
  [time 598] Run job 2 for   1.00 secs (DONE at 599.00)
  [time 599] Run job 2 for   1.00 secs (DONE at 600.00)


Final statistics:
  Job   0 -- Response:   0.00  Turnaround 298.00  Wait 198.00
  Job   1 -- Response:   1.00  Turnaround 499.00  Wait 299.00
  Job   2 -- Response:   2.00  Turnaround 600.00  Wait 300.00

  Average -- Response:   1.00  Turnaround 465.67  Wait 265.67
</pre>
</div>
</details>

#### 4

- When every length of jobs is same or the order in which the jobs run is ascending SJF and FIFO have the same turnaround time.

#### 5

- When the quantum length is the same as the lenth of jobs, SJF and RR have the same turnaround time.

#### 6

- The response time increases as job lengths increase.

```sh
$ ./scheduler.py -p SJF -l100,100,100 -c
ARG policy SJF
ARG jlist 100,100,100

Here is the job list, with the run time of each job: 
  Job 0 ( length = 100.0 )
  Job 1 ( length = 100.0 )
  Job 2 ( length = 100.0 )


** Solutions **

Execution trace:
  [ time   0 ] Run job 0 for 100.00 secs ( DONE at 100.00 )
  [ time 100 ] Run job 1 for 100.00 secs ( DONE at 200.00 )
  [ time 200 ] Run job 2 for 100.00 secs ( DONE at 300.00 )

Final statistics:
  Job   0 -- Response: 0.00  Turnaround 100.00  Wait 0.00
  Job   1 -- Response: 100.00  Turnaround 200.00  Wait 100.00
  Job   2 -- Response: 200.00  Turnaround 300.00  Wait 200.00

  Average -- Response: 100.00  Turnaround 200.00  Wait 100.00
```

```
$ ./scheduler.py -p SJF -l200,200,200 -c
ARG policy SJF
ARG jlist 200,200,200

Here is the job list, with the run time of each job: 
  Job 0 ( length = 200.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 200.0 )


** Solutions **

Execution trace:
  [ time   0 ] Run job 0 for 200.00 secs ( DONE at 200.00 )
  [ time 200 ] Run job 1 for 200.00 secs ( DONE at 400.00 )
  [ time 400 ] Run job 2 for 200.00 secs ( DONE at 600.00 )

Final statistics:
  Job   0 -- Response: 0.00  Turnaround 200.00  Wait 0.00
  Job   1 -- Response: 200.00  Turnaround 400.00  Wait 200.00
  Job   2 -- Response: 400.00  Turnaround 600.00  Wait 400.00

  Average -- Response: 200.00  Turnaround 400.00  Wait 200.00
```

```
$ ./scheduler.py -p SJF -l300,300,300 -c
ARG policy SJF
ARG jlist 300,300,300

Here is the job list, with the run time of each job: 
  Job 0 ( length = 300.0 )
  Job 1 ( length = 300.0 )
  Job 2 ( length = 300.0 )


** Solutions **

Execution trace:
  [ time   0 ] Run job 0 for 300.00 secs ( DONE at 300.00 )
  [ time 300 ] Run job 1 for 300.00 secs ( DONE at 600.00 )
  [ time 600 ] Run job 2 for 300.00 secs ( DONE at 900.00 )

Final statistics:
  Job   0 -- Response: 0.00  Turnaround 300.00  Wait 0.00
  Job   1 -- Response: 300.00  Turnaround 600.00  Wait 300.00
  Job   2 -- Response: 600.00  Turnaround 900.00  Wait 600.00

  Average -- Response: 300.00  Turnaround 600.00  Wait 300.00
```

#### 7

- The response time increases as job lengths increase.

- The equation that gives the worst-case response time is

$$
\sum_{i = 1}^N \text{min}(\text{job length}_i, \text{quantum length})
$$

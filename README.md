# 🔄 push_swap

> **Sort data on two stacks using the lowest possible number of actions.**

[![42 School](https://img.shields.io/badge/42-School-000000?style=for-the-badge\&logo=42)](https://42.fr/)
[![C](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge\&logo=c)](https://en.wikipedia.org/wiki/C_%28programming_language%29)
[![Norminette](https://img.shields.io/badge/Style-Norminette-00ADD8?style=for-the-badge)](https://github.com/42School/norminette)
[![Makefile](https://img.shields.io/badge/Build-Makefile-427819?style=for-the-badge)](https://www.gnu.org/software/make/)

---

## 📌 About

**push_swap** is a sorting project from the **42 School curriculum**.

The challenge is to sort a set of unique integers stored in **stack `a`**, using a second stack `b` and a restricted set of operations.

The objective is not simply to sort the numbers, but to produce the sorting sequence using the **lowest possible number of operations**.

This implementation uses **array-based stacks**, coordinate compression and multiple sorting strategies selected according to the input disorder.

---

## 🎯 The Challenge

At the beginning:

```text
        STACK A                 STACK B

       ┌─────┐                 ┌─────┐
       │  42 │                 │     │
       ├─────┤                 │     │
       │  -7 │                 │     │
       ├─────┤                 │     │
       │  19 │                 │     │
       ├─────┤                 │     │
       │  3  │                 │     │
       └─────┘                 └─────┘
```

The program must transform the input into:

```text
        STACK A                 STACK B

       ┌─────┐                 ┌─────┐
       │ -7  │                 │     │
       ├─────┤                 │     │
       │  3  │                 │     │
       ├─────┤                 │     │
       │  19  │                 │     │
       ├─────┤                 │     │
       │  42  │                 │     │
       └─────┘                 └─────┘
```

Only the allowed `push_swap` operations can be used.

---

## 📚 Table of Contents

* [Rules](#-rules)
* [Allowed Operations](#-allowed-operations)
* [Installation](#-installation)
* [Usage](#-usage)
* [Flags](#-flags)
* [How It Works](#-how-it-works)
* [Sorting Strategies](#-sorting-strategies)
* [Data Structures](#-data-structures)
* [Benchmark](#-benchmark)
* [Project Structure](#-project-structure)
* [Performance Targets](#-performance-targets)
* [Authors](#-authors)
* [Resources](#-resources)
* [AI Usage](#-ai-usage)

---

# 📋 Rules

The project follows the standard `push_swap` requirements:

* Two stacks: **`a`** and **`b`**
* Stack `b` starts empty
* Stack `a` contains unique integers
* Integers can be positive or negative
* The final result must be sorted in ascending order
* Only the allowed operations may be used
* Operations are printed one per line
* Invalid input prints `Error` to `stderr`
* No arguments produces no output

Invalid input includes:

```text
❌ Non-integer values
❌ Duplicate numbers
❌ Integer overflow
```

---

# ⚙️ Allowed Operations

### Swap

| Operation | Description                          |
| --------- | ------------------------------------ |
| `sa`      | Swap the first two elements of `a`   |
| `sb`      | Swap the first two elements of `b`   |
| `ss`      | Perform `sa` and `sb` simultaneously |

### Push

| Operation | Description                            |
| --------- | -------------------------------------- |
| `pa`      | Push the first element of `b` onto `a` |
| `pb`      | Push the first element of `a` onto `b` |

### Rotate

| Operation | Description                                 |
| --------- | ------------------------------------------- |
| `ra`      | Move the first element of `a` to the bottom |
| `rb`      | Move the first element of `b` to the bottom |
| `rr`      | Perform `ra` and `rb` simultaneously        |

### Reverse Rotate

| Operation | Description                             |
| --------- | --------------------------------------- |
| `rra`     | Move the last element of `a` to the top |
| `rrb`     | Move the last element of `b` to the top |
| `rrr`     | Perform `rra` and `rrb` simultaneously  |

---

# 🛠️ Installation

Clone the repository:

```bash
git clone https://github.com/MariaAndrade-25/Push_Swap.git
cd Push_Swap
```

Compile:

```bash
make
```

Available Makefile commands:

```bash
make
make clean
make fclean
make re
```

The project is compiled using:

```text
-Wall -Wextra -Werror
```

---

# 🚀 Usage

The program accepts numbers either as separate arguments:

```bash
./push_swap 2 1 3 6 5 8
```

or as a quoted string:

```bash
./push_swap "2 1 3 6 5 8"
```

Negative values are also supported:

```bash
./push_swap 4 67 3 87 23 -5
```

The **first argument represents the top of stack `a`**.

### Example

```bash
$ ./push_swap 2 1 3 6 5 8
sa
rra
```

---

# 🚩 Flags

The program supports different sorting strategies.

| Flag         | Strategy                         |
| ------------ | -------------------------------- |
| `--simple`   | Selection-sort based strategy    |
| `--medium`   | Chunk-based strategy             |
| `--complex`  | Binary radix sort                |
| `--adaptive` | Automatically selects a strategy |
| `--bench`    | Displays benchmark information   |

### Examples

```bash
./push_swap --simple 10 7 3 9 1 5
```

```bash
./push_swap --medium "4 67 3 87 23"
```

```bash
./push_swap --complex "4 67 3 87 23"
```

```bash
./push_swap --adaptive --bench 5 1 4 2 3
```

---

# 🧠 How It Works

Before sorting, the program analyzes the input and calculates a **disorder metric**.

The disorder represents the ratio of inverted pairs compared to the total number of possible pairs.

The values are then **coordinate-compressed** into ranks:

```text
Original values:

      42   -7   19   3

          ↓

Sorted:

      -7    3   19   42

          ↓

Ranks:

       1    0    3    2
```

This allows the sorting algorithms to operate on compact values from:

```text
0 → n - 1
```

The selected strategy depends on the amount of disorder.

---

# 🧩 Sorting Strategies

## 🟢 Simple — O(n²)

A selection-sort based strategy.

The algorithm repeatedly:

1. Finds the minimum value in `a`
2. Chooses the shortest rotation direction
3. Moves the minimum to the top
4. Pushes it to `b`
5. Repeats
6. Pushes everything back to `a`

Recommended for:

```text
disorder < 0.2
```

The stack is already relatively close to being sorted.

---

## 🟡 Medium — O(n√n)

A **chunk-based sorting strategy**.

The normalized values are divided into approximately `√n` chunks.

The algorithm:

```text
STACK A
   │
   ▼
┌─────────┐
│ Chunk 1 │
├─────────┤
│ Chunk 2 │
├─────────┤
│ Chunk 3 │
├─────────┤
│   ...   │
└─────────┘
   │
   ▼
 STACK B
   │
   ▼
Rebuild A using maximum values
```

Recommended for:

```text
0.2 ≤ disorder < 0.5
```

---

## 🔴 Complex — O(n log n)

Uses **LSD binary radix sort**.

For each bit position:

```text
bit = 0
   │
   ├── 0 → pb
   │
   └── 1 → ra
```

After processing all elements, the values pushed to `b` are returned to `a`.

The number of passes is approximately:

```text
ceil(log₂(n))
```

Recommended for:

```text
disorder ≥ 0.5
```

---

# 🤖 Adaptive Strategy

The default strategy automatically selects the algorithm based on disorder:

|    Disorder | Strategy   |
| ----------: | ---------- |
|     `< 0.2` | 🟢 Simple  |
| `0.2 – 0.5` | 🟡 Medium  |
|     `≥ 0.5` | 🔴 Complex |

This allows the program to adapt to the characteristics of the input instead of always using the same algorithm.

---

# 🧱 Data Structures

The project uses **arrays instead of linked lists**.

### Stack

```c
typedef struct s_stack
{
    int             *values;
    long            size;
    int             capacity;
    struct s_stats  *stats;
} t_stack;
```

Where:

| Field      | Purpose                         |
| ---------- | ------------------------------- |
| `values`   | Array containing stack values   |
| `size`     | Current number of elements      |
| `capacity` | Allocated array capacity        |
| `stats`    | Pointer to benchmark statistics |

### Statistics

```c
typedef struct s_stats
{
    long counts[11];
    long total;
} t_stats;
```

The statistics structure keeps track of:

```text
sa
sb
ss
pa
pb
ra
rb
rr
rra
rrb
rrr
```

---

# 📊 Benchmark

The `--bench` flag provides information about the sorting process.

Example:

```text
Disorder:  73.33%
Strategy:  complex
Complexity: O(n log(n))
Total ops: 42

sa: 0 | sb: 0 | ss: 0
pa: 6 | pb: 6 | ra: 12
rb: 0 | rr: 0 | rra: 18
rrb: 0 | rrr: 0
```

This makes it possible to analyze:

* Input disorder
* Selected algorithm
* Theoretical complexity
* Total operations
* Number of each operation

---

# 📁 Project Structure

```text
push_swap/
│
├── Makefile
├── push_swap.h
├── main.c
│
├── Parsing
│   ├── split.c
│   ├── parse.c
│   ├── parse_number.c
│   ├── count_elements.c
│   └── parse_flags.c
│
├── Stack Management
│   ├── stack_init.c
│   ├── check_duplicates.c
│   └── disorder.c
│
├── Operations
│   ├── op_swap.c
│   ├── op_push.c
│   ├── op_rotate.c
│   └── op_reverse.c
│
├── Sorting Algorithms
│   ├── sort_small.c
│   ├── sort_helpers.c
│   ├── sort_radix.c
│   ├── sort_chunk.c
│   └── push_swap.c
│
└── Utilities
    ├── utils.c
    ├── utils_chunk.c
    └── operation_log.c
```

---

# 📈 Performance Targets

The implementation targets the following operation limits:

|       Input | Maximum operations |
| ----------: | -----------------: |
|   3 numbers |              **2** |
|   5 numbers |             **12** |
| 100 numbers |            **700** |
| 500 numbers |           **5500** |

These targets are based on the 42 correction requirements.

---

# 👥 Authors

| Student      | Responsibilities                                    |
| ------------ | --------------------------------------------------- |
| **mtomanar** | Operations & core sorting algorithms                |
| **malves-a** | Parsing, validation, strategy selection & benchmark |

### mtomanar

```text
op_swap.c
op_push.c
op_rotate.c
op_reverse.c
sort_small.c
sort_chunk.c
utils_chunk.c
```

### malves-a

```text
main.c
push_swap.c
split.c
parse.c
parse_number.c
count_elements.c
parse_flags.c
disorder.c
check_duplicates.c
stack_init.c
utils.c
sort_helpers.c
sort_radix.c
operation_log.c
```

---

# 📚 Resources

The project was developed using resources related to:

* **42 push_swap subject**
* C language documentation
* Arrays and pointers
* Structures
* Dynamic memory allocation
* Stack data structures
* Sorting algorithms
* Algorithm complexity
* Coordinate compression
* Operation optimization
* 42 peer learning and code reviews

---

# 🤖 AI Usage

AI tools were used as a **learning and development aid**.

They were mainly used for:

* Understanding C concepts
* Understanding pointers and memory
* Discussing array-based stack implementations
* Reviewing and debugging operations
* Understanding sorting strategies
* Identifying logic errors
* Improving code structure
* Refactoring functions according to 42 standards
* Reviewing algorithmic approaches

AI was **not used as a replacement for understanding or implementing the project**.

Suggestions were reviewed, tested, adapted and integrated manually.

---

# 🏁 Conclusion

`push_swap` brings together several fundamental programming concepts:

```text
       DATA STRUCTURES
              │
              ▼
        ALGORITHMS
              │
              ▼
       MEMORY MANAGEMENT
              │
              ▼
         OPTIMIZATION
              │
              ▼
        PERFORMANCE
```

The project demonstrates how different sorting strategies can produce significantly different numbers of operations for the same input.

By combining:

* Array-based stacks
* Coordinate compression
* Multiple sorting algorithms
* Adaptive strategy selection
* Operation tracking
* Benchmarking

the project explores the relationship between **algorithm choice, data structures and performance**.

---

<div align="center">

### 💻 Built as part of the 42 School curriculum

**push_swap — Sort smarter, not harder.**

</div>

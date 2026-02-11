# PUSH_SWAP – PROFESSIONAL SYNTHESIS, CHECKLIST & ORGANIZATION PLAN

---

# 1. PROJECT SUMMARY

## 1.1 Objective

Develop a C program named `push_swap` that:

* Sorts a list of integers using **two stacks (a and b)**.
* Uses only a **restricted set of stack operations**.
* Outputs the **smallest possible sequence of operations** that sorts stack `a` in ascending order.
* Embeds **four distinct sorting strategies** with controlled algorithmic complexity.
* Selects the strategy at runtime via flags or automatically (adaptive mode).

The project focuses on:

* Algorithmic complexity (Big-O measured in number of push_swap operations)
* Runtime strategy selection
* Optimization of operation count
* Clean architecture and error handling
* Code quality under 42 Norm
* Team collaboration (mandatory 2-person project)

---

## 1.2 Constraints

### Language & Rules

* C only
* 42 Norm compliant
* No global variables
* No memory leaks
* Makefile required (`NAME`, `all`, `clean`, `fclean`, `re`)
* Compile with: `-Wall -Wextra -Werror`
* Only allowed functions:
  `read`, `write`, `malloc`, `free`, `exit`, `ft_printf` (if self-coded)

---

## 1.3 Functional Requirements

### Stacks

* Stack `a`: contains integers (no duplicates, valid int range)
* Stack `b`: initially empty

### Allowed Operations

* Swap: `sa`, `sb`, `ss`
* Push: `pa`, `pb`
* Rotate: `ra`, `rb`, `rr`
* Reverse rotate: `rra`, `rrb`, `rrr`

### Mandatory Features

1. Compute disorder metric (before sorting).
2. Implement 4 strategies:

   * O(n²)
   * O(n√n)
   * O(n log n)
   * Adaptive (based on disorder)
3. Strategy selection flags:

   * `--simple`
   * `--medium`
   * `--complex`
   * `--adaptive` (default)
4. Benchmark mode (`--bench`) → output to `stderr`:

   * Disorder (% with 2 decimals)
   * Strategy used + complexity class
   * Total operations
   * Count per operation

---

## 1.4 Performance Targets

### For 100 random numbers

* < 2000 → pass
* < 1500 → good
* < 700 → excellent

### For 500 random numbers

* < 12000 → pass
* < 8000 → good
* < 5500 → excellent

---

## 1.5 Bonus (Optional)

Create `checker` program:

* Reads instructions from stdin
* Executes them
* Outputs:

  * `OK` if sorted
  * `KO` otherwise
  * `Error` on invalid input

Bonus evaluated only if mandatory part is perfect.

---

# 2. COMPLETE TECHNICAL CHECKLIST

---

# A. PROJECT SETUP

### Repository

* [X] Both students listed as contributors
* [X] README.md created
* [ ] Contributions clearly described

### Makefile

* [X] NAME rule
* [X] all
* [X] clean
* [X] fclean
* [X] re
* [X] No relinking
* [X] Compiles with required flags
* [ ] bonus rule (if checker implemented)
* [ ] n utilise pas de * pour choisir les dossiers

---

# B. PARSING & ERROR MANAGEMENT

* [ ] Accept arguments as separate integers
* [ ] Handle quoted strings
* [ ] Detect:

  * [ ] Non-integer input
  * [ ] Overflow / underflow
  * [ ] Duplicates
  * [ ] Invalid flags
* [ ] Print `Error\n` to stderr
* [ ] No crash on invalid input
* [ ] No output if no arguments

---

# C. DATA STRUCTURES

Recommended:

```
typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
} t_node;
```

* [ ] Stack structure defined
* [ ] Push operation safe
* [ ] Pop operation safe
* [ ] Rotate safe
* [ ] Reverse rotate safe
* [ ] Swap safe
* [ ] No memory leaks
* [ ] Free all on exit

---

# D. OPERATION SYSTEM

* [ ] Implement all 11 operations
* [ ] Each operation:

  * Executes on stacks
  * Prints operation name
  * Increments operation counter
* [ ] Combined ops (ss, rr, rrr) implemented properly
* [ ] Operation counters tracked per type

---

# E. DISORDER METRIC

* [ ] Implement compute_disorder()
* [ ] O(n²) pair comparison
* [ ] Value between 0 and 1
* [ ] Computed BEFORE any move
* [ ] Printed in bench mode (2 decimals)

---

# F. REQUIRED STRATEGIES

---

## 1. Simple Strategy (O(n²))

Examples:

* Insertion-style stack adaptation
* Selection min extraction

Checklist:

* [ ] True O(n²) in push_swap operation model
* [ ] Works for all sizes
* [ ] Flag `--simple` forces use

---

## 2. Medium Strategy (O(n√n))

Examples:

* Chunk-based sorting
* Bucket-like partitioning

Checklist:

* [ ] √n chunk division
* [ ] Balanced push/pop strategy
* [ ] Meets complexity requirement
* [ ] Flag `--medium`

---

## 3. Complex Strategy (O(n log n))

Examples:

* Radix sort (binary)
* Merge adaptation
* Quick adaptation

Checklist:

* [ ] Valid O(n log n)
* [ ] Efficient for 500 numbers
* [ ] Flag `--complex`

---

## 4. Adaptive Strategy

Must:

* Measure disorder
* Select strategy based on thresholds:

| Disorder Range | Required Complexity |
| -------------- | ------------------- |
| < 0.2          | O(n)                |
| 0.2 – 0.5      | O(n√n)              |
| ≥ 0.5          | O(n log n)          |

Checklist:

* [ ] Threshold logic implemented
* [ ] O(n) solution for low disorder (e.g. nearly sorted detection)
* [ ] Correct selection
* [ ] Default mode if no selector
* [ ] Document thresholds in README

---

# G. BENCH MODE

Flag: `--bench`

* [ ] Metrics sent to stderr
* [ ] Operations remain on stdout
* [ ] Display:

  * Disorder
  * Strategy name
  * Complexity class
  * Total operations
  * Count per operation
* [ ] Hidden when flag not present

---

# H. PERFORMANCE VALIDATION

* [ ] 100 random numbers tested
* [ ] 500 random numbers tested
* [ ] Operation counts recorded
* [ ] Meet minimum requirements
* [ ] Attempt optimization for excellent tier

---

# I. MEMORY SAFETY

* [ ] No leaks (valgrind clean)
* [ ] No double free
* [ ] No segfault
* [ ] Free on error exit

---

# J. README REQUIREMENTS

Must include:

* [ ] First line italicized with required sentence
* [ ] Description section
* [ ] Instructions section
* [ ] Resources section
* [ ] AI usage disclosure
* [ ] Algorithm explanations
* [ ] Complexity justification
* [ ] Adaptive threshold explanation

---

# K. BONUS – CHECKER

* [ ] Reads instructions from stdin
* [ ] Executes correctly
* [ ] Validates instruction names
* [ ] Detects invalid instruction
* [ ] Outputs OK / KO
* [ ] Error management correct
* [ ] No crash

---

# 3. ORGANIZATION PLAN (TEAM OF 2)

---

# Phase 1 – Architecture & Design (Day 1–2)

### Together

* Define stack structure
* Decide:

  * Linked list vs array
  * Strategy choices
* Design file architecture
* Define operation API
* Define metrics structure

Deliverable:

* Technical design validated
* Roles split

---

# Phase 2 – Core Engine (Day 3–5)

### Person A

* Parsing
* Error handling
* Stack implementation

### Person B

* All 11 operations
* Operation counters
* Print system

Together:

* Test stack + operations
* Validate memory safety

Deliverable:

* Fully working stack engine

---

# Phase 3 – Algorithms (Day 6–12)

### Person A

* O(n²) strategy
* O(n√n) strategy

### Person B

* O(n log n) strategy
* O(n) low-disorder optimization

Together:

* Implement adaptive selector
* Benchmark testing
* Operation reduction optimization

Deliverable:

* 4 working strategies
* Strategy selector validated

---

# Phase 4 – Benchmark & Optimization (Day 13–15)

* Massive random tests
* Optimize chunk sizes
* Optimize rotation decisions
* Reduce unnecessary operations
* Validate performance targets

---

# Phase 5 – Bench Mode + README (Day 16–18)

### Person A

* Bench mode
* stderr formatting

### Person B

* README writing
* Complexity documentation
* AI usage explanation

Together:

* Peer explanation rehearsal

---

# Phase 6 – Bonus Checker (Optional)

If mandatory part perfect.

---

# 4. RECOMMENDED ARCHITECTURE

```
/src
    main.c
    parser.c
    error.c
    stack.c
    operations_swap.c
    operations_push.c
    operations_rotate.c
    operations_reverse.c
    disorder.c
    strategy_simple.c
    strategy_medium.c
    strategy_complex.c
    strategy_adaptive.c
    benchmark.c

/include
    push_swap.h
```

---

# 5. RISK MANAGEMENT

| Risk                        | Prevention                   |
| --------------------------- | ---------------------------- |
| Segfault                    | Defensive checks everywhere  |
| Memory leak                 | Free on all exit paths       |
| Strategy invalid complexity | Measure real operation count |
| Failing 500 benchmark       | Prioritize O(n log n) early  |
| Cannot explain algorithm    | Pair reviews every 2 days    |

---

# 6. STRATEGIC RECOMMENDATIONS

1. Implement Radix early → ensures performance baseline.
2. Use indexing (coordinate compression) for large inputs.
3. Keep operations atomic and reusable.
4. Build a local tester script.
5. Track operation counts during development.

---

# 7. FINAL VALIDATION BEFORE SUBMISSION

* [ ] Norm OK
* [ ] Valgrind clean
* [ ] 100 numbers < 2000 ops
* [ ] 500 numbers < 12000 ops
* [ ] All 4 strategies selectable
* [ ] Bench output correct
* [ ] No global variables
* [ ] Both members can explain:

  * Disorder computation
  * Why each strategy meets complexity
  * Why adaptive thresholds are valid

---

If you want, I can next provide:

* A concrete algorithm selection recommendation (best practical choices for each complexity tier), or
* A detailed technical design blueprint for maximum evaluation score.


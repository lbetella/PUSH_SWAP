*This project has been created as part of the 42 curriculum by guilfran, lbetella.

# Push_swap

## Description

**Push_swap** is a competitive algorithmic project within the 42 curriculum. The core objective is to sort a given stack of unique integers in ascending order using two stacks (`stack a` and `stack b`) and a strictly limited set of stack manipulation operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

Beyond finding any sequence of instructions, the challenge lies in computing the shortest possible sequence of operations. This project explores computational complexity measured not merely by theoretical CPU cycles over standard arrays, but by the physical volume of Push_swap instructions generated.

To satisfy the modern requirements of this project, four distinct sorting strategies are implemented:
1. **Simple Strategy ($O(n^2)$):** An insertion-based algorithm ("Turk Algorithm").
2. **Intermediate Strategy ($O(n\sqrt{n})$):** A chunk-based partitioning algorithm ("K-Sort").
3. **Complex Strategy ($O(n \log n)$):** An iterative QuickSort adapted for dual stacks with pivots.
4. **Adaptive Strategy:** A dynamic controller that calculates the initial permutation disorder index ($[0.0, 1.0]$) and routes the input into the most optimal internal routine according to predefined thresholds.

---

## Authors & Task Distribution

This project was built collaboratively by **guilfran** and **lbetella**. The tasks were divided according to each member's focus:

* **guilfran:**
  * Complete input parsing and validation (detecting non-integers, integer overflows/underflows, duplicates, empty arguments, and formatted strings).
  * Initial linked list / stack initialization and memory deallocation routines.
  * Logic and implementation of the **Medium Algorithm** ($O(n\sqrt{n})$ K-Sort / Chunks).
  * Implementation of flags (`--simple`, `--medium`, `--complex`, `--adaptive`, `--bench`).
  * Architecture of the **Adaptive Engine** and calculation of the disorder index.
  * Architecture of the **Benchmark Mode** (`--bench`) reporting detailed operation counters and performance metrics to `stderr`.

* **lbetella:**
  * Implementation and abstraction of all low-level Push_swap movement operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
  * Logic and implementation of the **Simple Algorithm** ($O(n^2)$ Turk / Insertion sort).
  * Logic and implementation of the **Complex Algorithm** ($O(n \log n)$ Iterative QuickSort with stack pivots).

* **Joint Collaboration (guilfran & lbetella):**
  * **Bonus Checker:** Full design and implementation of the custom `checker` binary, including stdin instruction reading, stack state simulation, memory sanity checks, and final validation reporting (`OK`, `KO`, or `Error`).
  * Peer reviews, edge-case testing, memory leak auditing, and Norminette compliance.

---

## Instructions

### Compilation

The project uses a standard `Makefile` that compiles with flags `-Wall -Wextra -Werror` without relinking.

```bash
# Compile the main push_swap binary
make

# Compile the bonus checker binary
make bonus

# Remove object files
make clean

# Remove all binaries and object files
make fclean

# Recompile the whole project
make re
```

### Execution

The `push_swap` program receives an optional strategy flag followed by a list of integers (which can be passed as individual arguments or formatted inside quoted strings):

```bash
# Default execution (Adaptive strategy)
./push_swap 2 1 3 6 5 8

# Force Simple strategy (O(n^2))
./push_swap --simple 5 4 3 2 1

# Force Medium strategy (O(n√n))
./push_swap --medium 4 67 3 87 23

# Force Complex strategy (O(n log n))
./push_swap --complex 4 67 3 87 23

# Enable Benchmark mode (outputs metrics to stderr, moves to stdout)
./push_swap --bench 4 67 3 87 23
```

### Running the Checker (Bonus)

The `checker` program takes the initial stack as arguments and reads Push_swap instructions from standard input:

```bash
# Interactive check
./checker 3 2 1 0
rra
pb
sa
rra
pa
# Press Ctrl+D
OK

# Pipeline execution with push_swap
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
```

---

## Algorithmic Strategies & Justification

### 1. Disorder Metric Calculation

Before applying any movements, the program computes the **inversion disorder index** $D \in [0.0, 1.0]$. The index evaluates all unique pairs $(a[i], a[j])$ where $i < j$. A pair is considered inverted (a "mistake") if $a[i] > a[j]$:

$$D = \frac{\text{mistakes}}{\text{total pairs}} = \frac{\sum_{i=0}^{n-2} \sum_{j=i+1}^{n-1} [a[i] > a[j]]}{\frac{n(n - 1)}{2}}$$

* $D = 0.0$: The stack is fully sorted in ascending order (0 operations executed).
* $0.0 < D < 1.0$: Partially ordered stack.
* $D = 1.0$: The stack is in exact reverse order (maximum entropy/inversions).

---

### 2. Strategy Breakdown & Selection Criteria

| Strategy | Classification | Chosen Algorithm | Theoretical Move Cost | Performance Category |
| :--- | :--- | :--- | :--- | :--- |
| **Simple** | $O(n^2)$ | **Turk Algorithm** (Greedy Insertion) | $O(n^2)$ worst, fast constants | **Excellent** ($< 600$ ops for 100 / $< 4500$ ops for 500) |
| **Medium** | $O(n\sqrt{n})$ | **K-Sort** (Range / Dynamic Chunks) | $O(n\sqrt{n})$ bounded by $\sqrt{n}$ windows | **Excellent** ($< 650$ ops for 100 / $< 4800$ ops for 500) |
| **Complex** | $O(n \log n)$ | **Iterative QuickSort** (Pivoting stacks) | $O(n \log n)$ recursive partitioning | **Medium** ($\approx 1100$ ops for 100 / $\approx 6800$ ops for 500) |

#### Simple Algorithm: The Turk Algorithm ($O(n^2)$)
* **Design & Mechanics:** A dual-stack cost-optimized insertion sort. It pushes initial elements to stack `b`, and then for every element in `a`, it computes the exact combined move cost (`ra`, `rra`, `rb`, `rrb`, `rr`, `rrr`) needed to position it in its sorted place in stack `b`. It greedily executes the globally cheapest move at each turn until `a` is empty, then rotates `b` to place the maximum at the top and transfers everything back to `a`.
* **Justification & Results:** Despite belonging to the theoretical class $O(n^2)$, its real-world operation count is among the lowest possible for Push_swap constraints. Empirical benchmarks demonstrate that the Turk algorithm reaches the **"Excellent"** threshold with ease (frequently under 550 operations for 100 numbers and under 4200 operations for 500 numbers), thanks to double rotations (`rr`, `rrr`) eliminating wasted moves.

#### Medium Algorithm: K-Sort ($O(n\sqrt{n})$)
* **Design & Mechanics:** First, values are normalized into indices $[0, n-1]$. Using a dynamic sliding window (chunk) of size $k \approx \sqrt{n} \times 1.4$, elements are pushed from `a` to `b`. If the top index is smaller than the current threshold, it is pushed (`pb`); if it lies in the lower half of the chunk, `rb` is triggered to form an hourglass distribution in `b`. Once `a` is depleted, elements are extracted from `b` back to `a` by selecting the largest available value at the top or bottom of `b`.
* **Justification & Results:** K-Sort guarantees a deterministic upper bound of $O(n\sqrt{n})$. During benchmarking, K-Sort consistently remained deep within the **"Excellent"** tier (comfortably below 700 moves for 100 values and below 5200 moves for 500 values).

#### Complex Algorithm: Iterative Dual-Stack QuickSort ($O(n \log n)$)
* **Design & Mechanics:** Adapts classic QuickSort partition mechanics across two stacks using an explicit frame tracking stack to prevent recursive stack overflows. At each partition step, a median pivot is determined; values smaller than the pivot are pushed to `b`, while values larger remain in `a` via rotations. Partitions are recursively subdivided and restored.
* **Justification & Results:** While strictly adhering to the $O(n \log n)$ complexity model required by the subject, the rotation overhead needed to restore stack positions in QuickSort creates unavoidable move inflation. Our testing demonstrated that while QuickSort achieves competitive counts that easily pass the mandatory limits, it was impossible to reach the "Excellent" threshold with this approach alone, landing solidly in the **"Medium"** range ($\approx 1000 - 1200$ ops for 100 numbers, and $\approx 6500 - 7000$ ops for 500 numbers).

---

### 3. Adaptive Strategy Design

When `--adaptive` is chosen (default mode), the program inspects the disorder index $D$ before issuing operations and routes the workload:

* **Low Disorder ($D < 0.2$):**
  * Target Complexity: $O(n)$ operations.
  * Routine: Scans for localized out-of-order runs. If only a minor subset of elements is misplaced or inverted, direct linear sweeps, single rotations (`ra`/`rra`), and localized swaps (`sa`) restore the stack in linear time without bulk migrations.
* **Medium Disorder ($0.2 \le D < 0.5$):**
  * Target Complexity: $O(n\sqrt{n})$ operations.
  * Routine: Employs **K-Sort** with dynamic chunk sizing adapted to the measured disorder, capitalizing on pre-existing sub-sequences to minimize rotation depth.
* **High Disorder ($D \ge 0.5$):**
  * Target Complexity: $O(n \log n)$ / optimal partitioned search.
  * Routine: Routes through our highly optimized **Turk Insertion engine** or **K-Sort partitioner**, achieving the lowest operational overhead on arbitrary and chaotic distributions.

---

## Benchmark Mode

When executed with the `--bench` flag, `push_swap` sends diagnostic telemetry directly to `stderr` while keeping `stdout` reserved exclusively for instruction parsing:

```bash
$> ARG=$(shuf -i 0-9999 -n 500); ./push_swap --bench $ARG > /dev/null
[bench] disorder: 49.88%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 4421
[bench] sa: 0  sb: 0  ss: 0  pa: 500  pb: 500
[bench] ra: 1621  rb: 980  rr: 312  rra: 154  rrb: 854  rrr: 0
```

---

## Resources & AI Usage

### References
* **Donald E. Knuth:** *The Art of Computer Programming, Volume 3: Sorting and Searching*.
* **Big-O Cheatsheet & Complexity Models:** Standard asymptotic classification references for comparative analysis.
* **Push_swap Turk Algorithm Technical Articles:** Documentation on dual-stack cost calculation and greedy placement.

### Responsible Use of AI
In alignment with Chapter III of the 42 Subject:
* **Conceptual Exploration & Brainstorming:** Generative AI tools were consulted to formulate mathematical expressions for inversion counting ($D$) and to explore edge cases in stack rotations.
* **Scaffolding & Templates:** AI was used to assist in drafting structured Markdown documentation and formatting benchmark telemetry log layouts.
* **Critical Review:** All algorithmic source code, logic, data structures, and edge-case validations were manually implemented, line-by-line audited, tested against memory leak checkers (Valgrind), and validated in C by both group members.

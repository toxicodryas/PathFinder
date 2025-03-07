# PathFinder

## Overview
PathFinder is a command-line utility designed to optimize paths through tower-style puzzle games often seen in mobile game advertisements. These games typically present players with a starting value and multiple towers containing mathematical operations (like +10, -5, *2). The goal is to find the sequence of operations that results in the highest possible final value.

Instead of relying on guesswork, PathFinder computes all possible paths through the towers and identifies the optimal sequence of operations to maximize your final score.

## How It Works
PathFinder uses a recursive permutation algorithm to explore all possible paths through the towers. For each unique path:

1. The program applies each operation in sequence to the starting value
2. It tracks the resulting value after each operation
3. It compares all final results to find the optimal path

This exhaustive approach guarantees you'll always find the best possible path through the towers.

## Installation

### Prerequisites
- A C compiler (gcc, clang, etc.)
- Basic command-line knowledge

### Compiling the Program
1. Save the code to a file named `pathfinder.c`
2. Open a terminal and navigate to the directory containing the file
3. Compile using your C compiler:

```bash
gcc pathfinder.c -o pathfinder
```

## Usage

1. Run the compiled program:
```bash
./pathfinder
```

2. Follow the prompts:
   - Enter your initial starting value (the value you begin with)
   - Enter the number of operations (how many towers you need to pass through)
   - For each tower, enter the operation in the format `+5`, `-10`, `*2`, `/3`, etc.

3. The program will calculate and display:
   - The maximum possible final value
   - The exact sequence of operations to achieve this value

### Example

```
Enter the initial starting value: 10
Enter the number of operations: 3
Enter operation 1 (e.g., +5, -50, *10): +5
Enter operation 2 (e.g., +5, -50, *10): *2
Enter operation 3 (e.g., +5, -50, *10): -3

Best path results in value: 27
Operations to reach this value:
+5 *2 -3
```

In this example, starting with 10:
1. First operation: +5 → 15
2. Second operation: *2 → 30
3. Third operation: -3 → 27

## Technical Details

- The program handles the four basic arithmetic operations: addition (+), subtraction (-), multiplication (*), and division (/).
- It uses recursion to explore all possible permutations of the operations.
- Memory is dynamically allocated to store the operations and is properly freed before program termination.
- The implementation assumes no more than 100 operations for the path and operation arrays.

## Limitations

- The program expects valid input in the correct format.
- Division by zero is not checked, so be careful with division operations.
- For very large numbers of operations (>12), the computation time may increase significantly due to the factorial growth of permutations.

## Why Use PathFinder?

Many tower-style mobile game ads are designed to seem frustratingly difficult or rely on luck. PathFinder removes the guesswork by mathematically determining the optimal path. Whether you're trying to beat a particularly challenging level or simply want to understand the underlying patterns, PathFinder provides the optimal solution.

## License

This software is provided as-is, free to use and modify for personal purposes.

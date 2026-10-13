# C++ problem-solving archive

My C++ practice solutions, organized mainly by problem rather than by a single course or contest. The repository includes LeetCode-style problem folders and separate difficulty/weekly practice folders.

## Finding a solution

- Problem folders are named with a number and slug, for example `141-linked-list-cycle/`.
- Many folders contain a short problem README and a `.cpp` implementation.
- `Difficulty: Basic/`, `Difficulty: Easy/`, `Difficulty: Medium/`, and `Difficulty: Hard/` hold additional practice sets.

**Windows checkout note:** those directory names contain `:`, which Windows cannot represent in a normal filename. A full clone may fail during checkout on Windows. Browse on GitHub or use a Linux/WSL filesystem; a future repository cleanup should rename those directories without changing the solutions.

Use GitHub's file search to find a title or problem number. Folder numbers are part of this archive's naming convention; confirm the platform and current statement in the folder before reusing a solution.

## Running code

Most files are standalone practice submissions, not one buildable application. Compile a self-contained file with a C++17 compiler when it has a `main` function:

```bash
g++ -std=c++17 -O2 -Wall -Wextra path/to/solution.cpp -o solution
./solution
```

Files written for an online judge may define only a `Solution` class and require that judge's supplied types or driver code. There is no repository-wide test command.

## Repository note

This is a learning archive. It is not a library of reviewed reference implementations; individual solutions can vary in style and completeness.

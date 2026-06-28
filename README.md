# c-project-3-grade-calculator

project for https://github.com/Harin23/learn-c/tree/main/projects

---
# Instructions:

# Project 3: Grade Calculator

**Module:** 1.2 — Control Flow and Basic I/O  
**Estimated time:** 3–4 hours

## Description

Build a program that reads numeric scores, computes statistics, and assigns letter grades using a `switch` or lookup table.

## Requirements

### Functional

1. Ask how many scores the user will enter (1–100).
2. Read that many scores (0.0–100.0).
3. Compute and print:
    - Count
    - Minimum
    - Maximum
    - Average (mean)
4. Assign a letter grade for the average using this scale:

   | Average | Grade |
      |---------|-------|
   | 90–100 | A |
   | 80–89 | B |
   | 70–79 | C |
   | 60–69 | D |
   | 0–59 | F |

5. Optionally print how many scores fall into each letter bucket.

### Error Handling

- Invalid count (≤ 0 or > 100): re-prompt
- Invalid score (outside 0–100 or non-numeric): re-prompt for that score
- Do not crash on any invalid input

## Technical Requirements

- Use a fixed-size array (`double scores[100]`)
- Use `switch` or `if/else` for letter grade assignment
- Single file: `grade_calc.c`

## Rubric

| Criterion | Points |
|-----------|--------|
| Statistics (min, max, mean) correct | 30 |
| Letter grade assignment correct | 25 |
| Input validation robust | 25 |
| Uses appropriate control flow (`switch` or equivalent) | 10 |
| Compiles with zero warnings | 10 |
| **Total** | **100** |

## Test Cases

1. Scores: 85, 92, 78 → mean 85.0, grade B
2. Single score: 100 → grade A
3. Enter count 0 — re-prompt
4. Enter score 150 — re-prompt for that score

## Extension (Optional)

Read scores from a file (one per line) if a filename is passed as `argv[1]`.

# Temperature Extremes Analyzer

## AOA Mini Project – Divide and Conquer

### Problem Statement

Develop a Temperature Extremes Analyzer using the Divide and Conquer
technique to find the minimum and maximum temperature from a set of
date-temperature records.

The program also compares the number of comparisons performed by the
Divide and Conquer approach with a linear approach.

## Objectives

- Find the minimum temperature using Divide and Conquer.
- Find the maximum temperature using Divide and Conquer.
- Use recursion with one-item and two-item base cases.
- Divide the input range at the midpoint.
- Combine the minimum and maximum results of both halves.
- Count the number of comparisons.
- Compare the Divide and Conquer approach with a linear approach.
- Handle negative temperatures, duplicate values, and edge cases.

## Algorithm

1. Store date and temperature records.
2. Divide the array into two halves.
3. Recursively find the minimum and maximum of each half.
4. Combine the results by comparing the minimum and maximum values.
5. Count the comparisons performed.
6. Apply a linear approach to find the same minimum and maximum.
7. Compare the number of comparisons of both approaches.

## Time Complexity

### Divide and Conquer
- Time Complexity: O(n)
- Auxiliary Space: O(log n) due to recursion.

### Linear Approach
- Time Complexity: O(n)
- Auxiliary Space: O(1)

## Sample Output

The output demonstrates:

- Minimum temperature
- Maximum temperature
- Number of comparisons using Divide and Conquer
- Number of comparisons using the Linear approach
- Comparison between both approaches

## Test Cases

The program can be tested with:

- Single temperature reading
- Two temperature readings
- Positive temperatures
- Negative temperatures
- Duplicate temperatures
- All temperatures equal
- Odd and even number of readings
- Mixed negative, zero and positive temperatures

## Files

| File | Description |
|------|-------------|
| `temperature_extremes.c` | C implementation of the algorithm |
| `output.png` | Sample program output |
| `README.md` | Project documentation |

## Technique Used

**Divide and Conquer**

The problem is divided into smaller subproblems, solved recursively,
and their results are combined to obtain the final minimum and maximum.

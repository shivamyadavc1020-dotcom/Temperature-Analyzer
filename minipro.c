#include <stdio.h>

#define MAX 100

// Structure to store date and temperature
struct Temperature {
    char date[20];
    int temperature;
};

// Structure to store minimum and maximum results
struct Result {
    int min;
    int max;
};

// Global counters for comparisons
int divideComparisons = 0;
int linearComparisons = 0;

// Divide and Conquer method
struct Result findMinMax(struct Temperature data[], int low, int high) {
    struct Result result;
    struct Result left;
    struct Result right;

    // Base case: one reading
    if (low == high) {
        result.min = data[low].temperature;
        result.max = data[low].temperature;
        return result;
    }

    // Base case: two readings
    if (high == low + 1) {
        divideComparisons++;

        if (data[low].temperature < data[high].temperature) {
            result.min = data[low].temperature;
            result.max = data[high].temperature;
        } else {
            result.min = data[high].temperature;
            result.max = data[low].temperature;
        }

        return result;
    }

    // Divide
    int mid = (low + high) / 2;

    // Conquer
    left = findMinMax(data, low, mid);
    right = findMinMax(data, mid + 1, high);

    // Combine - compare minimum values
    divideComparisons++;

    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    // Combine - compare maximum values
    divideComparisons++;

    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}

// Linear method
struct Result findMinMaxLinear(struct Temperature data[], int n) {
    struct Result result;

    result.min = data[0].temperature;
    result.max = data[0].temperature;

    for (int i = 1; i < n; i++) {

        // Compare for minimum
        linearComparisons++;

        if (data[i].temperature < result.min)
            result.min = data[i].temperature;

        // Compare for maximum
        linearComparisons++;

        if (data[i].temperature > result.max)
            result.max = data[i].temperature;
    }

    return result;
}

int main() {
    struct Temperature data[MAX];
    struct Result divideResult;
    struct Result linearResult;

    int n;

    printf(" TEMPERATURE EXTREMES ANALYZER\n");
    

    printf("Enter number of temperature readings: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of readings.\n");
        return 0;
    }

    // Input date and temperature records
    printf("\nEnter date and temperature readings:\n");

    for (int i = 0; i < n; i++) {
        printf("\nReading %d\n", i + 1);

        printf("Date/Day: ");
        scanf("%19s", data[i].date);

        printf("Temperature: ");
        scanf("%d", &data[i].temperature);
    }

    // Divide and Conquer
    divideResult = findMinMax(data, 0, n - 1);

    // Linear method
    linearResult = findMinMaxLinear(data, n);

    // Display all 
    printf("TEMPERATURE RECORDS\n");
    printf("%-15s %-15s\n", "Date/Day", "Temperature");

    for (int i = 0; i < n; i++) {
        printf("%-15s %-15d\n",
               data[i].date,
               data[i].temperature);
    }

    // Display Divide and Conquer result
    printf("DIVIDE AND CONQUER RESULT\n");

    printf("Minimum Temperature : %d\n", divideResult.min);
    printf("Maximum Temperature : %d\n", divideResult.max);
    printf("Number of Comparisons: %d\n", divideComparisons);

    // Display Linear result
\    printf("LINEAR METHOD RESULT\n");


    printf("Minimum Temperature : %d\n", linearResult.min);
    printf("Maximum Temperature : %d\n", linearResult.max);
    printf("Number of Comparisons: %d\n", linearComparisons);

    // Comparison

    printf("COMPARISON\n");


    if (divideComparisons < linearComparisons)
        printf("Divide and Conquer uses fewer comparisons.\n");
    else if (divideComparisons > linearComparisons)
        printf("Linear method uses fewer comparisons.\n");
    else
        printf("Both methods use the same number of comparisons.\n");

    printf("\nTime Complexity of Divide and Conquer: O(n)\n");
    printf("Time Complexity of Linear Method       : O(n)\n");

    return 0;
}
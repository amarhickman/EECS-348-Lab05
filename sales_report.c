#include <stdio.h>

#define NUM_MONTHS 12

int main() {
    float sales[NUM_MONTHS];

    // Takes 12 inputs from terminal "dont know file input yet"
    printf("Enter the monthly sales figures (one per line):\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("Month %d: ", i + 1);
        scanf("%f", &sales[i]);
    }

    // Calculate the monthly sales report
    printf("Monthly Sales Report for 2024\n");
    printf("Month\tSales\n");
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < NUM_MONTHS; i++) { //iterates through each month
        printf("%s\t%.2f\n", months[i], sales[i]);
    }

    // Calculate the sales summary report
    float min_sales = sales[0];
    float max_sales = sales[0];
    float sum = 0;
    for (int i = 0; i < NUM_MONTHS; i++) {
        if (sales[i] < min_sales) {//loops through sales and aleus for respective array
            min_sales = sales[i];//kinda like a bubble sort
        }
        if (sales[i] > max_sales) {
            max_sales = sales[i];
        }
        sum += sales[i];
    }
    float avg_sales = sum / NUM_MONTHS;
    printf("\nSales Summary Report:\n");
    printf("Minimum sales: %.2f (%s)\n", min_sales, months[0]);
    printf("Maximum sales: %.2f (%s)\n", max_sales, months[11]);
    printf("Average sales: %.2f\n", avg_sales);

    // Calculate the six-month moving average report
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < NUM_MONTHS - 5; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s-%s: %.2f\n", months[i], months[i + 5], sum / 6);
    }

    // Calculate the sales report (highest to lowest)
    int temp;// another nested loop making our bubble sort
    for (int i = 0; i < NUM_MONTHS; i++) {
        for (int j = i + 1; j < NUM_MONTHS; j++) {
            if (sales[i] < sales[j]) {
                temp = sales[i];
                sales[i] = sales[j];
                sales[j] = temp;
            }
        }
    }
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month\tSales\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%s\t%.2f\n", months[NUM_MONTHS - i - 1], sales[i]);
    }

    return 0;
} 
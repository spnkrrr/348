#include <stdio.h>
#include <stdlib.h>

int main()
{
    //months and file variable created
    char filename[100];
    char months[][12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    //prompt user for file and open it
    printf("Enter the file name: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    //store file input in sales
    double sales[12];
    int num_months = 0;
    while (fscanf(file, "%lf", &sales[num_months]) == 1 && num_months < 12) {
        num_months++;
    }

    fclose(file);

    //display monthly report
    printf("\nMonthly sales report for 2022:\n");
    printf("%-12s %-12s \n", "Month", "Sales");

    for (int i = 0; i < num_months; i++) {
        printf("%-12s $%-12.2f \n", months[i], sales[i]);
    }

    //find the minimum, maximum, and total sales and print them
    double total = 0;
    double min_sales = sales[0];
    double max_sales = sales[0];

    for (int i = 0; i < num_months; i++) {
        total += sales[i];

        if (sales[i] < min_sales) {
            min_sales = sales[i];
        }

        if (sales[i] > max_sales) {
            max_sales = sales[i];
        }
    }

    double average = total / num_months;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sales, months[0]);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, months[num_months - 1]);
    printf("Average sales: $%.2f\n", average);

    //print six month average sales report by finding each of the averages for six month periods
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= num_months - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }

        double average = sum / 6;
        printf("%-9s - %-12s $%.2f\n", months[i], months[i + 5], average);
    }

    //order and print the monthly sales from highest to lowest
    printf("\nSales Report (Highest to Lowest):\n");
    printf("%-12s %-12s \n", "Month", "Sales");
    int high_to_low[num_months];
    for (int i = 0; i < num_months; i++) {
        high_to_low[i] = i;
    }

    //sort and swap order of high_to_low based on amount
    for (int i = 0; i < num_months - 1; i++) {
        for (int j = 0; j < num_months - i - 1; j++) {
            if (sales[high_to_low[j]] < sales[high_to_low[j + 1]]) {
                int temp = high_to_low[j];
                high_to_low[j] = high_to_low[j + 1];
                high_to_low[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < num_months; i++) {
        printf("%-12s $%-12.2f \n", months[high_to_low[i]], sales[high_to_low[i]]);
    }

    return 0;
}


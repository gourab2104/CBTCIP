#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char date[20];
    float amount;
    char category[50];
    char description[100];
};

void addExpense(struct Expense *expenses, int *count) {
    if (*count < MAX_EXPENSES) {
        printf("\nEnter expense details:\n");

        printf("Date (MM/DD/YYYY): ");
        scanf("%s", expenses[*count].date);

        printf("Amount: $");
        scanf("%f", &expenses[*count].amount);

        printf("Category: ");
        scanf("%s", expenses[*count].category);

        printf("Description: ");
        scanf(" %[^\n]s", expenses[*count].description);

        (*count)++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense limit reached. Cannot add more expenses.\n");
    }
}

void generateReport(struct Expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses to generate a report.\n");
        return;
    }

    printf("\nExpense Report:\n");
    printf("%-15s %-10s %-20s %s\n", "Date", "Amount", "Category", "Description");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < count; ++i) {
        printf("%-15s $%-9.2f %-20s %s\n", expenses[i].date, expenses[i].amount, expenses[i].category, expenses[i].description);
    }
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int expenseCount = 0;
    int choice;

    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Generate Report\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &expenseCount);
                break;
            case 2:
                generateReport(expenses, expenseCount);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

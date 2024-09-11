#include <stdio.h>
#define MAX 100

int main(void) {
    char names[MAX][20];
    char firstNames[MAX][20];
    int grades[MAX];

    int max = 0, min = 0, average = 0;
    int choice;
    int count = 0;

    do {
        printf("Select an option from the menu:\n");
        printf("1: Add a student.\n");
        printf("2: Display the average grade.\n");
        printf("3: Display the student with the highest and lowest grade.\n");
        printf("4: Display the number of students with grades above the average.\n");
        printf("5: Quit.\n");

        do {
            printf("Your choice: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 5);

        switch (choice) {
        case 1:
            if (count >= MAX) {
                printf("Maximum number of students reached.\n");
                break;
            }
            printf("Enter the student's last name: ");
            scanf("%s", names[count]);
            printf("Enter the student's first name: ");
            scanf("%s", firstNames[count]);
            printf("Enter the student's grade: ");
            scanf("%d", &grades[count]);

            // Update max and min indices
            if (count == 0 || grades[count] > grades[max]) {
                max = count;
            }
            if (count == 0 || grades[count] < grades[min]) {
                min = count;
            }
            count++;
            break;

        case 2:
            if (count == 0) {
                printf("No students have been added.\n");
            } else {
                average = 0;
                for (int i = 0; i < count; i++) {
                    average += grades[i];
                }
                average /= count;
                printf("The average grade is: %d\n", average);
            }
            break;

        case 3:
            if (count == 0) {
                printf("No students have been added.\n");
            } else {
                printf("The student with the highest grade is: %s %s with a grade of %d\n", names[max], firstNames[max], grades[max]);
                printf("The student with the lowest grade is: %s %s with a grade of %d\n", names[min], firstNames[min], grades[min]);
            }
            break;

        case 4:
            if (count == 0) {
                printf("No students have been added.\n");
            } else {
                int aboveAverageCount = 0;
                int grades1[2];
                int ntc1,ntc2;

                printf("Enter the student's grade2: ");
            scanf("%d", &grades1[0]);

            printf("Enter the student's grade2: ");
            scanf("%d", &grades1[1]);

                for (int i = 0; i < count; i++) {
                    if (grades1[i] > average) {
                        aboveAverageCount++;
                    }
                }
                printf("The number of students with grades above the average is: %d\n", aboveAverageCount);
            }
            break;

        case 5:
            printf("Goodbye!\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

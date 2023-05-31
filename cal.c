#include <stdio.h>

int main() {
    int month, year, daysInMonth, startingDay;

    // Input month and year
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    // Determine the number of days in the month
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            // Check if it's a leap year
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                daysInMonth = 29;
            else
                daysInMonth = 28;
            break;
        default:
            printf("Invalid month!\n");
            return 0;
    }

    // Determine the starting day of the month
    printf("\n");
    printf("---------------------------\n");
    printf("   Calendar - %d/%d\n", month, year);
    printf("---------------------------\n");

    // January 1, 1 AD was a Monday
    startingDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 1; i < month; i++) {
        switch (i) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                startingDay += 31;
                break;
            case 4: case 6: case 9: case 11:
                startingDay += 30;
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                    startingDay += 29;
                else
                    startingDay += 28;
                break;
        }
    }
    startingDay %= 7;

    // Display the calendar
    printf(" Mon Tue Wed Thu Fri Sat Sun\n");
    for (int i = 0; i < startingDay; i++)
        printf("    ");
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%4d", day);
        if ((startingDay + day) % 7 == 0)
            printf("\n");
    }
    printf("\n---------------------------\n");
    getch();
    return 0;
}

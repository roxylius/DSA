// calculate the difference in time period by passing the structure to the fuction
#include <stdio.h>
#include <string.h>

typedef struct TimePeriod12Hours
{
    int hours;
    int minutes;
    char am_pm[2];
} time;

void calculateTimeDifference(time *times)
{
    //char containing am/pm
    char a = 'A';
    char p = 'P';

    //pointers pointing to am/pm
    char *am = &a;
    char *pm = &p;

    // converting the hours in AM/PM to 24 hours also comparing pointers to pointers
    if (times[0].am_pm[0] == *pm)
        times[0].hours += 12;
    else if (times[0].am_pm[0] != *am)
        printf("\nError");

    if (times[1].am_pm[0] == *pm)
        times[1].hours += 12;
    else if (times[1].am_pm[0] != *am)
        printf("\nError");

    // calculating the time difference
    if (times[0].hours > times[1].hours)
    {
        int hourDifferenceInMinutes = (times[0].hours - times[1].hours)*60;
        int minuteDifference = times[0].minutes - times[1].minutes;

        //incase the minutes in earlier time is greater
        int totalMinutes = minuteDifference + hourDifferenceInMinutes;

        //difference in hour
        int hour = totalMinutes / 60;
        int minutes = totalMinutes - (hour * 60);

        // displaying the time diff
        printf("\nThe Time Difference Between the two times: %d Hours and %d Minutes", hour, minutes);

    }else if (times[0].hours < times[1].hours)
    {
        int hourDifferenceInMinutes = (times[1].hours - times[0].hours) * 60;
        int minuteDifference = times[1].minutes - times[0].minutes;

        // incase the minutes in earlier time is greater
        int totalMinutes = minuteDifference + hourDifferenceInMinutes;

        // difference in hour
        int hour = totalMinutes / 60;
        int minutes = totalMinutes - (hour * 60);

        // displaying the time diff
        printf("\nThe Time Difference Between the two times: %d Hours and %d Minutes", hour, minutes);
    }else{
        printf("\nBoth times are Equal!");
    }



}

int main()
{
    // array for both time periods
    time times[2];

    // taking the 2 time values
    printf("Enter the Time[Format: hh:mm AM/PM] to Calculate Difference In Time -->\n");
    for (int i = 0; i < 2; i++)
    {
        printf("Time %d: ", i + 1);
        scanf("%d:%d %s", &times[i].hours, &times[i].minutes, &times[i].am_pm);
    }

    // passing the times array struct to function and displaying the diff
    calculateTimeDifference(times);

    return 0;
}
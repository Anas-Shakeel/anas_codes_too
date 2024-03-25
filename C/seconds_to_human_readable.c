#include <stdio.h>

// Custom structure to hold divmod values
typedef struct
{
    unsigned long long quotient;
    unsigned long long remainder;
} DIVMOD;

// Custom structure to hold time values
typedef struct
{
    unsigned long long seconds,
        minutes, hours, days,
        months, years;
} TIME;

// Limit of seconds that can be taken as input
const unsigned long long LIMIT = 9999999999999999999;

// Functions prototypes
TIME calculate_time(unsigned long long seconds);
DIVMOD divmod(unsigned long long divisor,
              unsigned long long dividend);

int main(void)
{
    // Get the seconds from user (upto 10 digits)
    unsigned long long seconds;
    printf("Enter seconds: ");
    scanf("%llu", &seconds);
    if (seconds <= 0)
    {
        printf("seconds must be positive.\n");
        return 1;
    }
    if (seconds > LIMIT)
    {
        printf("seconds can have 19 digits maximum.\n");
        return 1;
    }

    // Calculate the time
    TIME time = calculate_time(seconds);

    // Print the time in human-readable format
    if (time.years > 0)
    {
        printf("%llu years ", time.years);
    }
    if (time.months > 0)
    {
        printf("%llu months ", time.months);
    }
    if (time.days > 0)
    {
        printf("%llu days ", time.days);
    }
    if (time.hours > 0)
    {
        printf("%llu hours ", time.hours);
    }
    if (time.minutes > 0)
    {
        printf("%llu minutes ", time.minutes);
    }
    if (time.seconds > 0)
    {
        printf("%llu seconds\n", time.seconds);
    }

    return 0;
}

TIME calculate_time(unsigned long long seconds)
{
    DIVMOD result; // will hold the divmod values
    TIME t;        // will hold calculated time

    result = divmod(seconds, 60);
    t.minutes = result.quotient;
    t.seconds = result.remainder;

    result = divmod(t.minutes, 60);
    t.hours = result.quotient;
    t.minutes = result.remainder;

    result = divmod(t.hours, 24);
    t.days = result.quotient;
    t.hours = result.remainder;

    t.months = t.days / 30;
    t.days = t.days % 30;

    t.years = t.months / 12;
    t.months = t.months % 12;

    return t;
}

DIVMOD divmod(unsigned long long divisor,
              unsigned long long dividend)
{
    DIVMOD result;
    result.quotient = divisor / dividend;
    result.remainder = divisor % dividend;
    return result;
}

/*

Calculate_time(int seconds)
    takes seconds as input
    returns a string as output

    Examples:
        >> calculate_time(60);
        >> "1 minute"

        >> calculate_time(97);
        >> "1 minute, 37 seconds"

        >> calculate_time(7200);
        >> "2 hour"

        >> calculate_time(9028);
        >> "2 hour, 30 minute, 28 seconds"



MAX Int limit: 999999999
MAX unsigned long long limit: 9999999999999999999
*/
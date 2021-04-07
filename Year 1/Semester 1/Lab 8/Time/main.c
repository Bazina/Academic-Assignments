#include <stdio.h>
#include <stdlib.h>

struct time{
    int seconds;
    int minutes;
    int hours;
};

struct time split_time(long long int total_seconds);

int main(){
    struct time t;
    long long total_seconds;
    printf("\nEnter total seconds: ");
    scanf("%lld", &total_seconds);
    t = split_time(total_seconds);
    printf("\n%d hours, %d minutes, %d seconds\n", t.hours, t.minutes, t.seconds);

    return 0;
}

struct time split_time(long long int total_seconds){
    struct time time1;
    if (total_seconds >= 86400){
        total_seconds = total_seconds % 86400;
    }
    time1.hours = total_seconds / 3600;
    time1.minutes = (total_seconds % 3600) / 60;
    time1.seconds = (total_seconds%3600) % 60;
    return time1;
}

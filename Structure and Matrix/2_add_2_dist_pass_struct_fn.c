// add two distances in km-meter by passing structure to a function
#include<stdio.h>

typedef struct metricDistances
{
    int kilometers;
    int meters;
}metricDistances;

int addDistances(metricDistances *distances){
    const int KILO_IN_METERS = 1000;
    int kiloInMeters = distances->kilometers * KILO_IN_METERS;
    return kiloInMeters + distances->meters;
}

int main()
{
    metricDistances variable;
    printf("Enter the distances to Add -->");
    printf("\nin Kilometers: ");
    scanf("%d",&variable.kilometers);
    printf("in meters: ");
    scanf("%d",&variable.meters);

    //sum of the two distances in structure
    int sumOfDistances = addDistances(&variable);
    printf("\nThe sum of the two distances = %d m",sumOfDistances);
    return 0;
}
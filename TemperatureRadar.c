#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>


typedef int Temperature;

int generateTemperature(int min, int max){
    return min + rand() % (max - min +1);
}

void writeTmperature(FILE *file, Temperature temp, int hour){
    fprintf(file, "hour: %d - %d c\n", hour, temp);
}

int getActualDay(FILE *file){
    char line[100];
    int actualDay = 0;

    rewind(file);

    while (fgets(line, sizeof(line), file))
    {
        int tempDay;

        if (sscanf(line, "Day %d:", &tempDay) == 1)
        {
            actualDay = tempDay;
        }
    }
    return actualDay+1;
}

float calulateTemperatureAverage(int *arr){
    int total =0;
    for (size_t i = 0; i < 24; i++)
    {
        total += arr[i];
    }
    
    return (float)total / 24.0f;
}

void typeDay(float avrgTemperature, FILE *file){
    if (avrgTemperature < 10)
    {
        fprintf(file, "%s Type of the day: ", "hot");
    }else if (avrgTemperature > 30)
    {
        fprintf(file, "%s Type of the day: ", "cold");
    }else
    {
        fprintf(file, "%s Type of the day: ", "average");
    }
}

int main(){

    int day;
    int dayTemperatures[24];
    FILE *file = fopen("register.txt", "r");
    if (file != NULL) {
        day = getActualDay(file);
        fclose(file);
    }

    file = fopen("register.txt", "a");
    if (file ==NULL)
    {
        printf("%s Error opening the file");
        return 1;
    }

    fprintf(file,"Day %d : \n" , day);

    int i= 0;
    while (i <= 24)
    {
        Temperature temp = generateTemperature(0, 45);
        
        writeTmperature(file, temp, i);
        dayTemperatures[i] = temp;
        printf("%d\n", temp);   
        
        sleep(1);
        i++;
    }

    float average =  calulateTemperatureAverage(dayTemperatures);
    
    printf(" temp avrg %f", average);

    fprintf(file, "Temperature average: %f", average);
    typeDay(average, file);

    fclose(file);

    return 0;
}
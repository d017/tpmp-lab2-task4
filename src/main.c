#include <stdio.h>
#include <stdlib.h>
#include "car.h"


#define CURRENT_YEAR 2026  

int main() {
    int num_cars;
    
    printf("Enter number of cars: ");
    scanf("%d", &num_cars);
    
    
    CAR** cars = (CAR**)malloc(num_cars * sizeof(CAR*));
    
    
    for (int i = 0; i < num_cars; i++) {
        cars[i] = create_car();
        input_car_data(cars[i], i + 1);
    }
    
    
    printf("\nAll cars:\n");
    for (int i = 0; i < num_cars; i++) {
        print_car_info(cars[i]);
    }
    
    printf("\nCars older than 3 years:\n");
    int found = 0;
    for (int i = 0; i < num_cars; i++) {
        if (is_car_older_than(cars[i], 3, CURRENT_YEAR)) {
            print_car_info(cars[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("\nNo cars older than 3 years\n");
    }
    
    for (int i = 0; i < num_cars; i++) {
        free_car(cars[i]);
    }
    free(cars);
    
    return 0;
}
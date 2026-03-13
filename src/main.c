#include <stdio.h>
#include <stdlib.h>
#include "car.h"


#define CURRENT_YEAR 2026  
#define INPUT_FILE "src/input.txt"
#define OUTPUT_FILE "src/output.txt"

int main() {
    printf("Reading info");
    
    int n;
    CAR** cars = read_cars_from_file(INPUT_FILE, &n);
    
    if (!cars || n == 0) {
        printf("Error loading from file\n");
        return 1;
    }
    printf("\nLoaded %d cars\n", n);
    
    write_cars_to_file(OUTPUT_FILE, cars, n, CURRENT_YEAR);
    
    for (int i = 0; i < n; i++) {
        free_car(cars[i]);
    }
    free(cars);
    
    return 0;
}
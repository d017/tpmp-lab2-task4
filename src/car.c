#include "car.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct CAR {
    char* brand;
    char* color;
    char* serial_number;
    char* reg_number;
    int year_manufacture;
    int year_inspection;
    double price;
};


CAR* create_car() {
    CAR* car = (CAR*)calloc(1, sizeof(CAR));
    return car;
}

void free_car(CAR* car) {
    if (car) {
        free(car->brand);
        free(car->color);
        free(car->serial_number);
        free(car->reg_number);
        free(car);
    }
}

void set_car_brand(CAR* car, const char* brand) {
    if (car && brand) {
        if (car->brand) free(car->brand);
        car->brand = (char*)malloc((strlen(brand) + 1) * sizeof(char));
        strcpy(car->brand, brand);
    }
}

void set_car_color(CAR* car, const char* color) {
    if (car && color) {
        if (car->color) free(car->color);
        car->color = (char*)malloc((strlen(color) + 1) * sizeof(char));
        strcpy(car->color, color);
    }
}

void set_car_serial(CAR* car, const char* serial) {
    if (car && serial) {
        if (car->serial_number) free(car->serial_number);
        car->serial_number = (char*)malloc((strlen(serial) + 1) * sizeof(char));
        strcpy(car->serial_number, serial);
    }
}

void set_car_reg_number(CAR* car, const char* reg_number) {
    if (car && reg_number) {
        if (car->reg_number) free(car->reg_number);
        car->reg_number = (char*)malloc((strlen(reg_number) + 1) * sizeof(char));
        strcpy(car->reg_number, reg_number);
    }
}

void set_car_year_manufacture(CAR* car, int year) {
    if (car) {
        car->year_manufacture = year;
    }
}

void set_car_year_inspection(CAR* car, int year) {
    if (car) {
        car->year_inspection = year;
    }
}

void set_car_price(CAR* car, double price) {
    if (car) {
        car->price = price;
    }
}

const char* get_car_brand(const CAR* car) {
    return car ? car->brand : NULL;
}

const char* get_car_color(const CAR* car) {
    return car ? car->color : NULL;
}

const char* get_car_serial(const CAR* car) {
    return car ? car->serial_number : NULL;
}

const char* get_car_reg_number(const CAR* car) {
    return car ? car->reg_number : NULL;
}

int get_car_year_manufacture(const CAR* car) {
    return car ? car->year_manufacture : 0;
}

int get_car_year_inspection(const CAR* car) {
    return car ? car->year_inspection : 0;
}

double get_car_price(const CAR* car) {
    return car ? car->price : 0.0;
}

void print_car_info(const CAR* car, FILE* output) {
    if (!car || !output) return;
    fprintf(output, "\n");
    fprintf(output, "Brand: %s\n", get_car_brand(car));
    fprintf(output, "Color: %s\n", get_car_color(car));
    fprintf(output, "Serial number: %s\n", get_car_serial(car));
    fprintf(output, "Registration number: %s\n", get_car_reg_number(car));
    fprintf(output, "Year of manufacture: %d\n", get_car_year_manufacture(car));
    fprintf(output, "Year of inspection: %d\n", get_car_year_inspection(car));
    fprintf(output, "Price: %.2f\n", get_car_price(car));
    fprintf(output, "\n");
}

int is_car_older_than(const CAR* car, int years, int current_year) {
    if (!car) return 0;
    return (current_year - get_car_year_manufacture(car)) > years;
}

CAR** read_cars_from_file(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Cant open input file");
        *count = 0;
        return NULL;
    }
    
    
    int num_cars;
    if (fscanf(file, "%d", &num_cars) != 1 || num_cars <= 0) {
        printf("Invalid format\n");
        fclose(file);
        *count = 0;
        return NULL;
    }
    
    
    CAR** cars = (CAR**)malloc(num_cars * sizeof(CAR*));
    if (!cars) {
        printf("Memory allocation error\n");
        fclose(file);
        *count = 0;
        return NULL;
    }
    
    char buffer[100];
    
    
    for (int i = 0; i < num_cars; i++) {
        cars[i] = create_car();
        
        
        if (fscanf(file, "%99s", buffer) != 1) {
            printf("No brand for car %d\n", i + 1);
            break;
        }
        set_car_brand(cars[i], buffer);
        
        
        if (fscanf(file, "%99s", buffer) != 1) {
            printf("No color for car %d\n", i + 1);
            break;
        }
        set_car_color(cars[i], buffer);
        
        
        if (fscanf(file, "%99s", buffer) != 1) {
            printf("No serial number for car %d\n", i + 1);
            break;
        }
        set_car_serial(cars[i], buffer);
        
        
        if (fscanf(file, "%99s", buffer) != 1) {
            printf("No registration number for car %d\n", i + 1);
            break;
        }
        set_car_reg_number(cars[i], buffer);
        
        
        int year;
        if (fscanf(file, "%d", &year) != 1) {
            printf("No year of manufacture for car %d\n", i + 1);
            break;
        }
        set_car_year_manufacture(cars[i], year);
        
        
        if (fscanf(file, "%d", &year) != 1) {
            printf("No year of inspection for car %d\n", i + 1);
            break;
        }
        set_car_year_inspection(cars[i], year);
        
        
        double price;
        if (fscanf(file, "%lf", &price) != 1) {
            printf("No price for car %d\n", i + 1);
            break;
        }
        set_car_price(cars[i], price);
    }
    
    fclose(file);
    *count = num_cars;
    return cars;
}

void write_cars_to_file(const char* filename, CAR** cars, int count, int current_year) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Cant open output file");
        return;
    }
    
    
    fprintf(file, "Cars: %d\n", count);
    
    for (int i = 0; i < count; i++) {
        print_car_info(cars[i], file);
    }
    
    fprintf(file, "\nCars older than 3 years:\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (is_car_older_than(cars[i], 3, current_year)) {
            print_car_info(cars[i], file);
            found = 1;
        }
    }
    
    if (!found) {
        fprintf(file, "\nNo cars older than 3 years\n");
    }
    
    fclose(file);
    printf("Output written to %s\n", filename);
}
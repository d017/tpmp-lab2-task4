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

void input_car_data(CAR* car, int car_number) {
    if (!car) return;
    
    char buffer[100];
    
    printf("\nCar %d \n", car_number);
    
    printf("Enter brand: ");
    scanf("%99s", buffer);
    set_car_brand(car, buffer);
    
    printf("Enter color: ");
    scanf("%99s", buffer);
    set_car_color(car, buffer);
    
    printf("Enter serial number: ");
    scanf("%99s", buffer);
    set_car_serial(car, buffer);
    
    printf("Enter registration number: ");
    scanf("%99s", buffer);
    set_car_reg_number(car, buffer);
    
    printf("Enter year of manufacture: ");
    int year;
    scanf("%d", &year);
    set_car_year_manufacture(car, year);
    
    printf("Enter year of last inspection: ");
    scanf("%d", &year);
    set_car_year_inspection(car, year);
    
    printf("Enter price: ");
    double price;
    scanf("%lf", &price);
    set_car_price(car, price);
}

void print_car_info(const CAR* car) {
    if (!car) return;
    
    printf("\nCar\n");
    printf("Brand: %s\n", get_car_brand(car));
    printf("Color: %s\n", get_car_color(car));
    printf("Serial number: %s\n", get_car_serial(car));
    printf("Registration number: %s\n", get_car_reg_number(car));
    printf("Year of manufacture: %d\n", get_car_year_manufacture(car));
    printf("Year of last inspection: %d\n", get_car_year_inspection(car));
    printf("Price: %.2f\n", get_car_price(car));
}

int is_car_older_than(const CAR* car, int years, int current_year) {
    if (!car) return 0;
    return (current_year - get_car_year_manufacture(car)) > years;
}
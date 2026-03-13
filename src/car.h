#ifndef CAR_H
#define CAR_H


typedef struct CAR CAR;


CAR* create_car();


void free_car(CAR* car);


void set_car_brand(CAR* car, const char* brand);
void set_car_color(CAR* car, const char* color);
void set_car_serial(CAR* car, const char* serial);
void set_car_reg_number(CAR* car, const char* reg_number);
void set_car_year_manufacture(CAR* car, int year);
void set_car_year_inspection(CAR* car, int year);
void set_car_price(CAR* car, double price);


const char* get_car_brand(const CAR* car);
const char* get_car_color(const CAR* car);
const char* get_car_serial(const CAR* car);
const char* get_car_reg_number(const CAR* car);
int get_car_year_manufacture(const CAR* car);
int get_car_year_inspection(const CAR* car);
double get_car_price(const CAR* car);


void input_car_data(CAR* car, int car_number);
void print_car_info(const CAR* car);
int is_car_older_than(const CAR* car, int years, int current_year);

#endif
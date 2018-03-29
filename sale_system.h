#pragma once

#ifndef SALE_SESTEM_H
#define SALE_SESTEM_H
#define COMPUTER_CASE 1
#define DISPLAY 2
#define PERIPHERAL 3

#include<vector>
#include<iostream>
using namespace std;
const int case_price = 25;
const int display_price = 30;
const int peripheral_price = 45;
extern int case_amount;
extern int display_amount;
extern int peripheral_amount;

class SaleSystem {
public:
	SaleSystem();
	SaleSystem(int salesman_sum);
	float salary(int sales_amount);
	bool typein_sale_data(int sales_man_no, int computer_case, 
		int display, int periheral);
	int get_amount(int sales_man_no);
	float get_salary(int sales_man_no);
	bool sale(int sales_man_no, int product_type, int num);
private:
	int salesman_sum_;
	int* computer_case_;
	int* dispaly_;
	int* peripheral_;
	int* sales_amount_;
	float* salary_;
};


#endif // !SALE_SESTEM_H
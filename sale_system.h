#pragma once
#ifndef SALE_SESTEM_H
#define SALE_SESTEM_H
#define COMPUTER_CASE 1
#define DISPLAY 2
#define PERIPHERAL 3

#include<vector>
#include<iostream>
using namespace std;
int case_price = 25;
int display_price = 30;
int peripheral_price = 45;
int case_amount = 70;
int display_amount = 80;
int peripheral_amount = 90;

class SaleSystem {
public:
	SaleSystem();
	SaleSystem(int salesman_sum);
	int salary(int sales_amount);
	bool typein_sale_data(int sales_man_no, int computer_case, 
		int display, int periheral);
	bool sale(int sales_man_no, int product_type, int num);
private:
	int salesman_sum_;
	int* computer_case_;
	int* dispaly_;
	int* peripheral_;
	int* sales_amount_;
	int* salary_;
};


#endif // !SALE_SESTEM_H
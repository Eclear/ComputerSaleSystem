#include "sale_system.h"
#include<vector>
#include<numeric>
#include<iostream>
using namespace std;

SaleSystem::SaleSystem()
{
	salesman_sum_ = 0;
	computer_case_ = NULL;
	dispaly_ = NULL;
	peripheral_ = NULL;
	sales_amount_ = NULL;
	salary_ = NULL;
}

SaleSystem::SaleSystem(int salesman_sum)
{
	salesman_sum_ = salesman_sum;
	computer_case_ = new int[salesman_sum]();
	dispaly_ = new int[salesman_sum]();
	peripheral_ = new int[salesman_sum]();
	sales_amount_ = new int[salesman_sum]();
	salary_ = new int[salesman_sum]();
}

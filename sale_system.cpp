#include "sale_system.h"

using namespace std;

int case_amount = 70;
int display_amount = 80;
int peripheral_amount = 90;

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
	salary_ = new float[salesman_sum]();
}

float SaleSystem::salary(int sales_amount)  //Gradient salary
{
	float m_salary;
	if (sales_amount <= 1000 && sales_amount >= 0) {
		m_salary = sales_amount * 0.1;
	}
	else if (sales_amount < 1800) {
		m_salary = 1000 * 0.1 + (sales_amount - 1000)*0.15;
	}
	else {
		m_salary = 1000 * 0.1 + 800 * 0.15 + (sales_amount - 1800)*0.2;
	}
	return m_salary;
}

bool SaleSystem::typein_sale_data(int sales_man_no, int computer_case, int display, int periheral)
{
	//Sale the products
	sale(sales_man_no, COMPUTER_CASE, computer_case);
	sale(sales_man_no, DISPLAY, display);
	sale(sales_man_no, PERIPHERAL, periheral);
	return true;
}

int SaleSystem::get_amount(int sales_man_no)
{
	sales_amount_[sales_man_no] = case_price * computer_case_[sales_man_no]
		+ display_price * dispaly_[sales_man_no]
		+ peripheral_price * peripheral_[sales_man_no];
	return sales_amount_[sales_man_no];
}

float SaleSystem::get_salary(int sales_man_no)
{
	salary_[sales_man_no] = salary(sales_amount_[sales_man_no]);
	return salary_[sales_man_no];
}

bool SaleSystem::sale(int sales_man_no, int product_type, int num)
{
	int *product;
	int price;
	int *amount;
	switch (product_type)
	{
	case COMPUTER_CASE: 
		product = computer_case_;
		price = case_price;
		amount = &case_amount;
		break;
	case DISPLAY:
		product = dispaly_;
		price = display_price;
		amount = &display_amount;
		break;
	case PERIPHERAL:
		product = peripheral_;
		price = peripheral_price;
		amount = &peripheral_amount;
		break;
	default:
		break;
	}
	if (num < 0) {
		cout << "Input wrong!\n";
		return false;
	}
	//There are enough products
	if (num < *amount && num >= 0) {
		*amount -= num;
		product[sales_man_no] += num;
	}
	//Products are not enough
	else {
		num = *amount;
		*amount -= num;
		product[sales_man_no] += num;
	}
	return true;
}

#include "sale_system.h"
//#include<vector>
//#include<numeric>
//#include<iostream>
using namespace std;
int main() {
	int sales_man_no,computer_case,display,peripheral,sales_man_sum;
	cout << "Type in the amount of salesman: ";
	cin >> sales_man_sum;
	SaleSystem my_system(sales_man_sum);

	cout << "Computer sale system created, " << sales_man_sum << " salesmen contained.\n"
		<< "Enter the sale data now,type -2 to exit: \n";
	cin >> sales_man_no >> computer_case;
	
	while (sales_man_no > -2) {
		if (computer_case == -1) {
			cout << my_system.get_amount(sales_man_no) << " ";
			cout << my_system.get_salary(sales_man_no) << endl;
		}
		else {
			cin >> display >> peripheral;
			my_system.typein_sale_data(sales_man_no, computer_case, display, peripheral);
		}
		cin >> sales_man_no >> computer_case;
	}
	return 0;
}
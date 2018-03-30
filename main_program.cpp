//Read data from a file named "test.xls"
//The first line should include one integer which is she sum of salesmen(from 1 to 10)
//Substance lines include atmost 4 integers in respensentive of salesman number(0 to sum-1),
//computer case, display and peripheral. -1 on computer case means get the sales amount and
//salary of the appointed salesman.


#include "sale_system.h"
#include<fstream>
#include<sstream>
//#include<vector>
//#include<numeric>
//#include<iostream>
using namespace std;



bool write_xls(string file_name) {
	ofstream out_file;
	out_file.open(file_name, ios::out | ios::trunc);
	out_file << 3 << endl;
	out_file << 0 << "\t" << 10 << "\t" << 0 << "\t" << 0 << "\t" << endl;
	out_file << 0 << "\t" << 10 << "\t" << 0 << "\t" << 0 << "\t" << endl;
	out_file << 0 << "\t" << -1 << "\t" << 0 << "\t" << 0 << "\t" << endl;
	out_file.close();
	return true;
}


vector<int> read_xls(ifstream& in_file) {
	//get a line of ints in xls, return vector
	vector<int> line_res;
	int current;
	string line;
	string token;
	stringstream stream1, stream2;
	if (getline(in_file, line)) {
		//get a line of data in xls
		cout << line << endl;
		stream1 << line;
		while (getline(stream1, token, '\t')) {
			//get a line of integers and convert into vactor
			stream2 << token;
			stream2 >> current;
			line_res.push_back(current);
			stream2.clear();
			if (line_res.size()>1 && line_res[1] == -1) {
				break;
			}
		}
		stream1.clear();
	}
	return line_res;
}

int main() {
	//write_xls("test.xls"); //Write the test data to test.xls
	vector<int> line_data;
	int sales_man_no,computer_case,display,peripheral,sales_man_sum;
	//cout << "Type in the amount of salesman: ";
	//cin >> sales_man_sum;
	ifstream in_file;
	ofstream out_file;
	in_file.open("test.xls");
	out_file.open("result.xls", ios::out | ios::trunc);
	line_data = read_xls(in_file);
	sales_man_sum = line_data[0];
	SaleSystem my_system(sales_man_sum);

	

	//cout << "Computer sale system created, " << sales_man_sum << " salesmen contained.\n"
	//	<< "Enter the sale data now,type -2 to exit: \n";
	line_data = read_xls(in_file);
	//cin >> sales_man_no >> computer_case;
	if (!line_data.empty()) {
		sales_man_no = line_data[0];
		computer_case = line_data[1];
	}
	while (sales_man_no >= 0) {
		if (computer_case == -1) {
			out_file << my_system.get_amount(sales_man_no) << "\t";
			out_file << my_system.get_salary(sales_man_no) << endl;
			//cout << my_system.get_amount(sales_man_no) << " ";
			//cout << my_system.get_salary(sales_man_no) << endl;
		}
		else {
			display = line_data[2];
			peripheral = line_data[3];
			//cin >> display >> peripheral;
			my_system.typein_sale_data(sales_man_no, computer_case, display, peripheral);
		}
		//cin >> sales_man_no >> computer_case;
		line_data = read_xls(in_file);
		if (line_data.empty()) break;
		sales_man_no = line_data[0];
		computer_case = line_data[1];
	}
	in_file.close();
	out_file.close();
	return 0;
}
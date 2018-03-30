#Building notes
* C++ 编译器从语句右侧读起，所以需要先执行的语句成分不要放在右边，可以将它们单独分开
```
out_file << my_system.get_amount(sales_man_no) << "\t"
        << my_system.get_salary(sales_man_no) << endl;
```
to:
```
out_file << my_system.get_amount(sales_man_no) << "\t";
out_file << my_system.get_salary(sales_man_no) << endl;
```
* 需要连续读写的文件，可以把fstream对象作为参数按引用传给文件处理函数
```
main(){
  ...
	ifstream in_file;
	ofstream out_file;
	in_file.open("test.xls");
	out_file.open("result.xls", ios::out | ios::trunc);
 }
 
vector<int> read_xls(ifstream& in_file){
  ...
}
```

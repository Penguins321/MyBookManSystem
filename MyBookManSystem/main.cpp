#include<iostream>
#include"book.h"
#include"user.h"
#include"admin.h"
#include"student.h"
#include<iomanip>
using namespace std;
void menu_admin();
void menu_student();

int main() {

	/*
	封装好需要的类，实现其功能，最后组装
	book类的：同类型图书数量(一对多的关系)    属性的设计----> 学习使用观察者模式
	同类型书籍数量未存文件
	添加时同类型书籍未增加，修改时有
	添加，删除书籍的逻辑，先判断同名书籍是否大于1      
	密码输入错误时的逻辑判断
	*/
	User user;
	Book book;
	Admin admin;
	Student stu;
	vector<User> vec_user;
	vector<Book> vec_book;
	vector<Book> vec_temp;									// 用于存放展示数据，用完清空
	user.fetchUser(vec_user);								// 读取用户文件			
	book.fetchBook(vec_book);
	user = user.login(vec_user, user);
	while (!user.login_status) {
		user = user.login(vec_user, user);
	}
	int choice;
	// 判断用户权限
	if (user.role == 1) {		// 管理员
		do
		{
			menu_admin();
			// 重置choice 
			cin >> choice;
			while (cin.get() != '\n')
				continue;
			switch (choice) {
			case 1:
				user.createUser(vec_user);
				break;
			case 2:
				user.showUser(vec_user);
				break;
			case 3:
				user.deleteUser(vec_user);
				break;
			case 4:
				admin.showBook(vec_book);
				break;
			case 5:
				book.modifyByIsbn(vec_book);
				break;
			case 6:
				admin.appendBook(vec_book);
				break;
			case 7:
				admin.findBook(vec_book, vec_temp);
				vec_temp.clear();
				break;
			case 8:
				admin.deleteBook(vec_book);
			default:
				break;
			}
		} while (choice);
	}
	else if (user.role == 2) {				// 学生
		do {
			menu_student();
			cin >> choice;
			while (cin.get() != '\n')
				continue;
			switch (choice) {
			case 1:
				stu.showBook(vec_book);
				break;
			case 2:
				stu.findBook(vec_book, vec_temp);
				vec_temp.clear();
				break;
			case 3:
				stu.borrowBook(vec_book);
				break;
			case 4:
				stu.returnBook(vec_book);
				break;
			default:
				break;
			}
		} while (choice);
	}
	// 信息存储到文件
	book.saveBook(vec_book);
	user.saveUser(vec_user);
	return 0;
}

void menu_admin() {
	cout << "+-----------------------------------------------+\n";
	cout << "|           图书信息管理系统                   |\n";
	cout << "+-----------------------------------------------+\n";

	// 让每一列对齐，使用 setw 来设置列宽
	cout << "| " << left << setw(20) << "1、注册用户账号"
		<< "| " << setw(20) << "5、修改图书信息" << "|\n";
	cout << "| " << left << setw(20) << "2、查看用户账号"
		<< "| " << setw(20) << "6、添加图书" << "|\n";
	cout << "| " << left << setw(20) << "3、删除用户账号"
		<< "| " << setw(20) << "7、检索书籍" << "|\n";
	cout << "| " << left << setw(20) << "4、显示书本信息"
		<< "| " << setw(20) << "8、删除书本信息" << "|\n";
	cout << "| " << left << setw(20) << "0、退出系统"
		<< "| " << setw(20) << "  " << "|\n";

	cout << "+-----------------------------------------------+\n";
	cout << "|   请选择你要执行的操作（输入对应编号）：   |\n";
	cout << "+-----------------------------------------------+\n";
}


void menu_student() {
	cout << "+-----------------------------------------------+\n";
	cout << "|                  图书信息管理系统             |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|   1、查看书籍	      |  4、归还图书	     |\n";
	cout << "|   2、检索书籍	      |  0、退出系统	     |\n";
	cout << "|   3、借阅图书		  |					     |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|     请选择你要执行的操作（输入对应编号）：    |\n";
	cout << "+-----------------------------------------------+\n";
}
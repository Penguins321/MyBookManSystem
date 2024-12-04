#include<iostream>
#include"book.h"
#include"user.h"
#include"admin.h"
#include"student.h"
#include<iomanip>
#include<unordered_map>
using namespace std;
void menu_admin();
void menu_student();



int main() {

	/*
	封装好需要的类，实现其功能，最后组装
	book类的：同类型图书数量(一对多的关系)    属性的设计----> 学习使用观察者模式
	*/

	User user;
	User* userPtr = new User;
	Book book;
	Admin admin;
	Student stu;
	vector<User> vec_user;
	vector<Book> vec_book;
	vector<Book> vec_temp;									// 用于存放展示数据，用完清空
	Book::manager.readCount();								// 读取同类型书籍数量文件
	userPtr->fetchUser(vec_user);								// 读取用户文件			
	book.fetchBook(&vec_book);
	*userPtr = userPtr->login(vec_user, *userPtr);
	while (!userPtr->login_status) {
		cout << "用户名或密码错误，请重新输入：" << endl;
		*userPtr = userPtr->login(vec_user, *userPtr);
	}
	int choice;
	// 判断用户权限
	if (userPtr->role == 1) {		// 管理员
		do
		{
			menu_admin();
			// 重置choice 
			cin >> choice;
			while (cin.get() != '\n')
				continue;
			switch (choice) {
			case 1:
				userPtr->createUser(vec_user);
				break;
			case 2:
				userPtr->showUser(vec_user);
				break;
			case 3:
				userPtr->deleteUser(vec_user);
				break;
			case 4:
				admin.showBook(vec_book);
				break;
			case 5:
				book.modifyByIsbn(&vec_book);
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
	else if (userPtr->role == 2) {				// 学生
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
	userPtr->saveUser(vec_user);
	Book::manager.saveCount();
	delete userPtr;				// 释放动态分配的内存
	return 0;
}

void menu_admin() {
	cout << "+-----------------------------------------------+\n";
	cout << "|           图书信息管理系统                    |\n";
	cout << "+-----------------------------------------------+\n";

	// 让每一列对齐，使用 setw 来设置列宽
	cout << "| " << left << setw(22) << "1、注册用户账号"
		<< "| " << setw(22) << "5、修改图书信息" << "|\n";
	cout << "| " << left << setw(22) << "2、查看用户账号"
		<< "| " << setw(22) << "6、添加图书" << "|\n";
	cout << "| " << left << setw(22) << "3、删除用户账号"
		<< "| " << setw(22) << "7、检索书籍" << "|\n";
	cout << "| " << left << setw(22) << "4、显示书本信息"
		<< "| " << setw(22) << "8、删除书本信息" << "|\n";
	cout << "| " << left << setw(22) << "0、退出系统"
		<< "| " << setw(22) << "  " << "|\n";

	cout << "+-----------------------------------------------+\n";
	cout << "|   请选择你要执行的操作（输入对应编号）：      |\n";
	cout << "+-----------------------------------------------+\n";
}


void menu_student() {
	cout << "+-----------------------------------------------+\n";
	cout << "|               图书信息管理系统                |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|   1、查看书籍       |  4、归还图书            |\n";
	cout << "|   2、检索书籍       |  0、退出系统            |\n";
	cout << "|   3、借阅图书       |                         |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|     请选择你要执行的操作（输入对应编号）：    |\n";
	cout << "+-----------------------------------------------+\n";
}




/*
void func1();
void func2();
void func3();

void func1() {
	func2();
}

void func2() {
	func3();
}

void func3(){
	cout << "hello world" << endl;
}

int main() {

	func1();
	return 0;
}*/

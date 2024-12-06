#include<iostream>
#include"book.h"
#include"user.h"
#include"admin.h"
#include"student.h"
#include<iomanip>
#include"login.h"
#include "librarySystem.h"
using namespace std;
void menu_admin();
void menu_student();

// 程序主逻辑类

// 构造函数赋值
LibrarySystem::LibrarySystem() {
	userPtr = new User;
	bookPtr = new Book;
	adminPtr = new Admin;
	stuPtr = new Student;
	loginPtr = Login::getInstance();							// 获取实例，加载资源
	vec_user_ptr = new vector<User>;
	vec_book_ptr = new vector<Book>;
}

void LibrarySystem::run() {
	userPtr->fetchUser(vec_user_ptr);								// 读取用户文件			
	bookPtr->fetchBook(vec_book_ptr);

	// 登录
	*userPtr = loginPtr->login(vec_user_ptr, userPtr);
	while (!userPtr->login_status) {
		cout << "用户名或密码错误，请重新输入：" << endl;
		*userPtr = loginPtr->login(vec_user_ptr, userPtr);
	}
	// 判断用户权限
	if (userPtr->role == 1)						// 管理员
		runAdminMenu();
	else {
		runStudentMenu();
	}
}

// 析构函数释放指针
LibrarySystem::~LibrarySystem() {
	// 信息存储到文件
	bookPtr->saveBook(vec_book_ptr);
	userPtr->saveUser(vec_user_ptr);
	delete userPtr;				// 释放动态分配的内存
	delete bookPtr;
	delete adminPtr;
	delete stuPtr;
	delete loginPtr;
	delete vec_user_ptr;
	delete vec_book_ptr;
}

void LibrarySystem::runAdminMenu() {
	int choice;
	do
	{
		menu_admin();
		// 重置choice 
		cin >> choice;
		while (cin.get() != '\n')
			continue;
		switch (choice) {
		case 1:
			userPtr->createUser(vec_user_ptr);break;
		case 2:
			userPtr->showUser(vec_user_ptr);break;
		case 3:
			userPtr->deleteUser(vec_user_ptr);break;
		case 4:
			adminPtr->showBook(vec_book_ptr);break;
		case 5:
			bookPtr->modifyByIsbn(vec_book_ptr);break;
		case 6:
			adminPtr->appendBook(vec_book_ptr);break;
		case 7:
			adminPtr->findBook(vec_book_ptr, vec_temp);
			vec_temp.clear();
			break;
		case 8:
			adminPtr->deleteBook(vec_book_ptr);
		default:
			break;
		}
	} while (choice);

}

void LibrarySystem::runStudentMenu() {
	int choice;
	do {
		menu_student();
		cin >> choice;
		while (cin.get() != '\n')
			continue;
		switch (choice) {
		case 1:
			stuPtr->showBook(vec_book_ptr);break;
		case 2:
			stuPtr->findBook(vec_book_ptr, vec_temp);
			vec_temp.clear();
			break;
		case 3:
			stuPtr->borrowBook(vec_book_ptr);break;
		case 4:
			stuPtr->returnBook(vec_book_ptr);break;
		default:
			break;
		}
	} while (choice);
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

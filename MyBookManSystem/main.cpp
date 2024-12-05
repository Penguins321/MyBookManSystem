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

	User* userPtr = new User;
	Book* bookPtr = new Book;
	Admin* adminPtr = new Admin;
	Student* stuPtr = new Student;
	vector<User>* vec_user_ptr = new vector<User>;
	vector<Book>* vec_book_ptr = new vector<Book>;
	vector<Book> vec_book;
	vector<Book> vec_temp;											// 用于存放展示数据，用完清空
	// 获取单例实例
	BookManager* manager_ptr = BookManager::getInstance();			// 创建的指针整个程序运行期间有效，无需手动释放
	manager_ptr->readCount();										// 读取同类型书籍数量文件
	userPtr->fetchUser(vec_user_ptr);								// 读取用户文件			
	bookPtr->fetchBook(vec_book_ptr);
	*userPtr = userPtr->login(vec_user_ptr, userPtr);
	while (!userPtr->login_status) {
		cout << "用户名或密码错误，请重新输入：" << endl;
		*userPtr = userPtr->login(vec_user_ptr, userPtr);
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
				userPtr->createUser(vec_user_ptr);
				break;
			case 2:
				userPtr->showUser(vec_user_ptr);
				break;
			case 3:
				userPtr->deleteUser(vec_user_ptr);
				break;
			case 4:
				adminPtr->showBook(vec_book_ptr);
				break;
			case 5:
				bookPtr->modifyByIsbn(vec_book_ptr);
				break;
			case 6:
				adminPtr->appendBook(vec_book_ptr);
				break;
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
	else if (userPtr->role == 2) {				// 学生
		do {
			menu_student();
			cin >> choice;
			while (cin.get() != '\n')
				continue;
			switch (choice) {
			case 1:
				stuPtr->showBook(vec_book_ptr);
				break;
			case 2:
				stuPtr->findBook(vec_book_ptr, vec_temp);
				vec_temp.clear();
				break;
			case 3:
				stuPtr->borrowBook(vec_book_ptr);
				break;
			case 4:
				stuPtr->returnBook(vec_book_ptr);
				break;
			default:
				break;
			}
		} while (choice);
	}
	// 信息存储到文件
	bookPtr->saveBook(vec_book_ptr);
	userPtr->saveUser(vec_user_ptr);
	manager_ptr->saveCount();
	delete userPtr;				// 释放动态分配的内存
	delete bookPtr;
	delete adminPtr;
	delete stuPtr;
	delete vec_user_ptr;
	delete vec_book_ptr;
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

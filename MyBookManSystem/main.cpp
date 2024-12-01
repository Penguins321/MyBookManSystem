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
	��װ����Ҫ���࣬ʵ���书�ܣ������װ
	book��ģ�ͬ����ͼ������(һ�Զ�Ĺ�ϵ)    ���Ե����----> ѧϰʹ�ù۲���ģʽ
	ͬ�����鼮����δ���ļ�
	���ʱͬ�����鼮δ���ӣ��޸�ʱ��
	��ӣ�ɾ���鼮���߼������ж�ͬ���鼮�Ƿ����1      
	�����������ʱ���߼��ж�
	*/
	User user;
	Book book;
	Admin admin;
	Student stu;
	vector<User> vec_user;
	vector<Book> vec_book;
	vector<Book> vec_temp;									// ���ڴ��չʾ���ݣ��������
	user.fetchUser(vec_user);								// ��ȡ�û��ļ�			
	book.fetchBook(vec_book);
	user = user.login(vec_user, user);
	while (!user.login_status) {
		user = user.login(vec_user, user);
	}
	int choice;
	// �ж��û�Ȩ��
	if (user.role == 1) {		// ����Ա
		do
		{
			menu_admin();
			// ����choice 
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
	else if (user.role == 2) {				// ѧ��
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
	// ��Ϣ�洢���ļ�
	book.saveBook(vec_book);
	user.saveUser(vec_user);
	return 0;
}

void menu_admin() {
	cout << "+-----------------------------------------------+\n";
	cout << "|           ͼ����Ϣ����ϵͳ                   |\n";
	cout << "+-----------------------------------------------+\n";

	// ��ÿһ�ж��룬ʹ�� setw �������п�
	cout << "| " << left << setw(20) << "1��ע���û��˺�"
		<< "| " << setw(20) << "5���޸�ͼ����Ϣ" << "|\n";
	cout << "| " << left << setw(20) << "2���鿴�û��˺�"
		<< "| " << setw(20) << "6�����ͼ��" << "|\n";
	cout << "| " << left << setw(20) << "3��ɾ���û��˺�"
		<< "| " << setw(20) << "7�������鼮" << "|\n";
	cout << "| " << left << setw(20) << "4����ʾ�鱾��Ϣ"
		<< "| " << setw(20) << "8��ɾ���鱾��Ϣ" << "|\n";
	cout << "| " << left << setw(20) << "0���˳�ϵͳ"
		<< "| " << setw(20) << "  " << "|\n";

	cout << "+-----------------------------------------------+\n";
	cout << "|   ��ѡ����Ҫִ�еĲ����������Ӧ��ţ���   |\n";
	cout << "+-----------------------------------------------+\n";
}


void menu_student() {
	cout << "+-----------------------------------------------+\n";
	cout << "|                  ͼ����Ϣ����ϵͳ             |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|   1���鿴�鼮	      |  4���黹ͼ��	     |\n";
	cout << "|   2�������鼮	      |  0���˳�ϵͳ	     |\n";
	cout << "|   3������ͼ��		  |					     |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|     ��ѡ����Ҫִ�еĲ����������Ӧ��ţ���    |\n";
	cout << "+-----------------------------------------------+\n";
}
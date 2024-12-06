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

// �������߼���

// ���캯����ֵ
LibrarySystem::LibrarySystem() {
	userPtr = new User;
	bookPtr = new Book;
	adminPtr = new Admin;
	stuPtr = new Student;
	loginPtr = Login::getInstance();							// ��ȡʵ����������Դ
	vec_user_ptr = new vector<User>;
	vec_book_ptr = new vector<Book>;
}

void LibrarySystem::run() {
	userPtr->fetchUser(vec_user_ptr);								// ��ȡ�û��ļ�			
	bookPtr->fetchBook(vec_book_ptr);

	// ��¼
	*userPtr = loginPtr->login(vec_user_ptr, userPtr);
	while (!userPtr->login_status) {
		cout << "�û���������������������룺" << endl;
		*userPtr = loginPtr->login(vec_user_ptr, userPtr);
	}
	// �ж��û�Ȩ��
	if (userPtr->role == 1)						// ����Ա
		runAdminMenu();
	else {
		runStudentMenu();
	}
}

// ���������ͷ�ָ��
LibrarySystem::~LibrarySystem() {
	// ��Ϣ�洢���ļ�
	bookPtr->saveBook(vec_book_ptr);
	userPtr->saveUser(vec_user_ptr);
	delete userPtr;				// �ͷŶ�̬������ڴ�
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
		// ����choice 
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
	cout << "|           ͼ����Ϣ����ϵͳ                    |\n";
	cout << "+-----------------------------------------------+\n";

	// ��ÿһ�ж��룬ʹ�� setw �������п�
	cout << "| " << left << setw(22) << "1��ע���û��˺�"
		<< "| " << setw(22) << "5���޸�ͼ����Ϣ" << "|\n";
	cout << "| " << left << setw(22) << "2���鿴�û��˺�"
		<< "| " << setw(22) << "6�����ͼ��" << "|\n";
	cout << "| " << left << setw(22) << "3��ɾ���û��˺�"
		<< "| " << setw(22) << "7�������鼮" << "|\n";
	cout << "| " << left << setw(22) << "4����ʾ�鱾��Ϣ"
		<< "| " << setw(22) << "8��ɾ���鱾��Ϣ" << "|\n";
	cout << "| " << left << setw(22) << "0���˳�ϵͳ"
		<< "| " << setw(22) << "  " << "|\n";

	cout << "+-----------------------------------------------+\n";
	cout << "|   ��ѡ����Ҫִ�еĲ����������Ӧ��ţ���      |\n";
	cout << "+-----------------------------------------------+\n";
}

void menu_student() {
	cout << "+-----------------------------------------------+\n";
	cout << "|               ͼ����Ϣ����ϵͳ                |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|   1���鿴�鼮       |  4���黹ͼ��            |\n";
	cout << "|   2�������鼮       |  0���˳�ϵͳ            |\n";
	cout << "|   3������ͼ��       |                         |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|     ��ѡ����Ҫִ�еĲ����������Ӧ��ţ���    |\n";
	cout << "+-----------------------------------------------+\n";
}

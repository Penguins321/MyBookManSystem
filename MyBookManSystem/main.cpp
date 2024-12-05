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
	��װ����Ҫ���࣬ʵ���书�ܣ������װ
	book��ģ�ͬ����ͼ������(һ�Զ�Ĺ�ϵ)    ���Ե����----> ѧϰʹ�ù۲���ģʽ
	*/

	User* userPtr = new User;
	Book* bookPtr = new Book;
	Admin* adminPtr = new Admin;
	Student* stuPtr = new Student;
	vector<User>* vec_user_ptr = new vector<User>;
	vector<Book>* vec_book_ptr = new vector<Book>;
	vector<Book> vec_book;
	vector<Book> vec_temp;											// ���ڴ��չʾ���ݣ��������
	// ��ȡ����ʵ��
	BookManager* manager_ptr = BookManager::getInstance();			// ������ָ���������������ڼ���Ч�������ֶ��ͷ�
	manager_ptr->readCount();										// ��ȡͬ�����鼮�����ļ�
	userPtr->fetchUser(vec_user_ptr);								// ��ȡ�û��ļ�			
	bookPtr->fetchBook(vec_book_ptr);
	*userPtr = userPtr->login(vec_user_ptr, userPtr);
	while (!userPtr->login_status) {
		cout << "�û���������������������룺" << endl;
		*userPtr = userPtr->login(vec_user_ptr, userPtr);
	}
	int choice;
	// �ж��û�Ȩ��
	if (userPtr->role == 1) {		// ����Ա
		do
		{
			menu_admin();
			// ����choice 
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
	else if (userPtr->role == 2) {				// ѧ��
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
	// ��Ϣ�洢���ļ�
	bookPtr->saveBook(vec_book_ptr);
	userPtr->saveUser(vec_user_ptr);
	manager_ptr->saveCount();
	delete userPtr;				// �ͷŶ�̬������ڴ�
	delete bookPtr;
	delete adminPtr;
	delete stuPtr;
	delete vec_user_ptr;
	delete vec_book_ptr;
	return 0;
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

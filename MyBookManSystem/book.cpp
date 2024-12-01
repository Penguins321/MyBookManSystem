#include<iostream>
#include<fstream>
#include<iomanip>
#include"book.h"
#include"bookManager.h"
using namespace std;
// ���徲̬��Ա����
BookManager Book::manager;
void updateBookName(vector<Book>& vec);
void updateBookAuthor(vector<Book>& vec);
void updateMenu();
void updateBook();

// �޸�ͼ������
void Book::modifyByIsbn(vector<Book>& vec) {
	int choice;
	Book bo;
	cout << "��������Ҫ�Ĳ�����" << endl;
	updateMenu();
	cin >> choice;
	cin.ignore();
	switch (choice)
	{
	case 1:
		updateBookName(vec);
		bo.saveBook(vec);					// �޸ĺ����Ϣ�洢����
		break;
	case 2:
		updateBookAuthor(vec);
		bo.saveBook(vec);					// �޸ĺ����Ϣ�洢����
		break;
	case 3:
		updateBook();
		break;
	default:
		break;
	}
}

void updateMenu() {
	cout << "1:�޸��鼮����" << endl;
	cout << "2:�޸��鼮����" << endl;
	cout << "3:�޸��鼮����" << endl;
}

/*
1/�޸�vector������鼮����
2/�޸�unordered_map�����ͬ�����鼮����*/
void updateBookName(vector<Book>& vec) {
	string isbn;
	cout << "�������޸��鼮��ISBN��";
	getline(cin, isbn);
	for (auto it = vec.begin(); it != vec.end();++it) {
		if (isbn == it->isbn) {
			string name; 
			cout << "�������޸ĺ���鼮���ƣ�";
			getline(cin, name);
			Book::manager.removeBook(it->book_name);						// ԭ�����Ƶ��鼮������һ
			it->book_name = name;
			Book::manager.addBook(it->book_name);							// �����Ƶ��鼮������һ
		}
	}
}

// �޸��鼮����
void updateBookAuthor(vector<Book>& vec) {
	string isbn;
	cout << "�������޸��鼮��ISBN��";
	getline(cin, isbn);
	for (auto it = vec.begin(); it != vec.end();++it) {
		if (isbn == it->isbn) {
			string author;
			cout << "�������޸ĺ���������ƣ�";
			getline(cin, author);
			it->author = author;
		}
	}
}

// �޸�ͬ���鼮����
void updateBook() {
	string book_name;
	int count;
	cout << "�����޸��������鼮���ƣ�";
	getline(cin, book_name);
	cout << "�����޸ĺ���鼮������";
	cin >> count;
	Book::manager.updateCount(book_name, count);
}

// ��ȡͼ���ļ�
void Book::fetchBook(vector<Book>& vec) {
	fstream inFile;
	Book bo;
	inFile.open("book.txt",ios::in);
	while (inFile >> bo) {
		vec.push_back(bo);
	}
}
// ����ͼ���ļ�
void Book::saveBook(vector<Book>& vec) {
	fstream outFile;
	Book bo;
	outFile.open("book.txt", ios::out | ios::trunc);			// ���ԭ�ļ����ݲ����
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		bo.isbn = it->isbn;
		bo.book_name = it->book_name;
		bo.author = it->author;
		outFile << bo;
	}
}

// ���ͼ��
void Book::appendBook(vector<Book>& vec) {
	string isbn;
	string book_name;
	string author;
	cout << "������ͼ��ISBN�ţ�";
	getline(cin, isbn);
	cout << "������ͼ�����ƣ�";
	getline(cin, book_name);
	cout << "������ͼ�����ߣ�";
	getline(cin, author);
	Book bo(isbn, book_name, author);
	vec.push_back(bo);
	// ͬ�����鼮��һ
	Book::manager.addBook(book_name);
}

// ɾ��ͼ��
void Book::deleteBook(vector<Book>& vec) {
	string isbn;
	cout << "�������Ӧ��isbn�ţ�";
	getline(cin, isbn);
	for (auto it = vec.begin(); it != vec.end();) {
		if (it->isbn == isbn) {
			manager.removeBook(it->book_name);				// ͬ����ͼ��Ҳ��һ
			it = vec.erase(it);
		}
		else
			++it;
	}
}



// ����������������
istream& operator>>(istream& is, Book& bo) {
	getline(is, bo.isbn);
	getline(is, bo.book_name);
	getline(is, bo.author);
	return is;
}

ostream& operator<<(ostream& os, Book& bo) {
	os << bo.isbn << endl << bo.book_name << endl << bo.author << endl;
	return os;
}
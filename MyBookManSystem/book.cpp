#include<iostream>
#include<fstream>
#include<iomanip>
#include"book.h"
#include"bookManager.h"
using namespace std;
// ���徲̬��Ա����
BookManager Book::manager = BookManager();
void updateBookName(vector<Book>* vec);
void updateBookAuthor(vector<Book>* vec);
void updateMenu();
void updateBook();

// �޸�ͼ������
void Book::modifyByIsbn(vector<Book>* vec) {
	int* pchoice = new int;
	Book* pb = new Book;
	cout << "��������Ҫ�Ĳ�����" << endl;
	updateMenu();
	cin >> *pchoice;
	cin.ignore();
	switch (*pchoice)
	{
	case 1:
		updateBookName(vec);
		pb->saveBook(*vec);					// �޸ĺ����Ϣ�洢����
		break;
	case 2:
		updateBookAuthor(vec);
		pb->saveBook(*vec);					// �޸ĺ����Ϣ�洢����
		break;
	case 3:
		updateBook();
		break;
	default:
		break;
	}
	delete pb;
	delete pchoice;
}

void updateMenu() {
	cout << "1:�޸��鼮����" << endl;
	cout << "2:�޸��鼮����" << endl;
	cout << "3:�޸��鼮����" << endl;
}

/*
1/�޸�vector������鼮����
2/�޸�unordered_map�����ͬ�����鼮����*/
void updateBookName(vector<Book>* vec) {
	string* pisbn = new string;
	cout << "�������޸��鼮��ISBN��";
	getline(cin, *pisbn);
	for (auto it = vec->begin(); it != vec->end();++it) {
		if (*pisbn == it->isbn) {
			string name; 
			cout << "�������޸ĺ���鼮���ƣ�";
			getline(cin, name);
			Book::manager.removeBook(it->book_name);						// ԭ�����Ƶ��鼮������һ
			it->book_name = name;
			Book::manager.addBook(it->book_name);							// �����Ƶ��鼮������һ
		}
	}
	delete pisbn;
}

// �޸��鼮����
void updateBookAuthor(vector<Book>* vec) {
	string isbn;
	cout << "�������޸��鼮��ISBN��";
	getline(cin, isbn);
	for (auto it = vec->begin(); it != vec->end();++it) {
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
	int* pcount = new int;
	cout << "�����޸��������鼮���ƣ�";
	getline(cin, book_name);
	cout << "�����޸ĺ���鼮������";
	cin >> *pcount;
	Book::manager.updateCount(book_name, *pcount);
	delete pcount;
}

// ��ȡͼ���ļ�
void Book::fetchBook(vector<Book>* vec) {
	fstream inFile;
	Book* pb = new Book;
	inFile.open("book.txt",ios::in);
	while (inFile >> *pb) {
		vec->push_back(*pb);
	}
	delete pb;
}
// ����ͼ���ļ�
void Book::saveBook(vector<Book>& vec) {
	fstream outFile;
	Book* bookPtr = new Book;
	outFile.open("book.txt", ios::out | ios::trunc);			// ���ԭ�ļ����ݲ����
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		bookPtr->isbn = it->isbn;
		bookPtr->book_name = it->book_name;
		bookPtr->author = it->author;
		outFile << *bookPtr;
	}
	delete bookPtr;
}

// ���ͼ��
void Book::appendBook(vector<Book>& vec) {
	Book* pb = new Book;
	cout << "������ͼ��ISBN�ţ�";
	getline(cin, pb->isbn);
	cout << "������ͼ�����ƣ�";
	getline(cin, pb->book_name);
	cout << "������ͼ�����ߣ�";
	getline(cin, pb->author);
	int count = Book::manager.getCount(pb->book_name);
	// ���bookCount����ͬ�����鼮��������һ����ֻ����������vec���治�����
	if (count > 0) {
		Book::manager.addBook(pb->book_name);
	}
	else
	{
		vec.push_back(*pb);
		// ͬ�����鼮��һ
		Book::manager.addBook(pb->book_name);
	}
	delete pb;			// �ͷŶ�̬������ڴ�
}

// ɾ��ͼ��
void Book::deleteBook(vector<Book>* vec) {
	string isbn;
	cout << "�������Ӧ��isbn�ţ�";
	getline(cin, isbn);
	for (auto it = vec->begin(); it != vec->end();) {
		if (it->isbn == isbn) {
			int count = Book::manager.getCount(it->book_name);
			if (count > 0) {
				manager.removeBook(it->book_name);				// ͬ����ͼ���һ,vector�������ݲ��ټ���
				++it;
			}
			else {
				it = vec->erase(it);
				manager.removeBook(it->book_name);				// ͬ����ͼ��Ҳ��һ
			}
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
#include<iostream>
#include<fstream>
#include<iomanip>
#include"book.h"
#include"bookManager.h"
using namespace std;
// 定义静态成员变量
BookManager Book::manager;
void updateBookName(vector<Book>& vec);
void updateBookAuthor(vector<Book>& vec);
void updateMenu();
void updateBook();

// 修改图书属性
void Book::modifyByIsbn(vector<Book>& vec) {
	int choice;
	Book bo;
	cout << "请输入想要的操作：" << endl;
	updateMenu();
	cin >> choice;
	cin.ignore();
	switch (choice)
	{
	case 1:
		updateBookName(vec);
		bo.saveBook(vec);					// 修改后的信息存储起来
		break;
	case 2:
		updateBookAuthor(vec);
		bo.saveBook(vec);					// 修改后的信息存储起来
		break;
	case 3:
		updateBook();
		break;
	default:
		break;
	}
}

void updateMenu() {
	cout << "1:修改书籍名称" << endl;
	cout << "2:修改书籍作者" << endl;
	cout << "3:修改书籍数量" << endl;
}

/*
1/修改vector里面的书籍名称
2/修改unordered_map里面的同名称书籍数量*/
void updateBookName(vector<Book>& vec) {
	string isbn;
	cout << "请输入修改书籍的ISBN：";
	getline(cin, isbn);
	for (auto it = vec.begin(); it != vec.end();++it) {
		if (isbn == it->isbn) {
			string name; 
			cout << "请输入修改后的书籍名称：";
			getline(cin, name);
			Book::manager.removeBook(it->book_name);						// 原来名称的书籍数量减一
			it->book_name = name;
			Book::manager.addBook(it->book_name);							// 新名称的书籍数量加一
		}
	}
}

// 修改书籍作者
void updateBookAuthor(vector<Book>& vec) {
	string isbn;
	cout << "请输入修改书籍的ISBN：";
	getline(cin, isbn);
	for (auto it = vec.begin(); it != vec.end();++it) {
		if (isbn == it->isbn) {
			string author;
			cout << "请输入修改后的作者名称：";
			getline(cin, author);
			it->author = author;
		}
	}
}

// 修改同名书籍数量
void updateBook() {
	string book_name;
	int count;
	cout << "输入修改数量的书籍名称：";
	getline(cin, book_name);
	cout << "输入修改后的书籍数量：";
	cin >> count;
	Book::manager.updateCount(book_name, count);
}

// 读取图书文件
void Book::fetchBook(vector<Book>& vec) {
	fstream inFile;
	Book bo;
	inFile.open("book.txt",ios::in);
	while (inFile >> bo) {
		vec.push_back(bo);
	}
}
// 保存图书文件
void Book::saveBook(vector<Book>& vec) {
	fstream outFile;
	Book bo;
	outFile.open("book.txt", ios::out | ios::trunc);			// 清空原文件内容并添加
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		bo.isbn = it->isbn;
		bo.book_name = it->book_name;
		bo.author = it->author;
		outFile << bo;
	}
}

// 添加图书
void Book::appendBook(vector<Book>& vec) {
	string isbn;
	string book_name;
	string author;
	cout << "请输入图书ISBN号：";
	getline(cin, isbn);
	cout << "请输入图书名称：";
	getline(cin, book_name);
	cout << "请输入图书作者：";
	getline(cin, author);
	Book bo(isbn, book_name, author);
	vec.push_back(bo);
	// 同类型书籍加一
	Book::manager.addBook(book_name);
}

// 删除图书
void Book::deleteBook(vector<Book>& vec) {
	string isbn;
	cout << "请输入对应的isbn号：";
	getline(cin, isbn);
	for (auto it = vec.begin(); it != vec.end();) {
		if (it->isbn == isbn) {
			manager.removeBook(it->book_name);				// 同类型图书也减一
			it = vec.erase(it);
		}
		else
			++it;
	}
}



// 重载输入输出运算符
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
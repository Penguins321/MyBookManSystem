#include<iostream>
#include<fstream>
#include<iomanip>
#include"book.h"
#include"bookManager.h"
using namespace std;
// 定义静态成员变量
BookManager Book::manager = BookManager();
void updateBookName(vector<Book>* vec);
void updateBookAuthor(vector<Book>* vec);
void updateMenu();
void updateBook();

// 修改图书属性
void Book::modifyByIsbn(vector<Book>* vec) {
	int* pchoice = new int;
	Book* pb = new Book;
	cout << "请输入想要的操作：" << endl;
	updateMenu();
	cin >> *pchoice;
	cin.ignore();
	switch (*pchoice)
	{
	case 1:
		updateBookName(vec);
		pb->saveBook(*vec);					// 修改后的信息存储起来
		break;
	case 2:
		updateBookAuthor(vec);
		pb->saveBook(*vec);					// 修改后的信息存储起来
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
	cout << "1:修改书籍名称" << endl;
	cout << "2:修改书籍作者" << endl;
	cout << "3:修改书籍数量" << endl;
}

/*
1/修改vector里面的书籍名称
2/修改unordered_map里面的同名称书籍数量*/
void updateBookName(vector<Book>* vec) {
	string* pisbn = new string;
	cout << "请输入修改书籍的ISBN：";
	getline(cin, *pisbn);
	for (auto it = vec->begin(); it != vec->end();++it) {
		if (*pisbn == it->isbn) {
			string name; 
			cout << "请输入修改后的书籍名称：";
			getline(cin, name);
			Book::manager.removeBook(it->book_name);						// 原来名称的书籍数量减一
			it->book_name = name;
			Book::manager.addBook(it->book_name);							// 新名称的书籍数量加一
		}
	}
	delete pisbn;
}

// 修改书籍作者
void updateBookAuthor(vector<Book>* vec) {
	string isbn;
	cout << "请输入修改书籍的ISBN：";
	getline(cin, isbn);
	for (auto it = vec->begin(); it != vec->end();++it) {
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
	int* pcount = new int;
	cout << "输入修改数量的书籍名称：";
	getline(cin, book_name);
	cout << "输入修改后的书籍数量：";
	cin >> *pcount;
	Book::manager.updateCount(book_name, *pcount);
	delete pcount;
}

// 读取图书文件
void Book::fetchBook(vector<Book>* vec) {
	fstream inFile;
	Book* pb = new Book;
	inFile.open("book.txt",ios::in);
	while (inFile >> *pb) {
		vec->push_back(*pb);
	}
	delete pb;
}
// 保存图书文件
void Book::saveBook(vector<Book>& vec) {
	fstream outFile;
	Book* bookPtr = new Book;
	outFile.open("book.txt", ios::out | ios::trunc);			// 清空原文件内容并添加
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		bookPtr->isbn = it->isbn;
		bookPtr->book_name = it->book_name;
		bookPtr->author = it->author;
		outFile << *bookPtr;
	}
	delete bookPtr;
}

// 添加图书
void Book::appendBook(vector<Book>& vec) {
	Book* pb = new Book;
	cout << "请输入图书ISBN号：";
	getline(cin, pb->isbn);
	cout << "请输入图书名称：";
	getline(cin, pb->book_name);
	cout << "请输入图书作者：";
	getline(cin, pb->author);
	int count = Book::manager.getCount(pb->book_name);
	// 如果bookCount里面同名称书籍数量大于一，则只增加数量，vec里面不再添加
	if (count > 0) {
		Book::manager.addBook(pb->book_name);
	}
	else
	{
		vec.push_back(*pb);
		// 同类型书籍加一
		Book::manager.addBook(pb->book_name);
	}
	delete pb;			// 释放动态分配的内存
}

// 删除图书
void Book::deleteBook(vector<Book>* vec) {
	string isbn;
	cout << "请输入对应的isbn号：";
	getline(cin, isbn);
	for (auto it = vec->begin(); it != vec->end();) {
		if (it->isbn == isbn) {
			int count = Book::manager.getCount(it->book_name);
			if (count > 0) {
				manager.removeBook(it->book_name);				// 同类型图书减一,vector数据内容不再减少
				++it;
			}
			else {
				it = vec->erase(it);
				manager.removeBook(it->book_name);				// 同类型图书也减一
			}
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
#include<iostream>
#include<string>
#include"student.h"
#include"book.h"
using namespace std;

// 借阅图书
void Student::borrowBook(vector<Book>& vec) {
	showBook(vec);
	Book bo;
	bo.deleteBook(vec);
	cout << "书籍借阅成功" << endl;
}

// 归还图书
void Student::returnBook(vector<Book>& vec) {
	cout << "请输入归还书籍的相关信息" << endl;
	Book bo;
	bo.appendBook(vec);
}
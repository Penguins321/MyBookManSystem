#include<iostream>
#include<string>
#include"student.h"
#include"book.h"
using namespace std;

// 借阅图书
void Student::borrowBook(vector<Book>* vec) {
	showBook(vec);
	Book bo;
	Book* pb = &bo;
	pb->deleteBook(vec);
	cout << "书籍借阅成功" << endl;
	delete pb;
}

// 归还图书
void Student::returnBook(vector<Book>* vec) {
	cout << "请输入归还书籍的相关信息" << endl;
	Book bo;
	Book* pb = &bo;
	pb->appendBook(vec);
	delete pb;
}
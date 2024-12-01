#pragma once
#ifndef __BOOK__
#define __BOOK__
#include<string>
#include<vector>
//#include"user.h" 为何包括user.h会多处报错？
#include"bookManager.h"
using namespace std;

// 书籍类   todo:公有属性private，其他类如何访问
class Book {

public:
	string isbn;		     // 图书编号
	string book_name;	     // 图书名称
	string author;		     // 图书作者
	static BookManager manager;		// 同类型图书数量(按照书籍名称确定)->委托管理

	Book(){}
	Book(const string& isbn, const string& book_name, const string& author) :isbn(isbn), book_name(book_name), author(author) {
		manager.addBook(book_name);
	}
	virtual ~Book() {
		manager.removeBook(book_name);
	}
	void modifyByIsbn(vector<Book>& vec);								// 修改图书属性
	void fetchBook(vector<Book>& vec);									// 读取图书文件
	void saveBook(vector<Book>& vec);									// 保存图书文件
	void appendBook(vector<Book>& vec);									// 添加图书
	void deleteBook(vector<Book>& vec);									// 按isbn号删除图书

	// 友元重载输入输出运算符
	friend istream& operator>>(istream& is, Book& bo);
	friend ostream& operator<<(ostream& os, Book& bo);
 
};

#endif // !__BOOK__

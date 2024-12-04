#include"admin.h"
#include"book.h"
#include<fstream>
#include"user.h"
#include<iomanip>
using namespace std;

// 删除图书
void Admin::deleteBook(vector<Book>& vec) {
	showBook(vec);
	Book* pb = new Book;
	pb->deleteBook(&vec);
	cout << "书籍删除成功" << endl;
	delete pb;
}

// 添加图书
void Admin::appendBook(vector<Book>& vec)    {
	cout << "请输入添加书籍的相关信息";
	Book* pb = new Book;
	pb->appendBook(vec);
	pb->saveBook(vec);		// 固化到文件
	delete pb;
}

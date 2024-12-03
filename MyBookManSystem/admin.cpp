#include"admin.h"
#include"book.h"
#include<fstream>
#include"user.h"
#include<iomanip>
using namespace std;

// 删除图书
void Admin::deleteBook(vector<Book>& vec) {
	showBook(vec);
	Book bo;
	bo.deleteBook(vec);
	cout << "书籍删除成功" << endl;
}

// 添加图书
void Admin::appendBook(vector<Book>& vec) {
	cout << "请输入添加书籍的相关信息";
	Book bo;
	bo.appendBook(vec);
	bo.saveBook(vec);		// 固化到文件
}

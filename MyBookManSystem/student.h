#pragma once
#ifndef __STUDENT__
#define __STUDENT__
#include<vector>
#include<string>
#include"user.h"
using namespace std;

// 学生类继承自user
class Student :public User {

public:

	void borrowBook(vector<Book>& vec);						// 借阅图书
	void returnBook(vector<Book>& vec);						// 归还图书
};

#endif // !__STUDENT__

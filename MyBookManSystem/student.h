#pragma once
#ifndef __STUDENT__
#define __STUDENT__
#include<vector>
#include<string>
#include"user.h"
using namespace std;

// ѧ����̳���user
class Student :public User {

public:

	void borrowBook(vector<Book>& vec);						// ����ͼ��
	void returnBook(vector<Book>& vec);						// �黹ͼ��
};

#endif // !__STUDENT__

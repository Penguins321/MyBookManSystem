#pragma once
#ifndef __ADMIN__
#define __ADMIN__
#include"user.h"
#include<iostream>

class Admin :public User {

public:

	void deleteBook(vector<Book>& vec);						// ɾ��ͼ��
	void appendBook(vector<Book>& vec);						// ���ͼ��
};
#endif // !__ADMIN__

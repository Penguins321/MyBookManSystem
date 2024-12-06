#pragma once
#ifndef __LIBRARYSYSTEM__
#define __LIBRARYSYSTEM__
#include<iostream>
#include"book.h"
#include"user.h"
#include"admin.h"
#include"student.h"
#include"login.h"
using namespace std;

class LibrarySystem {
private:
	User* userPtr;
	Book* bookPtr;
	Admin* adminPtr;
	Student* stuPtr;
	Login* loginPtr;
	vector<User>* vec_user_ptr;
	vector<Book>* vec_book_ptr;
	vector<Book> vec_book;
	vector<Book> vec_temp;											// 用于存放展示数据，用完清空
public:
	LibrarySystem();
	~LibrarySystem();

	void run();
	void runAdminMenu();
	void runStudentMenu();
};
#endif // !__LIBRARYSYSTEM__

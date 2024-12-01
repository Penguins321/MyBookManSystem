#pragma once
#ifndef __BOOK__
#define __BOOK__
#include<string>
#include<vector>
//#include"user.h" Ϊ�ΰ���user.h��ദ����
#include"bookManager.h"
using namespace std;

// �鼮��   todo:��������private����������η���
class Book {

public:
	string isbn;		     // ͼ����
	string book_name;	     // ͼ������
	string author;		     // ͼ������
	static BookManager manager;		// ͬ����ͼ������(�����鼮����ȷ��)->ί�й���

	Book(){}
	Book(const string& isbn, const string& book_name, const string& author) :isbn(isbn), book_name(book_name), author(author) {
		manager.addBook(book_name);
	}
	virtual ~Book() {
		manager.removeBook(book_name);
	}
	void modifyByIsbn(vector<Book>& vec);								// �޸�ͼ������
	void fetchBook(vector<Book>& vec);									// ��ȡͼ���ļ�
	void saveBook(vector<Book>& vec);									// ����ͼ���ļ�
	void appendBook(vector<Book>& vec);									// ���ͼ��
	void deleteBook(vector<Book>& vec);									// ��isbn��ɾ��ͼ��

	// ��Ԫ����������������
	friend istream& operator>>(istream& is, Book& bo);
	friend ostream& operator<<(ostream& os, Book& bo);
 
};

#endif // !__BOOK__

#include<iostream>
#include<string>
#include"student.h"
#include"book.h"
using namespace std;

// ����ͼ��
void Student::borrowBook(vector<Book>* vec) {
	showBook(vec);
	Book bo;
	Book* pb = &bo;
	pb->deleteBook(vec);
	cout << "�鼮���ĳɹ�" << endl;
	delete pb;
}

// �黹ͼ��
void Student::returnBook(vector<Book>* vec) {
	cout << "������黹�鼮�������Ϣ" << endl;
	Book bo;
	Book* pb = &bo;
	pb->appendBook(vec);
	delete pb;
}
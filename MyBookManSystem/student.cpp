#include<iostream>
#include<string>
#include"student.h"
#include"book.h"
using namespace std;

// ����ͼ��
void Student::borrowBook(vector<Book>& vec) {
	showBook(vec);
	Book bo;
	bo.deleteBook(vec);
	cout << "�鼮���ĳɹ�" << endl;
}

// �黹ͼ��
void Student::returnBook(vector<Book>& vec) {
	cout << "������黹�鼮�������Ϣ" << endl;
	Book bo;
	bo.appendBook(vec);
}
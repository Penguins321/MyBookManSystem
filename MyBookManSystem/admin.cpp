#include"admin.h"
#include"book.h"
#include<fstream>
#include"user.h"
#include<iomanip>
using namespace std;

// ɾ��ͼ��
void Admin::deleteBook(vector<Book>& vec) {
	showBook(vec);
	Book* pb = new Book;
	pb->deleteBook(&vec);
	cout << "�鼮ɾ���ɹ�" << endl;
	delete pb;
}

// ���ͼ��
void Admin::appendBook(vector<Book>& vec)    {
	cout << "����������鼮�������Ϣ";
	Book* pb = new Book;
	pb->appendBook(vec);
	pb->saveBook(vec);		// �̻����ļ�
	delete pb;
}

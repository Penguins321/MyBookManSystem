#include"admin.h"
#include"book.h"
#include<fstream>
#include"user.h"
#include<iomanip>
using namespace std;

// ɾ��ͼ��
void Admin::deleteBook(vector<Book>& vec) {
	showBook(vec);
	Book bo;
	bo.deleteBook(vec);
	cout << "�鼮ɾ���ɹ�" << endl;
}

// ���ͼ��
void Admin::appendBook(vector<Book>& vec) {
	cout << "����������鼮�������Ϣ";
	Book bo;
	bo.appendBook(vec);
	bo.saveBook(vec);		// �̻����ļ�
}

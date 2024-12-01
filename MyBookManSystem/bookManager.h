#pragma once
#ifndef __BOOKMANAGER__
#define __BOOKMANAGER__
#include<unordered_map>
#include<string>	
using namespace std;

// ͬ�����鼮����  ������
class BookManager {
private:
	unordered_map <string, int> bookCount;
public:
	void addBook(const string& name);                   // ����鼮
	void removeBook(const string& name);				// �Ƴ��鼮
	int getCount(const string& name) const;				// ��ȡͬ��������
	int getTotalCount() const;							// ��ȡͼ��������
	void updateCount(const string& name, int n);		// �޸�����
};
#endif // !__BOOKMANAGER__

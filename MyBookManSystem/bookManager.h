#pragma once
#ifndef __BOOKMANAGER__
#define __BOOKMANAGER__
#include<unordered_map>
#include<string>	
#include<iostream>
#include<mutex>				// ������
using namespace std;

// ͬ�����鼮����  ������
// ˫��������ģʽ

class BookManager {
private:
	 unordered_map <string, int> bookCount;
	 BookManager() = default;					// ˽�й��캯��
	 static BookManager* instance;				// ����ʵ��
	 static mutex mtx;							// ���ڼ����Ļ�����

	 // ���ø��ƹ��캯���Լ����ظ�ֵ�����
	 BookManager(const BookManager&) = delete;
	 BookManager& operator=(const BookManager&) = delete;
public:
	// ȫ�ַ��ʵ�
	static BookManager* getInstance();

	void addBook(const string& name);                   // ����鼮
	void removeBook(const string& name);				// �Ƴ��鼮
	int getCount(const string& name) const;				// ��ȡͬ��������
	int getTotalCount() const;							// ��ȡͼ��������
	void updateCount(const string& name, int n);		// �޸�����

	void readCount();									// ���ļ���ȡ
	void saveCount();									// ���浽�ļ�

	
};
#endif // !__BOOKMANAGER__

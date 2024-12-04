#pragma once
#ifndef __USER__
#define __USER__
#include<vector>
#include<iostream>
#include<string>
using namespace std;

// Book��      ǰ������
class Book;

// �û�����
class User {	
	// �������޷�����User˽�г�Ա����Ҫ��д��������
public:
	string name;					// �û���
	string password;				// ����
	int role;						// ��ɫ������Ա��1�� ѧ����2�� δ���䣨0��
	bool login_status;				// ��¼�Ƿ�ɹ�   �ɹ���true�� δ��¼��false��
public:
	User():role(0),login_status(false) {}
	User(const string& name, const string& password):name(name), password(password), role(0),login_status(false) {}
	virtual ~User() = default;

	void showBook(vector<Book>& vec) const;								// ��ʾ�鼮��Ϣ 
	void findBook(vector<Book>& vec1,vector<Book>& vec2);				// �����Լ���ͼ��
	User& login(vector<User>& vec,User& user);												// ��¼ ��Ӧ�÷��ڻ���ƽ̨��

	// ���·���ԭ������admin.cpp
	void createUser(vector<User>& vec);						// �����û�
	void showUser(vector<User>& vec);						// �鿴�û�
	void fetchUser(vector<User>& vec);						// ��ȡ�û��ļ�
	void saveUser(vector<User>& vec);						// �����û���Ϣ�ļ�
	void deleteUser(vector<User>& vec);						// ɾ���û�

	// ��Ԫ����������������
	friend istream& operator>>(istream& is, User& user);
	friend ostream& operator<<(ostream& os, const User& user);

};

#endif // !__USER__

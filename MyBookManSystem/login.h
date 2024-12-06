#pragma once
#ifndef __LOGIN__
#define __LOGIN__
#include<vector>
#include<mutex>
using namespace std;
class User;

// ����ģʽ��¼�� ����һ�Σ����캯�������Զ�������Դ
class Login {
private:
	Login();						// ˽�й��캯��
	static Login* instance;			// Ψһʵ��
	static mutex mtx;				// ������
public:
	static Login* getInstance();
	User& login(vector<User>* vec, User* user);												// ��¼ 
	virtual ~Login();
};

#endif
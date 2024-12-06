#include<iostream>
#include"login.h"
#include<string>
#include<vector>
#include"user.h"
#include<mutex>
#include"bookManager.h"
using namespace std;
Login* Login::instance;
mutex Login::mtx;

// ����ģʽ��¼�� ����һ�Σ����캯�������Զ�������Դ
Login::Login() {
	// ��ȡ����ʵ��
	BookManager* manager_ptr = BookManager::getInstance();			// ������ָ���������������ڼ���Ч�������ֶ��ͷ�
	manager_ptr->readCount();										// ��ȡͬ�����鼮�����ļ�
}


Login* Login::getInstance() {
	if (instance == nullptr) {
		lock_guard<mutex> lock(mtx);
		if (instance == nullptr) {
			instance = new Login();
		}
	}
	return instance;
}

// �û���¼           
// idea 1������student, admin, ��������Ӳ������Ƿ��¼���������ֵ�¼����ѧ�����ǹ���Ա
// idea 2�����ݳ����ŵ�user�ࡣstudent���admin��ֻ�����з���
User& Login::login(vector<User>* vec, User* user) {
	bool flag = false;
	cout << "�������û�����";
	getline(cin, user->name);
	// ������֤�Ƿ�����û���
	for (auto it = vec->begin(); it != vec->end(); ++it) {
		if (it->name == user->name) {
			// ��֤����
			cout << "���������룺";
			getline(cin, user->password);
			if (it->password == user->password) {
				user->role = it->role;
				user->login_status = true;
				cout << "��¼�ɹ���" << endl;
				return *user;
			}
		}
	}
	return *user;
}

Login::~Login() {					// ���������Զ�������Դ
	BookManager* manager_ptr = BookManager::getInstance();			
	manager_ptr->saveCount();
}
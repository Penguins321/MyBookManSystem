#pragma once
#ifndef __LOGIN__
#define __LOGIN__
#include<vector>
#include<mutex>
using namespace std;
class User;

// 单例模式登录， 调用一次，构造函数里面自动加载资源
class Login {
private:
	Login();						// 私有构造函数
	static Login* instance;			// 唯一实例
	static mutex mtx;				// 互斥量
public:
	static Login* getInstance();
	User& login(vector<User>* vec, User* user);												// 登录 
	virtual ~Login();
};

#endif
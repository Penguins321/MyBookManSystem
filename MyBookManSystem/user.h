#pragma once
#ifndef __USER__
#define __USER__
#include<vector>
#include<iostream>
#include<string>
using namespace std;

// Book类      前向声明
class Book;

// 用户基类
class User {	
	// 迭代器无法访问User私有成员，需要重写迭代器？
public:
	string name;					// 用户名
	string password;				// 密码
	int role;						// 角色：管理员（1） 学生（2） 未分配（0）
	bool login_status;				// 登录是否成功   成功（true） 未登录（false）
public:
	User():role(0),login_status(false) {}
	User(const string& name, const string& password):name(name), password(password), role(0),login_status(false) {}
	virtual ~User() = default;

	void showBook(vector<Book>& vec) const;								// 显示书籍信息 
	void findBook(vector<Book>& vec1,vector<Book>& vec2);				// 按属性检索图书
	User& login(vector<User>& vec,User& user);												// 登录 （应该放在基础平台）

	// 以下方法原本放在admin.cpp
	void createUser(vector<User>& vec);						// 创建用户
	void showUser(vector<User>& vec);						// 查看用户
	void fetchUser(vector<User>& vec);						// 读取用户文件
	void saveUser(vector<User>& vec);						// 保存用户信息文件
	void deleteUser(vector<User>& vec);						// 删除用户

	// 友元重载输入输出运算符
	friend istream& operator>>(istream& is, User& user);
	friend ostream& operator<<(ostream& os, const User& user);

};

#endif // !__USER__

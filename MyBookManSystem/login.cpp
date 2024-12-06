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

// 单例模式登录， 调用一次，构造函数里面自动加载资源
Login::Login() {
	// 获取单例实例
	BookManager* manager_ptr = BookManager::getInstance();			// 创建的指针整个程序运行期间有效，无需手动释放
	manager_ptr->readCount();										// 读取同类型书籍数量文件
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

// 用户登录           
// idea 1：传入student, admin, 两个类添加参数：是否登录，用于区分登录的是学生还是管理员
// idea 2：数据抽出存放到user类。student类和admin类只有特有方法
User& Login::login(vector<User>* vec, User* user) {
	bool flag = false;
	cout << "请输入用户名：";
	getline(cin, user->name);
	// 遍历验证是否存在用户名
	for (auto it = vec->begin(); it != vec->end(); ++it) {
		if (it->name == user->name) {
			// 验证密码
			cout << "请输入密码：";
			getline(cin, user->password);
			if (it->password == user->password) {
				user->role = it->role;
				user->login_status = true;
				cout << "登录成功！" << endl;
				return *user;
			}
		}
	}
	return *user;
}

Login::~Login() {					// 析构函数自动保存资源
	BookManager* manager_ptr = BookManager::getInstance();			
	manager_ptr->saveCount();
}
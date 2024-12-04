#include<iostream>
#include"user.h"
#include"book.h"
#include<iomanip>
#include<fstream>
using namespace std;
void findByIsbn(vector<Book>* vec1, vector<Book>& vec2);
void findByBookName(vector<Book>* vec1, vector<Book>& vec2);
void findByAuthor(vector<Book>* vec1, vector<Book>& vec2);
void signUp(vector<User>* vec, User& user);


// 显示书籍信息
void User::showBook(vector<Book>* vec) const {
	cout << left << setw(20) << "isbn图书编号" << left << setw(20) << "图书名称"
		<< left << setw(20) << "图书作者" << left << setw(20) << "同名称书籍数量" << endl;
	cout << string(50, '-') << endl;
	int count = 0;
	for (auto it = vec->begin(); it != vec->end(); ++it) {
		count = Book::manager.getCount(it->book_name);
		cout << left << setw(20) << it->isbn << left << setw(20) << it->book_name
			<< left << setw(20) << it->author << left << setw(20) << count << endl;
	}
}

// 按属性检索书籍
/*
isbn、书名、图书作者
vec1为数据传入*/
void User::findBook(vector<Book>* vec1, vector<Book>& vec2) {
	int choice;
	cout << "请输入搜索类型： 1:按ISBN   2：按图书名称   3：按作者" << endl;
	cin >> choice;
	cin.ignore();
	switch (choice) {
	case 1:
		findByIsbn(vec1, vec2);
		break;
	case 2:
		findByBookName(vec1, vec2);
		break;
	case 3:
		findByAuthor(vec1, vec2);
		break;
	default:
		cout << "请输入正确的数字" << endl;
		break;
	}
}

// 按ISBN搜索
void findByIsbn(vector<Book>* vec1, vector<Book>& vec2) {
	string isbn;
	User user;
	cout << "请输入图书ISBN号：";
	getline(cin, isbn);
	Book bo;
	for (auto it = vec1->begin(); it != vec1->end();++it) {
		if (it->isbn == isbn) {
			bo.isbn = it->isbn;
			bo.book_name = it->book_name;
			bo.author = it->author;
			vec2.push_back(bo);
		}
	}
	user.showBook(&vec2);
}

// 按图书名称搜索
void findByBookName(vector<Book>* vec1, vector<Book>& vec2) {
	string book_name;
	User user;
	cout << "请输入你将要搜索的图书名称：";
	getline(cin, book_name);
	Book bo;
	for (auto it = vec1->begin(); it != vec1->end();++it) {
		if (it->book_name == book_name) {
			bo.isbn = it->isbn;
			bo.book_name = it->book_name;
			bo.author = it->author;
			vec2.push_back(bo);
		}
	}
	user.showBook(&vec2);
}

// 按作者名称搜索
void findByAuthor(vector<Book>* vec1, vector<Book>& vec2) {
	string author;
	User user;
	cout << "请输入你将要搜索的作者：";
	getline(cin, author);
	Book bo;
	for (auto it = vec1->begin(); it != vec1->end();++it) {
		if (it->author == author) {
			bo.isbn = it->isbn;
			bo.book_name = it->book_name;
			bo.author = it->author;
			vec2.push_back(bo);
		}
	}
	user.showBook(&vec2);
}

// 用户登录           
// idea 1：传入student, admin, 两个类添加参数：是否登录，用于区分登录的是学生还是管理员
// idea 2：数据抽出存放到user类。student类和admin类只有特有方法
User& User::login(vector<User>* vec,User* user) {
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


// 创建用户
void User::createUser(vector<User>* vec) {
	int choice;
	string userName;
	User user;
	cout << "请输入要创建的角色： 管理员（1）  学生（2）";
	cin >> choice;
	while (cin.get() != '\n')
		continue;
	cout << "请输入注册用户名：" << endl;
	getline(cin, userName);
	switch (choice) {
	case 1:
		user.name = userName;
		user.role = choice;
		signUp(vec, user);							// 注册逻辑
		break;
	case 2:
		user.name = userName;
		user.role = choice;
		signUp(vec, user);
		break;
	default:
		break;
	}
	cout << "注册成功！" << endl;

}

// 读取文件
void User::fetchUser(vector<User>* vec) {
	fstream inFile;
	User user;
	inFile.open("user.txt",ios::in);
	if (!inFile) {
		cout << "文件读取失败" << endl;
		return;
	}
	while (inFile >> user){
		vec->push_back(user);
	}
	inFile.close();
}

// 保存到文件
void User::saveUser(vector<User>* vec) {
	fstream outFile;
	User* userPtr = new User;
	outFile.open("user.txt", ios::out | ios::trunc);
	for (auto it = vec->begin(); it != vec->end(); ++it) {
		userPtr->name = it->name;
		userPtr->password = it->password;
		userPtr->role = it->role;
		outFile << *userPtr;
	}
	outFile.close();
}

// 注册逻辑
void signUp(vector<User>* vec, User& user) {
	for (auto it = vec->begin(); it != vec->end();++it) {
		if (it->name == user.name) {
			cout << "用户名重复，请重试：" << endl;
			user.createUser(vec);
		}
	}
	cout << "请输入注册密码：";
	getline(cin, user.password);
	vec->push_back(user);
}

// 展示用户
void User::showUser(vector<User>* vec) {
	string roleName;
	cout << left << setw(20) << "用户名" << left << setw(20) << "密码" << left << setw(20) << "角色" << endl;
	cout << string(50, '-') << endl;
	for (User u : *vec) {
		u.role == 1 ? roleName = "管理员" : roleName = "学生";
		cout << left << setw(20) << u.name << left << setw(20) << u.password << left << setw(20) << roleName << endl;
	}
}

// 删除用户
void User::deleteUser(vector<User>* vec) {
	string userName;
	cout << "请输入将要删除的用户名：" << endl;
	getline(cin, userName);
	for (auto it = vec->begin(); it != vec->end();) {
		if (it->name == userName) {
			it = vec->erase(it);
		}
		else
			++it;
	}
}



// 友元重载输入输出运算符
istream& operator>>(istream& is, User& user) {
	getline(is, user.name);
	getline(is, user.password);
	is >> user.role;
	is.ignore();			 // 忽略前一个输入后的换行符
	return is;
}
ostream& operator<<(ostream& os, const User& user) {
	os << user.name << endl
		<< user.password << endl
		<< user.role << endl;
	return os;
}

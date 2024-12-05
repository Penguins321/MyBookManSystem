#pragma once
#ifndef __BOOKMANAGER__
#define __BOOKMANAGER__
#include<unordered_map>
#include<string>	
#include<iostream>
#include<mutex>				// 互斥锁
using namespace std;

// 同名称书籍数量  管理器
// 双检锁单例模式

class BookManager {
private:
	 unordered_map <string, int> bookCount;
	 BookManager() = default;					// 私有构造函数
	 static BookManager* instance;				// 单例实例
	 static mutex mtx;							// 用于加锁的互斥量

	 // 禁用复制构造函数以及重载赋值运算符
	 BookManager(const BookManager&) = delete;
	 BookManager& operator=(const BookManager&) = delete;
public:
	// 全局访问点
	static BookManager* getInstance();

	void addBook(const string& name);                   // 添加书籍
	void removeBook(const string& name);				// 移除书籍
	int getCount(const string& name) const;				// 获取同类型数量
	int getTotalCount() const;							// 获取图书总数量
	void updateCount(const string& name, int n);		// 修改数量

	void readCount();									// 从文件读取
	void saveCount();									// 保存到文件

	
};
#endif // !__BOOKMANAGER__

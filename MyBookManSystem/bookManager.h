#pragma once
#ifndef __BOOKMANAGER__
#define __BOOKMANAGER__
#include<unordered_map>
#include<string>	
using namespace std;

// 同名称书籍数量  管理器
class BookManager {
private:
	unordered_map <string, int> bookCount;
public:
	void addBook(const string& name);                   // 添加书籍
	void removeBook(const string& name);				// 移除书籍
	int getCount(const string& name) const;				// 获取同类型数量
	int getTotalCount() const;							// 获取图书总数量
	void updateCount(const string& name, int n);		// 修改数量
};
#endif // !__BOOKMANAGER__

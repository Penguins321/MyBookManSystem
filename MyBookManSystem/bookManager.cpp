#include<iostream>
#include<unordered_map>
#include<string>
#include"bookManager.h"
using namespace std;

// 同名称书籍数量  管理器
	// 添加书籍
void BookManager::addBook(const string& name) {
	bookCount[name]++;
}
// 移除书籍
void BookManager::removeBook(const string& name) {
	if (bookCount[name] > 0) {
		bookCount[name]--;
		if (bookCount[name] == 0) {
			bookCount.erase(name);
		}
	}
}

// 获取同类型数量
int BookManager::getCount(const string& name) const {
	auto it = bookCount.find(name);
	return (it != bookCount.end()) ? it->second : 0;
}

// 获取图书总数量
int BookManager::getTotalCount() const {
	int totalCount = 0;
	for (auto it = bookCount.begin(); it != bookCount.end(); it++) {
		totalCount += it->second;
	}
	return totalCount;
}

// 修改数量
void BookManager::updateCount(const string& name, int n) {
	bookCount[name] = n;
};
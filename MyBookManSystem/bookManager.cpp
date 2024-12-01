#include<iostream>
#include<unordered_map>
#include<string>
#include"bookManager.h"
#include<fstream>
#include<sstream>
using namespace std;
//unordered_map<string, int> BookManager::bookCount;

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

// 从文件读取
void BookManager::readCount() {
	fstream inFile;
	string line;
	inFile.open("bookcount.txt",ios::in);
	if (!inFile) {
		cout << "File open failed!" << endl;
		return;
	}
	while (getline(inFile,line))			// 整行读取直到文件尾
	{
		string key;
		int value;

		stringstream ss(line);				// 使用stringstream 将每行解析为键值对
		ss >> key >> value;
		bookCount[key] = value;
	}
	inFile.close();
}

// 保存到文件
void BookManager::saveCount() {
	fstream outFile;
	outFile.open("bookcount.txt",ios::out|ios::trunc);
	for (const auto& pair : bookCount) {
		outFile << pair.first << " " << pair.second << endl;     // 格式为 key value
	}
	outFile.close();
}


#include<iostream>
#include<unordered_map>
#include<string>
#include"bookManager.h"
using namespace std;

// ͬ�����鼮����  ������
	// ����鼮
void BookManager::addBook(const string& name) {
	bookCount[name]++;
}
// �Ƴ��鼮
void BookManager::removeBook(const string& name) {
	if (bookCount[name] > 0) {
		bookCount[name]--;
		if (bookCount[name] == 0) {
			bookCount.erase(name);
		}
	}
}

// ��ȡͬ��������
int BookManager::getCount(const string& name) const {
	auto it = bookCount.find(name);
	return (it != bookCount.end()) ? it->second : 0;
}

// ��ȡͼ��������
int BookManager::getTotalCount() const {
	int totalCount = 0;
	for (auto it = bookCount.begin(); it != bookCount.end(); it++) {
		totalCount += it->second;
	}
	return totalCount;
}

// �޸�����
void BookManager::updateCount(const string& name, int n) {
	bookCount[name] = n;
};
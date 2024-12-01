#include<iostream>
#include<unordered_map>
#include<string>
#include"bookManager.h"
#include<fstream>
#include<sstream>
using namespace std;
//unordered_map<string, int> BookManager::bookCount;

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

// ���ļ���ȡ
void BookManager::readCount() {
	fstream inFile;
	string line;
	inFile.open("bookcount.txt",ios::in);
	if (!inFile) {
		cout << "File open failed!" << endl;
		return;
	}
	while (getline(inFile,line))			// ���ж�ȡֱ���ļ�β
	{
		string key;
		int value;

		stringstream ss(line);				// ʹ��stringstream ��ÿ�н���Ϊ��ֵ��
		ss >> key >> value;
		bookCount[key] = value;
	}
	inFile.close();
}

// ���浽�ļ�
void BookManager::saveCount() {
	fstream outFile;
	outFile.open("bookcount.txt",ios::out|ios::trunc);
	for (const auto& pair : bookCount) {
		outFile << pair.first << " " << pair.second << endl;     // ��ʽΪ key value
	}
	outFile.close();
}


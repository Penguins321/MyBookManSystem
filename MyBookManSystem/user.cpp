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


// ��ʾ�鼮��Ϣ
void User::showBook(vector<Book>* vec) const {
	cout << left << setw(20) << "isbnͼ����" << left << setw(20) << "ͼ������"
		<< left << setw(20) << "ͼ������" << left << setw(20) << "ͬ�����鼮����" << endl;
	cout << string(50, '-') << endl;
	int count = 0;
	for (auto it = vec->begin(); it != vec->end(); ++it) {
		count = Book::manager.getCount(it->book_name);
		cout << left << setw(20) << it->isbn << left << setw(20) << it->book_name
			<< left << setw(20) << it->author << left << setw(20) << count << endl;
	}
}

// �����Լ����鼮
/*
isbn��������ͼ������
vec1Ϊ���ݴ���*/
void User::findBook(vector<Book>* vec1, vector<Book>& vec2) {
	int choice;
	cout << "�������������ͣ� 1:��ISBN   2����ͼ������   3��������" << endl;
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
		cout << "��������ȷ������" << endl;
		break;
	}
}

// ��ISBN����
void findByIsbn(vector<Book>* vec1, vector<Book>& vec2) {
	string isbn;
	User user;
	cout << "������ͼ��ISBN�ţ�";
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

// ��ͼ����������
void findByBookName(vector<Book>* vec1, vector<Book>& vec2) {
	string book_name;
	User user;
	cout << "�������㽫Ҫ������ͼ�����ƣ�";
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

// ��������������
void findByAuthor(vector<Book>* vec1, vector<Book>& vec2) {
	string author;
	User user;
	cout << "�������㽫Ҫ���������ߣ�";
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

// �û���¼           
// idea 1������student, admin, ��������Ӳ������Ƿ��¼���������ֵ�¼����ѧ�����ǹ���Ա
// idea 2�����ݳ����ŵ�user�ࡣstudent���admin��ֻ�����з���
User& User::login(vector<User>* vec,User* user) {
	bool flag = false;
	cout << "�������û�����";
	getline(cin, user->name);
	// ������֤�Ƿ�����û���
	for (auto it = vec->begin(); it != vec->end(); ++it) {
		if (it->name == user->name) {
			// ��֤����
			cout << "���������룺";
			getline(cin, user->password);
			if (it->password == user->password) {
				user->role = it->role;
				user->login_status = true;
				cout << "��¼�ɹ���" << endl;
				return *user;
			}
		}
	}
	return *user;
}


// �����û�
void User::createUser(vector<User>* vec) {
	int choice;
	string userName;
	User user;
	cout << "������Ҫ�����Ľ�ɫ�� ����Ա��1��  ѧ����2��";
	cin >> choice;
	while (cin.get() != '\n')
		continue;
	cout << "������ע���û�����" << endl;
	getline(cin, userName);
	switch (choice) {
	case 1:
		user.name = userName;
		user.role = choice;
		signUp(vec, user);							// ע���߼�
		break;
	case 2:
		user.name = userName;
		user.role = choice;
		signUp(vec, user);
		break;
	default:
		break;
	}
	cout << "ע��ɹ���" << endl;

}

// ��ȡ�ļ�
void User::fetchUser(vector<User>* vec) {
	fstream inFile;
	User user;
	inFile.open("user.txt",ios::in);
	if (!inFile) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	while (inFile >> user){
		vec->push_back(user);
	}
	inFile.close();
}

// ���浽�ļ�
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

// ע���߼�
void signUp(vector<User>* vec, User& user) {
	for (auto it = vec->begin(); it != vec->end();++it) {
		if (it->name == user.name) {
			cout << "�û����ظ��������ԣ�" << endl;
			user.createUser(vec);
		}
	}
	cout << "������ע�����룺";
	getline(cin, user.password);
	vec->push_back(user);
}

// չʾ�û�
void User::showUser(vector<User>* vec) {
	string roleName;
	cout << left << setw(20) << "�û���" << left << setw(20) << "����" << left << setw(20) << "��ɫ" << endl;
	cout << string(50, '-') << endl;
	for (User u : *vec) {
		u.role == 1 ? roleName = "����Ա" : roleName = "ѧ��";
		cout << left << setw(20) << u.name << left << setw(20) << u.password << left << setw(20) << roleName << endl;
	}
}

// ɾ���û�
void User::deleteUser(vector<User>* vec) {
	string userName;
	cout << "�����뽫Ҫɾ�����û�����" << endl;
	getline(cin, userName);
	for (auto it = vec->begin(); it != vec->end();) {
		if (it->name == userName) {
			it = vec->erase(it);
		}
		else
			++it;
	}
}



// ��Ԫ����������������
istream& operator>>(istream& is, User& user) {
	getline(is, user.name);
	getline(is, user.password);
	is >> user.role;
	is.ignore();			 // ����ǰһ�������Ļ��з�
	return is;
}
ostream& operator<<(ostream& os, const User& user) {
	os << user.name << endl
		<< user.password << endl
		<< user.role << endl;
	return os;
}

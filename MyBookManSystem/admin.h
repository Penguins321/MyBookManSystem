#pragma once
#ifndef __ADMIN__
#define __ADMIN__
#include"user.h"
#include<iostream>

class Admin :public User {

public:

	void deleteBook(vector<Book>& vec);						// …æ≥˝Õº È
	void appendBook(vector<Book>& vec);						// ÃÌº”Õº È
};
#endif // !__ADMIN__

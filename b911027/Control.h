#pragma once
#include <iostream>
#include "Entity.h"

using namespace std;

class Join {

private:

	MemberCollection* memberCollection;
public:
	//Join();
	Join(MemberCollection* collection) : memberCollection(collection) {
		// 생성자에서 MemberCollection 객체를 받아와 초기화합니다.
	}
	Member* createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password);

};
//memberCollection;
class LogIn{
private:

	MemberCollection* memberCollection;
public: 

	LogIn(MemberCollection* collection) : memberCollection(collection){}
	Member * logIn(const char *ID, const char *password);

};
class LogOut {
private:
	MemberCollection* memberCollection;
public: 
	LogOut(MemberCollection* collection) : memberCollection(collection) {}
	Member* logOut();
};
class DeleteMembership {
	MemberCollection* memberCollection;
public: 
	DeleteMembership(MemberCollection *collection) : memberCollection(collection) {}
	char* deleteMember();
};



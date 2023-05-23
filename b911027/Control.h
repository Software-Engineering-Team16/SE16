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
	Member *createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password);

};
class LogIn{
private:
	//vector<Member*> membersList;
//	Member* loggedInMember; //로그인 된 멤버 객체 포인터
	//vector <Member*>& memberList;
	MemberCollection* memberCollection;
public: 
	//LogIn(std::vector<Member*>& members) : memberList(members) {
		// 생성자에서 memberList에 대한 참조를 초기화합니다.
//	}
	LogIn(MemberCollection* collection) : memberCollection(collection){}
	Member * logIn(const char *ID, const char *password);

};
class LogOut {

public: void logOut();
};
class DeleteMembership {

public: void deleteMember();
};



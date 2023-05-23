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
		// �����ڿ��� MemberCollection ��ü�� �޾ƿ� �ʱ�ȭ�մϴ�.
	}
	Member *createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password);

};
class LogIn{
private:
	//vector<Member*> membersList;
//	Member* loggedInMember; //�α��� �� ��� ��ü ������
	//vector <Member*>& memberList;
	MemberCollection* memberCollection;
public: 
	//LogIn(std::vector<Member*>& members) : memberList(members) {
		// �����ڿ��� memberList�� ���� ������ �ʱ�ȭ�մϴ�.
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



#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#define MAX_STRING 32
class Member 
{

private:
	int member_type; //1이면 회사회원, 2면 일반회원
	//string name; //이름
	//string SSN; //사업자번호 or 주민번호
	//string ID;
	//string password;
	char name[MAX_STRING];
	char SSN[MAX_STRING];
	char ID[MAX_STRING];
	char password[MAX_STRING];
	bool isLogin = false;

public:
	Member(int member_type, const char* name, const char* SSN, const char* ID, const char* password);
	int getMemberType();
	const char* getName();
	const char* getSSN();
	const char* getID();
	const char* getPassword();
	bool getIsLogin();
	void setIsLogin(bool login);
	bool isMatch(const char * targetID, const char * targetPassword);
	~Member();
};
class NormalMember: public Member
{
private:

public:
	NormalMember(const char* name, const char* SSN, const char* ID, const char* password);

	
};
class CompanyMember: public Member
{
private:
public:
	CompanyMember(const char* name, const char* SSN, const char* ID, const char* password);

};


class MemberCollection {

private: vector<Member*> membersList;
public: 

	void addMember(Member* member);
	Member* findMember(const char* ID, const char* password);
	Member* findLogInMember();
	void showMember();
	Member* findFirst();
	void deleteMember(Member* member);
};
//isLogin()?


#include "Entity.h"

/*Member::Member(int member_type, const char* name, const char* SSN, const char* ID, const char* password)
{
		this->member_type = member_type;
		this->name = name;
		this->SSN = SSN;
		this->ID = ID;
		this->password = password;

	

	this->member_type = member_type;
	strncpy(this->name, name, MAX_STRING - 1);
	strncpy(this->SSN, SSN, MAX_STRING - 1);
	strncpy(this->ID, ID, MAX_STRING - 1);
	strncpy(this->password, password, MAX_STRING - 1);
	this->name[MAX_STRING - 1] = '\0';
	this->SSN[MAX_STRING - 1] = '\0';
	this->ID[MAX_STRING - 1] = '\0';
	this->password[MAX_STRING - 1] = '\0';
		
		
	
		//member type이 1이면 회사회원
		//2면 일반 회원



}*/
Member::Member(int member_type, const char* name, const char* SSN, const char* ID, const char* password)
{
	this->member_type = member_type;
	strncpy(this->name, name, MAX_STRING - 1);
	strncpy(this->SSN, SSN, MAX_STRING - 1);
	strncpy(this->ID, ID, MAX_STRING - 1);
	strncpy(this->password, password, MAX_STRING - 1);
	this->name[MAX_STRING - 1] = '\0';
	this->SSN[MAX_STRING - 1] = '\0';
	this->ID[MAX_STRING - 1] = '\0';
	this->password[MAX_STRING - 1] = '\0';
}

NormalMember::NormalMember(const char* name, const char* SSN, const char* ID, const char* password)
	: Member(2, name, SSN, ID, password)
{
	
	// NormalMember의 추가적인 초기화 작업 수행
}

CompanyMember::CompanyMember(const char* name, const char* SSN, const char* ID, const char* password)
	: Member(1, name, SSN, ID, password)
{
	// CompanyMember의 추가적인 초기화 작업 수행
}

int Member::getMemberType()
{
	return this->member_type;
}

const char* Member::getSSN()
{
	return this->SSN;
}

const char* Member::getID()
{
	return this->ID;
}

const char* Member::getName()
{
	return this->name;
}

const char* Member::getPassword()
{
	return this->password;
}

bool Member::getIsLogin()
{
	return this->isLogin;
}
void Member::setIsLogin(bool login)
{
	if (login == true) this->isLogin = true;
	else this->isLogin = false;
}
bool Member::isMatch(const char* targetID, const char* targetPassword)
{
	return (strcmp(ID, targetID) == 0 && strcmp(password, targetPassword) == 0);
}

void MemberCollection::addMember(Member *member)
{
	membersList.push_back(member);
}
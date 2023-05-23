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
		
		
	
		//member type�� 1�̸� ȸ��ȸ��
		//2�� �Ϲ� ȸ��



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
	
	// NormalMember�� �߰����� �ʱ�ȭ �۾� ����
}

CompanyMember::CompanyMember(const char* name, const char* SSN, const char* ID, const char* password)
	: Member(1, name, SSN, ID, password)
{
	// CompanyMember�� �߰����� �ʱ�ȭ �۾� ����
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
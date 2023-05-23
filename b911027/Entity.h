#include "Entity.h"


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
	
	
}

CompanyMember::CompanyMember(const char* name, const char* SSN, const char* ID, const char* password)
	: Member(1, name, SSN, ID, password)
{
	
}

Member::~Member() {

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

Member* MemberCollection::findLogInMember()
{
	if (membersList.empty())
	{
		cout << "empty" << endl;
	}
	else {
		for (Member* member : membersList)
		{
			if (member->getIsLogin() == true)
			{
				return member;
			}
		}
	}
}

Member* MemberCollection::findMember(const char* ID, const char* password) {
	if (membersList.empty())
	{
		cout << "empty" << endl;
	}
	else {
		for (Member* member : membersList) {
			if (strcmp(member->getID(), ID) == 0 && strcmp(member->getPassword(), password) == 0) {
				return member;
			}
		}
	}
	return nullptr;
}

void MemberCollection::showMember()
{
	if (membersList.empty())
	{
		cout << "empty" << endl;
	}
	else {
		for (Member* member : membersList)
		{
			cout << member->getID() << endl;
			cout << member->getName() << endl;
			if (member->getIsLogin() == true) cout << "login" << endl;
			else { cout << "not login" << endl; }
		}
	}
	
}

void MemberCollection::deleteMember(Member* member) {
	auto it = std::find(membersList.begin(), membersList.end(), member);
	if (it != membersList.end()) {
		membersList.erase(it);
		delete member; // 멤버 객체의 메모리 해제
		cout << "delete" << endl;
	}
	cout << membersList.size() << endl;
}

Member* MemberCollection::findFirst()
{
	return membersList.front();
}

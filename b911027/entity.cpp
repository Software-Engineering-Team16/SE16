#include "entity.h"

//Member
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
	applyList = new ApplyInfoList();

}
NormalMember::~NormalMember()
{
	delete applyList;
}

CompanyMember::CompanyMember(const char* name, const char* SSN, const char* ID, const char* password)
	: Member(1, name, SSN, ID, password)
{
	jobList = new JobAdList();
}
CompanyMember::~CompanyMember()
{
	delete jobList;
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

void Member::setIsLogin(bool value)
{
	if (value)
		this->isLogin = true;
	else
		this->isLogin = false;
}
//Member

void MemberList::addMember(Member* member)
{
	membersList.push_back(member);
}
void MemberList::deleteMember(Member* member)
{
	auto it = std::find(membersList.begin(), membersList.end(), member);
	if (it != membersList.end()) {
		membersList.erase(it);
		delete member; // 멤버 객체의 메모리 해제
		cout << "delete" << endl;
	}
	cout << membersList.size() << endl;
}

void MemberList::showMember()
{
	if (membersList.empty())
	{
		cout << "empty" << endl;
	}
	else {
		for (Member* member : membersList)
		{
			cout <<"ID "<< member->getID() << endl;
			cout <<"NAME "<< member->getName() << endl;
			if (member->getIsLogin() == true) cout << "로그인" << endl;
			else { cout << "로그인 안함" << endl; }
		}
	}

}
Member* MemberList::findMember(const char* ID, const char* password) {
	
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
Member* MemberList::findLogInMember()
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

Member* MemberList::getMember()
{
	return membersList.back();
}

CompanyMember* MemberList::getCompanyMember()
{
	for (Member* member : membersList)
	{
		if (member->getMemberType() == 1)
		{
			return dynamic_cast<CompanyMember*>(member);
		}
	}
}

NormalMember* MemberList::getNormalMember()
{
	for (Member* member : membersList)
	{
		if (member->getMemberType() == 2)
		{
			return dynamic_cast<NormalMember*>(member);
		}
	}
}
//Member List
void CompanyMember::addJobAd(const char* task, int numberOfMember, const char* deadline)
{
	
	JobAd* newJobAd = new JobAd(task, numberOfMember, deadline);
	jobList->addJob(newJobAd);
}

JobAdList* CompanyMember::getJobList()
{
	return jobList;
}

JobAd::JobAd(const char*task ,int numberOfMember, const char* deadline)
{
	strncpy(this->task, task, MAX_STRING - 1);
	this->numberOfMember = numberOfMember;
	strncpy(this->deadline, deadline, MAX_STRING - 1);

	this->task[MAX_STRING - 1] = '\0';
	this->deadline[MAX_STRING - 1] = '\0';
	
}
const char* JobAd::getTask()
{
	return this->task;
}
const char* JobAd::getDeadLine()
{
	return this->deadline;
}
int JobAd::getNumberOfMember()
{
	return this->numberOfMember;
}

//채용 정보 JobAd
void ApplyInfoList::addApply(ApplyInfo* applyInfo)
{
	applyList.push_back(applyInfo);
}

void ApplyInfoList::deleteApply(ApplyInfo* applyInfo)
{

}

//ApplyInfo List

void JobAdList::addJob(JobAd* jobAd)
{
	jobList.push_back(jobAd);
}
void JobAdList::deleteJob(JobAd* jobAd)
{

}
char* JobAdList::getJobAd()
{
	string resultStr; // 반환할 문자열

	for (JobAd* jobAd : jobList)
	{
		// JobAd 객체에서 정보를 가져와 결과 문자열에 추가합니다.
		resultStr += jobAd->getTask();
		resultStr += " ";
		resultStr += to_string(jobAd->getNumberOfMember());
		resultStr += " ";
		resultStr += jobAd->getDeadLine();
		resultStr += "\n";

	}

	char* resultChar = new char[resultStr.size() + 1]; // char* 배열을 동적 할당합니다.
	strcpy(resultChar, resultStr.c_str()); // string을 char*로 변환합니다.

	return resultChar;
}
int JobAdList::getNumOfJobAd()
{
	return jobList.size();
}
//void JobAdList::showJobAdList()
//{
//	for (JobAd* jobAd : jobList)
//	{
//
//	}
//}

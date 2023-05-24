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
		delete member; // ��� ��ü�� �޸� ����
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
			if (member->getIsLogin() == true) cout << "�α���" << endl;
			else { cout << "�α��� ����" << endl; }
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
		if (member->getMemberType() == 1&&member->getIsLogin()==true) //ȸ��ȸ���̰� ���� �α��� ������
		{
			return dynamic_cast<CompanyMember*>(member);
		}
	}
}

NormalMember* MemberList::getNormalMember()
{
	for (Member* member : membersList)
	{
		if (member->getMemberType() == 2 &&member->getIsLogin()==true) //�Ϲ�ȸ���̰� ���� �α��� ������
		{
			return dynamic_cast<NormalMember*>(member);
		}
	}
}

CompanyMember* MemberList::findByName(const char * name)
{
	for (Member* member : membersList)
	{
		if (strcmp(member->getName(), name) == 0)
		{
			// �̸��� ��ġ�ϴ� ����� ã���� �� �ش� ����� ��ȯ�մϴ�.
			return dynamic_cast<CompanyMember*>(member);
		}
	}
}


CompanyMember* MemberList::findBySSN(const char* SSN)
{
	for (Member* member : membersList)
	{
		if (strcmp(member->getSSN(), SSN) == 0)
		{
			// SSN�� ��ġ�ϴ� ����� ã���� �� �ش� ����� ��ȯ�մϴ�.
			return dynamic_cast<CompanyMember*>(member);
		}
	}
}
//Member List
void CompanyMember::addJobAd(const char* task, int numberOfMember, const char* deadline)
{

	JobAd* newJobAd = new JobAd(this->getName(), this->getSSN(), task, numberOfMember, deadline);
	jobList->addJob(newJobAd);
}

//CompanyMember

void NormalMember::addApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline)
{
	ApplyInfo* newApplyInfo = new ApplyInfo(companyName, SSN, task, numberOfMember, deadline);
	applyList->addApply(newApplyInfo);
}

//NormalMember
JobAd::JobAd(const char* companyName, const char* SSN, const char*task ,int numberOfMember, const char* deadline)
{
	strncpy(this->companyName, companyName, MAX_STRING - 1);
	strncpy(this->SSN, SSN, MAX_STRING - 1);
	strncpy(this->task, task, MAX_STRING - 1);
	this->numberOfMember = numberOfMember;
	strncpy(this->deadline, deadline, MAX_STRING - 1);
	this->companyName[MAX_STRING - 1] = '\0';
	this->SSN[MAX_STRING - 1] = '\0';
	this->task[MAX_STRING - 1] = '\0';
	this->deadline[MAX_STRING - 1] = '\0';
	
	
}
//ä�� ���� JobAd

void JobAdList::addJob(JobAd* jobAd)
{
	jobList.push_back(jobAd);
}
void JobAdList::deleteJob(JobAd* jobAd)
{

}
char* JobAdList::getJobAd() //���ڿ��� ��ȯ
{
	//ȸ�� ȸ���� ����� ä�� ���� return
	string resultStr; // ��ȯ�� ���ڿ�

	for (JobAd* jobAd : jobList)
	{
		// JobAd ��ü���� ������ ������ ��� ���ڿ��� �߰��մϴ�.
		resultStr += jobAd->getTask();
		resultStr += " ";
		resultStr += to_string(jobAd->getNumberOfMember());
		resultStr += " ";
		resultStr += jobAd->getDeadLine();
		resultStr += "\n";

	}

	char* resultChar = new char[resultStr.size() + 1]; // char* �迭�� ���� �Ҵ��մϴ�.
	strcpy(resultChar, resultStr.c_str()); // string�� char*�� ��ȯ�մϴ�.

	return resultChar;
}
char* JobAdList::getSearchResult()
{
	//ȸ�� ȸ���� ����� ä�� ���� return
	string resultStr; // ��ȯ�� ���ڿ�

	for (JobAd* jobAd : jobList)
	{
		// JobAd ��ü���� ������ ������ ��� ���ڿ��� �߰��մϴ�.
		resultStr += jobAd->getName();
		resultStr += " ";
		resultStr += jobAd->getSSN();
		resultStr += " ";
		resultStr += jobAd->getTask();
		resultStr += " ";
		resultStr += to_string(jobAd->getNumberOfMember());
		resultStr += " ";
		resultStr += jobAd->getDeadLine();
		resultStr += "\n";

	}

	char* resultChar = new char[resultStr.size() + 1]; // char* �迭�� ���� �Ҵ��մϴ�.
	strcpy(resultChar, resultStr.c_str()); // string�� char*�� ��ȯ�մϴ�.

	return resultChar;
}

//JobAdList

ApplyInfo::ApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline)
{
	strncpy(this->companyName, companyName, MAX_STRING - 1);
	strncpy(this->SSN, SSN, MAX_STRING - 1);
	strncpy(this->task, task, MAX_STRING - 1);
	this->numberOfMember = numberOfMember;
	strncpy(this->deadline, deadline, MAX_STRING - 1);
	this->companyName[MAX_STRING - 1] = '\0';
	this->SSN[MAX_STRING - 1] = '\0';
	this->task[MAX_STRING - 1] = '\0';
	this->deadline[MAX_STRING - 1] = '\0';

}


//ApplyInfo
 void ApplyInfoList::addApply(ApplyInfo* applyInfo)
{
	applyList.push_back(applyInfo);
}

void ApplyInfoList::deleteApply(ApplyInfo* applyInfo)
{
	auto it = std::find(applyList.begin(), applyList.end(),applyInfo);
	if (it != applyList.end()) {
		applyList.erase(it);
		delete applyInfo; // ��� ��ü�� �޸� ����
		cout << "delete apply info" << endl;
	}
	cout << applyList.size() << endl;
}

char * ApplyInfoList::getApplyInfo()
{
	//> { [ȸ���̸�] [����ڹ�ȣ] [����] [�ο� ��] [��û������] }*
	string resultStr;
	for (ApplyInfo* applyInfo : applyList)
	{
		// JobAd ��ü���� ������ ������ ��� ���ڿ��� �߰��մϴ�.
		resultStr += applyInfo->getName();
		resultStr += " ";
		resultStr += applyInfo->getSSN();
		resultStr += " ";
		resultStr += applyInfo->getTask();
		resultStr += " ";
		resultStr += to_string(applyInfo->getNumberOfMember());
		resultStr += " ";
		resultStr += applyInfo->getDeadLine();
		resultStr += "\n";

	}

	char* resultChar = new char[resultStr.size() + 1]; // char* �迭�� ���� �Ҵ��մϴ�.
	strcpy(resultChar, resultStr.c_str()); // string�� char*�� ��ȯ�մϴ�.

	return resultChar;

}

ApplyInfo* ApplyInfoList::findBySSN(const char *SSN)
{
	for (ApplyInfo* applyInfo : applyList)
	{
		if (strcmp(applyInfo->getSSN(), SSN) == 0)
		{
			// SSN�� ��ġ�ϴ� ����� ã���� �� �ش� ����� ��ȯ�մϴ�.
			return applyInfo;
		}
	}
}
//ApplyInfo List


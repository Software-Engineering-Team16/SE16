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
		if (member->getMemberType() == 1&&member->getIsLogin()==true) //회사회원이고 지금 로그인 중인지
		{
			return dynamic_cast<CompanyMember*>(member);
		}
	}
}

NormalMember* MemberList::getNormalMember()
{
	for (Member* member : membersList)
	{
		if (member->getMemberType() == 2 &&member->getIsLogin()==true) //일반회원이고 지금 로그인 중인지
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
			// 이름이 일치하는 멤버를 찾았을 때 해당 멤버를 반환합니다.
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
			// SSN이 일치하는 멤버를 찾았을 때 해당 멤버를 반환합니다.
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
//채용 정보 JobAd

void JobAdList::addJob(JobAd* jobAd)
{
	jobList.push_back(jobAd);
}
void JobAdList::deleteJob(JobAd* jobAd)
{

}
char* JobAdList::getJobAd() //문자열로 반환
{
	//회사 회원이 등록한 채용 정보 return
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
char* JobAdList::getSearchResult()
{
	//회사 회원이 등록한 채용 정보 return
	string resultStr; // 반환할 문자열

	for (JobAd* jobAd : jobList)
	{
		// JobAd 객체에서 정보를 가져와 결과 문자열에 추가합니다.
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

	char* resultChar = new char[resultStr.size() + 1]; // char* 배열을 동적 할당합니다.
	strcpy(resultChar, resultStr.c_str()); // string을 char*로 변환합니다.

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
		delete applyInfo; // 멤버 객체의 메모리 해제
		cout << "delete apply info" << endl;
	}
	cout << applyList.size() << endl;
}

char * ApplyInfoList::getApplyInfo()
{
	//> { [회사이름] [사업자번호] [업무] [인원 수] [신청마감일] }*
	string resultStr;
	for (ApplyInfo* applyInfo : applyList)
	{
		// JobAd 객체에서 정보를 가져와 결과 문자열에 추가합니다.
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

	char* resultChar = new char[resultStr.size() + 1]; // char* 배열을 동적 할당합니다.
	strcpy(resultChar, resultStr.c_str()); // string을 char*로 변환합니다.

	return resultChar;

}

ApplyInfo* ApplyInfoList::findBySSN(const char *SSN)
{
	for (ApplyInfo* applyInfo : applyList)
	{
		if (strcmp(applyInfo->getSSN(), SSN) == 0)
		{
			// SSN이 일치하는 멤버를 찾았을 때 해당 멤버를 반환합니다.
			return applyInfo;
		}
	}
}
//ApplyInfo List


#include "entity.h"

/*
	함수 이름 : Member::MemberMember::Member(int member_type, const char* name, const char* SSN, const char* ID, const char* password)
	기능	  : 전달 받은 정보로 회원 객체 초기화하고 생성
	전달 인자 : int member_type, const char* name, const char* SSN, const char* ID, const char* password
	반환값    : 없음
*/
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
/*
	함수 이름 : void Member::setIsLogin(bool value)
	기능	  : 회원의 로그인 상태(isLogin)를 설정, 전달받은 value 값에 따라 로그인 상태를 변경
	전달 인자 : bool value-> true: 로그인, false: 로그인 x
	반환값    : 없음
*/
void Member::setIsLogin(bool value)
{
	if (value)
		this->isLogin = true;
	else
		this->isLogin = false;
}
/*
	함수 이름 : NormalMember::NormalMember(const char* name, const char* SSN, const char* ID, const char* password)
	기능	  : 부모 클래스인 Member의 생성자를 호출하여 회원 객체를 초기화, 생성된 일반 회원 객체는 ApplyInfoList를 가리키는 포인터 applyList를 생성하여 초기화
	전달 인자 : int member_type, const char* name, const char* SSN, const char* ID, const char* password
	반환값    : 없음
*/
NormalMember::NormalMember(const char* name, const char* SSN, const char* ID, const char* password)
	: Member(2, name, SSN, ID, password)
{
	applyList = new ApplyInfoList();	// 해당 일반 회원이 지원한 지원 정보 저장하는 지원 정보 리스트

}
/*
	함수 이름 : CompanyMember::CompanyMember(const char* name, const char* SSN, const char* ID, const char* password)
	기능	  : 부모 클래스인 Member의 생성자를 호출하여 회원 객체를 초기화, 생성된 회사 회원 객체는 JobAdLit를 가리키는 포인터 jobList를 생성하여 초기화
	전달 인자 : int member_type, const char* name, const char* SSN, const char* ID, const char* password
	반환값    : 없음
*/
CompanyMember::CompanyMember(const char* name, const char* SSN, const char* ID, const char* password)
	: Member(1, name, SSN, ID, password)
{
	jobList = new JobAdList();	// 해당 회사 회원이 등록한 채용 정보 저장하는 채용 정보 리스트
}
/*
	함수 이름 : void MemberList::addMember(Member* member)
	기능	  : Member 객체를 MemberList에 추가
	전달 인자 : Member* member-추가할 멤버 객체의 포인터
	반환값    : 없음
*/
// Member
void MemberList::addMember(Member* member)
{
	membersList.push_back(member);
}
/*
	함수 이름 : void MemberList::deleteMember(Member* member)
	기능	  : MemberList에서 Member 객체 삭제
	전달 인자 : Member* member-삭제할 멤버 객체의 포인터
	반환값    : 없음
*/
void MemberList::deleteMember(Member* member)
{
	auto it = std::find(membersList.begin(), membersList.end(), member); // memberList에서 전달받은 member 객체 찾음
	if (it != membersList.end()) {
		membersList.erase(it);		// 찾은 멤버 객체를 memberList에서 삭제
		delete member; // 멤버 객체의 메모리 해제
	}
}
/*
	함수 이름 : Member* MemberList::findMember(const char* ID, const char* password)
	기능	  : 전달 받은 ID, PW로 일치하는 Member 객체 찾아서 포인터 반환
	전달 인자 : const char * ID, const char * password
	반환값    : 찾은 Member 객체 포인터
*/
Member* MemberList::findMember(const char* ID, const char* password) {
	
	if (membersList.empty())	// membersList가 비어있는 경우
	{
		cout << "empty" << endl;
	}	
	else {	// memberList가 비어있지 않은 경우 membersList를 순회하면서 ID와 PW 비교하면서 ID, PW가 일치하는 멤버 객체 포인터 찾음
		for (Member* member : membersList) {
			if (strcmp(member->getID(), ID) == 0 && strcmp(member->getPassword(), password) == 0) {
				return member;
			}
		}
	}
	return nullptr;
}
/*
	함수 이름 : Member* MemberList::findLogInMember()
	기능	  : 현재 로그인 상태가 true인 Member 객체 찾아서 포인터 반환
	전달 인자 : 없음
	반환값    : 찾은 Member 객체 포인터
*/
Member* MemberList::findLogInMember()
{
	if (membersList.empty())
	{
		cout << "empty" << endl;
	}
	else { // memberList가 비어있지 않은 경우 membersList를 순회하면서 로그인 상태가 true인 객체 포인터 찾음
		for (Member* member : membersList)
		{
			if (member->getIsLogin() == true)
			{
				return member;
			}
		}
	}
}
/*
	함수 이름 : CompanyMember* MemberList::getCompanyMember()
	기능	  : 현재 로그인 상태가 true인 CompanyMember 객체 포인터 반환
	전달 인자 : 없음
	반환값    : 찾은 CompnayMember 객체 포인터
*/
CompanyMember* MemberList::getCompanyMember()
{
	// membersList가 비어있지 않은 경우 membersList를 순회하면서 로그인 상태가 true인 회원 객체 포인터 찾음
	for (Member* member : membersList)
	{
		if (member->getMemberType() == 1&&member->getIsLogin()==true) // membertype이 회사 회원이고 지금 로그인 중인지 확인
		{
			return dynamic_cast<CompanyMember*>(member);	// 찾은 회원 객체 포인터 CompanyMember로 다운캐스팅
		}
	}
}
/*
	함수 이름 : NormalMember* MemberList::getNormalMember()
	기능	  : 현재 로그인 상태가 true인 NormalMember 객체 포인터 반환
	전달 인자 : 없음
	반환값    : 찾은 NormalMember 객체 포인터 
*/
NormalMember* MemberList::getNormalMember()
{
	// membersList가 비어있지 않은 경우 membersList를 순회하면서 로그인 상태가 true인 회원 객체 포인터 찾음
	for (Member* member : membersList)
	{
		if (member->getMemberType() == 2 &&member->getIsLogin()==true) // membertype이 일반 회원이고 지금 로그인 중인지 확인
		{
			return dynamic_cast<NormalMember*>(member);	// 찾은 회원 객체 포인터 NormalMember로 다운캐스팅
		}
	}
}
/*
	함수 이름 : CompanyMember* MemberList::findByName(const char * name)
	기능	  : 이름이 일치하는 CompanyMember 객체 포인터 전달
	전달 인자 : const char* name
	반환값    : 찾은 CompanyMember 포인터
*/
CompanyMember* MemberList::findByName(const char * name)
{
	for (Member* member : membersList)
	{
		if (strcmp(member->getName(), name) == 0)
		{
			// membersList를 순회하면서 이름이 일치하는 멤버를 찾았을 때 해당 멤버 CompanyMember로 다운캐스팅 하여 반환
			return dynamic_cast<CompanyMember*>(member);
		}
	}
}
/*
	함수 이름 : CompanyMember* MemberList::findBySSN(const char* SSN)
	기능	  : SSN이 일치하는 CompanyMember 객체 포인터 전달
	전달 인자 : const char* SSN
	반환값    : 찾은 CompanyMember 포인터
*/
CompanyMember* MemberList::findBySSN(const char* SSN)
{
	for (Member* member : membersList)
	{
		if (strcmp(member->getSSN(), SSN) == 0)
		{
			// membersList를 순회하면서 SSN이 일치하는 멤버를 찾았을 때 해당 멤버 CompanyMember로 다운캐스팅 하여 반환
			return dynamic_cast<CompanyMember*>(member);
		}
	}
}
//Member List

/*
	함수 이름 : void CompanyMember::addJobAd(const char* task, int numberOfMember, const char* deadline)
	기능	  : 입력 받은 정보 가지고 채용 정보 생성하고 CompanyMember가 가지고 있는 jobList에 채용 정보 추가
	전달 인자 : const char* task, int numberOfMember, const char* deadline
	반환값    : 없음
*/
void CompanyMember::addJobAd(const char* task, int numberOfMember, const char* deadline)
{
	JobAd* newJobAd = new JobAd(this->getName(), this->getSSN(), task, numberOfMember, deadline);	// 입력받은 정보 가지고 JobAd 생성
	jobList->addJob(newJobAd);	// 생성한 JobAd를 CompanyMember의 jobList에 추가
}
//CompanyMember

/*
	함수 이름 : void NormalMember::addApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline)
	기능	  : 입력 받은 정보 가지고 지원 정보 등록 하고 NormalMember가 가지고 있는 applyList에 지운 정보 추가
	전달 인자 : const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline
	반환값    : 없음
*/
void NormalMember::addApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline)
{
	ApplyInfo* newApplyInfo = new ApplyInfo(companyName, SSN, task, numberOfMember, deadline);
	// 입력받은 정보 가지고 applyinfo 생성
	applyList->addApply(newApplyInfo);	// 생성한 applyInfo를 NormalMember의 applyList에 추가
}
//NormalMember

/*
	함수 이름 : JobAd::JobAd(const char* companyName, const char* SSN, const char*task ,int numberOfMember, const char* deadline)
	기능	  : 전달 받은 정보로 채용 정보 객체 초기화하고 생성
	전달 인자 : const char* companyName, const char* SSN, const char*task ,int numberOfMember, const char* deadline
	반환값    : 없음
*/
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

/*
	함수 이름 : void JobAdList::addJob(JobAd* jobAd)
	기능	  : 채용 정보 리스트(벡터)에 채용 정보 추가 
	전달 인자 : JobAd* jobAd - 추가하려는 채용 정보 포인터
	반환값    : 없음
*/
void JobAdList::addJob(JobAd* jobAd)
{
	jobList.push_back(jobAd);
}

/*
	함수 이름 : char* JobAd::getJobAdString()
	기능	  : 회사 회원이 채용 정보를 출력하기 위해 채용 정보를 문자열로 변환하는 함수
	전달 인자 : 없음
	반환값    : char* - 출력용 채용 정보 문자열(업무, 인원수, 마감)
*/
char* JobAd::getJobAdString()
{
	string resultStr; // 반환할 문자열 string

	// JobAd 객체에서 정보를 가져와 결과 문자열에 추가
	resultStr += this->getTask();	// 업무
	resultStr += " ";
	resultStr += to_string(this->getNumberOfMember());	// 인원수 
	resultStr += " ";
	resultStr += this->getDeadLine();	// 마감일
	resultStr += "\n";

	char* resultChar = new char[resultStr.size() + 1]; // char* 배열을 동적 할당
	strcpy(resultChar, resultStr.c_str()); // string을 char*로 변환
	return resultChar;
}
/*
	함수 이름 : char* JobAd::getSearchResult()
	기능	  : 일반 회원이 회사가 등록한 채용 정보를 검색한 결과를 출력하기 위해 채용 정보를 문자열로 변환하는 함수
	전달 인자 : 없음
	반환값    : char* - 검색 결과 출력용 채용 정보 문자열(회사 이름, 사업자번호, 업무, 인원수, 마감)
*/
char* JobAd::getSearchResult()
{
	string resultStr; // 반환할 문자열
	
	// JobAd 객체에서 정보를 가져와 결과 문자열에 추가
	resultStr += this->getName(); // 회사 이름
	resultStr += " ";
	resultStr += this->getSSN(); // 사업자번호
	resultStr += " ";
	resultStr += this->getJobAdString(); // 업무 인원수 마감일

	char* resultChar = new char[resultStr.size() + 1]; // char* 배열을 동적 할당
	strcpy(resultChar, resultStr.c_str()); // string을 char*로 변환

	return resultChar;
}

//JobAdList
/*
	함수 이름 : ApplyInfo::ApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline)
	기능	  : 전달 받은 정보로 지원 정보 객체 초기화하고 생성
	전달 인자 :	const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline
	반환값    : 없음
*/
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

/*
	함수 이름 : void ApplyInfoList::addApply(ApplyInfo* applyInfo)
	기능	  : 지원 정보 리스트(벡터)에 지원 정보 추가
	전달 인자 : ApplyInfo* applyInfo - 추가하려는 지원 정보 포인터
	반환값    : 없음
*/
//ApplyInfo
 void ApplyInfoList::addApply(ApplyInfo* applyInfo)
{
	applyList.push_back(applyInfo);
}
/*
	 함수 이름 : void ApplyInfoList::deleteApply(ApplyInfo* applyInfo)
	 기능	  :  지원 정보 리스트(벡터)에서 특정 지원 정보 삭제
	 전달 인자 : ApplyInfo* applyInfo - 삭제하려는 지원 정보 포인터
	 반환값    : 없음
*/
void ApplyInfoList::deleteApply(ApplyInfo* applyInfo)
{
	auto it = std::find(applyList.begin(), applyList.end(),applyInfo); // applyList에서 전달받은 applyInfo 찾음 
	if (it != applyList.end()) {
		applyList.erase(it); // 찾은 지원 정보 객체를 applyList에서 삭제
		delete applyInfo; // 지원 정보 객체의 메모리 해제
	}
}
/*
	함수 이름 :	char * ApplyInfoList::getApplyInfoString()
	기능	  : 일반 회원이 지원 정보를 출력하기 위해 자신이 지원한 지원 정보를 문자열로 변환하는 함수
	전달 인자 : 없음
	반환값    : char* - 출력용 지원 정보 문자열 (회사이름 사업자번호 업무 인원 수 신청마감일)
*/
char * ApplyInfoList::getApplyInfoString()
{
	//> { [회사이름] [사업자번호] [업무] [인원 수] [신청마감일] }*
	string resultStr; // 반환할 문자열 string
	for (ApplyInfo* applyInfo : applyList)	
	{
		// applyList를 순회하며 ApplyInfo 객체에서 정보를 가져와 결과 문자열에 추가	
		resultStr += applyInfo->getName(); // 이름 
		resultStr += " ";
		resultStr += applyInfo->getSSN(); // 사업자 번호
		resultStr += " ";
		resultStr += applyInfo->getTask(); // 업무
		resultStr += " ";
		resultStr += to_string(applyInfo->getNumberOfMember()); // 인원수
		resultStr += " ";
		resultStr += applyInfo->getDeadLine(); // 마감일
		resultStr += "\n";
	}

	char* resultChar = new char[resultStr.size() + 1]; // char* 배열을 동적 할당
	strcpy(resultChar, resultStr.c_str()); // string을 char*로 변환

	return resultChar;

}
/*
	함수 이름 :	char* ApplyInfoList::getApplyTaskCount()
	기능	  : 일반 회원이 지원 정보 통계(업무 지원횟수)를 출력하기 위해 지원 정보 통계를 문자열로 변환하는 함수
	전달 인자 : 없음
	반환값    : char* - 출력용 지원 정보 통계 문자열 (업무별 지원횟수)
*/
char* ApplyInfoList::getApplyTaskCount()
{
	// {[업무별][지원횟수]}
	string resultStr; // 반환할 문자열 string
	map<string, int> taskCountMap; // 각 업무별 지원횟수 저장하는 map 객체

	for (ApplyInfo* applyInfo : applyList)
	{
		const char* task = applyInfo->getTask(); 
		string taskStr(task); // 각 applyInfo 객체에서 업무 가져와서 taskStr에 저장

		if (taskCountMap.find(taskStr) == taskCountMap.end())	 
		{
			// 새로운 task인 경우 해당 업무의 지원 횟수 1로 설정
			taskCountMap[taskStr] = 1;
		}
		else
		{
			// 이미 있는 task인 경우 해당 업무의 지원 횟수 추가
			taskCountMap[taskStr]++;
		}
	}

	// taskCountMap을 순회하면서 업무 이름과 해당 업무의 지원 횟수 resultStr에 추가
	for (const auto& entry : taskCountMap)
	{
		resultStr += entry.first;
		resultStr += " ";
		resultStr += std::to_string(entry.second);
		resultStr += "\n";
	}

	char* resultChar = new char[resultStr.size() + 1]; // char* 배열을 동적 할당
	strcpy(resultChar, resultStr.c_str()); // string을 char*로 변환

	return resultChar;
}

/*
	함수 이름 :	ApplyInfo* ApplyInfoList::findBySSN(const char *SSN)
	기능	  : applyList에서 SSN이 일치하는 지원 정보 찾아 지원 정보 포인터 반환
	전달 인자 : const char *SSN 
	반환값    : 찾은 지원 정보 포인터 
*/
ApplyInfo* ApplyInfoList::findBySSN(const char *SSN)
{
	for (ApplyInfo* applyInfo : applyList)
	{
		if (strcmp(applyInfo->getSSN(), SSN) == 0)
		{
			return applyInfo; // SSN이 일치하는 지원정보 찾았을 때 지원 정보 반환
		}
	}
}
//ApplyInfo List


#include "control.h"

/*
    함수 이름 : void Join::createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password) 
    기능	  : 인자로 받은 정보를 가지고 member_type을 구분하여 Member 객체를 생성
    전달 인자 : int member_type, const char* name, const char* SSN, const char* ID, const char* password
    반환값    : 없음
*/
void Join::createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password) 
{
    Member* newMember = nullptr;
    // member_type이 1이면 회사 회원 생성, 2면 일반 회원 생성
    if (member_type == 1) {
        newMember = new CompanyMember(name, SSN, ID, password);
    }  
    else {
        newMember = new NormalMember(name, SSN, ID, password);
    }
    pMemberList->addMember(newMember);
}
//Join
/*
    함수 이름 : Member* LogIn::logIn(const char* ID, const char* password)
    기능	  : 인자로 받은 ID, 비밀번호를 가지고 ID와 비밀번호가 일치하는 Member 객체 찾아서 login 상태를 true로 바꿔주고, 로그인 한 Member 객체 포인터 반환
    전달 인자 : const char* ID, const char* password
    반환값    : 로그인 한 Member 객체 포인터
*/
Member* LogIn::logIn(const char* ID, const char* password)
{
    Member* member = pMemberList->findMember(ID, password);
    member->setIsLogin(true);
    return member;
}
//LogIn
/*
    함수 이름 : char* LogOut::logOut()
    기능	  : 현재 로그인 한 Member 객체 찾아서 login 상태를 false로 바꿔주고, 로그아웃된 Member 객체의 ID 문자열 반환
    전달 인자 : 없음
    반환값    : char* - 로그아웃 한 Member ID 문자열
*/
char* LogOut::logOut()
{
    char* ID = new char[MAX_STRING];
    Member* member = pMemberList->findLogInMember();
    member->setIsLogin(false);
    strncpy(ID, member->getID(), MAX_STRING - 1);
    return ID;
}
//LogOut
/*
    함수 이름 : char* DeleteMembership::deleteMember()
    기능	  : 현재 로그인 한 Member 객체 찾아서 ID 문자열 저장 후 객체를 MemberList에서 삭제(탈퇴)
    전달 인자 : 없음
    반환값    : 탈퇴한 Member 객체의 ID 문자열
*/
char* DeleteMembership::deleteMember()
{
    char* ID = new char[MAX_STRING];
    Member* member = pMemberList->findLogInMember();
    strncpy(ID, member->getID(), MAX_STRING - 1);
    pMemberList->deleteMember(member);
    return ID;
}
//DeleteMembership

/*
    함수 이름 : void AddJobAd::createJobAd(const char* task, int numberOfMember, const char* deadline)
    기능	  : 로그인 한 회사 회원이 채용정보 등록
    전달 인자 : const char* task, int numberOfMember, const char* deadline
    반환값    : 없음
*/
void AddJobAd::createJobAd(const char* task, int numberOfMember, const char* deadline)
{
    CompanyMember* companyMember = pMemberList->getCompanyMember(); // 로그인 한 회사 회원 객체
    companyMember->addJobAd(task, numberOfMember, deadline); // 회사 회원 객체가 전달된 정보 가지고 채용 정보 등록
}
//AddJobAd
/*
    함수 이름 : char* ListJobAd::getJobAd()
    기능	  : 회사 회원이 등록한 채용 정보의 문자열을 반환
    전달 인자 : 없음
    반환값    : char* - 채용 정보 문자열
*/
char* ListJobAd::getJobAd()
{
    CompanyMember* companyMember = pMemberList->getCompanyMember(); // 로그인 한 회사 회원 객체
    JobAd * jobAd= companyMember->getJobList()->getJobAdDetail(); // 회사 회원 객체가 가지고 있는 채용 정보 리스트에서 채용 정보 반환
    return jobAd->getJobAdString(); // 채용 정보를 문자열로 반환
}
//ListJobAd

/*
    함수 이름 : char* SearchJob::searchJob(const char* name) 
    기능	  : 일반 회원이 회사 이름으로 검색하여 해당 되는 회사 회원이 등록한 채용 정보 문자열 반환
    전달 인자 : const char* name - 회사 이름
    반환값    : char* - 검색 결과로 나온 채용 정보 문자열
*/
char* SearchJob::searchJob(const char* name) 
{
    CompanyMember* companyMember = pMemberList->findByName(name); // 회사 이름으로 찾은 회사 회원 객체
    JobAd* jobAd= companyMember->getJobList()->getJobAdDetail(); // 회사 회원 객체가 가지고 있는 채용 정보 리스트에서 채용 정보 반환
    return jobAd->getSearchResult(); // 채용 정보를 문자열로 반환
}
//SearchJob

/*
    함수 이름 : JobAd* Apply::getJobAdDetail(const char* SSN)
    기능	  : SSN으로 회사 회원을 찾고, 회사 회원이 올린 채용 정보 반환
    전달 인자 : const char* SSN
    반환값    : JobAd* - 회사 회원이 올린 채용 정보
*/
JobAd* Apply::getJobAdDetail(const char* SSN)
{
    CompanyMember* companyMember = pMemberList->findBySSN(SSN); // SSN으로 찾은 회사 회원 객체
    return companyMember->getJobList()->getJobAdDetail(); // 회사 회원이 등록한 채용 정보 반환
}
/*
    함수 이름 : ApplyInfo* Apply::createApplyInfo(const char* SSN)
    기능	  : 일반 회원이 채용 정보에 지원하여 지원정보 등록
    전달 인자 : const char* SSN 
    반환값    : ApplyInfo* - 생성된 지원 정보 객체 포인터
*/
ApplyInfo* Apply::createApplyInfo(const char* SSN)
{
    NormalMember* normalMember = pMemberList->getNormalMember(); // 현재 로그인해있는 일반 회원 찾아서 반환
   
    JobAd* jobAdBySSN = getJobAdDetail(SSN); // 입력받은 SSN으로 일치하는 회사를 찾는 getJobAdDetail 함수 호출, 반환되는 채용 정보 jobAdBySSN에 저장
    jobAdBySSN->addApplicantCount(); // 해당 채용 정보의 지원자수 + 1
    normalMember->addApplyInfo(jobAdBySSN->getName(), jobAdBySSN->getSSN(), jobAdBySSN->getTask(), jobAdBySSN->getNumberOfMember(), jobAdBySSN->getDeadLine());
    // 채용 정보의 회사 이름, 사업자 번호, 업무, 인원수, 마감일 받아와서 일반 회원의 지원정보 등록, 일반 회원의 지원 정보 리스트에 추가
    
    return normalMember->getApplyInfoList()->getApplyInfoDetail();
    // 생성한 지원 정보 객체 포인터 반환
}


//Apply

/*
    함수 이름 : char* CheckApplyInfo::getApplyInfoList()
    기능	  : 일반 회원이 등록한 지원 정보 리스트의 문자열 반환
    전달 인자 : 없음
    반환값    : char* - 일반 회원이 등록한 지원 정보 리스트의 문자열
*/
char* CheckApplyInfo::getApplyInfoList()
{
    NormalMember* normalMember = pMemberList->getNormalMember(); // 현재 로그인 중인 일반 회원 객체 포인터
    ApplyInfoList *applyInfoList= normalMember->getApplyInfoList(); // 일반 회원이 등록한 지원 정보 리스트 
    return applyInfoList->getApplyInfoString(); // 지원 정보 리스트를 문자열로 변환하여 반환하는 함수 호출
}
//CheckApplyInfo

/*
    함수 이름 : JobAd* CancelApplyInfo::getJobAdDetail(const char* SSN)
    기능	  : SSN으로 회사 회원을 찾고, 회사 회원이 올린 채용 정보 반환
    전달 인자 : const char* SSN
    반환값    : JobAd* - 회사 회원이 올린 채용 정보
*/
JobAd* CancelApplyInfo::getJobAdDetail(const char* SSN)
{
    CompanyMember* companyMember = pMemberList->findBySSN(SSN); // SSN으로 찾은 회사 회원 객체
    return companyMember->getJobList()->getJobAdDetail(); // 회사 회원이 등록한 채용 정보 반환
}

/*
    함수 이름 : const char* CancelApplyInfo::getCancelApplyInfo(const char* SSN)
    기능	  : SSN으로 채용 정보를 찾아 해당 채용 정보의 지원자 수를 줄이고, 일반 회원의 지원 정보 리스트에서 SSN으로 지원 정보를 찾아 해당 지원 정보 삭제, 지원 취소
    전달 인자 : const char* SSN
    반환값    : const char* - 지원 취소하는 지원 정보의 문자열
*/
const char* CancelApplyInfo::getCancelApplyInfo(const char* SSN)
{
    NormalMember* normalMember = pMemberList->getNormalMember(); // 현재 로그인 중인 일반 회원 객체 포인터
    JobAd* jobAdBySSN=this->getJobAdDetail(SSN); // 전달 받은 SSN으로 찾은 채용 정보
    jobAdBySSN->removeApplicantCount(); // 해당 채용 정보의 지원자 수 줄임

    ApplyInfoList* applyInfoList = normalMember->getApplyInfoList(); // 일반 회원이 가지고 있는 지원 정보 리스트 
    ApplyInfo * applyInfo=applyInfoList->findBySSN(SSN); // 해당 지원 정보 리스트에서 SSN으로 취소 할 지원 정보 찾음
    
    const char* name = applyInfo->getName(); // 회사 이름
    const char* ssn = applyInfo->getSSN(); // 사업자 번호
    const char* task = applyInfo->getTask(); // 업무
    size_t totalLength = strlen(name) + strlen(ssn) + strlen(task) + 3; 
    char* result = new char[totalLength];
    strcpy(result, name);
    strcat(result, " ");
    strcat(result, ssn);
    strcat(result, " ");
    strcat(result, task);
    strcat(result, "\n");
    // 문자열을 반환하기 위해 문자열 처리 
    
    applyInfoList->deleteApply(applyInfo); // 지원 정보 삭제(지원 취소)

    return result;
}
//CancelApplyInfo

/*
    함수 이름 : const char* ApplyStatistics::getApplicantCount()
    기능	  : 회사 회원의 지원정보 통계(업무 별 지원자 수) 출력을 위한 문자열 반환
    전달 인자 : 없음
    반환값    : const char* - 회사 회원의 지원정보 통계(업무 별 지원자 수) 문자열
*/
const char* ApplyStatistics::getApplicantCount()
{
    CompanyMember* companyMember = pMemberList->getCompanyMember();
    JobAdList* jobAdList = companyMember->getJobList(); //job ad list
    JobAd* jobAd = jobAdList->getJobAdDetail();
    const char* task = jobAd->getTask();

    int applicantCount = jobAd->getApplicantCount();
    char applicantCountStr[20];
    _itoa(applicantCount, applicantCountStr, 10); // 정수를 문자열로 변환

    size_t totalLength = strlen(applicantCountStr) + strlen(task) + 3;
    char* result = new char[totalLength];

    strcpy(result, task);
    strcat(result, " ");
    strcat(result, applicantCountStr);
    strcat(result, "\n");
    return result;
}
/*
    함수 이름 : const char* ApplyStatistics::getApplyCount() 
    기능	  : 일반 회원의 지원정보 통계(업무 별 지원횟수) 출력을 위한 문자열 반환
    전달 인자 : 없음
    반환값    : const char* -일반 회원의 지원정보 통계(업무 별 지원횟수) 문자열
*/
const char* ApplyStatistics::getApplyCount() 
{
    NormalMember* normalMember = pMemberList->getNormalMember();
    ApplyInfoList* applyInfoList = normalMember->getApplyInfoList();
    return applyInfoList->getApplyTaskCount(); 
}
/*
    함수 이름 : const char* ApplyStatistics::getStatistics()
    기능	  : 지원정보 통계 출력을 위한 문자열 반환
    전달 인자 : 없음
    반환값    : const char* - 일반 회원, 회사 회원 별 지원정보 통계 문자열
*/
const char* ApplyStatistics::getStatistics()
{
    
    Member* currentMember = pMemberList->findLogInMember(); // 현재 로그인 된 회원 객체 포인터 
    if (currentMember->getMemberType() == 1) // 현재 로그인 된 회원 객체의 type이 1이라면 회사 회원, 아니라면 일반 회원
    {
        return this->getApplicantCount(); // 회사 회원이라면 getApplicantCount 함수 호출하여 회사 회원의 지원 정보 통계 문자열 반환
    }
    else //일반 회원
    {
        return this->getApplyCount(); // 일반 회원이라면 getApplyCount 함수 호출하여 일반 회원의 지원 정보 통계 문자열 반환
    }

}
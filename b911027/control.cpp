#include "control.h"


Join::Join(): pMemberList(memberList) 
{
}

void Join::createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password) {
    Member* newMember = nullptr;
    if (member_type == 1) {
        newMember = new CompanyMember(name, SSN, ID, password);
        cout << "회사회원 생성" << endl;


        // 회사 회원 객체 생성 및 처리
    }
    else {
        newMember = new NormalMember(name, SSN, ID, password);
        // 일반 회원 객체 생성 및 처리
        cout << "일반회원 생성" << endl;
    }

    pMemberList->addMember(newMember);
    pMemberList->showMember();//테스트

}
//Join
LogIn::LogIn() : pMemberList(memberList)
{

}
Member* LogIn::logIn(const char* ID, const char* password)
{

    Member* member = pMemberList->findMember(ID, password);
    member->setIsLogin(true);
//    pMemberList->showMember();
    return member;
}
//LogIn
LogOut::LogOut() : pMemberList(memberList)
{

}

char* LogOut::logOut()
{
    char* ID = new char[MAX_STRING];
    Member* member = pMemberList->findLogInMember();
    member->setIsLogin(false);
    strncpy(ID, member->getID(), MAX_STRING - 1);
    pMemberList->showMember();
    return ID;
}
//LogOut
DeleteMembership::DeleteMembership() : pMemberList(memberList)
{
    
}
char* DeleteMembership::deleteMember()
{
    char* ID = new char[MAX_STRING];
    Member* member = pMemberList->getMember();
    strncpy(ID, member->getID(), MAX_STRING - 1);
    pMemberList->deleteMember(member);
    pMemberList->showMember();
    return ID;
}
//DeleteMembership

AddJobAd::AddJobAd(): pMemberList(memberList)
{
 
}
void AddJobAd::createJobAd(const char* task, int numberOfMember, const char* deadline)
{
    //Member* loggedInMember = pMemberList->findLogInMember();
    //회사 회원이 맞다면 형변환 한다
    //if (loggedInMember->getMemberType() == 1)
    //{
//		CompanyMember* companyMember = dynamic_cast<CompanyMember*>(loggedInMember);
	//	companyMember->addJobAd(task, numberOfMember, deadline);
	//}
    CompanyMember* companyMember = pMemberList->getCompanyMember();
    companyMember->addJobAd(task, numberOfMember, deadline);
}
//AddJobAd
ListJobAd::ListJobAd():pMemberList(memberList)
{
     
}
JobAdList* ListJobAd::getJobAdList()
{
    //현재 memberlist에 있고 로그인 중인 company member가 등록한 채용 정보를 return한다
    CompanyMember* companyMember = pMemberList->getCompanyMember();
    return companyMember->getJobList();
}
//ListJobAd
SearchJob::SearchJob() :pMemberList(memberList)
{

}
JobAdList* SearchJob::searchJob(const char* name) //회사 이름으로 검색
{
    CompanyMember* companyMember = pMemberList->findByName(name); //회사이름으로 companymember 찾아서 반환
    return companyMember->getJobList(); //회사이름 ssn 포함해서 출력
}
//SearchJob
Apply::Apply() :pMemberList(memberList)
{

}

ApplyInfo* Apply::createApplyInfo(const char* SSN)
{
    NormalMember* normalMember = pMemberList->getNormalMember(); //현재 로그인해있는 normal member찾는다
   
    JobAd* jobAdBySSN = getJobAdDetail(SSN); //입력받은 SSN으로 해당되는 채용 정보를 찾는다
    jobAdBySSN->addApplicantCount(); //채용정보의 지원자수 +1
    normalMember->addApplyInfo(jobAdBySSN->getName(), jobAdBySSN->getSSN(), jobAdBySSN->getTask(), jobAdBySSN->getNumberOfMember(), jobAdBySSN->getDeadLine());
    //지원정보 생성 완료, 지원정보 리스트에 추가 완료
    cout << "지원 정보 생성 완료" << endl;
    return normalMember->getApplyInfoList()->getApplyInfoDetail();
    // ApplyInfo* newApplyInfo = new ApplyInfo(); //지원 정보 생성 은  normal member가 해야지

}

JobAd* Apply::getJobAdDetail(const char* SSN)
{
    CompanyMember* companyMember = pMemberList->findBySSN(SSN);
    return companyMember->getJobList()->getJobAdDetail();
    

}

//Apply

CheckApplyInfo::CheckApplyInfo() :pMemberList(memberList)
{
}
ApplyInfoList* CheckApplyInfo::getApplyInfoList()
{
    NormalMember* normalMember = pMemberList->getNormalMember();
    return normalMember->getApplyInfoList();
}
//Check

CancelApplyInfo::CancelApplyInfo() :pMemberList(memberList)
{

}

JobAd* CancelApplyInfo::getJobAdDetail(const char* SSN)
{
    CompanyMember* companyMember = pMemberList->findBySSN(SSN);
    return companyMember->getJobList()->getJobAdDetail();

}

const char* CancelApplyInfo::cancelApply(const char* SSN)
{
    NormalMember* normalMember = pMemberList->getNormalMember();
    //현재 로그인 한 일반 회원
    //지원 정보 리스트에서 SSN을 찾는다
    // 
    //SSN가지고 회사 회원 찾는다, 회사회원이 등록한 채용 정보 찾는다, getJobAdDetail(SSN) 
    // 
    //채용정보의 지원자 수 --
    JobAd* jobAdBySSN=this->getJobAdDetail(SSN);
    jobAdBySSN->removeApplicantCount();
    

    //현재 로그인 한 일반 회원 찾는다
    ApplyInfoList* applyInfoList = normalMember->getApplyInfoList();
    //일반 회원이 가지고 있는 지원 정보 리스트
    ApplyInfo * applyInfo=applyInfoList->findBySSN(SSN);
  
    //지원 정보 리스트에서 SSN으로 지울 지원 정보 찾는다
  


    const char* name = applyInfo->getName();
    const char* ssn = applyInfo->getSSN();
    const char* task = applyInfo->getTask();
    size_t totalLength = strlen(name) + strlen(ssn) + strlen(task) + 3; // +3은 공백과 개행 문자를 포함한 길이입니다.
    char* result = new char[totalLength];

    strcpy(result, name);
    strcat(result, " ");
    strcat(result, ssn);
    strcat(result, " ");
    strcat(result, task);
    strcat(result, "\n");
    
    
    //삭제
    applyInfoList->deleteApply(applyInfo);

    return result;

//    resultStr += applyInfo->getName();
 //   resultStr += " ";
 //   resultStr += applyInfo->getSSN();
  //  resultStr += " ";
   // resultStr += applyInfo->getTask();

  //char* result = resultStr.c_str();
    //return result;


    //지울 지원 정보의 회사이름, 사업자번호, 업무 문자열 반환한다*/


}
//CancelApplyInfo

ApplyStatistics::ApplyStatistics() :pMemberList(memberList)
{

}

const char* ApplyStatistics::getApplicantCount()
{
    CompanyMember* companyMember = pMemberList->getCompanyMember();
    JobAdList* jobAdList = companyMember->getJobList(); //job ad list
    JobAd* jobAd = jobAdList->getJobAdDetail();
    const char* task = jobAd->getTask();
    const char* applicantCount = to_string(jobAd->getApplicantCount()).c_str();
    size_t totalLength = strlen(applicantCount) + strlen(task) + 3;
    char* result = new char[totalLength];

    strcpy(result, task);
    strcat(result, " ");
    strcat(result, applicantCount);
    strcat(result, "\n");
    return result;
}
const char* ApplyStatistics::getApplyCount() 
{
    return "a";
}

    //NormalMember* normalMember = pMemberList->getNormalMember();
    //applylist돌면서 출력해야할듯
    //ApplyInfoList* applyInfoList = normalMember->getApplyInfoList();
    //map<const char*, int> taskCountMap;
    //for (ApplyInfo* applyInfo : applyInfoList)
    //{
//
  //  }
   
const char* ApplyStatistics::getStatistics()
{
    //회사 회원이라면 업무, 지원자 수 출력
    
    Member* currentMember = pMemberList->findLogInMember();
    if (currentMember->getMemberType() == 1) //회사 회원
    {
        return this->getApplicantCount();
    }
    else //일반 회원
    {
        return this->getApplyCount();
    }

    //일반 회원이라면 업무, 지원 횟수 출력
    //다른 회사의 같은 업무에 각각 지원했다면 더해서 출력
    //applylist에서 업무 기준으로 정렬..?
}
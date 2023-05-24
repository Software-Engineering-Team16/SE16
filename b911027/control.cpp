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

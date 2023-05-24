#include "control.h"


Join::Join(): pMemberList(memberList) 
{
}

void Join::createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password) {
    Member* newMember = nullptr;
    if (member_type == 1) {
        newMember = new CompanyMember(name, SSN, ID, password);
        cout << "ȸ��ȸ�� ����" << endl;


        // ȸ�� ȸ�� ��ü ���� �� ó��
    }
    else {
        newMember = new NormalMember(name, SSN, ID, password);
        // �Ϲ� ȸ�� ��ü ���� �� ó��
        cout << "�Ϲ�ȸ�� ����" << endl;
    }

    pMemberList->addMember(newMember);
    pMemberList->showMember();//�׽�Ʈ

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
    //ȸ�� ȸ���� �´ٸ� ����ȯ �Ѵ�
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
    //���� memberlist�� �ְ� �α��� ���� company member�� ����� ä�� ������ return�Ѵ�
    CompanyMember* companyMember = pMemberList->getCompanyMember();
    return companyMember->getJobList();
}
//ListJobAd
SearchJob::SearchJob() :pMemberList(memberList)
{

}
JobAdList* SearchJob::searchJob(const char* name) //ȸ�� �̸����� �˻�
{
    CompanyMember* companyMember = pMemberList->findByName(name); //ȸ���̸����� companymember ã�Ƽ� ��ȯ
    return companyMember->getJobList(); //ȸ���̸� ssn �����ؼ� ���
}
//SearchJob
Apply::Apply() :pMemberList(memberList)
{

}

ApplyInfo* Apply::createApplyInfo(const char* SSN)
{
    NormalMember* normalMember = pMemberList->getNormalMember(); //���� �α������ִ� normal memberã�´�
   
    JobAd* jobAdBySSN = getJobAdDetail(SSN); //�Է¹��� SSN���� �ش�Ǵ� ä�� ������ ã�´�

    jobAdBySSN->addApplicantCount(); //ä�������� �����ڼ� +1
    normalMember->addApplyInfo(jobAdBySSN->getName(), jobAdBySSN->getSSN(), jobAdBySSN->getTask(), jobAdBySSN->getNumberOfMember(), jobAdBySSN->getDeadLine());
    //�������� ���� �Ϸ�, �������� ����Ʈ�� �߰� �Ϸ�
    cout << "���� ���� ���� �Ϸ�" << endl;
    return normalMember->getApplyInfoList()->getApplyInfoDetail();
    // ApplyInfo* newApplyInfo = new ApplyInfo(); //���� ���� ���� ��  normal member�� �ؾ���

}

JobAd* Apply::getJobAdDetail(const char* SSN)
{
    CompanyMember* companyMember = pMemberList->findBySSN(SSN);
    return companyMember->getJobList()->getJobAdDetail();
    

}

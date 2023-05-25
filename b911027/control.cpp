#include "control.h"

/*
    �Լ� �̸� : void Join::createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password) 
    ���	  : ���ڷ� ���� ������ ������ member_type�� �����Ͽ� Member ��ü�� ����
    ���� ���� : int member_type, const char* name, const char* SSN, const char* ID, const char* password
    ��ȯ��    : ����
*/
void Join::createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password) 
{
    Member* newMember = nullptr;
    // member_type�� 1�̸� ȸ�� ȸ�� ����, 2�� �Ϲ� ȸ�� ����
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
    �Լ� �̸� : Member* LogIn::logIn(const char* ID, const char* password)
    ���	  : ���ڷ� ���� ID, ��й�ȣ�� ������ ID�� ��й�ȣ�� ��ġ�ϴ� Member ��ü ã�Ƽ� login ���¸� true�� �ٲ��ְ�, �α��� �� Member ��ü ������ ��ȯ
    ���� ���� : const char* ID, const char* password
    ��ȯ��    : �α��� �� Member ��ü ������
*/
Member* LogIn::logIn(const char* ID, const char* password)
{
    Member* member = pMemberList->findMember(ID, password);
    member->setIsLogin(true);
    return member;
}
//LogIn
/*
    �Լ� �̸� : char* LogOut::logOut()
    ���	  : ���� �α��� �� Member ��ü ã�Ƽ� login ���¸� false�� �ٲ��ְ�, �α׾ƿ��� Member ��ü�� ID ���ڿ� ��ȯ
    ���� ���� : ����
    ��ȯ��    : char* - �α׾ƿ� �� Member ID ���ڿ�
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
    �Լ� �̸� : char* DeleteMembership::deleteMember()
    ���	  : ���� �α��� �� Member ��ü ã�Ƽ� ID ���ڿ� ���� �� ��ü�� MemberList���� ����(Ż��)
    ���� ���� : ����
    ��ȯ��    : Ż���� Member ��ü�� ID ���ڿ�
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
    �Լ� �̸� : void AddJobAd::createJobAd(const char* task, int numberOfMember, const char* deadline)
    ���	  : �α��� �� ȸ�� ȸ���� ä������ ���
    ���� ���� : const char* task, int numberOfMember, const char* deadline
    ��ȯ��    : ����
*/
void AddJobAd::createJobAd(const char* task, int numberOfMember, const char* deadline)
{
    CompanyMember* companyMember = pMemberList->getCompanyMember(); // �α��� �� ȸ�� ȸ�� ��ü
    companyMember->addJobAd(task, numberOfMember, deadline); // ȸ�� ȸ�� ��ü�� ���޵� ���� ������ ä�� ���� ���
}
//AddJobAd
/*
    �Լ� �̸� : char* ListJobAd::getJobAd()
    ���	  : ȸ�� ȸ���� ����� ä�� ������ ���ڿ��� ��ȯ
    ���� ���� : ����
    ��ȯ��    : char* - ä�� ���� ���ڿ�
*/
char* ListJobAd::getJobAd()
{
    CompanyMember* companyMember = pMemberList->getCompanyMember(); // �α��� �� ȸ�� ȸ�� ��ü
    JobAd * jobAd= companyMember->getJobList()->getJobAdDetail(); // ȸ�� ȸ�� ��ü�� ������ �ִ� ä�� ���� ����Ʈ���� ä�� ���� ��ȯ
    return jobAd->getJobAdString(); // ä�� ������ ���ڿ��� ��ȯ
}
//ListJobAd

/*
    �Լ� �̸� : char* SearchJob::searchJob(const char* name) 
    ���	  : �Ϲ� ȸ���� ȸ�� �̸����� �˻��Ͽ� �ش� �Ǵ� ȸ�� ȸ���� ����� ä�� ���� ���ڿ� ��ȯ
    ���� ���� : const char* name - ȸ�� �̸�
    ��ȯ��    : char* - �˻� ����� ���� ä�� ���� ���ڿ�
*/
char* SearchJob::searchJob(const char* name) 
{
    CompanyMember* companyMember = pMemberList->findByName(name); // ȸ�� �̸����� ã�� ȸ�� ȸ�� ��ü
    JobAd* jobAd= companyMember->getJobList()->getJobAdDetail(); // ȸ�� ȸ�� ��ü�� ������ �ִ� ä�� ���� ����Ʈ���� ä�� ���� ��ȯ
    return jobAd->getSearchResult(); // ä�� ������ ���ڿ��� ��ȯ
}
//SearchJob

/*
    �Լ� �̸� : JobAd* Apply::getJobAdDetail(const char* SSN)
    ���	  : SSN���� ȸ�� ȸ���� ã��, ȸ�� ȸ���� �ø� ä�� ���� ��ȯ
    ���� ���� : const char* SSN
    ��ȯ��    : JobAd* - ȸ�� ȸ���� �ø� ä�� ����
*/
JobAd* Apply::getJobAdDetail(const char* SSN)
{
    CompanyMember* companyMember = pMemberList->findBySSN(SSN); // SSN���� ã�� ȸ�� ȸ�� ��ü
    return companyMember->getJobList()->getJobAdDetail(); // ȸ�� ȸ���� ����� ä�� ���� ��ȯ
}
/*
    �Լ� �̸� : ApplyInfo* Apply::createApplyInfo(const char* SSN)
    ���	  : �Ϲ� ȸ���� ä�� ������ �����Ͽ� �������� ���
    ���� ���� : const char* SSN 
    ��ȯ��    : ApplyInfo* - ������ ���� ���� ��ü ������
*/
ApplyInfo* Apply::createApplyInfo(const char* SSN)
{
    NormalMember* normalMember = pMemberList->getNormalMember(); // ���� �α������ִ� �Ϲ� ȸ�� ã�Ƽ� ��ȯ
   
    JobAd* jobAdBySSN = getJobAdDetail(SSN); // �Է¹��� SSN���� ��ġ�ϴ� ȸ�縦 ã�� getJobAdDetail �Լ� ȣ��, ��ȯ�Ǵ� ä�� ���� jobAdBySSN�� ����
    jobAdBySSN->addApplicantCount(); // �ش� ä�� ������ �����ڼ� + 1
    normalMember->addApplyInfo(jobAdBySSN->getName(), jobAdBySSN->getSSN(), jobAdBySSN->getTask(), jobAdBySSN->getNumberOfMember(), jobAdBySSN->getDeadLine());
    // ä�� ������ ȸ�� �̸�, ����� ��ȣ, ����, �ο���, ������ �޾ƿͼ� �Ϲ� ȸ���� �������� ���, �Ϲ� ȸ���� ���� ���� ����Ʈ�� �߰�
    
    return normalMember->getApplyInfoList()->getApplyInfoDetail();
    // ������ ���� ���� ��ü ������ ��ȯ
}


//Apply

/*
    �Լ� �̸� : char* CheckApplyInfo::getApplyInfoList()
    ���	  : �Ϲ� ȸ���� ����� ���� ���� ����Ʈ�� ���ڿ� ��ȯ
    ���� ���� : ����
    ��ȯ��    : char* - �Ϲ� ȸ���� ����� ���� ���� ����Ʈ�� ���ڿ�
*/
char* CheckApplyInfo::getApplyInfoList()
{
    NormalMember* normalMember = pMemberList->getNormalMember(); // ���� �α��� ���� �Ϲ� ȸ�� ��ü ������
    ApplyInfoList *applyInfoList= normalMember->getApplyInfoList(); // �Ϲ� ȸ���� ����� ���� ���� ����Ʈ 
    return applyInfoList->getApplyInfoString(); // ���� ���� ����Ʈ�� ���ڿ��� ��ȯ�Ͽ� ��ȯ�ϴ� �Լ� ȣ��
}
//CheckApplyInfo

/*
    �Լ� �̸� : JobAd* CancelApplyInfo::getJobAdDetail(const char* SSN)
    ���	  : SSN���� ȸ�� ȸ���� ã��, ȸ�� ȸ���� �ø� ä�� ���� ��ȯ
    ���� ���� : const char* SSN
    ��ȯ��    : JobAd* - ȸ�� ȸ���� �ø� ä�� ����
*/
JobAd* CancelApplyInfo::getJobAdDetail(const char* SSN)
{
    CompanyMember* companyMember = pMemberList->findBySSN(SSN); // SSN���� ã�� ȸ�� ȸ�� ��ü
    return companyMember->getJobList()->getJobAdDetail(); // ȸ�� ȸ���� ����� ä�� ���� ��ȯ
}

/*
    �Լ� �̸� : const char* CancelApplyInfo::getCancelApplyInfo(const char* SSN)
    ���	  : SSN���� ä�� ������ ã�� �ش� ä�� ������ ������ ���� ���̰�, �Ϲ� ȸ���� ���� ���� ����Ʈ���� SSN���� ���� ������ ã�� �ش� ���� ���� ����, ���� ���
    ���� ���� : const char* SSN
    ��ȯ��    : const char* - ���� ����ϴ� ���� ������ ���ڿ�
*/
const char* CancelApplyInfo::getCancelApplyInfo(const char* SSN)
{
    NormalMember* normalMember = pMemberList->getNormalMember(); // ���� �α��� ���� �Ϲ� ȸ�� ��ü ������
    JobAd* jobAdBySSN=this->getJobAdDetail(SSN); // ���� ���� SSN���� ã�� ä�� ����
    jobAdBySSN->removeApplicantCount(); // �ش� ä�� ������ ������ �� ����

    ApplyInfoList* applyInfoList = normalMember->getApplyInfoList(); // �Ϲ� ȸ���� ������ �ִ� ���� ���� ����Ʈ 
    ApplyInfo * applyInfo=applyInfoList->findBySSN(SSN); // �ش� ���� ���� ����Ʈ���� SSN���� ��� �� ���� ���� ã��
    
    const char* name = applyInfo->getName(); // ȸ�� �̸�
    const char* ssn = applyInfo->getSSN(); // ����� ��ȣ
    const char* task = applyInfo->getTask(); // ����
    size_t totalLength = strlen(name) + strlen(ssn) + strlen(task) + 3; 
    char* result = new char[totalLength];
    strcpy(result, name);
    strcat(result, " ");
    strcat(result, ssn);
    strcat(result, " ");
    strcat(result, task);
    strcat(result, "\n");
    // ���ڿ��� ��ȯ�ϱ� ���� ���ڿ� ó�� 
    
    applyInfoList->deleteApply(applyInfo); // ���� ���� ����(���� ���)

    return result;
}
//CancelApplyInfo

/*
    �Լ� �̸� : const char* ApplyStatistics::getApplicantCount()
    ���	  : ȸ�� ȸ���� �������� ���(���� �� ������ ��) ����� ���� ���ڿ� ��ȯ
    ���� ���� : ����
    ��ȯ��    : const char* - ȸ�� ȸ���� �������� ���(���� �� ������ ��) ���ڿ�
*/
const char* ApplyStatistics::getApplicantCount()
{
    CompanyMember* companyMember = pMemberList->getCompanyMember();
    JobAdList* jobAdList = companyMember->getJobList(); //job ad list
    JobAd* jobAd = jobAdList->getJobAdDetail();
    const char* task = jobAd->getTask();

    int applicantCount = jobAd->getApplicantCount();
    char applicantCountStr[20];
    _itoa(applicantCount, applicantCountStr, 10); // ������ ���ڿ��� ��ȯ

    size_t totalLength = strlen(applicantCountStr) + strlen(task) + 3;
    char* result = new char[totalLength];

    strcpy(result, task);
    strcat(result, " ");
    strcat(result, applicantCountStr);
    strcat(result, "\n");
    return result;
}
/*
    �Լ� �̸� : const char* ApplyStatistics::getApplyCount() 
    ���	  : �Ϲ� ȸ���� �������� ���(���� �� ����Ƚ��) ����� ���� ���ڿ� ��ȯ
    ���� ���� : ����
    ��ȯ��    : const char* -�Ϲ� ȸ���� �������� ���(���� �� ����Ƚ��) ���ڿ�
*/
const char* ApplyStatistics::getApplyCount() 
{
    NormalMember* normalMember = pMemberList->getNormalMember();
    ApplyInfoList* applyInfoList = normalMember->getApplyInfoList();
    return applyInfoList->getApplyTaskCount(); 
}
/*
    �Լ� �̸� : const char* ApplyStatistics::getStatistics()
    ���	  : �������� ��� ����� ���� ���ڿ� ��ȯ
    ���� ���� : ����
    ��ȯ��    : const char* - �Ϲ� ȸ��, ȸ�� ȸ�� �� �������� ��� ���ڿ�
*/
const char* ApplyStatistics::getStatistics()
{
    
    Member* currentMember = pMemberList->findLogInMember(); // ���� �α��� �� ȸ�� ��ü ������ 
    if (currentMember->getMemberType() == 1) // ���� �α��� �� ȸ�� ��ü�� type�� 1�̶�� ȸ�� ȸ��, �ƴ϶�� �Ϲ� ȸ��
    {
        return this->getApplicantCount(); // ȸ�� ȸ���̶�� getApplicantCount �Լ� ȣ���Ͽ� ȸ�� ȸ���� ���� ���� ��� ���ڿ� ��ȯ
    }
    else //�Ϲ� ȸ��
    {
        return this->getApplyCount(); // �Ϲ� ȸ���̶�� getApplyCount �Լ� ȣ���Ͽ� �Ϲ� ȸ���� ���� ���� ��� ���ڿ� ��ȯ
    }

}
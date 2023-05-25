#include "entity.h"

/*
	�Լ� �̸� : Member::MemberMember::Member(int member_type, const char* name, const char* SSN, const char* ID, const char* password)
	���	  : ���� ���� ������ ȸ�� ��ü �ʱ�ȭ�ϰ� ����
	���� ���� : int member_type, const char* name, const char* SSN, const char* ID, const char* password
	��ȯ��    : ����
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
	�Լ� �̸� : void Member::setIsLogin(bool value)
	���	  : ȸ���� �α��� ����(isLogin)�� ����, ���޹��� value ���� ���� �α��� ���¸� ����
	���� ���� : bool value-> true: �α���, false: �α��� x
	��ȯ��    : ����
*/
void Member::setIsLogin(bool value)
{
	if (value)
		this->isLogin = true;
	else
		this->isLogin = false;
}
/*
	�Լ� �̸� : NormalMember::NormalMember(const char* name, const char* SSN, const char* ID, const char* password)
	���	  : �θ� Ŭ������ Member�� �����ڸ� ȣ���Ͽ� ȸ�� ��ü�� �ʱ�ȭ, ������ �Ϲ� ȸ�� ��ü�� ApplyInfoList�� ����Ű�� ������ applyList�� �����Ͽ� �ʱ�ȭ
	���� ���� : int member_type, const char* name, const char* SSN, const char* ID, const char* password
	��ȯ��    : ����
*/
NormalMember::NormalMember(const char* name, const char* SSN, const char* ID, const char* password)
	: Member(2, name, SSN, ID, password)
{
	applyList = new ApplyInfoList();	// �ش� �Ϲ� ȸ���� ������ ���� ���� �����ϴ� ���� ���� ����Ʈ

}
/*
	�Լ� �̸� : CompanyMember::CompanyMember(const char* name, const char* SSN, const char* ID, const char* password)
	���	  : �θ� Ŭ������ Member�� �����ڸ� ȣ���Ͽ� ȸ�� ��ü�� �ʱ�ȭ, ������ ȸ�� ȸ�� ��ü�� JobAdLit�� ����Ű�� ������ jobList�� �����Ͽ� �ʱ�ȭ
	���� ���� : int member_type, const char* name, const char* SSN, const char* ID, const char* password
	��ȯ��    : ����
*/
CompanyMember::CompanyMember(const char* name, const char* SSN, const char* ID, const char* password)
	: Member(1, name, SSN, ID, password)
{
	jobList = new JobAdList();	// �ش� ȸ�� ȸ���� ����� ä�� ���� �����ϴ� ä�� ���� ����Ʈ
}
/*
	�Լ� �̸� : void MemberList::addMember(Member* member)
	���	  : Member ��ü�� MemberList�� �߰�
	���� ���� : Member* member-�߰��� ��� ��ü�� ������
	��ȯ��    : ����
*/
// Member
void MemberList::addMember(Member* member)
{
	membersList.push_back(member);
}
/*
	�Լ� �̸� : void MemberList::deleteMember(Member* member)
	���	  : MemberList���� Member ��ü ����
	���� ���� : Member* member-������ ��� ��ü�� ������
	��ȯ��    : ����
*/
void MemberList::deleteMember(Member* member)
{
	auto it = std::find(membersList.begin(), membersList.end(), member); // memberList���� ���޹��� member ��ü ã��
	if (it != membersList.end()) {
		membersList.erase(it);		// ã�� ��� ��ü�� memberList���� ����
		delete member; // ��� ��ü�� �޸� ����
	}
}
/*
	�Լ� �̸� : Member* MemberList::findMember(const char* ID, const char* password)
	���	  : ���� ���� ID, PW�� ��ġ�ϴ� Member ��ü ã�Ƽ� ������ ��ȯ
	���� ���� : const char * ID, const char * password
	��ȯ��    : ã�� Member ��ü ������
*/
Member* MemberList::findMember(const char* ID, const char* password) {
	
	if (membersList.empty())	// membersList�� ����ִ� ���
	{
		cout << "empty" << endl;
	}	
	else {	// memberList�� ������� ���� ��� membersList�� ��ȸ�ϸ鼭 ID�� PW ���ϸ鼭 ID, PW�� ��ġ�ϴ� ��� ��ü ������ ã��
		for (Member* member : membersList) {
			if (strcmp(member->getID(), ID) == 0 && strcmp(member->getPassword(), password) == 0) {
				return member;
			}
		}
	}
	return nullptr;
}
/*
	�Լ� �̸� : Member* MemberList::findLogInMember()
	���	  : ���� �α��� ���°� true�� Member ��ü ã�Ƽ� ������ ��ȯ
	���� ���� : ����
	��ȯ��    : ã�� Member ��ü ������
*/
Member* MemberList::findLogInMember()
{
	if (membersList.empty())
	{
		cout << "empty" << endl;
	}
	else { // memberList�� ������� ���� ��� membersList�� ��ȸ�ϸ鼭 �α��� ���°� true�� ��ü ������ ã��
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
	�Լ� �̸� : CompanyMember* MemberList::getCompanyMember()
	���	  : ���� �α��� ���°� true�� CompanyMember ��ü ������ ��ȯ
	���� ���� : ����
	��ȯ��    : ã�� CompnayMember ��ü ������
*/
CompanyMember* MemberList::getCompanyMember()
{
	// membersList�� ������� ���� ��� membersList�� ��ȸ�ϸ鼭 �α��� ���°� true�� ȸ�� ��ü ������ ã��
	for (Member* member : membersList)
	{
		if (member->getMemberType() == 1&&member->getIsLogin()==true) // membertype�� ȸ�� ȸ���̰� ���� �α��� ������ Ȯ��
		{
			return dynamic_cast<CompanyMember*>(member);	// ã�� ȸ�� ��ü ������ CompanyMember�� �ٿ�ĳ����
		}
	}
}
/*
	�Լ� �̸� : NormalMember* MemberList::getNormalMember()
	���	  : ���� �α��� ���°� true�� NormalMember ��ü ������ ��ȯ
	���� ���� : ����
	��ȯ��    : ã�� NormalMember ��ü ������ 
*/
NormalMember* MemberList::getNormalMember()
{
	// membersList�� ������� ���� ��� membersList�� ��ȸ�ϸ鼭 �α��� ���°� true�� ȸ�� ��ü ������ ã��
	for (Member* member : membersList)
	{
		if (member->getMemberType() == 2 &&member->getIsLogin()==true) // membertype�� �Ϲ� ȸ���̰� ���� �α��� ������ Ȯ��
		{
			return dynamic_cast<NormalMember*>(member);	// ã�� ȸ�� ��ü ������ NormalMember�� �ٿ�ĳ����
		}
	}
}
/*
	�Լ� �̸� : CompanyMember* MemberList::findByName(const char * name)
	���	  : �̸��� ��ġ�ϴ� CompanyMember ��ü ������ ����
	���� ���� : const char* name
	��ȯ��    : ã�� CompanyMember ������
*/
CompanyMember* MemberList::findByName(const char * name)
{
	for (Member* member : membersList)
	{
		if (strcmp(member->getName(), name) == 0)
		{
			// membersList�� ��ȸ�ϸ鼭 �̸��� ��ġ�ϴ� ����� ã���� �� �ش� ��� CompanyMember�� �ٿ�ĳ���� �Ͽ� ��ȯ
			return dynamic_cast<CompanyMember*>(member);
		}
	}
}
/*
	�Լ� �̸� : CompanyMember* MemberList::findBySSN(const char* SSN)
	���	  : SSN�� ��ġ�ϴ� CompanyMember ��ü ������ ����
	���� ���� : const char* SSN
	��ȯ��    : ã�� CompanyMember ������
*/
CompanyMember* MemberList::findBySSN(const char* SSN)
{
	for (Member* member : membersList)
	{
		if (strcmp(member->getSSN(), SSN) == 0)
		{
			// membersList�� ��ȸ�ϸ鼭 SSN�� ��ġ�ϴ� ����� ã���� �� �ش� ��� CompanyMember�� �ٿ�ĳ���� �Ͽ� ��ȯ
			return dynamic_cast<CompanyMember*>(member);
		}
	}
}
//Member List

/*
	�Լ� �̸� : void CompanyMember::addJobAd(const char* task, int numberOfMember, const char* deadline)
	���	  : �Է� ���� ���� ������ ä�� ���� �����ϰ� CompanyMember�� ������ �ִ� jobList�� ä�� ���� �߰�
	���� ���� : const char* task, int numberOfMember, const char* deadline
	��ȯ��    : ����
*/
void CompanyMember::addJobAd(const char* task, int numberOfMember, const char* deadline)
{
	JobAd* newJobAd = new JobAd(this->getName(), this->getSSN(), task, numberOfMember, deadline);	// �Է¹��� ���� ������ JobAd ����
	jobList->addJob(newJobAd);	// ������ JobAd�� CompanyMember�� jobList�� �߰�
}
//CompanyMember

/*
	�Լ� �̸� : void NormalMember::addApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline)
	���	  : �Է� ���� ���� ������ ���� ���� ��� �ϰ� NormalMember�� ������ �ִ� applyList�� ���� ���� �߰�
	���� ���� : const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline
	��ȯ��    : ����
*/
void NormalMember::addApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline)
{
	ApplyInfo* newApplyInfo = new ApplyInfo(companyName, SSN, task, numberOfMember, deadline);
	// �Է¹��� ���� ������ applyinfo ����
	applyList->addApply(newApplyInfo);	// ������ applyInfo�� NormalMember�� applyList�� �߰�
}
//NormalMember

/*
	�Լ� �̸� : JobAd::JobAd(const char* companyName, const char* SSN, const char*task ,int numberOfMember, const char* deadline)
	���	  : ���� ���� ������ ä�� ���� ��ü �ʱ�ȭ�ϰ� ����
	���� ���� : const char* companyName, const char* SSN, const char*task ,int numberOfMember, const char* deadline
	��ȯ��    : ����
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
//ä�� ���� JobAd

/*
	�Լ� �̸� : void JobAdList::addJob(JobAd* jobAd)
	���	  : ä�� ���� ����Ʈ(����)�� ä�� ���� �߰� 
	���� ���� : JobAd* jobAd - �߰��Ϸ��� ä�� ���� ������
	��ȯ��    : ����
*/
void JobAdList::addJob(JobAd* jobAd)
{
	jobList.push_back(jobAd);
}

/*
	�Լ� �̸� : char* JobAd::getJobAdString()
	���	  : ȸ�� ȸ���� ä�� ������ ����ϱ� ���� ä�� ������ ���ڿ��� ��ȯ�ϴ� �Լ�
	���� ���� : ����
	��ȯ��    : char* - ��¿� ä�� ���� ���ڿ�(����, �ο���, ����)
*/
char* JobAd::getJobAdString()
{
	string resultStr; // ��ȯ�� ���ڿ� string

	// JobAd ��ü���� ������ ������ ��� ���ڿ��� �߰�
	resultStr += this->getTask();	// ����
	resultStr += " ";
	resultStr += to_string(this->getNumberOfMember());	// �ο��� 
	resultStr += " ";
	resultStr += this->getDeadLine();	// ������
	resultStr += "\n";

	char* resultChar = new char[resultStr.size() + 1]; // char* �迭�� ���� �Ҵ�
	strcpy(resultChar, resultStr.c_str()); // string�� char*�� ��ȯ
	return resultChar;
}
/*
	�Լ� �̸� : char* JobAd::getSearchResult()
	���	  : �Ϲ� ȸ���� ȸ�簡 ����� ä�� ������ �˻��� ����� ����ϱ� ���� ä�� ������ ���ڿ��� ��ȯ�ϴ� �Լ�
	���� ���� : ����
	��ȯ��    : char* - �˻� ��� ��¿� ä�� ���� ���ڿ�(ȸ�� �̸�, ����ڹ�ȣ, ����, �ο���, ����)
*/
char* JobAd::getSearchResult()
{
	string resultStr; // ��ȯ�� ���ڿ�
	
	// JobAd ��ü���� ������ ������ ��� ���ڿ��� �߰�
	resultStr += this->getName(); // ȸ�� �̸�
	resultStr += " ";
	resultStr += this->getSSN(); // ����ڹ�ȣ
	resultStr += " ";
	resultStr += this->getJobAdString(); // ���� �ο��� ������

	char* resultChar = new char[resultStr.size() + 1]; // char* �迭�� ���� �Ҵ�
	strcpy(resultChar, resultStr.c_str()); // string�� char*�� ��ȯ

	return resultChar;
}

//JobAdList
/*
	�Լ� �̸� : ApplyInfo::ApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline)
	���	  : ���� ���� ������ ���� ���� ��ü �ʱ�ȭ�ϰ� ����
	���� ���� :	const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline
	��ȯ��    : ����
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
	�Լ� �̸� : void ApplyInfoList::addApply(ApplyInfo* applyInfo)
	���	  : ���� ���� ����Ʈ(����)�� ���� ���� �߰�
	���� ���� : ApplyInfo* applyInfo - �߰��Ϸ��� ���� ���� ������
	��ȯ��    : ����
*/
//ApplyInfo
 void ApplyInfoList::addApply(ApplyInfo* applyInfo)
{
	applyList.push_back(applyInfo);
}
/*
	 �Լ� �̸� : void ApplyInfoList::deleteApply(ApplyInfo* applyInfo)
	 ���	  :  ���� ���� ����Ʈ(����)���� Ư�� ���� ���� ����
	 ���� ���� : ApplyInfo* applyInfo - �����Ϸ��� ���� ���� ������
	 ��ȯ��    : ����
*/
void ApplyInfoList::deleteApply(ApplyInfo* applyInfo)
{
	auto it = std::find(applyList.begin(), applyList.end(),applyInfo); // applyList���� ���޹��� applyInfo ã�� 
	if (it != applyList.end()) {
		applyList.erase(it); // ã�� ���� ���� ��ü�� applyList���� ����
		delete applyInfo; // ���� ���� ��ü�� �޸� ����
	}
}
/*
	�Լ� �̸� :	char * ApplyInfoList::getApplyInfoString()
	���	  : �Ϲ� ȸ���� ���� ������ ����ϱ� ���� �ڽ��� ������ ���� ������ ���ڿ��� ��ȯ�ϴ� �Լ�
	���� ���� : ����
	��ȯ��    : char* - ��¿� ���� ���� ���ڿ� (ȸ���̸� ����ڹ�ȣ ���� �ο� �� ��û������)
*/
char * ApplyInfoList::getApplyInfoString()
{
	//> { [ȸ���̸�] [����ڹ�ȣ] [����] [�ο� ��] [��û������] }*
	string resultStr; // ��ȯ�� ���ڿ� string
	for (ApplyInfo* applyInfo : applyList)	
	{
		// applyList�� ��ȸ�ϸ� ApplyInfo ��ü���� ������ ������ ��� ���ڿ��� �߰�	
		resultStr += applyInfo->getName(); // �̸� 
		resultStr += " ";
		resultStr += applyInfo->getSSN(); // ����� ��ȣ
		resultStr += " ";
		resultStr += applyInfo->getTask(); // ����
		resultStr += " ";
		resultStr += to_string(applyInfo->getNumberOfMember()); // �ο���
		resultStr += " ";
		resultStr += applyInfo->getDeadLine(); // ������
		resultStr += "\n";
	}

	char* resultChar = new char[resultStr.size() + 1]; // char* �迭�� ���� �Ҵ�
	strcpy(resultChar, resultStr.c_str()); // string�� char*�� ��ȯ

	return resultChar;

}
/*
	�Լ� �̸� :	char* ApplyInfoList::getApplyTaskCount()
	���	  : �Ϲ� ȸ���� ���� ���� ���(���� ����Ƚ��)�� ����ϱ� ���� ���� ���� ��踦 ���ڿ��� ��ȯ�ϴ� �Լ�
	���� ���� : ����
	��ȯ��    : char* - ��¿� ���� ���� ��� ���ڿ� (������ ����Ƚ��)
*/
char* ApplyInfoList::getApplyTaskCount()
{
	// {[������][����Ƚ��]}
	string resultStr; // ��ȯ�� ���ڿ� string
	map<string, int> taskCountMap; // �� ������ ����Ƚ�� �����ϴ� map ��ü

	for (ApplyInfo* applyInfo : applyList)
	{
		const char* task = applyInfo->getTask(); 
		string taskStr(task); // �� applyInfo ��ü���� ���� �����ͼ� taskStr�� ����

		if (taskCountMap.find(taskStr) == taskCountMap.end())	 
		{
			// ���ο� task�� ��� �ش� ������ ���� Ƚ�� 1�� ����
			taskCountMap[taskStr] = 1;
		}
		else
		{
			// �̹� �ִ� task�� ��� �ش� ������ ���� Ƚ�� �߰�
			taskCountMap[taskStr]++;
		}
	}

	// taskCountMap�� ��ȸ�ϸ鼭 ���� �̸��� �ش� ������ ���� Ƚ�� resultStr�� �߰�
	for (const auto& entry : taskCountMap)
	{
		resultStr += entry.first;
		resultStr += " ";
		resultStr += std::to_string(entry.second);
		resultStr += "\n";
	}

	char* resultChar = new char[resultStr.size() + 1]; // char* �迭�� ���� �Ҵ�
	strcpy(resultChar, resultStr.c_str()); // string�� char*�� ��ȯ

	return resultChar;
}

/*
	�Լ� �̸� :	ApplyInfo* ApplyInfoList::findBySSN(const char *SSN)
	���	  : applyList���� SSN�� ��ġ�ϴ� ���� ���� ã�� ���� ���� ������ ��ȯ
	���� ���� : const char *SSN 
	��ȯ��    : ã�� ���� ���� ������ 
*/
ApplyInfo* ApplyInfoList::findBySSN(const char *SSN)
{
	for (ApplyInfo* applyInfo : applyList)
	{
		if (strcmp(applyInfo->getSSN(), SSN) == 0)
		{
			return applyInfo; // SSN�� ��ġ�ϴ� �������� ã���� �� ���� ���� ��ȯ
		}
	}
}
//ApplyInfo List


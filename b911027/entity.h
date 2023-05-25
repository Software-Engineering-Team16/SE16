#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define MAX_STRING 32

// Ŭ���� ����
class Member;
class NormalMember;
class CompanyMember;
class MemberList;
class ApplyInfo;
class ApplyInfoList;
class JobAd;
class JobAdList;

// Member(ȸ��) Ŭ���� ����
class Member
{
private:
	int member_type;			// 1�̸� ȸ��ȸ��, 2�� �Ϲ�ȸ��
	char name[MAX_STRING];		// �̸�
	char SSN[MAX_STRING];		// ȸ�� ȸ���̸� ����� ��ȣ, �Ϲ� ȸ���̸� �ֹι�ȣ
	char ID[MAX_STRING];		// ID
	char password[MAX_STRING];	// ��й�ȣ
	bool isLogin = false;		// �α��� ����

public:
	Member(int member_type, const char* name, const char* SSN, const char* ID, const char* password); // ������
	virtual ~Member() {};	// �Ҹ���
	int getMemberType() { return member_type; };
	const char* getName() { return name; };
	const char* getSSN() { return SSN; };
	const char* getID() { return ID; };
	const char* getPassword() { return password; };
	bool getIsLogin() { return isLogin; };
	void setIsLogin(bool value);	// �α��� �� ���� ��ȭ
};

// Member�� ��� ���� NormalMember(�Ϲ� ȸ��) Ŭ���� ����
class NormalMember : public Member
{
private:
	ApplyInfoList* applyList; // ���� ���� ����Ʈ ������
public:
	NormalMember(const char* name, const char* SSN, const char* ID, const char* password);	// ������
	~NormalMember() { delete applyList; }	// �Ҹ���. applyList �޸𸮿��� ����
	void addApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline);	// ä�� ���� �� ���� ���� ���
	ApplyInfoList* getApplyInfoList() { return applyList; };	// ������ �ִ� ���� ���� ����Ʈ ������ ��ȯ
};

// Member�� ��� ���� CompanyMember(ȸ�� ȸ��) Ŭ���� ����
class CompanyMember : public Member
{
private:
	JobAdList* jobList;	// ä�� ���� ����Ʈ ������
public:
	CompanyMember(const char* name, const char* SSN, const char* ID, const char* password);	// ������
	~CompanyMember() { delete jobList; };	// �Ҹ���, jobList �޸𸮿��� ����
	void addJobAd(const char* task, int numberOfMember, const char* deadline);	// ä�� ���� ���
	JobAdList* getJobList() { return jobList; };	// ������ �ִ� ä�� ���� ����Ʈ ������ ��ȯ
};

//  MemberList Ŭ���� ����
class MemberList
{
private:
	vector<Member*> membersList;	// ȸ�� �����ϱ� ���� Member ������ ���� 
public:
	void addMember(Member* member); // ���Ϳ� ȸ�� �߰�
	void deleteMember(Member* member); // ���Ϳ��� ȸ�� ����
	Member* findMember(const char* ID, const char* password); // ID�� PW ��ġ�ϴ� ȸ�� ã�Ƽ� ȸ�� ������ ��ȯ
	Member* findLogInMember(); // �α��� �� ȸ�� ������ ��ȯ
//	Member* getMember(); //���� �������� �߰��� ȸ�� ������ ��ȯ
	CompanyMember* getCompanyMember(); // �α��� �� ȸ�� ȸ�� ������ ��ȯ
	NormalMember* getNormalMember(); // �α��� �� �Ϲ� ȸ�� ������ ��ȯ
	CompanyMember* findByName(const char* name); // �̸����� ȸ�� ȸ�� ã�Ƽ� ȸ�� ȸ�� ������ ��ȯ
	CompanyMember* findBySSN(const char* SSN); // ����� ��ȣ�� ȸ��ȸ�� ã�Ƽ� ȸ�� ȸ�� ������ ��ȯ
	
};

// ApplyInfo(���� ����) Ŭ���� ����
class ApplyInfo
{
private:
	char companyName[MAX_STRING];	// ȸ�� �̸�
	char SSN[MAX_STRING];			// ����� ��ȣ
	char task[MAX_STRING];			// ����
	int numberOfMember;				// �ο���
	char deadline[MAX_STRING];		// ������
public:
	ApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline);	//������
	~ApplyInfo() {};
	const char* getName() { return companyName; };	
	const char* getSSN() { return SSN; };
	const char* getTask() { return task; };
	int getNumberOfMember() { return numberOfMember; };
	const char* getDeadLine() { return deadline; };
};

// ApplyInfoList(���� ���� ����Ʈ) Ŭ���� ����
class ApplyInfoList 
{
private:
	vector <ApplyInfo*> applyList; // ���� ������ �����ϱ� ���� ApplyInfo ������ ���� 
public:
	void addApply(ApplyInfo* applyInfo); // ���Ϳ� ���� ���� �߰�
	void deleteApply(ApplyInfo* applyInfo); // ���Ϳ��� ���� ���� ����
	ApplyInfo* getApplyInfoDetail() { return applyList.back(); };	// ���� �ֱٿ� ��ϵ� ���������� ������ ��ȯ
	char* getApplyInfoString();	// ���� ���� ���ڿ� ��ȯ
	ApplyInfo* findBySSN(const char * SSN);	// SSN���� ���� ���� ã�Ƽ� �ش�Ǵ� ���� ���� ������ ��ȯ
	char* getApplyTaskCount(); // ������ ����Ƚ�� ���ڿ� ��ȯ
};

// JobAd(ä�� ����) Ŭ���� ����
class JobAd
{
private:
	char companyName[MAX_STRING];	// ȸ�� �̸�
	char SSN[MAX_STRING];			// SSN
	char task[MAX_STRING];			// ����
	int numberOfMember;				// �ο��� 
	char deadline[MAX_STRING];		// ������
	int applicantCount=0;			// ������ �� 
public:
	JobAd(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline); // ������
	~JobAd() {}; //�Ҹ���
	const char* getName() { return companyName; };
	const char* getSSN() { return SSN; };
	const char* getTask() { return task; };
	int getNumberOfMember() { return numberOfMember; };
	const char* getDeadLine() { return deadline; };
	void addApplicantCount() { applicantCount++; }; // �Ϲ� ȸ���� �ش� ä�� ������ �������� �� �����ڼ� ++
	void removeApplicantCount() { applicantCount--; }; // �Ϲ� ȸ���� �ش� ä�� ������ ������ �� ������� �� �����ڼ� --
	int getApplicantCount() { return applicantCount; }; // �����ڼ� ��ȯ
	char* getJobAdString(); // ä�� ���� ���ڿ��� ��ȯ (���� ,�ο���, ������)
	char* getSearchResult(); //�˻� ��� ���ڿ��� ��ȯ (ȸ�� �̸�, SSN, ����, �ο��� , ������)	
};

// JobAdList(ä�� ���� ����Ʈ) Ŭ���� ����
class JobAdList
{
private:
	vector<JobAd*> jobList;	// ä�� ������ �����ϱ� ���� JobAd ������ ����
public:
	void addJob(JobAd* jobAd); // ����Ʈ�� ä�� ���� �߰�
	JobAd* getJobAdDetail() { return jobList.back(); }; // JobAd ��ȯ
};

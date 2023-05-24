#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define MAX_STRING 32

class Member;
class NormalMember;
class CompanyMember;
class MemberList;
class ApplyInfo;
class ApplyInfoList;
class JobAd;
class JobAdList;

//ȸ�� Member
class Member
{
private:
	int member_type; //1�̸� ȸ��ȸ��, 2�� �Ϲ�ȸ��
	char name[MAX_STRING];
	char SSN[MAX_STRING];
	char ID[MAX_STRING];
	char password[MAX_STRING];
	bool isLogin = false;

public:
	Member(int member_type, const char* name, const char* SSN, const char* ID, const char* password); //������
	int getMemberType() { return member_type; };
	const char* getName() { return name; };
	const char* getSSN() { return SSN; };
	const char* getID() { return ID; };
	const char* getPassword() { return password; };
	bool getIsLogin() { return isLogin; };
	void setIsLogin(bool value);
	virtual ~Member();
};
class NormalMember : public Member
{
private:
	ApplyInfoList* applyList; //���� ���� ����Ʈ ������
public:
	NormalMember(const char* name, const char* SSN, const char* ID, const char* password);
	void addApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline);
	~NormalMember();
	ApplyInfoList* getApplyInfoList() { return applyList; };
};
class CompanyMember : public Member
{
private:
	JobAdList* jobList; //ä�� ���� ����Ʈ ������
public:
	CompanyMember(const char* name, const char* SSN, const char* ID, const char* password);
	~CompanyMember();
	void addJobAd(const char* task, int numberOfMember, const char* deadline);
	JobAdList* getJobList() { return jobList; };
};

//��� ����Ʈ
class MemberList
{
private:
	vector<Member*> membersList;
public:
	void addMember(Member* member); //����Ʈ�� member �߰�
	void deleteMember(Member* member); //����Ʈ���� member ����
	void showMember(); //�׽�Ʈ��
	Member* findMember(const char* ID, const char* password); //ID�� PW�� ȸ�� ã��
	Member* findLogInMember(); //�α��� �� ȸ�� ������ ��ȯ
	Member* getMember(); //���� �������� �߰��� ȸ�� ��ȯ
	CompanyMember* getCompanyMember(); //�α��� �� ȸ��ȸ�� ������ ��ȯ
	NormalMember* getNormalMember(); //�α��� �� �Ϲ�ȸ�� ������ ��ȯ
	CompanyMember* findByName(const char* name);
	CompanyMember* findBySSN(const char* SSN);
	
};

//���� ���� ApplyInfo-ȸ���̸� ����ڹ�ȣ ���� �ο��� ��û������
class ApplyInfo
{
private:
	char companyName[MAX_STRING]; //ȸ�� �̸�
	char SSN[MAX_STRING]; //����� ��ȣ
	char task[MAX_STRING]; //����
	int numberOfMember; //�ο���
	char deadline[MAX_STRING]; //������
public:
	ApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline);
	const char* getName() { return companyName; };
	const char* getSSN() { return SSN; };
	const char* getTask() { return task; };
	int getNumberOfMember() { return numberOfMember; };
	const char* getDeadLine() { return deadline; };
	~ApplyInfo() {};
};

//���� ���� ����Ʈ<-�� �Ϲ� ȸ�� ��ü���� �Ҵ�
class ApplyInfoList 
{
private:
	vector <ApplyInfo*> applyList;
	int applyCount; //���� Ƚ��
public:
	void addApply(ApplyInfo* applyInfo); //����Ʈ�� ���� ���� �߰�
	void deleteApply(ApplyInfo* applyInfo); //����Ʈ�� ä�� ���� ����
	ApplyInfo* getApplyInfoDetail() { return applyList.back(); };
	char* getApplyInfo();//���� ���� ���ڿ� ��ȯ
	ApplyInfo* findBySSN(const char * SSN);
	//���� ���� ����Ʈ���� ����
};

//ä�� ���� JobAd -���� �ο��� ��û ������
class JobAd
{
private:
	char companyName[MAX_STRING]; //ȸ�� �̸�
	char SSN[MAX_STRING]; //SSN
	char task[MAX_STRING]; //����
	int numberOfMember; //�ο��� 
	char deadline[MAX_STRING]; //������
	int applicantCount=0; //������ �� 
public:
	JobAd(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline);
	const char* getName() { return companyName; };
	const char* getSSN() { return SSN; };
	const char* getTask() { return task; };
	int getNumberOfMember() { return numberOfMember; };
	const char* getDeadLine() { return deadline; };
	void addApplicantCount() { applicantCount++; }; //�����ڼ�(�������� ���� ���� �� ++)
	void removeApplicantCount() { applicantCount--; };
	int getApplicantCount() { return applicantCount; }; //�����ڼ� ��ȯ
	~JobAd() {}; //�Ҹ���

};

//ä�� ���� ����Ʈ<-�� �Ϲ� ȸ�� ��ü���� �Ҵ�
class JobAdList
{
private:
	vector<JobAd*> jobList;
	//int numOfJobAd=jobList.size(); //jobList�� ����
public:
	int getNumOfJobAd() { return jobList.size(); };
	void addJob(JobAd* jobAd); //����Ʈ�� ä�� ���� �߰�
	void deleteJob(JobAd* jobAd); //����Ʈ�� ä�� ���� ����
	//void showJobAdList();
	//void getJobList();
	char* getSearchResult(); //�˻� ��� ��ȯ (ȸ�� �̸�, SSN ����)
	char* getJobAd(); //jobAd ���ڿ� ��ȯ
	JobAd* getJobAdDetail() { return jobList.back(); };
};

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
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
	int getMemberType();
	const char* getName();
	const char* getSSN();
	const char* getID();
	const char* getPassword();
	bool getIsLogin();
	void setIsLogin(bool value);
	virtual ~Member();
};
class NormalMember : public Member
{
private:
	ApplyInfoList* applyList; //���� ���� ����Ʈ ������
public:
	NormalMember(const char* name, const char* SSN, const char* ID, const char* password);
	~NormalMember();
};
class CompanyMember : public Member
{
private:
	JobAdList* jobList; //ä�� ���� ����Ʈ ������
public:
	CompanyMember(const char* name, const char* SSN, const char* ID, const char* password);
	~CompanyMember();
	void addJobAd(const char* task, int numberOfMember, const char* deadline);
	JobAdList* getJobList();
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
	Member* findMember(const char* ID, const char* password);
	Member* findLogInMember();
	Member* getMember();
	CompanyMember* getCompanyMember();
	NormalMember* getNormalMember();
};

//���� ���� ApplyInfo-ȸ���̸� ����ڹ�ȣ ���� �ο��� ��û������
class ApplyInfo
{
private:
	char name[MAX_STRING]; //ȸ�� �̸�
	char SSN[MAX_STRING]; //����� ��ȣ
	char task[MAX_STRING]; //����
	int numberOfMember;
	char deadline[MAX_STRING]; //������
public:
	const char* getName();
	const char* getSSN();
	const char* getTask();
	int getNumberOfMember();
	const char* getDeadline();
};

//���� ���� ����Ʈ<-�� �Ϲ� ȸ�� ��ü���� �Ҵ�
class ApplyInfoList 
{
private:
	vector <ApplyInfo*> applyList;
public:
	void addApply(ApplyInfo* applyInfo); //����Ʈ�� ���� ���� �߰�
	void deleteApply(ApplyInfo* applyInfo); //����Ʈ�� ä�� ���� ����
};

//ä�� ���� JobAd -���� �ο��� ��û ������
class JobAd
{
private:
	
	char task[MAX_STRING];
	int numberOfMember; //�ο��� 
	char deadline[MAX_STRING]; //������
public:
	JobAd(const char* task, int numberOfMember, const char* deadline);
	const char* getTask();
	int getNumberOfMember();
	const char* getDeadLine();
	~JobAd(); //�Ҹ���

};

//ä�� ���� ����Ʈ<-�� �Ϲ� ȸ�� ��ü���� �Ҵ�
class JobAdList
{
private:
	vector<JobAd*> jobList;
	int numOfJobAd; //jobList�� ����
public:
	int getNumOfJobAd();
	void addJob(JobAd* jobAd); //����Ʈ�� ä�� ���� �߰�
	void deleteJob(JobAd* jobAd); //����Ʈ�� ä�� ���� ����
	//void showJobAdList();
	char* getJobAd(); //jobAd��ȯ
};

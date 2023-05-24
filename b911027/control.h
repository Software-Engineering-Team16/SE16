#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "entity.h"
extern MemberList* memberList;
//ȸ�� ����
class Join
{
private:
	MemberList* pMemberList=memberList;
public:
	Join();
	void createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password);
};

//�α���
class LogIn
{
private:
	MemberList* pMemberList = memberList;
public:
	LogIn();
	Member* logIn(const char* ID, const char* password);
};

//�α׾ƿ�
class LogOut
{
private:
	MemberList* pMemberList = memberList;
public:
	LogOut();
	char* logOut();
};

//ȸ�� Ż��
class DeleteMembership
{
private:
	MemberList* pMemberList = memberList;
public:
	DeleteMembership();
	char* deleteMember();
};

//ä������ ���
class AddJobAd
{
private:
	MemberList* pMemberList = memberList;
public:
	AddJobAd();
	void createJobAd(const char* task, int numberOfMember, const char* deadline ); //ä�� ���� ����

};

//ä������ ����Ʈ ��ȸ
class ListJobAd //CheckJobAdList
{
private:
	MemberList* pMemberList = memberList;
public:
	ListJobAd();
	JobAdList* getJobAdList();
};



//ä�� ���� �˻�
class SearchJob
{
private:
	MemberList* pMemberList = memberList;
public:
	SearchJob();
	JobAdList* searchJob(const char* name); //ȸ�� �̸����� ä������ ã��
};

//ä�� ����
class Apply
{
private:
	MemberList* pMemberList = memberList;
public:
	Apply();
	ApplyInfo* createApplyInfo(const char *SSN); //SSN���� ä�� ���� ã��
	JobAd* getJobAdDetail(const char* SSN);
};

//���� ���� ��ȸ
class CheckApplyInfo
{
private:
	MemberList* pMemberList = memberList;
public:
	CheckApplyInfo();
	ApplyInfoList* getApplyInfoList();
};
//���� ���
class CancelApplyInfo
{
private:
	MemberList* pMemberList = memberList;
public:
	CancelApplyInfo();
	JobAd* getJobAdDetail(const char* SSN);
	const char* cancelApply(const char *SSN); //����� ���� ������ ���ڿ� ��ȯ
};

//���� ���� ���
class ApplyStatistics
{
private:
	MemberList* pMemberList = memberList;
public:
	ApplyStatistics();
	const char* getStatistics();
	const char* getApplicantCount();
	const char* getApplyCount();
};

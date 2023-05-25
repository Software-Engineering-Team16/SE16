#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "entity.h"

// ���� ���� MemberList ����
extern MemberList* memberList;

// Join Ŭ���� ����
class Join
{
private:
	MemberList* pMemberList=memberList;
public:
	Join() {};
	void createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password); // ȸ�� ��ü ����
};

// LogIn Ŭ���� ����
class LogIn
{
private:
	MemberList* pMemberList = memberList;
public:
	LogIn() {};
	Member* logIn(const char* ID, const char* password); // �α��� �� ȸ�� ��ü ������ ��ȯ
};

// LogOut Ŭ���� ����
class LogOut
{
private:
	MemberList* pMemberList = memberList;
public:
	LogOut() {};
	char* logOut(); // �α׾ƿ� �� ȸ�� ��ü�� ID ��ȯ
};

// DelelteMembership Ŭ���� ����
class DeleteMembership
{
private:
	MemberList* pMemberList = memberList;
public:
	DeleteMembership() {};
	char* deleteMember(); // Ż���� ȸ�� ��ü�� ID ��ȯ
};

// AddJobAd Ŭ���� ����
class AddJobAd
{
private:
	MemberList* pMemberList = memberList;
public:
	AddJobAd() {};
	void createJobAd(const char* task, int numberOfMember, const char* deadline ); // ä�� ���� ����
};

// ListJobAd Ŭ���� ����
class ListJobAd 
{
private:
	MemberList* pMemberList = memberList;
public:
	ListJobAd() {};
	char* getJobAd(); // ȸ�� ȸ���� ����� ä�� ���� ���ڿ� ��ȯ
};



// SearchJob Ŭ���� ����
class SearchJob
{
private:
	MemberList* pMemberList = memberList;
public:
	SearchJob() {};
	char* searchJob(const char* name); // ȸ�� �̸����� ä������ ã�Ƽ� ä�� ���� ���ڿ� ��ȯ
};

// Apply Ŭ���� ����
class Apply
{
private:
	MemberList* pMemberList = memberList;
public:
	Apply() {};
	ApplyInfo* createApplyInfo(const char *SSN); // ���� ���� �����Ͽ� ������ ���� ���� ��ȯ
	JobAd* getJobAdDetail(const char* SSN); // SSN���� ä�� ���� ã�Ƽ� ä�� ���� ��ȯ
};

// CheckApplyInfo Ŭ���� ����
class CheckApplyInfo
{
private:
	MemberList* pMemberList = memberList;
public:
	CheckApplyInfo() {};
	char* getApplyInfoList(); // �Ϲ� ȸ���� ����� ���� ���� ����Ʈ ���ڿ� ��ȯ
};

// CancelApplyInfo Ŭ���� ����
class CancelApplyInfo
{
private:
	MemberList* pMemberList = memberList;
public:
	CancelApplyInfo() {};
	JobAd* getJobAdDetail(const char* SSN); // ���� ����� ä�� ���� ��ȯ 
	const char* getCancelApplyInfo(const char *SSN); // ���� ����� ���� ���� ���ڿ� ��ȯ
};

// ApplyStatistics Ŭ���� ����
class ApplyStatistics
{
private:
	MemberList* pMemberList = memberList;
public:
	ApplyStatistics() {};	
	const char* getStatistics(); // ���� ���� ��� ���ڿ� ��ȯ
	const char* getApplicantCount(); // ȸ�� ȸ���� ���� ���� ��� ��ȯ 
	const char* getApplyCount(); // �Ϲ� ȸ���� ���� ���� ��� ��ȯ
};

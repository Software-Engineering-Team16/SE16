#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "control.h"

// ���� ���� ����
extern FILE* in_fp;
extern FILE* out_fp;
extern MemberList* memberList;


// JoinUI Ŭ���� ����
class JoinUI 
{
private:
	Join* pJoin;

public:
	JoinUI() { pJoin = new Join(); };
	void createNewMember(); 
};

// LogInUI Ŭ���� ����
class LogInUI 
{
private:
	LogIn* pLogIn;

public:
	LogInUI() { pLogIn = new LogIn(); };
	void inputIDPW();  
};

// LogOutUI Ŭ���� ����
class LogOutUI 
{
private:
	LogOut* pLogOut;

public:
	LogOutUI() { pLogOut = new LogOut(); };
	void logOut();
};

// DeleteMembershipUI Ŭ���� ����
class DeleteMembershipUI 
{
private:
	DeleteMembership* pDeleteMembership;
public: 
	DeleteMembershipUI() { pDeleteMembership = new DeleteMembership(); };
	void deleteMembership();
};

// AddJobAdUI Ŭ���� ����
class AddJobAdUI
{
private:
	AddJobAd* pAddJobAd; 
public:
	AddJobAdUI() { pAddJobAd = new AddJobAd(); };
	void addJobAd();
};

// ListJobAdUI Ŭ���� ����
class ListJobAdUI 
{
private: 
	ListJobAd* pListJobAd;
public:
	ListJobAdUI() { pListJobAd = new ListJobAd(); };
	void viewListJobAd();
};


// SearchJobUI Ŭ���� ����
class SearchJobUI
{
private:
	SearchJob* pSearchJob;
public:
	SearchJobUI() { pSearchJob = new SearchJob(); };
	void searchJobAd();
};

// ApplyUI Ŭ���� ����
class ApplyUI
{
private:
	Apply* pApply;
public:
	ApplyUI() { pApply = new Apply(); };
	void apply();
};

// CheckApplyInfoUI Ŭ���� ����
class CheckApplyInfoUI
{
private:
	CheckApplyInfo* pCheckApplyInfo;
public:
	CheckApplyInfoUI() { pCheckApplyInfo = new CheckApplyInfo(); };
	void checkApplyInfo();
	
};
// CancelApplyInfoUI Ŭ���� ����
class CancelApplyInfoUI
{
private:
	CancelApplyInfo* pCancelApplyInfo;
public:
	CancelApplyInfoUI() { pCancelApplyInfo = new CancelApplyInfo(); };
	void cancelApply();
};

// ApplyStatisticsUI Ŭ���� ����
class ApplyStatisticsUI
{
private:
	ApplyStatistics* pApplyStatistics;
public:
	ApplyStatisticsUI() { pApplyStatistics = new ApplyStatistics(); };
	void showStatistics();
};

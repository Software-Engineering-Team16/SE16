#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "control.h"

// 전역 변수 선언
extern FILE* in_fp;
extern FILE* out_fp;
extern MemberList* memberList;


// JoinUI 클래스 정의
class JoinUI 
{
private:
	Join* pJoin;

public:
	JoinUI() { pJoin = new Join(); };
	void createNewMember(); 
};

// LogInUI 클래스 정의
class LogInUI 
{
private:
	LogIn* pLogIn;

public:
	LogInUI() { pLogIn = new LogIn(); };
	void inputIDPW();  
};

// LogOutUI 클래스 정의
class LogOutUI 
{
private:
	LogOut* pLogOut;

public:
	LogOutUI() { pLogOut = new LogOut(); };
	void logOut();
};

// DeleteMembershipUI 클래스 정의
class DeleteMembershipUI 
{
private:
	DeleteMembership* pDeleteMembership;
public: 
	DeleteMembershipUI() { pDeleteMembership = new DeleteMembership(); };
	void deleteMembership();
};

// AddJobAdUI 클래스 정의
class AddJobAdUI
{
private:
	AddJobAd* pAddJobAd; 
public:
	AddJobAdUI() { pAddJobAd = new AddJobAd(); };
	void addJobAd();
};

// ListJobAdUI 클래스 정의
class ListJobAdUI 
{
private: 
	ListJobAd* pListJobAd;
public:
	ListJobAdUI() { pListJobAd = new ListJobAd(); };
	void viewListJobAd();
};


// SearchJobUI 클래스 정의
class SearchJobUI
{
private:
	SearchJob* pSearchJob;
public:
	SearchJobUI() { pSearchJob = new SearchJob(); };
	void searchJobAd();
};

// ApplyUI 클래스 정의
class ApplyUI
{
private:
	Apply* pApply;
public:
	ApplyUI() { pApply = new Apply(); };
	void apply();
};

// CheckApplyInfoUI 클래스 정의
class CheckApplyInfoUI
{
private:
	CheckApplyInfo* pCheckApplyInfo;
public:
	CheckApplyInfoUI() { pCheckApplyInfo = new CheckApplyInfo(); };
	void checkApplyInfo();
	
};
// CancelApplyInfoUI 클래스 정의
class CancelApplyInfoUI
{
private:
	CancelApplyInfo* pCancelApplyInfo;
public:
	CancelApplyInfoUI() { pCancelApplyInfo = new CancelApplyInfo(); };
	void cancelApply();
};

// ApplyStatisticsUI 클래스 정읜
class ApplyStatisticsUI
{
private:
	ApplyStatistics* pApplyStatistics;
public:
	ApplyStatisticsUI() { pApplyStatistics = new ApplyStatistics(); };
	void showStatistics();
};

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "entity.h"

// 전역 변수 MemberList 선언
extern MemberList* memberList;

// Join 클래스 정의
class Join
{
private:
	MemberList* pMemberList=memberList;
public:
	Join() {};
	void createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password); // 회원 객체 생성
};

// LogIn 클래스 정의
class LogIn
{
private:
	MemberList* pMemberList = memberList;
public:
	LogIn() {};
	Member* logIn(const char* ID, const char* password); // 로그인 한 회원 객체 포인터 반환
};

// LogOut 클래스 정의
class LogOut
{
private:
	MemberList* pMemberList = memberList;
public:
	LogOut() {};
	char* logOut(); // 로그아웃 한 회원 객체의 ID 반환
};

// DelelteMembership 클래스 정의
class DeleteMembership
{
private:
	MemberList* pMemberList = memberList;
public:
	DeleteMembership() {};
	char* deleteMember(); // 탈퇴한 회원 객체의 ID 반환
};

// AddJobAd 클래스 정의
class AddJobAd
{
private:
	MemberList* pMemberList = memberList;
public:
	AddJobAd() {};
	void createJobAd(const char* task, int numberOfMember, const char* deadline ); // 채용 정보 생성
};

// ListJobAd 클래스 정의
class ListJobAd 
{
private:
	MemberList* pMemberList = memberList;
public:
	ListJobAd() {};
	char* getJobAd(); // 회사 회원이 등록한 채용 정보 문자열 반환
};



// SearchJob 클래스 정의
class SearchJob
{
private:
	MemberList* pMemberList = memberList;
public:
	SearchJob() {};
	char* searchJob(const char* name); // 회사 이름으로 채용정보 찾아서 채용 정보 문자열 반환
};

// Apply 클래스 정의
class Apply
{
private:
	MemberList* pMemberList = memberList;
public:
	Apply() {};
	ApplyInfo* createApplyInfo(const char *SSN); // 지원 정보 생성하여 생성한 지원 정보 반환
	JobAd* getJobAdDetail(const char* SSN); // SSN으로 채용 정보 찾아서 채용 정보 반환
};

// CheckApplyInfo 클래스 정의
class CheckApplyInfo
{
private:
	MemberList* pMemberList = memberList;
public:
	CheckApplyInfo() {};
	char* getApplyInfoList(); // 일반 회원이 등록한 지원 정보 리스트 문자열 반환
};

// CancelApplyInfo 클래스 정의
class CancelApplyInfo
{
private:
	MemberList* pMemberList = memberList;
public:
	CancelApplyInfo() {};
	JobAd* getJobAdDetail(const char* SSN); // 지원 취소할 채용 정보 반환 
	const char* getCancelApplyInfo(const char *SSN); // 지원 취소할 지원 정보 문자열 반환
};

// ApplyStatistics 클래스 정의
class ApplyStatistics
{
private:
	MemberList* pMemberList = memberList;
public:
	ApplyStatistics() {};	
	const char* getStatistics(); // 지원 정보 통계 문자열 반환
	const char* getApplicantCount(); // 회사 회원의 지원 정보 통계 반환 
	const char* getApplyCount(); // 일반 회원의 지원 정보 통계 반환
};

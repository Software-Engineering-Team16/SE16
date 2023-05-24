#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "entity.h"
extern MemberList* memberList;
//회원 가입
class Join
{
private:
	MemberList* pMemberList=memberList;
public:
	Join();
	void createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password);
};

//로그인
class LogIn
{
private:
	MemberList* pMemberList = memberList;
public:
	LogIn();
	Member* logIn(const char* ID, const char* password);
};

//로그아웃
class LogOut
{
private:
	MemberList* pMemberList = memberList;
public:
	LogOut();
	char* logOut();
};

//회원 탈퇴
class DeleteMembership
{
private:
	MemberList* pMemberList = memberList;
public:
	DeleteMembership();
	char* deleteMember();
};

//채용정보 등록
class AddJobAd
{
private:
	MemberList* pMemberList = memberList;
public:
	AddJobAd();
	void createJobAd(const char* task, int numberOfMember, const char* deadline ); //채용 정보 생성

};

//채용정보 리스트 조회
class ListJobAd //CheckJobAdList
{
private:
	MemberList* pMemberList = memberList;
public:
	ListJobAd();
	JobAdList* getJobAdList();
};


//채용정보 상세 조회
class CheckJobAd
{

};

//채용 정보 검색
class SearchJob
{

};

//채용 지원
class Apply
{

};

//지원 정보 조회
class CheckApplyInfo
{

};
//지원 취소
class CancelApplyInfo
{

};

//지원 정보 통계
class ApplyStatistics
{

};

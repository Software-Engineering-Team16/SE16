#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "control.h"
extern FILE* in_fp;
extern FILE* out_fp;
extern MemberList* memberList;


//1.1 회원 가입
class JoinUI 
{
	//포인터 앞에 p 붙이기
private:
	Join* pJoin;

public:
	JoinUI();
	void createNewMember();
};

//2.1 로그인
class LogInUI 
{
private:
	LogIn* pLogIn;

public:
	LogInUI();
	void inputIDPW();  
};

//2.2 로그아웃
class LogOutUI 
{
private:
	LogOut* pLogOut;

public:
	LogOutUI();
	void logOut();
};

//1.2 회원 탈퇴
class DeleteMembershipUI 
{
private:
	DeleteMembership* pDeleteMembership;

public: 
	DeleteMembershipUI();
	void deleteMembership();
};

//채용정보 등록->회사 회원이 등록 3 1 [업무] [인원 수] [신청 마감일] 
class AddJobAdUI
{
private:
	AddJobAd* pAddJobAd; //control 
	//MemberList* pMemberList;
	//JobAdList* pJobAdList; //회사회원의 private member에 넣어야 하는데...
	//applyList는 회사회원의 멤버... 여기서 선언하지 않아도 되지 않나
	//Member* pMember; //로그인 하는 중인 회사 회원 반환 해야함<-전역변수로 하면 되지 않을까...
public:
	AddJobAdUI();
	void addJobAd();
};

//채용정보 리스트 조회->회사 회원이 조회
class ListJobAdUI //CheckJobAdListUI
{
private: 
	//Member* pMember;
	ListJobAd* pListJobAd;
public:
	ListJobAdUI();
	void viewListJobAd();
};

//현재 로그인 한 member은 하나 뿐이다
//하지만 이전에 등록한 채용정보는 검색할 수 있어야 한다

/*
/채용정보 상세 조회
class CheckJobAdUI
{
private: 
	//Member* pMember;
	CheckJobAd* pCheckJobAd;
public:


};
*/

//채용 정보 검색
class SearchJobUI
{

};

//채용 지원
class ApplyUI
{

};

//지원 정보 조회
class CheckApplyInfoUI
{

};
//지원 취소
class CancelApplyInfoUI
{

};

//지원 정보 통계
class ApplyStatisticsUI
{

};

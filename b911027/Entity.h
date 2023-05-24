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

//회원 Member
class Member
{
private:
	int member_type; //1이면 회사회원, 2면 일반회원
	char name[MAX_STRING];
	char SSN[MAX_STRING];
	char ID[MAX_STRING];
	char password[MAX_STRING];
	bool isLogin = false;

public:
	Member(int member_type, const char* name, const char* SSN, const char* ID, const char* password); //생성자
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
	ApplyInfoList* applyList; //지원 정보 리스트 포인터
public:
	NormalMember(const char* name, const char* SSN, const char* ID, const char* password);
	~NormalMember();
};
class CompanyMember : public Member
{
private:
	JobAdList* jobList; //채용 정보 리스트 포인터
public:
	CompanyMember(const char* name, const char* SSN, const char* ID, const char* password);
	~CompanyMember();
	void addJobAd(const char* task, int numberOfMember, const char* deadline);
	JobAdList* getJobList();
};

//멤버 리스트
class MemberList
{
private:
	vector<Member*> membersList;
public:
	void addMember(Member* member); //리스트에 member 추가
	void deleteMember(Member* member); //리스트에서 member 삭제
	void showMember(); //테스트용
	Member* findMember(const char* ID, const char* password);
	Member* findLogInMember();
	Member* getMember();
	CompanyMember* getCompanyMember();
	NormalMember* getNormalMember();
};

//지원 정보 ApplyInfo-회사이름 사업자번호 업무 인원수 신청마감일
class ApplyInfo
{
private:
	char name[MAX_STRING]; //회사 이름
	char SSN[MAX_STRING]; //사업자 번호
	char task[MAX_STRING]; //업무
	int numberOfMember;
	char deadline[MAX_STRING]; //마감일
public:
	const char* getName();
	const char* getSSN();
	const char* getTask();
	int getNumberOfMember();
	const char* getDeadline();
};

//지원 정보 리스트<-각 일반 회원 객체마다 할당
class ApplyInfoList 
{
private:
	vector <ApplyInfo*> applyList;
public:
	void addApply(ApplyInfo* applyInfo); //리스트에 지원 정보 추가
	void deleteApply(ApplyInfo* applyInfo); //리스트에 채용 정보 삭제
};

//채용 정보 JobAd -업무 인원수 신청 마감일
class JobAd
{
private:
	
	char task[MAX_STRING];
	int numberOfMember; //인원수 
	char deadline[MAX_STRING]; //마감일
public:
	JobAd(const char* task, int numberOfMember, const char* deadline);
	const char* getTask();
	int getNumberOfMember();
	const char* getDeadLine();
	~JobAd(); //소멸자

};

//채용 정보 리스트<-각 일반 회원 객체마다 할당
class JobAdList
{
private:
	vector<JobAd*> jobList;
	int numOfJobAd; //jobList의 갯수
public:
	int getNumOfJobAd();
	void addJob(JobAd* jobAd); //리스트에 채용 정보 추가
	void deleteJob(JobAd* jobAd); //리스트에 채용 정보 삭제
	//void showJobAdList();
	char* getJobAd(); //jobAd반환
};

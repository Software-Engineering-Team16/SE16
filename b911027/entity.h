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
	ApplyInfoList* applyList; //지원 정보 리스트 포인터
public:
	NormalMember(const char* name, const char* SSN, const char* ID, const char* password);
	void addApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline);
	~NormalMember();
	ApplyInfoList* getApplyInfoList() { return applyList; };
};
class CompanyMember : public Member
{
private:
	JobAdList* jobList; //채용 정보 리스트 포인터
public:
	CompanyMember(const char* name, const char* SSN, const char* ID, const char* password);
	~CompanyMember();
	void addJobAd(const char* task, int numberOfMember, const char* deadline);
	JobAdList* getJobList() { return jobList; };
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
	Member* findMember(const char* ID, const char* password); //ID와 PW로 회원 찾기
	Member* findLogInMember(); //로그인 한 회원 포인터 반환
	Member* getMember(); //가장 마지막에 추가된 회원 반환
	CompanyMember* getCompanyMember(); //로그인 한 회사회원 포인터 반환
	NormalMember* getNormalMember(); //로그인 한 일반회원 포인터 반환
	CompanyMember* findByName(const char* name);
	CompanyMember* findBySSN(const char* SSN);
	
};

//지원 정보 ApplyInfo-회사이름 사업자번호 업무 인원수 신청마감일
class ApplyInfo
{
private:
	char companyName[MAX_STRING]; //회사 이름
	char SSN[MAX_STRING]; //사업자 번호
	char task[MAX_STRING]; //업무
	int numberOfMember; //인원수
	char deadline[MAX_STRING]; //마감일
public:
	ApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline);
	const char* getName() { return companyName; };
	const char* getSSN() { return SSN; };
	const char* getTask() { return task; };
	int getNumberOfMember() { return numberOfMember; };
	const char* getDeadLine() { return deadline; };
	~ApplyInfo() {};
};

//지원 정보 리스트<-각 일반 회원 객체마다 할당
class ApplyInfoList 
{
private:
	vector <ApplyInfo*> applyList;
	int applyCount; //지원 횟수
public:
	void addApply(ApplyInfo* applyInfo); //리스트에 지원 정보 추가
	void deleteApply(ApplyInfo* applyInfo); //리스트에 채용 정보 삭제
	ApplyInfo* getApplyInfoDetail() { return applyList.back(); };
	char* getApplyInfo();//지원 정보 문자열 반환
	ApplyInfo* findBySSN(const char * SSN);
	//지원 정보 리스트에서 업무
};

//채용 정보 JobAd -업무 인원수 신청 마감일
class JobAd
{
private:
	char companyName[MAX_STRING]; //회사 이름
	char SSN[MAX_STRING]; //SSN
	char task[MAX_STRING]; //업무
	int numberOfMember; //인원수 
	char deadline[MAX_STRING]; //마감일
	int applicantCount=0; //지원자 수 
public:
	JobAd(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline);
	const char* getName() { return companyName; };
	const char* getSSN() { return SSN; };
	const char* getTask() { return task; };
	int getNumberOfMember() { return numberOfMember; };
	const char* getDeadLine() { return deadline; };
	void addApplicantCount() { applicantCount++; }; //지원자수(누군가가 지원 했을 때 ++)
	void removeApplicantCount() { applicantCount--; };
	int getApplicantCount() { return applicantCount; }; //지원자수 반환
	~JobAd() {}; //소멸자

};

//채용 정보 리스트<-각 일반 회원 객체마다 할당
class JobAdList
{
private:
	vector<JobAd*> jobList;
	//int numOfJobAd=jobList.size(); //jobList의 갯수
public:
	int getNumOfJobAd() { return jobList.size(); };
	void addJob(JobAd* jobAd); //리스트에 채용 정보 추가
	void deleteJob(JobAd* jobAd); //리스트에 채용 정보 삭제
	//void showJobAdList();
	//void getJobList();
	char* getSearchResult(); //검색 결과 반환 (회사 이름, SSN 포함)
	char* getJobAd(); //jobAd 문자열 반환
	JobAd* getJobAdDetail() { return jobList.back(); };
};

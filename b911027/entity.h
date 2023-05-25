#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define MAX_STRING 32

// 클래스 선언
class Member;
class NormalMember;
class CompanyMember;
class MemberList;
class ApplyInfo;
class ApplyInfoList;
class JobAd;
class JobAdList;

// Member(회원) 클래스 정의
class Member
{
private:
	int member_type;			// 1이면 회사회원, 2면 일반회원
	char name[MAX_STRING];		// 이름
	char SSN[MAX_STRING];		// 회사 회원이면 사업자 번호, 일반 회원이면 주민번호
	char ID[MAX_STRING];		// ID
	char password[MAX_STRING];	// 비밀번호
	bool isLogin = false;		// 로그인 상태

public:
	Member(int member_type, const char* name, const char* SSN, const char* ID, const char* password); // 생성자
	virtual ~Member() {};	// 소멸자
	int getMemberType() { return member_type; };
	const char* getName() { return name; };
	const char* getSSN() { return SSN; };
	const char* getID() { return ID; };
	const char* getPassword() { return password; };
	bool getIsLogin() { return isLogin; };
	void setIsLogin(bool value);	// 로그인 시 상태 변화
};

// Member를 상속 받은 NormalMember(일반 회원) 클래스 정의
class NormalMember : public Member
{
private:
	ApplyInfoList* applyList; // 지원 정보 리스트 포인터
public:
	NormalMember(const char* name, const char* SSN, const char* ID, const char* password);	// 생성자
	~NormalMember() { delete applyList; }	// 소멸자. applyList 메모리에서 해제
	void addApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline);	// 채용 지원 시 지원 정보 등록
	ApplyInfoList* getApplyInfoList() { return applyList; };	// 가지고 있는 지원 정보 리스트 포인터 반환
};

// Member를 상속 받은 CompanyMember(회사 회원) 클래스 정의
class CompanyMember : public Member
{
private:
	JobAdList* jobList;	// 채용 정보 리스트 포인터
public:
	CompanyMember(const char* name, const char* SSN, const char* ID, const char* password);	// 생성자
	~CompanyMember() { delete jobList; };	// 소멸자, jobList 메모리에서 해제
	void addJobAd(const char* task, int numberOfMember, const char* deadline);	// 채용 정보 등록
	JobAdList* getJobList() { return jobList; };	// 가지고 있는 채용 정보 리스트 포인터 반환
};

//  MemberList 클래스 정의
class MemberList
{
private:
	vector<Member*> membersList;	// 회원 저장하기 위한 Member 포인터 벡터 
public:
	void addMember(Member* member); // 벡터에 회원 추가
	void deleteMember(Member* member); // 벡터에서 회원 삭제
	Member* findMember(const char* ID, const char* password); // ID와 PW 일치하는 회원 찾아서 회원 포인터 반환
	Member* findLogInMember(); // 로그인 한 회원 포인터 반환
//	Member* getMember(); //가장 마지막에 추가된 회원 포인터 반환
	CompanyMember* getCompanyMember(); // 로그인 한 회사 회원 포인터 반환
	NormalMember* getNormalMember(); // 로그인 한 일반 회원 포인터 반환
	CompanyMember* findByName(const char* name); // 이름으로 회사 회원 찾아서 회사 회원 포인터 반환
	CompanyMember* findBySSN(const char* SSN); // 사업자 번호로 회사회원 찾아서 회사 회원 포인터 반환
	
};

// ApplyInfo(지원 정보) 클래스 정의
class ApplyInfo
{
private:
	char companyName[MAX_STRING];	// 회사 이름
	char SSN[MAX_STRING];			// 사업자 번호
	char task[MAX_STRING];			// 업무
	int numberOfMember;				// 인원수
	char deadline[MAX_STRING];		// 마감일
public:
	ApplyInfo(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline);	//생성자
	~ApplyInfo() {};
	const char* getName() { return companyName; };	
	const char* getSSN() { return SSN; };
	const char* getTask() { return task; };
	int getNumberOfMember() { return numberOfMember; };
	const char* getDeadLine() { return deadline; };
};

// ApplyInfoList(지원 정보 리스트) 클래스 정의
class ApplyInfoList 
{
private:
	vector <ApplyInfo*> applyList; // 지원 정보를 저장하기 위한 ApplyInfo 포인터 벡터 
public:
	void addApply(ApplyInfo* applyInfo); // 벡터에 지원 정보 추가
	void deleteApply(ApplyInfo* applyInfo); // 벡터에서 지원 정보 삭제
	ApplyInfo* getApplyInfoDetail() { return applyList.back(); };	// 가장 최근에 등록된 지원정보의 포인터 반환
	char* getApplyInfoString();	// 지원 정보 문자열 반환
	ApplyInfo* findBySSN(const char * SSN);	// SSN으로 지원 정보 찾아서 해당되는 지원 정보 포인터 반환
	char* getApplyTaskCount(); // 업무별 지원횟수 문자열 반환
};

// JobAd(채용 정보) 클래스 정의
class JobAd
{
private:
	char companyName[MAX_STRING];	// 회사 이름
	char SSN[MAX_STRING];			// SSN
	char task[MAX_STRING];			// 업무
	int numberOfMember;				// 인원수 
	char deadline[MAX_STRING];		// 마감일
	int applicantCount=0;			// 지원자 수 
public:
	JobAd(const char* companyName, const char* SSN, const char* task, int numberOfMember, const char* deadline); // 생성자
	~JobAd() {}; //소멸자
	const char* getName() { return companyName; };
	const char* getSSN() { return SSN; };
	const char* getTask() { return task; };
	int getNumberOfMember() { return numberOfMember; };
	const char* getDeadLine() { return deadline; };
	void addApplicantCount() { applicantCount++; }; // 일반 회원이 해당 채용 정보에 지원했을 때 지원자수 ++
	void removeApplicantCount() { applicantCount--; }; // 일반 회원이 해당 채용 정보에 지원한 걸 취소했을 때 지원자수 --
	int getApplicantCount() { return applicantCount; }; // 지원자수 반환
	char* getJobAdString(); // 채용 정보 문자열로 반환 (업무 ,인원수, 마감일)
	char* getSearchResult(); //검색 결과 문자열로 반환 (회사 이름, SSN, 업무, 인원수 , 마감일)	
};

// JobAdList(채용 정보 리스트) 클래스 정의
class JobAdList
{
private:
	vector<JobAd*> jobList;	// 채용 정보를 저장하기 위한 JobAd 포인터 벡터
public:
	void addJob(JobAd* jobAd); // 리스트에 채용 정보 추가
	JobAd* getJobAdDetail() { return jobList.back(); }; // JobAd 반환
};

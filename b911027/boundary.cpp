#include "boundary.h"

/*
	함수 이름 : void JoinUI::createNewMember()
	기능	  : 회원 타입, 이름, 사업자 번호 혹은 주민번호, ID, 비밀번호 입력 받고 입력받은 정보들로 회원을 생성한 다음 회원 타입, 이름, 사업자 번호 혹은 주민번호, ID, 비밀번호를 파일에 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void JoinUI::createNewMember()
{
	int member_type = 0;
	char name[MAX_STRING];
	char SSN[MAX_STRING];
	char ID[MAX_STRING];
	char password[MAX_STRING];

	fscanf(in_fp, "%d %s %s %s %s", &member_type, name, SSN, ID, password);	// 파일에서 입력 받은 회원 정보 변수에 저장
	 pJoin->createMember(member_type, name, SSN, ID, password);		// 입력 받은 회원 정보를 가지고 pJoin이 가리키는 Join 객체의 createMember 함수 호출

	fprintf(out_fp, "1.1. 회원가입\n");
	fprintf(out_fp, "> %d %s %s %s %s\n", member_type, name, SSN, ID, password);	// 입력받은 정보 파일에 출력

}

/*
	함수 이름 : void LogInUI::inputIDPW() 
	기능	  : ID, 비밀번호 입력 받아서 로그인, 입력받은 ID, 비밀번호와 일치하는 Member 객체의 ID와 비밀번호 파일에 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void LogInUI::inputIDPW() 
{
	char ID[MAX_STRING];
	char password[MAX_STRING];

	fscanf(in_fp, "%s %s\n", ID, password); // 파일에서 입력 받은 ID와 비밀번호 변수에 저장
	Member* loginMember = pLogIn->logIn(ID, password); // ID와 비밀번호 가지고 pLogIn이 가리키는 LogIn 객체의 logIn 함수 호출, logIn된 멤버 객체 반환되어 logInMember에 저장

	fprintf(out_fp, "2.1. 로그인\n");
	fprintf(out_fp, "> %s %s\n", loginMember->getID(), loginMember->getPassword()); // logInMember 객체의 ID와 비밀번호 파일에 출력

}

/*
	함수 이름 : void LogOutUI::logOut() 
	기능	  : 로그아웃 한 회원 객체의 아이디 파일에 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void LogOutUI::logOut() 
{
	char ID[MAX_STRING];
	strncpy(ID, pLogOut->logOut(), MAX_STRING - 1); // pLogOut이 가리키는 LogOut 객체의 logOutString 함수 호출, 함수가 반환하는 문자열 ID 변수에 저장
	fprintf(out_fp, "2.2. 로그아웃\n");
	fprintf(out_fp, "> %s \n", ID); // 로그아웃 한 회원 객체의 ID 파일에 출력 
}
//LogOutUI

/*
	함수 이름 : void DeleteMembershipUI::deleteMembership()
	기능	  : 탈퇴한 회원 객체의 아이디 파일에 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void DeleteMembershipUI::deleteMembership()
{
	fprintf(out_fp, "1.2. 회원탈퇴\n");
	char ID[MAX_STRING];
	strncpy(ID,pDeleteMembership->deleteMember(), MAX_STRING - 1);  // pDeleteMembership이 가리키는 DeleteMembership 객체의 deleteMember 함수 호출, 함수가 반환하는 문자열 ID 변수에 저장
	fprintf(out_fp, "> %s \n", ID); // 탈퇴한 회원 객체의 ID 파일에 출력
}
//DeleteMembershipUI

/*
	함수 이름 : void AddJobAdUI::addJobAd()
	기능	  : 파일로 입력 받은 정보 가지고 채용 정보 등록하고 파일에 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void AddJobAdUI::addJobAd()
{
	char task[MAX_STRING];
	int numberOfMember;
	char deadline[MAX_STRING];

	fscanf(in_fp, "%s %d %s\n", task, &numberOfMember, deadline); // 파일에서 업무, 인원수, 마감일을 입력받음 
	pAddJobAd->createJobAd(task, numberOfMember, deadline); // 입력받은 채용 정보 가지고 pAddJobAd이 가리키는 AddJobAd 객체의 createJobAd 함수 호출하여 

	fprintf(out_fp, "3.1. 채용 정보 등록\n");
	fprintf(out_fp, "> %s %d %s\n", task, numberOfMember, deadline); // 입력 받은 정보 파일에 출력
}
//AddJobAdUI

/*
	함수 이름 : void ListJobAdUI::viewListJobAd() 
	기능	  : 등록된 채용 정보 파일에 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void ListJobAdUI::viewListJobAd() 
{
	fprintf(out_fp, "3.2. 등록된 채용 정보 조회\n");
	fprintf(out_fp, "> %s", pListJobAd->getJobAd()); 
	// pListJob이 가리키는 ListJobAd 객체의 getJobAd 함수 호출, getJobAd 함수가 반환하는 문자열(채용 정보) 파일에 출력
}
//ListJobAdUI


/*
	함수 이름 : void SearchJobUI::searchJobAd()
	기능	  : 회사 이름으로 채용 정보 검색하고 검색 결과 파일에 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void SearchJobUI::searchJobAd()
{
	char name[MAX_STRING];
	fscanf(in_fp, "%s", name); // 회사 이름 입력 받아 변수에 저장

	fprintf(out_fp, "4.1. 채용 정보 검색\n");
	fprintf(out_fp, "> %s", pSearchJob->searchJob(name));
	// 입력 받은 회사 이름 가지고 pSearchJobAd가 가리키는 SearchJobAd 객체의 searchJob 함수 호출(검색)
	// searchJob 함수가 반환하는 문자열(검색 결과로 나온 채용 정보 객체의 정보) 파일에 출력
}
//SearchJobUI

/*
	함수 이름 : void SearchJobUI::searchJobAd()
	기능	  : 검색 결과로 나온 채용 정보 파일에 입력받은 SSN으로 지원, 지원 정보 등록하고 등록한 지원 정보의 이름, SSN, 업무 파일에 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void ApplyUI::apply()
{
	char SSN[MAX_STRING];
	fscanf(in_fp, "%s", SSN); // 파일에서 SSN 입력 받음
	ApplyInfo *applyInfo=pApply->createApplyInfo(SSN); // 입력받은 SSN을 가지고 pApply가 가리키는 Apply 객체의 createApplyInfo 함수 호출, 생성된 지원 정보 객체 반환되어 applyInfo에 저장
	fprintf(out_fp, "4.2. 채용 지원\n");
	fprintf(out_fp, "> %s %s %s\n", applyInfo->getName(), applyInfo->getSSN(), applyInfo->getTask()); // 생성된 지원 정보 applyInfo의 회사 이름, SSN, 업무 파일에 출력
}//ApplyUI

/*
	함수 이름 : void CheckApplyInfoUI::checkApplyInfo()
	기능	  : 일반 회원의 지원 정보 리스트 정보 파일에 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void CheckApplyInfoUI::checkApplyInfo()
{
	fprintf(out_fp, "4.3. 지원 정보 조회\n");
	fprintf(out_fp, "> %s", pCheckApplyInfo->getApplyInfoList());
	// pCheckApplyInfo가 가리키는 CheckApplyInfo 객체의 getApplyInfoList 함수 호출
	// getApplyInfoList 함수가 반환하는 문자열(지원 정보 리스트 문자열) 파일에 출력
}
//CheckApplyInfoUI 지원정보 조회

/*
	함수 이름 : void CancelApplyInfoUI::cancelApply()
	기능	  : 입력 받은 SSN으로 지원 정보 찾아서 지원 취소하고 취소한 지원 정보 파일에 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void CancelApplyInfoUI::cancelApply()
{
	char SSN[MAX_STRING];
	fscanf(in_fp, "%s", SSN); // 파일에서 SSN 입력 받음

	fprintf(out_fp, "4.4. 지원 취소\n");
	fprintf(out_fp, "> %s\n", pCancelApplyInfo->getCancelApplyInfo(SSN));
	// 입력 받은 SSN 가지고 pCancelApplyInfo가 가리키는 CancelApplyInfo 객체의 getCancelApplyInfo 함수 호출
	// getCancelApplyInfo 함수가 반환하는 문자열(취소한 지원 정보 문자열) 파일에 출력
}
//CancelApplyInfoUI

/*
	함수 이름 : void ApplyStatisticsUI::showStatistics()
	기능	  : 일반 회원, 회사 회원에 따라 지원 정보 통계 출력
	전달 인자 : 없음
	반환값    : 없음
*/
void ApplyStatisticsUI::showStatistics()
{
	fprintf(out_fp, "5.1. 지원 정보 통계\n");
	fprintf(out_fp, "> %s", pApplyStatistics->getStatistics());
	// pApplyStatistics가 가리키는 ApplyStatistics 객체의 getStatistics 함수 호출
	// getStatistics 함수가 반환하는 문자열 (업무별 지원자수 or 업무별 지원 횟수) 파일에 출력
}
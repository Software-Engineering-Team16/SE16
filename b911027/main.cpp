// 헤더 선언
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Boundary.h"

using namespace std;
// 상수 선언
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 변수 선언
FILE* in_fp, * out_fp;
MemberList* memberList = new MemberList();

//함수 선언
void doTask();
void program_exit();

int main()
{
	// 파일 입출력을 위한 초기화
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");

	doTask();

	return 0;
}
void doTask()
{
	// 메뉴 파싱을 위한 level 구분 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit)
	{
		// 입력파일에서 메뉴 숫자 2개를 읽기
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
		
		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1:	// "1.1 회원가입" 메뉴 부분
			{
				JoinUI joinUI = JoinUI();	// JoinUI 객체 생성
				joinUI.createNewMember();	// JoinUI의 createNewMember() 함수에서 해당 기능 수행
				break;
			}
			case 2: // "1.2 회원탈퇴" 메뉴 부분
			{
				DeleteMembershipUI deleteMembershipUI = DeleteMembershipUI();	// DeleteMembershipUI 객체 생성
				deleteMembershipUI.deleteMembership();							// DeleteMembershipUI의 deleteMembership() 함수에서 해당 기능 수행
				break;
			}
			}
			break;
		case 2:
			switch (menu_level_2)
			{
			case 1: // "2.1 로그인" 메뉴 부분
			{
				LogInUI loginUI = LogInUI();	// LogInUI 객체 생성
				loginUI.inputIDPW();			// LoginUI의 inputIDPW() 함수에서 해당 기능 수행
				break;
			}
			case 2: // "2.2 로그아웃" 메뉴 부분
			{
				LogOutUI logoutUI = LogOutUI();	// LogOutUI 객체 생성
				logoutUI.logOut();				// LougOutUI의 logOut() 함수에서 해당 기능 수행
				break;
			}
			}
			break;
		case 3:
			switch (menu_level_2)
			{
			case 1: // "3.1 채용 정보 등록" 메뉴 부분
			{
				AddJobAdUI addJobUI = AddJobAdUI();	// AddJobAdUI 객체 생성
				addJobUI.addJobAd();				// AddJobAdUI의 addJobAd() 함수에서 해당 기능 수행
				break;
			}
			case 2: // "3.2 등록된 채용 정보 조회" 메뉴 부분
			{
				ListJobAdUI listJobAdUI = ListJobAdUI();	// ListJobAdUI 객체 생성
				listJobAdUI.viewListJobAd();				// ListJobAdUI의 viewListJobAd() 함수에서 해당 기능 수행
				break;
			}
			}
			break;
		case 4:
			switch (menu_level_2)
			{
			case 1:	// "4.1 채용 정보 검색" 메뉴 부분
			{
				SearchJobUI searchJobUI = SearchJobUI();	// SearchJobUI 객체 생성
				searchJobUI.searchJobAd();					// SearchJobUI의 searchJobAd() 함수에서 해당 기능 수행
				break;
			}
			case 2: // "4.2 채용 지원" 메뉴 부분
			{
				ApplyUI applyUI = ApplyUI();	// ApplyUI 객체 생성
				applyUI.apply();				// ApplyUI의 apply() 함수에서 해당 기능 수행
				break;
			}
			case 3:	// "4.3 지원 정보 조회" 메뉴 부분
			{
				CheckApplyInfoUI checkApplyInfoUI = CheckApplyInfoUI();	// CheckApplyInfoUI 객체 생성
				checkApplyInfoUI.checkApplyInfo();						// CheckApplyInfoUI의 checkApplyInfo() 함수에서 해당 기능 수행
				break;
			}
			case 4:	// "4.4 지원 취소" 메뉴 부분
			{
				CancelApplyInfoUI cancelApplyInfoUI = CancelApplyInfoUI();	// CancelApplyInfoUI 객체 생성
				cancelApplyInfoUI.cancelApply();							// CancelApplyInfoUI의 cancelApply() 함수에서 해당 기능 수행
				break;
			}
			}
			break;

		case 5:
			switch (menu_level_2)
			{
			case 1: // "5.1 지원 정보 통계" 메뉴 부분
				ApplyStatisticsUI applyStatisticsUI = ApplyStatisticsUI();	// ApplyStatisticsUI 객체 생성
				applyStatisticsUI.showStatistics();							// ApplyStatisticsUI의 showStatistics() 함수에서 해당 기능 수행
				break;
			}
			break;
		case 6:	
			switch (menu_level_2)
			{
			case 1: // " 6.1 종료" 메뉴 부분

				program_exit();
				is_program_exit = 1;
				break;
			}
			break;
		}
	}
	return;
}

void program_exit()
{
	// 출력 형식
	fprintf(out_fp, "6.1. 종료\n");
}
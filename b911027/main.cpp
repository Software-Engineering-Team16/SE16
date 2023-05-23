#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <fstream>
#include "Boundary.h"

using namespace std;


#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
FILE* in_fp, * out_fp;


void doTask();

void program_exit();;
int main()
{
	// 파일 입출력을 위한 초기화
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");
	

	doTask();

	//doTask(); 
	return 0;
}
void doTask()
{
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	MemberCollection *memberCollection=new MemberCollection();
	JoinUI joinUI = JoinUI(in_fp, out_fp,memberCollection );
	LogInUI loginUI = LogInUI(in_fp, out_fp, memberCollection);
	LogOutUI logoutUI = LogOutUI(in_fp, out_fp, memberCollection);
	DeleteMembershipUI deletemembershipUI = DeleteMembershipUI(in_fp, out_fp, memberCollection);
	while (!is_program_exit)
	{
		// 입력파일에서 메뉴 숫자 2개를 읽기
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
		//printf("%d %d", menu_level_1, menu_level_2);
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1: //회원가입

				cout << "가입" << endl;
				joinUI.createNewMember();
				break;
			case 2: //회원탈퇴
				
				cout << "탈퇴" << endl;
				deletemembershipUI.deleteMember();
				break;
			}
			break;
		case 2:
			switch (menu_level_2)
			{
			case 1: //로그인
				
				cout << "로그인" << endl;
				loginUI.fillinIDPW();
				break;
			case 2: //로그아웃

				cout << "로그아웃" << endl;
				logoutUI.logOut();
				break;
			}
			break;
		case 6:
			switch (menu_level_2)
			{
			case 1:

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
	printf("종료\n");
	fprintf(out_fp, "6.1. 종료\n");
}

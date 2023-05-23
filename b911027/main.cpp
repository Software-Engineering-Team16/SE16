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
void join();
void logIn();
void logOut();
void deleteMembership();
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

				//join();
				joinUI.createNewMember();
				break;
			case 2: //회원탈퇴
				//deleteMembership();
				//DeleteMembershipUI();
				break;
			}
			break;
		case 2:
			switch (menu_level_2)
			{
			case 1: //로그인
				
				//logIn();
				cout << "로그인" << endl;
				loginUI.fillinIDPW();
				break;
			case 2: //로그아웃

				//logOut();
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

/*void logIn()
{
	printf("로그인\n");
	char ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s", ID, password);

	fprintf(out_fp, "2.1. 로그인\n");
	fprintf(out_fp, "> %s %s\n", ID, password);
}
void logOut()
{
	printf("로그아웃\n");
	fprintf(out_fp, "2.2. 로그아웃\n");
}
void deleteMembership()
{
	printf("회원탈퇴\n");
	fprintf(out_fp, "1.2. 회원탈퇴\n");
	//fprintf(out_fp, "> %s %s %s %s %s\n", user_type, name, SSN, ID, password);
}
void join()
{
	printf("회원가입\n");
	/* !!!!!!! 중요 !!!!!!!!!
	* 단순히 파일을 통해 입출력하는 방법을 보이기 위한 코드이므로 이 함수에서 그대로 사용하면 안됨.
	* control 및 boundary class를 이용해서 해당 기능이 구현되도록 해야 함.
	*/
	/*char user_type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING],
		address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
	// 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음

	fscanf(in_fp, "%s %s %s %s %s", user_type, name, SSN, ID, password);
	// 해당 기능 수행

		// 출력 형식
	fprintf(out_fp, "1.1. 회원가입\n");
	fprintf(out_fp, "> %s %s %s %s %s\n", user_type, name, SSN, ID, password);
	
}*/
void program_exit()
{
	printf("종료\n");
	fprintf(out_fp, "6.1. 종료\n");
}

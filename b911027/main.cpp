// ��� ����
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Boundary.h"

using namespace std;
// ��� ����
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// ���� ����
FILE* in_fp, * out_fp;
MemberList* memberList = new MemberList();

//�Լ� ����
void doTask();
void program_exit();

int main()
{
	// ���� ������� ���� �ʱ�ȭ
	in_fp = fopen(INPUT_FILE_NAME, "r+");
	out_fp = fopen(OUTPUT_FILE_NAME, "w+");

	doTask();

	return 0;
}
void doTask()
{
	// �޴� �Ľ��� ���� level ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit)
	{
		// �Է����Ͽ��� �޴� ���� 2���� �б�
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
		
		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1:	// "1.1 ȸ������" �޴� �κ�
			{
				JoinUI joinUI = JoinUI();	// JoinUI ��ü ����
				joinUI.createNewMember();	// JoinUI�� createNewMember() �Լ����� �ش� ��� ����
				break;
			}
			case 2: // "1.2 ȸ��Ż��" �޴� �κ�
			{
				DeleteMembershipUI deleteMembershipUI = DeleteMembershipUI();	// DeleteMembershipUI ��ü ����
				deleteMembershipUI.deleteMembership();							// DeleteMembershipUI�� deleteMembership() �Լ����� �ش� ��� ����
				break;
			}
			}
			break;
		case 2:
			switch (menu_level_2)
			{
			case 1: // "2.1 �α���" �޴� �κ�
			{
				LogInUI loginUI = LogInUI();	// LogInUI ��ü ����
				loginUI.inputIDPW();			// LoginUI�� inputIDPW() �Լ����� �ش� ��� ����
				break;
			}
			case 2: // "2.2 �α׾ƿ�" �޴� �κ�
			{
				LogOutUI logoutUI = LogOutUI();	// LogOutUI ��ü ����
				logoutUI.logOut();				// LougOutUI�� logOut() �Լ����� �ش� ��� ����
				break;
			}
			}
			break;
		case 3:
			switch (menu_level_2)
			{
			case 1: // "3.1 ä�� ���� ���" �޴� �κ�
			{
				AddJobAdUI addJobUI = AddJobAdUI();	// AddJobAdUI ��ü ����
				addJobUI.addJobAd();				// AddJobAdUI�� addJobAd() �Լ����� �ش� ��� ����
				break;
			}
			case 2: // "3.2 ��ϵ� ä�� ���� ��ȸ" �޴� �κ�
			{
				ListJobAdUI listJobAdUI = ListJobAdUI();	// ListJobAdUI ��ü ����
				listJobAdUI.viewListJobAd();				// ListJobAdUI�� viewListJobAd() �Լ����� �ش� ��� ����
				break;
			}
			}
			break;
		case 4:
			switch (menu_level_2)
			{
			case 1:	// "4.1 ä�� ���� �˻�" �޴� �κ�
			{
				SearchJobUI searchJobUI = SearchJobUI();	// SearchJobUI ��ü ����
				searchJobUI.searchJobAd();					// SearchJobUI�� searchJobAd() �Լ����� �ش� ��� ����
				break;
			}
			case 2: // "4.2 ä�� ����" �޴� �κ�
			{
				ApplyUI applyUI = ApplyUI();	// ApplyUI ��ü ����
				applyUI.apply();				// ApplyUI�� apply() �Լ����� �ش� ��� ����
				break;
			}
			case 3:	// "4.3 ���� ���� ��ȸ" �޴� �κ�
			{
				CheckApplyInfoUI checkApplyInfoUI = CheckApplyInfoUI();	// CheckApplyInfoUI ��ü ����
				checkApplyInfoUI.checkApplyInfo();						// CheckApplyInfoUI�� checkApplyInfo() �Լ����� �ش� ��� ����
				break;
			}
			case 4:	// "4.4 ���� ���" �޴� �κ�
			{
				CancelApplyInfoUI cancelApplyInfoUI = CancelApplyInfoUI();	// CancelApplyInfoUI ��ü ����
				cancelApplyInfoUI.cancelApply();							// CancelApplyInfoUI�� cancelApply() �Լ����� �ش� ��� ����
				break;
			}
			}
			break;

		case 5:
			switch (menu_level_2)
			{
			case 1: // "5.1 ���� ���� ���" �޴� �κ�
				ApplyStatisticsUI applyStatisticsUI = ApplyStatisticsUI();	// ApplyStatisticsUI ��ü ����
				applyStatisticsUI.showStatistics();							// ApplyStatisticsUI�� showStatistics() �Լ����� �ش� ��� ����
				break;
			}
			break;
		case 6:	
			switch (menu_level_2)
			{
			case 1: // " 6.1 ����" �޴� �κ�

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
	// ��� ����
	fprintf(out_fp, "6.1. ����\n");
}
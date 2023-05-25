#include "boundary.h"

/*
	�Լ� �̸� : void JoinUI::createNewMember()
	���	  : ȸ�� Ÿ��, �̸�, ����� ��ȣ Ȥ�� �ֹι�ȣ, ID, ��й�ȣ �Է� �ް� �Է¹��� ������� ȸ���� ������ ���� ȸ�� Ÿ��, �̸�, ����� ��ȣ Ȥ�� �ֹι�ȣ, ID, ��й�ȣ�� ���Ͽ� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void JoinUI::createNewMember()
{
	int member_type = 0;
	char name[MAX_STRING];
	char SSN[MAX_STRING];
	char ID[MAX_STRING];
	char password[MAX_STRING];

	fscanf(in_fp, "%d %s %s %s %s", &member_type, name, SSN, ID, password);	// ���Ͽ��� �Է� ���� ȸ�� ���� ������ ����
	 pJoin->createMember(member_type, name, SSN, ID, password);		// �Է� ���� ȸ�� ������ ������ pJoin�� ����Ű�� Join ��ü�� createMember �Լ� ȣ��

	fprintf(out_fp, "1.1. ȸ������\n");
	fprintf(out_fp, "> %d %s %s %s %s\n", member_type, name, SSN, ID, password);	// �Է¹��� ���� ���Ͽ� ���

}

/*
	�Լ� �̸� : void LogInUI::inputIDPW() 
	���	  : ID, ��й�ȣ �Է� �޾Ƽ� �α���, �Է¹��� ID, ��й�ȣ�� ��ġ�ϴ� Member ��ü�� ID�� ��й�ȣ ���Ͽ� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void LogInUI::inputIDPW() 
{
	char ID[MAX_STRING];
	char password[MAX_STRING];

	fscanf(in_fp, "%s %s\n", ID, password); // ���Ͽ��� �Է� ���� ID�� ��й�ȣ ������ ����
	Member* loginMember = pLogIn->logIn(ID, password); // ID�� ��й�ȣ ������ pLogIn�� ����Ű�� LogIn ��ü�� logIn �Լ� ȣ��, logIn�� ��� ��ü ��ȯ�Ǿ� logInMember�� ����

	fprintf(out_fp, "2.1. �α���\n");
	fprintf(out_fp, "> %s %s\n", loginMember->getID(), loginMember->getPassword()); // logInMember ��ü�� ID�� ��й�ȣ ���Ͽ� ���

}

/*
	�Լ� �̸� : void LogOutUI::logOut() 
	���	  : �α׾ƿ� �� ȸ�� ��ü�� ���̵� ���Ͽ� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void LogOutUI::logOut() 
{
	char ID[MAX_STRING];
	strncpy(ID, pLogOut->logOut(), MAX_STRING - 1); // pLogOut�� ����Ű�� LogOut ��ü�� logOutString �Լ� ȣ��, �Լ��� ��ȯ�ϴ� ���ڿ� ID ������ ����
	fprintf(out_fp, "2.2. �α׾ƿ�\n");
	fprintf(out_fp, "> %s \n", ID); // �α׾ƿ� �� ȸ�� ��ü�� ID ���Ͽ� ��� 
}
//LogOutUI

/*
	�Լ� �̸� : void DeleteMembershipUI::deleteMembership()
	���	  : Ż���� ȸ�� ��ü�� ���̵� ���Ͽ� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void DeleteMembershipUI::deleteMembership()
{
	fprintf(out_fp, "1.2. ȸ��Ż��\n");
	char ID[MAX_STRING];
	strncpy(ID,pDeleteMembership->deleteMember(), MAX_STRING - 1);  // pDeleteMembership�� ����Ű�� DeleteMembership ��ü�� deleteMember �Լ� ȣ��, �Լ��� ��ȯ�ϴ� ���ڿ� ID ������ ����
	fprintf(out_fp, "> %s \n", ID); // Ż���� ȸ�� ��ü�� ID ���Ͽ� ���
}
//DeleteMembershipUI

/*
	�Լ� �̸� : void AddJobAdUI::addJobAd()
	���	  : ���Ϸ� �Է� ���� ���� ������ ä�� ���� ����ϰ� ���Ͽ� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void AddJobAdUI::addJobAd()
{
	char task[MAX_STRING];
	int numberOfMember;
	char deadline[MAX_STRING];

	fscanf(in_fp, "%s %d %s\n", task, &numberOfMember, deadline); // ���Ͽ��� ����, �ο���, �������� �Է¹��� 
	pAddJobAd->createJobAd(task, numberOfMember, deadline); // �Է¹��� ä�� ���� ������ pAddJobAd�� ����Ű�� AddJobAd ��ü�� createJobAd �Լ� ȣ���Ͽ� 

	fprintf(out_fp, "3.1. ä�� ���� ���\n");
	fprintf(out_fp, "> %s %d %s\n", task, numberOfMember, deadline); // �Է� ���� ���� ���Ͽ� ���
}
//AddJobAdUI

/*
	�Լ� �̸� : void ListJobAdUI::viewListJobAd() 
	���	  : ��ϵ� ä�� ���� ���Ͽ� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void ListJobAdUI::viewListJobAd() 
{
	fprintf(out_fp, "3.2. ��ϵ� ä�� ���� ��ȸ\n");
	fprintf(out_fp, "> %s", pListJobAd->getJobAd()); 
	// pListJob�� ����Ű�� ListJobAd ��ü�� getJobAd �Լ� ȣ��, getJobAd �Լ��� ��ȯ�ϴ� ���ڿ�(ä�� ����) ���Ͽ� ���
}
//ListJobAdUI


/*
	�Լ� �̸� : void SearchJobUI::searchJobAd()
	���	  : ȸ�� �̸����� ä�� ���� �˻��ϰ� �˻� ��� ���Ͽ� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void SearchJobUI::searchJobAd()
{
	char name[MAX_STRING];
	fscanf(in_fp, "%s", name); // ȸ�� �̸� �Է� �޾� ������ ����

	fprintf(out_fp, "4.1. ä�� ���� �˻�\n");
	fprintf(out_fp, "> %s", pSearchJob->searchJob(name));
	// �Է� ���� ȸ�� �̸� ������ pSearchJobAd�� ����Ű�� SearchJobAd ��ü�� searchJob �Լ� ȣ��(�˻�)
	// searchJob �Լ��� ��ȯ�ϴ� ���ڿ�(�˻� ����� ���� ä�� ���� ��ü�� ����) ���Ͽ� ���
}
//SearchJobUI

/*
	�Լ� �̸� : void SearchJobUI::searchJobAd()
	���	  : �˻� ����� ���� ä�� ���� ���Ͽ� �Է¹��� SSN���� ����, ���� ���� ����ϰ� ����� ���� ������ �̸�, SSN, ���� ���Ͽ� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void ApplyUI::apply()
{
	char SSN[MAX_STRING];
	fscanf(in_fp, "%s", SSN); // ���Ͽ��� SSN �Է� ����
	ApplyInfo *applyInfo=pApply->createApplyInfo(SSN); // �Է¹��� SSN�� ������ pApply�� ����Ű�� Apply ��ü�� createApplyInfo �Լ� ȣ��, ������ ���� ���� ��ü ��ȯ�Ǿ� applyInfo�� ����
	fprintf(out_fp, "4.2. ä�� ����\n");
	fprintf(out_fp, "> %s %s %s\n", applyInfo->getName(), applyInfo->getSSN(), applyInfo->getTask()); // ������ ���� ���� applyInfo�� ȸ�� �̸�, SSN, ���� ���Ͽ� ���
}//ApplyUI

/*
	�Լ� �̸� : void CheckApplyInfoUI::checkApplyInfo()
	���	  : �Ϲ� ȸ���� ���� ���� ����Ʈ ���� ���Ͽ� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void CheckApplyInfoUI::checkApplyInfo()
{
	fprintf(out_fp, "4.3. ���� ���� ��ȸ\n");
	fprintf(out_fp, "> %s", pCheckApplyInfo->getApplyInfoList());
	// pCheckApplyInfo�� ����Ű�� CheckApplyInfo ��ü�� getApplyInfoList �Լ� ȣ��
	// getApplyInfoList �Լ��� ��ȯ�ϴ� ���ڿ�(���� ���� ����Ʈ ���ڿ�) ���Ͽ� ���
}
//CheckApplyInfoUI �������� ��ȸ

/*
	�Լ� �̸� : void CancelApplyInfoUI::cancelApply()
	���	  : �Է� ���� SSN���� ���� ���� ã�Ƽ� ���� ����ϰ� ����� ���� ���� ���Ͽ� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void CancelApplyInfoUI::cancelApply()
{
	char SSN[MAX_STRING];
	fscanf(in_fp, "%s", SSN); // ���Ͽ��� SSN �Է� ����

	fprintf(out_fp, "4.4. ���� ���\n");
	fprintf(out_fp, "> %s\n", pCancelApplyInfo->getCancelApplyInfo(SSN));
	// �Է� ���� SSN ������ pCancelApplyInfo�� ����Ű�� CancelApplyInfo ��ü�� getCancelApplyInfo �Լ� ȣ��
	// getCancelApplyInfo �Լ��� ��ȯ�ϴ� ���ڿ�(����� ���� ���� ���ڿ�) ���Ͽ� ���
}
//CancelApplyInfoUI

/*
	�Լ� �̸� : void ApplyStatisticsUI::showStatistics()
	���	  : �Ϲ� ȸ��, ȸ�� ȸ���� ���� ���� ���� ��� ���
	���� ���� : ����
	��ȯ��    : ����
*/
void ApplyStatisticsUI::showStatistics()
{
	fprintf(out_fp, "5.1. ���� ���� ���\n");
	fprintf(out_fp, "> %s", pApplyStatistics->getStatistics());
	// pApplyStatistics�� ����Ű�� ApplyStatistics ��ü�� getStatistics �Լ� ȣ��
	// getStatistics �Լ��� ��ȯ�ϴ� ���ڿ� (������ �����ڼ� or ������ ���� Ƚ��) ���Ͽ� ���
}
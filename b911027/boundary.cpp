#include "boundary.h"

JoinUI::JoinUI()
{

	pJoin = new Join();
}
void JoinUI::createNewMember()
{
	int member_type = 0;
	char name[MAX_STRING];

	char SSN[MAX_STRING];
	char ID[MAX_STRING];
	char password[MAX_STRING];

	fscanf(in_fp, "%d %s %s %s %s", &member_type, name, SSN, ID, password);
	 pJoin->createMember(member_type, name, SSN, ID, password); 

	fprintf(out_fp, "1.1. ȸ������\n");
	fprintf(out_fp, "> %d %s %s %s %s\n", member_type, name, SSN, ID, password);



}
//JoinUI
LogInUI::LogInUI() {


	pLogIn = new LogIn();
}

void LogInUI::inputIDPW() {
	char ID[MAX_STRING];
	char password[MAX_STRING];

	fscanf(in_fp, "%s %s\n", ID, password);
	Member* loginMember = pLogIn->logIn(ID, password);

	fprintf(out_fp, "2.1. �α���\n");
	fprintf(out_fp, "> %s %s\n", loginMember->getID(), loginMember->getPassword());


}
//LogInUI
LogOutUI::LogOutUI()
{


	pLogOut = new LogOut();
}


void LogOutUI::logOut() {
	fprintf(out_fp, "2.2. �α׾ƿ�\n");
	char ID[MAX_STRING];
	strncpy(ID, pLogOut->logOut(), MAX_STRING - 1);
	fprintf(out_fp, "> %s \n", ID);
}
//LogOutUI
DeleteMembershipUI::DeleteMembershipUI()
{

	pDeleteMembership = new DeleteMembership();

}
void DeleteMembershipUI::deleteMembership()
{
	fprintf(out_fp, "1.2. ȸ��Ż��\n");
	char ID[MAX_STRING];
	strncpy(ID,pDeleteMembership->deleteMember(), MAX_STRING - 1);
	fprintf(out_fp, "> %s \n", ID);
}

//DeleteMembershipUI
AddJobAdUI::AddJobAdUI()
{
	pAddJobAd = new AddJobAd();
}
void AddJobAdUI::addJobAd()
{

	char task[MAX_STRING];
	int numberOfMember;
	char deadline[MAX_STRING];

	fscanf(in_fp, "%s %d %s\n", task, &numberOfMember, deadline);
	pAddJobAd->createJobAd(task, numberOfMember, deadline);
	

	fprintf(out_fp, "3.1. ä�� ���� ���\n");
	fprintf(out_fp, "> %s %d %s\n", task, numberOfMember, deadline);
}
//AddJobAdUI
ListJobAdUI::ListJobAdUI()
{
	pListJobAd = new ListJobAd();
}
void ListJobAdUI::viewListJobAd() //��ϵ� ä�� ���� ��ȸ
{
	fprintf(out_fp, "3.2. ��ϵ� ä�� ���� ��ȸ\n");
	JobAdList* jobAdList = pListJobAd->getJobAdList(); //JobAdList ������ ��ȯ�ؾ��� �� ����
	//JobAdList ������ �ް�, ������ �̿��ؼ� jobAdList���� ���ڿ� ��ȯ
	fprintf(out_fp, "> %s", jobAdList->getJobAd()); //���ڿ� ��ȯ�ϴ� �� ���� �ٸ� ���?

}
//ListJobAdUI
SearchJobUI::SearchJobUI()
{
	pSearchJob = new SearchJob();
}
void SearchJobUI::searchJobAd()
{
	char name[MAX_STRING];
	fscanf(in_fp, "%s", name);

	fprintf(out_fp, "4.1. ä�� ���� �˻�\n");
	JobAdList* jobAdList = pSearchJob->searchJob(name); //JobAdList ������ ��ȯ
	fprintf(out_fp, "> %s", jobAdList->getSearchResult());
}
//SearchJobUI
ApplyUI::ApplyUI()
{
	pApply = new Apply();
}
void ApplyUI::apply()
{
	char SSN[MAX_STRING];
	fscanf(in_fp, "%s", SSN);
	ApplyInfo *applyInfo=pApply->createApplyInfo(SSN);
	//SSN������ companyȸ�� ã��
	//compnayȸ���� ����� ä�� ���� list ����, ä������ ����Ʈ���� get JobAd
	//jobAd
	//ä�� ������ �����ڼ� ++
	//���� ���� ����(> { [ȸ���̸�] [����ڹ�ȣ] [����] [�ο� ��] [��û������] }*
	//ä�� ������ ���� �״�� �����ؼ� ���?
	//���� ���� �����ϰ� �������� ����Ʈ�� �߰�>
	//����� �������� ����Ʈ���� ������ ���� ������ ȸ���̸�, ����ڹ�ȣ, ����
	fprintf(out_fp, "4.2. ä�� ����\n");
	fprintf(out_fp, "> %s %s %s", applyInfo->getName(), applyInfo->getSSN(), applyInfo->getNumberOfMember());
	//ȸ�� �̸� ����ڹ�ȣ ���� ���
	//ApplyInfoList* applyInfoList;
}


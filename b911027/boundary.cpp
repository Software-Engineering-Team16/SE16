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

	fprintf(out_fp, "1.1. 회원가입\n");
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

	fprintf(out_fp, "2.1. 로그인\n");
	fprintf(out_fp, "> %s %s\n", loginMember->getID(), loginMember->getPassword());


}
//LogInUI
LogOutUI::LogOutUI()
{


	pLogOut = new LogOut();
}


void LogOutUI::logOut() {
	fprintf(out_fp, "2.2. 로그아웃\n");
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
	fprintf(out_fp, "1.2. 회원탈퇴\n");
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
	

	fprintf(out_fp, "3.1. 채용 정보 등록\n");
	fprintf(out_fp, "> %s %d %s\n", task, numberOfMember, deadline);
}
//AddJobAdUI
ListJobAdUI::ListJobAdUI()
{
	pListJobAd = new ListJobAd();
}
void ListJobAdUI::viewListJobAd() //등록된 채용 정보 조회
{
	fprintf(out_fp, "3.2. 등록된 채용 정보 조회\n");
	JobAdList* jobAdList = pListJobAd->getJobAdList(); //JobAdList 포인터 반환해야할 것 같음
	
		fprintf(out_fp, "> %s\n", jobAdList->getJobAd());

}
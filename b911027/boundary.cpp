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
	//JobAdList 포인터 받고, 포인터 이용해서 jobAdList에서 문자열 반환
	fprintf(out_fp, "> %s", jobAdList->getJobAd()); //문자열 반환하는 것 말고 다른 방법?

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

	fprintf(out_fp, "4.1. 채용 정보 검색\n");
	JobAdList* jobAdList = pSearchJob->searchJob(name); //JobAdList 포인터 반환
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
	//SSN가지고 company회원 찾고
	//compnay회원이 등록한 채용 정보 list 받음, 채용정보 리스트에서 get JobAd
	//jobAd
	//채용 정보에 지원자수 ++
	//지원 정보 생성(> { [회사이름] [사업자번호] [업무] [인원 수] [신청마감일] }*
	//채용 정보의 정보 그대로 복사해서 사용?
	//지원 정보 생성하고 지원정보 리스트에 추가>
	//출력은 지원정보 리스트에서 가져온 지원 정보의 회사이름, 사업자번호, 업무
	fprintf(out_fp, "4.2. 채용 지원\n");
	fprintf(out_fp, "> %s %s %s", applyInfo->getName(), applyInfo->getSSN(), applyInfo->getNumberOfMember());
	//회사 이름 사업자번호 업무 출력
	//ApplyInfoList* applyInfoList;
}


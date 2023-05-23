#include "Boundary.h"
#include "Control.h"

JoinUI::JoinUI(FILE* in_fp, FILE* out_fp, MemberCollection *memberCollection)
{
	this->in_fp = in_fp;
	this->out_fp = out_fp;
	//MemberCollection* memberCollection=new MemberCollection();
	//join = new Join(memberCollection);
	this->memberCollection = memberCollection;
	join = new Join(memberCollection);
}
void JoinUI::createNewMember() 
{
	int member_type = 0;
	char name[MAX_STRING];
	//string name;
	//string SSN;
	//string ID;
	//string password;
	char SSN[MAX_STRING];
	char ID[MAX_STRING];
	char password[MAX_STRING];

	fscanf(in_fp, "%d %s %s %s %s", &member_type, name, SSN, ID, password);
	//MemberCollection collection;
	Member *newMember=join->createMember(member_type, name, SSN, ID, password); //join createMember의 반환은 Member 객체 포인터 일까?
	
	fprintf(out_fp, "1.1. 회원가입\n");
	fprintf(out_fp, "> %d %s %s %s %s\n", newMember->getMemberType(), newMember->getName(), newMember->getSSN(), newMember->getID(), newMember->getPassword());
	//fprintf(out_fp, "> %d %s %s %s %s\n", member_type, name, SSN, ID, password);
	
	
}

LogInUI::LogInUI(FILE* in_fp, FILE* out_fp, MemberCollection* memberCollection) {
	this->in_fp = in_fp;
	this->out_fp = out_fp;
	this->memberCollection = memberCollection;
	logIn = new LogIn(memberCollection);
}

void LogInUI::fillinIDPW() {
	char ID[MAX_STRING];
	char password[MAX_STRING];
	
	fscanf(in_fp, "%s %s\n", ID, password);
	Member *loginMember= logIn->logIn(ID, password);

	fprintf(out_fp, "2.1. 로그인\n");
	fprintf(out_fp, "> %s %s\n",loginMember->getID(), loginMember->getPassword());

	
}

LogOutUI::LogOutUI(FILE*in_fp, FILE* out_fp, MemberCollection* memberCollection)
{
	this->in_fp = in_fp;
	this->out_fp = out_fp;
	this->memberCollection = memberCollection;
	logOut = new LogOut(memberCollection);
}
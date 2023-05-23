#pragma once
#include <iostream>
#include <fstream>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#include "Control.h"
using namespace std;

class JoinUI {

private:

	FILE* in_fp;
	FILE* out_fp;
	Join* join;
	MemberCollection* memberCollection;
public:
	JoinUI(FILE* in_fp, FILE* out_fp, MemberCollection *memberCollection);
	void createNewMember();	//join할 때 새로운 멤버 만들기 위해
	
};

class LogInUI {
private:
	FILE* in_fp;
	FILE* out_fp;
	LogIn* logIn;
	MemberCollection* memberCollection;
public:
	LogInUI(FILE* in_fp, FILE* out_fp, MemberCollection *memberCollection);
	void fillinIDPW();

};

class DeleteMembershipUI {
private:
	FILE* in_fp;
	FILE* out_fp;
	DeleteMembership* deleteMembership;
	MemberCollection* memberCollection;
public: 
	DeleteMembershipUI(FILE* in_fp, FILE* out_fp, MemberCollection* memberCollection);
	void deleteMember();

};

class LogOutUI {
private:
	FILE* in_fp;
	FILE* out_fp;
	LogOut* _logOut;
	MemberCollection* memberCollection;
public:
	LogOutUI(FILE* in_fp, FILE* out_fp, MemberCollection* memberCollection);
	void logOut();



};

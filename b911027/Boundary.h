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

class LoginUI {
private:
	FILE* in_fp;
	FILE* out_fp;
	LogIn* logIn;
	MemberCollection* memberCollection;
public:
	LoginUI(FILE* in_fp, FILE* out_fp, MemberCollection *memberCollection);
	void fillinIDPW();

};

class DeleteMembershipUI {
private:
public: 
	void deleteMember();

};

class LogOutUI {
private:
public:
	void logOut();



};
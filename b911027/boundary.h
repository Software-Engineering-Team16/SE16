#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "control.h"
extern FILE* in_fp;
extern FILE* out_fp;
extern MemberList* memberList;


//1.1 ȸ�� ����
class JoinUI 
{
	//������ �տ� p ���̱�
private:
	Join* pJoin;

public:
	JoinUI();
	void createNewMember();
};

//2.1 �α���
class LogInUI 
{
private:
	LogIn* pLogIn;

public:
	LogInUI();
	void inputIDPW();  
};

//2.2 �α׾ƿ�
class LogOutUI 
{
private:
	LogOut* pLogOut;

public:
	LogOutUI();
	void logOut();
};

//1.2 ȸ�� Ż��
class DeleteMembershipUI 
{
private:
	DeleteMembership* pDeleteMembership;

public: 
	DeleteMembershipUI();
	void deleteMembership();
};

//ä������ ���->ȸ�� ȸ���� ��� 3 1 [����] [�ο� ��] [��û ������] 
class AddJobAdUI
{
private:
	AddJobAd* pAddJobAd; //control 
	//MemberList* pMemberList;
	//JobAdList* pJobAdList; //ȸ��ȸ���� private member�� �־�� �ϴµ�...
	//applyList�� ȸ��ȸ���� ���... ���⼭ �������� �ʾƵ� ���� �ʳ�
	//Member* pMember; //�α��� �ϴ� ���� ȸ�� ȸ�� ��ȯ �ؾ���<-���������� �ϸ� ���� ������...
public:
	AddJobAdUI();
	void addJobAd();
};

//ä������ ����Ʈ ��ȸ->ȸ�� ȸ���� ��ȸ
class ListJobAdUI //CheckJobAdListUI
{
private: 
	//Member* pMember;
	ListJobAd* pListJobAd;
public:
	ListJobAdUI();
	void viewListJobAd();
};

//���� �α��� �� member�� �ϳ� ���̴�
//������ ������ ����� ä�������� �˻��� �� �־�� �Ѵ�

/*
/ä������ �� ��ȸ
class CheckJobAdUI
{
private: 
	//Member* pMember;
	CheckJobAd* pCheckJobAd;
public:


};
*/

//ä�� ���� �˻�
class SearchJobUI
{

};

//ä�� ����
class ApplyUI
{

};

//���� ���� ��ȸ
class CheckApplyInfoUI
{

};
//���� ���
class CancelApplyInfoUI
{

};

//���� ���� ���
class ApplyStatisticsUI
{

};

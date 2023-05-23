#include "Control.h"



Member* Join::createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password) {
    Member* newMember = nullptr;
    if (member_type == 1) {
        newMember = new CompanyMember(name, SSN, ID, password);
        cout << "회사회원 생성" << endl;
      
      
        // 회사 회원 객체 생성 및 처리
    }
    else {
        newMember = new NormalMember(name, SSN, ID, password);
        // 일반 회원 객체 생성 및 처리
        cout << "일반회원 생성" << endl;
     
        
      
    }
   
    memberCollection->addMember(newMember);
    
  
    return newMember;

    
    
}


Member* LogIn::logIn(const char* ID, const char* password)
{

  
   Member *member= memberCollection->findMember(ID, password);
   member->setIsLogin(true);
   memberCollection->showMember();
   return member;
}

Member* LogOut::logOut()
{
    Member *member= memberCollection->findLogInMember();
    member->setIsLogin(false);
    memberCollection->showMember();
    return member;
}
char* DeleteMembership::deleteMember()
{
    Member* member = memberCollection->findFirst();
    char* ID = new char[MAX_STRING];

    strncpy(ID, member->getID(), MAX_STRING - 1);
    memberCollection->deleteMember(member);
    memberCollection->showMember();
    return ID;
}

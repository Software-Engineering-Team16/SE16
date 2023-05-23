#include "Control.h"



Member* Join::createMember(int member_type, const char* name, const char* SSN, const char* ID, const char* password) {
    Member* newMember = nullptr;
    if (member_type == 1) {
        newMember = new CompanyMember(name, SSN, ID, password);
        cout << "ȸ��ȸ�� ����" << endl;
      
      
        // ȸ�� ȸ�� ��ü ���� �� ó��
    }
    else {
        newMember = new NormalMember(name, SSN, ID, password);
        // �Ϲ� ȸ�� ��ü ���� �� ó��
        cout << "�Ϲ�ȸ�� ����" << endl;
     
        
      
    }
   
    memberCollection->addMember(newMember);
    
  
    return newMember;

    
    
}

Member* MemberCollection::findMember(const char* ID, const char* password) {
    for (Member* member : membersList) {
        if (strcmp(member->getID(), ID) == 0 && strcmp(member->getPassword(), password) == 0) {
            return member;
        }
    }
    return nullptr;
}
Member* LogIn::logIn(const char* ID, const char* password)
{
    return memberCollection->findMember(ID, password);
}
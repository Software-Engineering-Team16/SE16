#include "Boundary.h"
#include "Control.h"
extern FILE* in_fp;
extern FILE* out_fp;

SearchJobAdUI::SearchJobAdUI(FILE* in_fp, FILE* out_fp)
{
	
}
void SearchJobAdUI::startInterface(SearchJobAd* pSearchJobAdUI)
{
	char name[MAX_STRING];
	char SSN[MAX_STRING];
    char work[MAX_STRING];
	int employeeNumber[MAX_STRING] = 0;
	char deadline[MAX_STRING];

	fscanf(in_fp, "%s %s %s %d %s", name, SSN, work, employeeNumber, deadline);
	
	fprintf(out_fp, "4.1 채용 정보 검색\n");
	fprintf(out_fp, "> %s %s %s %d %s\n", name, SSN, work, employeeNumber, deadline);
	
}

ApplyUI::ApplyUI(FILE* in_fp, FILE* out_fp) {

	logIn = new LogIn(memberCollection);
}
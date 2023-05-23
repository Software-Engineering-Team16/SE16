#include <iostream>
#include <fstream>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#include "control.h"
using namespace std;

class AddJobAdUI {
private:
	FILE* in_fp;
	FILE* out_fp;
	AddJobAd* addJobAd;

public:
	AddJobAdUI(FILE* in_fp, FILE* out_fp);
};

class ListJobAdUI {
private:
	FILE* in_fp;
	FILE* out_fp;
	ListJobAd* listJobAd;
	JobAdList* jobAdList;
public:
	ListJobAdUI(FILE* in_fp, FILE* out_fp);
	void listJobAd();
};

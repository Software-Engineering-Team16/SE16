#pragma once
#include <iostream>
#include <fstream>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#include "Control.h"
using namespace std;
FILE* in_fp;
FILE* out_fp;

// 4.1 채용 정보 검색
class SearchJobAdUI {

private:

public:
	SearchJobAdUI(FILE* in_fp, FILE* out_fp);
    void 
};


// 4.2 채용 지원
class ApplyUI {

private:
    ApplyInfoList* ApplyInfoList;

public:
	ApplyUI(FILE* in_fp, FILE* out_fp);
    void addApplyList()
};
#endif
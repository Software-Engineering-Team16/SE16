#pragma once
#include <iostream>
#include <fstream>
//일단 다하고 아침에 나누기
// 지원자수 통계
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#include "control_statistics.h"
using namespace std;

class ApplicantNumberStatisticsUI {
private:
	ApplicantNumberStatistics* pApplicantNumberStatistics();

public:
	ApplicantNumberStatistics();
	viewApplicantNumberStatistics();
};



class ApplyStatisticsUI {
private:
	ApplyStatistics& pApplyStatistics();

public:
	ApplyStatistics();
	viewApplyStatistics();
	

};



class CancelApplyInfoUI {
private:
	CancelApplyInfo* pCancelApplyInfo();
	
public:
	CancelApplyInfo();
	viewCancelApplyInfo();

};


class CheckApplyInfoUI {
private:
	CheckApplyInfo* pCheckApplyInfo();

public:
	CheckApplyInfo();
	viewCheckApplyInfo();

};

#include <iostream>
#include <fstream>
//일단 다하고 아침에 나누기
// 지원자수 통계
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#include "control_statistics.h"
using namespace std;

class ApplicantNumberStatisticsUI {
public:
	ApplicantNumberStatisticsUI();
	void startInterface(ApplicantNumberStatisticsUI* pApplicantNumberStatisticsUI);
};



class ApplyStatisticsUI {
public:
	ApplyStatisticsUI();
	void startInterface(ApplyStatisticsUI* pApplyStatisticsUI);


};



class CancelApplyInfoUI {
public:
	CancelApplyInfoUI();
	void startInterface(CancelApplyInfoUI* pCancelApplyInfoUI);


};

class ApplyInfoList {
public:
	ApplyInfoList();
	void startInterface(ApplyInfoList* pApplyInfoList);


};


class CheckApplyInfoUI {
public:
	CheckApplyInfoUI();
	void startInterface(CheckApplyInfoUI* pCheckApplyInfoUI);


};

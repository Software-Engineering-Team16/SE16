#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Boundary.h"

        using namespace std;

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
        FILE* in_fp, * out_fp;
        MemberList* memberList = new MemberList();
        ApplyList* applyList = new ApplyList(); //지원
        EmployList* employList = new EmployList();//채용
        


        void doTask();
        void program_exit();
        int main()
        {
            // 파일 입출력을 위한 초기화
            in_fp = fopen(INPUT_FILE_NAME, "r+");
            out_fp = fopen(OUTPUT_FILE_NAME, "w+");

            doTask();

            return 0;
        }
        void doTask()
        {

            int menu_level_1 = 0, menu_level_2 = 0;
            int is_program_exit = 0;

            //JobAdList* jobAdList = new JobAdList();
            //ApplyInfoList* applyInfoList = new ApplyInfoList();


            while (!is_program_exit)
            {

                // 입력파일에서 메뉴 숫자 2개를 읽기
                fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

                switch (menu_level_1)
                {
                
                case 4:
                    switch (menu_level_2)
                    {
                    case 1:
                        cout << "채용 정보 검색" << endl;

                        break;
                    case 2:
                        cout << "채용 지원" << endl;

                        break;
                    case 3:
                        cout << "지원 정보 조회" << endl; //view 
                        CheckApplyInfoUI checkApplyInfoUI = CheckApplyInfoUI();
                        listCheckApplyInfoUI.viewListCheckApplyInfo();
                        break;
                    case 4:
                        cout << "지원 취소" << endl;
                        
                        CancelApplyInfo()
                        //도중에 리스트 삭제
                        //마지막에 view
                        CheckApplyInfoUI();
                        listCheckApplyInfoUI.viewListCheckApplyInfo();

                        break;
                    }
                    break;

                case 5:
                    switch (menu_level_2)
                    {
                    case 1:
                        cout << "지원 정보 통계" << endl;
               
                        //리스트 조회
                        //리스트 배열 조회가 있어야 됨
                        break;
                    }
                    break;
                case 6:
                    switch (menu_level_2)
                    {
                    case 1:

                        program_exit();
                        is_program_exit = 1;
                        break;
                    }
                    break;
                }
            }
            return;
        }

        void program_exit()
        {
            printf("종료\n");
            fprintf(out_fp, "6.1. 종료\n");
        }
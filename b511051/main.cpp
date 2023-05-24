#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Boundary.h"

        using namespace std;

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
        FILE* in_fp, * out_fp;
        MemberList* memberList = new MemberList();
        ApplyList* applyList = new ApplyList(); //����
        EmployList* employList = new EmployList();//ä��
        


        void doTask();
        void program_exit();
        int main()
        {
            // ���� ������� ���� �ʱ�ȭ
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

                // �Է����Ͽ��� �޴� ���� 2���� �б�
                fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

                switch (menu_level_1)
                {
                
                case 4:
                    switch (menu_level_2)
                    {
                    case 1:
                        cout << "ä�� ���� �˻�" << endl;

                        break;
                    case 2:
                        cout << "ä�� ����" << endl;

                        break;
                    case 3:
                        cout << "���� ���� ��ȸ" << endl; //view 
                        CheckApplyInfoUI checkApplyInfoUI = CheckApplyInfoUI();
                        listCheckApplyInfoUI.viewListCheckApplyInfo();
                        break;
                    case 4:
                        cout << "���� ���" << endl;
                        
                        CancelApplyInfo()
                        //���߿� ����Ʈ ����
                        //�������� view
                        CheckApplyInfoUI();
                        listCheckApplyInfoUI.viewListCheckApplyInfo();

                        break;
                    }
                    break;

                case 5:
                    switch (menu_level_2)
                    {
                    case 1:
                        cout << "���� ���� ���" << endl;
               
                        //����Ʈ ��ȸ
                        //����Ʈ �迭 ��ȸ�� �־�� ��
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
            printf("����\n");
            fprintf(out_fp, "6.1. ����\n");
        }
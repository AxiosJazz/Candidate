#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "user.h"
#include "menu.h"
#include "function.h"

extern int tot, N, vote_end;
extern struct user user[100];
extern int choice_main, choice_admin, choice_logon_regist, choice_user;
extern char name[20], passwd[20];

int main()
{
    while (1)
    {
    	system("color f5");//�ı����̨��ɫ 
        menu_begin();
        Sleep(1500);
        load(user);//�����û����ݵ��ڴ�ṹ�������� 
        system("cls");
        menu_main();
        switch (choice_main)//��Ϊ����Ա����ѡ�ߡ���ͨ�û�����ģʽ 
        {
            case 1:
            {
                system("cls");
                menu_logon();
                if ((strcmp(name, "admin") == 0) && (strcmp(passwd, "passwd") == 0))//���ù���Ա�˺����ڹ���Ա��¼ 
                {
                    system("cls");
                    menu_admin();
                    switch (choice_admin)//����Ա�ɽ��еĲ鿴�û���Ϣ������ͶƱ���ޡ�����������ֲ��� 
                    {
                        case 1:
                        {
                        	system("cls");
                        	information_condidate(user, tot);
                        	printf("\n");
                        	information_users(user, tot);
                            break;
                        }
                        case 2:
                        {
                        	system("cls");
                        	printf("        ������ͶƱ����ֵN��");
                        	scanf("%d", &N);
                        	printf("\n");
                        	printf("        �޸ĳɹ���\n");
                            break;
                        }
                        case 3:
                        {
                        	vote_end = 1;
                        	system("cls");
                            printf("        ��������ɹ���\n");
                            break;
                        }
                        default:
                        {
                        	system("cls");
                        	error_input();
                        }
                    }
                }
                else
                {
                	system("cls");
                	error_logon();
                }
                break;
            }
            case 2:
            {
            	system("cls");
            	menu_logon_regist();
                switch (choice_logon_regist)//��¼ORע�� 
                {
                    case 1:
                    {
                        system("cls");
                        menu_logon();
                        int i;
                        int flag = 0;
                        for (i=0; i<tot; i++)
                        {
                            if ((strcmp(user[i].name, name) == 0) && (strcmp(user[i].passwd, passwd) == 0) && user[i].user_type == 0)//��ѡ�ߵ�¼ֻ�ܲ鿴ͶƱ��� 
                            {
                            	flag = 1;
                                system("cls");
                                information_condidate(user, tot);
                                break;
                            }
                        }
                        if (flag == 0)
                        {
                        	system("cls");
                        	error_logon();
                        }
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        menu_regist();
                        regist();
                        break;
                    }
                    default:
                    {
                    	system("cls");
                    	error_input();
                    }
                }
                break;
            }
            case 3:
            {
            	system("cls");
            	menu_logon_regist();
                switch (choice_logon_regist)//��¼ORע�� 
                {
                    case 1:
                    {
                        system("cls");
                        menu_logon();
                        int i;
                        int flag = 0;
                        for (i=0; i<tot; i++)
                        {
                            if ((strcmp(user[i].name, name) == 0) && (strcmp(user[i].passwd, passwd) == 0) && user[i].user_type == 1)
                            {
                            	flag = 1;
                                system("cls");
                                menu_user();
                                switch (choice_user)//��ͨ�û��ɽ��в�ѯͶƱ�����������ѡ�ߡ�ͶƱ���ֲ��� 
                                {
                                    case 1:
                                    {
                                    	system("cls");
                                    	information_condidate(user, tot);
                                        break;
                                    }
                                    case 2:
                                    {
                                        system("cls");
                                        search();
                                        break;
                                    }
                                    case 3:
                                    {
                                    	system("cls");
                                        vote();
                                        break;
                                    }
									default:
									{
										system("cls");
										error_input();
									}
                                }
                                break;
                            }
                        }
                        if (flag == 0)
                        {
                        	system("cls");
                        	error_logon();
                        }
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        menu_regist();
                        regist();
                        break;
                    }
                    default:
                    {
                    	system("cls");
                    	error_input();
                    }
                }
                break;
            }
            case 4://�˳�ģ��ͶƱС���� 
            {
            	system("cls");
            	menu_end();
            	exit(0);
            }
            default:
            {
            	system("cls");
            	error_input();
            }
        }
        dump(user, tot);//ÿ��ѭ���󵼳���ǰ�û���Ϣ�������ļ� 
        system("pause");
    }
    return 0;
}

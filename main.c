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
    	system("color f5");//改变控制台颜色 
        menu_begin();
        Sleep(1500);
        load(user);//加载用户数据到内存结构体数组中 
        system("cls");
        menu_main();
        switch (choice_main)//分为管理员、参选者、普通用户三种模式 
        {
            case 1:
            {
                system("cls");
                menu_logon();
                if ((strcmp(name, "admin") == 0) && (strcmp(passwd, "passwd") == 0))//内置管理员账号用于管理员登录 
                {
                    system("cls");
                    menu_admin();
                    switch (choice_admin)//管理员可进行的查看用户信息、设置投票上限、发布结果三种操作 
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
                        	printf("        请输入投票上限值N：");
                        	scanf("%d", &N);
                        	printf("\n");
                        	printf("        修改成功！\n");
                            break;
                        }
                        case 3:
                        {
                        	vote_end = 1;
                        	system("cls");
                            printf("        结果发布成功！\n");
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
                switch (choice_logon_regist)//登录OR注册 
                {
                    case 1:
                    {
                        system("cls");
                        menu_logon();
                        int i;
                        int flag = 0;
                        for (i=0; i<tot; i++)
                        {
                            if ((strcmp(user[i].name, name) == 0) && (strcmp(user[i].passwd, passwd) == 0) && user[i].user_type == 0)//参选者登录只能查看投票情况 
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
                switch (choice_logon_regist)//登录OR注册 
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
                                switch (choice_user)//普通用户可进行查询投票情况、搜索参选者、投票三种操作 
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
            case 4://退出模拟投票小程序 
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
        dump(user, tot);//每次循环后导出当前用户信息到数据文件 
        system("pause");
    }
    return 0;
}

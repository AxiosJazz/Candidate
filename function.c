#include <stdio.h>
#include "user.h"


/*
	��Դ�ļ���������������ʹ�õ��������Զ��庯�� 
*/


extern int tot, N, vote_end;
extern struct user user[100];
extern int choice_main, choice_admin, choice_logon_regist, choice_user;
extern char name[20], phone[12], passwd[20];
extern char search_name[20];

/*
	�βΣ�user��������û����ݵĽṹ�����飻tot���������ܳ���
	����ֵ����
	�����ܣ���ʾÿһ����ͨ�û�����Ϣ 
*/ 
void information_users(struct user user[], int tot)
{
	int i;
	printf(" ----------------------------------------------------- \n");
    printf("|                ע���û���Ϣ��                       |\n");
    printf("|         �û���\t�ֻ���\t\tͶƱ����      |\n");
    for (i=0; i<tot; i++)
    {
        if (user[i].user_type == 1)//user_type = 1 ˵������ͨ�û� 
        {
            printf("|         %s\t%s\t%d             |\n", user[i].name, user[i].phone, user[i].vote_num);
        }
    }
    printf(" ----------------------------------------------------- \n");
}

/*
	�βΣ�user��������û����ݵĽṹ�����飻n���������ܳ��ȣ�user_condidate���������洢��ѡ����Ϣ�Ľṹ������ 
	����ֵ������user_condidate�ṹ������ĳ��� 
	�����ܣ����ܵ������洢�û���Ϣ�Ľṹ��������ɸѡ����ѡ�ߵ���Ϣ������user_condidate�ṹ�������У�����user_condidate���鰴��vote_num��Ա�Ӹߵ������� 
*/ 
int sort(struct user user[], int n, struct user user_condidate[])
{
    int i, j;
    int m = 0;
    struct user temp;
    for (i=0; i<n; i++)
    {
        if (user[i].user_type == 0)
        {
            user_condidate[m] = user[i];
            m++;
        }
    }
    for (i=0; i<m; i++)//ѡ�����򷨰��յ�Ʊ���Ӹߵ������� 
    {
        for (j=i + 1; j<m; j++)
        {
            if (user_condidate[i].vote_num < user_condidate[j].vote_num)
            {
                temp = user_condidate[i];
                user_condidate[i] = user_condidate[j];
                user_condidate[j] = temp;
            }
        }
    }
    return m;
}

/*
	�βΣ�user��������û����ݵĽṹ�����飻tot���������ܳ���
	����ֵ����
	�����ܣ���ʾÿһ����ѡ�ߵ���Ϣ�����ǰ���Ʊ���Ӹߵ�����ʾ���������ÿһλ�ĵ�Ʊ�� 
*/ 
void information_condidate(struct user user[], int tot)
{
    int i;
    double sum = 0;
    int tot_condidate = 0;
    struct user user_codidate[100];
    printf(" ----------------------------------------------------- \n");
    printf("|                    ��ѡ����Ϣ��                     |\n");
    if (vote_end == 1)//���ݹ���Ա�Ƿ񷢲�ͶƱ�����������ʾ������û�з���ʱ����ʾ��������Ʊ�� 
    {
        printf("|          ��ѡ����\tƱ��\t����\t�ٷֱ�        |\n");
        for (i=0; i<tot; i++)
        {
        	if (user[i].user_type == 0)
        	{
            	sum += user[i].vote_num;	        	
	        }
        }
        tot_condidate = sort(user, tot, user_codidate);
        if (sum != 0)//����û���κ�һ�˵�Ʊ�����������������²���ʾ��Ʊ�� 
        {
            for (i=0; i<tot_condidate; i++)
            {
                if (user_codidate[i].user_type == 0)
                {
                    printf("|          %s\t%d\t%d\t%.2f%%        |\n", user_codidate[i].name, user_codidate[i].vote_num, i + 1, user_codidate[i].vote_num / sum * 100);
                }
            }
            printf(" ----------------------------------------------------- \n");
        }
        else
        {
            for (i=0; i<tot_condidate; i++)
            {
                if (user_codidate[i].user_type == 0)
                {
                    printf("|          %s\t%d\t%d                     |\n", user_codidate[i].name, user_codidate[i].vote_num, i + 1);
                }
            }
            printf(" ----------------------------------------------------- \n");
        }
    }
    else
    {
        printf("|                 ��ѡ����\tƱ��                  |\n");
        tot_condidate = sort(user, tot, user_codidate);
        for (i=0; i<tot_condidate; i++)
        {
        	if (user_codidate[i].user_type == 0)
        	{
        		printf("|                 %s\t%d                     |\n", user_codidate[i].name, user_codidate[i].vote_num);
        	}
        }
        printf(" ----------------------------------------------------- \n");
    }
}

/*
	�βΣ��� 
	����ֵ���� 
	�����ܣ������û�ע�ᣬ��ע����Ϣ����user�ṹ�������� 
*/ 
void regist()
{
	int i;
	int flag = 1;//��������û����Ƿ�ռ�� 
	for (i=0; i<tot; i++)
 	{
  		if (strcmp(user[i].name, name) == 0)
  		{
    		flag = 0;
    		system("cls");
    		error_regist();
    		break;
      	}
    }
    if (flag == 1 && choice_main == 2)
    {
   		strcpy(user[tot].name, name);
   		strcpy(user[tot].phone, phone);
   		strcpy(user[tot].passwd, passwd);
   		user[tot].vote_num = 0;
   		user[tot].user_type = 0;//ע��ʱ������ע���ѡ��OR��ͨ�û� 
   		tot++;
    }
    if (flag == 1 && choice_main == 3)
    {
    	strcpy(user[tot].name, name);
    	strcpy(user[tot].phone, phone);
    	strcpy(user[tot].passwd, passwd);
    	user[tot].vote_num = 0;
    	user[tot].user_type = 1;
    	tot++;
    }
}

/*
	�βΣ��� 
	����ֵ���� 
	�����ܣ�ʵ����ͨ�û����������ܣ���ʾ���������Ĳ�ѡ����Ϣ 
*/ 
void search()
{
	int i;
	int flag = 0;//��������Ƿ���������ѡ�� 
	printf("        �������������ѡ�ߣ�");
	scanf("%s", search_name);
	printf("\n");
	for (i=0; i<tot; i++)
	{
		if ((strcmp(user[i].name, search_name) == 0) && user[i].user_type == 0)
		{
			flag = 1;
			printf(" ----------------------------------------------------- \n");
			printf("|                 ��ѡ����\tƱ��                  |\n");
			printf("|                                                     |\n");
			printf("|                 %s\t%d                     |\n", user[i].name, user[i].vote_num);
			printf("|                                                     |\n");
			printf(" ----------------------------------------------------- \n");
		}
	}
	if (flag == 0)
	{
		printf("        δ�ҵ��ò�ѡ�ߣ�\n");
	}
}

/*
	�βΣ��� 
	����ֵ���� 
	�����ܣ���ͨ�û���ͶƱ���� 
*/ 
void vote()
{
	int i, j;
	int flag = 0;//������Ǳ�ͶƱ�Ĳ�ѡ���Ƿ���� 
	printf("        ��ѡ��ͶƱ��ѡ�ߣ�");
	scanf("%s", search_name);
	printf("\n");
	for (i=0; i<tot; i++)
	{
		if ((strcmp(user[i].name, search_name) == 0) && user[i].user_type == 0)
		{
			flag = 1;
		}
	}
	if (flag == 1)
	{
		for (i=0; i<tot; i++)
		{
			if ((strcmp(user[i].name, name) == 0) && user[i].user_type == 1 && user[i].vote_num < N)//ֻ���û���ͶƱ����С��ͶƱ�����޲���ͶƱ 
			{
				for (j=0; j<tot; j++)
				{
					if ((strcmp(user[j].name, search_name) == 0) && user[j].user_type == 0)
					{
						user[j].vote_num++;//��ѡ��Ʊ��+1 
						user[i].vote_num++;//��ͨ�û���ͶƱ����+1 
						printf("        ͶƱ��ɣ���л����֧�֣�\n");
						printf("\n");
					}
				}
			}
			if ((strcmp(user[i].name, name) == 0) && user[i].user_type == 1 && user[i].vote_num >= N)
			{
				printf("        ����ͶƱ�����Ѵﵽ���ޣ�\n");
			}
		}
	}
	else
	{
		printf("        δ�ҵ��ò�ѡ�ߣ�\n");
	}
}

/*
	�βΣ�userΪ�ڴ��д洢�û����ݵĽṹ������ 
	����ֵ���� 
	�����ܣ��������ļ��м����û����ݣ���������ʽ�� 
*/ 
void load(struct user user[])
{
    FILE *fp;
    if ((fp=fopen("user.db", "ab+")) == NULL )
    {
        puts("Fail to open file!\n");
        exit(0);
    }
    tot = 0;
    while (!feof(fp))//ͨ��feof()�����ж��Ƿ��ȡ���ļ�β 
    {
        fread(user + tot, sizeof(struct user), 1, fp);
        tot++;
    }
    tot--;//����δ֪ԭ�� tot �ܻ�� 1 ������ڴ˴���Ϊ -1 
    fclose(fp);
}

/*
	�βΣ�userΪ�ڴ��д洢�û����ݵĽṹ�����飬totΪ���鳤��Ҳ���û����� 
	����ֵ���� 
	�����ܣ����ڴ��е��û����ݵ����������ļ��У���������ʽ�� 
*/ 
void dump(struct user user[], int tot)
{
    FILE *fp;
    if ((fp=fopen("user.db", "wb+")) == NULL )
    {
        puts("Fail to open file!\n");
        exit(0);
    }
    fwrite(user, sizeof(struct user), tot, fp);
    fclose(fp);
}

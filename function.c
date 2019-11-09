#include <stdio.h>
#include "user.h"


/*
	该源文件包含主程序中所使用到的所有自定义函数 
*/


extern int tot, N, vote_end;
extern struct user user[100];
extern int choice_main, choice_admin, choice_logon_regist, choice_user;
extern char name[20], phone[12], passwd[20];
extern char search_name[20];

/*
	形参：user传入存有用户数据的结构体数组；tot传入数组总长度
	返回值：无
	程序功能：显示每一个普通用户的信息 
*/ 
void information_users(struct user user[], int tot)
{
	int i;
	printf(" ----------------------------------------------------- \n");
    printf("|                注册用户信息：                       |\n");
    printf("|         用户名\t手机号\t\t投票次数      |\n");
    for (i=0; i<tot; i++)
    {
        if (user[i].user_type == 1)//user_type = 1 说明是普通用户 
        {
            printf("|         %s\t%s\t%d             |\n", user[i].name, user[i].phone, user[i].vote_num);
        }
    }
    printf(" ----------------------------------------------------- \n");
}

/*
	形参：user传入存有用户数据的结构体数组；n传入数组总长度；user_condidate传入用来存储参选者信息的结构体数组 
	返回值：返回user_condidate结构体数组的长度 
	程序功能：从总的用来存储用户信息的结构体数组中筛选出参选者的信息并存入user_condidate结构体数组中，并对user_condidate数组按照vote_num成员从高到低排序 
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
    for (i=0; i<m; i++)//选择排序法按照得票数从高到低排序 
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
	形参：user传入存有用户数据的结构体数组；tot传入数组总长度
	返回值：无
	程序功能：显示每一个参选者的信息，且是按照票数从高到低显示，并计算出每一位的得票率 
*/ 
void information_condidate(struct user user[], int tot)
{
    int i;
    double sum = 0;
    int tot_condidate = 0;
    struct user user_codidate[100];
    printf(" ----------------------------------------------------- \n");
    printf("|                    参选者信息：                     |\n");
    if (vote_end == 1)//根据管理员是否发布投票结果有两种显示方案，没有发布时不显示排名及得票率 
    {
        printf("|          参选对象\t票数\t排名\t百分比        |\n");
        for (i=0; i<tot; i++)
        {
        	if (user[i].user_type == 0)
        	{
            	sum += user[i].vote_num;	        	
	        }
        }
        tot_condidate = sort(user, tot, user_codidate);
        if (sum != 0)//处理没有任何一人得票的特殊情况，该情况下不显示得票率 
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
        printf("|                 参选对象\t票数                  |\n");
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
	形参：无 
	返回值：无 
	程序功能：用于用户注册，将注册信息存入user结构体数组中 
*/ 
void regist()
{
	int i;
	int flag = 1;//用来标记用户名是否被占用 
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
   		user[tot].user_type = 0;//注册时分类型注册参选者OR普通用户 
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
	形参：无 
	返回值：无 
	程序功能：实现普通用户的搜索功能，显示出搜索到的参选者信息 
*/ 
void search()
{
	int i;
	int flag = 0;//用来标记是否搜索到参选者 
	printf("        请输入待搜索参选者：");
	scanf("%s", search_name);
	printf("\n");
	for (i=0; i<tot; i++)
	{
		if ((strcmp(user[i].name, search_name) == 0) && user[i].user_type == 0)
		{
			flag = 1;
			printf(" ----------------------------------------------------- \n");
			printf("|                 参选对象\t票数                  |\n");
			printf("|                                                     |\n");
			printf("|                 %s\t%d                     |\n", user[i].name, user[i].vote_num);
			printf("|                                                     |\n");
			printf(" ----------------------------------------------------- \n");
		}
	}
	if (flag == 0)
	{
		printf("        未找到该参选者！\n");
	}
}

/*
	形参：无 
	返回值：无 
	程序功能：普通用户的投票功能 
*/ 
void vote()
{
	int i, j;
	int flag = 0;//用来标记被投票的参选者是否存在 
	printf("        请选择被投票参选者：");
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
			if ((strcmp(user[i].name, name) == 0) && user[i].user_type == 1 && user[i].vote_num < N)//只有用户的投票总数小于投票数上限才能投票 
			{
				for (j=0; j<tot; j++)
				{
					if ((strcmp(user[j].name, search_name) == 0) && user[j].user_type == 0)
					{
						user[j].vote_num++;//参选者票数+1 
						user[i].vote_num++;//普通用户的投票总数+1 
						printf("        投票完成，感谢您的支持！\n");
						printf("\n");
					}
				}
			}
			if ((strcmp(user[i].name, name) == 0) && user[i].user_type == 1 && user[i].vote_num >= N)
			{
				printf("        您的投票次数已达到上限！\n");
			}
		}
	}
	else
	{
		printf("        未找到该参选者！\n");
	}
}

/*
	形参：user为内存中存储用户数据的结构体数组 
	返回值：无 
	程序功能：从数据文件中加载用户数据（二进制形式） 
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
    while (!feof(fp))//通过feof()函数判断是否读取到文件尾 
    {
        fread(user + tot, sizeof(struct user), 1, fp);
        tot++;
    }
    tot--;//由于未知原因 tot 总会多 1 ，因此在此处人为 -1 
    fclose(fp);
}

/*
	形参：user为内存中存储用户数据的结构体数组，tot为数组长度也即用户总数 
	返回值：无 
	程序功能：将内存中的用户数据导出到数据文件中（二进制形式） 
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

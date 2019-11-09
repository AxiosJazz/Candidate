#include "user.h"


/* 
	该源文件存储程序中使用到的外部引用变量
	以下为每一个变量用途说明
	
	tot：	记录用户数据文件中存储的用户数量
	
	vote_end：	标记是否发布投票结果
	
	N：	用户投票数量上限
	
	user[100]：	结构体数组用来存储数据文件中用户的信息
	
	choice_*：	该类变量配合 switch 语句使用 
	
	name, phone, passwd：	注册或登录时用来获取用户输入的信息
	
	search_name：	 普通用户执行搜索或投票功能时所选择的参选者用户名 
*/ 


int tot, vote_end, N = 3;
struct user user[100];
int choice_main, choice_admin, choice_logon_regist, choice_user;
char name[20], phone[12], passwd[20];
char search_name[20];

#include "user.h"


/* 
	��Դ�ļ��洢������ʹ�õ����ⲿ���ñ���
	����Ϊÿһ��������;˵��
	
	tot��	��¼�û������ļ��д洢���û�����
	
	vote_end��	����Ƿ񷢲�ͶƱ���
	
	N��	�û�ͶƱ��������
	
	user[100]��	�ṹ�����������洢�����ļ����û�����Ϣ
	
	choice_*��	���������� switch ���ʹ�� 
	
	name, phone, passwd��	ע����¼ʱ������ȡ�û��������Ϣ
	
	search_name��	 ��ͨ�û�ִ��������ͶƱ����ʱ��ѡ��Ĳ�ѡ���û��� 
*/ 


int tot, vote_end, N = 3;
struct user user[100];
int choice_main, choice_admin, choice_logon_regist, choice_user;
char name[20], phone[12], passwd[20];
char search_name[20];

#ifndef USER
#define USER

    struct user
    {
        char name[20];		//�û��� 
        char phone[12];		//ע��绰 
        char passwd[20];	//���� 
        int vote_num;		//��ѡ��Ʊ������ͨ�û���ͶƱ���� 
        int user_type;		//�û����ͣ�0 �����ѡ�ߣ�1 ������ͨ�û� 
    };

#endif // !USER

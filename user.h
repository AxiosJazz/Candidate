#ifndef USER
#define USER

    struct user
    {
        char name[20];		//用户名 
        char phone[12];		//注册电话 
        char passwd[20];	//密码 
        int vote_num;		//参选者票数或普通用户的投票总数 
        int user_type;		//用户类型，0 代表参选者，1 代表普通用户 
    };

#endif // !USER

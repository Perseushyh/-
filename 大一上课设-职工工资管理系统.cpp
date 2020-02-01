#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Staff
{
	int ID;/*职工号*/
	char name[10];/* 姓名*/
	char Dm[10];/*部门*/
	int BS;/*基本工资*/
	int FS;/*职务工资*/
	int Awa;/*津贴*/
	int PF;/*公积金*/
	int Ir;/* 保险*/
	int Pz;/*奖金*/
	int TS;/*总工资*/
	struct Staff* next;/*链表*/
}Staff;
Staff* createdata();/*输入数据*/
void menu1();/*管理员菜单界面*/
void menu2();/*普通职工菜单界面*/
void start();/*开始界面*/
int login();/*登录界面*/
void fliesave1(Staff*);/*文件添加*/
void fliesave2(Staff*);/*文件保存*/
void display(Staff*);/*显示数据*/
Staff* deleteList(Staff* head);/*删除数据*/
Staff* find(Staff* head);/*查找数据*/
Staff* revise(Staff* head);/*修改数据*/
void Sta(Staff* head);/*统计数据*/
Staff* loadfile();/*读取文件*/
int check(int m);/*检查ID合法性*/
Staff* adddata();/*添加职工*/
int main()
{
	Staff* head;
	int m, n, flag;
	start();
	scanf("%d", &m);
	switch (m)
	{
	case 1:
	{
		flag = login();
	}break;
	case 2:
		flag = 0;
		break;
	}
	if (flag)
	{
		menu1();
		scanf("%d", &n);
		while (n)
		{
			switch (n)
			{
			case 1:
			{
				printf("按1新建数据，按2使用添加数据\n");
				int add;
				scanf("%d", &add);
				switch (add)
				{
				case 1:
				{
					head = createdata();
					fliesave2(head);
				}break;
				case 2:
				{
					head = adddata();
					fliesave1(head);
				}break;
				}
			}break;
			case 2:
			{
				head = loadfile();
				display(head);
			}break;
			case 3:
			{
				head = loadfile();
				Staff* L = revise(head);
				fliesave2(L);
			}break;
			case 4:
			{
				head = loadfile();
				find(head);
			}break;
			case 5:
			{
				head = loadfile();
				Staff* L = deleteList(head);
				fliesave2(L);
			}break;
			case 6:
			{
				head = loadfile();
				Sta(head);
			}break;
			}
			menu1();
			scanf("%d", &n);
		}
		printf("感谢使用\n");
	}
	else
	{
		menu2();
		scanf("%d", &n);
		while (n)
		{
			switch (n)
			{

			case 2:
			{
				head = loadfile();
				display(head);
			}break;
			case 3:
			{
				head = loadfile();
				find(head);
			}break;
			case 1:
			{
				head = loadfile();
				Sta(head);
			}break;
			}
			menu2();
			scanf("%d", &n);
		}
		printf("感谢使用\n");
	}

	return 0;
}
void start()
{
	system("cls");
	printf("-------------------| 员工工资管理系统 |-------------------\n");
	printf("     ---------------------|欢迎|---------------------\n");
	printf("                       - 1 -管理员操作                       \n");
	printf("                       - 2 -普通职工查询                       \n");
	printf("                       - 0 -退出                       \n");
}
int login()
{
	system("cls");
	printf("-------------------| 员工工资管理系统 |-------------------\n");
	printf("     ---------------------|欢迎|---------------------\n");
	printf("                        请输入密钥                      \n");
	printf("                       - 0 -退出                       \n");
	int m, n;
	scanf("%d", &m);
	if (m == 1005)
		n = 1;
	else
		n = 0;
	return n;

}
void menu1()
{
	system("cls");
	printf(" ---------------------- | 请选择功能 | ----------------------\n");
	printf("  ==========================================================\n");
	printf("  ||                                                      ||\n");
	printf("  ||    - 1 - 输入       - 2 - 显示       - 3 - 修改      ||\n");
	printf("  ||                                                      ||\n");
	printf("  ||    - 4 - 查找       - 5 - 删除       - 6 - 统计数据  ||\n");
	printf("  ||                                                      ||\n");
	printf("  ||                     - 0 - 退出                       ||\n");
}
void menu2()
{
	system("cls");
	printf(" ---------------------- | 请选择功能 | ----------------------\n");
	printf("  ==========================================================\n");
	printf("  ||                                                      ||\n");
	printf("  ||    - 1 - 统计数据   - 2 - 显示      - 3 - 查找       ||\n");
	printf("  ||                                                      ||\n");
	printf("  ||                     - 0 - 退出                       ||\n");
	printf("  ||                                                      ||\n");
}
Staff* createdata()
{
	Staff* p, * head, * tail;
	int ID, BS, FS, Awa, PF, Ir, Pz, TS, n, m;
	char name[10];
	char Dm[10];
	head = NULL;
	tail = NULL;
	printf("按1逐项输入，按2依人数输入\n");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
	{
		printf("请输入职工号，按0退出\n");
		scanf("%d", &ID);
		while (ID != 0)
		{
			p = (Staff*)malloc(sizeof(Staff));
			p->ID = ID;
			printf("请输入姓名\n");
			scanf("%s", p->name);
			printf("请输入部门名称\n");
			scanf("%s", p->Dm);
			printf("请输入基本工资\n");
			scanf("%d", &p->BS);
			printf("请输入职务工资\n");
			scanf("%d", &p->FS);
			printf("请输入津贴\n");
			scanf("%d", &p->Awa);
			printf("请输入公积金\n");
			scanf("%d", &p->PF);
			printf("请输入保险金额\n");
			scanf("%d", &p->Ir);
			printf("请输入奖金\n");
			scanf("%d", &p->Pz);
			p->TS = p->BS + p->Awa + p->FS + p->Ir + p->Pz + p->PF;
			p->next = NULL;
			if (head == NULL)
				head = p;
			else
				tail->next = p;
			tail = p;
			printf("请输入职工号，按0退出\n");
			scanf("%d", &ID);
		}
	}break;
	case 2:
	{
		int count;
		printf("请输入录入职工人数\n");
		scanf("%d", &count);
		printf("请按顺序输入ID 姓名 部门 基本工资 职务工资 津贴 公积金 保险 奖金\n");
		printf("中间以空格分隔\n");
		for (int i = 1; i <= count; i++)
		{
			p = (Staff*)malloc(sizeof(Staff));
			scanf("%d %s %s %d %d %d %d %d %d\n", &p->ID, &p->name, &p->Dm, &p->BS, &p->FS, &p->Awa, &p->Ir, &p->PF, &p->Pz);
			p->TS = p->BS + p->Awa + p->FS + p->Ir + p->Pz + p->PF;
			p->next = NULL;
			if (head == NULL)
				head = p;
			else
				tail->next = p;
			tail = p;
		}
	}break;
	}
	printf("输入成功\n");
	system("pause");
	return head;
}

void fliesave1(Staff* head)
{
	Staff* p;
	FILE* fp;
	if ((fp = fopen("staff.txt", "a")) == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	for (p = head; p != NULL; p = p->next)
	{
		fprintf(fp, "%d     %s     %s      %d       %d        %d    %d        %d      %d      %d\n", p->ID, p->name, p->Dm, p->BS, p->FS, p->Awa, p->Ir, p->PF, p->Pz, p->TS);
	}
	if (fclose(fp))
	{
		printf("无法关闭文件\n");
		exit(0);
	}
}
void fliesave2(Staff* head)
{
	Staff* p;
	FILE* fp;
	if ((fp = fopen("staff.txt", "w")) == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	for (p = head; p != NULL; p = p->next)
	{
		fprintf(fp, "%d     %s     %s      %d       %d        %d    %d        %d      %d      %d\n", p->ID, p->name, p->Dm, p->BS, p->FS, p->Awa, p->Ir, p->PF, p->Pz, p->TS);
	}
	if (fclose(fp))
	{
		printf("无法关闭文件\n");
		exit(0);
	}
}
void display(Staff* head)
{
	Staff* p;
	int count = 0;
	double sum[7] = { 0.0 };
	printf("---------------------------------------------------------------------------------\n");
	printf("|ID号   姓名   部门   基本工资  职务工资  津贴  医疗保险  公积金  奖金   总工资|\n");
	printf("---------------------------------------------------------------------------------\n");
	for (p = head; p != NULL; p = p->next)
	{
		printf("|%d      %s   %s    %-4d       %-4d     %-4d    %-4d     %-4d   %-4d   %-4d |\n", p->ID, p->name, p->Dm, p->BS, p->FS, p->Awa, p->Ir, p->PF, p->Pz, p->TS);
		printf("---------------------------------------------------------------------------------\n");
		count++;
		sum[0] += p->BS;
		sum[1] += p->FS;
		sum[2] += p->Awa;
		sum[3] += p->Ir;
		sum[4] += p->PF;
		sum[5] += p->Pz;
		sum[6] += p->TS;
	}
	printf("|各项平均工资为        %-4.1f    %-4.1f    %-4.1f    %-4.1f     %-4.1f  %-4.1f  %-4.1f|\n", sum[0] / count, sum[1] / count, sum[2] / count, sum[3] / count, sum[4] / count, sum[5] / count, sum[6] / count);
	printf("---------------------------------------------------------------------------------\n");
	system("pause");
}
Staff* find(Staff* head)
{
	printf("按1使用职工号查询，按2使用姓名查询\n");
	int n;
	Staff* p;
	p = NULL;
	scanf("%d", &n);
	switch (n)
	{
	case 1:
	{
		int ID;
		printf("请输入职工号\n");
		scanf("%d", &ID);
		for (p = head; p != NULL; p = p->next)
		{
			if (p->ID == ID)
			{
				printf("ID号   姓名   部门   基本工资  职务工资  津贴  医疗保险  公积金  奖金   总工资\n");
				printf("%d      %s    %s    %d       %d     %d    %d     %d     %d    %d\n", p->ID, p->name, p->Dm, p->BS, p->FS, p->Awa, p->Ir, p->PF, p->Pz, p->TS);
				break;
			}
		}
		if (p == NULL)
			printf("职工号不存在\n");

	}break;
	case 2:
	{
		char name[10];
		printf("请输入姓名\n");
		scanf("%s", &name);
		name[9] = '\0';
		for (p = head; p != NULL; p = p->next)
		{
			if ((strcmp(name, p->name)) == 0)
			{
				printf("ID号   姓名   部门   基本工资  职务工资  津贴  医疗保险  公积金  奖金   总工资\n");
				printf("%d      %s    %s    %d       %d     %d    %d     %d     %d    %d\n", p->ID, p->name, p->Dm, p->BS, p->FS, p->Awa, p->Ir, p->PF, p->Pz, p->TS);
				break;
			}
		}
		if (p == NULL)
			printf("姓名不存在\n");

	}break;
	}
	system("pause");
	return p;
}
Staff* deleteList(Staff* head)//删除
{
	int ID, s1;
	char name[10];
	Staff* p = head, * p1 = NULL;
	p = find(head);
	if (p != NULL)//如果有这个员工
	{
		if(head!=p)
		for (p1 = head; p1->next != p; p1 = p1->next);
		printf("\n  已找到该员工信息！\n");
		printf("  -----------------------| 是否删除 |-----------------------\n");
		printf("  ==========================================================\n");
		printf("  ||                                                      ||\n");
		printf("  ||            - 1 - 是                 - 2 - 否         ||\n");
		printf("  ||                                                      ||\n");
		printf("  ==========================================================\n");
		printf("\n  --请输入您的选择：");
		scanf("%d", &s1);
		if (s1 == 1)
		{
			if (head == p) head = p->next;
			else if (p->next == NULL)
				p1->next = NULL;
			else
				p1->next = p->next;//p1是p的上一个
			free(p);//删除p
			printf("\n  删除成功！\n");
		}
		else
			printf("退出成功\n");
	}
	system("pause");
	return head;
}
Staff* revise(Staff* head)//修改员工信息
{
	int ID, s1;
	char name[10];
	Staff* p = NULL, * p1 = NULL;
	p = find(head);
	if (p != NULL)
	{
		printf("\n  已找到该员工信息！\n");
		printf("\n  --请选择要修改的信息：\n");
		printf("\n  ----------------------| 请选择内容 |----------------------\n");
		printf("  ==========================================================\n");
		printf("  ||                                                      ||\n");
		printf("  ||    - 1 - 姓名       - 2 - 部门       - 3 - 基本工资  ||\n");
		printf("  ||                                                      ||\n");
		printf("  ||    - 4 - 职务工资   - 5 - 津贴       - 6 - 医疗保险  ||\n");
		printf("  ||                                                      ||\n");
		printf("  ||    - 7 - 公积金     - 8 - 奖金       - 0 - 退出      ||\n");
		printf("  ||                                                      ||\n");
		int n;
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			char name1[10];
			printf("请输入修改后姓名\n");
			scanf("%s", &name1);
			strcpy(p->name, name1);
			printf("修改成功\n");
		}break;
		case 2:
		{
			char Dm1[10];
			printf("请输入修改后部门名称\n");
			scanf("%s", &Dm1);
			strcpy(p->Dm, Dm1);
			printf("修改成功\n");
		}break;
		case 3:
		{
			int BS1;
			printf("请输入修改后的基本工资\n");
			scanf("%d", &BS1);
			p->BS = BS1;
			printf("修改成功\n");
		}break;
		case 4:
		{
			int FS1;
			printf("请输入修改后的职务工资\n");
			scanf("%d", &FS1);
			p->FS = FS1;
			printf("修改成功\n");
		}break;
		case 5:
		{
			int Awa1;
			printf("请输入修改后的津贴\n");
			scanf("%d", &Awa1);
			p->Awa = Awa1;
			printf("修改成功\n");
		}break;
		case 6:
		{
			int Ir1;
			printf("请输入修改后的医疗保险\n");
			scanf("%d", &Ir1);
			p->Ir = Ir1;
			printf("修改成功\n");
		}break;
		case 7:
		{
			int PF1;
			printf("请输入修改后的公积金\n");
			scanf("%d", &PF1);
			p->PF = PF1;
			printf("修改成功\n");
		}break;
		case 8:
		{
			int Pz1;
			printf("请输入修改后的奖金\n");
			scanf("%d", &Pz1);
			p->Pz = Pz1;
			printf("修改成功\n");
		}break;
		case 0:
			break;
		}
		if (n != 0)
		{
			p->TS = p->BS + p->Awa + p->FS + p->Ir + p->Pz + p->PF;
		}
	}
	return head;
}
void Sta(Staff* head)
{
	Staff* p;
	int sum1 = 0, sum2 = 0, sum3 = 0;
	int count1 = 0, count2 = 0, count3 = 0;
	int max1, max2, max3;
	int min1, min2, min3;
	double ave1, ave2, ave3;
	p = head;
	while (p != NULL)
	{
		if (strcmp(p->Dm, "行政") == 0)
		{
			max1 = min1 = p->TS;//初始化
			break;//找出其部门第一个
		}
		p = p->next;

	}
	p = head;
	while (p != NULL)
	{
		if (strcmp(p->Dm, "财务") == 0)
		{
			max2 = min2 = p->TS;
			break;
		}
		p = p->next;

	}
	p = head;
	while (p != NULL)
	{
		if (strcmp(p->Dm, "销售") == 0)
		{
			max3 = min3 = p->TS;
			break;
		}
		p = p->next;

	}
	p = head;
	while (p != NULL)
	{
		if (strcmp(p->Dm, "行政") == 0)
		{
			if (p->TS > max1)
				max1 = p->TS;
			if (p->TS < min1)
				min1 = p->TS;
			sum1 += p->TS;
			count1++;
		}
		p = p->next;

	}
	p = head;
	while (p != NULL)
	{
		if (strcmp(p->Dm, "财务") == 0)
		{
			if (p->TS > max2)
				max2 = p->TS;
			if (p->TS < min2)
				min2 = p->TS;
			sum2 += p->TS;
			count2++;
		}
		p = p->next;

	}
	p = head;
	while (p != NULL)
	{
		if (strcmp(p->Dm, "销售") == 0)
		{
			if (p->TS > max3)
				max3 = p->TS;
			if (p->TS < min3)
				min3 = p->TS;
			sum3 += p->TS;
			count3++;
		}
		p = p->next;

	}
	p = head;
	ave1 = 1.0 * sum1 / count1;
	ave2 = 1.0 * sum2 / count2;
	ave3 = 1.0 * sum3 / count3;
	printf("---------------------------------------------------------------\n");
	printf("|部门     工资总额      平均工资      最高工资      最低工资  |\n");
	printf("---------------------------------------------------------------\n");
	printf("|行政      %d          %.1f        %d         %d      |\n", sum1, ave1, max1, min1);
	printf("---------------------------------------------------------------\n");
	printf("|财务      %d          %.1f        %d         %d      |\n", sum2, ave2, max2, min2);
	printf("---------------------------------------------------------------\n");
	printf("|销售      %d          %.1f        %d         %d      |\n", sum3, ave3, max3, min3);
	printf("---------------------------------------------------------------\n");
	system("pause");
}
Staff* loadfile()
{
	Staff* p, * head, * tail;
	head = tail = NULL;
	FILE* fp;
	if ((fp = fopen("staff.txt", "r")) == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	while (!feof(fp))
	{
		p = (Staff*)malloc(sizeof(Staff));
		fscanf(fp, "%d     %s     %s      %d       %d        %d    %d        %d      %d      %d\n", &p->ID, p->name, p->Dm, &p->BS, &p->FS, &p->Awa, &p->Ir, &p->PF, &p->Pz, &p->TS);
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;

	}
	if (fclose(fp))
	{
		printf("无法关闭文件\n");
		exit(0);
	}
	return head;
}
int check(int m)
{
	Staff* p;
	int n=1;
	p = loadfile();
	while (p != NULL)
	{
		if (p->ID == m)
		{
			n = 0;
			break;
		}
		p = p->next;
	}
	return n;
}
Staff * adddata()
{
	Staff* p, * head, * tail;
	int flag = 0;
	head = tail = NULL;
	int count,id=0;
	printf("请按顺序输入ID 姓名 部门 基本工资 职务工资 津贴 公积金 保险 奖金\n");
	printf("中间以空格分隔，一次输入一人\n");
		p = (Staff*)malloc(sizeof(Staff));
		scanf("%d %s %s %d %d %d %d %d %d\n", &p->ID, &p->name, &p->Dm, &p->BS, &p->FS, &p->Awa, &p->Ir, &p->PF, &p->Pz);
		id = p->ID;
		p->TS = p->BS + p->Awa + p->FS + p->Ir + p->Pz + p->PF;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		if (check(id) == 0)
		{
			printf("职工号重复，添加失败，请重新选择\n");
			system("pause");
			head = NULL;
		}
		else
		{
			printf("添加成功");
			system("pause");
		}
	return head;
}

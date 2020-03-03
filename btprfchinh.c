#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100
typedef struct
{
    char ten[100];
    char mssv[100];
    float Math,ktm_math,kt_15p_math,kt_1t_math,kt_hk_math;
    float PRF,ktm_prf,kt_15p_prf,kt_1t_prf,kt_hk_prf;
    float Literature, ktm_lit,kt_15p_lit,kt_1t_lit,kt_hk_lit;
    float English, ktm_eng,kt_15p_eng,kt_1t_eng,kt_hk_eng;
} sinhvien;
int stt=0;
sinhvien* Maxsv[MAXN];
void add()
{
	system("cls");
    sinhvien *name = (sinhvien*) malloc( sizeof(sinhvien) );
	printf("Enter name of student: "); fflush(stdin);
	scanf("%20[^\n]", name->ten); getchar();
	printf("Enter MSSV: "); fflush(stdin);
	scanf("%20[^\n]", name->mssv); getchar();
	name->ktm_math=0; name->kt_15p_math=0; name->kt_1t_math=0; name->kt_hk_math=0; name->Math=0;
	name->ktm_lit=0; name->kt_15p_lit=0; name->kt_1t_lit=0; name->kt_hk_lit=0; name->Literature=0;
	name->ktm_prf=0; name->kt_15p_prf=0; name->kt_1t_prf=0; name->kt_hk_prf=0; name->PRF=0;
	name->ktm_eng=0; name->kt_15p_eng=0; name->kt_1t_eng=0; name->kt_hk_eng=0; name->English=0;
	Maxsv[stt++]=name;
    printf("Done!\n");
    getchar();
    system("cls");
}

void print()
{
    int i;
    sinhvien* temp[stt];
    printf("\n ----- Thong tin sinh vien -----\n");
    printf("%s\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n","STT", "MSSV", "NAME", "MATH", "LIT", "ENG", "PRF");
    for(i=0; i<stt;i++)
    {
        temp[i]=Maxsv[i];
        printf("%d\t%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",i+1, temp[i]->mssv, temp[i]->ten, temp[i]->Math, temp[i]->Literature, temp[i]->English, temp[i]->PRF);
    }
    getchar();
    system("cls");
}
int case4_1()
{
    char student[100];
    int f,l;
    sinhvien* tp[stt];
    printf("nhap ten sv can check point: ");
    gets(student);
    for (f=0;f<stt;f++)
    {
        tp[f]=Maxsv[f];
        if (strcmp((tp[f]->ten),student)==0) {printf("Name of student: %s\n", tp[f]->ten);l=f;}
    }
    printf("position in struct: %d", l);
    int choice5;
            {
                printf("\n-----chosen student point menu------\n");
                printf("1 - Print out all parts of math score\n");
                printf("2 - Print out all parts of literature score\n");
                printf("3 - Print out all parts of English score\n");
                printf("4 - Print out all parts of PRF score\n");
                printf("5 - Turn back main menu\n");
                printf("\nEnter choice: ");
                scanf("%d", &choice5);
                getchar();
                switch(choice5)
                do
                {
                    case 1:
                        {
                            printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "MSSV", "NAME", "KTM", "KT15P", "KT1T", "KTHK", "DTB");
                            printf("%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", tp[l]->mssv, tp[l]->ten, tp[l]->ktm_math, tp[l]->kt_15p_math, tp[l]->kt_1t_math, tp[l]->kt_hk_math, tp[l]->Math);
                        }   break;
                    case 2:
                        {
                            printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "MSSV", "NAME", "KTM", "KT15P", "KT1T", "KTHK", "DTB");
                            printf("%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", tp[l]->mssv, tp[l]->ten, tp[l]->ktm_lit, tp[l]->kt_15p_lit, tp[l]->kt_1t_lit, tp[l]->kt_hk_lit, tp[l]->Literature);
                        }   break;
                    case 3:
                        {
                            printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "MSSV", "NAME", "KTM", "KT15P", "KT1T", "KTHK", "DTB");
                            printf("%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", tp[l]->mssv, tp[l]->ten, tp[l]->ktm_eng, tp[l]->kt_15p_eng, tp[l]->kt_1t_eng, tp[l]->kt_hk_eng, tp[l]->English);
                        }   break;
                    case 4:
                        {
                            printf("%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", "MSSV", "NAME", "KTM", "KT15P", "KT1T", "KTHK", "DTB");
                            printf("%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", tp[l]->mssv, tp[l]->ten, tp[l]->ktm_prf, tp[l]->kt_15p_prf, tp[l]->kt_1t_prf, tp[l]->kt_hk_prf, tp[l]->PRF);
                        }   break;

                }
                while (choice5!=5);

            }


}
int case1()
{
    char name[100];
    float average;
    float ktm, kt15p, kt1t, kthk;
    int k,s;
    sinhvien* kieu[stt];
    printf("nhap ten sv can add point: ");
    gets(name);
    for (k=0;k<stt;k++)
    {
        kieu[k]=Maxsv[k];
        if (strcmp((kieu[k]->ten),name)==0) {printf("Name of student: %s\n", kieu[k]->ten);s=k;}
    }
    printf("position in struct: %d", s);
        int choice3;
            {
                printf("\n-----score menu------\n");
                printf("1 - Add parts of math score\n");
                printf("2 - Add parts of literature score\n");
                printf("3 - Add parts of English score\n");
                printf("4 - Add parts of PRF score\n");
                printf("5 - Turn back main menu\n");
                printf("\nEnter choice: ");
                scanf("%d", &choice3);
                getchar();
                switch(choice3)
                do

                {
                    case 1:
                    {
                        float ktm_m, kt15p_m, kt1t_m, kthk_m, average_m;
                        printf("Enter kt mieng point: ");
                        scanf("%f", &ktm_m); getchar();
                        printf("Enter kt 15p point: ");
                        scanf("%f", &kt15p_m); getchar();
                        printf("Enter kt 1 tiet point: ");
                        scanf("%f", &kt1t_m); getchar();
                        printf("Enter kt hk point: ");
                        scanf("%f", &kthk_m); getchar();
                        average=((ktm_m + kt15p_m + kt1t_m + kthk_m)/4);
                        kieu[s]->ktm_math=kieu[s]->ktm_math+ktm_m;
                        kieu[s]->kt_15p_math=kieu[s]->kt_15p_math+kt15p_m;
                        kieu[s]->kt_1t_math=kieu[s]->kt_1t_math+kt1t_m;
                        kieu[s]->kt_hk_math=kieu[s]->kt_hk_math+kthk_m;
                        printf("Check added math point:\nKTm math: %.2f\nKT15p math: %.2f\nKt1t math: %.2f\nKtHK math: %.2f\n",kieu[s]->ktm_math, kieu[s]->kt_15p_math, kieu[s]->kt_1t_math, kieu[s]->kt_hk_math);
                        kieu[s]->Math=kieu[s]->Math+average;
                        printf("Diem TB math: %.2f\n", kieu[s]->Math);
                        printf("Added!");
                    }   break;
                    case 2:
                    {
                        float ktm_v, kt15p_v, kt1t_v, kthk_v, average_v;
                        printf("Enter kt mieng point: ");
                        scanf("%f", &ktm_v); getchar();
                        printf("Enter kt 15p point: ");
                        scanf("%f", &kt15p_v); getchar();
                        printf("Enter kt 1 tiet point: ");
                        scanf("%f", &kt1t_v); getchar();
                        printf("Enter kt hk point: ");
                        scanf("%f", &kthk_v); getchar();
                        average_v=((ktm_v + kt15p_v + kt1t_v + kthk_v)/4);
                        kieu[s]->ktm_lit=kieu[s]->ktm_lit+ktm_v;
                        kieu[s]->kt_15p_lit=kieu[s]->kt_15p_lit+kt15p_v;
                        kieu[s]->kt_1t_lit=kieu[s]->kt_1t_lit+kt1t_v;
                        kieu[s]->kt_hk_lit=kieu[s]->kt_hk_lit+kthk_v;
                        printf("Check added math point:\nKTm lit: %.2f\nKT15p lit: %.2f\nKt1t lit: %.2f\nKtHK lit: %.2f\n",kieu[s]->ktm_lit, kieu[s]->kt_15p_lit, kieu[s]->kt_1t_lit, kieu[s]->kt_hk_lit);
                        kieu[s]->Literature=kieu[s]->Literature+average_v;
                        printf("Diem TB Literature: %.2f\n", kieu[s]->Literature);
                        printf("Added!");
                    }   break;
                    case 3:
                    {
                        float ktm_e, kt15p_e, kt1t_e, kthk_e, average_e;
                        printf("Enter kt mieng point: ");
                        scanf("%f", &ktm_e); getchar();
                        printf("Enter kt 15p point: ");
                        scanf("%f", &kt15p_e); getchar();
                        printf("Enter kt 1 tiet point: ");
                        scanf("%f", &kt1t_e); getchar();
                        printf("Enter kt hk point: ");
                        scanf("%f", &kthk_e); getchar();
                        average_e=((ktm_e + kt15p_e + kt1t_e + kthk_e)/4);
                        kieu[s]->ktm_eng=kieu[s]->ktm_eng+ktm_e;
                        kieu[s]->kt_15p_eng=kieu[s]->kt_15p_eng+kt15p_e;
                        kieu[s]->kt_1t_eng=kieu[s]->kt_1t_eng+kt1t_e;
                        kieu[s]->kt_hk_eng=kieu[s]->kt_hk_eng+kthk_e;
                        printf("Check added math point:\nKTm eng: %.2f\nKT15p eng: %.2f\nKt1t eng: %.2f\nKtHK eng: %.2f\n",kieu[s]->ktm_eng, kieu[s]->kt_15p_eng, kieu[s]->kt_1t_eng, kieu[s]->kt_hk_eng);
                        kieu[s]->English=kieu[s]->English+average_e;
                        printf("Diem TB Literature: %.2f\n", kieu[s]->English);
                        printf("Added!");
                    } break;
                    case 4:
                    {
                        float ktm_p, kt15p_p, kt1t_p, kthk_p, average_p;
                        printf("Enter kt mieng point: ");
                        scanf("%f", &ktm_p); getchar();
                        printf("Enter kt 15p point: ");
                        scanf("%f", &kt15p_p); getchar();
                        printf("Enter kt 1 tiet point: ");
                        scanf("%f", &kt1t_p); getchar();
                        printf("Enter kt hk point: ");
                        scanf("%f", &kthk_p); getchar();
                        average_p=((ktm_p + kt15p_p + kt1t_p + kthk_p)/4);
                        kieu[s]->ktm_prf=kieu[s]->ktm_prf+ktm_p;
                        kieu[s]->kt_15p_prf=kieu[s]->kt_15p_prf+kt15p_p;
                        kieu[s]->kt_1t_prf=kieu[s]->kt_1t_prf+kt1t_p;
                        kieu[s]->kt_hk_prf=kieu[s]->kt_hk_prf+kthk_p;
                        printf("Check added math point:\nKTm PRF: %.2f\nKT15p PRF: %.2f\nKt1t PRF: %.2f\nKtHK PRF: %.2f\n",kieu[s]->ktm_prf, kieu[s]->kt_15p_prf, kieu[s]->kt_1t_prf, kieu[s]->kt_hk_prf);
                        kieu[s]->PRF=kieu[s]->PRF+average_p;
                        printf("Diem TB Literature: %.2f\n", kieu[s]->PRF);
                        printf("Added!");
                    } break;

                }
            while(choice3!=5);
            }

}

int passed_students()
{
    int g,d;
    float u,t;
    sinhvien*tc[stt];
    printf("passed students");
    printf("\n%s\t%s\t\t%s\t\t%s\t%s\t\t%s\t\t%s\n", "MSSV", "NAME", "MATH", "LITERATURE", "ENGLISH", "PRF", "TBM");
    for (g=0;g<stt;g++)
    {
        tc[g]=Maxsv[g];
        if (tc[g]->Math>=5 && tc[g]->Literature>=5 && tc[g]->English>=5 && tc[g]->PRF>=5)
        {
            u=(tc[g]->Math + tc[g]->Literature + tc[g]->English + tc[g]->PRF)/4;
            printf("%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", tc[g]->mssv, tc[g]->ten, tc[g]->Math, tc[g]->Literature, tc[g]->English, tc[g]->PRF, u);
        }
    }
    printf("fail student");
    printf("\n%s\t%s\t\t%s\t\t%s\t%s\t\t%s\t\t%s\n", "MSSV", "NAME", "MATH", "LITERATURE", "ENGLISH", "PRF", "TBM");
    for(d=0;d<stt;d++)
    {
        tc[d]=Maxsv[d];
        if (tc[d]->Math<5 || tc[d]->Literature<5 || tc[d]->English<5 || tc[d]->PRF<5);
        {
            t=(tc[d]->Math + tc[d]->Literature + tc[d]->English + tc[d]->PRF)/4;
            printf("%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", tc[d]->mssv, tc[d]->ten, tc[d]->Math, tc[d]->Literature, tc[d]->English, tc[d]->PRF, t);
        }
    }
}

int main()
{
    system("cls");
	int choice;
	do
	{
		printf("-----------------------------------------\n");
		printf("1 - Add a student and his/her MSSV\n");
		printf("2 - Add subject point of a student\n");
		printf("3 - Print out the infor TB of students\n");
		printf("4 - Print out the subject points of defined Student\n");
		printf("5 - Print out students who would pass or fail\n");
		//printf("5 - Print out passed students\n");
		printf("6 - Quit\n");
		printf("\nEnter your choice:");
		scanf("%d", &choice);
		getchar();
		switch(choice)
		{
		    case 1: add(); break;
            case 2:
            {   int choice2;
                do
                {
                    printf("\n-----add point menu------\n");
                    printf("1 - Enter a name of sudent you want to add score\n");
                    printf("2 - Quit\n");
                    printf("\nEnter choice: ");
                    scanf("%d", &choice2);
                    getchar();
                    switch(choice2)
                    {
                        case 1: case1(); break;
                    }
                }
                while(choice2!=2);
            }   break;
            case 3: print(); break;
            case 4:
            {
                int choice4;
                do
                {
                    printf("\n-----student point menu------\n");
                    printf("1 - Enter a name of student you want to add score\n");
                    printf("2 - Quit\n");
                    printf("\nEnter Choice: ");
                    scanf("%d", &choice4);
                    getchar();
                    switch(choice4)
                    {
                        case 1: case4_1(); break;
                    }
                }
                while(choice4!=2);
            }   break;
            case 5: passed_students();
            break;

		}
	}
	while(choice != 6);
    getch();
	return 0;
}

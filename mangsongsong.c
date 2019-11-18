#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void add(char stt[][21], int price[], char dayIn[][11], char dayOut[][11], int rest[], int *pn)
{
	char ts[21],d[11],d1[11];
	int i, t, h;
	do 
	{
	printf("Nhap ten loai coffee: ");   // nhap ten coffee
	fflush(stdin);
	scanf("%20[^\n]", ts);     
	t = 1;
	for ( i = 0; i < *pn; i++) // kiem tra ten da co hay chua 
		if (strcmp(ts,stt[i]) == 0)             
			{
				printf("Ten da co!Hay nhap lai!\n");   
				t = 0;
				i = *pn - 1;
			}
	}
	 while (!t);
	strcpy(stt[*pn], ts);

	printf("Ngay nhap : ");   // nhap ngay vao
	fflush(stdin);
	scanf("%11[^\n]", d);
	strcpy(dayIn[*pn], d);
	
	
	printf("Ngay ra: ");	// nhap ngau xuat 
	fflush(stdin);
	scanf("%11[^\n]", d1);
	strcpy(dayOut[*pn], d1);
		
	printf("Gia : ");	//nhap gia
	scanf("%d", &h);    
	price[*pn] = h;
	
	printf("So luong: ");	// nhap so luong
	scanf("%d",&h);
	rest[*pn]=h;
	
	(*pn)++;
	printf("Da Nhap!!\n\n");
  	system("pause");
    system("cls");
}
int searchCf(char stt[][21], int *pn)
{
	char st[21];
	int i,dem;
	printf("Nhap ten loai cafe : ");
	fflush(stdin);
	scanf("%20[^\n]",&st);
	for (i=0;i<*pn;i++)
		if (strcmp(st,stt[i])==0)	// kiem tra co gia tri trong mang
			{
				return i;		// vi tri tim dc
			}
	return -1;
}
int maxCf(char stt[][21], int price[], char dayIn[][11], char dayOut[][11], int rest[], int *pn)
{
	int i,max=0;
	for(i=0;i<*pn-1;i++)
		if(price[i]>price[i+1])
			{
				return i;
			}
	return -1;

}
void capNhat(int pos,char stt[][21], int price[], char dayIn[][11], char dayOut[][11], int rest[], int *pn)
{ 	
	char luachon[11]="0";
	char newDayIn[11],newDayOut[11];
	int i,newPrice,newRest;
	
	printf("gia chinh sua (Nhap 0 neu khong chinh sua): ");
	scanf("%d", &newPrice);
	if (newPrice!=0) price[pos]=newPrice;
	
	printf("Ngay vao can chinh sua (Nhap 0 neu khong chinh sua): ");
	fflush(stdin);
	scanf("%11[^\n]", &newDayIn);
	if (strcmp(luachon,newDayIn)!=0) strcpy(dayIn[pos],newDayIn);
	
	printf("Ngay ra can chinh sua (Nhap 0 neu khong chinh sua): ");
	fflush(stdin);
	scanf("%11[^\n]", &newDayOut);
	if (strcmp(luachon,newDayOut)!=0) strcpy(dayOut[pos],newDayOut);
	
	printf("so luong can chinh sua (Nhap 0 neu khong chinh sua): ");
	scanf("%d",&newRest);
	if (newRest!=0) rest[pos]=newRest;
	
	
	
	printf("Sau khi cap nhat: \n");
	for(i=0;i<*pn;i++)
		{
			printf(" STT :[%d] NameCf : %20s|price : %d|dayIn: %11s|dayOut: %11s|rest: %d kg \n ",i,stt[i],price[i],dayIn[i],dayOut[i],rest[i]);
		}
	system("pause");
	system("cls");
}
void sort(int a[],char stt[][21], int price[], char dayIn[][11], char dayOut[][11], int rest[], int *pn)
{
	char t[21],d[11],dO[11];
	int i,j,g,r;
	for(i=0;i<=*pn-1;i++)
		for(j=*pn-1;j>i;j--)
			if(a[j]>a[j-1])
			{
				strcpy(t,stt[j]);
				strcpy(stt[j],stt[j-1]);
				strcpy(stt[j-1],t);
				
				g=price[j];
				price[j]=price[j-1];
				price[j-1]=g;
				
				strcpy(d,dayIn[j]);
				strcpy(dayIn[j],dayIn[j-1]);
				strcpy(dayIn[j-1],d);
				
				strcpy(dO,dayOut[j]);
				strcpy(dayOut[j],dayOut[j-1]);
				strcpy(dayOut[j-1],dO);
				
				r=rest[j];
				rest[j]=rest[j-1];
				rest[j-1]=r;
			}
	printf("Cafe sau khi sap xep: \n");
	for(i=0;i<*pn;i++)
		{
			printf("STT :[%d] NameCf : %20s|price : %d|dayIn: %11s|dayOut: %11s|rest: %d kg \n ",i,stt[i],price[i],dayIn[i],dayOut[i],rest[i]);
		}
	system("pause");
	system("cls");
}

int het( char stt[][21], int price[], char dayIn[][11], char dayOut[][11], int rest[], int *pn)
{ int t=0;
  for (t; t<*pn; t++)
    { 
	  if ( rest[t] == 0)
      printf(" Loai ca phe %s da het", stt[t]);
    };
   system("pause");
   system("cls");  
}

int tinhTienLoi(char stt[][21], int price[], char dayIn[][11], char dayOut[][11], int rest[], int *pn)
{ int i,tl;
  int gg[100], sl[100];
  for (i=0;i<*pn;i++)
    { printf("Gia goc cua %s:", stt[i]);   // nhap tien von va so luong ban duoc
      scanf("%d", &gg[i]);
      printf("So luong cua %s da ban:", stt[i]);
      scanf("%d", &sl[i]);
    }
  system("pause");
  system("cls");
 
  for (i=0;i<*pn;i++)
    { tl=price[i]*sl[i]-gg[i]*sl[i];   // tinh tien loi
	  printf("So tien loi da ban duoc cua %s: %d\n", stt[i], tl);
	}
  system("pause"); 
  system("cls");
}

int toiDa(char stt[][21], int price[], char dayIn[][11], char dayOut[][11], int rest[], int *pn)
{ int gia, tb, S=0;
  int i, toida;
  printf("Nhap vao gia tien ban co:");
  scanf("%d", &gia);
  tb= (gia / *pn);                              // tinh trung binh
  printf("Voi %d mua duoc toi uu  nhat:\n", gia);
  for (i=0; i<*pn; i++)
    { 
	  toida= (tb/ price[i]);                       // tinh so toi da
      printf("%d loai %s\n", toida, stt[i]);
	  S=(toida*price[i] + S);
	}
  printf("Va du ra %d", gia-S);
  system("pause");
  system("cls");
}

int main(int argc, char *argv[]) 
{
	int choice,n=0,pos,max;
	char stt[100][21],dayIn[100][11],dayOut[100][11];
	int price[8],rest[3];
	do   
	      {
		   printf("\n1- them vao ca phe \n");
           printf("2- tim \n");
           printf("3- cap nhat \n");
           printf("4- sap xep theo gia\n");
           printf("5- sap xep theo so luong\n");
           printf("6- gia ca phe cao nhat\n");
           printf("7- ca phe da het\n");
           printf("8- tinh tien loi\n");
           printf("9- so do uong mua duoc toi uu nhat\n");
           printf("10- Quit\n");
           printf("Select an operation: ");
           scanf("%d", &choice);
           switch(choice) 
               {  case 1: {	
                           	if (n==100) printf("Impossible to add!\n");
							else add(stt,price,dayIn,dayOut,rest, &n);
							break;
                          }
                  case 2: {
                  			if (n==0) printf("Nothing to search!\n");
							else {
									pos=searchCf(stt, &n);
									if( pos == -1) 
											{	
												printf("khong co mon do anh oi!!!!\n");
												system("pause");
												system("cls");
											}
									else
									{
										printf("STT :[%d] NameCf : %20s|price : %d|dayin: %11s|dayout: %11s|rest: %d kg \n ",pos,stt[pos],price[pos],dayIn[pos],dayOut[pos],rest[pos]);
								    }
								  }
							system("pause");
			    			system("cls");
							break;
        				  }
        		  case 3: {
        		  			if (n==0) printf("Nothing to cap nhat!\n");
        		  			else {
        		  				  pos=searchCf(stt,&n);
        		  			      if (pos == -1) 
									{ 
									 printf("khong co mon do anh oi!!!!\n");
									 system("pause");
									 system("cls");
									}
									
								  else capNhat(pos,stt,price,dayIn,dayOut,rest,&n);
								 }
						    break;
				  		  }
        		  case 4: {
        		  	 		if (n==0) printf("Nothing to sort!\n");
							else sort(price,stt,price,dayIn,dayOut,rest,&n);
							break;
        		  	 	  }
        		  case 5: {
        		  	 		if (n==0) printf("Nothing to sort!\n");
							else sort(rest,stt,price,dayIn,dayOut,rest,&n);
							break;
        		  	 	  }
        		  case 6: {
        		  			if (n==0) printf("Nothing to find max!\n");
        		  			else max=maxCf(stt,price,dayIn,dayOut,rest,&n);
        		  			printf("Cafe co gia cao nhat: STT :[%d] NameCf : %20s|price : %d|dayin: %11s|dayout: %11s|rest: %d kg \n ",max,stt[max],price[max],dayIn[max],dayOut[max],rest[max]);
							system("pause");
							system("cls");
							break;
				  		  }
				  case 7: {
				  	       if (n==0) printf("Nothing to find!\n");
				  	       else het(stt,price,dayIn,dayOut,rest,&n);
				  	       break;
				  	      }
				  case 8: {
				  	       if (n==0) printf("Nothing to solve!\n");
				  	       else tinhTienLoi(stt,price,dayIn,dayOut,rest,&n);
				  	       break;
				  	   	  }
				  case 9: {
				  	       if (n==0) printf("Nothing to solve!\n");
				  	       else toiDa(stt,price,dayIn,dayOut,rest,&n);
				  	       break;
				  	      }
			    }
         }
     while ( choice >0 && choice<10); 
	return 0;
}


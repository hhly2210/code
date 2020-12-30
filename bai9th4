#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct
{
	char hoten[30], gtinh[4], ngaysinh[10], lop[5];
}hocsinh;

typedef hocsinh Mang[100];
void Nhaptt(hocsinh*a, int *n)
{
	int i;
	printf("So hoc sinh: ");
	do
	{
		scanf("%d", &n);
		if(*n < 1)
            printf("\nNhap lai so hoc sinh:  ");
	} while(n<=0);

	for(i = 0; i < *n; i++)
	{
    	fflush(stdin);
    	printf("\nHoc sinh thu [%d]\n", i+1);
    	printf("Ho ten : ");
    	gets(a[i].hoten);
    	
    	fflush(stdin);
    	printf("Ngay sinh: ");
  		gets(a[i].ngaysinh);
        
        fflush(stdin);
        printf("Gioi tinh: ");
        gets(a[i].gtinh);
        
        fflush(stdin);
        printf("Lop: ");
        gets(a[i].lop);
    }
}

void tachten(char hoten[],char ten[])
{
	for(int i=strlen(hoten)-1;i>=0;i--)
	{
		if(hoten[i]==' ')
		{
			strcpy(ten,hoten+1+i);
			break;
		}
	}
}

void Sx(hocsinh*a, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j< n; j++)
		{
			char ten1[30] = "", ten2[30] = "";
			tachten(a[i].hoten,ten1);
			tachten(a[j].hoten,ten2);
			int check1=strcmpi(ten1,ten2);
				if(check1>0)
				{
					hocsinh tam = a[i];
					a[i] = a[j];
					a[j] = tam;
				}
				else if(check1==0)
				{
					int check2=strcmpi(a[i].hoten,a[j].hoten);
						if(check2>0)
						{
							hocsinh tam = a[i];
							a[i] = a[j];
							a[i] = tam;
						}
				}
		}
	}
}

void hien(hocsinh*a, int n)
{
	int i;
	printf("\n-----------------------------");
	printf("\nDanh sach thi sinh");
	printf("\tHo ten: %-21s", a[i].hoten);
	printf("\tGioi tinh: %-s", a[i].gtinh);
	printf("\tNgay sinh: %-s", a[i].ngaysinh);
	printf("\tLop: %-s", a[i].lop);
	printf("\n-----------------------------");
}

int main()
{
	Mang a;
	int n,i,j;
	
	Nhaptt(a, &n);
	tachten(hoten, ten);
	Sx(a,n);
	hien(a,n);
	
	getch;
	return 0;
}

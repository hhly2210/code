//205748010310003
#include <stdio.h>
#include <string.h> // de dung ham strlen
#include <stdbool.h> // de co kieu bool

typedef struct HOSO_S
{
	char hoten[30];
	char gioitinh[10];
	char lop[10];
	int ngaysinh[3];
} HOSO;

void nhapSo(int* n);
char* tachTen(char* hoten);
bool soSanhTen(char* a, char* b);
void nhapHoSo(HOSO hoso[], int n);
void hienHoSo(HOSO hoso[], int n);
void xepHoSo(HOSO hoso[], int n);
void traoHoSo(HOSO* a, HOSO* b);

int main()
{
	int n;

	nhapSo(&n);

	HOSO hoso[n];

	nhapHoSo(hoso, n);

	xepHoSo(hoso, n);

	hienHoSo(hoso, n);


	return 0;
}

void nhapSo(int* n)
{
	do
	{
		printf("So hoc sinh : ");
		scanf("%d", n);
		if (*n < 1)
			printf("Sai pham vi!!!");
	} while (*n < 1); // neu so be hon 1 thi nhap lai
}

void hienHoSo(HOSO hoso[], int n)
{
	/*
		hoten : 30 ki tu -> %-30s
		lop : 10 ki tu -> %-10s
		gioi tinh : 10 ki tu ->%-10s
		ngay sinh 2 + 2 + 4 + 2 ki tu ':' = 11 ki tu ->%-10s
	*/
	printf("|--------------------------------------------------------------------------|\n");
	printf("|%-30s\t|%-10s\t|%-10s\t|%-10s|\n", "Ho va ten", "Lop", "Gioi tinh", "Ngay sinh");
	printf("|--------------------------------------------------------------------------|\n");
	
	int i;
	for (i = 0; i < n; i++)
		printf("|%-30s\t|%-10s\t|%-10s\t|%02d/%02d/%04d|\n", hoso[i].hoten, hoso[i].lop, hoso[i].gioitinh, hoso[i].ngaysinh[0], hoso[i].ngaysinh[1], hoso[i].ngaysinh[2]);
	printf("|--------------------------------------------------------------------------|\n");
}

void nhapHoSo(HOSO hoso[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("----------------------------------------\n");

		printf("Ho va ten\t: ");
		fflush(stdin);
		gets(hoso[i].hoten);

		printf("Gioi tinh\t: ");
		fflush(stdin);
		gets(hoso[i].gioitinh);

		printf("Ngay sinh\t: ");
		// Cach nhap ngay sinh : nhap SO + cach + nhap SO + cach + nhap SO + enter
		scanf("%d%d%d", &hoso[i].ngaysinh[0], &hoso[i].ngaysinh[1], &hoso[i].ngaysinh[2]);

		printf("Lop\t\t: ");
		fflush(stdin);
		gets(hoso[i].lop);
	}
}

void xepHoSo(HOSO hoso[], int n)
{
	int i, j;
	/*
		tachTen --> soSanh
		nen soSanh(  tachTen(HoTen_1)-->Ten_1  ,  tachTen(HoTen-2)-->Ten_2   )
	*/
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (soSanhTen(tachTen(hoso[i].hoten), tachTen(hoso[j].hoten)))
				traoHoSo(&hoso[i], &hoso[j]);
}

void traoHoSo(HOSO* a, HOSO* b)
{
	HOSO t = *a;
	*a = *b;
	*b = t;
}

char* tachTen(char* hoten)
{
	/*
		vi tri cua hien tai
		hoten -----
			  |
			  V
			  vo ta nam

		ta can dua vi tri ve cuoi
		hoten += khoang cach tu vi tri dau den vi tri cuoi
		dung ham strlen de tinh khoang cach

		hoten -------------
				  |
				  V
			  vo ta nam
	*/
	hoten += strlen(hoten);

	/*
		gia can tim dia chi BAT DAU cua TEN
		logic co ban -> chac chan co dau cach truoc phan TEN
		Ta tim bang cach
			di lui tu vi tri cuoi
			gap chu ' ' tuc dau cach thi dung lai
	*/
	while (*hoten != ' ')
		hoten--;

	// thu ta can la vi tri BAT DAU cua ten, khong phai cua chu ' '
	// nen + 1 de sua lai vi tri
	// tra dia chi ve
	return hoten + 1;
}

bool soSanhTen(char* a, char* b)
{
	bool kq = true;
	int i;
	/*
		ta can co chieu dai ngan nhat trong 2 xau
		neu a be hon thi lay cua a
		neu b be hon thi lay cua b
	*/
	int length = strlen(a) < strlen(b) ? strlen(a) : strlen(b);

	/*
		tai sao?
		vi du: nam va duong
		nam -> 3 ki tu
		duong -> 5 ki tu
		khi so sanh tung ki tu mot
		ta KHONG THE lay ki tu thu 4 cua nam duoc
		vi no vo li, nam chi co 3 ki tu
	*/


	/*
		so sanh tung ki tu mot, trai -> phai
		neu co khac nhau thi HUY vong lap
		kq se la noi luu ket qua so sanh
	*/
	for (i = 0; i < length; i++)
		if (a[i] != b[i])
		{
			kq = a[i] < b[i];
			// NEU ki tu ben a xuat hien truoc --> TRUE
			// NEU ki tu ben a xuat hien SAU --> FALSE
			break; // HUY vong lap
		}
	//NEU MUON DAO NGUOC THI THEM ! truoc kq
	return kq;
}

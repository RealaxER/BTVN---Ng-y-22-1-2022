
#include<stdio.h>
#include <stdbool.h>
#define MAX 100
//=== nguyên m?u hàm
void Sieu_nguyento(int a[], int n);
void Tangdan(int a[], int n);
void Duong(int a[], int n);
void Doan(int a[], int n);
void Gtri_le(int a[], int n);
void Nhap(int a[], int n);
void Xuat(int a[], int n);
void So_nt(int a[], int n);

int main()
{
	int a[MAX];
	int n;
	do
	{
		printf("Nhap n : ");
		scanf("%d", &n);
	} while (n <= 0 || n > MAX);
	So_nt(a, n);
	// Gtri_le(a,n); ====== Giá tr? l? cu?i cùng
	// Doan(a, n); ======== Ðo?n [a, b] ch?a m?i giá tr? trong m?ng.
	// Duong(a, n); ======== So toan duong
	// Tangdan(a, n); == Kiemtra xem s? dso có tang d?n hay khong 
	// Sieu_nguyento(a,n);
	return 0;
}

void So_nt(int a[], int n)
{
	Nhap(a, n);
	printf ("So nguyent to trong mang la: ");
	for (int i = 0; i < n; i++)
	{
		bool kiemtra = true;
		for (int j = 2; j < a[i]; j++)
		{
			if (a[i] % j == 0)
			{
				kiemtra = false;
				break;
			}
		}
		if (kiemtra == true)
		{
			printf(" %d", a[i]);
		}
	}
}

void Gtri_le(int a[], int n)
{
	Nhap(a, n);
	for (int i = 1; i < n; i++)
	{
		if (a[n - i] % 2 != 0)
		{
			printf ( "Gia tri le la: %d ", a[n - i]);
			break;
		}
	}
}

void Doan(int a[], int n)
{
	Nhap(a, n);
	int Min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < Min)
		{
			Min = a[i];
		}
	}
	int Max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > Max)
		{
			Max = a[i];
		}
	}
	printf("Doan chua moi gia tri la [ %d, %d ]: ", Min, Max);

}

void Duong(int a[], int n)
{
	Nhap(a, n);
	bool kiemtra = true;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			kiemtra = false;
			break;
		}
	}
	if (kiemtra == false)
	{
		printf("Khong la so duong ");
	}
	else
	{
		printf("La so duong");
	}
}

void Tangdan(int a[], int n)
{
	Nhap(a, n);
	bool kiemtra;
	int temp = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= temp)
		{
			kiemtra = true;
		}
		else
		{
			kiemtra = false;
			printf("Khong tang dan ");
			break;
		}
		temp = a[i];
	}
	if (kiemtra == true)
	{
		printf( "Tang dan ");
	}
}

bool So_NT(int temp) // ph?c v? cho s? siêu nguyên t?
{
	bool kiemtra = true;
	for (int j = 2; j < temp; j++)
	{
		if (temp % j == 0)
		{
			kiemtra = false;
			break;
		}
	}
	return kiemtra;
}

void Sieu_nguyento(int a[], int n)
{
	// kiemtra sieu nguyen to
	Nhap(a, n);
	int temp;
	printf( "Cac so sieu nguyen to la : ");
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		while (temp != 0)
		{
			temp = temp / 10;
			bool kiemtra = So_NT(temp);
			if (kiemtra == false)
			{
				break;
			}
			if (kiemtra == true && temp == 0)
			{
				printf("%d  ", a[i]);
			}
		}
	}
}

void Nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap phan tu thu %d :  ", i);
		scanf("%d", a[i]);
	}
}

void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i];
	}
}

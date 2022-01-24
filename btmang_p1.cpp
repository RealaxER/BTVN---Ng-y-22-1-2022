// Lý thuyết 
// ============
// câu 1 : Mảng là tập hợp các biến có cùng kiểu dữ liệu nằm liên tiếp cùng nhau 
// trong bộ nhớ.
// cCaau2 : Số luowjgn phần tử tối đa của mảng là số lượng phần tử mà cái mảng đó
// có thể chứa được nếu như số lượng vượt qua mảng đó thì sẽ k chưa vd tủ 5 ngăn thì
// chỉ chứa được 5 ngăn không có ngăn thứ 6 để chưa.
// 
// câu 3 : mảng tĩnh là mảng có số lượng phân tử tối đa không thể thay đổi được :(
// còn mảng động thì có thể thay đổi kích thước số lượng phần tử 
// 
// câu 4 ; int a[7] là khai báo khai báo một cái mảng tên là a với kiểu dữ liệu số
// nguyên (int) với 7 vùng nhớ kiểu (int) hay là có 7 phần tử ;Còn a[0] thì lại không
// có kiểu dữ liệu không có 1 vùng nhớ nào cả 
// 
// Ccaau 5; Mảng hay ở chỗ khi khai báo xong nếu không nhập giá trị luôn thì nó
// sẽ mặc định là 0 ,không như biến thông thường mặc định giá trị rác;
// 
// Câu 6 : ta biet kiểu float có (4byte) hay còn gọi là 32 bit, vì vây neeus ta khai báo 
// kiểu  float a[n] thì:
// Hệ điệu hành cấp phát cho ta n vùng nhớ hay còn gọi là n phần tử với mỗi một vùng nhớ
//  có kích thước là 4byte;
// Kích thước của mảng đó = n*4 (byte) hoặc = n*32(bit)
// 
// 
// Bài tập 

#include<iostream>
#define MAX 100
using namespace std;
//=== nguyên mẫu hàm
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
		cout << "Nhap n : ";
		cin >> n;
	} while (n <= 0 || n > MAX);
	// So_nt(a, n); ====== Số nguyên tố 
	// Gtri_le(a,n); ====== Giá trị lẻ cuối cùng
	// Doan(a, n); ======== Đoạn [a, b] chứa mọi giá trị trong mảng.
	// Duong(a, n); ======== So toan duong
	// Tangdan(a, n); == Kiemtra xem số đso có tăng dần hay khong 
	// Sieu_nguyento(a,n);
	return 0;
}

void So_nt(int a[], int n)
{
	Nhap(a, n);
	cout << "So nguyent to trong mang la: ";
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
			cout << a[i] << " ";
		}
	}
}

void Gtri_le(int a[],int n)
{
	Nhap(a, n);
	for(int i = 1; i < n; i++)
	{
		if (a[n-i] % 2 != 0)
		{
			cout << "Gia tri le la : " << a[n - i];
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
	cout << "Doan chua moi gia tri la : " << "[" << Min << "," << Max << "] ";

}

void Duong(int a[], int n)
{
	Nhap(a, n);
	bool kiemtra=true;
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
		cout << "Khong phai so toan duong";
	}
	else
	{
		cout << "La so toan duong";
	}
}

void Tangdan(int a[], int n)
{
	Nhap(a, n);
	bool kiemtra ;
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
			cout << "Khong tang dan ";
			break;
		}
		temp = a[i];
	}
	if ( kiemtra == true)
	{
		cout << "Tang dan ";
	}
}

bool So_NT(int temp) // phục vụ cho số siêu nguyên tố
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
	cout << "Cac so sieu nguyen to la : \t";
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
				cout << a[i] << " ";
			}
		}
	}
}

void Nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i << " : ";
		cin >> a[i];
	}
}

void Xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i];
	}
}
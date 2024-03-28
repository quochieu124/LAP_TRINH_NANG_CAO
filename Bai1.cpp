#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct sinhvien{
	int tuoi;
	float diem;
};
void docfile(sinhvien **sv,int &n,char *tentep)
{
	FILE *f=fopen(tentep,"r");
	if(f==NULL)
	{
		printf("\nLoi tao file!");
		exit(0);
	}
	fscanf(f,"%d\n",&n);
	//Cap phat bo nho dong:
	(*sv)=(sinhvien*) malloc (n*sizeof(sinhvien));
	//doc tung gia tri:
	for(int i=0;i<n;i++)
	{
		fscanf(f,"%d",&(*sv)[i].tuoi);
		fscanf(f,"%f",&(*sv)[i].diem);
	}
	//XUat ra man hinh xem co doc duoc khong:
	for(int i=0;i<n;i++)
	{
		printf("\nTuoi sinh vien %d la: %d___Diem la:%.2f",i+1,(*sv)[i].tuoi,(*sv)[i].diem);
	}
}
//xuat ra man hinh 5 sinh vien co diem cao nhat:
void caonhat(sinhvien *sv,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(sv[i].diem > sv[j].diem)
			{
				sinhvien sapxep=sv[i];
				sv[i]=sv[j];
				sv[j]=sapxep;
			}	
		}
	}
	//xuat ra man hinh:
	printf("\nDiem 5 sinh vien cao nhat la: \n");
	for(int i=0;i<6;i++)
	{
		printf("%.2f ",sv[i].diem);
	}
}
//nhap vao do tuoi t tu ban phim,tinh diem trung binh cua tat ca sinh vien co tuoi t:
void diemtrungbinh(sinhvien *sv,int n,int t)
{
	float dtb=0;
	float tong=0;
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(sv[i].tuoi==t)
		{
			dem++;
			tong+=sv[i].diem;
		}
	}
	if(dem==0)
	{
		printf("\nKhong co sinh vien nao co do tuoi bang t");
	}
	else
	{
		dtb+=tong/dem;
		printf("\nDiem trung binh la: %.2f",dtb);
	}
}
int main()
{
	int n;
	sinhvien *sv;
	char tentep[50]="Sinhvien.txt";
	docfile(&sv,n,tentep);
	caonhat(sv,n);
	int t;
	printf("\nNhap vao tuoi t: ");
	scanf("%d",&t);
	diemtrungbinh(sv,n,t);
	return 0;
	
}

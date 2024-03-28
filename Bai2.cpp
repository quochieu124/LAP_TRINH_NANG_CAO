#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct nghesy{
	char ten[30];
	char sdt[15];
	int catxe;
};
void docfile(nghesy **ns,int &n,char *tentep)
{
	FILE *f=fopen(tentep,"r");
	if(f==NULL)
	{
		printf("\nLoi mo file!");
		exit(0);
	}
	fscanf(f,"%d\n",&n);
	//Cap phat bo nho dong:
	(*ns)=(nghesy*) malloc(n*sizeof(nghesy));
	for(int i=0;i<n;i++)
	{
		fscanf(f," %[^\n]",(*ns)[i].ten);
		fscanf(f," %[^\n]",(*ns)[i].sdt);
		fscanf(f,"%d",&(*ns)[i].catxe);
	}
	//xuat ra man hinh xem co doc duoc khong:
	for(int i=0;i<n;i++)
	{
		printf("\nHo ten la: %s___SDT la: %s___Catxe la: %d",(*ns)[i].ten,(*ns)[i].sdt,(*ns)[i].catxe);
	}
}
void sapxep(nghesy *ns,int n,FILE *f1=stdout)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ns[i].catxe > ns[j].catxe)
			{
				nghesy sapxep=ns[i];
				ns[i]=ns[j];
				ns[j]=sapxep;
			}
		}
	}
	printf("\nTen cac nghe sy theo catxe giam dan la: \n");
	fprintf(f1,"\nTen cac nghe sy theo catxe giam dan la: \n");
	for(int i=0;i<n;i++)
	{
		printf("\n%s ",ns[i].ten);
		fprintf(f1,"\n%s\n%s\n%d",ns[i].ten,ns[i].sdt,ns[i].catxe);
	}
}
void tong(nghesy *ns,int n,FILE *f1=stdout)
{
	int tong=0;
	for(int i=0;i<n;i++)
	{
		tong+=ns[i].catxe;
	}
	fprintf(f1,"\nTong so tien catxe cua tat ca cac nghe sy la: %d ",tong);
}
int main()
{
	int n;
	nghesy *ns;
	char tentep[50]="NgheSy.txt";
	docfile(&ns,n,tentep);
	FILE *f1=fopen("Catxe.txt","w");
	if(f1==NULL)
	{
		printf("\nLoi mo file!");
		exit(0);
	}
	sapxep(ns,n,f1);
	tong(ns,n,f1);
	return 0;
	
	
}

#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	int *G,*F;
	int i,j,z,k;
	printf("������� ������ �������: ");
	scanf("%d",&z);
	printf("\n");
	G = (int*)malloc(z*z * sizeof(int));
	F = (int*)malloc(z * sizeof(int));
	printf("������� 1 ���� ������� ������� ������ �������, 0 ���� �� �������: ");
	scanf("%d",&k);
	printf("\n");
	if (k==1)
	for (i=0;i<z;i++)
	{
		for (j=i;j<z;j++)
		{
			printf("����� ����� %d � %d ���������: ",i,j);
			scanf("%d",(G+i*z+j));
			*(G+j*z+i)=*(G+i*z+j);
		}
	}
	else
	for (i=0;i<z;i++)
	{
		for (j=i;j<z;j++)
		{
			*(G+i*z+j)=rand()%2;
			*(G+j*z+i)=*(G+i*z+j);
		}
		*(G+i*z+i)=0;
	}
	k=0;
	FILE *Itog;
	Itog = fopen("Itog.txt", "w");
	for (i=0;i<z;i++)
	{
		if (i==0) 
		{
			printf("   ");
			fprintf(Itog, "   ");
			for (j=0;j<z;j++)
			{
				printf("%2d",j);
				fprintf(Itog, "%2d",j);
			}
			printf("\n\n");
			fprintf(Itog, "\n\n");
		}
		printf("%2d ",i);
		fprintf(Itog, "%2d ",i);
		for (j=0;j<z;j++)
		{
			printf("%2d",*(G+i*z+j));
			fprintf(Itog, "%2d", *(G+i*z+j));
		}
	printf("\n");
	fprintf(Itog, "\n");
	}
	printf("\n");
	fprintf(Itog, "\n");
	for (i=0;i<z-1;i++)
	{
		for (j=i+1;j<z;j++)
		{
			if (*(G+i*z+j)==1)
			{
				F[i]=1;
				F[j]=1;
			}
			if (F[j]!=1) F[j]=0;
		}
		if (F[i]!=1) F[i]=0;
	}
	for (i=0;i<z;i++)
		if (F[i]==0)
		{
		printf("������� %d �������� �������������\n", i);
		fprintf(Itog, "������� %d �������� �������������\n", i);
		k++;
		}
	if (k==0)
	{
		printf("������������� ������ ���");
		fprintf(Itog, "������������� ������ ���");
	}
	fclose(Itog);
	free(G);
	getch();
	return 0;
}

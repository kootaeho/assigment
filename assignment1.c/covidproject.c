/*
[���׸� 1] : ��������
 �а�:��ǻ�Ͱ��а�
 �й�:202200340
 �̸�:����ȣ

 ��������:�� ������ 1�δ� �����Ѽҵ�(1�δ� GNI) ���ذ� �ڷγ� ������� ���� + ������ 1�δ� GNI��� �Լ�

*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000000000
#include <stdio.h>
#include <string.h>
#include "GPP1.h"                           //[���׸� 8] : ���� �ҽ� ���� ���
double  Pop;  //�α�(Population)
double GNI;  //�����Ѽҵ�
double* p_g; //������ ����
double GPP; //1�δ� ���μҵ�
char DR[100]; //����� (Death rate)                  [���׸� 3] : �迭���
char name[100];  //���� �̸�
char line[MAX];
double result;
struct Covidinfo {
	char* Title;
	char* Symptom;
	char* definition;
	int IP;// (incubation period / �ẹ��)
	int infected;//(2022�� 6��11�� ���� ������ �����ڼ�)
	int Death;//(2022sus 6 �� 11�� ���� ������ ����ڼ�)
};

int GNI_Perperson(char name[100], char DR[100], double Pop, double GNI, double* p_g);  //[���׸� 2] : �Լ����
int main() {
	struct Covidinfo covidinfo220611;                //[���׸�5 ] : ����ü ���
	covidinfo220611.Title = "Covid Virus";
	covidinfo220611.definition = "2019�� 12�� �߱� ���ѿ��� ó�� �߻��� �� �� ����� Ȯ���, ���ο� ������ �ڷγ����̷����� ���� ȣ��� ������ȯ.";
	covidinfo220611.Symptom = "�߿�, ���°�, ��ħ, ȣ���� �� ���,����, ������, ����, ������ ����, ����";
	covidinfo220611.IP = 6;
	covidinfo220611.infected = 534187944;
	covidinfo220611.Death = 6306367;

	char answer[100];
	for (int i = 0; i < 200; i++) {
		printf("����Ͻ� ����� �Է��ϼ���(1,2,3,4 �� �ϳ��Է�) \n");
		printf("\n(1)�ڷγ� ���� (2)������ ���� (3)1�δ� GNI��� (4)���α׷� ���� : ");
		scanf("%s", answer);
		char(*pa)[100];                         //[���׸� 6] : ������ Ȱ��
		pa = &answer;

		if (strcmp(pa, "1") == 0) {
			printf("\n\n");
			printf("----�ڷγ� �⺻ ����-----------------------------------------------------\n");
			printf("��Ī : %s\n", covidinfo220611.Title);
			printf("���� : %s\n", covidinfo220611.definition);
			printf("���� : %s\n", covidinfo220611.Symptom);

			printf("�ẹ�� : %d��\n", covidinfo220611.IP);
			printf("(2022�� 6�� 11�� ����)������ �����ڼ� : %d      ����ڼ� : %d\n", covidinfo220611.infected, covidinfo220611.Death);
			printf("-------------------------------------------------------------------------\n\n\n");
		}

		//�� ��� ����
		/*FILE* fp = fopen("C:\\Users\\0307r\\source\\repos\\assignment1.c\\assignment1.c\\countryinfo1.txt", "wt");  //[���׸� 7] : ���� �����
		if (fp == NULL) {
			printf("���� ���� ����");
		}
		fputs("Norway-Pop:550(����) / 1�δ� GNI:6,9761(�޷�)/ DR:0.2% \n", fp);
		fputs("ROK-Pop:5,190(����) / 1�δ� GNI:3,1000(�޷�) / DR:0.1% \n", fp);
		fputs("Slovakia-Pop:546(����) / 1�δ� GNI:1,8800(�޷�) / DR:0.8% \n", fp);
		fputs("Philiphinnes-Pop:1��1250(����) / 1�δ� GNI:3,500(�޷�) / DR:1.6% \n", fp);
		fputs("India-Pop:14��663���� / 1�δ� GNI:1,883(�޷�) / DR:1.2% \n", fp);
		fputs("Uganda-Pop:4,843(����) / 1�δ� GNI:804(�޷�) / DR:2.2% \n", fp);
		fclose(fp);*/
		else if (strcmp(pa, "2") == 0) {
			printf("\n\n");
			FILE* fp = fopen("C:\\Users\\0307r\\source\\repos\\assignment1.c\\assignment1.c\\countryinfo1.txt", "rt"); //[���׸� 7] : ���� �����
			printf("�� ������ ����\n");
			printf("-----------------------------------------------------------\n");
			while (fgets(line, MAX, fp) != NULL) {
				printf("%s", line);
			}
			printf("-----------------------------------------------------------");
			printf("\n\n");
		}
		else if (strcmp(pa, "3") == 0) {
			GNI_Perperson(name, DR, Pop, GNI, p_g);
		}
		else if (strcmp(pa, "4") == 0) {
			printf("\n\n���α׷��� ����Ǿ����ϴ�.\n\n");
			return 0;
		}
	}return 0;
}


int GNI_Perperson(char name[100], char DR[100], double Pop, double GNI, double* p_g) {
	printf("----------------------------------------------------\n");

	getc(stdin);

	printf("������ �̸��� �Է��ϼ��� :");
	gets_s(name, 100);

	printf("\n%s�� �ڷγ� ������� �Է��ϼ���(ex 1.2 % %) :", name);
	scanf("%s", DR);

	printf("\n%s�� �α��� �Է��ϼ��� : ", name);
	scanf("%lf", &Pop);

	printf("\n%s�� ���� �� �ҵ��� �Է��ϼ���(����:�޷�):", name);
	scanf("%lf", &GNI);

	result = GPP_result(GNI, Pop, GPP);

	p_g = &result;  //[���׸� 4] : ������ ���

	printf("\n%s�� 1�δ� ���� �� �ҵ��� %lf�޷� �Դϴ�.", name, *p_g);
	printf("\n\n%s�� �ڷγ� ������� %s�Դϴ�.\n", name, DR);
	printf("-----------------------------------------------------\n\n");

	return 0;
}

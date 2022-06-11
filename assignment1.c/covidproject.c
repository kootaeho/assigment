/*
[평가항목 1] : 과제설명
 학과:컴퓨터공학과
 학번:202200340
 이름:구태호

 과제주제:각 국가별 1인당 국민총소득(1인당 GNI) 수준과 코로나 사망률의 관계 + 국가별 1인당 GNI계산 함수

*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000000000
#include <stdio.h>
#include <string.h>
#include "GPP1.h"                           //[평가항목 8] : 다중 소스 파일 사용
double  Pop;  //인구(Population)
double GNI;  //국민총소득
double* p_g; //포인터 선언
double GPP; //1인당 국민소득
char DR[100]; //사망률 (Death rate)                  [평가항목 3] : 배열사용
char name[100];  //국가 이름
char line[MAX];
double result;
struct Covidinfo {
	char* Title;
	char* Symptom;
	char* definition;
	int IP;// (incubation period / 잠복기)
	int infected;//(2022년 6월11일 기준 전세계 감염자수)
	int Death;//(2022sus 6 월 11일 기준 전세계 사망자수)
};

int GNI_Perperson(char name[100], char DR[100], double Pop, double GNI, double* p_g);  //[평가항목 2] : 함수사용
int main() {
	struct Covidinfo covidinfo220611;                //[평가항목5 ] : 구조체 사용
	covidinfo220611.Title = "Covid Virus";
	covidinfo220611.definition = "2019년 12월 중국 우한에서 처음 발생한 뒤 전 세계로 확산된, 새로운 유형의 코로나바이러스에 의한 호흡기 감염질환.";
	covidinfo220611.Symptom = "발열, 권태감, 기침, 호흡곤란 및 폐렴,가래, 인후통, 두통, 객혈과 오심, 설사";
	covidinfo220611.IP = 6;
	covidinfo220611.infected = 534187944;
	covidinfo220611.Death = 6306367;

	char answer[100];
	for (int i = 0; i < 200; i++) {
		printf("사용하실 기능을 입력하세요(1,2,3,4 중 하나입력) \n");
		printf("\n(1)코로나 정보 (2)국가별 정보 (3)1인당 GNI계산 (4)프로그램 종료 : ");
		scanf("%s", answer);
		char(*pa)[100];                         //[평가항목 6] : 포인터 활용
		pa = &answer;

		if (strcmp(pa, "1") == 0) {
			printf("\n\n");
			printf("----코로나 기본 정보-----------------------------------------------------\n");
			printf("명칭 : %s\n", covidinfo220611.Title);
			printf("정의 : %s\n", covidinfo220611.definition);
			printf("증상 : %s\n", covidinfo220611.Symptom);

			printf("잠복기 : %d일\n", covidinfo220611.IP);
			printf("(2022년 6월 11일 기준)전세계 감염자수 : %d      사망자수 : %d\n", covidinfo220611.infected, covidinfo220611.Death);
			printf("-------------------------------------------------------------------------\n\n\n");
		}

		//비교 대상 국가
		/*FILE* fp = fopen("C:\\Users\\0307r\\source\\repos\\assignment1.c\\assignment1.c\\countryinfo1.txt", "wt");  //[평가항목 7] : 파일 입출력
		if (fp == NULL) {
			printf("파일 열기 실패");
		}
		fputs("Norway-Pop:550(만명) / 1인당 GNI:6,9761(달러)/ DR:0.2% \n", fp);
		fputs("ROK-Pop:5,190(만명) / 1인당 GNI:3,1000(달러) / DR:0.1% \n", fp);
		fputs("Slovakia-Pop:546(만명) / 1인당 GNI:1,8800(달러) / DR:0.8% \n", fp);
		fputs("Philiphinnes-Pop:1억1250(만명) / 1인당 GNI:3,500(달러) / DR:1.6% \n", fp);
		fputs("India-Pop:14억663만명 / 1인당 GNI:1,883(달러) / DR:1.2% \n", fp);
		fputs("Uganda-Pop:4,843(만명) / 1인당 GNI:804(달러) / DR:2.2% \n", fp);
		fclose(fp);*/
		else if (strcmp(pa, "2") == 0) {
			printf("\n\n");
			FILE* fp = fopen("C:\\Users\\0307r\\source\\repos\\assignment1.c\\assignment1.c\\countryinfo1.txt", "rt"); //[평가항목 7] : 파일 입출력
			printf("각 국가별 정보\n");
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
			printf("\n\n프로그램이 종료되었습니다.\n\n");
			return 0;
		}
	}return 0;
}


int GNI_Perperson(char name[100], char DR[100], double Pop, double GNI, double* p_g) {
	printf("----------------------------------------------------\n");

	getc(stdin);

	printf("국가의 이름을 입력하세요 :");
	gets_s(name, 100);

	printf("\n%s의 코로나 사망률을 입력하세요(ex 1.2 % %) :", name);
	scanf("%s", DR);

	printf("\n%s의 인구를 입력하세요 : ", name);
	scanf("%lf", &Pop);

	printf("\n%s의 국민 총 소득을 입력하세요(단위:달러):", name);
	scanf("%lf", &GNI);

	result = GPP_result(GNI, Pop, GPP);

	p_g = &result;  //[평가항목 4] : 포인터 사용

	printf("\n%s의 1인당 국민 총 소득은 %lf달러 입니다.", name, *p_g);
	printf("\n\n%s의 코로나 사망률은 %s입니다.\n", name, DR);
	printf("-----------------------------------------------------\n\n");

	return 0;
}

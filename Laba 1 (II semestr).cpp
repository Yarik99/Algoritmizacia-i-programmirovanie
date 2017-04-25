#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <cstdlib>
#include <iostream>

typedef struct 
{
	char PunktOtprav[20];
	char PunktNaznach[20];
	char NomerMarsh[3];
} Marsh;

void GlavMenu(Marsh *marsh,int kol);

int KolMarshs() {
	FILE *f;
	char kolstr[100];
	int i = 0;
	if (!(f = fopen("C:/Users/Ярослав/Downloads/marsh.txt", "r"))) {
		printf("Файл не найден....\n");
		getch();
		system("pause");
		exit(0);
	} else {
		while(fgets(kolstr, 100, f)){
			i++;
		}
		fclose(f);
		return i;
	}
	
}

void ReadFile(Marsh *marsh) {
	FILE *f;
	int i = 0;
	if (!(f = fopen("C:/Users/Ярослав/Downloads/marsh.txt", "r"))) {
		printf("Файл не найден....\n");
		getch();
		system("pause");
		exit(0);
	} else {
	while ((fscanf(f," %s %s %s \n", marsh[i].PunktOtprav, marsh[i].PunktNaznach, marsh[i].NomerMarsh)!=EOF))
	{
		i++;
	}
		fclose(f);
	}
}
void ShowMarshs(Marsh *marsh, int kol) {
	system("cls");

	printf("\t\tSpisok marshrutov\n\n");

	for (int i = 0; i < kol; i++) {
		printf(" %d | %-15s | %-15s | %-2s|\n", i + 1, marsh[i].PunktOtprav, marsh[i].PunktNaznach, marsh[i].NomerMarsh);
	}
}	

void AddMarsh() {
	system("cls");
	Marsh NewMarsh;
	FILE *f;
	printf("\t\tDobavlenie zapisi\n\n");
	printf("Punkt otpravlenia  ");
	scanf("%s", NewMarsh.PunktOtprav);
	printf("\nPunkt naznachenia  ");
	scanf("%s", NewMarsh.PunktNaznach);
	printf("\nNomer marshruta  ");
	scanf("%s", NewMarsh.NomerMarsh);
	f = fopen("C:/Users/Ярослав/Downloads/marsh.txt", "a");
	fprintf(f, " %s %s %s ", NewMarsh.PunktOtprav, NewMarsh.PunktNaznach, NewMarsh.NomerMarsh);
	fclose(f);
	printf("\nZapis dobavlena\n");
}

void DelMarsh(Marsh *marsh,int kol) {
	system("cls");

	printf("\t\tUdalenie zapisi\n\n");

	FILE *f;
	int i = 0,numdel;
	ShowMarshs(marsh, kol);
	printf("\nVvedite nomer udalaemoi zapisi\n");
	scanf("%d", &numdel);
	if(numdel<kol){
	for (i = numdel; i < kol - 1; i++) {
		marsh[i] = marsh[i + 1];
	}
	f = fopen("C:/Users/Ярослав/Downloads/marsh.txt", "w");
	i = 0;
	while (i < kol - 1) {
		fprintf(f, "%s %s %s \n", marsh[i].PunktOtprav, marsh[i].PunktNaznach, marsh[i].NomerMarsh);
		i++;
	}
	fclose(f);
	printf("Zapis udalena\n", numdel);}
	else printf("Takogo marshruta net\n");
}

void FilterMarsh(Marsh *SortMarsh, int kol) {
	Marsh dop;
	FILE *f;
	int k = 1;
	while (k) {
		k = 0;
		for (int i = 0; i < kol - 1 ; i++) {
			if (strcmp(SortMarsh[i].NomerMarsh, SortMarsh[i + 1].NomerMarsh) > 0) {
				k = 1;
				dop = SortMarsh[i];
				SortMarsh[i] = SortMarsh[i + 1];
				SortMarsh[i + 1] = dop;	
			}
		}
	}
	ShowMarshs(SortMarsh, kol);
	f = fopen("C:/Users/Ярослав/Downloads/sort.txt", "w");
	int i = 0;
	while (i < kol ) {
		fprintf(f, "%s %s %s\n", SortMarsh[i].PunktOtprav, SortMarsh[i].PunktNaznach, SortMarsh[i].NomerMarsh);
		i++;
	}
	fclose(f);
}

void MarshNum(Marsh *marsh, int kol) {
	system("cls");

	int flag=0;
	char nmbr[10];

	printf("\t\tInformacia o marshrute\n\n");

	printf("Vvedite nomer marshruta\n\n");
	scanf("%s", &nmbr);
	for(int i = 0; i < kol; i++) {
		//printf("%s", marsh[i].NomerMarsh);
		if (strcmp(marsh[i].NomerMarsh, nmbr) == 0) {
			printf("\n\nMarshrut s nomerom %s\n\n", nmbr);
			printf(" %d| %s | %s | %s|\n", i + 1,marsh[i].PunktOtprav, marsh[i].PunktNaznach, marsh[i].NomerMarsh);
			flag=1;
		}
	
	}
	if(flag==0) printf("\n\nTakogo marshruta net\n");
}



void VlogMenu(Marsh *marsh, int kol) {
	printf("\n\n");
	printf("Vernutsa v glavnoe menu - w\n\n");
	printf("Viyti-nazmite q\n");
	while (true) {
		switch (_getch()) {
		case 'w':
			GlavMenu(marsh,kol);
			break;
		case 'q':
			//abort();
			exit(0);
			break;
		}
	}
}

void GlavMenu(Marsh *marsh,int kol) {
	system("cls");

	printf("\t\tGlavnoe Menu:\n\n");
	
	printf("1 - Otobrazit vse zapisi\n");
	printf("2 - Dobavit zapis\n");
	printf("3 - Udalit zapis\n");
	printf("4 - Pokazat  nomer marshruta\n");
	printf("5 - Sortirovka po nomeru marshruta\n");
	printf("q - Quit\n");
	printf("\n");
	while (true) {
		switch (_getch()) {
		case '1':
			ShowMarshs(marsh,kol);
			VlogMenu(marsh,kol);
			break;

		case '2':
			AddMarsh();
			VlogMenu(marsh,kol);
			break;

		case '3':
			DelMarsh(marsh, kol);
			VlogMenu(marsh,kol);
			break;

		case '4':
			MarshNum(marsh, kol);
			VlogMenu(marsh,kol);
			break;

		case '5':
			FilterMarsh(marsh, kol);
			VlogMenu(marsh,kol);
			break;

		case 'q':
			//abort();
			exit(0);
			break;
		}
	}

}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "rus");
	system("color F0");
	int kol = KolMarshs();
	Marsh marsh[5];
	ReadFile(marsh);
	GlavMenu(marsh,kol);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
	
int main()
{
	int pil = 0; 				//variabel
	for (;;) 				   //pengulangan
	{
		printf("\n\n\n\n\n\n\n\n\t\t\t\t==============================================\n");
		printf("\t\t\t\t\t  [WELCOME TO CAHYA LIBRARY]\n");
		printf("\t\t\t\t==============================================\n\n");
		printf("\t\t\t\t\t 1. Registrasi \n");
		printf("\t\t\t\t\t 2. Masuk sebagai admin \n");
		printf("\t\t\t\t\t 3. Selesai \n");
		printf("\n\t\t\t\t\t Pilihan	: ");
		scanf("%d", &pil); fflush(stdin);						//input pilihan
		switch (pil) {
			case 1 : { 	registration();
				break;
			}
			case 2 : { 	login();
				break;
			}
			case 3 : { exit(0);
			}
			default : {
			printf("\n\t\t\t\t\t Pilihan tidak ditemukan!");
			getch();
			system("cls");
			main();
			break;
			}
		}
	}	
}


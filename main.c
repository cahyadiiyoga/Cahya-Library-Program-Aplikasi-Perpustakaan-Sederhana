#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
	
int main()
{
	console_clear_screen();
	int pil = 0; 				//variabel
	for (;;) 					//pengulangan
	{
		printf("\n\n\n\n\n\n\n\n\t\t\t\t==============================================\n");
		printf("\t\t\t\t\t  [WELCOME TO CAHYA LIBRARY]\n");
		printf("\t\t\t\t==============================================\n\n");
		printf("\t\t\t\t\t 1. Registrasi \n");
		printf("\t\t\t\t\t 2. Masuk sebagai admin \n");
		printf("\t\t\t\t\t 3. Daftar Buku \n");
		printf("\t\t\t\t\t 4. Panduan menggunakan aplikasi \n");
		printf("\t\t\t\t\t 5. Selesai \n");
		printf("\n\t\t\t\t\t Pilihan	: ");
		scanf("%d", &pil); fflush(stdin);						//input pilihan
		switch (pil) {
			case 1 : { 	registration();
				break;
			}
			case 2 : { 	login();
				break;
			}
			case 3 : { 	Tampil_File();
				getch();
				console_clear_screen();
				break;
			}	
//			case 4 : { 	panduan();
//				break;
//			}
			case 5 : { exit(0);
			}
			default : {
			printf("\n\t\t\t\t\t Pilihan tidak ditemukan!");
			getch();
			console_clear_screen();
			main();
			break;
			}
		}
	}	
}

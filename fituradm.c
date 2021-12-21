#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Membersihkan Menu Sebelumnya
#define WINDOWS 1

void console_clear_screen() {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}

//=============================================================================  Fitur Login  =====================================================================================
struct login
{
    char username[20];
    char password[20];
};

void registration()
{
    FILE *log;
    log=fopen("login.txt","w");
    struct login l;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t==============================================\n");
	printf("\t\t\t\t\t\t  [REGISTRASI]\n");
	printf("\t\t\t\t==============================================\n\n");
	printf("\t\t\t\t\t Masukkan username : ");
	scanf("%s",l.username);
	printf("\t\t\t\t\t Masukkan password : ");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);
    
    fclose(log);
    
    printf("\n\t\t\t\t\tRegistrasi selesai, silakan login! \n");
    getch();
    system("cls");
    login();
}

void login()
{
    char username[20];
    char password[20];
    FILE *log;
    log=fopen("login.txt","r");
    struct login l;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t==============================================\n");
	printf("\t\t\t\t\t\t   [LOGIN]\n");
	printf("\t\t\t\t==============================================\n\n");
	printf("\t\t\t\t\t Masukkan username : ");
    scanf("%s", &username);
	printf("\t\t\t\t\t Masukkan password : ");
    scanf("%s", &password);
    
    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            printf("\n\t\t\t\t\t Login sukses!");
        }
        else
        {
            printf("\n\t\t\t\t\t Masukkan username dan password yang benar.");
        }
    }
    fclose(log);
    getch();
    system("cls");
    menuadm();
}

//=============================================================================  Menu Admin  =====================================================================================
void menuadm()
{
	system("cls");
	int pil = 0;
	printf("\n\n\n\n\n\n\n\n\t\t\t\t==============================================\n");
	printf("\t\t\t\t\t\t[Menu Admin]\n");
	printf("\t\t\t\t==============================================\n");
	printf("\t\t\t\t 1. Pinjam Buku\n");
	printf("\t\t\t\t 2. Kembalikan Buku \n");
	printf("\t\t\t\t 3. Input Buku \n");
	printf("\t\t\t\t 4. Hapus Data Buku \n");
	printf("\t\t\t\t 5. Kembali ke menu sebelumnya \n");
	printf("\t\t\t\t 6. Selesai \n");
	printf("\n\t\t\t\t Pilihan	: ");
	scanf("%d", &pil); fflush(stdin);
	switch (pil)
	{
		case 1 : { menupinjam();
			break;
		}
//		case 2 : { kembalikanbuku();
//		break;
//		}
//		case 3 : { Input_Buku();
//		break;
//		}
//		case 4 : { menuhapus();
//			break;
//		}
		case 5 : { main();
			break;
		}
		case 6 :{ exit(1);
			break;
		}
		default : { menuadm();
		}
	}
}

//===================================================================  Menu Pinjam dan Kembalikan Buku  ==========================================================================
void menupinjam()
{
	system("cls");
	int pil = 0;
//	Tampil_File();
//	sortKode(buku);
	printf("\n========================================================================================================================\n");
	printf("|                                                 [Menu Sewa Buku]                                                 |\n");
	printf("========================================================================================================================\n");
	printf("\t * Maksimal waktu peminjaman adalah 1 minggu, jika melebihi batas waktu akan terkena denda per hari\n");
	printf("\t ** Denda : Rp 1000/hari\n\n\n");
	printf("\t 1. Pinjam\n");
	printf("\t 2. Kembali ke menu sebelumnya \n");
	printf("\n\t Pilihan	: ");
	scanf("%d", &pil); fflush(stdin);
	switch (pil)
		{
//			case 1 : { 	pinjam();
//		}
				break;
			case 2 : { menuadm();
			}
			default :{
				printf("\n\t\t\t\t\t Pilihan tidak ditemukan!");
				getch();
				system("cls");
				menupinjam();
				break;
			}
		}
}



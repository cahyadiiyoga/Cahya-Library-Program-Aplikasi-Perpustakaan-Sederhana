#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "fituradm.h"

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
void registration()
{
    FILE *log;
    log = fopen("login.txt","w");
    struct login l;
    console_clear_screen();
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
    console_clear_screen();
    login();
}

void login()
{
    char username[20];
    char password[20];
    FILE *log;
    log = fopen("login.txt","r");
    struct login l;
    console_clear_screen();
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
    console_clear_screen();
    menuadm();
}

//=============================================================================  Menu Admin  =====================================================================================
void menuadm()
{
	console_clear_screen();
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
		case 4 : { menuhapus();
			break;
		}
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
	console_clear_screen();
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
//		case 1 : { 	pinjam();
//	}
			break;
		case 2 : { menuadm();
		}
		default :{
			printf("\n\t\t\t\t\t Pilihan tidak ditemukan!");
			getch();
			console_clear_screen();
			menupinjam();
			break;
		}
	}
}

//===================================================================  Menu dan fitur hapus buku  ================================================================================
void menuhapus(){
	int pil = 0;
//	Tampil_File();
	printf("\n========================================================================================================================\n");
	printf("|                                                 [Menu Hapus]                                  	               |\n");
	printf("========================================================================================================================\n");
	printf("\t 1. Hapus 1 data\n");
	printf("\t 2. Hapus semua data \n");
	printf("\t 3. Kembali ke menu sebelumnya \n");
	printf("\n\t Pilihan	: ");
	scanf("%d", &pil); fflush(stdin);
	switch (pil)
		{
			case 1 : { 	hapus1();
		}
				break;
			case 2 : { hapus2();
			}
			case 3 : { menuadm();
				break;
			}
			default :{
				printf("\n\t\t\t\t\t Pilihan tidak ditemukan!");
				getch();
				console_clear_screen();
				menuhapus();
				break;
			}
		}
}

void hapus1(){
	int pil;
	printf("Masukkan kode buku yang akan di hapus : ");
	scanf("%d",&pil); fflush(stdin);
	printf("Apakah anda yakin? (Y/T)");
	jawab = toupper(getche());			/* Baca jawaban dari keyboard */
	if (jawab == 'Y')
	{	
//		hapusdtbuku(buku, pil);
		menuhapus();
	}
	menuhapus();
}

void hapus2(){
	int pil;
	char jawab;
	printf("Apakah anda yakin? (Y/T)");
	jawab = toupper(getche());			/* Baca jawaban dari keyboard */
	if (jawab == 'Y')
	{	
//		hapusAllData(buku);
	}
	menuhapus();
}
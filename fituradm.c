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
}

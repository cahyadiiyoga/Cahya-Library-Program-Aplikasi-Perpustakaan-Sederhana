#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "fituradm.h"
#include "utama.h"

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
    log = fopen("login.txt", "w");
    struct login l;
    console_clear_screen();
    printf("\n\n\n\n\n\n\n\n\t\t\t\t==============================================\n");
	printf("\t\t\t\t\t\t  [REGISTRASI]\n");
	printf("\t\t\t\t==============================================\n\n");
	printf("\t\t\t\t\t Masukkan username : ");
	scanf("%s", l.username);
	printf("\t\t\t\t\t Masukkan password : ");
    scanf("%s", l.password);
    fwrite(&l, sizeof(l), 1, log);
    
    fclose(log);
    
    printf("\n\t\t\t\t\tRegistrasi selesai,  silakan login! \n");
    getch();
    console_clear_screen();
    login();
}

void login()
{
    char username[20];
    char password[20];
    FILE *log;
    log = fopen("login.txt", "r");
    struct login l;
    console_clear_screen();
    printf("\n\n\n\n\n\n\n\n\t\t\t\t==============================================\n");
	printf("\t\t\t\t\t\t   [LOGIN]\n");
	printf("\t\t\t\t==============================================\n\n");
	printf("\t\t\t\t\t Masukkan username : ");
    scanf("%s",  &username);
	printf("\t\t\t\t\t Masukkan password : ");
    scanf("%s",  &password);
    
    if(log)
    {
		while(fread(&l, sizeof(l), 1, log))
	    {
	        if(strcmp(username, l.username)==0 && strcmp(password, l.password)==0)
	        {
	            printf("\n\t\t\t\t\t Login sukses!");
	            getch();
	            menuadm();
	        }
	        else
	        {
	            printf("\n\t\t\t\t\t Masukkan username dan password yang benar!");
	            getch();
	            console_clear_screen();
	        }
	    }
	}
	else
	{
		printf("\n\t\t\t\t\t Buat akun terlebih dahulu!");
	    getch();
	    console_clear_screen();
	}    
    fclose(log);
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
	printf("\t\t\t\t 5. History Peminjaman\n");
	printf("\t\t\t\t 6. Kembali ke menu sebelumnya \n");
	printf("\t\t\t\t 7. Selesai \n");
	printf("\n\t\t\t\t Pilihan	: ");
	scanf("%d",  &pil); fflush(stdin);
	switch (pil)
	{
		case 1 : { menupinjam();
			break;
		}
		case 2 : { kembalikanbuku();
		break;
		}
		case 3 : { Input_Buku();
		break;
		}
		case 4 : { menuhapus();
			break;
		}
		case 5 : { daftarpj();
			break;
		}
		case 6 : { main();
			break;
		}
		case 7 : { exit(1);
			break;
		}
		default :{ menuadm();
		}
	}
}

//===================================================================  Menu Pinjam dan Kembalikan Buku  ==========================================================================
void menupinjam()
{
	console_clear_screen();
	int pil = 0;
	Tampil_File();
	sortKode(buku);
	printf("\n========================================================================================================================\n");
	printf("|                                                 [Menu Sewa Buku]                                                 |\n");
	printf("========================================================================================================================\n");
	printf("\t * Maksimal waktu peminjaman adalah 1 minggu,  jika melebihi batas waktu akan terkena denda per hari\n");
	printf("\t ** Denda : Rp 1000/hari\n\n\n");
	printf("\t 1. Pinjam\n");
	printf("\t 2. Kembali ke menu sebelumnya \n");
	printf("\n\t Pilihan	: ");
	scanf("%d",  &pil); fflush(stdin);
	switch (pil)
	{
		case 1 : { pinjam();
	}
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
void menuhapus()
{
	console_clear_screen();
	int pil = 0;
	Tampil_File();
	printf("\n========================================================================================================================\n");
	printf("|                                                 [Menu Hapus]                                  	               |\n");
	printf("========================================================================================================================\n");
	printf("\t 1. Hapus 1 data\n");
	printf("\t 2. Hapus semua data \n");
	printf("\t 3. Kembali ke menu sebelumnya \n");
	printf("\n\t Pilihan	: ");
	scanf("%d",  &pil); fflush(stdin);
	switch (pil)
		{
			case 1 : { hapus1();
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
	scanf("%d", &pil); fflush(stdin);
	printf("Apakah anda yakin? (Y/T)");
	jawab = toupper(getche());			/* Baca jawaban dari keyboard */
	if (jawab == 'Y')
	{	
		hapusdtbuku(buku,  pil);
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
		hapusAllData(buku);
	}
	menuhapus();
}

//============================================================================  Pinjam Buku  =====================================================================================
void pinjam(){
	
	struct tm *Sys_T;
	int pil = 0;
	int kodebuku, cek_kode;
	char a;
	Tampil_File();
	printf("\n\n========================================================================================================================\n");
	printf("|                                                 [Pinjam Buku]                                                 |\n");
	printf("========================================================================================================================\n");
	if ((dtpinjam=fopen("datapinjam.dat",  "ab")) == NULL ){
		printf("File tidak dapat dibuat!\r\n");
		main();
	}
	
	do {
		printf("\n\t Masukkan nomor : ");
		if (scanf("%d",  &bukupj.nomor) != 1){
			fflush(stdin);
			printf("\n\t Input Salah! Mohon masukkan angka.");
			getch();
			pinjam();
		}
		printf("\n\t Masukkan nama peminjam [Maksimal 10 Huruf] : ");fflush(stdin);
		scanf("\t%10s", bukupj.nama);fflush(stdin);
		printf("\n\t Masukkan kode buku yang akan dipinjam : ");fflush(stdin);
		scanf("\t%d",  &kodebuku);
		cek_kode = checkKode(buku,  kodebuku);
		if(cek_kode == 0){
			printf("\nKode Buku tidak ditemukan");
			pinjam();
		}else{
			bukupj.kode = kodebuku;
			dtbuku = fopen("daftarbuku.dat", "rb");
			while(fread(&buku,  sizeof(buku), 1,  dtbuku)){
				if(kodebuku == buku.kode){
					strcpy(bukupj.judul, buku.judul);
				}
			}
			fclose(dtbuku);
		}
		
		printf("\n\t Buku yang akan dipinjam : %s", bukupj.judul);
		printf("\n\n\t Tanggal Peminjaman : \n");fflush(stdin);
		Tanggal();
		time_t Tval;
    	Tval = time(NULL);
		Sys_T = localtime(&Tval);
		bukupj.tgl_pinjam.tgl = Sys_T->tm_mday;
		bukupj.tgl_pinjam.bln = Sys_T->tm_mon+1;
		bukupj.tgl_pinjam.thn = 1900+Sys_T->tm_year;
		/* Rekam sebuah data bertipe record menggunakan fungsi fwrite */
		fwrite(&bukupj,  sizeof(bukupj),  1,  dtpinjam);
		printf("\r\n\t Pinjam buku lagi? (Y/T)?"); fflush(stdin);
		jawab = toupper(getche());		/* Baca jawaban dari keyboard */
	}
	while (jawab == 'Y');
	fclose(dtpinjam);		/* Tutup file */
	
	printf("\r\nData peminjaman tersimpan.\r\n");
	menupinjam();
}

void kembalikanbuku()
{
	int pil = 0;

	Tampil_Pinjam();
	printf("\t 1. Kembalikan\n");
	printf("\t 2. Kembali ke menu sebelumnya \n");
	printf("\n\t Pilihan	: ");
	scanf("\t%d",  &pil); 
	fflush(stdin);

	switch (pil)
	{
		case 1 : 
		{ 	
			kembalikan();
		}
			break;
		case 2 : 
		{	
			menuadm();
		}
		default : 
		{
			printf("\n\t Pilihan tidak ditemukan!");
			getch();
			kembalikanbuku();
			break;
		}
	}
}

//===========================================================================  Kembalikan Buku  ==================================================================================
void kembalikan()
{
	data_tanggal kembali;
	int cek_kode,  tglpinjam,  blnpinjam,  thnpinjam,  denda,  telat,  uang,  kembalian;
	int pil = 0;
	char nama[16];
	char judul[30];
	Tampil_Pinjam();
	printf("\n\t Pilih nomor buku yang akan dikembalikan : ");
	scanf("\t%d",  &pil);
	cek_kode = checkNomor(bukupj, pil);
	if(cek_kode == 0)
	{
		printf("\n\t Data Peminjaman tidak ditemukan!");
		getch();
		kembalikanbuku();
	}
	else
	{
		dtpinjam = fopen("datapinjam.dat", "rb");
		while(fread(&bukupj,  sizeof(bukupj), 1, dtpinjam))
		{
			if(pil == bukupj.nomor)
			{
				tglpinjam = bukupj.tgl_pinjam.tgl;
				blnpinjam = bukupj.tgl_pinjam.bln;
				thnpinjam = bukupj.tgl_pinjam.thn;
				strcpy(judul, bukupj.judul);
				strcpy(nama, bukupj.nama);
			}
		}
		fclose(dtbuku);
	}
	printf("\n\t Masukkan tanggal pengembalian : \n");
	do
	{
		do
		{
			printf("\t Bulan [MM] : ");
			if (scanf("\t%d",  &kembali.bln) != 1)
			{
				fflush(stdin);
				printf("\n\t Input Salah! Mohon masukkan angka.");
				getch();
				kembalikan();
			}
		}
		while((kembali.bln <= 0) || (kembali.bln > 12));
		if(kembali.bln == 1 || kembali.bln == 3 || kembali.bln == 5 || kembali.bln == 7 || kembali.bln == 8 || kembali.bln == 10 || kembali.bln == 12)
		{
			printf("\t Tanggal [DD] : ");
			if (scanf("\t%d",  &kembali.tgl) != 1)
			{
				fflush(stdin);
				printf("\n\t Input Salah! Mohon masukkan angka.");
				getch();
				kembalikan();
			}
			if(kembali.tgl <= 0 || kembali.tgl > 31)
			{
				do
				{
					printf("\t Input Tanggal Salah! Harap Masukkan Kembali.\n");
					printf("\t Tanggal [DD] : ");
					if (scanf("\t%d",  &kembali.tgl) != 1)
					{
						fflush(stdin);
						printf("\n\t Input Salah! Mohon masukkan angka.");
						getch();
						kembalikan();
					}
				}
				while((kembali.tgl <= 0) || (kembali.tgl > 31));
			}
		}
		else if(kembali.bln == 4 || kembali.bln == 6 || kembali.bln == 9 || kembali.bln == 11)
		{
			printf("\t Tanggal [DD] : ");
			if (scanf("\t%d",  &kembali.tgl) != 1)
			{
				fflush(stdin);
				printf("\n\t Input Salah! Mohon masukkan angka.");
				getch();
				kembalikan();
			}
			if(kembali.tgl <= 0 || kembali.tgl > 30)
			{
				do
				{
					printf("\t Input Tanggal Salah! Harap Masukkan Kembali.\n");
					printf("\t Tanggal [DD] : ");
					if (scanf("\t%d",  &kembali.tgl) != 1)
					{
						fflush(stdin);
						printf("\n\t Input Salah! Mohon masukkan angka.");
						getch();
						kembalikan();
					}
				}
				while((kembali.tgl <= 0) || (kembali.tgl > 30));
			}
		}
		else if(kembali.bln == 2)
		{
			printf("\t Tanggal [DD] : ");
			if (scanf("\t%d",  &kembali.tgl) != 1)
			{
				fflush(stdin);
				printf("\n\t Input Salah! Mohon masukkan angka.");
				getch();
				kembalikan();
			}
			if(kembali.tgl <= 0 || kembali.tgl > 28)
			{
				do
				{
					printf("\t Input Tanggal Salah! Harap Masukkan Kembali.\n");
					printf("\t Tanggal [DD] : ");
					if (scanf("\t%d",  &kembali.tgl) != 1)
					{
						fflush(stdin);
						printf("\n\t Input Salah! Mohon masukkan angka.");
						getch();
						kembalikan();
					}
				}
				while((kembali.tgl <= 0) || (kembali.tgl > 28));
			}
		}
		printf("\t Tahun [YYYY] : ");
		if (scanf("\t%d",  &kembali.thn) != 1)
		{
			fflush(stdin);
			printf("\n\t Input Salah! Mohon masukkan angka.");
			getch();
			kembalikan();
		}
	}
	while((((kembali.tgl < tglpinjam) && (kembali.bln < blnpinjam)) && (kembali.thn == thnpinjam)) || (kembali.thn < thnpinjam));
	telat = (kembali.tgl - tglpinjam) + ((kembali.bln - blnpinjam) * 30 + ((kembali.thn - thnpinjam) * 365));
	if(telat > 7)
	{
		telat -= 7;
		denda = telat * 1000;	
		printf("\n\t Anda telat mengembalikan buku selama %d hari,  harap membayar sebesar Rp%d", telat, denda);
		printf("\n\t Masukkan jumlah uang : Rp");
		if (scanf("\t%d", &uang) != 1)
		{
			do
			{
				fflush(stdin);
				printf("\n\t Input Salah! Mohon masukkan angka.");
				printf("\n\t Masukkan jumlah uang : Rp");
				fflush(stdin);
			}
			while(scanf("\t%d", &uang) == 0);
		}
		kembalian = uang - denda;
		if (uang < denda)
		{
			do
			{
				printf("\n\t Jumlah uang kurang!");
				printf("\n\t Masukkan kembali jumlah uang : Rp");
				scanf("\t%d", &uang); fflush(stdin);
				kembalian = uang - denda;
			}
			while(uang < denda);
			if (uang > denda)
			{
				printf("\n\t Kembaliannya sebesar : Rp%d", kembalian);
			}
			printf("\n\t Terima Kasih sudah membayar");
			getch();
			dtpinjam = fopen("datapinjam.dat", "rb");
			hapusbuku(bukupj, pil);
			fclose(dtbuku);
			struk(kembali, nama, judul, tglpinjam, blnpinjam, thnpinjam);
			menuadm();
		}
		else if (uang > denda)
		{
			printf("\n\t Kembalian nya sebesar : Rp%d", kembalian);
			printf("\n\t Terima Kasih sudah membayar");
			getch();
			dtpinjam = fopen("datapinjam.dat", "rb");
			hapusbuku(bukupj, pil);
			fclose(dtbuku);
			struk(kembali, nama, judul, tglpinjam, blnpinjam, thnpinjam);
			menuadm();
		} 
		else if (uang == denda)
		{
			printf("\n\t Terima Kasih sudah membayar");
			getch();
			dtpinjam = fopen("datapinjam.dat", "rb");
			hapusbuku(bukupj, pil);
			fclose(dtbuku);
			struk(kembali, nama, judul, tglpinjam, blnpinjam, thnpinjam);
			menuadm();
		}
	}
	else if(telat <= 7)
	{
		printf("\n\tTerima Kasih sudah mengembalikan tepat waktu");
		getch();
		dtpinjam = fopen("datapinjam.dat", "rb");
		hapusbuku(bukupj, pil);
		fclose(dtbuku);
		struk(kembali, nama, judul, tglpinjam, blnpinjam, thnpinjam);
		menuadm();
	}
}

//=======================================================================  Prosedur pemanggilan struk  =============================================================================
void struk(data_tanggal tglk, char a[26], char b[26], int c, int d, int e){
	console_clear_screen();
	char buffer[100];
	if ((dtstruk=fopen("datastruk.dat",  "ab")) == NULL ){
		printf("File tidak dapat dibuat!\r\n");
		main();
	}   
	printf("\nNama Penyewa Buku    : %s\n\n", a);
    printf("-----------------------------------------------------------------------------------\n");
    printf("| TANGGAL PINJAM |   TANGGAL KEMBALI   |     NAMA     |  	JUDUL BUKU	  |\n");
    printf("-----------------------------------------------------------------------------------\n");
	
	sprintf(buffer, "   %d - %d - %d     %d - %d - %d     %13s   	%-20s    \n\n",d,c,e,tglk.bln,tglk.tgl,tglk.thn,a,b);
	fputs(buffer, dtstruk);
	fclose(dtstruk);
    printf(buffer);   
   	printf("Terima Kasih Telah Mengembalikan");
   	
   	
	getch();
	kembalikanbuku();
}

void daftarpj()
{
	console_clear_screen();
	char buffer[100];
	if ((dtstruk=fopen("datastruk.dat",  "rb")) == NULL ){
		printf("File tidak dapat dibuat!\r\n");
		main();
	}   
	
	printf("-----------------------------------------------------------------------------------\n");
    printf("| TANGGAL PINJAM |   TANGGAL KEMBALI   |     NAMA     |  	JUDUL BUKU	  |\n");
    printf("-----------------------------------------------------------------------------------\n");
    
    while(fgets(buffer, sizeof(buffer), dtstruk)){
        printf("%s", buffer);
    }
    getch();
    menuadm();
}

//======================================================================  Menu Daftar Buku  ========================================================================================

void menudaftar()
{
	int pil = 0;
	printf("\n========================================================================================================================\n");
	printf("|             					 [Menu Daftar Buku] 					          |\n");
	printf("========================================================================================================================\n\n");
	printf("\t 1. Urutkan\n");
	printf("\t 2. Kembali ke menu sebelumnya \n");
	printf("\n\t Pilihan	: ");
	scanf("%d", &pil); fflush(stdin);
	switch (pil)
		{
			case 1 : { 	menusort();

				break;
			default : { main();
			}
		}
	}
}

//====================================================================  Menu Sorting Buku  =========================================================================================
void menusort()
{
	int pil = 0;
	printf("\n\t 1. Kode Buku \n");
	printf("\t 2. Tahun Terbit Buku \n");
	printf("\t 3. Kembali ke menu sebelumnya \n");
	printf("\n\t Urutkan berdasarkan	: ");
	scanf("%d", &pil); fflush(stdin);
	switch (pil)
		{
			case 1 : { 	sortKode(buku);
						menudaftar();
				break;
			}
			case 2 : { sortTahun(buku);
				break;
			}
			case 3 : { menudaftar();
				break;
			}
			default : { menusort();
			}
		}
}


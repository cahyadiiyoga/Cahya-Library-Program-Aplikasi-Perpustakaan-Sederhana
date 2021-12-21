#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "fituradm.h"
#include "utama.h"
#define MAX_LEN 100 // Length of each line in input file.

//======================================================================= Prosedur Menginput Buku  =============================================================================
void Input_Buku(){
	system("cls");
	printf("\n========================================================================================================================\n");
	printf("|                                             	[Input Buku]     	     	                                     |\n");
	printf("========================================================================================================================\n");
	if ((dtbuku=fopen("daftarbuku.dat", "ab")) == NULL )
	{
		printf("File tidak dapat dibuat!\r\n");
		main();
	}
	
	do {
		printf("Kode buku : "); fflush(stdin);
		scanf("%d", &buku.kode);
		printf("Judul buku : "); fflush(stdin);
		gets(buku.judul);
		printf("Jenis buku : "); fflush(stdin);
		gets(buku.jenis);
		printf("Genre buku : "); fflush(stdin);
		gets(buku.genre);
		printf("Kategori Umur : "); fflush(stdin);
		gets(buku.umur);
		printf("Nama pengarang : "); fflush(stdin);
		gets(buku.pengarang);
		printf("Tahun Terbit : "); fflush(stdin);
		scanf("%d", &buku.tahun);
		
		/* Rekam sebuah data bertipe record menggunakan fungsi fwrite */
		fwrite(&buku, sizeof(buku), 1, dtbuku);
		
		printf("\r\nMemasukkan data lagi (Y/T)?"); fflush(stdin);
		jawab = toupper(getche());		/* Baca jawaban dari keyboard */
	}
	while (jawab == 'Y');
	fclose(dtbuku);		/* Tutup file */
	
	printf("\r\nData sudah disimpan pada file.\r\n");
	printf("\r\nLihat isi file (Y/T)?"); fflush(stdin);
	jawab = toupper(getche());			/* Baca jawaban dari keyboard */
	if (jawab == 'Y');
	{	Tampil_File();
	}
	
	menuadm();
}

//======================================================================= Prosedur Menampilkan File  ===========================================================================
void Tampil_File(){
	console_clear_screen();
	printf("========================================================================================================================\n\n");
	printf("\t\t\t\t\t\tD A F T A R  B U K U\n\n");
	printf("========================================================================================================================\n");
	printf("| Kode |        Judul Buku       | Jenis Buku  |     Genre         | Umur     |   	 Pengarang  	 | Tahun Terbit|\n");
	/* Buka file untuk dibaca isinya */
	if ((dtbuku=fopen("daftarbuku.dat", "rt")) == NULL )
		{
			printf("File tidak dapat dibuka!\r\n");
			exit(1);
		}
	printf("\n");
		/* Ambil isi file ngenggunakan fungsi fread(), lalu tampilkan ke layar */
	while ((fread(&buku, sizeof(buku), JUM_BLOK, dtbuku)) == JUM_BLOK )
	printf("  %d\t %-26s %-16s %-16s %-3s\t %-16s       	%4d\n", buku.kode, buku.judul, buku.jenis, buku.genre, buku.umur, buku.pengarang, buku.tahun);
	fclose(dtbuku);		/* Tutup file */
	
}

//=================================================================  Prosedur untuk mengambil tanggal sekarang  =================================================================
void Tanggal(){
    struct tm *Sys_T;
 
    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval); /* Untuk mendapatkan waktu lokal komputer */
    /* Sys_T = gmtime(&Tval); */ /* Untuk mendapatkan waktu komputer berbasis GMT/UTC */
 	
    printf("\t Tanggal	= %d", Sys_T->tm_mday);
    printf("\n\t Bulan		= %d", Sys_T->tm_mon+1); /* Ditambah 1 karena Januari dimulai dari 0 */
    printf("\n\t Tahun		= %d", 1900+Sys_T->tm_year); /* Ditambah 1900, karena tahun dimulai dari 1900 */
}


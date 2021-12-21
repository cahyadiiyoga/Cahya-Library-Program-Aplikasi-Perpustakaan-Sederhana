#ifndef utama_H
#define utama_H

// Deklarasi Variabel
#define JUM_BLOK 1		/* sebuah record */
FILE *dtbuku;

typedef struct{
		int kode;
		char judul[26];
		char jenis[30];
		char genre[30];
		char umur[3];
		char pengarang[30];
		int tahun;
	}data_buku;

data_buku buku;

char jawab;
// Fungsi Input Buku
void Input_Buku();

// Fungsi Baca Daftar Buku
void Tampil_File();

// Prosedur Baca Status Peminjaman
void Tampil_Pinjam();

#endif

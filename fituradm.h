#ifndef fituradm_H
#define fituradm_H

char jawab;

FILE *dtpinjam;
FILE *dtstruk;

struct login
{
    char username[20];
    char password[20];
};

// Struct Tanggal
typedef struct{
	int tgl;
	int bln;
	int thn;
}data_tanggal;

// Struct Buku
typedef struct {
	int nomor;
	char nama[26];
	int kode;
	char judul[30];
	data_tanggal tgl_pinjam;
}buku_pinjam;
buku_pinjam bukupj;

// Fitur Login
void login();

// Menu Admin
void menuadm();

// Menu Pinjam dan Kembalikan Buku
void menupinjam();

// Pinjam Buku
void pinjam();

// Kembalikan Buku
void kembalikanbuku();
void kembalikan();
void kembalikanbuku1();

// Menu Daftar Buku
void menudaftar();

// Sorting buku
void menusort();

void statuspjm();

// Prosedur pemanggilan struk
void struk(data_tanggal tglk, char a[26], char b[26], int c, int d, int e);

void daftarpj();

// Menu Hapus
void menuhapus();
void hapus1();
void hapus2();

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

//--------------------------------------------------------------------------------------------------------------------------------
char file_name[] = "list_data.txt";
char delim[] = ";";
char data_barang[200][3][200];
int jml_data_barang = 0;
char username[20], password[20];
//--------------------------------------------------------------------------------------------------------------------------------

char *substring(char *string, int position, int length) {
   	char *pointer;
   	int c;
 
   	pointer = malloc(length+1);
   
   	if (pointer == NULL) {
      	printf(" Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
   	}
   	for (c = 0 ; c < length ; c++) {
      	*(pointer+c) = *(string+position-1);      
      	string++;  
   	}
 
   	*(pointer+c) = '\0';
 
   	return pointer;
}
//--------------------------------------------------------------------------------------------------------------------------------

void getData() {
	FILE *fp = fopen(file_name, "r");
    char line[200];
	
	memset(data_barang,0,sizeof(data_barang));
    jml_data_barang = 0;  
	   
	if (fp == NULL) {
		printf("Gagal membuka file %s", file_name);
		exit(EXIT_FAILURE);
	} else {
		int i = 0;
		while (fgets(line, sizeof(line), fp) != NULL) {
			char *token = strtok(line, delim);
    		
    		int j = 0;
			while (token != NULL) {
				strcpy(data_barang[i][j], token);
				token = strtok(NULL, delim);
				j++;
			}
			
			i++;
			jml_data_barang++;
		}
	}
	fclose(fp);
}
//--------------------------------------------------------------------------------------------------------------------------------

void viewData() {
    getData();
    system("@cls||clear");
    printf("============================================\n");
   	printf(" Menu Lihat Data Onderdil\n");
   	printf("============================================\n");
    if (jml_data_barang > 0) {
        printf(" Nama Onderdil\t\tHarga\tStok\n");
   		printf("============================================\n");
        int i;
		for (i = 0; i < jml_data_barang; i++) {
			char nama_brg[100];
			strcpy(nama_brg, data_barang[i][0]);
			if (strlen(nama_brg) > 10) {	//jika lebih dari 15 
		   		strcpy(nama_brg, substring(nama_brg, 1, 12));
			} else if (strlen(nama_brg) < 8) {
		   		snprintf(nama_brg, sizeof nama_brg, "%s%s", data_barang[i][0], "");
			}
            int harga_brg = atoi(data_barang[i][1]);
            int stok_brg = atoi(data_barang[i][2]);

            printf("%i. %s\t\t%d\t%d \n",i+1,nama_brg,harga_brg,stok_brg);
        }
    } else {
        printf("Tidak ada data barang!\n");
    }
    printf("============================================\n ");
    system("pause");
    menu_utama();
}
//--------------------------------------------------------------------------------------------------------------------------------

bool addToFile(char inputan[]) {
	FILE *fp = fopen(file_name,"a+");
	if (fp == NULL) {
		return false;
	} else {
		fputs(inputan, fp);
	}
	fclose(fp);
	return true;
}
//--------------------------------------------------------------------------------------------------------------------------------

void tambahData() {
	scanf("%c");
	system("@cls||clear");
	printf("============================================\n");
   	printf(" Menu Tambah Data Onderdil\n");
   	printf("============================================\n");
   	
   	char nama[100], harga[50], stok[50], hasil[200];
   	
	printf(" Masukkan Nama Onderdil : ");
   	gets(nama);
   	if (strlen(nama) > 15) {
   		strcpy(nama, substring(nama, 1, 15));
	}
	
   	printf(" Masukkan Harga Onderdil : ");
   	gets(harga);
   	int hargaa = atoi(harga);
   	if (hargaa < 1000) hargaa = 1000;
   	else if (hargaa > 9999999) hargaa = 9999999;
   	
   	printf(" Masukkan Stok Onderdil : ");
   	gets(stok);
   	int stokk = atoi(stok);
   	if (stokk < 1) stokk = 1;
   	else if (stokk > 10000) stokk = 10000;
   	
   	printf("============================================\n");
	snprintf(hasil, sizeof hasil, "%s;%d;%d;\n", nama, hargaa, stokk);
	if (addToFile(hasil)) {
		printf(" Sukses tambah data barang!\n");
	} else {
		printf(" Gagal tambah data barang!\n");
	}
	printf("============================================\n");
	system("pause");
    menu_utama();
}
//--------------------------------------------------------------------------------------------------------------------------------

void hapusData() {
	scanf("%c");
	system("@cls||clear");
	printf("============================================\n");
   	printf(" Menu Hapus Data Onderdil\n");
   	printf("============================================\n");
   	char nama[100];
   	printf(" Masukkan Nama Onderdil : ");
   	gets(nama);
	if (jml_data_barang > 0) {
		FILE *fp = fopen(file_name, "r");
	    char line[200];
		if (fp == NULL) {
			printf(" Gagal membuka file %s", file_name);
			exit(EXIT_FAILURE);
		} else {
			bool ada = false, ada2 = false;
			int i = 0, j = 0, k = 0;
			char tampung[100][200];
			while (fgets(line, sizeof(line), fp) != NULL) {
				char *token = strtok(line, delim);
	    		j = 0;
				ada = false;
				while (token != NULL) {
					if (j == 0) {
						if (strcmp(data_barang[i][j],nama) == 0) {
							ada = true;
							ada2 = true; //memastikan jika ketemu
						}
					}
					token = strtok(NULL, delim);
					j++;
				}
				
				if (!ada) {
					//data barang yg bukan dihapus akan ditampung di array tampung
					snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;\n", data_barang[i][0], data_barang[i][1], data_barang[i][2]);
					k++;
				}
				
				i++;
			}
			
			fclose(fp);
			
			printf("============================================\n");
			if (ada2) {
				fp = fopen(file_name, "w"); //reset file jadi kosong
				fclose(fp);
				if (k > 0) {
					for (i = 0; i < k; i++) {
						addToFile(tampung[i]);
					}	
				}
				printf(" Sukses hapus (%s) dari data barang!\n",nama);
			} else {
				printf(" Nama barang (%s) tidak ditemukan!\n",nama);
			}
		}
   	} else {
   		printf("============================================\n");
   		printf(" Tidak ada data barang!\n");
    }
    
    printf("============================================\n ");
    system("pause");
    menu_utama();
}
//--------------------------------------------------------------------------------------------------------------------------------

void transaksi(){
	struct tm *Sys_T;
 
    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);
	
    getData();
    system("@cls||clear");
    printf ("\n   Menu Transaksi   %s", asctime (Sys_T));
   	printf(" ============================================\n");
    if (jml_data_barang > 0) {
        printf("  Nama Onderdil\t\tHarga\n");
   		printf(" ============================================\n");
        int i;
		for (i = 0; i < jml_data_barang; i++) {
			char nama_brg[100];
			strcpy(nama_brg, data_barang[i][0]);
			if (strlen(nama_brg) > 10) {
		   		strcpy(nama_brg, substring(nama_brg, 1, 12));
			} else if (strlen(nama_brg) < 8) {
		   		snprintf(nama_brg, sizeof nama_brg, "%s%s", data_barang[i][0], "");
			}
            int harga_brg = atoi(data_barang[i][1]);
            int stok_brg = atoi(data_barang[i][2]);

            printf("%i. %s\t\t%d\t \n",i+1,nama_brg,harga_brg);
        }
    } else {
        printf(" Tidak ada data barang!\n");
    }
    printf(" ============================================\n");
	nota();
}
//--------------------------------------------------------------------------------------------------------------------------------

void nota(){
	getData();
	char nama_brg[100];
	char total_harga, plh;
	int i, a;
	int totalpembelian = 0;
	int bayar;
	int jml_pesan[200][200], stok_akhir[100];
	
	FILE     *fp;
    char     *fmode, filename[255], strtime_sec[20], strtime_nsec[20];	
    struct   tm* tm;
    struct   timespec ts;
    time_t   now;

    now = time(NULL);
    tm  = localtime(&now);

    sprintf(filename, "%04d-%02d-%02d %02d.%02d.txt", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min);
    fmode = "a";
    fp = fopen(filename, fmode);
//--------------------------------------------------------------------------------------------------------------------------------
	fprintf(fp, "\n\t     Toko Onderdil\n");
	fprintf(fp, "\t   Ivan Classic Shop\n");
	fprintf(fp, "     Jl. Sl3-Bringin KM 4 Tuntang \n");	
	fprintf(fp, "========================================\n");	
	fprintf(fp, " Nama Barang\t  Qyt\tHarga\tTotal\n");
	fprintf(fp, "========================================");
	do{
		sebelum_stok:
    	printf(" Pesan barang nomor: ");	
		scanf("%i", &i);
		if(i == 999){
			goto totalan;
		}
		else{
		i=i-1;
		strcpy(nama_brg, data_barang[i][0]);
			printf(" Jumlah barang: ");
				scanf("%i", &jml_pesan[a][0]);
			if(atoi(data_barang[i][2]) < 0 || jml_pesan[a][0] > atoi(data_barang[i][2])){
				printf(" stok habis !!\n\n");
				goto sebelum_stok;
				}
			else{
			printf(" Pesan barang : %s\n", nama_brg);
			printf(" Stok barang : %d\n\n", atoi(data_barang[i][2])-jml_pesan[a][0]);

		strcpy(nama_brg, data_barang[i][0]);
		int harga_brg = atoi(data_barang[i][1]);
			fprintf(fp, "\n%s\t   %d\t%d\t%d", nama_brg, jml_pesan[a][0], harga_brg, atoi(data_barang[i][1])*jml_pesan[a][0]);
		totalpembelian = totalpembelian + (atoi(data_barang[i][1])*jml_pesan[a][0]);
		stok_akhir[i] = atoi(data_barang[i][2])-jml_pesan[a][0];
			i++;
			a++;
			}
		}
	}	while(1);
		
	totalan:
		printf(" Total : %i\n", totalpembelian);
	pembayaran:
		printf(" Tunai : ");
			scanf("%i", &bayar);
			if(bayar < totalpembelian){
				printf(" Jumlah uang tunai yang anda masukkan kurang, silakan isi kembali\n\n");
				goto pembayaran;
			}
		printf(" Kembali : %i", bayar-totalpembelian);
		fprintf(fp, "\n=========================================");
		fprintf(fp, "\n\t\tTotal      : Rp %i", totalpembelian);
		fprintf(fp, "\n\t\tTunai      : Rp %i", bayar);
		fprintf(fp, "\n\t\tKembali    : Rp %i", bayar-totalpembelian);
		fprintf(fp, "\n=========================================");		
		fprintf(fp, "\n Opr : %s\t\tID: %04d%02d%02d%02d%02d", username, tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min);
		fprintf(fp, "\n=========================================");	
		fprintf(fp, "\n Pesan Barang (Online): 0895391703636");
		fprintf(fp, "\n      Terima Kasih Telah Berbelanja");
			
		printf("\n Sukses membuat nota %s \n", filename);
		
//--------------------------------------------------------------------------------------------------------------------------------
	fp = fopen(file_name, "w");	// menghapus
	for(i = 0 ;i < jml_data_barang; i++){
    		int harga_brg = atoi(data_barang[i][1]);
    		int stok_brg = atoi(data_barang[i][2]);
    if(stok_akhir[i] == 0){	//jika kondisi stok akhir == 0, cetak stok barang awal
    	fprintf(fp, "%s;%d;%d;\n",  data_barang[i][0], harga_brg, stok_brg);
		}
	else{		//jika kondisi stok akhir != 0, cetak stok barang akhir
		fprintf(fp, "%s;%d;%d;\n",  data_barang[i][0], harga_brg, stok_akhir[i]);
		}
	}
	system("pause");
	menu_utama();
}
//--------------------------------------------------------------------------------------------------------------------------------

void login() {system("color 03");
	int i;
	
	printf("\n\n ");
	for(i = 0; i <= 38; i++){
		printf("|", i);
		Sleep(10);
	}

	for(i = 0; i <= 5; i++){
		//--------------------ANIMASI--------------------//
			system("cls");
		printf("\n\n ||||||||||||||||||||||||||||||||||||||| ", i);
			Sleep(50);
			system("cls");
		printf("\n\n ||||||||||||||||||||||||||||||||||||||||| ", i);
			Sleep(50);
			system("cls");
		printf("\n\n ||||||||||||||||||||||||||||||||||||||||||| ", i);
			Sleep(100);
	}
	login_in:
			system("cls");
			Sleep(5);
		printf("\n ================= WELCOME =================\n");
		printf(" |||||||||||||||| L O G I N |||||||||||||||| \n\n");
			Sleep(1000);
		printf("   Username : ");
		gets(username);
		printf("   Password : ");
		gets(password);
	
	if (strcmp(username,"Ivan") == 0 && strcmp(password,"fira") == 0) {
		printf("   Selamat Datang %s!\n",username);
		scanf("%c");
		menu_utama();
	}else{
		system("cls");
		printf("\n\n ");
		//--------------------ANIMASI--------------------//
		for(i = 0; i <= 5; i++){
		system("cls");
		printf("\n\n ||||||||||||||||||||||||||||||||||| ", i);
			Sleep(50);
		system("cls");
		printf("\n\n ||||||||||||||||||||||||||||||||||||| ", i);
			Sleep(50);
		system("cls");
		printf("\n\n ||||||||||||||||||||||||||||||||||||||| ", i);
			Sleep(100);
			}
		printf("\n\t\t\tAKSES DITOLAK !!\n");
			scanf("%c");
		
		system("cls");
		goto login_in;
	}
	
}
//--------------------------------------------------------------------------------------------------------------------------------

void menu_utama() {system("color 03");
void menu(int pil) {
	if (pil == 1) viewData();
	else if (pil == 2) tambahData();
	else if (pil == 3) hapusData();
	else if (pil == 4) transaksi();
	else if (pil == 5) login();
}

	int pilihan = 0;
	struct tm *Sys_T;
 
    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);
    
	while (pilihan == 0) {
		system("@cls||clear");
		printf("\n\t\t     %s\n", asctime (Sys_T));
		printf(" Selamat Datang, %s !\n", username);
		printf(" ============================================\n");
		printf(" |  \t\tMENU UTAMA                  |\n");
		printf(" ============================================\n");
		printf(" 1. Lihat Data Onderdil\n");
		printf(" 2. Tambah Data Onderdil\n");
		printf(" 3. Hapus Data Onderdil\n");
		printf(" 4. Transaksi\n");
		printf(" 5. Logout\n");
		printf(" 6. Exit\n");
		printf(" Pilih Menu : ");
		scanf("%d",&pilihan);
		if (pilihan <= 0 || pilihan > 6) {
			pilihan = 0;
			system("@cls||clear");
			printf(" Pilihan Menu Salah!\n");
			system("pause");
		}
	}
	
	if (pilihan == 5) login();
	else if (pilihan == 6) exit(EXIT_SUCCESS);
	else menu(pilihan);
}
//--------------------------------------------------------------------------------------------------------------------------------

void main() {
	getData();
	login();
}


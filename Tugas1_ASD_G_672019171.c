#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// Tugas1_ASD_G_672019171
// Ivan Andika Surya (672019171)
// 17 Februari 2021

struct data {
	// Struct
	char name[50];
	int nim;
	int ipk;
	};
	
void main() {
	// Main
	int i, j, save1, save2;
	int pilih = 0, jml = 3;
	int identifier = 0;
	struct data arr_data[jml];
	char *temp = (char *)malloc((strlen(arr_data[i].name) + 1) * sizeof(char));
	
	menu: 
	system("cls");
	printf(" ----------------------------------------\n");
	printf(" ================= MENU =================\n");
	printf(" ----------------------------------------\n\n");
	printf(" 1. Input Data\n");
	printf(" 2. Lihat Data Terkini\n");
	printf(" 3. Sorting Data\n");
	printf(" 4. Search Data\n");
	printf(" 5. Keluar\n");
	printf(" Silakan masukkan pilihan anda : ");
	scanf("%d", &pilih);
	switch (pilih) {
		case 1: {
			// Input Data
			system("cls");
			printf(" ----------------------------------------\n");
			printf(" ============== INPUT DATA ==============\n");
			printf(" ----------------------------------------\n\n");
			for (i = 0; i < jml; i++) {
				printf(" Masukkan data mahasiswa ke %d\n", i+1);
				printf(" Masukkan Nama\t: ");
				fflush(stdin);
				gets(arr_data[i].name);
				printf(" Masukkan NIM\t: ");
				scanf("%d", &arr_data[i].nim);
				ulang:
				printf(" Masukkan IPK\t: ");
				scanf("%d", &arr_data[i].ipk);
				if(arr_data[i].ipk <= 0 || arr_data[i].ipk > 4) {
					printf(" IPK yang anda masukkan belum valid. (0-4)\n\n ");
					system("pause");
					goto ulang;
				}
				printf("\n");
			}
			printf(" Data berhasil di input.");
			identifier = 1;
			printf("\n\n ");
			system("pause");
			system("cls");
			goto menu;
		}
		case 2: {
			// Lihat Data Terkini
			if (identifier == 0) {
				printf("\n Anda belum memasukkan data!\n\n ");
				system("pause");
				system("cls");
				goto menu;
			} else if (identifier == 1) {
				for (i = 0; i < jml; i++) {
					printf("\n Nama\t: %s\n NIM\t: %d\n IPK\t: %d", arr_data[i].name, arr_data[i].nim, arr_data[i].ipk);
					printf("\n");
				}
				printf("\n ");
				system("pause");
				system("cls");
				goto menu;
			}
		}
		case 3: {
			// Sort menggunakan Selection Sort
			int sort = 0;
			if (identifier == 0) {
				printf("\n Anda belum memasukkan data!\n\n ");
				system("pause");
				system("cls");
				goto menu;
			} else if (identifier == 1) {
				system("cls");
				printf(" ----------------------------------------\n");
				printf(" ================= SORT =================\n");
				printf(" ----------------------------------------\n\n");
				printf(" 1. Sort berdasarkan Abjad\n");
				printf(" 2. Sort berdasarkan NIM\n");
				printf(" 3. Sort berdasarkan IPK\n");
				printf(" 4. Kembali ke menu utama\n");
				printf(" Silakan masukkan pilihan anda : ");
				scanf("%d", &sort);
				switch (sort) {
					case 1: {
						// Sorting Abjad pertama dari arr_data[i].name
						for (i = 0; i < jml-1; i++) {
							for (j = i; j < jml; j++) {
								if (strcmp(arr_data[i].name, arr_data[j].name) > 0) {
									save1 = arr_data[i].nim;
									save2 = arr_data[i].ipk;
									arr_data[i].nim = arr_data[j].nim;
									arr_data[i].ipk = arr_data[j].ipk;
									arr_data[j].nim = save1;
									arr_data[j].ipk = save2;
									strcpy(temp, arr_data[i].name);
									strcpy(arr_data[i].name, arr_data[j].name);
									strcpy(arr_data[j].name, temp);
								}
							}
						}
						printf("\n Data setelah sorting Abjad adalah :\n");
						for (i = 0; i < jml; i++) {
							printf(" Nama\t: %s\n NIM\t: %d\n IPK\t: %d", arr_data[i].name, arr_data[i].nim, arr_data[i].ipk);
							printf("\n\n");
						}
						printf(" ");
						system("pause");
						system("cls");
						goto menu;
					}
					case 2: {
						// Sorting NIM
						for (i = 0; i < jml-1; i++) {
							for (j = i; j < jml; j++) {
								if (arr_data[i].nim > arr_data[j].nim) {
									save1 = arr_data[i].nim;
									save2 = arr_data[i].ipk;
									arr_data[i].nim = arr_data[j].nim;
									arr_data[i].ipk = arr_data[j].ipk;
									arr_data[j].nim = save1;
									arr_data[j].ipk = save2;
									strcpy(temp, arr_data[i].name);
									strcpy(arr_data[i].name, arr_data[j].name);
									strcpy(arr_data[j].name, temp);
								}
							}
						}
						printf("\n Data setelah sorting NIM adalah :\n");
						for (i = 0; i < jml; i++) {
							printf(" Nama\t: %s\n NIM\t: %d\n IPK\t: %d", arr_data[i].name, arr_data[i].nim, arr_data[i].ipk);
							printf("\n\n");
						}
						printf(" ");
						system("pause");
						system("cls");
						goto menu;
					}
					case 3: {
						// Sorting IPK
						for (i = 0; i < jml-1; i++) {
							for (j = i; j < jml; j++) {
								if (arr_data[i].ipk > arr_data[j].ipk) {
									save1 = arr_data[i].nim;
									save2 = arr_data[i].ipk;
									arr_data[i].nim = arr_data[j].nim;
									arr_data[i].ipk = arr_data[j].ipk;
									arr_data[j].nim = save1;
									arr_data[j].ipk = save2;
									strcpy(temp, arr_data[i].name);
									strcpy(arr_data[i].name, arr_data[j].name);
									strcpy(arr_data[j].name, temp);
								}
							}
						}
						printf("\n Data setelah sorting IPK adalah :\n");
						for (i = 0; i < jml; i++) {
							printf(" Nama\t: %s\n NIM\t: %d\n IPK\t: %d", arr_data[i].name, arr_data[i].nim, arr_data[i].ipk);
							printf("\n\n");
						}
						printf(" ");
						system("pause");
						system("cls");
						goto menu;
					}
					case 4: {
						system("cls");
						goto menu;
					}
					default: {
						printf(" Oops coba lagi! Masukkan nomor menu dengan benar.\n\n ");
						system("pause");
						goto menu;
					}
				}
			}
		}
		case 4: {
			// Search menggunakan Squential Search
			int searchnim, searchipk, search = 0;
			char searchname[50];
			
			// mengubah data pointer menjadi char
			char *tempname1 = (char *)malloc((strlen(arr_data[i].name) + 1) * sizeof(char));
			char *tempname2 = (char *)malloc((strlen(arr_data[i].name) + 1) * sizeof(char));
			char *tempname3 = (char *)malloc((strlen(arr_data[i].name) + 1) * sizeof(char));
			strcpy(tempname1, arr_data[0].name);
			strcpy(tempname2, arr_data[1].name);
			strcpy(tempname3, arr_data[2].name);
			
			if (identifier == 0) {
				printf("\n Anda belum memasukkan data!\n\n ");
				system("pause");
				system("cls");
				goto menu;
			} else if (identifier == 1) {
				system("cls");
				printf(" ----------------------------------------\n");
				printf(" ================ SEARCH ================\n");
				printf(" ----------------------------------------\n\n");
				printf(" 1. Search dengan Nama\n");
				printf(" 2. Search dengan NIM\n");
				printf(" 3. Search dengan IPK\n");
				printf(" 4. Kembali ke menu utama\n");
				printf(" Silakan masukkan pilihan anda : ");
				scanf("%d", &search);
				switch (search) {
					case 1: {
						printf("\n List Nama yang ada dalam data : \n");
						printf(" > %s\n", tempname1);
						printf(" > %s\n", tempname2);
						printf(" > %s\n", tempname3);
						searchlagi1:
						printf("\n Silakan masukkan Nama yang dicari : ");
						fflush(stdin);
						gets(searchname);
						if (strcmp(tempname1, searchname) == 0) {
							printf("\n Data yang anda cari adalah sebagai berikut.\n");
							printf(" Nama\t: %s\n NIM\t: %d\n IPK\t: %d\n\n ", arr_data[0].name, arr_data[0].nim, arr_data[0].ipk);
							system("pause");
							goto menu;
						} else if (strcmp(tempname2, searchname) == 0) {
							printf("\n Data yang anda cari adalah sebagai berikut.\n");
							printf(" Nama\t: %s\n NIM\t: %d\n IPK\t: %d\n\n ", arr_data[1].name, arr_data[1].nim, arr_data[1].ipk);
							system("pause");
							goto menu;
						} else if (strcmp(tempname3, searchname) == 0) {
							printf("\n Data yang anda cari adalah sebagai berikut.\n");
							printf(" Nama\t: %s\n NIM\t: %d\n IPK\t: %d\n\n ", arr_data[2].name, arr_data[2].nim, arr_data[2].ipk);
							system("pause");
							goto menu;
						} else {
							printf("\n Nama yang anda cari tidak ada dalam data.\n Silakan coba lagi dan tulis nama dengan lengkap.\n ");
							goto searchlagi1;
						}
					}
					case 2: {
						printf("\n List NIM yang ada dalam data : \n");
						for (i = 0; i < jml; i++) {
							printf(" - %d\n", arr_data[i].nim);
						}
						searchlagi2:
						printf("\n Silakan masukkan NIM yang dicari : ");
						scanf("%d", &searchnim);
						for (i = 0; i < jml; i++) {
							if (arr_data[i].nim == searchnim) {
								printf("\n Data yang anda cari adalah sebagai berikut.\n");
								printf(" Nama\t: %s\n NIM\t: %d\n IPK\t: %d\n\n ", arr_data[i].name, arr_data[i].nim, arr_data[i].ipk);
								system("pause");
								goto menu;
							}
						}
						if (arr_data[i].nim != searchnim) {
							printf("\n NIM yang anda cari tidak ada dalam data.\n Silakan coba lagi.\n ");
							goto searchlagi2;
						}
					}
					case 3: {
						printf("\n List IPK yang ada dalam data : \n");
						for (i = 0; i < jml; i++) {
							printf(" > %d\n", arr_data[i].ipk);
						}
						searchlagi3:
						printf("\n Silakan masukkan IPK yang dicari : ");
						scanf("%d", &searchipk);
						for (i = 0; i < jml; i++) {
							if (arr_data[i].ipk == searchipk) {
								printf("\n Data yang anda cari adalah sebagai berikut.\n");
								printf(" Nama\t: %s\n NIM\t: %d\n IPK\t: %d\n\n ", arr_data[i].name, arr_data[i].nim, arr_data[i].ipk);
								system("pause");
								goto menu;
							}
						}
						if (arr_data[i].ipk != searchipk) {
							printf("\n IPK yang anda cari tidak ada dalam data.\n Silakan coba lagi.\n ");
							goto searchlagi3;
						}
					}
					case 4: {
						system("cls");
						goto menu;
					}
					default: {
						printf(" Oops coba lagi! Masukkan nomor menu dengan benar.\n\n ");
						system("pause");
						goto menu;
					}
				}
			}
		}
		case 5: {
			printf("\n Byebye!\n ");
			printf("Ivan Andika Surya, 2021\n");
			exit(EXIT_SUCCESS);
		}
		default: {
			printf(" Oops coba lagi! Masukkan nomor menu dengan benar.\n\n ");
			system("pause");
			goto menu;
		}
	}
}

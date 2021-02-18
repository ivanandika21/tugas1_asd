#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct data{
    char* name[30];
    int nim;
    int ipk;
    };
    
void main(){
	pilihmenu();
}

void menu_utama(){
	void pilihmenu(int pilih){
		if (pilih == 1) inputdata();
		else if (pilih == 2) lihatdata();
		else if (pilih == 3) sortdata();
		else if (pilih == 4) searchdata();
		}
		
	int pilih = 0;
	while (pilih == 0) {
	printf(" ========================================\n");
		printf(" ==================MENU==================\n");
		printf(" ========================================\n");
		printf(" 1. Input Data\n");
		printf(" 2. Lihat Data\n");
		printf(" 3. Sorting Data\n");
		printf(" 4. Search Data\n");
		printf(" Silakan masukkan pilihan anda : ");
		scanf("%d", &pilih);
		if (pilih <= 0 || pilih > 4) {
			pilih = 0;
			system("cls");
			printf(" Pilihan Menu Salah!\n");
			system("pause");
		}
		else pilihmenu(pilih);
	}
}

void inputdata(){
	
}


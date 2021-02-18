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
	int i, j;
	int save2, save3;
    int jml = 2, pilih = 0;
	
	struct data data_temp[jml];
	char *temp = (char *)malloc((strlen(data_temp[i].name) + 1) * sizeof(char));
	
	if (pilih == 1){
		system("cls");
    	for(i = 0; i < jml; i++){
        	printf("Masukkan data mahasiswa ke %d\n", i+1);
        	printf("Masukkan nama\t: ");
            	fflush(stdin);
            	gets(&data_temp[i].name);
        	printf("Masukkan nim\t: ");
        	scanf("%d", &data_temp[i].nim);
        	printf("Masukkan ipk\t: ");
        	scanf("%d", &data_temp[i].ipk);
        	printf("\n");
        	}
    	system("pause");
    	system("cls");
    	main();
		}
	else if (pilih == 2){
		system("cls");
		for(i = 0; i < jml; i++){
        	printf("Nama\t: %s\nNIM\t: %d\nNilai\t: %d", data_temp[i].name, data_temp[i].nim, data_temp[i].ipk);
        	printf("\n\n");
        	}
    	system("pause");
    	system("cls");
    	main();
	}
	else if (pilih == 3){
		//sorting ipk
    for (i = 0; i < jml-1; i++){
        for (j = i; j < jml; j++){
            if (data_temp[i].ipk > data_temp[j].ipk){
                save2 = data_temp[i].nim;
                save3 = data_temp[i].ipk;

                data_temp[i].nim = data_temp[j].nim;
                data_temp[i].ipk = data_temp[j].ipk;

                data_temp[j].nim = save2;
                data_temp[j].ipk = save3;

                strcpy(temp, data_temp[i].name);
                strcpy(data_temp[i].name, data_temp[j].name);
                strcpy(data_temp[j].name, temp);
            }
        }
    }
	
	printf("Data setelah sorting adalah :\n");
    for(i = 0; i < jml; i++){
        printf("Nama\t: %s\nNIM\t: %d\nNilai\t: %d", data_temp[i].name, data_temp[i].nim, data_temp[i].ipk);
        printf("\n\n");
		}
	}
	else if (pilih == 4);
}

void menu(int pilih){
	
}

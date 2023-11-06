//
//  sten, saks, papir.c
//  Programering
//
//  Created by Magnus Nielsen on 06/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    
    srand(time(0));
    int aflustspil = 0;
    
    //    0="sten"
    //    1="saks"
    //    2="papir"
    while (aflustspil == 0) {
        int cvalg = rand() % 3;
        
        
        int valg;
        printf("Velkomen til sten, saks, papir\n");
        printf("0: Sten\n");
        printf("1: Saks\n");
        printf("2: Papir\n");
        printf("Valg: ");
        scanf("%d", &valg);
        
        switch(valg) {
            case 0:
                printf("Du valgte Sten\n");
                break;
            case 1:
                printf("Du valgte Saks\n");
                break;
            case 2:
                printf("Du valgte Papir\n");
                break;
        }
        
        if (valg >= 0 && valg <= 2) {
            switch (cvalg) {
                case 0:
                    printf("Computeren valgte Sten\n");
                    break;
                case 1:
                    printf("Computeren valgte Saks\n");
                    break;
                case 2:
                    printf("Computeren valgte Papir\n");
                    break;
            }
        }
        
        
        if (valg == cvalg) {
            printf("Uafgjort\n");
        } else if(valg == 0 && cvalg == 1) {
            printf("Du vandt\n");
        } else if (valg == 1 && cvalg == 2){
            printf("Du vandt\n");
        } else if (valg == 2 && cvalg == 0){
            printf("Du vandt\n");
        } else if (valg > 2) {
            printf("Ugyldigt valg\n");
        } else {
            printf("Du vandt\n");
        }
        
        
        printf("0: spil igen\n");
        printf("1: aflsut\n");
        scanf("%d", &aflustspil);
        
        if (aflustspil == 0) {
            printf("Spiller igen\n");
        } else {
            printf("Afslutter...\n");
        }
    }
}

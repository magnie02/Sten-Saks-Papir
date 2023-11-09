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
    int uafgjorte = 0;
    int vundet = 0;
    int tabte = 0;
    
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
                printf("\nDu valgte Sten\n");
                break;
            case 1:
                printf("\nDu valgte Saks\n");
                break;
            case 2:
                printf("\nDu valgte Papir\n");
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
            printf("\nResultat: \n");
            printf("Uafgjort\n");
            uafgjorte ++;
        } else if(valg == 0 && cvalg == 1) {
            printf("\nResultat: \n");
            printf("Du vandt\n");
            vundet ++;
        } else if (valg == 1 && cvalg == 2){
            printf("\nResultat: \n");
            printf("Du vandt\n");
            vundet ++;
        } else if (valg == 2 && cvalg == 0){
            printf("\nResultat: \n");
            printf("Du vandt\n");
            vundet ++;
        } else if (valg > 2) {
            printf("\nResultat: \n");
            printf("Ugyldigt valg\n");
        } else {
            printf("\nResultat: \n");
            printf("Du tabte\n");
            tabte ++;
        }
        
        
        printf("\n0: spil igen\n");
        printf("1: tjek score\n");
        printf("2: aflust spil\n");
        printf("valg: ");
        scanf("%d", &aflustspil);
        
        if (aflustspil == 0) {
            printf("Spiller igen\n");
        } else if (aflustspil == 1) {
            printf("\nAntal uafgjorte: %d\n", uafgjorte);
            printf("antal vundet: %d\n", vundet);
            printf("Antal tabte: %d\n\n", tabte);
            aflustspil = 0;
        } else {
            printf("Afslutter...\n");
            printf("\nAntal uafgjorte: %d\n", uafgjorte);
            printf("antal vundet: %d\n", vundet);
            printf("Antal tabte: %d\n", tabte);
        }
    }
}

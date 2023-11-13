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
    
    srand(time(NULL));
    int aflustspil = 1;
    int uafgjorte = 0;
    int vundet = 0;
    int tabte = 0;
    int gemtspil = 0;
    int c;
    
    FILE *filr = fopen("DinStilher.txt", "r");
    
    if (filr == NULL) {
        perror("Fejl ved at åbne filen");
    }

    
    //    0="sten"
    //    1="saks"
    //    2="papir"

    printf("Velkomen til sten, saks, papir\n");
    printf("0: Start Nyt spil\n");
    printf("1: Åben sidste spil\n");
    printf("Valg: ");
    scanf("%d", &gemtspil);
    
    
    
    switch (gemtspil) {
            
        case 0:
            aflustspil = 0;
            break;

        case 1:
        {
            int result = fscanf(filr, "Vundet: %d\nTabte: %d\nUafgjorte: %d", &vundet, &tabte, &uafgjorte);
            // Check om læsningen var vellykket
            if (result == 3) {
                // Print værdierne eller brug dem efter behov
                printf("Vundet: %d\nTabte: %d\nUafgjorte: %d\n", vundet, tabte, uafgjorte);
            } else {
                printf("Fejl ved at læse fra filen\n");
            }
            
            fclose(filr);
            aflustspil = 0;
            break;
        }
        default:
            printf("Ugyldigt valg");
            break;
    }


    while (aflustspil == 0) {
        int cvalg = rand() % 3;
        
        
        int valg;
        printf("\n0: Sten\n");
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
            printf("\nAntal vundet: %d\n", vundet);
            printf("Antal tabte: %d\n", tabte);
            printf("Antal uafgjorte: %d\n", uafgjorte);
            aflustspil = 0;
        } else {
            printf("Afslutter...\n");
            printf("\nAntal vundet: %d\n", vundet);
            printf("Antal tabte: %d\n", tabte);
            printf("Antal uafgjorte: %d\n", uafgjorte);
            
            
            FILE *filw = fopen("DinStilher.txt", "w");


            if (filw == NULL) {
                perror("Fejl ved at åbne filen");
            }

            fprintf(filw, "Vundet: %d\n", vundet);
            fprintf(filw, "Tabte: %d\n", tabte);
            fprintf(filw, "Uafgjorte: %d\n", uafgjorte);

            fclose(filw);
        }
    }
}



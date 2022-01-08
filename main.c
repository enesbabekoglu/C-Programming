#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tasKagitMakas(char isim[30]){

    int i = 1, puanOyuncu = 0, puanBilgisayar = 0, oyuncununCevabi;

    /*

    Oyuncudan scanf ile deger alinmasi icin input donduren,
    Bilgisayara rastgele olarak 1 - 3 arasinda bir deger dondurten ve sonrasinda

    */

    while(i < 6){

        printf("Tas [1], Kagit [2], Makas [3]\n\n");

        printf("(Bilgisayar): [%d. Tur] Hangisi? ", i);
        scanf("%d",&oyuncununCevabi);
        printf("\n");

        srand(time(0));

        int bilgisayarinCevabi = rand() % 3 + 1;

        /*

        Burada bilgisayara rastgele 1 - 3 arasinda sayi urettiriyoruz.

        */

        switch (oyuncununCevabi){

            case 1: // Eger oyuncunun sectigi sayi 1'e (tas) esit ise yap:
                switch(bilgisayarinCevabi){
                    case 1: // Eger bilgisayarin sectigi sayi 1'e (tas) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ikimizde \"TAS [1]\" cevabini verdik. Berabere kaldik ve ikimizde puan alamadik.\n", i);
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 2: // Eger bilgisayarin sectigi sayi 2'ye (kagit) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ben kazandim. Ben \"KAGIT [2]\" cevabini vermistim. (Kagit, tasi kirar!)\n\n", i);
                        puanBilgisayar = puanBilgisayar + 1;
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 3: // Eger bilgisayarin sectigi sayi 3'e (makas) esit ise yap:
                        printf("(Bilgisayar): TEBRIKLER %s! %d. Turda sen kazandin. Ben \"MAKAS [3]\" cevabini vermistim. (Tas, makasi kirar!)\n\n", isim, i);
                        puanOyuncu = puanOyuncu + 1;
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    default:
                        printf("Bir hata olustu.\n\n");
                }

                break;

            case 2: // Eger oyuncunun sectigi sayi 2'ye (kagit) esit ise yap:
                switch(bilgisayarinCevabi){
                    case 1: // Eger bilgisayarin sectigi sayi 1'e (tas) esit ise yap:
                        printf("(Bilgisayar): TEBRIKLER %s! %d. Turda sen kazandin. Ben \"TAS [3]\" cevabini vermistim. (Kagit, tasi sarar!)\n\n", isim, i);
                        puanOyuncu = puanOyuncu + 1;
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 2: // Eger bilgisayarin sectigi sayi 2'ye (kagit) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ikimizde \"KAGIT [2]\" cevabini verdik. Berabere kaldik ve ikimizde puan alamadik.\n\n", i);
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 3: // Eger bilgisayarin sectigi sayi 3'e (makas) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ben kazandim. Ben \"MAKAS [3]\" cevabini vermistim. (Makas, kagidi keser!)\n\n", i);
                        puanBilgisayar = puanBilgisayar + 1;
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    default:
                        printf("Bir hata olustu.\n\n");
                }

                break;

            case 3: // Eger oyuncunun sectigi sayi 3'e (makas) esit ise yap:
                switch(bilgisayarinCevabi){
                    case 1: // Eger bilgisayarin sectigi sayi 1'e (tas) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ben kazandim. Ben \"TAS [1]\" cevabini vermistim. (Tas, makasi kirar!)\n\n", i);
                        puanBilgisayar = puanBilgisayar + 1;
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 2: // Eger bilgisayarin sectigi sayi 2'ye (kagit) esit ise yap:
                        printf("(Bilgisayar): TEBRIKLER %s! %d. Turda sen kazandin. Ben \"KAGIT [2]\" cevabini vermistim. (Makas, kagidi keser!)\n\n", isim, i);
                        puanOyuncu = puanOyuncu + 1;
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 3: // Eger bilgisayarin sectigi sayi 3'e (makas) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ikimizde \"MAKAS [3]\" cevabini verdik. Berabere kaldik ve ikimizde puan alamadik.\n\n", i);
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    default:
                        printf("Bilinmeyen bir hata olustu.\n\n");
                }

                break;

            default: // Eger oyuncunun sectigi sayi 1,2,3 degerlerine esit degil ise yap:
                printf("Hatali bir sayi girdiniz. Lutfen 1, 2 ve 3 degerlerinden birisini giriniz. %d. Tur tekrarlaniyor...\n\n", i);
                i = i-1; // Hatalı bir sayi girildigi icin ayni turu tekrar ediyoruz.

        }

        if(puanBilgisayar == 3 || puanOyuncu == 3){

            /*
            Burada oyunda 5 tur oldugundan dolayı
            Zaten en az 3 puan alanin oyunu kesinlikle kazanacagindan
            Donguden cikiyoruz ve oyunu bitiriyoruz
            */

            break;

        }

    printf("--------------------------------------------------------------------\n\n");

    i++;

    }

    if(puanBilgisayar > puanOyuncu){ // Eger bilgisayarin puani oyuncunun puanindan fazla ise yap:
        printf("--------------------------------------------------\n--------------------------------------------------\n\n");
        printf("(Bilgisayar): KAYBETTIN %s! :(\n\n", isim);
        printf("PUANLAR = Bilgisayar: [%d] / Sen: %d\n\n", puanBilgisayar, puanOyuncu);
        printf("--------------------------------------------------\n--------------------------------------------------\n");
    }else if(puanBilgisayar < puanOyuncu){ // Eger oyuncunun puani bilgisayarin puanindan fazla ise yap:
        printf("##################################################\n##################################################\n\n");
        printf("(Bilgisayar): TEBRIKLER %s! Oyunu sen kazandin. :)\n\n", isim);
        printf("PUANLAR = Bilgisayar: %d / Sen: [%d]\n\n", puanBilgisayar, puanOyuncu);
        printf("##################################################\n##################################################\n");
    }else{  // Eger oyuncunun puani ve bilgisayarin puani esitse yap:
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("(Bilgisayar): BERABERE KALDIK %s! Bu oyunda kazanan kardeslik oldu. :)\n\n", isim);
        printf("PUANLAR = Bilgisayar: %d / Sen: %d\n\n", puanBilgisayar, puanOyuncu);
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    }

}

int main(){

    char ad[30];
    int hazirmi;

    printf("\n");
    printf("TAS KAGIT MAKAS");
    printf("\n\n");
    printf("(Bilgisayar): Hosgeldin, sana hitap edebilmem icin adini ogrenmem gerekir. Bana adini soyler misin?\n\n");
    printf("(Sen): Benim Adim ");
    scanf("%s", ad);

    printf("\n(Bilgisayar): Tekrar hosgeldin %s, sana biraz oyunun kurallarindan bahsetmeliyim.\n\n", ad);

    printf("(Bilgisayar): Asagidaki tabloda tas, kagit ve makasin hangi durumlarda kazanabilecegi yaziyor.\n\n");

    printf("KIM KIMI YENER\n");
    printf("Tas (1) & Kagit (2) = Kagit (2)\n");
    printf("Tas (1) & Makas (3) = Tas (1)\n");
    printf("Kagit (2) & Makas (3) = Makas (3)\n\n");

    printf("(Bilgisayar): Dilersen baslayalim...\n\n");

    for(int kontrol = 0; kontrol < 10; kontrol++){

        printf("(Bilgisayar): %s, baslamak icin hazir misin? Evet - [1] # Hayir: [2]\n", ad);
        scanf("%d", &hazirmi);

        printf("\n");

        if(hazirmi == 1){ // Eger Yanit 1 Ise Yani Hazirsa Oyunu Baslatan Fonksiyonu Cagir

            printf("(Bilgisayar): Oyun baslatiliyor...\n\n");
            printf("--------------------------------------------------------------------\n\n");

            tasKagitMakas(ad);
            break;

        }else if(hazirmi == 2){ // Eger Yanit 2 Ise Yani Hazir Degilse Yaz ve Donguyu Bitir

            printf("(Bilgisayar): %s, oyunu iptal ettim. Tekrar baslamak istersen lutfen oyunu kapat ve yeniden ac.\n", ad);
            break;

        }else{ // Yanit 1 ve 2 Degilse Tekrar Sor

            printf("(Bilgisayar): %s, ne yazik ki seni anlayamadim. Lutfen sadece Evet [1] ve Hayir [2] yazarak yanit ver.\n", ad);

        }

    }

}

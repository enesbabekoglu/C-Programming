#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Bilgisayara Rastgele 1 - 3 Arasinda Sayi Sectirip Donduren Fonksiyon */

int bilgisayarinSecimi(){

    srand(time(0));

    int bilgisayarinCevabi = rand() % 3 + 1;
    return bilgisayarinCevabi;
    
}

/* Oyuncudan Hangisini Sectigini Alan ve Donduren Fonksiyon */

int oyuncununSecimi(int i){
    
    int oyuncununCevabi;
    
    printf("Tas [1], Kagit [2], Makas [3]\n\n");
    printf("(Bilgisayar): [%d. Tur] Hangisi?\n(Sen): ", i);
    scanf("%d",&oyuncununCevabi);
    printf("\n");
    
    return oyuncununCevabi;
    
}

/* Kazananin Kim Oldugunu Kontrol Eden ve Konsola Yazdiran Fonksiyon */

void kazananKim(int puanBilgisayar, int puanOyuncu, char isim[30], int i, int kazananinAlacagiPuan){
    
    int bilgisayarTur = puanBilgisayar/kazananinAlacagiPuan;
    int oyuncuTur = puanOyuncu/kazananinAlacagiPuan;
    int beraberlikSayisi = (i)-(bilgisayarTur+oyuncuTur);

    if(puanBilgisayar > puanOyuncu){ // Eger bilgisayarin puani oyuncunun puanindan fazla ise yap:
        printf("--------------------------------------------------\n--------------------------------------------------\n\n");
        printf("(Bilgisayar): KAYBETTIN %s! :(\n\n", isim);
        printf("DURUM TABLOSU\n[Bilgisayar: %d Puan / %d Tur]\nSen: %d Puan / %d Tur\nBeraberlik: %d Tur\nOyun %d Tur Surdu\n\n", puanBilgisayar, bilgisayarTur, puanOyuncu, oyuncuTur, beraberlikSayisi, i);
        printf("--------------------------------------------------\n--------------------------------------------------\n\n");
    }else if(puanBilgisayar < puanOyuncu){ // Eger oyuncunun puani bilgisayarin puanindan fazla ise yap:
        printf("##################################################\n##################################################\n\n");
        printf("(Bilgisayar): TEBRIKLER %s! Oyunu sen kazandin. :)\n\n", isim);
        printf("DURUM TABLOSU\nBilgisayar: %d Puan / %d Tur\n[Sen: %d Puan / %d Tur]\nBeraberlik: %d Tur\nOyun %d Tur Surdu\n\n", puanBilgisayar, bilgisayarTur, puanOyuncu, oyuncuTur, beraberlikSayisi, i);
        printf("##################################################\n##################################################\n\n");
    }else{  // Eger oyuncunun puani ve bilgisayarin puani esitse yap (Burasi eger oyunda tur sinirlamasi yapilirsa gecerli olacaktir.)
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("(Bilgisayar): BERABERE KALDIK %s! Bu oyunda kazanan kardeslik oldu. :)\n\n", isim);
        printf("DURUM TABLOSU\nBilgisayar: %d Puan / %d Tur\nSen: %d Puan / %d Tur\nBeraberlik: %d Tur\nOyun %d Tur Surdu\n\n", puanBilgisayar, bilgisayarTur, puanOyuncu, oyuncuTur, beraberlikSayisi, i);
        printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    }
    
}

/* Oyunun Ana Fonksiyonu */

void tasKagitMakas(char isim[30], int kazananinAlacagiPuan, int kacPuandaKazanilacak){

    int i = 1, puanOyuncu = 0, puanBilgisayar = 0; // Degiskenlerin bir tam sayi oldugunu tanimliyoruz.
    
    while(1){ // Bu dongu kendisi icin break; kodu kullanilana kadar devam edecektir.

        int bilgisayarinCevabi = bilgisayarinSecimi(); // Bilgisayarin Sectigi Sayiyi Veren Fonksiyonu Cagiriyoruz ve Degiskene Atiyoruz
        int oyuncununCevabi = oyuncununSecimi(i); // Oyuncunun Sectigi Sayiyi Veren Fonksiyonu Cagiriyoruz ve Degiskene Atiyoruz

        switch (oyuncununCevabi){ 
            
            /* 
            
            Switch ile oyuncunun vermis oldugu cevabi case yapilarina her secenegin denk geldigi sayiyi yazip karsilastiriyoruz.
            Ornegin: Oyuncu 1 yazdiginda switch(1) degeri doner ve bu case 1: degerinin icindeki islemlerin yapilacagi anlamina gelir.
            
            */

            case 1: // Eger oyuncunun sectigi sayi 1'e (tas) esit ise yap:
                switch(bilgisayarinCevabi){
                    
                    /* 
            
                    Switch ile bilgisayarin vermis oldugu cevabi case yapilarina her secenegin denk geldigi sayiyi yazip karsilastiriyoruz.
                    Ornegin: Bilgisayar 2 yazdiginda switch(2) degeri doner ve bu case 2: degerinin icindeki islemlerin yapilacagi anlamina gelir.
            
                    */
            
                    case 1: // Eger bilgisayarin sectigi sayi 1'e (tas) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ikimizde \"TAS [1]\" cevabini verdik. Berabere kaldik ve ikimizde puan alamadik.\n", i);
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 2: // Eger bilgisayarin sectigi sayi 2'ye (kagit) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ben kazandim. Ben \"KAGIT [2]\" cevabini vermistim. (Kagit, tasi sarar!)\n\n", i);
                        puanBilgisayar = puanBilgisayar + kazananinAlacagiPuan; // Bilgisayara +kazananinAlacagiPuan Puan Ekliyoruz
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 3: // Eger bilgisayarin sectigi sayi 3'e (makas) esit ise yap:
                        printf("(Bilgisayar): TEBRIKLER %s! %d. Turda sen kazandin. Ben \"MAKAS [3]\" cevabini vermistim. (Tas, makasi kirar!)\n\n", isim, i);
                        puanOyuncu = puanOyuncu + kazananinAlacagiPuan; // Oyuncuya +kazananinAlacagiPuan Puan Ekliyoruz
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    default: // Burasi calistiginde bilgisayarin hatali bir sayi urettigi yani 1 - 3 disinda bir sayi urettigi anlasilabilir.
                        printf("Bir hata olustu.\n\n");
                }

                break;

            case 2: // Eger oyuncunun sectigi sayi 2'ye (kagit) esit ise yap:
                switch(bilgisayarinCevabi){
                    
                    /* 
            
                    Switch ile bilgisayarin vermis oldugu cevabi case yapilarina her secenegin denk geldigi sayiyi yazip karsilastiriyoruz.
                    Ornegin: Bilgisayar 2 yazdiginda switch(2) degeri doner ve bu case 2: degerinin icindeki islemlerin yapilacagi anlamina gelir.
            
                    */
                    
                    case 1: // Eger bilgisayarin sectigi sayi 1'e (tas) esit ise yap:
                        printf("(Bilgisayar): TEBRIKLER %s! %d. Turda sen kazandin. Ben \"TAS [3]\" cevabini vermistim. (Kagit, tasi sarar!)\n\n", isim, i);
                        puanOyuncu = puanOyuncu + kazananinAlacagiPuan; // Oyuncuya +kazananinAlacagiPuan Puan Ekliyoruz
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 2: // Eger bilgisayarin sectigi sayi 2'ye (kagit) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ikimizde \"KAGIT [2]\" cevabini verdik. Berabere kaldik ve ikimizde puan alamadik.\n\n", i);
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 3: // Eger bilgisayarin sectigi sayi 3'e (makas) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ben kazandim. Ben \"MAKAS [3]\" cevabini vermistim. (Makas, kagidi keser!)\n\n", i);
                        puanBilgisayar = puanBilgisayar + kazananinAlacagiPuan; // Bilgisayara +kazananinAlacagiPuan Puan Ekliyoruz
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    default: // Burasi calistiginde bilgisayarin hatali bir sayi urettigi yani 1 - 3 disinda bir sayi urettigi anlasilabilir.
                        printf("Bir hata olustu.\n\n");
                }
                
                break;

            case 3: // Eger oyuncunun sectigi sayi 3'e (makas) esit ise yap:
                switch(bilgisayarinCevabi){
                    
                    /* 
            
                    Switch ile bilgisayarin vermis oldugu cevabi case yapilarina her secenegin denk geldigi sayiyi yazip karsilastiriyoruz.
                    Ornegin: Bilgisayar 2 yazdiginda switch(2) degeri doner ve bu case 2: degerinin icindeki islemlerin yapilacagi anlamina gelir.
            
                    */
                    
                    case 1: // Eger bilgisayarin sectigi sayi 1'e (tas) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ben kazandim. Ben \"TAS [1]\" cevabini vermistim. (Tas, makasi kirar!)\n\n", i);
                        puanBilgisayar = puanBilgisayar + kazananinAlacagiPuan; // Bilgisayara +kazananinAlacagiPuan Puan Ekliyoruz
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 2: // Eger bilgisayarin sectigi sayi 2'ye (kagit) esit ise yap:
                        printf("(Bilgisayar): TEBRIKLER %s! %d. Turda sen kazandin. Ben \"KAGIT [2]\" cevabini vermistim. (Makas, kagidi keser!)\n\n", isim, i);
                        puanOyuncu = puanOyuncu + kazananinAlacagiPuan; // Oyuncuya +kazananinAlacagiPuan Puan Ekliyoruz
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    case 3: // Eger bilgisayarin sectigi sayi 3'e (makas) esit ise yap:
                        printf("(Bilgisayar): %d. Turda ikimizde \"MAKAS [3]\" cevabini verdik. Berabere kaldik ve ikimizde puan alamadik.\n\n", i);
                        printf("(PUAN DURUMU = Bilgisayar: %d / %s: %d)\n\n", puanBilgisayar, isim, puanOyuncu);
                        break;
                    default: // Burasi calistiginde bilgisayarin hatali bir sayi urettigi yani 1 - 3 disinda bir sayi urettigi anlasilabilir.
                        printf("Bilinmeyen bir hata olustu.\n\n");
                }
                
                break;

            default: // Eger oyuncunun sectigi sayi 1,2,3 degerlerine esit degil ise yap:
                printf("Hatali bir sayi girdiniz. Lutfen 1, 2 ve 3 degerlerinden birisini giriniz. %d. Tur tekrarlaniyor...\n\n", i);
                i = i-1; // Hatalı bir sayi girildigi icin "i" degerini geri alip ayni turu tekrar ediyoruz.

        }

        if(puanBilgisayar >= kacPuandaKazanilacak || puanOyuncu >= kacPuandaKazanilacak){

            /*
            Burada 5 puan alanin oyunu kazanacagindan
            Donguden cikiyoruz ve oyunu bitiriyoruz
            */

            break;

        }

    printf("--------------------------------------------------------------------\n\n");

    i++;

    }
    
    kazananKim(puanBilgisayar, puanOyuncu, isim, i, kazananinAlacagiPuan); // Burada kazananin kim oldugunu kontrol eden ve konsola yazdiran fonksiyonu cagiriyoruz.

}

int main(){

    char isim[30]; // Oyuncunun ismini tutacagimiz degisken.
    int hazirmi; // Oyuncunun oyunu baslatmasi icin bu degerin 1 olarak dondurulmesi gerekir.
    int kazananinAlacagiPuan = 1; // Bu degisken degeri degistirilerek her turda kazananin alacagi puan belirtilebilir.
    int kacPuandaKazanilacak = 5; // Bu degisken degeri degistirilerek oyunun kac puanda bitecegi belirtilebilir.
    
    printf("\n");
    printf("TAS KAGIT MAKAS");
    printf("\n\n");
    printf("(Bilgisayar): Hosgeldin, sana hitap edebilmem icin adini ogrenmem gerekir. Bana adini soyler misin?\n\n");
    printf("(Sen): ");
    scanf("%s", isim);

    printf("\n(Bilgisayar): Tekrar hosgeldin %s, sana biraz oyunun kurallarindan bahsetmeliyim.\n\n", isim);

    printf("(Bilgisayar): Asagidaki tabloda tas, kagit ve makasin hangi durumlarda kazanabilecegi yaziyor.\n\n");

    printf("KIM KIMI YENER\n");
    printf("Tas (1) & Kagit (2) = Kagit (2)\n");
    printf("Tas (1) & Makas (3) = Tas (1)\n");
    printf("Kagit (2) & Makas (3) = Makas (3)\n\n");

    printf("(Bilgisayar): Kazanan her turda +%d puan alir. Oyun taraflardan birisi %d puan oldugunda bitecektir.\n\n", kazananinAlacagiPuan, kacPuandaKazanilacak);

    printf("(Bilgisayar): Dilersen baslayalim...\n\n");

    for(;;){ // Burada sonsuz tekrar eden bir kontrol dongusu olusturduk.

        printf("(Bilgisayar): %s, baslamak icin hazir misin? Evet - [1] # Hayir: [2]\n(Sen): ", isim);
        scanf("%d", &hazirmi);

        printf("\n");

        if(hazirmi == 1){ // Eger Yanit 1 Ise Yani Hazirsa Oyunu Baslatan Fonksiyonu Cagir

            printf("(Bilgisayar): Oyun baslatiliyor...\n\n");
            printf("--------------------------------------------------------------------\n\n");

            tasKagitMakas(isim, kazananinAlacagiPuan, kacPuandaKazanilacak); // Oyun Fonksiyonunu Cagirdik
            
            break; // Cevabi aldigimiz icin donguyu sonlandiriyoruz.

        }else if(hazirmi == 2){ // Eger Yanit 2 Ise Yani Hazir Degilse Yaz ve Donguyu Bitir

            printf("(Bilgisayar): %s, oyunu iptal ettim. Tekrar baslamak istersen lutfen oyunu kapat ve yeniden ac.\n", isim);
            
            break; // Cevabi aldigimiz icin donguyu sonlandiriyoruz.

        }else{ // Yanit 1 ve 2 Degilse Tekrar Sor

            printf("(Bilgisayar): %s, ne yazik ki seni anlayamadim. Lutfen sadece Evet [1] ve Hayir [2] yazarak yanit ver.\n", isim);

        }

    }
    
    return 0;

}


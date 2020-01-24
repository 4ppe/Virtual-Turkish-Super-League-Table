/*
Alper Babadað	365256 365256@ogr.ktu.edu.tr Bireysel deðerlendirme 2.kisim
Yusuf Nadaroðlu 365242 365242@ogr.ktu.edu.tr Bireysel degerlendirme 1.kisim
*/

#include <stdio.h>
#include <stdlib.h>

// Takim struct'i olusturuldu
struct takim{
	char ad[13];
	char kisa_ad;
	int oynadigi_mac;
	int galibiyet_sayisi;
	int beraberlik_sayisi;
	int maglubiyet_sayisi;
	int attigi_gol;
	int yedigi_gol;
	int averaj;
	int puan;
};

//islenecek maclar icin struct olusturuldu
struct mac{
	char ev_sahibi;
	char deplasman;
};

int ayarlar[5]; 		//ayarlar.txt den cekilen ayarlarin islenecegi dizi tanimlandi
struct takim *takimlar; //takimlar ve maclar structu tanimlandi
struct mac *maclar;


//Ayarlari okuyan fonksiyon
void ayar_oku(){
    FILE *ayarlar_dosyasi = fopen("ayarlar.txt", "r");
    if(ayarlar_dosyasi == NULL){
		printf("\nayarlar.txt dosyasi mevcut degil\n");
		exit(0);
    }
    int i = 0;
    while(!feof(ayarlar_dosyasi)){
		fscanf(ayarlar_dosyasi,"%d",&ayarlar[i]);  //Ayarlar dizisine tum ayarlar atandi
		i++;
    }
    fclose(ayarlar_dosyasi);
    
    ayarlar[4] = 0;  //Oynanan mac sayisi
}

//Takimlari okuyan fonksiyon
void takimlari_oku(){
	FILE *takimlar_dosyasi = fopen("takimlar.txt","r");
    if(takimlar_dosyasi == NULL){
        printf("\ntakimlar.txt dosyasi mevcut degil\n");
        exit(0);
    }
    //takimlar.txt mevcut ise struct yapisina takim bilgileri tek tek ekleniyor
	int i = 0;
	char ch = 'A';
    while(!feof(takimlar_dosyasi)){
    	if(i < ayarlar[0]){
    		fscanf(takimlar_dosyasi,"%s",takimlar[i].ad);
            takimlar[i].kisa_ad = ch++;
            takimlar[i].oynadigi_mac = 0;
            takimlar[i].galibiyet_sayisi = 0;
            takimlar[i].beraberlik_sayisi = 0;
            takimlar[i].maglubiyet_sayisi = 0;
            takimlar[i].attigi_gol = 0;
            takimlar[i].yedigi_gol = 0;
            takimlar[i].averaj = 0;
            takimlar[i].puan = 0;
    		i++;
		}else{
			break;
		}
	}
    ayarlar[0] = i; //Takim sayisini guncelliyor
    fclose(takimlar_dosyasi);
}


//Macin daha once oynanip oynanmadigini kontrol ediyor tekrar etmiyorsa 1 ediyorsa 0 donduruyor
int mac_kontrol(char ev, char dep){
	int i;
	for(i = 0; i < ayarlar[4];i++){
		if(maclar[i].ev_sahibi == ev && maclar[i].deplasman == dep){
			return 0;
		}
	}
		return 1;
}

//dosyadan maclari okuyan fonksiyon
void maclari_oku(){
	FILE *mac_dosyasi = fopen("maclar1.txt","r");
    if(mac_dosyasi == NULL){
        printf("\nmaclar1.txt dosyasi mevcut degil\n");
        return;
    }
    int m[4],i;
    while(!feof(mac_dosyasi)){
		fscanf(mac_dosyasi," %lc %d %lc %d", &m[0], &m[1], &m[2], &m[3]);
		if(mac_kontrol(m[0], m[2])){
			maclar[ayarlar[4]].ev_sahibi = m[0];
			maclar[ayarlar[4]].deplasman = m[2];
			ayarlar[4]++;  //Mac oynanmadiysa 1 arttir
			for(i = 0; i < ayarlar[0]; i++){
				if(takimlar[i].kisa_ad == m[0]){
			        takimlar[i].oynadigi_mac++;
			        takimlar[i].galibiyet_sayisi += m[1] > m[3] ? 1 : 0;
			        takimlar[i].beraberlik_sayisi += m[1] == m[3] ? 1 : 0;
			        takimlar[i].maglubiyet_sayisi += m[1] < m[3] ? 1 : 0;
			        takimlar[i].attigi_gol += m[1];
			        takimlar[i].yedigi_gol += m[3];
			        takimlar[i].averaj += m[1] - m[3];
			        takimlar[i].puan += m[1] > m[3] ? ayarlar[1] : m[1] < m[3] ? ayarlar[3] : ayarlar[2];
				}else if(takimlar[i].kisa_ad == m[2]){
			        takimlar[i].oynadigi_mac++;
			        takimlar[i].galibiyet_sayisi += m[3] > m[1] ? 1 : 0;
			        takimlar[i].beraberlik_sayisi += m[3] == m[1] ? 1 : 0;
			        takimlar[i].maglubiyet_sayisi += m[3] < m[1] ? 1 : 0;
			        takimlar[i].attigi_gol += m[3];
			        takimlar[i].yedigi_gol += m[1];
			        takimlar[i].averaj += m[3] - m[1];
			        takimlar[i].puan += m[3] > m[1] ? ayarlar[1] : m[3] < m[1] ? ayarlar[3] : ayarlar[2];
				}
			}
		}
	}
	printf("\nMaclar basariyla islendi\n");
}

void klavyeden_mac(){
    int m[4],i;
    printf("Lutfen mac sonucunu giriniz : ");
    scanf(" %lc %d %lc %d", &m[0], &m[1], &m[2], &m[3]);
    //Mac daha once oynanmadiysa kontrol ediliyor
    if(mac_kontrol(m[0], m[2])){
        maclar[ayarlar[4]].ev_sahibi = m[0];
        maclar[ayarlar[4]].deplasman = m[2];
        ayarlar[4]++; //Mac daha once oynanmadiysa oynanan mac sayisini 1 arttiriyor
        for(i = 0; i < ayarlar[0]; i++){
            if(takimlar[i].kisa_ad == m[0]){
                takimlar[i].oynadigi_mac++;
                takimlar[i].galibiyet_sayisi += m[1] > m[3] ? 1 : 0;
                takimlar[i].beraberlik_sayisi += m[1] == m[3] ? 1 : 0;
                takimlar[i].maglubiyet_sayisi += m[1] < m[3] ? 1 : 0;
                takimlar[i].attigi_gol += m[1];
                takimlar[i].yedigi_gol += m[3];
                takimlar[i].averaj += m[1] - m[3];
                takimlar[i].puan += m[1] > m[3] ? ayarlar[1] : m[1] < m[3] ? ayarlar[3] : ayarlar[2];
            }else if(takimlar[i].kisa_ad == m[2]){
                takimlar[i].oynadigi_mac++;
                takimlar[i].galibiyet_sayisi += m[3] > m[1] ? 1 : 0;
                takimlar[i].beraberlik_sayisi += m[3] == m[1] ? 1 : 0;
                takimlar[i].maglubiyet_sayisi += m[3] < m[1] ? 1 : 0;
                takimlar[i].attigi_gol += m[3];
                takimlar[i].yedigi_gol += m[1];
                takimlar[i].averaj += m[3] - m[1];
                takimlar[i].puan += m[3] > m[1] ? ayarlar[1] : m[3] < m[1] ? ayarlar[3] : ayarlar[2];
            }
        }
        printf("\nMac basariyla islendi\n");
    }else{
        printf("\nMac daha once oynandi.\n");
    }
}

void takimi_sirala(){
	int i,k;
	
	 for(i=1;i<ayarlar[0];i++) {
	    for(k=0;k<ayarlar[0]-i;k++) {
	    if(takimlar[k].ad[0] >takimlar[k+1].ad[0]) {
	        struct takim bosluk = takimlar[k];
	        takimlar[k] =takimlar[k+1];
	        takimlar[k+1] = bosluk; }
	    else if (takimlar[k].ad[0]==takimlar[k+1].ad[0]){
	        if (takimlar[k].ad[1] >takimlar[k+1].ad[1]){
	            struct takim bosluk = takimlar[k];
	            takimlar[k] =takimlar[k+1];
	            takimlar[k+1] = bosluk; }
	            else if(takimlar[k].ad[1] ==takimlar[k+1].ad[1]){
	                if (takimlar[k].ad[2] >takimlar[k+1].ad[2]){
	                struct takim bosluk = takimlar[k];
	                takimlar[k] =takimlar[k+1];
	                takimlar[k+1] = bosluk; }
	                else if (takimlar[k].ad[2]==takimlar[k+1].ad[2]){
	                    if (takimlar[k].ad[3] >takimlar[k+1].ad[3]){
	                        struct takim bosluk = takimlar[k];
	                        takimlar[k] =takimlar[k+1];
	                        takimlar[k+1] = bosluk; }
	
	                    else if (takimlar[k].ad[3]==takimlar[k+1].ad[3]){
	                        if (takimlar[k].ad[4] >takimlar[k+1].ad[4]){
	                            struct takim bosluk = takimlar[k];
	                            takimlar[k] =takimlar[k+1];
	                            takimlar[k+1] = bosluk; }
	                       else if (takimlar[k].ad[4]==takimlar[k+1].ad[4]){
	                            if (takimlar[k].ad[5] >takimlar[k+1].ad[5]){
	                                struct takim bosluk = takimlar[k];
	                                takimlar[k] =takimlar[k+1];
	                                takimlar[k+1] = bosluk; }
	                           else if (takimlar[k].ad[6]==takimlar[k+1].ad[6]){
	                                if (takimlar[k].ad[7] >takimlar[k+1].ad[7]){
	                                struct takim bosluk = takimlar[k];
	                                takimlar[k] =takimlar[k+1];
	                                takimlar[k+1] = bosluk; }
	                                else if (takimlar[k].ad[8]==takimlar[k+1].ad[8]){
	                                    if (takimlar[k].ad[9] >takimlar[k+1].ad[9]){
	                                        struct takim bosluk = takimlar[k];
	                                        takimlar[k] =takimlar[k+1];
	                                        takimlar[k+1] = bosluk; }
	                                    else if (takimlar[k].ad[9]==takimlar[k+1].ad[9]){
	                                        if (takimlar[k].ad[10] >takimlar[k+1].ad[10]){
	                                            struct takim bosluk = takimlar[k];
	                                            takimlar[k] =takimlar[k+1];
	                                            takimlar[k+1] = bosluk; }
	                                        else if  (takimlar[k].ad[10] ==takimlar[k+1].ad[10]){
	                                            if (takimlar[k].ad[11] >takimlar[k+1].ad[11]){
	                                            struct takim bosluk = takimlar[k];
	                                            takimlar[k] =takimlar[k+1];
	                                            takimlar[k+1] = bosluk; }
	
	                                        }
	                                    }
	                                }
	                            }
	                        }
	                    }
	                }
	            }
	        }
	    }
	}
}


//Puana gore siralayan fonksiyon
void puan_siralama(){
	int i,j;
    for(i=1;i<ayarlar[0];i++)
    {
        for(j=0;j<ayarlar[0]-i;j++)
        {
            if(takimlar[j].puan<takimlar[j+1].puan)
            {
    			struct takim tkm_temp = takimlar[j+1];
    			takimlar[j+1] = takimlar[j];
    			takimlar[j] = tkm_temp;
            }
        }
    }
}

//Takma ada gore siralayan fonksiyon
void takma_ad_siralama(){
	int i,j;
	for(i=1;i<ayarlar[0];i++)
    {
        for(j=0;j<ayarlar[0]-i;j++)
        {
            if(takimlar[j].kisa_ad>takimlar[j+1].kisa_ad)
            {
    			struct takim tkm_temp = takimlar[j+1];
    			takimlar[j+1] = takimlar[j];
    			takimlar[j] = tkm_temp;
            }
        }
    }
}

//Duzenlenen veya duzenlenmemis takimlari yazdirir
void siralama_goster(){
    int o,c;
    printf("TA\tTakim adi  \tOM\tGS\tBS\tMS\tAG\tYG\tA\tP\n");

    for (o = 0;o<ayarlar[0];o++){

        printf("%c\t%s",takimlar[o].kisa_ad,takimlar[o].ad);
        
        //Dizinin boyunu c sayesinde tuttuk
		c = 0;
        while (takimlar[o].ad[c] != '\0'){
        c++;}
        //Takim ismi 8 karakterden buyukse 1 adet tab ekle
        if(c<8){
            printf("\t");
        }

        printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",takimlar[o].oynadigi_mac,takimlar[o].galibiyet_sayisi,takimlar[o].beraberlik_sayisi,takimlar[o].maglubiyet_sayisi,takimlar[o].attigi_gol,takimlar[o].yedigi_gol,takimlar[o].averaj,takimlar[o].puan);
    }
    //Puan tablosu icin gerekli kisaltmalarin bilgileri
    printf("\nOM = Oynanan mac - GS = Galibiyet sayisi - BS = Beraberlik sayisi - MS = Maglubiyet sayisi - AG = Atilan gol\nYG = Yedigi gol - A = Averaj - P = Puan - T.a = Takma ad\n\n");
}

//Takimlarin adini harf harf buyuten fonksiyon
void hepsini_buyut(){
    int v,c;
    for(c=0; c<=ayarlar[0]; c++)
    {
        for(v=0;takimlar[c].ad[v]!='\0';v++)
        {
            if(takimlar[c].ad[v]>=97 && takimlar[c].ad[v]<=122)
            {
               takimlar[c].ad[v] = takimlar[c].ad[v]-32;
            }
        }
    }
    printf("\nTakim isimleri buyultuldu\n");
}

//Takimlarin adini harf harf kuculten fonksiyon
void hepsini_kucult(){
    int v,c;
    for(c=0; c<=ayarlar[0]; c++)
    {
        for(v=0;takimlar[c].ad[v]!='\0';v++)
        {
            if(takimlar[c].ad[v]>=65 && takimlar[c].ad[v]<=90)
            {
               takimlar[c].ad[v] = takimlar[c].ad[v]+32;

            }


        }
    }
    printf("\nTakim isimleri kucultuldu\n");
}

void dosyaya_siralama_yaz(){
	FILE *siralama_dosya;
	siralama_dosya = fopen("siralama_tablosu.txt","w");
	int o,c;
    fprintf(siralama_dosya,"T.A\tTakim adi  \tOM\tGS\tBS\tMS\tAG\tYG\tA\tP\n");

    for (o = 0;o<ayarlar[0];o++){

        fprintf(siralama_dosya,"%c\t%s",takimlar[o].kisa_ad,takimlar[o].ad);
        
        //Dizinin boyunu c sayesinde tuttuk
		c = 0;
        while (takimlar[o].ad[c] != '\0'){
        c++;}

        //Takim ismi 8 karakterden buyukse 1 adet tab ekle
        if(c<8){
            fprintf(siralama_dosya,"\t");
        }

        fprintf(siralama_dosya,"\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",takimlar[o].oynadigi_mac,takimlar[o].galibiyet_sayisi,takimlar[o].beraberlik_sayisi,takimlar[o].maglubiyet_sayisi,takimlar[o].attigi_gol,takimlar[o].yedigi_gol,takimlar[o].averaj,takimlar[o].puan);

    }
    //Puan tablosu icin gerekli kisaltmalarin bilgileri
    fprintf(siralama_dosya,"\nOM = Oynanan mac - GS = Galibiyet sayisi - BS = Beraberlik sayisi - MS = Maglubiyet sayisi - AG = Atilan gol\nYG = Yedigi gol - A = Averaj - P = Puan - TA = Takma ad\n\n");

		fclose(siralama_dosya);
		printf("\nSiralamalar dosyaya yazildi\n\nAna menuye donuluyor");
	}

int main(){
	int islem,y,secim;
	printf("\n\n****  Turkiye Sanal Super Ligine Hosgeldiniz  ****\n\n");
	ayar_oku(); // Ayarlari okuyor
	takimlar = (struct takim*)malloc(ayarlar[0] * sizeof(struct takim)); // takimlar structu ayarlar[0] daki takim isimlerine gore duzenlendi
	takimlari_oku();
	takimlar = (struct takim*)realloc(takimlar, ayarlar[0] * sizeof(struct takim)); // takimlar structu ayarlar[0] daki takim isimlerine gore tekrar duzenlendi
	maclar = (struct mac*)malloc((((ayarlar[4] - 1) * ayarlar[4]) + 1) * sizeof(struct mac)); //oynanabilecek mac sayisi kadar yer ayirdi

	while(1){
	    printf("\n\n************\n1.) Takma ada gore sirala\n2.) Takim adina gore sirala\n3.) Puana gore sirala\n4.) Manuel mac girisi\n5.) Dosyadan mac girisi\n6.) Takim isimlerini buyut\n7.) Takim isimlerini kucult\n8.) Programdan cik\n************\n");
        printf("\nYapmak istediginiz islemin kodunu giriniz : ");
        scanf("%d",&islem);
	    if(islem>=1 && islem<9){
	    	//8 girildiginde donguyu kiriyor ve programi kapatiyor
	        if(islem==8){
				break;
	        }
	        if( islem == 1 ){
                takma_ad_siralama();
                siralama_goster();
                printf("1.) Siralamayi dosyaya yaz\n2.) Ana menuye don\n3.) Programi sonlandir\nYapmak istediginiz islemin kodunu giriniz : ");
                scanf("%d",&y);
                if(y==1){
                	dosyaya_siralama_yaz();
				}
                if(y==3){
                    break;
                }
            } else if( islem == 2 ) {
					takimi_sirala();
					siralama_goster();
                	printf("1.) Siralamayi dosyaya yaz\n2.) Ana menuye don\n3.) Programi sonlandir\nYapmak istediginiz islemin kodunu giriniz : ");
                	scanf("%d",&y);
                	if(y==1){
                		dosyaya_siralama_yaz();
					}
                	if(y==3){
                    	break;
                }
	        } else if( islem == 3 ) {
                puan_siralama();
                siralama_goster();
                printf("1.) Siralamayi dosyaya yaz\n2.) Ana menuye don\n3.) Programi sonlandir\nYapmak istediginiz islemin kodunu giriniz : ");
                scanf("%d",&y);
                if(y==1){
                	dosyaya_siralama_yaz();
				}
                if(y==3){
                    break;
                }
			}else if( islem == 4 ) {
				while(1){
					klavyeden_mac();
					printf("\n1.) Mac girmeye devam et\n2.) Ana menuye don\nLutfen yapmak istediginiz islemi seciniz : ");
					scanf("%d",&secim);
					if(secim==2){
						break;
					}
				}
	        }else if( islem == 5 ) {
	        	maclari_oku();
	        	printf("\nAna menuye donuluyor\n");
	        }else if( islem == 6 ) {
	        	hepsini_buyut();
	        	printf("\nAna menuye donuluyor\n");
	        }else if( islem == 7 ) {
	        	hepsini_kucult();
	        	printf("\nAna menuye donuluyor\n");
	        }
	        else{
	        	printf("\nIslem kodu gecersiz tekrar deneyiniz\n");
	        }
	    }
    }printf("\nProgram Sonlandi\n");
	return 0;
}

                         // öğrenci no:181213053
                         // öğrenci ad:Ayşe Beyza Soyad: Ünal
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>

int main(int argc,char *argv[]){
       int Asure=atoi(argv[1]), Bsure=atoi(argv[2]);
	struct timespec begin;
        struct timespec end;
	srand(time(NULL)); 
	int rdeger =rand()%100;
	int first=0;
        int last=99;   
	int tahmind1=0,tahmind2=0;
	double diff,toplam_sure=0;
    FILE *dosya=fopen("oyun_181213053.txt","w+");;
    fprintf(dosya,"rdeger=%d\n A=%d B=%d \n",rdeger,Asure,Bsure);
	while(rdeger!=tahmind1 || rdeger!=tahmind2){
		    if(tahmind2==0) first=0;
			else first=tahmind2;
			if(tahmind1==0) last=99;
			else last=tahmind1;
		clock_gettime(CLOCK_MONOTONIC,&begin);
		printf("oyuncu 1 [%d-%d] arasinda deger gir:",first,last);
	       scanf("%d",&tahmind1);
               clock_gettime(CLOCK_MONOTONIC,&end);
               diff=(end.tv_sec-begin.tv_sec)*1e9;               
	       diff=(diff+(end.tv_nsec-begin.tv_nsec))*1e-9;
	       toplam_sure+=diff;
		if(toplam_sure>Bsure){
			printf("sure bitti! kazanan yok");
			fprintf(dosya,"Süre bitti. Kazanan yok.\n");
			break;
		}
	    fprintf(dosya,"oyuncu 1 tahmin: %d\n",tahmind1);
		if(rdeger==tahmind1 || diff>Asure){
		    printf("oyuncu 1 kaybetti\n"); 
		    fprintf(dosya,"oyuncu 1 gecen sure:%lf ms\n",diff*1000);
			fprintf(dosya,"kazanan:oyuncu 2\n");
			printf("oyuncu 1 gecen sure:%f ms \n",diff*1000);
			break;
	    }
	    else if(rdeger!=tahmind1 || diff>Asure){
	    	if(tahmind1>last || tahmind1<first){
	    		printf("HATA. oyuncu 1 kaybetti.\n");
	    		fprintf(dosya,"oyuncu 1 gecen sure:%f ms \n",diff*1000);
				fprintf(dosya,"Kazanan:oyuncu 2\n");
				 break;
			}
			else{
				fprintf(dosya,"oyuncu 1 gecen sure:%f ms\n",diff*1000);
				printf("Yanlis. oyuncu 1 gecen sure: %f ms\n",diff*1000);
				if(tahmind2==0) first=0;
				else first=tahmind2;
				last=tahmind1;
				//time (&basla);
                                clock_gettime(CLOCK_MONOTONIC,&begin);
	    	    printf("oyuncu 2 [%d-%d] arasında deger gir:",first,last);
		        scanf("%d",&tahmind2);
		       // time (&bit);
                //fark = difftime(bit, basla);
                clock_gettime(CLOCK_MONOTONIC,&end);
                diff=(end.tv_sec-begin.tv_sec)*1e9;
                diff=(diff+(end.tv_nsec-begin.tv_nsec))*1e-9;
                toplam_sure+=diff;
		        fprintf(dosya,"oyuncu 2 tahmin: %d\n",tahmind2);
		        fprintf(dosya,"oyuncu 2 gecen sure: %f ms\n",diff*1000);
		        if(tahmind2>last || tahmind2<first){
		        	printf("HATA! oyuncu 2 kaybetti.\n"); 
		        	printf("oyuncu 2 gecen sure:%f ms\n",diff*1000);
		        	fprintf(dosya,"kazanan: oyuncu 1\n");
					break;
		        	
				}
				else if(tahmind2==rdeger ||diff>Asure ){
					printf("oyuncu 2 kaybetti.\n");
					printf("oyuncu 2 gecen sure:%f\n ms",diff*1000);
					fprintf(dosya,"kazanan: oyuncu 1\n");
					break;
				}
				printf("yanlis. oyuncu 2 gecen sure:%f\n ms",diff*1000);
			}
		}
	}	
	fprintf(dosya,"toplam sure:%lf ms \n",toplam_sure*1000);
	fclose(dosya);
	printf("rdeger:%d toplam sure:%lf ms",rdeger,toplam_sure*1000);
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>


int main(int argc,char *argv[]){
    //    int Asure=atoi(argv[1]), Bsure=atoi(argv[2]);
	struct timespec begin;
    struct timespec end;
	int Asure=3,Bsure=20;
	srand(time(NULL)); 
	int rdeger =50;
	int first=0;
    int last=99;   
	int tahmind1=0,tahmind2=0;
	//time_t basla,bit;
	double fark,toplam_sure=0;
    double diff;
    FILE *dosya=fopen("oyun_181213053.txt","w+");;
    fprintf(dosya,"rdeger=%d\n A=%d B=%d \n",rdeger,Asure,Bsure);
	while(rdeger!=tahmind1 || rdeger!=tahmind2){
		    if(tahmind2==0) first=0;
			else first=tahmind2;
			if(tahmind1==0) last=99;
			else last=tahmind1;
		//time(&basla);
		int clock_getir(CLOCK_MONOTONIC,&begin);
		printf("oyuncu 1 [%d-%d] arasinda deger gir:",first,last);
	    scanf("%d",&tahmind1);
	   // time (&bit);
        //fark = difftime(bit, basla);
        clock_getir(CLOCK_MONOTONIC,&end);
        diff=(end.tv_sec-begin.tv_sec)*1e9;               
		 diff=(diff+(end.tv_nsec-begin.tv_nsec))*1e-9;
		toplam_sure+=fark;
		if(toplam_sure>Bsure){
			printf("sure bitti! kazanan yok");
			fprintf(dosya,"Süre bitti. Kazanan yok.\n");
			break;
		}
	    fprintf(dosya,"oyuncu 1 tahmin: %d\n",tahmind1);
		if(rdeger==tahmind1 || fark>Asure){
		    printf("oyuncu 1 kaybetti\n"); 
		    fprintf(dosya,"oyuncu 1 gecen sure:%lf\n",fark*1000);
			fprintf(dosya,"kazanan:oyuncu 2\n");
			printf("oyuncu 1 gecen sure:%f\n",diff);
			break;
	    }
	    else if(rdeger!=tahmind1 || fark>Asure){
	    	if(tahmind1>last || tahmind1<first){
	    		printf("HATA. oyuncu 1 kaybetti.\n");
	    		fprintf(dosya,"oyuncu 1 gecen sure:%f\n",diff);
				fprintf(dosya,"Kazanan:oyuncu 2\n");
				 break;
			}
			else{
				fprintf(dosya,"oyuncu 1 gecen sure:%f\n",diff);
				printf("Yanlis. oyuncu 1 gecen sure: %f \n",diff);
				if(tahmind2==0) first=0;
				else first=tahmind2;
				last=tahmind1;
				//time (&basla);
	    	    printf("oyuncu 2 [%d-%d] arasýnda deger gir:",first,last);
		        scanf("%d",&tahmind2);
		       // time (&bit);
                //fark = difftime(bit, basla);
                int clock_getir(CLOCK_MONOTONIC,&end);
                diff=(end.tv_sec-begin.tv_sec)*1e9;
                diff=(diff+(end.tv_nsec-begin.tv_nsec))*1e-9;
                toplam_sure+=fark;
		        fprintf(dosya,"oyuncu 2 tahmin: %d\n",tahmind2);
		        fprintf(dosya,"oyuncu 2 gecen sure: %f \n",diff);
		        if(tahmind2>last || tahmind2<first){
		        	printf("HATA! oyuncu 2 kaybetti.\n"); 
		        	printf("oyuncu 2 gecen sure:%f\n",diff);
		        	fprintf(dosya,"kazanan: oyuncu 1\n");
					break;
		        	
				}
				else if(tahmind2==rdeger || fark>Asure ){
					printf("oyuncu 2 kaybetti.\n");
					printf("oyuncu 2 gecen sure:%f\n",diff);
					fprintf(dosya,"kazanan: oyuncu 1\n");
					break;
				}
				printf("yanlis. oyuncu 2 gecen sure:%f\n",diff);
			}
		}
	}	
	fprintf(dosya,"toplam sure:%lf\n",toplam_sure*1000);
	fclose(dosya);
	printf("rdeger:%d toplam sure:%lf",rdeger,toplam_sure*1000);
	return 0;
}

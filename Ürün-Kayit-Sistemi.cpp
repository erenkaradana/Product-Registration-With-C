#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct urun{
	char ad[20],sktt[20];
	int no;
	
}urun;


int main(){
	
	FILE *filep;
	filep=fopen("kayit.dat","w+");
	char sec;
	urun x;
	
	anamenu:
		printf("\t\nURUN KAYIT PROGRAMI\t\t");
		printf("\nUrun eklemek icin  basiniz\t\t(1)\n");
		printf("\nUrun bulmak icin  basiniz\t\t(2)\n");
		printf("\nUrunleri listelemek icin  basiniz\t\t(3)\n");
		sec=getche();
		switch(sec){
			case '1':
				if(fopen("kayit.dat","ab")==NULL){
					printf("dosya acilamadi");
					break;
				}
				do{
					printf("\n\turun no,ad ve sktt giriniz\n\t\n");
					scanf("%d %s %s",&x.no,x.ad,x.sktt);
					fwrite(&x,sizeof(urun),1,filep);
	
					printf("\n\tkayita devam etmek icin e tusuna basiniz\n\t");
					
				}while(getche()=='e');
				fclose(filep);
				break;
			case '2':
				if(fopen("kayit.dat","rb")==NULL){
					printf("dosya acilamadi");
					break;
				}
				int n;
				printf("\n\tbulunacak urun nosunu giriniz\n\t");
				scanf("%d",&n);
				
				
				do{
					fseek(filep,sizeof(urun)*(n-1),SEEK_SET);
					if(fread(&x,sizeof(urun),1,filep)==1){
						printf("\n\t%d. urun-->\n",n);
						printf("\n\tAd:%s\n",x.ad);
						printf("\n\tNumara:%d\n",x.no);
						printf("\n\tSon Kullaným Tarihi:%s\n",x.sktt);
						
					}
					else{
						printf("\n\tboyle bir urun yok\n\t");
						printf("\n\tkayit islemine devam etmek icin e giriniz\n\t");
					}
					
				}while(getche()=='e');
				fclose(filep);
				break;
				
			case '3':
				if(fopen("kayit.dat","rb")==NULL){
					printf("dosya acilamadi");
					break;
				}
				while(fread(&x,sizeof(urun),1,filep)==1){
					n++;
					printf("\n\t%d. urun->\n\t",n);
					printf("\n\tUrun no:%d\n\t",x.no);
					printf("\n\tUrun ad:%s\n\t",x.ad);
					printf("\n\tUrun sktt:%s\n\t",x.sktt);
					
					
				}	
				fclose(filep);
				break;
				default: printf("\n\nGecersiz secim yaptiniz\n\n");
				
				}
				
		printf("\nanamenuye donmek icin e basiniz\n");
		if(getche()=='e'){
			system("cls");
			goto anamenu;
		}
		printf("uygulamadan cikmak icin herhangi bir tusa basiniz");
		getch();
		return 0;		
		
		
					
}

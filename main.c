#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float serbestDusme(float *g, float *t){

     return 0.5*(*g)*(*t)*(*t);
     }
float yukariAtis(float *v0, float *g){

     return ((*v0)*(*v0))/(2*(*g));
}
float agirlik(float *m, float *g){

    return (*m)*(*g);
}
float kutlecekimselPotansiyelEnerji(float *m, float *g, float *h){

   return (*m)*(*g)*(*h);
}
float hidrostatikBasinc(float *p,float *g, float *h){

 return (*p)*(*g)*(*h);
}
float arsimetKaldirmaKuvveti(float *p, float *g, float *V){

 return (*p)*(*g)*(*V);
}
float basitSarkacPeriyodu(float *L, float *g){

 return 2*3.14*sqrt((*L)/(*g));
}
float sabitIpGerilmesi(float *m,float *g){

return (*m)*(*g);
}
float asansor( float *m, float *g, float *a, int *yon){

  if(*yon==1){
    return (*m)*((*g)+(*a));
  }
 else if(*yon== -1){

    return (*m)*((*g)-(*a));
 }
 else{
    return -1.0;
 }
}
int main()
{
    char biliminsani[60];
    int secim,yon;
    float sonuc;
    float h,t,v0,m,p,V,L,a;
    float g[8]={3.7,8.87,9.8,3.7,25.8,10.44,8.69,11.15};

    printf("---Uzay Simulasyonuna Hosgeldiniz---\n\n");
    printf("Bir bilim insani ismi giriniz: ");
    gets(biliminsani);
    printf("\n");

    printf("1: %s Serbest Dusme Deneyi\n", biliminsani);
    printf("2: %s Yukari Atis Deneyi\n", biliminsani);
    printf("3: %s Agirlik Deneyi\n", biliminsani);
    printf("4: %s Kutlecekimsel Potansiyel Enerji Deneyi\n", biliminsani);
    printf("5: %s Hidrostatik Basinc Deneyi\n", biliminsani);
    printf("6: %s Arsimet Kaldirma Kuvveti Deneyi\n", biliminsani);
    printf("7: %s Basit Sarkac Periyodu Deneyi\n", biliminsani);
    printf("8: %s Sabit Ip Gerilmesi Deneyi\n", biliminsani);
    printf("9: %s Asansor Deneyi\n\n", biliminsani);


    while(1){
    printf("Yapmak istediginiz deneyin numarasini giriniz(-1 cikis): ");
    scanf("%d", &secim);

     if(secim== -1){
        break;
     }

    switch(secim){
      case 1:
          printf("--- %s Serbest Dusme Deneyine Hosgeldiniz---\n\n", biliminsani);

          printf("Saniye cinsinden sure giriniz: ");
          scanf("%f", &t);

          t=(t<0)? -t:t;

          for(int i=0;i<8;i++){
            sonuc=serbestDusme((g+i), &t);
            printf("%d. gezegende cismin kat ettigi yol %.2f Metredir.\n", i+1, sonuc);
          }
          break;
      case 2:
          printf("--- %s Yukari Atis Deneyine Hosgeldiniz---\n\n", biliminsani);

          printf("Cismin firlatildigi ilk hizi m/s cinsinden giriniz: ");
          scanf("%f", &v0);

          v0=(v0<0)? -v0:v0;

          for(int i=0;i<8;i++){
            sonuc=yukariAtis(&v0,(g+i));
            printf("%d. gezegende cismin cikabilecegi maksimum yukseklik %.2f Metredir.\n", i+1, sonuc);
         }
         break;
      case 3:
          printf("--- %s Agirlik Deneyine Hosgeldiniz---\n\n", biliminsani);

          printf("Cismin kutlesini kilogram cinsinden giriniz: ");
          scanf("%f", &m);

          m=(m<0)?-m:m;

          for(int i=0;i<8;i++){
            sonuc=agirlik(&m, (g+i));
            printf("%d. gezegende agirlik %.2f Newtondur.\n", i+1,sonuc);
          }
          break;
      case 4:
          printf("--- %s Kutlecekimsel Potansiyel Enerji Deneyine Hosgeldiniz---\n\n", biliminsani);

          printf("Kilogram cinsinden cismin kutlesini giriniz: ");
          scanf("%f",&m);

          printf("Metre cinsinden cismin bulundugu yuksekligi giriniz: ");
          scanf("%f", &h);

          m=(m<0)? -m:m;
          h=(h<0)? -h:h;

          for(int i=0;i<8;i++){
            sonuc=kutlecekimselPotansiyelEnerji(&m,(g+i),&h);
            printf("%d. gezegende cismin kutlecekimsel potansiyel enerjisi %.2f Joule'dur.\n", i+1,sonuc);
          }
          break;
      case 5:
          printf("--- %s Hidrostatik Basinc Deneyine Hosgeldiniz---\n\n", biliminsani);

          printf("Sivinin birim hacmindeki kutlesini kg/m*3 cinsinden giriniz: ");
          scanf("%f", &p);

          printf("Sivinin derinligini metre cinsinden giriniz: ");
          scanf("%f", &h);

          p=(p<0)? -p:p;
          h=(h<0)? -h:h;

          for(int i=0;i<8;i++){
            sonuc=hidrostatikBasinc(&p,(g+i),&h);
            printf("%d. gezegende %.2f derinliginde cismin yuzeyine uyguladigi hidrostatik basinc %.2f Pascaldir.\n",i+1,h,sonuc);
          }
          break;
      case 6:
          printf("--- %s Arsimet Kaldirma Kuvveti Deneyine Hosgeldiniz---\n\n", biliminsani);

          printf("Sivinin birim hacmindeki kutlesini kg/m*3 cinsinden giriniz: ");
          scanf("%f", &p);

          printf("Cismin batan hacminin m*3 cinsinden giriniz: ");
          scanf("%f", &V);

          p=(p<0)? -p:p;
          V=(V<0)? -V:V;

          for(int i=0;i<8;i++){
            sonuc=arsimetKaldirmaKuvveti(&p,(g+i),&V);
            printf("%d. gezegende sivi icerisindeki cisme uygulanan kaldirma kuvveti %.2f Newtondur.\n",i+1,sonuc);
            }
            break;

      case 7:
          printf("--- %s Basit Sarkac Periyodu Deneyine Hosgeldiniz---\n\n", biliminsani);

          printf("Sarkacin uzunlugunu metre cinsinden giriniz: ");
          scanf("%f", &L);

          L=(L<0)? -L:L;

          for(int i=0;i<8;i++){
            sonuc=basitSarkacPeriyodu(&L, (g+i));
            printf("%d. gezegende sarkacin periyodu %.2f saniyedir.\n",i+1,sonuc);
          }
          break;
      case 8:
          printf("--- %s Sabit Ip Gerilmesi Deneyine Hosgeldiniz---\n\n", biliminsani);

          printf("Cismin kutlesini kilogram cinsinden giriniz: ");
          scanf("%f",&m);

          m=(m<0)?-m:m;

          for(int i=0;i<8;i++){
            sonuc=sabitIpGerilmesi(&m,(g+i));
            printf("%d. gezegende ipin gerilme kuvveti %.2f Newtondur.\n",i+1,sonuc);
          }
         break;
      case 9:
          printf("--- %s Asansor Deneyine Hosgeldiniz---\n\n", biliminsani);

          printf("Cismin kutlesini kilogram cinsinden giriniz: ");
          scanf("%f", &m);

          printf("Asansorun ivmesini m/s*2 cinsinden giriniz: ");
          scanf("%f", &a);

          m=(m<0)? -m:m;
          a=(a<0)? -a:a;

          printf("\nAsansor yukari yonde ivmelenerek hizlaniyorsa veya asagi yonde ivmelenerek yavasliyorsa 1 giriniz.\n");
          printf("Asansor asagi yonde ivmelenerek hizlaniyorsa veya yukari yonde ivmelenerek yavasliyorsa -1 giriniz.\n");

          printf("Bir yon seciniz: ");
          scanf("%d", &yon);

          if(yon==1){
            for(int i=0;i<8;i++){
                sonuc=asansor(&m,(g+i),&a,&yon);
                printf("%d. gezegende cismin etkin agirligi %.2f Newtondur.\n", i+1,sonuc);
            }
          }
          else if(yon==-1){
                for(int i=0;i<8;i++){
                sonuc=asansor(&m,(g+i),&a,&yon);
                printf("%d. gezegende cismin etkin agirligi %.2f Newtondur.\n", i+1,sonuc);
            }
        }
          else{
             printf("Hatali yon girdiniz lutfen 1 veya -1 seciniz.\n");
        }
         break;
      default:
        printf("Gecersiz bir deney numarasi girdiniz.Lutfen 1-9 arasi bir numara giriniz!");
}

}




    return 0;
}

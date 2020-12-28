#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float calculated_frequencies[20];
float distances [2]={0,0};

void filter_str(char m[]){

  for(int i=0;m[i]!='\0';i++){ //NULL karakterine ulasana kadar i'yi bir arttir

  m[i]=tolower(m[i]); //buyuk harfleri kucuk harfe donustur

      while(!(m[i]>='a' && m[i]<='z') && (m[i]!=' ')){ //a-z arasi ve bosluk karakteri harici
        m[i]=' '; // karakterleri bosluga cevir

  }
}

printf("\n\n%s",m);

}


void calculate_frequencies_bi(char m[]){

const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};

printf("\n\n");

    for(int k=0;k<10;k++){

  char *matrix_bigram_strings_ptr=&matrix_bigram_strings[k];

  int i=0,j=0;
  float sayac=0;

  while(m[i]!='\0'){
    if(m[i]==matrix_bigram_strings_ptr[j]){ //eger bigramin ilk karakteri metinle eslesirse
    //aramaya devam et
      while(m[i]==matrix_bigram_strings_ptr[j] && m[i]!='\0' ){
        i++;
        j++;
      }
      if(j==strlen(matrix_bigram_strings_ptr)) //eger aranan bigramin uzunlugu metnin uzunluguyla eslesirse
      sayac++; //sayaci bir arttir

    }

      {
            if(m[i] == '\0')  //eger metnin son karakterine ulasmissa
            break; //donguyu kir
      }
      i++;
      j=0; //dongunun devam etmesi icin sayaci sifirlar
  }


float frekans[10];


frekans[k]=sayac/100;



      printf("\n%s bigramin frekansi: %.2f",matrix_bigram_strings_ptr, frekans[k]);

calculated_frequencies[k]=frekans[k]; //frekans degerlerini calculated_frequencies'in ilk 10 indisine ata
}




}

void calculate_frequencies_tri(char m[]){

const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};

printf("\n\n");


    for(int k=0;k<10;k++){

  char *matrix_trigram_strings_ptr=&matrix_trigram_strings[k];

  int i=0,j=0;

  float sayac=0;



  while(m[i]!='\0'){
    if(m[i]==matrix_trigram_strings_ptr[j]){ //eger trigramin ilk karakteri metinle eslesirse
    //aramaya devam et
      while(m[i]==matrix_trigram_strings_ptr[j] && m[i]!='\0' ){
        i++;
        j++;
      }
      if(j==strlen(matrix_trigram_strings_ptr)) //aranan trigramin uzunlugu metnin uzunluguyla eslesirse
      sayac++; //sayaci bir arttir

    }
      {
            if(m[i] == '\0')
            break;
      }
      i++;
      j=0;
  }

float frekans[10];

frekans[k]=sayac/100;

 printf("\n%s trigramin frekansi: %.2f",matrix_trigram_strings_ptr, frekans[k]);


calculated_frequencies[k+10]=frekans[k];   //frekans degerlerini calculated_frequencies'in son 10 indisine ata


}
}

void calculate_distances(){

const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };

const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };

float ing_mes[20];
float alm_mes[20];

float ing_toplam=0;
float alm_toplam=0;

for(int i=0;i<20;i++){

if(calculated_frequencies[i]==0.00) //eger calculated_frequencies degeri 0.00'a esitse
continue; //atla

ing_mes[i] = sqrt(pow((calculated_frequencies[i]-frequency_eng[i]),2.00)); //iki dizi arasindaki uzaklik

ing_toplam+=ing_mes[i]; //uzakliklarin toplami

alm_mes[i] = sqrt(pow((calculated_frequencies[i]-frequency_germ[i]),2.00));

alm_toplam+=alm_mes[i];

}

distances[0]=ing_toplam; // ing_toplam degerini distances dizisinin 0. indisine ata
distances[1]=alm_toplam;  // alm_toplam degerini distances dizisinin 1. indisine ata

}

void detect_lang(){
printf("\n\n");

  if(distances[0]>distances[1]) //eger ingilizce diline olan uzaklik > almanca diline olan uzakliksa
  printf("Girdiginiz metin ingilizce");

  if(distances[1]>distances[0]) //eger almanca diline olan uzaklik > ingilizce diline olan uzakliksa
  printf("Girdiginiz metin almanca");

}


int main()

{

   char metin[10000];

    printf("metini giriniz: ");

    fgets(metin,sizeof(metin),stdin);


    filter_str(metin);

     calculate_frequencies_bi(metin);

    calculate_frequencies_tri(metin);

    calculate_distances();

     detect_lang();

     return 0;

 }

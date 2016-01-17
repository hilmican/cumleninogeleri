#include <stdio.h>
#include <string.h>
#include "fiiller.h"

void ogelerine_ayir(char cumle[]);
char *fiil_soylu_yuklem_bul(char cumle[]);


int main()
{
   	char cumle[500];
   	printf("Cümle giriniz. : \r\n");
	while (fgets(cumle, sizeof(cumle), stdin) != 0)
	{
	    printf("Girilen cümle: %s", cumle);
	    ogelerine_ayir(cumle);
	    printf("Cümle giriniz. : \r\n");
	}
	return(0);
}

void ogelerine_ayir(char cumle[])
{
	char *fiil_soylu_yuklem;
	printf("Cumlenin ogeleri:%s\r\n", cumle);

	//burada cok basit sekilde yüklemi bulmaya çalışacağım.
	//ileride yuh.. bu nasıl bir yöntem... olur mu böyle şey demeyin.
	//akşam canım sıkıldı ve bu projeye başladım :) daha iyi bir yol bulursanız, bilirseniz yapın lütfen :) herkese açık.
	
	//yüklem fiil ya da isim soylu olurmuş. Ben fiil soylu yüklemleri bulmak için fonksiyon yazıyorum.
	fiil_soylu_yuklem_bul(cumle);
	//printf("Fiil soylu yüklem:%s\r\n", fiil_soylu_yuklem);

}

char *fiil_soylu_yuklem_bul(char cumle[])
{
	int i = 0;
	char *incelenecek_nokta;
	//cumlede fiil var mi?
	//bunun icin bir fiil listesi kullanayım ve cümlenin içerisinde fiil var mı araştırayım.
	
	//bu fonksiyon icin özür diliyorum. arayin her bir elemanı için strstr den başka bir çözüm aklıma gelmedi.. bi yolu olsa gerek ama..
	while (fiiller[i] != NULL)
	{
		if (strstr(cumle, fiiller[i]))
		{
			printf("Bu fiil var:%s\r\n", fiiller[i]);
			//var olan fiil gerçekten fiil mi yoksa cümle içerisinde mi geçmiş?
			//burada birazcık salladım ama.. arada geçmişse fiil değildir, fiil kökünün başta olması gerekit.
			//bunun anlamıda ya cümlenin ilk kelimesi olacak ya da önünde boşluk olacak.
			incelenecek_nokta = strstr(cumle, fiiller[i]);
			if(incelenecek_nokta == cumle)
			{
				printf("Bu kelime cumlenin ilk ogesi, fiil olabilir.\r\n");
			}
			if(incelenecek_nokta != cumle)
			{
				printf("İncelenecek noktanın bir öncesi:\"%c\"\r\n", *(incelenecek_nokta-1));
				if(*(incelenecek_nokta-1) == ' ')
				{
					printf("izlenecek noktanın bir öncesi boşluk olduğundan bu fiil olabilir :%s\n", incelenecek_nokta);
				}

			}
		}
		else
		{
			//olmayanları yazmaya gerek yok
			//printf("Bu fiil yok%s\r\n", fiiller[i]);
		}
		i++;
	}
	return "fiil_soylu_yuklem";
}
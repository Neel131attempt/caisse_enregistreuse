#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>



int main ()
{

srand(time(NULL)) ;

double Montant  = 0.00 ;
int flag = 1 ; // avec bool sa ne marcher pas alors j'ai oppter pour un petit 'pseudo-bool'
double MontantDonne = 0.00;
double echange = 0.00;
int RandomNum = 0;
RandomNum = (rand() % 200000) + 1; // j'ai mis un gros montant en prevision des prochaines etapes du code et aussi acause de l'inflation et au supermarcher ces prix sont realistique :(
				   //
Montant = RandomNum / 20.00 ; // en plus j'ai vue la convertion d'un int vers un double est plus facile que de generer un random double.

while (flag == 1) {
	printf("vous devez payer Rs%.2lf, Combien donnez vous ?\n", Montant);
	scanf("%lf",&MontantDonne);

if (MontantDonne > Montant)
{
	flag = 0;
	printf("merci, nous calculons la monnaie sur ce montant \n");
}else{
	printf("vous n'avez pas donner assez. pouvez vous donner plus ?");
}

}

return 0;
	
}

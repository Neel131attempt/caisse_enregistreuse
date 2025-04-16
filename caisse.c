#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

double CalculeMonnaie(double Montant, double MontantDonne)
{
	return (MontantDonne - Montant);
}

int main ()
{

srand(time(NULL)) ;

double Montant  = 0.00 ;
int Flag = 1 ; // avec bool sa ne marcher pas alors j'ai oppter pour un petit 'pseudo-bool'
double MontantDonne = 0.00;
int RandomNum = 0;
double Monnaie = 0.00;

RandomNum = (rand() % 200000) + 1; // j'ai mis un gros montant en prevision des prochaines etapes du code et aussi acause de l'inflation et au supermarcher ces prix sont realistique :(
				   //
Montant = RandomNum / 20.00 ; // en plus j'ai vue la convertion d'un int vers un double est plus facile que de generer un random double.


while (Flag == 1) {
	printf("vous devez payer Rs%.2lf, Combien donnez vous ?\n", Montant);
	scanf("%lf",&MontantDonne);

if (MontantDonne > Montant)
{
	Flag = 0;
	printf("merci, nous calculons la monnaie sur ce montant \n");
}else{
	printf("vous n'avez pas donner assez. pouvez vous donner plus ?");
}

}

Monnaie = CalculeMonnaie(Montant, MontantDonne);
printf("Monnaie a rendre : Rs%.2lf \n", Monnaie);

// section pour les billets et les pieces 

double Billets[7] = {2000, 1000, 500, 200, 100, 50, 25};
int BilletsUtilise[7] = {0};
int BilletsRestant[7] = {2,2,2,2,4,4,8};

double Pieces[7] = {20.00,10.00,5.00,1.00,0.50,0.20,0.05};
int PiecesUtilise[7] = {0};
int PiecesRestant[7] = {2,2,2,2,4,10};
int CaisseVide = 1;
int choix = 0;

//Affichage
for (int x = 0; x < 7; ++x){
printf("Rs%.2lf : %d \n", Billets[x], BilletsRestant[x]);
printf("Rs%.2lf : %d \n", Pieces[x], PiecesRestant[x]);
}


//calculation


while (CaisseVide == 1){

for (int x; x < 7 ; ++x){
	while (BilletsRestant[x] > 0){
		while (Monnaie >= Billets[x]) {
				Monnaie = Monnaie - Billets[x];
				BilletsUtilise[x] = BilletsUtilise[x] + 1; 
				BilletsRestant[x] = BilletsRestant[x] - 1;
				printf("on a utiliser : Rs%.2lf et il reste %d Billets \n", Billets[x], BilletsRestant[x]);
		}
	}
}

for (int x; x < 7 ; ++x){
	while (PiecesRestant[x] > 0){
		while (Monnaie >= Pieces[x] - 0.00000000001) {
				Monnaie = Monnaie - Pieces[x];
				PiecesUtilise[x] = PiecesUtilise[x] + 1;
				PiecesRestant[x] = PiecesRestant[x] - 1;
				printf("on a utiliser : Rs%.2lf et il reste %d piecess \n", Pieces[x], PiecesRestant[x]);
		}
	}
}
if (Monnaie >= 0.05){
	printf("voulez-vous remplir la caisse encore (tapez 1) ou Arreter maintenant (tapez 2)?\n ");
	scanf("%d", &choix);

	if (choix == 1){
for (int x = 0 ; x < 7 ; ++x) {
	BilletsRestant[x] = 4 ;
	PiecesRestant[x] = 4;
}
}
else if (choix == 2) {
	CaisseVide = 0;
}
else{
	printf("vous devez mettre entre 1 et 2 uniquement !!!");
}
}
//Affichage
printf("vous avez recu en billets: \n");

for (int x = 0; x < 7; ++x){
		printf("Rs%.2lf : %d \n", Billets[x], BilletsUtilise[x]);
}

printf("vous avez recu en pieces: \n");
for (int x = 0; x < 7; ++x){
		printf("Rs%.2lf : %d \n", Pieces[x], PiecesUtilise[x]);
}

	return 0;


}

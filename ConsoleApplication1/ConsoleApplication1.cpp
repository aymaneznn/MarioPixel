#include<SDL.h> //ne pas oublier
#include<SDL_ttf.h> //ne pas oublier
#include<iostream>
#include "config_sdl.h"
#include <fstream>


using namespace std;

int const CARRE = 30;
int const petit = 30;

int const LARGEUR = 12;
int const HAUTEUR = 16;
int const TAILLEY = CARRE * HAUTEUR;
int const TAILLEX = CARRE * LARGEUR + 120;
const char* nom_fichier = "Mystere.txt";

void charger(const char* nom_fichier, SDL_Color tabcouleur[HAUTEUR][LARGEUR]) {
	char lettres;
	ifstream entree(nom_fichier, ios::in);
	if (!entree)
		cout << "Probleme d'ouverture \n";
	else {
		cout << "pas de probleme \n";
		for (int i = 0; i < HAUTEUR; i++) {
			for (int j = 0; j < LARGEUR; j++) {
				entree >> lettres;

				if (lettres == 'B') {
					tabcouleur[i][j] = { 255, 255, 255 };
				}
				else if (lettres == 'N') {
					tabcouleur[i][j] = { 0, 0, 0 };
				}
				if (lettres == 'R') {
					tabcouleur[i][j] = { 255, 0, 0 };
				}
				if (lettres == 'V') {
					tabcouleur[i][j] = { 106, 164, 30 };
				}
				if (lettres == 'J') {
					tabcouleur[i][j] = { 255, 255, 0 };
				};

			}
		}
	}
}

void affiche(SDL_Color tabcouleur[HAUTEUR][LARGEUR], SDL_Renderer* rendu) {
	for (int i = 0; i < HAUTEUR; i++) {
		for (int j = 0; j < LARGEUR; j++) {
			SDL_Rect rectmario;
			rectmario.x = j * CARRE;
			rectmario.y = i * CARRE;
			rectmario.w = CARRE;  //largeur
			rectmario.h = CARRE;  //hauteur

			
			SDL_SetRenderDrawColor(rendu, tabcouleur[i][j].r, tabcouleur[i][j].g, tabcouleur[i][j].b, 255);  //pinceau vert
			SDL_RenderFillRect(rendu, &rectmario); //on trace un rectangle plein

		}


	}
	SDL_RenderPresent(rendu); //sinon on ne voit rien

}

void negative(SDL_Renderer* rendu, SDL_Color tabcouleur[HAUTEUR][LARGEUR]) {
	for (int i = 0; i < HAUTEUR; i++) {
		for (int j = 0; j < LARGEUR; j++) {
			SDL_Rect rect;
			rect.x = j * CARRE;
			rect.y = i * CARRE;
			rect.w = CARRE;  //largeur
			rect.h = CARRE;  //hauteur
			SDL_SetRenderDrawColor(rendu, 255-tabcouleur[i][j].r, 255-tabcouleur[i][j].g, 255-tabcouleur[i][j].b, 255);  //pinceau vert
			SDL_RenderFillRect(rendu, &rect); //on trace un rectangle plein

		}


	}
	
	

}

void effacer(SDL_Renderer* rendu) {
	SDL_Rect rect; //on définit le rectangle à tracer
				   //SDL_Rect est un type struct	
	rect.x = 0;  //coin en haut à gauche
	rect.y = 0;  //coin en haut à gauche
	rect.w = 440;		//largeur
	rect.h = 480;		//hauteur
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);	//pinceau vert
	SDL_RenderFillRect(rendu, &rect); //on trace un rectangle plein
}


int main(int argn, char* argv[]) {//entête imposée
								  //ouverture de la SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Echec à l’ouverture";
		return 1;
	}
	//on ouvre la police de caractères
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("C:\\Windows\\Fonts\\calibri.ttf", 25);

	//on crée la fenêtre
	SDL_Window* win = SDL_CreateWindow("Titre de la fenetre",
		SDL_WINDOWPOS_CENTERED,     //pos. X: autre option: SDL_WINDOWPOS_UNDEFINED
		SDL_WINDOWPOS_CENTERED,     //pos. Y: autre option: SDL_WINDOWPOS_UNDEFINED 
		640, 			//largeur en pixels			
		480, 			//hauteur en pixels
		SDL_WINDOW_SHOWN //d’autres options (plein ecran, resizable, sans bordure...)
	);
	if (win == NULL)
		cout << "erreur ouverture fenetre";
	//Création d’un dessin associé à la fenêtre (1 seul renderer par fenetre)
	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,  //nom de la fenêtre
		-1, //par défaut
		SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommandée

	SDL_Color tabcouleur[HAUTEUR][LARGEUR]; // tableau qui stock les lettres pour les couleurs
	charger(nom_fichier, tabcouleur);
	affiche(tabcouleur, rendu);

	//tracer un rectangle
	SDL_Rect rect; //on définit le rectangle à tracer
				   //SDL_Rect est un type struct	
	rect.x = 600;  //coin en haut à gauche
	rect.y = 50;  //coin en haut à gauche
	rect.w = 30;		//largeur
	rect.h = 30;		//hauteur
	SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);	//pinceau vert
	SDL_RenderFillRect(rendu, &rect); //on trace un rectangle plein

	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255); //pinceau blanc
	SDL_RenderDrawRect(rendu, &rect); //on trace un rectangle vide

		//tracer un 2 eme rectangle
	SDL_Rect rect2; //on définit le rectangle à tracer
				   //SDL_Rect est un type struct	
	rect2.x = 600;  //coin en haut à gauche
	rect2.y = 10;  //coin en haut à gauche
	rect2.w = 30;		//largeur
	rect2.h = 30;		//hauteur
	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);	//pinceau vert
	SDL_RenderFillRect(rendu, &rect2); //on trace un rectangle plein

	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255); //pinceau blanc
	SDL_RenderDrawRect(rendu, &rect2); //on trace un rectangle vide

	// rect 3

	SDL_Rect rect3; //on définit le rectangle à tracer
				   //SDL_Rect est un type struct	
	rect3.x = 600;  //coin en haut à gauche
	rect3.y = 90;  //coin en haut à gauche
	rect3.w = 30;		//largeur
	rect3.h = 30;		//hauteur
	SDL_SetRenderDrawColor(rendu, 160, 100, 255, 255);	//pinceau vert
	SDL_RenderFillRect(rendu, &rect3); //on trace un rectangle plein

	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255); //pinceau blanc
	SDL_RenderDrawRect(rendu, &rect2); //on trace un rectangle vide

	SDL_Rect noir; //on définit le rectangle à tracer
			   //SDL_Rect est un type struct	
	noir.x = 600;  //coin en haut à gauche
	noir.y = 130;  //coin en haut à gauche
	noir.w = 30;		//largeur
	noir.h = 30;		//hauteur
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);	//pinceau noir
	SDL_RenderFillRect(rendu, &noir); //on trace un rectangle plein

	SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255); //pinceau blanc
	SDL_RenderDrawRect(rendu, &noir); //on trace un rectangle vide

	//on met à jour le rendu - FONCTION CAPITALE
	SDL_RenderPresent(rendu); //sinon on ne voit rien

	int couleur = 0;

	/*************BOUCLE D'evenements**************/
	bool continuer = true;   //booléen fin de programme
	SDL_Event event;//gestion des évènements souris/clavier, 
					//SDL_Event est de type struct
	while (continuer)
	{
		SDL_WaitEvent(&event);//attente d’un évènement
		switch (event.type) //test du type d’évènement
		{
		case SDL_QUIT: //clic sur la croix de fermeture
					   //on peut enlever SDL_Delay
			continuer = false;
			break;
		case SDL_MOUSEBUTTONUP://appui souris
			if (event.button.button == SDL_BUTTON_LEFT) {//si on clique bouton gauche
				if (event.button.x > rect.x && event.button.x<rect.x + rect.w && event.button.y>rect.y && event.button.y < rect.y + rect.h) { //dans 	le rectangle
					couleur = 1;
				}
				if (event.button.x > rect2.x && event.button.x<rect2.x + rect.w && event.button.y>rect2.y && event.button.y < rect2.y + rect2.h) { //dans 	le rectangle
					couleur = 2;
				}
				if (event.button.x > rect3.x && event.button.x<rect3.x + rect.w && event.button.y>rect3.y && event.button.y < rect3.y + rect3.h) { //dans 	le rectangle
					couleur = 3;
				}

				if (event.button.x > noir.x && event.button.x<noir.x + rect.w && event.button.y>noir.y && event.button.y < noir.y + noir.h) { //dans 	le rectangle
					couleur = 4;
				}

			}
			// break;
			

				if (couleur == 1) {

					int x = event.button.x;
					int y = event.button.y;
					SDL_Rect position;
					position.h = position.w = petit;
					if (x < CARRE * LARGEUR && y < CARRE * HAUTEUR) {
						cout << "avant x : " << x << endl;
						x /= petit;
						cout << "apres x : " << x << endl;
						y /= petit;
						position.x = x * petit;
						cout << "position x : " << position.x << endl;
						position.y = y * petit;
					}
					SDL_SetRenderDrawColor(rendu, 0, 255, 0, 255);	//pinceau vert
					SDL_RenderFillRect(rendu, &position); //on trace un rectangle plein


				}

				if (couleur == 2) {

					int x = event.button.x;
					int y = event.button.y;
					SDL_Rect position;
					position.h = position.w = petit;
					if (x < CARRE * LARGEUR && y < CARRE * HAUTEUR) {
						x /= petit;
						y /= petit;
						position.x = x * petit;
						position.y = y * petit;
					}
					SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);	//pinceau vert
					SDL_RenderFillRect(rendu, &position); //on trace un rectangle plein

				}

				if (couleur == 3) {

					int x = event.button.x;
					int y = event.button.y;
					SDL_Rect position;
					position.h = position.w = petit;
					if (x < CARRE * LARGEUR && y < CARRE * HAUTEUR) {
						x /= petit;
						y /= petit;
						position.x = x * petit;
						position.y = y * petit;
					}
					
					SDL_SetRenderDrawColor(rendu, 160, 100, 255, 255);	//pinceau vert
					SDL_RenderFillRect(rendu, &position); //on trace un rectangle plein

				}

				if (couleur == 4) {

					int x = event.button.x;
					int y = event.button.y;
					SDL_Rect position;
					position.h = position.w = petit;
					if (x < CARRE * LARGEUR && y < CARRE * HAUTEUR) {
						x /= petit;
						y /= petit;
						position.x = x * petit;
						position.y = y * petit;
					}

					SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);	//pinceau vert
					SDL_RenderFillRect(rendu, &position); //on trace un rectangle plein

				}


				SDL_RenderPresent(rendu);//on rafraichit
			
			
			break;


		case SDL_KEYDOWN:
			
			if (event.key.keysym.sym == SDLK_j) { //touche j
				SDL_SetRenderDrawColor(rendu, rand() % 255, rand() % 255, rand() % 255, 255);
				SDL_RenderDrawLine(rendu, rand() % 600, 0, rand() % 600, 480);
				SDL_RenderPresent(rendu);
				
			}
			if (event.key.keysym.sym == SDLK_n) {
				
				negative(rendu, tabcouleur);
			}

			if (event.key.keysym.sym == SDLK_p) {
				effacer(rendu);
				
			}
				SDL_RenderPresent(rendu); //sinon on ne voit rien
	
			
			break;

		}
	}



	//destruction du renderer à la fin
	SDL_DestroyRenderer(rendu);
	//destruction à la fin
	SDL_DestroyWindow(win);   //equivalent du delete

	TTF_CloseFont(font); //on ferme la font
	TTF_Quit(); //on quitte la TTF


	//fermeture
	SDL_Quit();
	return 0;
}
//test test
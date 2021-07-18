#pragma once
struct horario
{   
	int hora = 0;
	int minuto = 0;
};

struct quest�es
{
	short int dificuldade = 0;
	horario Inicio;   
	horario Fim;   
};

struct m�dia
{
	float dificuldade = 0;
	float tempo = 0;
};

struct participantes
{
	char nome[20];
	quest�es* ponteiro;
};

//Ler tipo horario com cin e exibir com cout 
istream& operator >> (istream& is, horario& h);
ostream& operator << (ostream& os, horario& h);
//Subtrair tipo horario com o operador de subtra��o, operator-().
int operator-(horario h, horario m);



//prot�tipos das fun��es
char escreveCaractere(char ch, int n);
void PorParticipante(quest�es* vetorQuest�es, int quantidadequestoes);
void PorQuest�o(participantes* participante, int quant, int numQuestoes);
m�dia retornaMedia(quest�es* quest�o, int tamanhoVetor, int IndiceElemento, int TamanhoPasso);
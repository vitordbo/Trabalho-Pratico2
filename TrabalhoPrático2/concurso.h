#pragma once
struct horario
{   
	int hora = 0;
	int minuto = 0;
};

struct questões
{
	short int dificuldade = 0;
	horario Inicio;   
	horario Fim;   
};

struct média
{
	float dificuldade = 0;
	float tempo = 0;
};

struct participantes
{
	char nome[20];
	questões* ponteiro;
};

//Ler tipo horario com cin e exibir com cout 
istream& operator >> (istream& is, horario& h);
ostream& operator << (ostream& os, horario& h);
//Subtrair tipo horario com o operador de subtração, operator-().
int operator-(horario h, horario m);



//protótipos das funções
char escreveCaractere(char ch, int n);
void PorParticipante(questões* vetorQuestões, int quantidadequestoes);
void PorQuestão(participantes* participante, int quant, int numQuestoes);
média retornaMedia(questões* questão, int tamanhoVetor, int IndiceElemento, int TamanhoPasso);
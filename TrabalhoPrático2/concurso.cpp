#include <iostream>
using namespace std;
#include <iomanip>  // usar para poder corrigir os zeros = > setw e setfill
#include "concurso.h"

istream &operator >> (istream &is, horario &h)
{
	// usar tipo horario com cin
	char dp; // receber com os dois pontos  
	cin >> h.hora >> dp >> h.minuto;
	return is;
}

ostream &operator << (ostream &os, horario &h)   
{
	cout << setw(2) << setfill('0');  // solu��o encontrada para exibir os numeros de forma corrreta => sem perder nenhum 0 na escrita => como em 10:00
	// usar tipo horario com cout 
	os << h.hora;
	os << ":";       // escrever com os dois pontos  
	cout << setw(2) << setfill('0');
	os << h.minuto;
	cout << setw(2) << setfill('0');
	return os;
}

int operator-(horario h, horario m)  
{
	//h de hora m de minutos
	// usar - com o tipo horario 
	return (h.hora - m.hora) * 60 + (h.minuto - m.minuto);
	// por ex => 15:20 as 15:45 => 15 - 15 => (0 * 60) + 45 - 20 => 0 + 25 = 25
}

char escreveCaractere(char ch, int n)
{
	// escreve o caractere desejado na quantidade escolhida 
	int i = 0;
	while (i < n)
	{
		cout << ch;
		i++;
	}
	cout << endl;
	return 0;
}

void PorParticipante(quest�es *vetorQuest�es, int quantidadequestoes)
{
	// mostra o resumo por participante => sem mostrar o nome do participante 
	// uma vez para cada participante 
	for (int i = 0; i < quantidadequestoes; i++)
	{
		cout << "\n\t" << char('A' + i);   // letra da quest�o
		cout << " (" << (vetorQuest�es + i)->dificuldade << ") "; // dificuldade da quest�o
		cout << (vetorQuest�es + i)->Inicio << " �s " << (vetorQuest�es + i)->Fim;  // horario inicial e horario final da quest�o
		cout << " (" << (vetorQuest�es + i)->Fim - (vetorQuest�es + i)->Inicio << "min)"; // diferen�a entre os horarios 		
	}
}

void PorQuest�o(participantes* participante, int quant, int numQuestoes) 
{
	// fun��o criada para exbir o resumo por quest�o
	// parecida com a fun��o PorParticipante
	for (int i = 0; i < (numQuestoes); i++)
	{
		cout << "\t" << (participante + i)->nome; // nome do participante
		cout << " (" << ((participante + i)->ponteiro + quant)->dificuldade << ") "; // dificuldade da quest�o 
		cout << ((participante + i)->ponteiro + quant)->Inicio << " �s " << ((participante + i)->ponteiro + quant)->Fim; // horario inicial e horario final da quest�o
		cout << " (" << ((participante + i)->ponteiro + quant)->Fim - ((participante + i)->ponteiro + quant)->Inicio << "min)"; // diferen�a entre os horarios 
		cout << endl;
	}
}


m�dia retornaMedia(quest�es* quest�o, int tamanhoVetor, int IndiceElemento, int TamanhoPasso)
{
	m�dia MediaParaSerRetornada;  // criando variavel que vai receber os dados e retornar para a fun��o principal 

	for (int i = IndiceElemento; i < tamanhoVetor; i += TamanhoPasso)
	{
		MediaParaSerRetornada.dificuldade += (quest�o + i)->dificuldade;     //somatorio => se for mais de uma dificuldade (mais de uma quest�o) 
		MediaParaSerRetornada.tempo += (quest�o + i)->Fim - (quest�o + i)->Inicio;  // somatorio => se for mais de um tempo (mais de uma quest�o) 
	}
	
	MediaParaSerRetornada.dificuldade = MediaParaSerRetornada.dificuldade / TamanhoPasso;   // dificuldade geral dividida pelo tamanho do passo (para obter o �ndice do pr�ximo elemento)
	MediaParaSerRetornada.tempo = MediaParaSerRetornada.tempo / TamanhoPasso;      // tempo geral dividido pelo tamanho do passo (para obter o �ndice do pr�ximo elemento)

	return MediaParaSerRetornada;
}



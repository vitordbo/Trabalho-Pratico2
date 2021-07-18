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
	cout << setw(2) << setfill('0');  // solução encontrada para exibir os numeros de forma corrreta => sem perder nenhum 0 na escrita => como em 10:00
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

void PorParticipante(questões *vetorQuestões, int quantidadequestoes)
{
	// mostra o resumo por participante => sem mostrar o nome do participante 
	// uma vez para cada participante 
	for (int i = 0; i < quantidadequestoes; i++)
	{
		cout << "\n\t" << char('A' + i);   // letra da questão
		cout << " (" << (vetorQuestões + i)->dificuldade << ") "; // dificuldade da questão
		cout << (vetorQuestões + i)->Inicio << " às " << (vetorQuestões + i)->Fim;  // horario inicial e horario final da questão
		cout << " (" << (vetorQuestões + i)->Fim - (vetorQuestões + i)->Inicio << "min)"; // diferença entre os horarios 		
	}
}

void PorQuestão(participantes* participante, int quant, int numQuestoes) 
{
	// função criada para exbir o resumo por questão
	// parecida com a função PorParticipante
	for (int i = 0; i < (numQuestoes); i++)
	{
		cout << "\t" << (participante + i)->nome; // nome do participante
		cout << " (" << ((participante + i)->ponteiro + quant)->dificuldade << ") "; // dificuldade da questão 
		cout << ((participante + i)->ponteiro + quant)->Inicio << " às " << ((participante + i)->ponteiro + quant)->Fim; // horario inicial e horario final da questão
		cout << " (" << ((participante + i)->ponteiro + quant)->Fim - ((participante + i)->ponteiro + quant)->Inicio << "min)"; // diferença entre os horarios 
		cout << endl;
	}
}


média retornaMedia(questões* questão, int tamanhoVetor, int IndiceElemento, int TamanhoPasso)
{
	média MediaParaSerRetornada;  // criando variavel que vai receber os dados e retornar para a função principal 

	for (int i = IndiceElemento; i < tamanhoVetor; i += TamanhoPasso)
	{
		MediaParaSerRetornada.dificuldade += (questão + i)->dificuldade;     //somatorio => se for mais de uma dificuldade (mais de uma questão) 
		MediaParaSerRetornada.tempo += (questão + i)->Fim - (questão + i)->Inicio;  // somatorio => se for mais de um tempo (mais de uma questão) 
	}
	
	MediaParaSerRetornada.dificuldade = MediaParaSerRetornada.dificuldade / TamanhoPasso;   // dificuldade geral dividida pelo tamanho do passo (para obter o índice do próximo elemento)
	MediaParaSerRetornada.tempo = MediaParaSerRetornada.tempo / TamanhoPasso;      // tempo geral dividido pelo tamanho do passo (para obter o índice do próximo elemento)

	return MediaParaSerRetornada;
}



#include <iostream>
#include <windows.h>
#include <iomanip> 
using namespace std;
#include "concurso.h"

int main()
{
	SetConsoleCP(1252); // entrada
	SetConsoleOutputCP(1252); // saída

	cout << escreveCaractere('*', 60);
	cout << "Concurso de Programação " << endl;

	cout << "\nQual o número de participantes? ";
	int Quantparticipantes;   
	cin >> Quantparticipantes; 

	cout << "Qual o número de questões? ";
	int numeroquestoes;
	cin >> numeroquestoes;
	cout << endl;
	cout << escreveCaractere('*', 60);
	cin.ignore(); // para usar o cin.getine e o cin mais na frente 

	// criando os vetores dinâmicos
	questões* vetorQuestões = new questões[(Quantparticipantes * numeroquestoes)];   // vetor do tipo questões de tamanho => participantes * número de questões 
	participantes* vetorparticipantes = new participantes[Quantparticipantes];  // vetor do tipo participantes de tamanho => quantidade de participantes 

	int trocaParticipante = 0;
    // para atribuir os dados da forma que foi citada nas instruções
    for (int i = 0 ; i < (numeroquestoes * Quantparticipantes); i += numeroquestoes)  
	{
		(vetorparticipantes + trocaParticipante)->ponteiro = (vetorQuestões + i);  
		// ponteiro que foi criado na struct participantes vai receber a quantidade de questões =>
		// i só vai parar quando for maior que o tamanho do vetor questões => fazendo com que cada elemento do vetor de participantes
		// contenha o nome do participante e o endereço onde iniciam suas informações no vetor de questões =>
		// da forma que foi mencionado no arquivo do trabalho 
		trocaParticipante++;	
	}


	//lendo do ususario 
	for (int i = 0; i < Quantparticipantes; i++)
	{
		cout << escreveCaractere('-', 14);
		cout << "Participante: ";
		cin.getline((vetorparticipantes+i)->nome, 20); // Lê o nome do participante => cin.getline para pegar nome e sobrenome
		cout << escreveCaractere('-', 14);
		cout << endl;

		for (int quest = 0; quest < numeroquestoes; quest++)
		{
			cout << "Questão " << char('A' + quest) << endl;   // letra da questão => vai para B na próxima repetição do for 
			cout << "\tDificuldade: "; 
			cin >> ((vetorparticipantes + i)->ponteiro + quest)->dificuldade; //lendo a dificuldade 
			cout << "\tInicio: ";
			cin >> ((vetorparticipantes + i)->ponteiro + quest)->Inicio;     // lendo a hora (metade inicial)
			cout << "\tFim: ";
			cin >> ((vetorparticipantes + i)->ponteiro + quest)->Fim;        // lendo a hora (metade final)
			
	
			cin.ignore(); // estava dando erro ao receber o outro nome
	
        }
		cout << escreveCaractere('-', 14);
		cout << endl;
	}

	cout << escreveCaractere('-', 14);
	escreveCaractere('*', 60);
	escreveCaractere('-', 28);

	// mostrando o resumo por participante
	cout << "Resumo por participante\n";
	escreveCaractere('-', 28);

	for (int i = 0; i < Quantparticipantes; i++)
	{
		setw(2);
		cout << vetorparticipantes[i].nome << ":";  // mostra o nome pois a função não deve mostrar 
		PorParticipante((vetorparticipantes+i)->ponteiro, numeroquestoes);  // função que mostra o resumo por participante => sem mostrar o nome 
		cout << endl;
    }
	
	escreveCaractere('-', 19);
	cout << endl;
    escreveCaractere('-', 19);


	// mostrando o resumo por questão
	cout << "Resumo por questão\n";
	escreveCaractere('-', 19); 
	
	for (int i = 0; i < numeroquestoes; i++)
	{
		cout << "Questao " << char('A' + i) << ":" << endl; // letra da questão => vai para B na próxima repetição do for 
		// função que não está nas instruções do trabalho, mas que foi criada para facilitar a exibição 
		PorQuestão(vetorparticipantes, i, numeroquestoes);  // função que mostra o resumo por questão
	}

	escreveCaractere('-', 20);
	cout << endl << endl;
	escreveCaractere('-', 12);
	cout << "Estatísticas " << endl;
	escreveCaractere('-', 12);


	// mostrando a media
	// criando variaveis tipo media para guardar o retorno da função retornaMedia
	média questãoAB;   // questões individuais 
	média Concurso;    // concurso no geral 

	cout << fixed;
	std::cout.precision(2);  // para exibir com duas casas decimais 
	
	for (int contador = 0; contador < numeroquestoes; contador++)
	{
		questãoAB =  retornaMedia(vetorQuestões, Quantparticipantes * numeroquestoes, contador, numeroquestoes);
		 // exibindo as medias de dificuldade e tempo das questões de forma individual 
		 cout << "Questao " << char('A' + contador) << ": Dificuldade";   // letra da questão => vai para B na próxima repetição do for 
		 cout << " (" << questãoAB.dificuldade << ")";  // exibindo o valor que foi retornado pela função e armazenado em questãoAB
		 cout << " - Tempo (" << questãoAB.tempo << " minutos)" << endl; // exibindo o valor que foi retornado pela função e armazenado em questãoAB

		 Concurso.dificuldade += questãoAB.dificuldade; // somatorio das dificuldades para o concurso geral 
		 Concurso.tempo += questãoAB.tempo;    // somatorio do tempo para o concurso geral
	}

	// exibindo as medias de dificuldade e tempo do concurso de forma geral 
	cout << "Concurso:  Dificuldade";
	cout << " (" << (Concurso.dificuldade / numeroquestoes) << ")" << " - ";   // dificuldade de todas as questões dividido pelo número de questões 
	cout << "Tempo (" << (Concurso.tempo / numeroquestoes) << " minutos)\n" << endl;   // tempo de todas as questões dividido pelo número de questões 
	cout << escreveCaractere('*', 60);

	system("Pause");

	// deletando os dois 
	delete[]vetorparticipantes;   
	delete[]vetorQuestões;

	return 0;

}


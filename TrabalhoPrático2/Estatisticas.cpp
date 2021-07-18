#include <iostream>
#include <windows.h>
#include <iomanip> 
using namespace std;
#include "concurso.h"

int main()
{
	SetConsoleCP(1252); // entrada
	SetConsoleOutputCP(1252); // sa�da

	cout << escreveCaractere('*', 60);
	cout << "Concurso de Programa��o " << endl;

	cout << "\nQual o n�mero de participantes? ";
	int Quantparticipantes;   
	cin >> Quantparticipantes; 

	cout << "Qual o n�mero de quest�es? ";
	int numeroquestoes;
	cin >> numeroquestoes;
	cout << endl;
	cout << escreveCaractere('*', 60);
	cin.ignore(); // para usar o cin.getine e o cin mais na frente 

	// criando os vetores din�micos
	quest�es* vetorQuest�es = new quest�es[(Quantparticipantes * numeroquestoes)];   // vetor do tipo quest�es de tamanho => participantes * n�mero de quest�es 
	participantes* vetorparticipantes = new participantes[Quantparticipantes];  // vetor do tipo participantes de tamanho => quantidade de participantes 

	int trocaParticipante = 0;
    // para atribuir os dados da forma que foi citada nas instru��es
    for (int i = 0 ; i < (numeroquestoes * Quantparticipantes); i += numeroquestoes)  
	{
		(vetorparticipantes + trocaParticipante)->ponteiro = (vetorQuest�es + i);  
		// ponteiro que foi criado na struct participantes vai receber a quantidade de quest�es =>
		// i s� vai parar quando for maior que o tamanho do vetor quest�es => fazendo com que cada elemento do vetor de participantes
		// contenha o nome do participante e o endere�o onde iniciam suas informa��es no vetor de quest�es =>
		// da forma que foi mencionado no arquivo do trabalho 
		trocaParticipante++;	
	}


	//lendo do ususario 
	for (int i = 0; i < Quantparticipantes; i++)
	{
		cout << escreveCaractere('-', 14);
		cout << "Participante: ";
		cin.getline((vetorparticipantes+i)->nome, 20); // L� o nome do participante => cin.getline para pegar nome e sobrenome
		cout << escreveCaractere('-', 14);
		cout << endl;

		for (int quest = 0; quest < numeroquestoes; quest++)
		{
			cout << "Quest�o " << char('A' + quest) << endl;   // letra da quest�o => vai para B na pr�xima repeti��o do for 
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
		cout << vetorparticipantes[i].nome << ":";  // mostra o nome pois a fun��o n�o deve mostrar 
		PorParticipante((vetorparticipantes+i)->ponteiro, numeroquestoes);  // fun��o que mostra o resumo por participante => sem mostrar o nome 
		cout << endl;
    }
	
	escreveCaractere('-', 19);
	cout << endl;
    escreveCaractere('-', 19);


	// mostrando o resumo por quest�o
	cout << "Resumo por quest�o\n";
	escreveCaractere('-', 19); 
	
	for (int i = 0; i < numeroquestoes; i++)
	{
		cout << "Questao " << char('A' + i) << ":" << endl; // letra da quest�o => vai para B na pr�xima repeti��o do for 
		// fun��o que n�o est� nas instru��es do trabalho, mas que foi criada para facilitar a exibi��o 
		PorQuest�o(vetorparticipantes, i, numeroquestoes);  // fun��o que mostra o resumo por quest�o
	}

	escreveCaractere('-', 20);
	cout << endl << endl;
	escreveCaractere('-', 12);
	cout << "Estat�sticas " << endl;
	escreveCaractere('-', 12);


	// mostrando a media
	// criando variaveis tipo media para guardar o retorno da fun��o retornaMedia
	m�dia quest�oAB;   // quest�es individuais 
	m�dia Concurso;    // concurso no geral 

	cout << fixed;
	std::cout.precision(2);  // para exibir com duas casas decimais 
	
	for (int contador = 0; contador < numeroquestoes; contador++)
	{
		quest�oAB =  retornaMedia(vetorQuest�es, Quantparticipantes * numeroquestoes, contador, numeroquestoes);
		 // exibindo as medias de dificuldade e tempo das quest�es de forma individual 
		 cout << "Questao " << char('A' + contador) << ": Dificuldade";   // letra da quest�o => vai para B na pr�xima repeti��o do for 
		 cout << " (" << quest�oAB.dificuldade << ")";  // exibindo o valor que foi retornado pela fun��o e armazenado em quest�oAB
		 cout << " - Tempo (" << quest�oAB.tempo << " minutos)" << endl; // exibindo o valor que foi retornado pela fun��o e armazenado em quest�oAB

		 Concurso.dificuldade += quest�oAB.dificuldade; // somatorio das dificuldades para o concurso geral 
		 Concurso.tempo += quest�oAB.tempo;    // somatorio do tempo para o concurso geral
	}

	// exibindo as medias de dificuldade e tempo do concurso de forma geral 
	cout << "Concurso:  Dificuldade";
	cout << " (" << (Concurso.dificuldade / numeroquestoes) << ")" << " - ";   // dificuldade de todas as quest�es dividido pelo n�mero de quest�es 
	cout << "Tempo (" << (Concurso.tempo / numeroquestoes) << " minutos)\n" << endl;   // tempo de todas as quest�es dividido pelo n�mero de quest�es 
	cout << escreveCaractere('*', 60);

	system("Pause");

	// deletando os dois 
	delete[]vetorparticipantes;   
	delete[]vetorQuest�es;

	return 0;

}


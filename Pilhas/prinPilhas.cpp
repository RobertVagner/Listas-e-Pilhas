#include <iostream>
using namespace std;

class Pilha
{
private:
	struct no
	{
		int info;
		no* prox;
	}*P;
public:
	Pilha()
	{
		P = NULL;
	}
	void push(int);
	int pop();
	void mostra();
	char empty();
	int total();
};

void Pilha::push(int x)
{
	no* aux = new no;
	aux->info = x;
	aux->prox = P;
	P = aux;
}

int Pilha::pop()
{
	int x;
	if (P)
	{
		no* aux = P;
		P = P->prox;
		x = aux->info;
		delete aux;
	}

	return x;
}

char Pilha::empty()
{
	return P == NULL;
}

void Pilha::mostra()
{
	int x;
	cout << "[";
	while (P != NULL)
	{
		x = P->info;
		cout << P->info;
		if (P->prox != NULL)
			cout << ",";
		P = P->prox;
	}
	cout << "]";
}

int Pilha::total()
{
	int s = 0;
	no* aux = P;
	while (P != NULL)
	{
		s = s + aux->info;
		P = P->prox;
	}
	return s;
}

int main()
{
	Pilha *P1 = new Pilha();
	P1->push(5);
	P1->push(8);
	P1->push(10);
	P1->push(45);
	P1->push(13);
	P1->pop();
	P1->push(7);

	//cout << P1->pop() << endl;
	/*while (not P1->empty())
	{
		cout << P1->pop() << endl;
	}*/

	P1->mostra();

	return 1;
}
#include <iostream>
using namespace std;
float soma(float num1, float num2)
{
	return num1 + num2;
}
float subtracao(float num1, float num2)
{
	return num1 - num2;
}
float multiplicacao(float num1, float num2)
{
	return num1 * num2;
}
float divisao(float num1, float num2)
{
	return num1 / num2;
}
float potencia(float num1, float num2)
{
	float resultado = 1;
	for (int i = 0; i < num2; i++)
	{
		resultado = resultado * num1;
	}
	return resultado;
}
float porcentagem(float num1, float num2)
{
	return num2 * num1 / 100;
}
float fatorial(float num)
{
	float resultado = 1;
	while (num > 1)
		resultado = resultado * num--;
	return resultado;
}
float cosseno(float num)
{
	float rad = num * 3.1415 / 180;
	int den = 2;
	float resultado = 1 / 1;
	int sinal = -1;
	for (int i = 0; i < 10; i++)
	{
		resultado += (potencia(rad, den) / fatorial(den)) * sinal;
		sinal *= -1;
		den += 2;
	}
	return resultado;
}
float seno(float num)
{
	float rad = num * 3.1415 / 180;
	int den = 1;
	float resultado = 0;
	int sinal = -1;
	for (int i = 0; i < 10; i++)
	{
		resultado += (potencia(rad, den) / fatorial(den)) * sinal;
		sinal *= -1;
		den += 2;
	}
	return resultado * sinal;
}
float operacoesResultado(char operacaoSelecionada, float input1, float input2)
{
	switch (operacaoSelecionada)
	{
	case '+':
		system("COLOR 90");
		printf("\nSomando %.2f com %.2f resultou em: %.2f\n", input1, input2, soma(input1, input2));
		return soma(input1, input2);

	case '-':
		system("COLOR 90");
		printf("\nSubtraindo %.2f de %.2f resultou em: %.2f\n", input2, input1, subtracao(input1, input2));
		return subtracao(input1, input2);

	case '*':
	case 'x':
	case 'X':
		system("COLOR 90");
		printf("\nMultiplicando %.2f por %.2f resultou em: %.2f\n", input1, input2, multiplicacao(input1, input2));
		return multiplicacao(input1, input2);

	case ':':
	case '/':
	case '\\':
		system("COLOR 90");
		printf("Dividindo %.0f por %.0f resultou em: %.0f\n", input1, input2, divisao(input1, input2));
		return divisao(input1, input2);

	case '~':
	case '^':
		system("COLOR 90");
		printf("\nO numero %.2f elevado a %.2f resultou em: %.2f\n", input1, input2, potencia(input1, input2));
		return potencia(input1, input2);

	case '%':
		system("COLOR 90");
		printf("\n%.2f porcento de %.2f resultou em: %.2f\n", input2, input1, porcentagem(input1, input2));
		return porcentagem(input1, input2);

	case 's':
	case 'S':
		system("COLOR 90");
		printf("\nO seno do numero %.2f resultou em: %.4f\n", input1, seno(input1));
		return seno(input1);

	case 'c':
	case 'C':
		system("COLOR 90");
		printf("\nO cosseno do numero %.2f resultou em: %.4f\n", input1, cosseno(input1));
		return cosseno(input1);

	default:
		printf("\n*****Opcao invalida, tente novamente*****\n");
		break;
	}
}

int main(int argc, char const *argv[])
{
	float input1, input2;
	float resultado = 0;
	char input, operacaoSelecionada;

	do
	{
		system("COLOR F0");
		printf("\t\t\t=============******=============\n");
		printf("\t\t\t Qual operacao deseja realizar?\n");
		printf("\t\t\t=============******=============\n\n\n");
		printf("\t\t  (+) Adicao            \t(* ou x) Multiplicacao\n\n");
		printf("\t\t  (-) Subtracao         \t(: ou / ou \\) Divisao\n\n");
		printf("\t\t  (%%) Porcentagem           \t(^ ou ~) Potencia \n\n");
		printf("\t\t  (s) Seno              \t(c) Cosseno\n\n");

		printf("\nDigite o caracter ou simbolo correspondente a operacao a ser realizada:\n");
		scanf("%s", &operacaoSelecionada);

		if (resultado != 0)
		{
			if (operacaoSelecionada == '+' || operacaoSelecionada == '-' || operacaoSelecionada == '*' || operacaoSelecionada == 'x' || operacaoSelecionada == 'X' ||
				operacaoSelecionada == ':' || operacaoSelecionada == '/' || operacaoSelecionada == '\\' || operacaoSelecionada == '^' || operacaoSelecionada == '~' || operacaoSelecionada == '%')
			{
				printf("Digite um numero.\n");
				scanf("%f", &input1);
			}
		}
		else if (operacaoSelecionada == '+' || operacaoSelecionada == '-' || operacaoSelecionada == '*' || operacaoSelecionada == 'x' || operacaoSelecionada == 'X' ||
				 operacaoSelecionada == ':' || operacaoSelecionada == '/' || operacaoSelecionada == '\\' || operacaoSelecionada == '^' || operacaoSelecionada == '~')
		{
			printf("Digite um numero.\n");
			scanf("%f", &input1);
			printf("Digite outro numero.\n");
			scanf("%f", &input2);
		}
		else if (operacaoSelecionada == 's' || operacaoSelecionada == 'S' || operacaoSelecionada == 'c' || operacaoSelecionada == 'C')
		{
			printf("Digite um numero.\n");
			scanf("%f", &input1);
		}
		else if (operacaoSelecionada == '%')
		{
			printf("Digite um numero.\n");
			scanf("%f", &input1);
			printf("Digite agora quantos porcento voce quer desse numero.\n");
			scanf("%f", &input2);
		}
		if (resultado == 0)
		{
			resultado = operacoesResultado(operacaoSelecionada, input1, input2);
		}
		else
		{
			resultado = operacoesResultado(operacaoSelecionada, resultado, input1);
		}

		system("PAUSE");
		system("cls");
		system("color 90");
		printf("\n\n\t\t\t#***************************************#");
		printf("\n\n\t\t\tSe deseja fazer outra operacao digite 'S'");
		printf("\n\n\t\t\tSe deseja fechar a calculadora digite 'N'");
		printf("\n\n\t\t\tSe deseja zerar a calculadora digite 'Z'");
		printf("\n\n\t\t\t#***************************************#\n");
		printf("\n\n\t\t\t\t Deseja continuar?   ");
		scanf("%s", &input);
		if (input == 'z' || input == 'Z')
		{
			resultado = 0;
			input = 's';
		}
		system("cls");

	} while (input == 's' || input == 'S');
	return 0;
}



#include <stdbool.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//#include <exception>
//#include <new>

typedef struct Elemento
{
    struct Elemento *_proximo;
    void *_dado;
} Elemento;
typedef struct
{
    Elemento *_primeiro;
    int _quantidade;
} ListaEncadeada;

ListaEncadeada *iniciaListaEncadeada()
{

    ListaEncadeada *lista = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    lista->_primeiro = NULL;
    lista->_quantidade = 0;

    return (lista);
}

void adicionaNoInicio(ListaEncadeada *umaLista, void *umDado)
{
    //printf("\tadicionando no inicio    |  ");
    //printf("\tumDado: %p\n", umDado);
    Elemento *el = (Elemento *)malloc(sizeof(Elemento));
    //printf("\tendereço do novo elemento: %p\n", el);
    el->_dado = umDado;

    if (umaLista->_quantidade == 0)
    {
        umaLista->_primeiro = el;
        el->_proximo = NULL;
    }
    else
    {
        Elemento *antigo = umaLista->_primeiro;
        antigo->_dado = umaLista->_primeiro->_dado;
        //printf("\tdado do antigo: %p\n", antigo->_dado);
        antigo->_proximo = umaLista->_primeiro->_proximo;
        umaLista->_primeiro = el;
        el->_proximo = antigo;
    }
    umaLista->_quantidade = umaLista->_quantidade + 1;

    return;
}
bool listaVazia(ListaEncadeada *umaLista)
{
    return umaLista->_primeiro == NULL;
}
void destroiListaEncadeada(ListaEncadeada *umaLista)
{
    /*printf("\t| Destruindo lista encadeada |\n");
    printf("\t| Percorrendo toda a lista |\n");
    bool ultimo = true;
    bool primeiro = true;
    Elemento *percorre = (Elemento *)malloc(sizeof(Elemento));
    while (ultimo)
    {
        if (primeiro)
        {
            percorre = umaLista->_primeiro;
            printf("\tO primeiro elemento é %p", percorre);
            primeiro = false;
        }
        else
        {
            ultimo = false;
        }
    }*/
    free(umaLista);
    return;
}

bool contem(ListaEncadeada *umaLista, void *umDado)
{
    bool achou = false;
    //printf("\t\tprocurando se existe\n");
    Elemento *el = (Elemento *)malloc(sizeof(Elemento));
    for (int i = 0; i < umaLista->_quantidade; i++)
    {
        if (!(umaLista->_primeiro == NULL))
        {
            if (i == 0)
            {
                el = umaLista->_primeiro;
            }
            else
            {
                if ((el->_proximo != NULL))
                {
                    el = el->_proximo;
                }
                else
                {
                    return achou;
                }
            }
            //printf("\t\tel: %p / el.dado: %p\n", el, el->_dado);
            if (el->_dado == umDado)
            {
                achou = true;
                //printf("      opa, achei\n");
                return achou;
            }
            else
            {
                //printf("\t\tainda não achei\n");
            }
        }
    }
    free(el);
    return achou;
}
int posicao(ListaEncadeada *umaLista, void *umDado)
{
    //printf("\tVerficando Posicao | \n");
    //printf("\n");
    int i = 0;
    if (contem(umaLista, umDado))
    {
        //printf("\n");
        bool achou = false;
        Elemento *el = (Elemento *)malloc(sizeof(Elemento));

        for (i = 0; i < umaLista->_quantidade && !achou; i++)
        {
            if (i == 0)
            {
                el = umaLista->_primeiro;
            }
            else
            {
                if (!(el->_proximo == NULL))
                {
                    el = el->_proximo;
                }
                else
                {
                    return achou;
                }
            }
            //printf("\tel: %p / el.dado: %p\n", el, el->_dado);
            if (el->_dado == umDado)
            {
                achou = true;
                //printf("\topa, achei a posicao\n");
            }
            else
            {
                //printf("\tainda não achei a posicao\n");
            }
        }

        free(el);
    }
    return i - 1;
}
void adicionaNaPosicao(ListaEncadeada *umaLista, void *umDado, int umaPosicao)
{
    return;
}
void adicionaNoFim(ListaEncadeada *umaLista, void *umDado)
{
    return;
}
void *retiraDoInicio(ListaEncadeada *umaLista)
{
    return NULL;
}
void *retiraDaPosicao(ListaEncadeada *umaLista, int umaPosicao)
{
    return NULL;
}
void *retiraDoFim(ListaEncadeada *umaLista)
{
    return NULL;
}
void *retiraEspecifico(ListaEncadeada *umaLista, void *umDado)
{
    return NULL;
}

//implemente as funcoes da lista encadeada neste arquivo

int main()
{
    printf("\nInicio do Teste iniciaListaEncadeada\n");
    ListaEncadeada *p = iniciaListaEncadeada();
    printf("Lista é nula? %s\n", (p != NULL) ? "não - OK!" : "sim - ERRO!");
    printf("Lista está vazia? %d\n", listaVazia(p));
    //printf("\tDestruindo lista\n");
    destroiListaEncadeada(p);

    printf("\nInicio do Teste listaVazia\n");
    p = iniciaListaEncadeada();
    int d1 = 10;
    printf("A lista esta vazia? %s\n", listaVazia(p) ? "sim - OK" : "não - ERRO!");
    adicionaNoInicio(p, &d1);
    printf("A lista está vazia? %d\n", listaVazia(p) == 0);
    destroiListaEncadeada(p);

    printf("\nInicio do Teste adicionaNoInicio\n");
    p = iniciaListaEncadeada();
    int d2 = 20;
    int d3 = 30;
    adicionaNoInicio(p, &d1);
    printf("O tamanho da Lista é 1? %d\n", p->_quantidade == 1);
    printf("A lista contam d1? %d\n", contem(p, &d1) == true);
    printf("A posicao do d1? %d\n", posicao(p, &d1) == 1);
    adicionaNoInicio(p, &d2);
    printf("O tamanho da lista é 2? %d\n", p->_quantidade == 2);
    printf("A lista contem d2? %d\n", contem(p, &d2) == true);
    printf("A posicao de d2 é 1? %d\n", posicao(p, &d2) == 1);
    printf("A posicao de d1? %d\n", posicao(p, &d1) == 2);
    adicionaNoInicio(p, &d3);
    printf("O tamanho da lista é 3? %d\n", p->_quantidade == 3);
    printf("A lista contem d3? %d\n", contem(p, &d3) == true);
    printf("A posicao de d3 é 1? %d\n", posicao(p, &d3) == 1);
    printf("A posicao de d2 é 2? %d\n", posicao(p, &d2) == 2);
    printf("A posicao de d1 é 3? %d\n", posicao(p, &d1) == 3);
    destroiListaEncadeada(p);

    printf("\nInicio do Teste AdicionaNaPosicao\n");
    p = iniciaListaEncadeada();
    int d4 = 40;
    adicionaNaPosicao(p, &d1, 1);
    printf("O tamanho da lista é 1? %d\n", p->_quantidade == 1);
    printf("A posicção do d1 é 1? %d\n", posicao(p, &d1) == 1);
    adicionaNaPosicao(p, &d2, 2);
    printf("O tamanho da lista é 2? %d\n", p->_quantidade == 2);
    printf("A posicao do d2 é 2? %d\n", posicao(p, &d2) == 2);
    printf("A posicao do d1 é 1? %d\n", posicao(p, &d1) == 1);
    adicionaNaPosicao(p, &d3, 2);
    printf("O tamanho da lista é 3? %d\n", p->_quantidade == 3);
    printf("A posicao do d3 é 2? %d\n", posicao(p, &d3) == 2);
    printf("A posicao do d2 é 3? %d\n", posicao(p, &d2) == 3);
    printf("A posicao do d1 é 1? %d\n", posicao(p, &d1) == 1);
    adicionaNaPosicao(p, &d4, 3);
    printf("O tamanho da lista é 4? %d\n", p->_quantidade == 4);
    printf("A posicao do d4 é 3? %d\n", posicao(p, &d4) == 3);
    printf("A posicao do d3 é 2? %d\n", posicao(p, &d3) == 2);
    printf("A posicao d2 é 4? %d\n", posicao(p, &d2) == 4);
    printf("A posicao do d1 é 1? %d\n", posicao(p, &d1) == 1);
    destroiListaEncadeada(p);

    printf("\nInicio do Teste retiraDoInicio\n");
    p = iniciaListaEncadeada();
    int *r;
    adicionaNoInicio(p, &d3);
    adicionaNoInicio(p, &d2);
    adicionaNoInicio(p, &d1);
    r = (int *)retiraDoInicio(p);
    printf("Quem foi removido foi o d1? %d\n", *r == d1);
    printf("O tamanho da lista é 2? %d\n", p->_quantidade == 2);
    printf("A posicao do d2 é 1? %d\n", posicao(p, &d2) == 1);
    printf("A posicao do d3 é 2? %d\n", posicao(p, &d3) == 2);
    r = (int *)retiraDoInicio(p);
    printf("Quem foi removido foi o d2? %d\n", *r == d2);
    printf("O tamanho da lista é 1? %d\n", p->_quantidade == 1);
    printf("A posicao do d3 é 1? %d\n", posicao(p, &d3) == 1);
    r = (int *)retiraDoInicio(p);
    printf("Quem foi removido foi o d3? %d\n", *r == d3);
    printf("O tamanho da lista é 0? %d\n", p->_quantidade == 0);
    destroiListaEncadeada(p);

    printf("\nInicio do Teste retiraDaPosicao\n");
    p = iniciaListaEncadeada();
    int d5 = 50;
    adicionaNoInicio(p, &d5);
    adicionaNoInicio(p, &d4);
    adicionaNoInicio(p, &d3);
    adicionaNoInicio(p, &d2);
    adicionaNoInicio(p, &d1);
    r = (int *)retiraDaPosicao(p, 5);
    printf("Quem foi removido foi o d5? %d\n", *r == d5);
    printf("O tamanho da lista é 4? %d\n", p->_quantidade == 4);
    printf("A posicao do d2 é 2? %d\n", posicao(p, &d2) == 2);
    r = (int *)retiraDaPosicao(p, 3);
    printf("Quem foi removido foi o d3? %d\n", *r == d3);
    printf("O tamanho da lista é 3? %d\n", p->_quantidade == 3);
    printf("A posicao do d4 é 3? %d\n", posicao(p, &d4) == 3);
    r = (int *)retiraDaPosicao(p, 2);
    printf("Quem foi removido foi o d2? %d\n", *r == d2);
    printf("O tamanho da lista é 2? %d\n", p->_quantidade == 2);
    printf("A posicao do d4 é 2? %d\n", posicao(p, &d4) == 2);
    r = (int *)retiraDaPosicao(p, 1);
    printf("%d\n", *r == d1);
    printf("O tamanho da lista é 1? %d\n", p->_quantidade == 1);
    printf("A posicao do d4 é 1? %d\n", posicao(p, &d4) == 1);
    r = (int *)retiraDaPosicao(p, 1);
    printf("quem foi removido foi o d4? %d\n", *r == d4);
    printf("O tamanho da lista é 0? %d\n", p->_quantidade == 0);
    printf("A lista contem  d4? %d\n", contem(p, &d4) == false);
    destroiListaEncadeada(p);
}
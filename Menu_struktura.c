#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#define ilosc 50
#define size 20

void menu1(Klient *head)  /*! funkcja wyswietlajaca menu z opcjami odnosnie listy klientów*/
{

    char i;
    char p;

    do  /*! petla do..while*/
    {
        system("cls"); /*! wyczyszczenie konsoli*/
        printf("1. Wyswietl liste klientow\n");
        printf("2. Dodawanie klienta\n");
        printf("3. Usuwanie klienta\n");
        printf("4. Edytowanie klienta\n");
        printf("5. Zapisanie zmian\n");
        printf("6. Wczytanie\n");
        printf("0. Powrot\n\n");
        printf("Twoj wybor: "); /*! wyswietlenie opcji*/

        i = getchar(); /*! do i przypisywany jest pobrany klawisz*/
        getchar();  /*! pobranie klawisza od uzytkownika*/

        if (i == '1') Wyswietlenie(head);  /*! jezeli 1 wywołujey odpowiednia funkcje*/
        else if(i == '2')Dodawanie(&head);  /*! jezeli 2 wywołujey odpowiednia funkcje*/
        else if(i == '3')Usuwanie(head);  /*! jezeli 3 wywołujey odpowiednia funkcje*/
        else if(i == '4')Edytowanie(&head);  /*! jezeli 4 wywołujey odpowiednia funkcje*/
        else if(i == '5')Zapisywanie(head);  /*! jezeli 5 wywołujey odpowiednia funkcje*/
        else if(i == '6')Wczytanie(&head);  /*! jezeli 6 wywołujey odpowiednia funkcje*/
        else if(i == '0') /*! jezelie 0*/
        {

            printf("Zapisac zmiany?\n1.Tak\n2.Nie\n"); /*! wyswietlenie komunikatu*/
            do /*! petla do..while*/
            {
                printf("Twoj wybor: "); /*! wyswietlenie komunikatu*/
                p = getchar(); /*! do i przypisywany jest pobrany klawisz*/
                getchar();  /*! pobranie klawisza od uzytkownika*/
                if(p == '1') /*! jezeli 1*/
                {
                    Zapisywanie(head); /*! wywołanie odpowiednie funckji*/
                    break; /*! wyjscie z petli*/
                }
                else if(p == '2')break; /*! jezeli 2 wyjscie z petli*/
                printf("Podano zla odpowiedz.\n"); /*! wyswietlenie komunikatu*/
            }
            while(p!='1' || p!='2'); /*! dopóki i jest rozne o 1 lub 2*/

        }
    }
    while (i != '0'); /*! dopoki i nie jest 0*/
}
void menu2(Film *head)  /*! funkcja wyswietlajaca menu z opcjami odnosnie listy filmow*/
{

    char i;
    char p;

    do  /*! petla do while*/
    {
        system("cls"); /*! wyczyszczenie konsoli*/
        printf("1. Wyswietl filmy\n");
        printf("2. Dodawanie filmu\n");
        printf("3. Usuwanie filmu\n");
        printf("4. Edytowanie filmu\n");
        printf("5. Zapisanie zmian\n");
        printf("6. Wczytanie\n");
        printf("7. Szukanie filmu\n");
        printf("8. Sortowanie\n");
        printf("0. Powrot\n\n");
        printf("Twoj wybor: "); /*! wyswietlenie opcji*/

        i = getchar(); /*! do i przypisywany jest pobrany klawisz*/
        getchar(); /*! pobranie klawisza od uzytkownika*/

        if (i == '1') Wyswietlenie2(head);  /*! jezeli 1 wywołujey odpowiednia funkcje*/
        else if(i == '2')Dodawanie2(&head); /*! jezeli 2 wywołujey odpowiednia funkcje*/
        else if(i == '3')Usuwanie2(head); /*! jezeli 3 wywołujey odpowiednia funkcje*/
        else if(i == '4')Edytowanie2(&head); /*! jezeli 4 wywołujey odpowiednia funkcje*/
        else if(i == '5')Zapisywanie2(head); /*! jezeli 5 wywołujey odpowiednia funkcje*/
        else if(i == '6')Wczytanie2(&head); /*! jezeli 6 wywołujey odpowiednia funkcje*/
        else if(i =='7')Szukanie_filmu(head); /*! jezeli 7 wywołujey odpowiednia funkcje*/
        else if(i == '8')Sortowanie(head); /*! jezeli 8 wywołujey odpowiednia funkcje*/
        else if(i == '0') /*! jezeli 0*/
        {

            printf("Zapisac zmiany?\n1.Tak\n2.Nie\n"); /*! wyswietlenie komunikatu*/
            do /*! petla do..while */
            {
                printf("Twoj wybor: "); /*! wyswietlenie komunikatu*/
                p = getchar(); /*! do p przypisywany jest pobrany klawisz*/
                getchar();  /*! pobranie klawisza od uzytkownika*/
                if(p == '1') /*! jezeli 1*/
                {
                    Zapisywanie2(head); /*! wywołanie odpowiednie funckji*/
                    break; /*! wyjscie z petli*/
                    getchar();  /*! pobranie klawisza od uzytkownika*/
                }
                else if(p == '2')break; /*! jezeli 2 wyjscie z petli*/
                printf("Podano zla odpowiedz.\n"); /*! wyswietlenie komunikatu*/
            }
            while(p!='1' || p!='2'); /*! dopóki i jest rozne o 1 lub 2*/

        }
    }
    while (i != '0'); /*! dopoki i nie jest 0*/
}
void menu3(Filmy *head3, Film *head2, Klient *head) /*! funkcja wyswietlajaca menu z wypozyczeniami*/
{

    char i;
    char p;

    do  /*! petla do while*/
    {
        system("cls"); /*! wyczyszczenie konsoli*/
        printf("1. Wypozyczenie filmu\n");
        printf("2. Oddanie filmu\n");
        printf("3. Lista wypozyczen\n");
        printf("4. Zapisanie zmian\n");
        printf("5. Wczytanie zmian\n");
        printf("0. Powrot\n\n");
        printf("Twoj wybor: "); /*! wyswietlenie opcji*/

        i = getchar(); /*! do i przypisywany jest pobrany klawisz*/
        getchar(); /*! pobranie klawisza od uzytkownika*/

        if(i == '1')Wypozyczanie(&head3, &head2, &head);  /*! jezeli 1 wywołujey odpowiednia funkcje*/
        else if(i == '2')Oddawanie(&head3, &head2, &head); /*! jezeli 2 wywołujey odpowiednia funkcje*/
        else if(i == '3')Wyswietlenie3(head3); /*! jezeli 3 wywołujey odpowiednia funkcje*/
        else if(i == '4')Zapisywanie3(head3); /*! jezeli 4 wywołujey odpowiednia funkcje*/
        else if(i == '5')Wczytanie3(&head3); /*! jezeli 5 wywołujey odpowiednia funkcje*/
        else if(i == '0') /*! jezeli 0*/
        {

            printf("Zapisac zmiany?\n1.Tak\n2.Nie\n"); /*! wyswietlenie komunikatu*/
            do /*! petla do..while*/
            {
                printf("Twoj wybor: ");  /*! wyswietlenie komunikatu*/
                p = getchar(); /*! do p przypisywany jest pobrany klawisz*/
                getchar(); /*! pobranie klawisza od uzytkownika*/
                if(p == '1') /*! jezeli 1*/
                {
                    Zapisywanie3(head3); /*! wywołanie odpowiednie funckji*/
                    break; /*! wyjscie z petli*/
                }
                else if(p == '2')break; /*! jezeli 2 wyjscie z petli*/
                printf("Podano zla odpowiedz.\n"); /*! wyswietlenie komunikatu*/
            }
            while(p!='1' || p!='2'); /*! dopóki i jest rozne o 1 lub 2*/

        }
    }
    while (i != '0'); /*! dopoki i nie jest 0*/
}
void menu(Klient *head, Film *head2, Filmy *head3)  /*!funkcja wyswietlajaca menu glowne*/
{
    char p;

    do
    {
        system("cls"); /*! wyczyszczenie konsoli*/
        printf("1. Lista Klientow\n");
        printf("2. Lista filmow\n");
        printf("3. Wypozyczanie filmow\n");
        printf("0. Wyjscie\n\n");
        printf("Twoj wybor: "); /*! wyswietlenie opcji*/

        p = getchar(); /*! do p przypisywany jest pobrany klawisz*/
        getchar(); /*! pobranie klawisza od uzytkownika*/

        if (p == '1') /*! jezeli 1*/
        {
            system("cls"); /*! wyczyszczenie konsoli*/
            menu1(head); /*! wywolanie odpowiedniej funkcji*/
        } /*! wybor uzytkownika i wybranie odopwiedniej funkcji*/
        else if(p == '2') /*! jezeli 2*/
        {
            system("cls"); /*! wyczyszczenie konsoli*/
            menu2(head2); /*! wywolanie odpowiedniej funkcji*/
        }
        else if(p == '3') /*! jezeli 3*/
        {
            system("cls"); /*! wyczyszczenie konsoli*/
            menu3(head3, head2, head); /*! wywolanie odpowiedniej funkcji*/
        }
    }
    while(p!='0'); /*! dopoki p nie jest 0*/
}

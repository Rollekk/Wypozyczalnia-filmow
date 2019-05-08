#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#define ilosc 50
#define size 20

typedef struct FILM Film; /*! struktura z Filmami */
struct FILM
{
    int id2;
    char tytul[ilosc];
    int rok;
    char rezyser[ilosc];
    char gatunek[ilosc];
    int liczba_eg;
    int liczba_wyp;
    Film* next;
};
int ID_Filmu(Film **head) /*! funckja wyliczajaca ID filmu */
{
    static int id2 = 0;
    if((*head) == NULL) /*! jezeli lista jest pusta*/
    {
        return 0; /*! zwracamy wartosc zero*/
    }
    else
    {
        return ++id2; /*! jezeli nie to zwiekszamy id filmu o 1*/
    }
}
Film* Tworzenie2(Film **head)  /*! funkcja tworzaca nowy element*/
{
    Film *element;
    char tytul[ilosc];
    char rezyser[ilosc];
    char gatunek[ilosc];
    int rok;
    int liczba_eg;
    int liczba_wyp;
    int id2;

    system("cls"); /*! wyczyszczenie ekranu */
    printf("Prosze podac nastepujace dane:\n"); /*! wyswietlenie polecenia dla uzytkownika*/

    printf("Tytul: ");
    scanf(" %[^\t\n]s", tytul); /*! pobranie wartosci od uzytkownika*/

    printf("Gatunek: ");
    scanf(" %[^\t\n]s", gatunek); /*! pobranie wartosci od uzytkownika*/

    printf("Rezyser: ");
    scanf(" %[^\t\n]s", rezyser); /*! pobranie wartosci od uzytkownika*/

    printf("Rok: ");
    scanf("%d", &rok); /*! pobranie wartosci od uzytkownika*/

    printf("Liczba egzemplarzy: ");
    scanf("%d", &liczba_eg); /*! pobranie wartosci od uzytkownika*/

    printf("Liczba wypozyczen: ");
    scanf("%d", &liczba_wyp); /*! pobranie wartosci od uzytkownika*/

    id2 = ID_Filmu(head); /*! przypisujemy id filmu wartosc zwracana przez funkcje*/

    element = (Film*)malloc(sizeof(Film)); /*! zalokowanie pamieci dla zmiennej Klient i przypisanie do zmiennej element*/
    element->next = NULL; /*! przypisujemy nastepnemu elementowi wartosc NULL*/
    strcpy(element->tytul, tytul); /*! kopiujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie*/
    strcpy(element->gatunek, gatunek); /*! kopiujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie*/
    strcpy(element->rezyser, rezyser); /*! kopiujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie*/
    element->rok = rok; /*! przypisujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie*/
    element->id2 = id2; /*! przypisujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie*/
    element->liczba_eg = liczba_eg; /*! przypisujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie*/
    element->liczba_wyp = liczba_wyp; /*! przypisujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie*/
    getchar(); /*! pobranie klawisza od uzytkownika*/

    return element; /*! zwracamy wskaznik listy*/
}
void Dodawanie2(Film **head)  /*! funkcja dodajaca*/
{
    Film *tmp = Tworzenie2(head); /*! przypisanie wskaznikowi tmp funkcji tworzenia*/
    if (*head != NULL) /*! jezeli lista nie jest pusta*/
        tmp->next = *head; /*! to do nastepnego elementu przypisywana jest wartosc head*/
    *head = tmp; /*! a wartosc wskaznika tmp jest przypisywana wskaznikowi head*/
}
void Wyswietlenie2(Film *head)  /*! wyswietlenie listy*/
{

    system("cls"); /*! wyczyszczenie ekranu*/
    Film *tmp;
    tmp = head; /*! przypisanie wskaznikowi tmp wartosci wskaznika head*/
    if (tmp == NULL) /*! jezeli lista jest pusta*/
    {
        printf("Brak filmow\n"); /*! wyswietlamy komunikat*/
    }
    else
    {
        while (tmp != NULL)  /*! jezeli lista nie jest pusta*/
        {
            printf("Tytul: %s\n", tmp->tytul);
            printf("Gatunek: %s\n", tmp->gatunek);
            printf("Rezyser: %s\n", tmp->rezyser);
            printf("Rok: %d\n", tmp->rok);
            printf("Liczba egzemplarzy: %d\n", tmp->liczba_eg);
            printf("Liczba wypozyczen: %d\n", tmp->liczba_wyp);
            printf("ID filmu: %d\n", tmp->id2);
            printf("\n"); /*! wyswietlamy informacje o filmie*/
            tmp = tmp->next; /*! wskaznikowi tmp przypisujemy nastepny element aby poprawnie przechodzic po liscie*/
        }
    }
    getchar(); /*! pobranie klawisza od uzytkownika*/
}
void Szukanie_filmu(Film *head) /*! funkcja szukajaca filmów*/
{

    int i;
    Film *tmp;
    char tytul[size];
    char gatunek[size];
    char rezyser[size];
    int rok;
    int check = 0;
    tmp = head;

    system("cls"); /*! wyczyszczenie ekranu*/
    printf("Po czym wyszukac?\n");
    printf("1.Tytul\n");
    printf("2.Gatunek\n");
    printf("3.Rezyser\n");
    printf("4.Rok\n");
    printf("0.Powrot\n");
    printf("Twoj wybor: "); /*! wyswietlenie opcji*/

    i = getchar(); /*! przypisanie i klwaisza podanego przez uzytkownika*/
    getchar(); /*! pobranie klawisza od uzytkownika*/

    if(i == '1') /*! jezeli 1*/
    {
        system("cls"); /*! wyczyszczenie ekranu*/
        printf("Prosze podac tytul: ");
        scanf(" %[^\t\n]s", tytul); /*! pobranie tytulu od uzytkownika*/
        while(tmp) /*! jezeli lista nie jest pusta*/
        {
            if(strcmp(tytul, tmp->tytul) == 0) /*! i tytul jest prawidlowy*/
            {
                printf("%s %s %s %d %d %d %d\n", tmp->tytul, tmp->gatunek, tmp->rezyser, tmp->rok, tmp->liczba_eg, tmp->liczba_wyp, tmp->id2); /*! wyswietlamy informacje*/
                check = 1; /*! zmieniamy wartosc na 1*/
            }
            tmp = tmp->next; /*! przypisujemy wskaznikowi tmp nastepny element aby poprawnie przechodzic po liscie*/
        }
        if(check == 0) /*! jezeli check jest 0 to znaczy ze nie ma filmów*/
        {
            printf("Nie ma filmu o podanym tytule");
        }
        check = 0; /*! przypisujemy ponownie wartosc 0*/
        getchar(); /*! pobranie klawisza od uzytkownika*/
    }
    else if(i == '2') /*! jezeli 2*/
    {
        system("cls"); /*! wyczyszczenie ekranu*/
        printf("Prosze podac gatunek: ");
        scanf(" %[^\t\n]s", gatunek); /*! pobranie gatunku od uzytkownika*/
        while(tmp) /*! jezeli lista nie jest pusta*/
        {
            if(strcmp(gatunek, tmp->gatunek) == 0) /*! i gatunek jest prawidlowy*/
            {
                printf("%s %s %s %d %d %d %d\n", tmp->tytul, tmp->gatunek, tmp->rezyser, tmp->rok, tmp->liczba_eg, tmp->liczba_wyp, tmp->id2); /*! wyswietlamy informacje*/
                check = 1; /*! zmieniamy wartosc na 1*/
            }
            tmp = tmp->next; /*! przypisujemy wskaznikowi tmp nastepny element aby poprawnie przechodzic po liscie*/
        }
        if(check == 0) /*! jezeli check jest 0 to znaczy ze nie ma filmów*/
        {
            printf("Nie ma filmu o podanym gatunku");
        }
        check = 0;  /*! przypisujemy ponownie wartosc 0*/
        getchar(); /*! pobranie klawisza od uzytkownika*/
    }
    else if(i == '3') /*! jezeli 3*/
    {
        system("cls"); /*! wyczyszczenie ekranu*/
        printf("Prosze podac rezysera: ");
        scanf(" %[^\t\n]s", rezyser); /*! pobranie rezsyera od uzytkownika*/
        while(tmp) /*! jezeli lista nie jest pusta*/
        {
            if(strcmp(rezyser, tmp->rezyser) == 0)  /*! i rezyser jest prawidlowy*/
            {
                printf("%s %s %s %d %d %d %d\n", tmp->tytul, tmp->gatunek, tmp->rezyser, tmp->rok, tmp->liczba_eg, tmp->liczba_wyp, tmp->id2); /*! wyswietlamy informacje*/
                check = 1; /*! zmieniamy wartosc na 1*/
            }
            tmp = tmp->next; /*! przypisujemy wskaznikowi tmp nastepny element aby poprawnie przechodzic po liscie*/
        }
        if(check == 0) /*! jezeli check jest 0 to znaczy ze nie ma filmów*/
        {
            printf("Nie ma filmu od danego rezysera");
        }
        check = 0;  /*! przypisujemy ponownie wartosc 0*/
        getchar(); /*! pobranie klawisza od uzytkownika*/
    }
    else if(i == '4') /*! jezeli 4*/
    {
        system("cls"); /*! wyczyszczenie ekranu*/
        printf("Prosze podac rok: ");
        scanf("%d", &rok); /*! pobranie rezsyera od uzytkownika*/
        while(tmp) /*! jezeli lista nie jest pusta*/
        {
            if(rok == tmp->rok) /*! i rok jest prawidlowy*/
            {
                printf("%s %s %s %d %d %d %d\n", tmp->tytul, tmp->gatunek, tmp->rezyser, tmp->rok, tmp->liczba_eg, tmp->liczba_wyp, tmp->id2); /*! wyswietlamy informacje*/
                check = 1; /*! zmieniamy wartosc na 1*/
            }
            tmp = tmp->next; /*! przypisujemy wskaznikowi tmp nastepny element aby poprawnie przechodzic po liscie*/
        }
        if(check == 0) /*! jezeli check jest 0 to znaczy ze nie ma filmów*/
        {
            printf("Nie ma filmu z danego roku");
        }
        check = 0; /*! przypisujemy ponownie wartosc 0*/
        getchar(); /*! pobranie klawisza od uzytkownika*/
    }
    getchar(); /*! pobranie klawisza od uzytkownika*/
}
Film* Usuwanie2(Film *head) /*! funkcja usuwajaca*/
{
    int id2;

    system("cls"); /*! wyczyszczenie ekranu*/
    printf("Prosze podac numer karty: ");
    scanf("%d", &id2); /*! pobranie id od uzytkownika*/
    getchar(); /*! pobranie klawisza od uzytkownika*/


    Film *tmp = head;		/*! wskaznik tymczasowy tmp wskazuje na head*/
    Film *prev = head;	    /*! wskaznik pomocniczy prev wskazuje równie? na head*/
    while (tmp!=NULL) 	    /*! dopóki wskaznik nie pokazuje konca listy wykonuj polecenia*/
    {
        /*! rozpoczynamy przeszukiwanie listy za podanym elementem*/
        if (tmp->id2==id2)	    /*! jesli wartosc zgadza sie z liczba z danych z elementu*/
            if (tmp==head) 		/*! gdy do usuniecia jest head*/
            {
                head = head->next;  /*! przesuwamy wskaznik head na nastepny element*/
                free(tmp);		    /*! usuwamy element*/
                tmp = head ; /*! wskaznikowi tmp przypisujemy wartosc head*/
                prev = head; /*! wskaznikowi tmp takze przypisujemy wartosc head*/
            }
            else 		                 /*! jesli element do usuniecia nie jest pierwszym na liscie*/
            {
                prev->next = tmp->next; /*! wskaznikowi nastepnemu z poprzedniego nadajemy*/
                /*! wartosc wskaznika nastepnego z tmp( z tego do usuniecia )*/
                free(tmp);		    /*! usuwamy wartosc na która wskazuje tmp*/
                tmp = prev->next;	/*! tmp przechodzi na nastepny element*/
            }
        else 					    /*! jesli wartosc nie jest taka jak liczba z danych z elementu*/
        {
            prev = tmp;		    /*! prev przyjmuje wartosc tmp*/
            tmp = tmp->next;
        }	    /*! tmp przechodzi do nastepnego elementu listy*/
    }
    return head; /*! zwracamy wskaznik head*/
}
void Edytowanie2(Film **head) /*! funckja edytujaca*/
{

    int i;
    int id2 = 0;
    Film *tmp = NULL;
    tmp = *head;

    system("cls"); /*! wyczyszczenie ekranu*/
    printf("Prosze podac ID filmu: ");
    scanf("%d", &id2); /*! pobranie id od uzytkownika*/
    getchar(); /*! pobranie klawisza od uzytkownika*/
    if(tmp) /*! jezeli lista nie jest pusta*/
    {
        while(tmp != NULL) /*! dopóki lista nie jest pusta*/
        {
            if(tmp->id2 == id2) /*! id filmu zgadza sie*/
            {
                printf("Co edytowac?\n"); /*! wyswietlamy opcje*/
                do /*! petla do..while */
                {
                    system("cls");
                    printf("Wybrany film:");
                    printf("%s %s %s %d %d %d %d\n", tmp->tytul, tmp->gatunek, tmp->rezyser, tmp->rok, tmp->liczba_eg, tmp->liczba_wyp, tmp->id2);
                    printf("1.Tytul\n");
                    printf("2.Gatunek\n");
                    printf("3.Rezyser\n");
                    printf("4.Rok\n");
                    printf("5.Liczbe egzemplarzy\n");
                    printf("6.Liczbe wypozyczen\n");
                    printf("0.Powrot\n");
                    printf("Twoj wybor: ");

                    i = getchar(); /*! przypisanie i klawisza od uzytkownika*/
                    getchar(); /*! pobranie klawisza od uzytkownika*/

                    if(i == '1') /*! jezeli 1*/
                    {
                        system("cls"); /*! wyczyszczenie ekranu*/
                        printf("Tytul: %s\n", tmp->tytul); /*! wyswietlenie aktualnego tytulu*/
                        printf("Nowy tytul: ");
                        scanf(" %[^\t\n]s", tmp->tytul); /*! pobranie nowego tytulu*/
                        getchar(); /*! pobranie klawisza od uzytkownika*/
                    }
                    else if(i == '2') /*! jezeli 2*/
                    {
                        system("cls");
                        printf("Gatunek: %s\n", tmp->gatunek); /*! wyswietlenie aktualnego gatunku*/
                        printf("Nowy gatunek: ");
                        scanf(" %[^\t\n]s", tmp->gatunek); /*! pobranie nowego gatunku*/
                        getchar(); /*! pobranie klawisza od uzytkownika*/
                    }
                    else if(i == '3') /*! jezeli 3*/
                    {
                        system("cls");
                        printf("Rezyser: %s\n", tmp->rezyser); /*! wyswietlenie aktualnego rezysera*/
                        printf("Nowy rezyser: ");
                        scanf(" %[^\t\n]s", tmp->rezyser); /*! pobranie nowego rezysera*/
                        getchar(); /*! pobranie klawisza od uzytkownika*/
                    }
                    else if(i == '4') /*! jezeli 4*/
                    {
                        system("cls");
                        printf("Rok: %d\n", tmp->rok); /*! wyswietlenie aktualnego roku*/
                        printf("Nowy rok: ");
                        scanf("%d", &tmp->rok); /*! pobranie nowego roku*/
                        getchar(); /*! pobranie klawisza od uzytkownika*/
                    }
                    else if(i == '5') /*! jezeli 5*/
                    {
                        system("cls");
                        printf("Liczba egzemplarzy: %d\n", tmp->liczba_eg); /*! wyswietlenie aktualnej liczby egzemplarzy*/
                        printf("Nowa liczba egzemplarzy: ");
                        scanf("%d", &tmp->liczba_eg); /*! pobranie nowej liczby egzemplarzy*/
                        getchar(); /*! pobranie klawisza od uzytkownika*/
                    }
                    else if(i == '6') /*! jezeli 6 */
                    {
                        system("cls");
                        printf("Liczba wypozyczen: %d\n", tmp->liczba_wyp); /*! wyswietlenie aktualnej liczby wypozyczen*/
                        printf("Nowa liczba wypozyczen: ");
                        scanf("%d", &tmp->liczba_wyp); /*! pobranie nowej liczby wypozyczen*/
                        getchar(); /*! pobranie klawisza od uzytkownika*/
                    }
                }
                while(i != '0'); /*! dopóki i nie bedzie 0*/
            }
            else
            {
                printf("Nie ma filmu o podanym ID.\n"); /*! jezeli id sie nie zgadza, wyswietlamy*/
            }
            tmp = tmp->next; /*! wskaznikowi tmp przypisujemy wartosc nastepnego elementu aby poprawnie przechodzic po liscie*/
        }
    }
}
void swap(Film *a, Film *b) /*! funkcja zamieniajaca 2 dane*/
{
    int rok = a->rok;
    int id2 = a->id2;
    int liczba_eg = a->liczba_eg;
    int liczba_wyp = a->liczba_wyp;
    char tytul[20];
    char gatunek[20];
    char rezyser[20];
    strcpy(tytul, a->tytul); /*! skopiowanie wartosci*/
    strcpy(gatunek, a->gatunek); /*! skopiowanie wartosci*/
    strcpy(rezyser, a->rezyser); /*! skopiowanie wartosci*/
    a->rok = b->rok; /*! przypisanie wskaznikowi a wskazujacemy na rok wartosci wskaznika b wskazujacego na rok*/
    b->rok = rok;   /*! przypisanie wskaznikowy b wartosci danej rok*/

    a->id2 = b->id2; /*! przypisanie wskaznikowi a wskazujacemy na id2 wartosci wskaznika b wskazujacego na id2*/
    b->id2 = id2; /*! przypisanie wskaznikowy b wartosci danej id2*/

    a->liczba_eg = b->liczba_eg; /*! przypisanie wskaznikowi a wskazujacemy na liczba_eg wartosci wskaznika b wskazujacego na liczba_eg*/
    b->liczba_eg = liczba_eg; /*! przypisanie wskaznikowy b wartosci danej liczba_eg*/

    a->liczba_wyp = b->liczba_wyp; /*! przypisanie wskaznikowi a wskazujacemy na liczba_wyp wartosci wskaznika b wskazujacego na liczba_wyp*/
    b->liczba_wyp = liczba_wyp; /*! przypisanie wskaznikowy b wartosci danej liczba_wyp*/

    strcpy(a->tytul, b->tytul); /*! skopiowanie do wskaznika a wskazujacemy na tytul wartosci wskaznika b wskazujacego na tytul*/
    strcpy(b->tytul, tytul); /*! skopiowanie do wskaznika b wartosci danej tytul*/

    strcpy(a->gatunek, b->gatunek); /*! skopiowanie do wskaznika a wskazujacemy na gatunek wartosci wskaznika b wskazujacego na gatunek*/
    strcpy(b->gatunek, gatunek); /*! skopiowanie do wskaznika b wartosci danej gatunek*/

    strcpy(a->rezyser, b->rezyser); /*! skopiowanie do wskaznika a wskazujacemy na rezyser wartosci wskaznika b wskazujacego na rezyser*/
    strcpy(b->rezyser, rezyser); /*! skopiowanie do wskaznika b wartosci danej rezyser*/
}
void sortowanie_po_tytule_ros(Film *head) /*! funkcja sortujaca*/
{
    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (strcmp(ptr1->tytul, ptr1->next->tytul) > 0) /*! jezeli tytul jest wiekszy od nastepnego tytulu*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void sortowanie_po_gatunku_ros(Film *head) /*! funkcja sortujaca*/
{
    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (strcmp(ptr1->gatunek, ptr1->next->gatunek) > 0) /*! jezeli gatunek jest wiekszy od nastepnego gatunku*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1;  /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void sortowanie_po_roku_ros(Film *head) /*! funkcja sortujaca*/
{
    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (ptr1->rok > ptr1->next->rok) /*! jezeli rok jest wiekszy od nastepnego roku*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1;  /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void sortowanie_po_rezyser_ros(Film *head) /*! funkcja sortujaca*/
{

    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (strcmp(ptr1->rezyser, ptr1->next->rezyser) > 0) /*! jezeli rezyser jest wiekszy od nastepnego rezysera*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void sortowanie_po_liczbieeg_ros(Film *head) /*! funkcja sortujaca*/
{

    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (ptr1->liczba_eg > ptr1->next->liczba_eg) /*! jezeli liczba_eg jest wieksza od nastepnej liczba_eg*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1 */
}
void sortowanie_po_liczbiewyp_ros(Film *head) /*! funkcja sortujaca*/
{

    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (ptr1->liczba_wyp > ptr1->next->liczba_wyp) /*! jezeli liczba_wyp jest wieksza od nastepnej liczba_wyp*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void sortowanie_po_id_ros(Film *head) /*! funkcja sortujaca*/
{

    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (ptr1->id2 > ptr1->next->id2) /*! jezeli id2 jest wiekszy od nastepnego id2*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void Sortowanie_rosnaco(Film *head) /*! funkcja wyswietlajaca mozliwosci do sortowania*/
{

    int p;

    do
    {
        system("cls");
        printf("Po jakim polu sortowac ?\n");
        printf("1. Tytul\n");
        printf("2. Gatunek\n");
        printf("3. Rezyser\n");
        printf("4. Rok\n");
        printf("5. Liczba egzemplarzy\n");
        printf("6. Liczba wypozyczen\n");
        printf("7. ID\n");
        printf("0. Powrot\n\n");
        printf("Twoj wybor: "); /*! wyswietlenie opcji dla uzytkownika*/

        p = getchar(); /*! przypisanie p opcji wybranej przez uzytkownika*/
        getchar(); /*! pobranie klawisza od uzytkownika*/

        if(p == '1') /*! jezeli 1*/
        {
            sortowanie_po_tytule_ros(head); /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano rosnaco po tytule.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '2') /*! jezeli 2*/
        {
            sortowanie_po_gatunku_ros(head); /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano rosnaco po gatunku.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '3') /*! jezeli 3*/
        {
            sortowanie_po_rezyser_ros(head); /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano rosnaco po nazwie rezysera.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '4') /*! jezeli 4*/
        {
            sortowanie_po_roku_ros(head); /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano rosnaco po roku.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '5') /*! jezeli 5*/
        {
            sortowanie_po_liczbieeg_ros(head); /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano rosnaco po liczbie egzemplarzy.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '6') /*! jezeli 6*/
        {
            sortowanie_po_liczbiewyp_ros(head); /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano rosnaco po liczbie wypozyczen.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '7') /*! jezeli 7*/
        {
            sortowanie_po_id_ros(head); /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano rosnaco po ID.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
    }
    while(p != '0'); /*! dopóki p nie bedzie 0*/

}
void sortowanie_po_tytule_mal(Film *head) /*! funkcja sortujaca*/
{
    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (strcmp(ptr1->tytul, ptr1->next->tytul) < 0) /*! jezeli id2 jest mniejszy od nastepnego id2*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void sortowanie_po_gatunku_mal(Film *head) /*! funkcja sortujaca*/
{
    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (strcmp(ptr1->gatunek, ptr1->next->gatunek) < 0) /*! jezeli gatunek jest mniejszy od nastepnego gatunku*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void sortowanie_po_rezyser_mal(Film *head) /*! funkcja sortujaca*/
{
    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (strcmp(ptr1->rezyser, ptr1->next->rezyser) < 0) /*! jezeli rezsyer jest mniejszy od nastepnego rezysera*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1 */
}
void sortowanie_po_roku_mal(Film *head) /*! funkcja sortujaca*/
{
    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (ptr1->rok < ptr1->next->rok) /*! jezeli rok jest mniejszy od nastepnego roku*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void sortowanie_po_liczbieeg_mal(Film *head) /*! funkcja sortujaca*/
{
    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (ptr1->liczba_eg < ptr1->next->liczba_eg) /*! jezeli liczba_eg jest mniejsza od nastepnej liczba_eg*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void sortowanie_po_liczbiewyp_mal(Film *head) /*! funkcja sortujaca*/
{
    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (ptr1->liczba_wyp < ptr1->next->liczba_wyp) /*! jezeli liczba_wyp jest mniejsza od nastepnej liczba_wyp*/
            {
                swap(ptr1, ptr1->next);  /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void sortowanie_po_id_mal(Film *head) /*! funkcja sortujaca*/
{
    int swapped;
    Film *ptr1 = (Film*)malloc(sizeof(Film));; /*! zalokowanie pamieci na wskaznik*/
    Film *lptr = NULL;


    if (ptr1 == NULL) /*! jezeli lista jest pusta*/
        return; /*! wracamy*/

    do
    {
        swapped = 0; /*! przypisanie wartosci 0*/
        ptr1 = head; /*! przypisanie wskaznikowi ptr1 wartosci head*/

        while (ptr1->next != lptr) /*! dopóki wskaznik na nastepny element ptr1 i lptr roznia sie*/
        {
            if (ptr1->id2 < ptr1->next->id2) /*! jezeli id2 jest mniejsza od nastepnego id2*/
            {
                swap(ptr1, ptr1->next); /*! zamieniamy wartosci*/
                swapped = 1; /*! ustawiamy swapped na 1*/
            }
            ptr1 = ptr1->next; /*! przypisujemy ptr1 wartosc wskaznika nastepengo elemetnu*/
        }
        lptr = ptr1; /*! lptr przypisujemy wartosc ptr1*/
    }
    while (swapped); /*! robimy to dopóki swapped = 1*/
}
void Sortowanie_malejaco(Film *head) /*! funkcja wyswietlajaca mozliwosci do sortowania*/
{

    int p;

    do
    {
        system("cls");
        printf("Po jakim polu sortowac ?\n");
        printf("1. Tytul\n");
        printf("2. Gatunek\n");
        printf("3. Rezyser\n");
        printf("4. Rok\n");
        printf("5. Liczba egzemplarzy\n");
        printf("6. Liczba wypozyczen\n");
        printf("7. ID\n");
        printf("0. Powrot\n\n");
        printf("Twoj wybor: "); /*! wyswietlenie opcji dla uzytkownika*/

        p = getchar();  /*! przypisanie p opcji wybranej przez uzytkownika*/
        getchar(); /*! pobranie klawisza od uzytkownika*/

        if(p == '1') /*! jezeli 1*/

        {
            sortowanie_po_tytule_mal(head); /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano malejaco po tytule.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '2') /*! jezeli 2*/
        {
            sortowanie_po_gatunku_mal(head);  /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano malejaco po gatunku.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '3') /*! jezeli 3*/
        {
            sortowanie_po_rezyser_mal(head);  /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano malejaco po nazwie rezysera.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '4') /*! jezeli 4*/
        {
            sortowanie_po_roku_mal(head);  /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano malejaco po roku.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '5') /*! jezeli 5*/
        {
            sortowanie_po_liczbieeg_mal(head);  /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano malejaco po liczbie egzemplarzy.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '6') /*! jezeli 6*/
        {
            sortowanie_po_liczbiewyp_mal(head);  /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano malejaco po liczbie wypozyczen.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else if(p == '7') /*! jezeli 7*/
        {
            sortowanie_po_id_mal(head);  /*! wywołujemy odpowiednia funkcje*/
            system("cls"); /*! wyczyszczenie ekranu*/
            printf("Posortowano malejaco po ID.\n");
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
    }
    while(p != '0'); /*! dopóki p nie bedzie 0*/
}
void Sortowanie(Film *head) /*! funkcja wyswietlajaca opcje do sortowania*/
{

    int i;

    do
    {
        system("cls");
        printf("W jaki sposob sortowac ?\n\n");
        printf("1. Rosnaco\n");
        printf("2. Malejaco\n\n");
        printf("0. Powrot\n\n");
        printf("Twoj wybor: "); /*! wyswietlenie opcji dla uzytkownika*/

        i = getchar(); /*! przypisanie p opcji wybranej przez uzytkownika*/
        getchar(); /*! pobranie klawisza od uzytkownika*/

        if(i == '1') /*! jezeli 1*/
            Sortowanie_rosnaco(head); /*! wywołujemy odpowiednia funkcje*/
        else if(i == '2') /*! jezeli 2 */
            Sortowanie_malejaco(head); /*! wywołujemy odpowiednia funkcje*/
    }
    while(i != '0'); /*! dopóki p nie bedzie 0*/
}
void Zapisywanie2(Film *head) /*! funkcja zapisujaca*/
{
    FILE *zapisz = NULL; /*! wskaznikowi zapisz przypisujemy NULL na poczatek*/
    Film *tmp;
    char nazwa_pliku2[] ="Film.txt"; /*! przypisanie pliku do zapisu*/

    if(head == NULL) /*! jezeli lista jest pusta*/
    {
        printf("Nie ma elementow do zapisania"); /*! wypisujemy komunikat*/
        getchar();  /*! pobranie klawisza od uzytkownika*/
    }
    else
    {
        zapisz=fopen(nazwa_pliku2, "w"); /*! jezeli nie jest, do wskaznika zapisz otwieramy plik to zapisu, w-write*/
        if(zapisz == NULL) /*! jezeli nie ma pliku*/
        {
            printf("Blad otwarcia pliku"); /*! wypisujemy komunikat*/
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else
        {
            tmp = head; /*! wskaznikowi tmp przypisujemy wartosc head*/
            while (tmp != NULL) /*! dopoki lista nie jst pusta*/
            {
                fprintf(zapisz, ".");

                fprintf(zapisz, "%s\t", tmp->tytul);

                fprintf(zapisz, "%s\t", tmp->gatunek);

                fprintf(zapisz, "%s\t", tmp->rezyser);

                fprintf(zapisz, "%d\t", tmp->rok);

                fprintf(zapisz, "%d\t", tmp->liczba_eg);

                fprintf(zapisz, "%d\t", tmp->liczba_wyp);

                fprintf(zapisz, "%d\n", tmp->id2); /*! zapisujemy dane*/

                tmp = tmp->next; /*! wskanizkowi tmp przypisujemy wartosc nastepna aby poprawnie przechodzic po lisice*/
            }
        }
    }
}
void Wczytanie2(Film **head) /*! funkcja wczytujaca*/
{
    FILE *wczytaj = NULL; /*! wskaznikowi wczytaj przypisujemy NULL na poczatek*/
    char nazwa_pliku2[] = "Film.txt"; /*! przypisanie pliku do otworzenia*/
    Film *tmp, *pom;


    wczytaj = fopen(nazwa_pliku2, "r"); /*! wskaznikowi wczytaj przypisujemy otwarcie pliku, r-read*/
    if (wczytaj == NULL) /*! jezeli nie ma pliku*/
    {
        printf("Blad otwarcia pliku z filmami"); /*! to wypisujemy komunikat*/
        getchar(); /*! pobranie klawisza od uzytkownika*/
    }
    else
    {
        while (fgetc(wczytaj) != EOF) /*!dopóki w pliku są linijki i funkcja nie zwróci EOF*/
        {
            tmp = (Film*)malloc(sizeof(Film));  /*! zalokowanie pamieci na wskaznik*/
            tmp->next = NULL;  /*! przypisanie wskaznikowi tmp->next wartosci NULL*/


            fscanf(wczytaj, " %[^\t\n]s", tmp->tytul);

            fscanf(wczytaj, " %[^\t\n]s", tmp->gatunek);

            fscanf(wczytaj, " %[^\t\n]s", tmp->rezyser);

            fscanf(wczytaj, "%d", &tmp->rok);

            fscanf(wczytaj, "%d", &tmp->liczba_eg);

            fscanf(wczytaj, "%d", &tmp->liczba_wyp);

            fscanf(wczytaj, "%d\n", &tmp->id2); /*! wczytujemy dane*/

            if (*head == NULL) /*! jezeli lista jest pusta*/
                *head = tmp; /*! przypisujemy jej wartosc wskaznika tmp*/
            else
            {
                pom = *head; /*! jezeli nie jest pusta przypisujemy wskaznikowi pom wartosc wskaznika head*/
                while (pom->next != NULL) /*! dopóki wskaznik pom->next nie jest pusty*/
                    pom = pom->next; /*! przypisujemy wskaznikowi pom wskaznik na nastepny element*/
                pom->next = tmp; /*! a wskaznikowi na nastepny element wartosc wskaznika tmp*/
            }
        }
    }
}

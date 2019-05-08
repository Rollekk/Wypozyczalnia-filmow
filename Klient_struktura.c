#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#define ilosc 50
#define size 20

typedef struct KLIENT Klient; /*! struktura z Klientami */
struct KLIENT
{
    char imie[ilosc];
    char nazwisko[ilosc];
    int telefon;
    int id;
    Klient* next;
};
int ID_Klienta(Klient **head) /*! funckja wyliczajaca ID klienta */
{
    static int id = 0;
    if((*head) == NULL) /*! jeżeli lista jest pusta */
    {
        return 0; /*! zwracamy 0 jako id */
    }
    else
    {
        return ++id; /*! gdy nie jest pusta, zwiekszamy id o 1 i zwracamy */
    }
}
Klient* Tworzenie(Klient **head) /*! funkcja tworzaca liste klientów */
{
    Klient *element;
    char imie[ilosc], nazwisko[ilosc];
    int telefon, id;

    system("cls"); /*! wyczyszczenie ekranu konsoli */
    printf("Prosze podac nastepujace dane:\n"); /*! wyswietlenie polecenia dla uzytkownika */

    printf("Imie: ");
    scanf("%s", imie); /*! pobranie wartosci od uzytkownika */

    printf("Nazwisko: ");
    scanf("%s", nazwisko); /*! pobranie wartosci od uzytkownika */

    printf("Telefon: ");
    scanf("%d", &telefon); /*! pobranie wartosci od uzytkownika */

    id = ID_Klienta(head); /*! przypisanie ID wartosci zwracanej funkcji */

    element = (Klient*)malloc(sizeof(Klient)); /*! zalokowanie pamięci na wskaznik */
    element->next = NULL; /*! przypisanie wartosci NULL nastepnemy elementowi wskaznika */
    strcpy(element->imie, imie); /*! kopiujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie */
    strcpy(element->nazwisko, nazwisko); /*! kopiujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie */
    element->telefon = telefon; /*! przypisujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie */
    element->id = id; /*! przypisujemy wartosc podana przez uzytkownika do odpowiedniego pola w liscie */
    getchar(); /*! pobranie klawisza od uzytkownika */

    return element; /*! zwracamy wskaznik listy */
}
void Dodawanie(Klient **head) /*! funkcja dodajaca klienta */
{

    Klient *tmp = Tworzenie(head); /*! przypisanie wskaznikowi tmp funkcji tworzenia */
    if (*head != NULL) /*! jezeli lista nie jest pusta */
        tmp->next = *head; /*! nastepnemu elementowi przypisujemy head */
    *head = tmp; /*! przypisujemy wskaznikowi head wartosc tmp */
}
void Wyswietlenie(Klient *head) /*! funkcja wyswietlajaca liste */
{

    system("cls"); /*! wyczyszczenie ekranu */
    Klient *tmp;
    tmp = head; /*! przypisujemy wskaznikowi tmp wartosc head */
    if (tmp == NULL) /*! jezeli lista pusta */
    {
        printf("Brak klientow"); /*! wyswietlamy komunikat */
        getchar(); /*! pobranie klawisza od uzytkownika */
    }
    else
    {
        while (tmp != NULL) /*! dopóki lista nie jesst pusta */
        {
            printf("Imie: %s\n", tmp->imie);
            printf("Nazwisko: %s\n", tmp->nazwisko);
            printf("Numer Karty: %d\n", tmp->id);
            printf("Telefon: %d\n\n", tmp->telefon); /*! wyswietlamy dane klienta */
            tmp = tmp->next; /*! wskaznikowi tmp przypisujemy wskaznik na element nastepny aby przejsc po liscie poprawnie */
        }
        getchar(); /*! pobranie klawisza od uzytkownika */
    }
}
Klient* Usuwanie(Klient *head) /*! funkcja usuwajaca */
{
    int id;

    system("cls"); /*! wyczyszczenie ekranu */
    printf("Prosze podac numer karty: "); /*! wyswietlenie polecenia dla uzytkownika */
    scanf("%d", &id); /*! pobranie wartosci podanej przez uzytkownika */
    getchar(); /*! pobranie klawisza od uzytkownika */


    Klient *tmp = head;		/*! wskaznik tymczasowy tmp wskazuje na head */
    Klient *prev = head;	    /*! wskaznik pomocniczy prev wskazuje równie? na head */
    while (tmp!=NULL) 	    /*! dopóki wskaznik nie pokazuje konca listy wykonuj polecenia*/
    {
        /*! rozpoczynamy przeszukiwanie listy za podanym elementem*/
        if (tmp->id==id)	    /*! jesli wartosc zgadza sie z liczba z danych z elementu*/
            if (tmp==head) 		/*! gdy do usuniecia jest head*/
            {
                head = head->next;  /*! przesuwamy wskaznik head na nastepny element*/
                free(tmp);		    /*! usuwamy element*/
                tmp = head ;
                prev = head;
            }
            else 		                 /*! jesli element do usuniecia nie jest pierwszym na liscie to:*/
            {
                prev->next = tmp->next; /*! wskaznikowi nastepnemu z poprzedniego nadajemy*/
                /*! wartosc wskaznika nastepnego z tmp( z tego do usuniecia )*/
                free(tmp);		    /*! usuwamy wartosc na która wskazuje tmp*/
                tmp = prev->next;	/*! tmp przechodzi na nastepny element*/
            }
        else 					    /*! jezli wartooa nie jest taka jak liczba z danych z elementu to:*/
        {
            prev = tmp;		    /*! prev przyjmuje wartosc tmp*/
            tmp = tmp->next;	    /*! tmp przechodzi do nastepnego elementu listy*/
        }
    }
    return head; /*! zwracamy wskaznik head*/
}
void Edytowanie(Klient **head) /*! funkcja edytujaca klienta*/
{

    int i;
    int id;

    Klient *tmp;
    tmp = *head; /*! przypisujemy wskaznikowi tmp wartosc head*/

    system("cls"); /*! wczyszczenie ekranu*/
    printf("Prosze podac numer karty: "); /*! wyswietlenie polecenia dla uzytkownika*/
    scanf("%d", &id); /*! pobranie wartosci pobranej przez uzytkownika*/
    getchar(); /*! pobranie klawisza od uzytkownika*/
    if(tmp) /*! jezeli lista nie jest pusta*/
    {
        while(tmp != NULL) /*! dopóki nie jest pusta*/
        {
            if(tmp->id == id) /*! jezeli id podane jest zgodne z zachowanym w liscie*/
            {
                printf("Co edytowac?\n"); /*! wyswietlamy dostepne opcje*/
                do /*! wykonujemy podany w petli do..while*/
                {
                    system("cls"); /*! wyczyszczenie ekranu*/
                    printf("Wybrany klient: "); /*! wyswietlenie opcji*/
                    printf("%s %s %d %d\n", tmp->imie, tmp->nazwisko, tmp->id, tmp->telefon); /*! wyswietlenie klienta*/
                    printf("1.Imie\n");
                    printf("2.Nazwisko\n");
                    printf("3.Numer telefonu\n");
                    printf("0.Powrot\n");
                    printf("Twoj wybor: ");

                    i = getchar(); /*! przypisanie i pobranego klawisza*/
                    getchar(); /*! pobranie klawisza od uzytkownika*/

                    if(i == '1') /*! jezeli 1 */
                    {
                        system("cls"); /*! wyczyszczenie ekranu*/
                        printf("Imie: %s\n", tmp->imie); /*! wypisujemy aktualne imie*/
                        printf("Nowe imie: ");
                        scanf("%s", tmp->imie); /*! pobieramy nowe imie od uzytkwnika*/
                        getchar(); /*! pobranie klawisza od uzytkownika*/
                    }
                    else if(i == '2') /*! jezeli 2*/
                    {
                        system("cls"); /*! wyczyszczenie ekranu*/
                        printf("Nazwisko: %s\n", tmp->nazwisko); /*! wypisujemy aktualne nazwisko*/
                        printf("Nowe nazwisko: ");
                        scanf("%s", tmp->nazwisko);; /*! pobieramy nowe nazwisko od uzytkwnika*/
                        getchar(); /*! pobranie klawisza od uzytkownika*/
                    }
                    else if(i == '3') /*! jezeli 3*/
                    {
                        system("cls"); /*! wyczyszczenie ekranu*/
                        printf("Telefon: %d\n", tmp->telefon); /*! wypisujemy aktualny telefon*/
                        printf("Nowy telefon: ");
                        scanf("%d", &tmp->telefon); /*! pobieramy nowy telefon od uzytkwnika*/
                        getchar(); /*! pobranie klawisza od uzytkownika*/
                    }
                }
                while(i != '0'); /*!wykonujemy petle dopoki nie napotakmy 0*/
            }
            else
            {
                printf("Nie ma klienta o podanym numerze karty"); /*! jezeli zostanie podany bledny numer wypisujemy komunikat*/
            }
            tmp = tmp->next; /*! przypisujemy wskaznikowi tmp wartosc nastepna aby przechodzic poprawnie po liscie*/
        }
    }
}
void Zapisywanie(Klient *head) /*! funkcja zapisujaca*/
{
    FILE *zapisz = NULL; /*! wskaznikowi zapisz przypisujemy NULL na poczatek*/
    Klient *tmp;
    char nazwa_pliku[] ="Klienci.txt"; /*! przypisanie pliku do zapisu*/

    if(head == NULL) /*! jezeli lista jest pusta*/
    {
        printf("Nie ma elementow do zapisania"); /*! wypisujemy komunikat*/
        getchar(); /*! pobranie klawisza od uzytkownika*/
    }
    else
    {
        zapisz=fopen(nazwa_pliku, "w"); /*! jezeli nie jest, do wskaznika zapisz otwieramy plik to zapisu, w-write*/
        if(zapisz == NULL) /*! jezeli nie ma pliku*/
        {
            printf("Blad otwarcia pliku"); // wypisujemy komunikat*/
            getchar(); /*! pobranie klawisza od uzytkownika*/
        }
        else
        {
            tmp = head; /*! wskaznikowi tmp przypisujemy wartosc head*/
            while (tmp != NULL) /*! dopoki lista nie jst pusta*/
            {
                fprintf(zapisz, ".");

                fprintf(zapisz, "%s\t", tmp->imie);

                fprintf(zapisz, "%s\t", tmp->nazwisko);

                fprintf(zapisz, "%d\t", tmp->id);

                fprintf(zapisz, "%d\t", tmp->telefon); /* zapisujemy dane*/
                fprintf(zapisz, "\n");
                tmp = tmp->next; /*! wskanizkowi tmp przypisujemy wartosc nastepna aby poprawnie przechodzic po lisice*/
            }
        }
    }
}
void Wczytanie(Klient **head) /*! funkcja wczytujaca*/
{
    FILE *wczytaj = NULL; /*! wskaznikowi wczytaj przypisujemy NULL na poczatek*/
    char nazwa_pliku[] = "Klienci.txt"; /*! przypisanie pliku do otworzenia*/
    Klient *tmp, *pom;


    wczytaj = fopen(nazwa_pliku, "r"); /*! wskaznikowi wczytaj przypisujemy otwarcie pliku, r-read*/
    if (wczytaj == NULL) /*! jezeli nie ma pliku*/
    {
        printf("Blad otwarcia pliku z klientami"); /*! to wypisujemy komunikat*/
        getchar(); /*! pobranie klawisza od uzytkownika*/
    }
    else
    {
        while (fgetc(wczytaj) != EOF) /*!dopóki w pliku są linijki i funkcja nie zwróci EOF*/
        {
            tmp = (Klient*)malloc(sizeof(Klient)); /*! zalokowanie pamieci na wskaznik*/
            tmp->next = NULL; /*! przypisanie wskaznikowi tmp->next wartosci NULL*/


            fscanf(wczytaj, "%s", tmp->imie);

            fscanf(wczytaj, "%s", tmp->nazwisko);

            fscanf(wczytaj, "%d", &tmp->id);

            fscanf(wczytaj, "%d\n", &tmp->telefon); /*! wczytujemy dane*/

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

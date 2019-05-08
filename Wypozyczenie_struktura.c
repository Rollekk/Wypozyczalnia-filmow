#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#define ilosc 50
#define size 20

typedef struct FILMY Filmy; /*! struktura z wypozyczeniami */
struct FILMY
{
    int numer_karty;
    int id_filmu;
    char od_kiedy[ilosc];
    char do_kiedy[ilosc];
    Filmy* next;
};
void Wyswietlenie3(Filmy *head3) /*! funkcja wyswietlajaca*/
{
    Filmy *tmp3;
    tmp3 = head3; /*! przypisanie wskaznikowi tmp3 wartosci haed3*/
    time_t czas; /*! zmienna czas ze struktury time_t*/
    struct tm * data;
    char help[ilosc];

    time( &czas); /*! funkcja zwraca czas lokany do zmiennej czas*/
    data = localtime(&czas); /*! do daty przypisywany jest lokalny czas z zmiennej czas*/

    if(tmp3 == NULL) /*! jezeli lista jest pusta*/
    {
        printf("Brak wypozyczen.\n"); /*! wypisujemy komunikat*/
    }
    else
    {
        system("cls"); /*! wyczyszczenie ekranu*/
        while(tmp3 != NULL) /*! dopóki lista nie jest pusta*/
        {
            printf("Numer karty: %d\n", tmp3->numer_karty);
            printf("ID filmu: %d\n", tmp3->id_filmu);
            strftime(help, ilosc, "Od: %x", data);
            printf("%s\n", help);
            printf("Do: %s\n\n", tmp3->do_kiedy); /*! wyswietlamy dane*/
            tmp3 = tmp3->next; /*! wskaznikowi tmp3 przypisujemy wartosc nastepnego elemenut aby poprawnie przechodzic po liscie*/
        }
    }
    getchar(); /*! pobranie klawisza od uzytkownika*/
}
Filmy *szukanie_elemetu(Filmy *head, int numer_karty) /*! funkcja szukajaca element*/
{
    Filmy *previous = NULL; /*! przypisanie wskazniwkoi previous wartosci null*/
    while(head && head->numer_karty!=numer_karty) /*! dopóki istnieje lista i numer_karty jest zgodny*/
    {
        previous=head; /*! wartosci previous przypisujemy wartosc head*/
        head=head->next; /*! wartosci head przypisujemy wartosc nastepnego elementu*/
    }
    return previous; /*! zwracamy wskaznik previous*/
}
void usuwanie_elementu(Filmy *previous) /*! funkcja usuwajaca srodkowy albo ostatni element*/
{
    Filmy *node = previous->next; /*! przypisanie wskaznikowi node wartosc wskaznika nastepnego previous*/
    if(node) /*! jezeli istnieje lista*/
    {
        previous->next = node->next; /*! przypisanie wskaznikowi na nastepny element previous wartosci wskaznika nastepnego node*/
        free(node); /*! usuwamy zawartosci wskaznik node*/
    }
}
Filmy *usuwanie_poczatku(Filmy *head) /*!usuwanie poczatkowego elementu*/
{
Filmy *next = head->next; /*! przypisanie wskaznikowi next wartosci nastepnego wskaznika next*/
free(head); /*! usniecie zawartosci wskaznika head*/
return next; /*! zwrócenie wskaznika next*/
}
Filmy *Usuwanie3(Filmy *head, int numer_karty) /*! funkcja usuwajaca*/
{
    if(head) /*! jezeli istnieje lista*/
    {
        if(head->numer_karty==numer_karty) /*! numer karty sie zgadza z pierwsyzm elementem*/
            return usuwanie_poczatku(head); /*! zwracamy i wywołujemy odpowiednia funkcje*/
        else
        {
            Filmy *previous = szukanie_elemetu(head, numer_karty); /*! jezeli sie nie zgadza szukamy elementu na liscie*/
            usuwanie_elementu(previous); /*! wywołujemy odpowiednia funkcje*/
        }
    }
    return head; /*! zwracamy wartosc wskaznika head*/
}
void Oddawanie(Filmy **head3, Film **head2, Klient **head) /*! funkcja oddajaca filmy*/
{

    Film *tmp2 = *head2; /*! przypisanie wskaznikowi tmp2 wskaznik head2*/
    Klient *tmp = *head; /*! przypisanie wskaznikowi tmp wskaznik head*/
    Filmy *tmp3 = *head3; /*! przypisanie wskaznikowi tmp3 wskaznik head3*/
    int i;
    int numer_karty;
    int id_filmu;

    system("cls"); /*! wyczyszczenie ekranu*/
    printf("Prosze podac nastepujace dane:\n");
    printf("Numer karty : "); /*! wyswietlenie opcji dla uzytkownika*/
    scanf("%d", &numer_karty); /*! pobranie numeru karty od uzytkownika*/
    while(tmp && tmp->id!=numer_karty) /*! dopóki istnieje lista i numer karty sie nie zgadza*/
    {
        if(!tmp->next) /*! jezeli nie ma wskaznika nastepnego*/
        {
            printf("Nie ma klienta o podanym numerze karty\n"); /*! wyswietlamy komunikat*/
            getche(); /*! pobieramy klawisz od uzytkownika*/
            getchar(); /*! pobieramy klawisz od uzytkownika*/
            return; /*! wracamy */
        }
        tmp=tmp->next; /*! przypisujemy wskaznikowi tmp wartosc wskaznika nastepengo aby poprawnie przechodzic po liscie */
    }
    printf("ID filmu: "); /*! wyswietlenie opcji dla uzytkownika*/
    scanf("%d", &id_filmu); /*! pobranie id filmu od uzytkownika*/
    while(tmp2 && tmp2->id2!=id_filmu) /*! dopóki istnieje lista i id filmu sie nie zgadza*/
    {
        if(!tmp2->next) /*! jezeli nie ma wskaznika nastepnego*/
        {
            printf("Nie ma filmu o podanym ID.\n"); /*! wyswietlamy komunikat*/
            getche(); /*! pobieramy klawisz od uzytkownika*/
            getchar(); /*! pobieramy klawisz od uzytkownika*/
            return;  /*! wracamy*/
        }
        tmp2=tmp2->next; /*! przypisujemy wskaznikowi tmp wartosc wskaznika nastepengo aby poprawnie przechodzic po liscie*/
    }
    system("cls"); /*! wyczyszczenie ekranu*/
    printf("Znaleziony klient: ");
    printf("%s %s \n", tmp->imie, tmp->nazwisko);
    printf("Znaleziony film: ");
    printf("%s %s %s %d\n\n", tmp2->tytul, tmp2->gatunek, tmp2->rezyser, tmp2->rok); /*! wyswietlenie danych*/
    printf("Oddac film ?\n");
    printf("1. Tak\n2. Nie\n");
    printf("Twoj wybor: "); /*! wyswietlenie opcji dla uzytkownika*/
    i=getch(); /*! przypisanie i pobranego od uzytkownika klawisza*/
    if(i == '1') /*! jezeli 1*/
    {
        Usuwanie3(tmp3, numer_karty); /*! wywołujemy funkcje usuwajaca*/
        (tmp2->liczba_eg)++; /*! zwiekszamy liczbe egzemplarzy o 1*/
        (tmp2->liczba_wyp)--; /*! zmniejszamy liczbe wypozyczen o 1*/
        tmp2= tmp2->next; /*! przypisujemy wskaznikowi tmp wartosc wskaznika nastepengo aby poprawnie przechodzic po liscie*/
    }
    getchar(); /*! pobieramy klawisz od uzytkownika*/
}
Filmy *create_list_wypozyczenia(int nr_klienta_tmp, int nr_filmu_tmp, char do_kiedy[ilosc]) /*! funkcja tworzaca liste z wypozyczeniami*/
{
    Filmy *first =(Filmy *)malloc(sizeof(Filmy)); /*! zalokowanie pamieci na wskaznik*/
    if(first) /*! jezeli jest pierwszy element*/
    {
        first->numer_karty = nr_klienta_tmp;
        first->id_filmu = nr_filmu_tmp;
        strcpy(first->do_kiedy, do_kiedy); /*! przypisujemy dane do odpowiednich zmiennych*/
        first->next=NULL; /*! nastepnemu elementowi przypisujemy NULL*/
    }
    return first; /*! zwracamy wskaznik na next*/
}

Filmy *add_node_wypozyczenia(Filmy *head, int nr_klienta_tmp, int nr_filmu_tmp, char do_kiedy[ilosc]) /*! funkcja dodajaca kolejne elementy do listy z wypozyczeniami*/
{
    Filmy *new_node = (Filmy *)malloc(sizeof(Filmy)); /*! zalokowanie pamieci na wskaznik*/
    if(new_node) /*! jezeli jest element*/
    {
        new_node->numer_karty = nr_klienta_tmp;
        new_node->id_filmu = nr_filmu_tmp;
        strcpy(new_node->do_kiedy, do_kiedy); /*! przypisujemy odpowiednie dane*/
        new_node->next=head->next; /*! nastepnemu elementwoi z new_node przypisujemy nastepny element z head*/
        head->next=new_node;  /*! przypisujemy nastepny element head wartosc new_node*/
    }
    return head; /*! zwracamy wskaznik head*/
}

void Wypozyczanie(Filmy **head3, Film **head2, Klient **head) /*! funkcja do wypozyczania filmów*/
{
    Film *tmp2 = *head2; /*! wskaznikowi tmp2 przypisujemy wartosc wskaznika head2*/
    Klient *tmp = *head; /*! wskaznikowi tmp przypisujemy wartosc wskaznika head*/
    int i;
    char do_kiedy[ilosc];
    int numer_karty, id_filmu;
    system("cls"); /*! wyczyszczenie ekranu*/
    printf("Prosze podac nastepujace dane:\n");
    printf("Numer karty : "); /*! wyswietlenie opcji dla uzytkownika*/
    scanf("%d", &numer_karty); /*! pobranie numeru karty od uzytkownika*/
    while(tmp && tmp->id!=numer_karty) /*! dopóki lista nie jest pusta i numer karty zgadza się*/
    {
        if(!tmp->next) /*! jezeli nie ma wskaznika nastepnego*/
        {
            printf("Nie ma klienta o podanym numerze karty\n"); /*! wyswietlamy komunikat*/
            getche(); /*! pobieramy klawisz od uzytkownika*/
            return; /*! wracamy*/
        }
        tmp=tmp->next; /*! przypisujemy wskaznikowi tmp wartosc wskaznika nastepengo aby poprawnie przechodzic po liscie*/
    }
    printf("ID filmu: "); /*! wyswietlenie opcji dla uzytkownika*/
    scanf("%d", &id_filmu); /*! pobranie numeru karty od uzytkownika*/
    while(tmp2 && tmp2->id2!=id_filmu) /*! dopóki lista nie jest pusta i id filmu zgadza się*/
    {
        if(!tmp2->next) /*! jezeli nie ma wskaznika nastepnego*/
        {
            printf("Nie ma filmu o podanym ID.\n");  /*! wyswietlamy komunikat*/
            getche(); /*! pobieramy klawisz od uzytkownika*/
            return; /*! wracamy*/
        }
        tmp2=tmp2->next; /*! przypisujemy wskaznikowi tmp wartosc wskaznika nastepengo aby poprawnie przechodzic po liscie*/
    }
    system("cls");  /*! wyczyszczenie ekranu*/
    printf("Znaleziony klient: ");
    printf("%s %s \n", tmp->imie, tmp->nazwisko);
    printf("Znaleziony film: ");
    printf("%s %s %s %d\n\n", tmp2->tytul, tmp2->gatunek, tmp2->rezyser, tmp2->rok);
    printf("Wypozyczyc film ?\n");
    printf("1. Tak\n2. Nie\n");
    printf("Twoj wybor: "); /*! wyswietlenie opcji dla uzytkownika*/
    i=getch(); /*! przypisanie i pobranego od uzytkownika klawisza*/
    getchar(); /*! pobranie od uzytkownika klawisza*/
    if(i == '1') /*! jezeli 1*/
    {
        (tmp2->liczba_eg)--; /*! zmniejszenie liczby egzemplarzy*/
        (tmp2->liczba_wyp)++; /*! zwiekszenie liczby wypozyczen*/
        printf("\nDo kiedy?\n");
        scanf("%s", do_kiedy); /*! pobranie daty od uzytkownika*/
        getchar(); /*! pobranie od uzytkownika klawisza */
        if(*head3) /*! jezeli istnieje lista */
            add_node_wypozyczenia(*head3,numer_karty,id_filmu,do_kiedy); /*! wywołujemy odpowiednia funkcje*/
        else
            *head3=create_list_wypozyczenia(numer_karty,id_filmu,do_kiedy); /*! jezeli nie istnieje wywołujemy odpowiednia funkcje*/
    }
}

void Zapisywanie3(Filmy *head3) /*! funkcja zapisujaca*/
{
    FILE *zapisz = NULL; /*! wskaznikowi zapisz przypisujemy NULL na poczatek*/
    Filmy *tmp;
    char nazwa_pliku3[] ="Wypozyczanie.txt"; /*! przypisanie pliku do zapisu*/

    if(head3 == NULL) /*! jezeli lista jest pusta*/
    {
        printf("Nie ma elementow do zapisania"); /*! wypisujemy komunikat*/
        getchar(); /*! pobranie klawisza od uzytkownika*/
    }
    else
    {
        zapisz=fopen(nazwa_pliku3, "w"); /*! jezeli nie jest, do wskaznika zapisz otwieramy plik to zapisu, w-write*/
        if(zapisz == NULL) /*! jezeli nie ma pliku*/
        {
            printf("Blad otwarcia pliku"); /*! wypisujemy komunikat*/
            getchar();  /*! pobranie klawisza od uzytkownika*/
        }
        else
        {
            tmp = head3; /*! wskaznikowi tmp przypisujemy wartosc head*/
            while (tmp != NULL) /*! dopoki lista nie jst pusta*/
            {
                fprintf(zapisz, ".");

                fprintf(zapisz, "%d ", tmp->id_filmu);

                fprintf(zapisz, "%d ", tmp->numer_karty);

                fprintf(zapisz, "%s\n", tmp->do_kiedy); /*! zapisujemy dane*/

                tmp = tmp->next; /*! wskanizkowi tmp przypisujemy wartosc nastepna aby poprawnie przechodzic po lisice*/
            }
        }
    }
}
void Wczytanie3(Filmy **head3) /*! funkcja wczytujaca*/
{
    *head3=NULL; /*! przypisanie wskaznikowi head3 null */
    FILE *wczytaj = NULL; /*! wskaznikowi wczytaj przypisujemy NULL na poczatek*/
    char nazwa_pliku3[] = "Wypozyczanie.txt"; /*! przypisanie pliku do otworzenia*/
    wczytaj = fopen(nazwa_pliku3, "r"); /*! wskaznikowi wczytaj przypisujemy otwarcie pliku, r-read*/
    if (wczytaj == NULL) /*! jezeli nie ma pliku*/
    {
        printf("Brak pliku z wypozyczeniami"); /*! to wypisujemy komunikat*/
        getchar();  /*! pobranie klawisza od uzytkownika*/
    }
    else
    {
        int film_nr, klient_nr;
        char do_kiedy[ilosc];
        while (fgetc(wczytaj) != EOF) /*!dopóki w pliku są linijki i funkcja nie zwróci EOF*/
        {
            fscanf(wczytaj, "%d", &film_nr);
            fscanf(wczytaj, "%d", &klient_nr);
            fscanf(wczytaj, "%s\n", do_kiedy); /*! wczytujemy dane*/
            if(!(*head3)) /*! jezeli lista jest pusta*/
                *head3=create_list_wypozyczenia(klient_nr,film_nr,do_kiedy); /*! wywołujemy odpowiednia funkcje*/
            else
                add_node_wypozyczenia(*head3,klient_nr,film_nr,do_kiedy); /*! jezeli jest wywołujemy odpowiednia funkcje*/
        }
    }
}

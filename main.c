#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#define ilosc 50
#define size 20

#include "Klient_struktura.c"
#include "Film_struktura.c"
#include "Wypozyczenie_struktura.c"
#include "Menu_struktura.c"

int main()
{

    Klient *head = NULL; /*! przypisanie wskaznikowi head NULL */
    Film *head2 = NULL; /*! przypisanie wskaznikowi head2 NULL */
    Filmy *head3 = NULL; /*! przypisanie wskaznikowi head3 NULL */

    Wczytanie(&head); /*! wywoalanie funkcji wczytujacej */
    Wczytanie2(&head2); /*! wywoalanie funkcji wczytujacej */
    Wczytanie3(&head3); /*! wywoalanie funkcji wczytujacej */
    menu(head, head2, head3); /*! wywoalnie funkcji head */
    return 0; /*! zwrocenie 0 */
}


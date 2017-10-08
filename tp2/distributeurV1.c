/******************************************************************************
**
** Version initiale.
** ----------------
** Ce programme se compose de trois fonctions. La fonction de desitribution
** est charg�e de lire les caract�res en provenance de l'entr�e standard,
** d'envoyer les chiffres � la fonction chiffre (par l'interm�diaire d'un
** appel de fonction classique) et les lettres � la fonction lettre (aussi par
** l'interm�diaire d'un appel de fonction).
** Une fois la fin de fichier atteinte, les fonctions renvoient leurs
** r�sultats � la fonction de distribution qui affiche ensuite les r�sultats.
**
** � 2002, �ric Renault pour l'Institut National des T�l�communications.
** � 2003, Denis Conan
**
******************************************************************************/

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  int fdNombre[2];
  int fdLettre[2];

  pipe(fdLettre);
  pipe(fdNombre);

  if( !fork() ){ //Proc Lettre
    close(fdNombre[0]);
    close(fdNombre[1]);
    close(fdLettre[1]);

    static int frequence['z' - 'a' + 1] ;
    int car = -1;
    read(fdLettre[0],&car,sizeof(car));
    while( car != EOF) {
      /* Incr�ment des fr�quences. */
      frequence [ tolower ( car ) - 'a' ] ++ ;
    }
    for(int i = 'a' ; i <= 'z' ; i ++) {
      printf(" ; %c : %d", i, frequence[i - 'a']) ;
    }
    printf("\n");

    close(fdLettre[0]);
    exit(0);
  }
  else{ // père
    if( !fork() ){ // ProcNombre
      close(fdLettre[0]);
      close(fdLettre[1]);
      close(fdNombre[1]);

      static int somme = 0 ;
      int car = -1;
      read(fdNombre[0],&car,sizeof(car));
      while (car != EOF) {
        /* Somme des chiffres. */
        somme += (car - '0') ;
      }
      printf("Somme : %d", somme);

      close(fdNombre[0]);
      exit(0);
    }
    else{ //père
      close(fdNombre[0]); //Descripteur inutile (lecture)
      close(fdLettre[0]);
      int car = -1;
      do {
        car = getchar() ;

          if (isalpha(car) || (car == EOF)){ //écrire sur proc lettre
            write(fdLettre[1],&car,sizeof(car));
          }
          if (isdigit(car) || (car == EOF)){ //écrire sur proc nombre
            write(fdNombre[1],&car,sizeof(car));
          }
      } while(car != EOF);

      close(fdNombre[1]); //fermeture descripteurs en fin de tâche
      close(fdLettre[1]);
    }
  }


}

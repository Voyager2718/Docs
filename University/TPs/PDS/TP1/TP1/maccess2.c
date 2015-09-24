#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
/*exercice 2*/
int main(int argc, char** argv)
{
  if (argv[2][0]=='-' && argv[2][1]=='r'){
    return access(argv[1],R_OK);
  }
  else
    if ((argv[2][0]=='-') && (argv[2][1]=='w')){
      return access(argv[1],W_OK);
	
    }
    else 
      if ((argv[2][0]=='-') && (argv[2][1]=='x')){
	return access(argv[1],X_OK);
      }
      else 
	if (argv[2][0]=='-' && argv[2][1]=='v'){
	  access(argv[1],F_OK);
	  switch(errno)
	    {
	    case ENOENT:
	      printf(",le fichier n'existe pas\n");
	      break;
	    case ENOTDIR:
	      printf(",une des composantes du nom de fichier n'est pas un repectoire\n");
	      break;
	    case ELOOP:
	      printf(",trop de lien symbolique\n");
	      break;
	    case ENAMETOOLONG:
	      printf(",le nom du fichier est trop long\n");
	      break;
	    case EACCES:
	      printf(",le droit d'acces demandé au fichier n'est pas positionné\n");
	      break;
	    default:
	      printf(",Autre erreur\n");
	      break;
	    }
	}

}

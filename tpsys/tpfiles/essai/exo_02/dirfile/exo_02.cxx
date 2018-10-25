

  #include <string>
  #include <exception>


  #include "string.h"

  #include "../include/CExc.h"
  #include "../include/nsSysteme.h"  // wrappers système

  // a verifier avec le man 2 ou man 3  de la fonction systeme les #include a rajouter

  using namespace nsSysteme; // wrappers système
  using namespace std;

  int main (int argc, char * argv []) {
    try {

    if (2 != argc){
	cout<<"Usage : ./exo2.run <nomfic>" <<endl;
	}

    struct stat S;
    Stat(argv[1], &S);
    cout<<"Taille : "<<S.st_size<<endl;
    cout<<"Nbe de liens en dur : "<<S.st_nlink<<endl;
    cout<<"Date de dernière modif : "<<ctime(&(S.st_mtime))<<endl;


    }
    catch (const CExc & Exc) {
      cerr << Exc << endl;
      return errno;
    }
    catch (const exception & Exc) {
      cerr << "Exception : " << Exc.what () << endl;
      return 1;
    }  
    catch (...) {
       cerr << "Exception inconnue recue dans la fonction main()" << endl;
       return 1;
    }
  }// main()


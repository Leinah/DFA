/************************
****    LIBRERIAS    ****
*************************/
#include <iostream>
#include <stdlib.h>
#include "dfa.hpp"
/***********************
****   CONSTANTES   ****
************************/

using namespace std;

/************************
* Declaracion Funciones *
*************************/
int elegir_opcion();
/***********************
****    Princiapl   ****
************************/
int main(void){
    int opc;
    string file, cadena;
    DFA A;
    do{ 
       opc = elegir_opcion();
       system("cls");
       switch(opc){
                 case 1:
                      cout<<endl<<"Introduce el nombre del fichero y su extension: ";
                      cin>>file;
                      A.leer_archivo(file);
                      if(!A.comprobar_fichero())
                        cout<<endl<<"Error al leer el fichero";
                      break;
                 case 2:
                      A.mostrar_dfa();
                      break;
                 case 3:
                      A.buscar_estado_muerte();
                      break;
                 case 4:
                      cout<<endl<<"Introduce la cadena: ";
                      cin>> cadena;
                      A.set_cadena(cadena);
                      if(A.comprobar_cadena() == 1)
                        A.analizar_cadena();
                      else
                        cout<<endl<<"Esta cadena no pertenece al lenguaje.";
                      break;
                 case 9:
                      cout<<endl<<"Gracias por usar el programa";
                      A.~DFA();
                      break;
                 default:
                      cout<<endl<<"La opcion introducida no es valida.";
                      break;
                 }//fin swith
    
    }while(opc != 9);
    cout<<endl<<endl<<endl; system("pause");
    return 0;
}
/***********************
****    FUNCIONES   ****
************************/
int elegir_opcion(){
    int opc;
    cout<<endl;
    cout<<endl<<"**********";
    cout<<endl<<"** MENU **";
    cout<<endl<<"**********";
    cout<<endl<<"1. Leer DFA de fichero.";
    cout<<endl<<"2. Mostrar DFA.";
    cout<<endl<<"3. Estados de muerte.";
    cout<<endl<<"4. Analizar cadena.";
    cout<<endl<<"9.Salir";
    cout<<endl<<"Opcion: ";
    cin>> opc;
    return opc;
}

     
     

#include <iostream>
#include <fstream>
#include "dfa.hpp"
#include <stdlib.h>

#define TAM 7
#define ESTADO 0
#define ACEPTACION 1
#define N_TRANSICIONES 2
#define P_SIMBOLO 3
#define P_ESTADO 4
#define S_SIMBOLO 5
#define S_ESTADO 6


using namespace std;

DFA::DFA(){ states = 0; start = 0;}

int DFA::analizar_cadena(){
      int i=0;
      char *p={"              "};
      char *s={"        "};
      int actual = start;
      int longitud = cadena.size(); 
      cout<<endl<<"Cadena de entrada: "<<cadena;
      cout<<endl<<"Estado actual"<< "  "<<"Entrada"<< "  "<<"Siguiente estado"<<endl;  
      for(i=0;i<longitud;i++){ //recorre la cadena a analizar
            if(info_dfa[actual][P_SIMBOLO] == cadena[i]){ //compara si hemos encontrado el simbolo
               if((i == (longitud-1)) && (info_dfa[c_atoi(&info_dfa[actual][P_ESTADO])][ACEPTACION] == '1')){
                      cout<<actual<<p; //muestra primer estado donde sale el simbolo
                      cout<<info_dfa[actual][P_SIMBOLO]<<s;  //muestra simobolo      
                      actual = (c_atoi(&info_dfa[actual][P_ESTADO])); 
                      cout<<actual<<endl; //muestra estado final dodne fue el simbolo
                      cout<<endl<<"Cadena de entrada ACEPTADA";
                      return 1;}
            }else if(info_dfa[actual][S_SIMBOLO] == cadena[i])
               if((i == (longitud-1))&&(info_dfa[c_atoi(&info_dfa[actual][S_ESTADO])][ACEPTACION] == '1')){
                      cout<<actual<<p; //muestra primer estado donde sale el simbolo
                      cout<<info_dfa[actual][S_SIMBOLO]<<s;  //muestra simobolo 
                      actual = (c_atoi(&info_dfa[actual][S_ESTADO]));      
                      cout<<actual<<endl; //muestra estado final dodne fue el simbolo
                      cout<<endl<<"Cadena de entrada ACEPTADA";
                      return 1;}
           //si no estamos al final de la cadena ni tampoco  en una cadena de aceptación 
           //actualizamos la variable actual, la cual es el indice del estado actual.                                                       
            if (info_dfa[actual][P_SIMBOLO] == cadena[i]){
               cout<<actual<<p; //muestra primer estado donde sale el simbolo
               cout<<info_dfa[actual][P_SIMBOLO]<<s;  //muestra simobolo       
               actual = (c_atoi(&info_dfa[actual][P_ESTADO]));
               cout<<actual<<endl;} //muestra estado final dodne fue el simbolo
            else if (info_dfa[actual][S_SIMBOLO] == cadena[i]){
               cout<<actual<<p;
               cout<<info_dfa[actual][S_SIMBOLO]<<s;
               actual = (c_atoi(&info_dfa[actual][S_ESTADO]));
               cout<<actual<<endl;}
            }    //fin for*/
         cout<<endl<<"Cadena de entrada NO ACEPTADA";
         return  0;     
      }

void DFA::leer_archivo(string nfile){
     
     ifstream file;
     int i,j;
     /*Pasamos a char secuence ya que la funcion no lee string*/
     char *aux = new char[nfile.size()+1];
     strcpy(aux, nfile.c_str());
     
     file.open(aux, ifstream::in);
   if(file.good()){
      file>>states;
      file>>start;
      //Redimensionamos nuestra matriz
      info_dfa=new char *[states];
      for(i=0;i<states;i++)
         info_dfa[i] = new char[TAM];
      //almacenamos en nuestra matriz
      for(i=0;i<states;i++)
       for(j=0;j<TAM;j++)
          file>>info_dfa[i][j];
   }else{
      cout << "Fichero no disponible" << endl;
      if(file.fail()) cout << "Bit fail activo" << endl;
      if(file.eof())  cout << "Bit eof activo" << endl;
      if(file.bad())  cout << "Bit bad activo" << endl;
   }
   file.close();
}
void DFA::mostrar_dfa(){
     int i,j;
     cout<<endl<<states;
     cout<<endl<<start;
     for(i=0;i<states;i++){
       cout<<endl;
       for(j=0;j<TAM;j++)
          cout<<info_dfa[i][j]<<" ";
          }
}

void DFA::buscar_estado_muerte(){
     int i;
     int decimal = 10;
     char estado[states];
     for(i=0;i<states;i++)
        if(info_dfa[i][ACEPTACION] == '0'){
            itoa(i,estado, decimal);      
            if((info_dfa[i][P_ESTADO] == *estado) && (info_dfa[i][S_ESTADO] == *estado))
                    cout<<endl<<"El estado "<< i <<" es un estado de muerte.";    
                    }
}
int DFA::comprobar_cadena(){
    int i;
    //lenguajes a,b
    if((info_dfa[start][P_SIMBOLO] == 'a') || (info_dfa[start][P_SIMBOLO] == 'b')) 
        for(i=0;i<cadena.size();i++)
           if((cadena[i] != 'a') && (cadena[i] != 'b'))
              return 0;
    //lenguajes 0,1          
    if((info_dfa[start][P_SIMBOLO] == '0') || (info_dfa[start][P_SIMBOLO] == '1')) 
        for(i=0;i<cadena.size();i++)
           if((cadena[i] != '0') && (cadena[i] != '1'))       
              return 0;
            
    return 1;   //sino a retornado ningun error entonces es que esta todo correcto     
                        }

int DFA::comprobar_fichero(){ //funcion que comprueba que para cada estado solo tengamos un simbolo por cada cada transicion
    int i;
    for(i=0;i<states;i++)
       if(info_dfa[i][P_SIMBOLO] == info_dfa[i][S_SIMBOLO])
          return 0;
    return 1;
    }

int DFA::c_atoi(char *cad){ 
   int valor=0;
     valor = *cad-'0';
   return valor; 
}

void DFA::set_cadena(string cad){cadena = cad; }
string DFA::get_cadena(){ return cadena;}
DFA::~DFA(){ states = 0; start = 0;}



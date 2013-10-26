# if !defined ( _dfa_HPP_ )
# define _dfa_HPP_
# include <vector>

# include <iostream>

using namespace std;

class DFA{
    private:
        int states, start;
        char **info_dfa;
        string cadena;
    public:       
        DFA(); // constructor sin parámetros
        void leer_archivo(string nfile);
        void mostrar_dfa();
        void buscar_estado_muerte();
        int analizar_cadena();
        int c_atoi(char *cad);
        void set_cadena(string cad);
        string get_cadena();       
        int comprobar_fichero();
        int comprobar_cadena();
        ~DFA();
};
# endif 

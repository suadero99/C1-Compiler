#ifndef LEXER_H
#define LEXER_H
#include <fstream>
#include <string>
#include <map>
#include <sstream>


using namespace std;

namespace C_1{    

    class Lexer
    {
    private:        
      const int ERROR = -1;
        const int ACEPTAR = 0;
        const int INT = 1;
        const int FLOAT = 2;
        const int ELSE = 3;
        const int IF = 4;
        const int WHILE = 5;
        const int MAS = 6;
        const int MENOS = 7;
        const int MUL = 8;
        const int DIV = 9;
        const int ASIG = 10;
        const int LPAR = 11;
        const int RPAR = 12;
        const int ID = 13;
        const int PYC = 14;
        const int COMA = 15;
        const int NUM = 16;

    
        // Se debe de ingresar todos los constantes necesarios para generar los tokens
        

         ifstream yyin; //obj para archivo de entrada
        int **transiciones;// tabla transiciones
        bool *acc; //arreglo de estados de acept       
        string yytext; //buffer que almacena lo leido
        int yyline; //buffer que cuenta las lineas.
        char c; //ccaracter
        int edos, nsimbolos;
        map<char, int> simbolos;

    public:
        Lexer(/* args */);
        Lexer(string file); //lectura TXT.
        ~Lexer();

        bool readAFD(string file);
        void getChar();

            /*manipulacion de archivos*/
        bool openFile(string file);
        void closeFile();

        //retorno de tokens al leer
        int yylex();
        void printTTrans();
        int token(int q);
        string getYytext();   
    };  
    
    
}

#endif
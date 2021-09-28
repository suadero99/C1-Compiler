#include "Lexer.h"
#include "tokens.h"
#include <iostream>


namespace C_1{
    Lexer::Lexer(/* args */)
    {

    }

    Lexer::Lexer(string file)
    {
       
        ifstream afd(file);
        string line, aceptar;
        stringstream s;
        int row=0, col=0, q;

        //Se lee la primera linea 
        getline(afd,line);
        s = stringstream(line);
        s>>edos;
        s>>nsimbolos;


        transiciones = new int*[edos];
        for(int i=0; i<edos; i++){
            transiciones[i]=new int[nsimbolos];
        }

        acc = new bool[edos];

        while(row < edos){
            getline(afd,line);
            s = stringstream(line);
            while(col < nsimbolos){
                s >> q;
                transiciones[row][col++]=q;
            }
            //en realidad hay nsimbolos+1 columnas porque la última no tiene que ver con símbolos
            s >> aceptar;
            aceptar =="true"? acc[row] = true : acc[row]=false;
            row++;
            col=0;
        }
        afd.close();

        simbolos['+'] = 0;
        simbolos['-'] = 1;
        simbolos['*'] = 2;
        simbolos['/'] = 3;
        simbolos['='] = 4;
        simbolos[' ']  = 5;
        simbolos['\t'] = 5;
        simbolos['\r'] = 5;
        simbolos['\n'] = 5;
        simbolos['0'] = 6;
        simbolos['1'] = 6;
        simbolos['2'] = 6;
        simbolos['3'] = 6;
        simbolos['4'] = 6;
        simbolos['5'] = 6;
        simbolos['6'] = 6;
        simbolos['7'] = 6;
        simbolos['8'] = 6;
        simbolos['9'] = 6;
        simbolos['a'] = 7;
        simbolos['E'] = 8;
        simbolos['e'] = 9;
        simbolos['f'] = 10;
        simbolos['h'] = 11;
        simbolos['i'] = 12;
        simbolos['l'] = 13;
        simbolos['n'] = 14;
        simbolos['o'] = 15;
        simbolos['s'] = 16;
        simbolos['t'] = 17;
        simbolos['w'] = 18;
        simbolos['b'] = 19;
        simbolos['c'] = 19;
        simbolos['d'] = 19;
        simbolos['g'] = 19;
        simbolos['j'] = 19;
        simbolos['k'] = 19;
        simbolos['m'] = 19;
        simbolos['p'] = 19;
        simbolos['q'] = 19;
        simbolos['u'] = 19;
        simbolos['v'] = 19;
        simbolos['x'] = 19;
        simbolos['y'] = 19;
        simbolos['z'] = 19;
        simbolos['A'] = 19;
        simbolos['B'] = 19;
        simbolos['C'] = 19;
        simbolos['D'] = 19;
        simbolos['F'] = 19;
        simbolos['G'] = 19;
        simbolos['H'] = 19;
        simbolos['I'] = 19;
        simbolos['J'] = 19;
        simbolos['K'] = 19;
        simbolos['L'] = 19;
        simbolos['M'] = 19;
        simbolos['N'] = 19;
        simbolos['O'] = 19;
        simbolos['P'] = 19;
        simbolos['Q'] = 19;
        simbolos['R'] = 19;
        simbolos['S'] = 19;
        simbolos['T'] = 19;
        simbolos['U'] = 19;
        simbolos['V'] = 19;
        simbolos['W'] = 19;
        simbolos['X'] = 19;
        simbolos['Y'] = 19;
        simbolos['Z'] = 19;
        simbolos['_'] = 19;
        simbolos['.'] = 20;
        simbolos[','] = 21;
        simbolos[';'] = 22;
        simbolos['('] = 23;
        simbolos[')'] = 24;
    }
    /*Libera memoria de forma inversa reservada*/
    Lexer::~Lexer()
    {
        for(int i=0; i<edos; i++)
            delete transiciones[i];
        delete transiciones;
        delete acc;
    }

    void Lexer::getChar(){
        yyin.get(c);
    }

    bool Lexer::readAFD(string file)
    {
        return true;
    }
        

    bool Lexer::openFile(string file)
    {
        yyin.open(file,ios::in);
        if(!yyin.is_open()){
            cerr << "Problemas al abrir el archivo: '" << file <<"'" << endl;
            return EXIT_FAILURE;
        }
        getChar();
        return true;
    }


    void Lexer::closeFile(){
        yyin.close();
    }

    int Lexer::yylex(){
        int q=0;
        int cc;
        yytext = "";        
        if(yyin.eof()) return 0;
        while(true){
            cc =  simbolos[c];
            if(transiciones[q][cc]!=-1){
                q=transiciones[q][cc];
                yytext+=c;
                getChar();
                if(yyin.eof()) return token(q);
            }else{
                if(acc[q]){
                    //retorna al estado 0.
                    if(q==17){
                        q = 0;
                        yytext="";
                    }
                    else return token(q);
                }else{
                    return ERROR;
                }
            } 
        }
    }

    string Lexer::getYytext(){
        return yytext;
    } 

    void Lexer::printTTrans(){
        for(int i = 0; i<edos; i++){
            for(int j = 0; j<nsimbolos; j++){
                cout << transiciones[i][j] << "\t";
            }
            cout << acc[i] << "\t";
            cout << endl; 
        }
    }


    int Lexer::token(int q)
    {
        // TODO(7) Completar la función para que pueda retornar los tokens
        //COMPLETADO SEGÚN
        switch(q){
            case 1:
                return MAS;
            case 2:
                return MENOS;
            case 3:
                return MUL;
            case 4:
                return DIV;
            case 5:
                return ASIG;
            case 6:
                return LPAR;
            case 7:
                return RPAR;
            case 8:
                return PYC;
            case 9:
                return COMA;
            case 10 : case 20 : case 35:
                return NUMERO;
            case 12 : case 13 : case 14 : case 15 : case 16 : case 18 : case 21 :
            case 22 : case 23 : case 25 : case 26 : case 27 :  case 30 :
                return ID;
            case 17:
                return ESP;
            case 19:
                return IF;
            case 24:
                return INT;
            case 29:
                return ELSE;
            case 31:
                return FLOAT;
            case 32:
                return WHILE; 
        }
    }
}
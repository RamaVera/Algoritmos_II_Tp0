//Archivo fuente principal del tp0 para la materia 9512 Algoritmos y Programacion 2.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <limits>

#include"vector.h"
#include"Block.h"
#include"cmdline.h"
#include"TiposHash.h"

using namespace std;

//Prototipos para la utilizacion de la clase cmdline.
static void opt_input(string const &);
static void opt_output(string const &);
static void opt_method(string const &);
static void opt_help(string const &);

//Variables globales para la utilizacion de la clase cmdline.
static option_t options[] = {
    {1, "i", "input", "-", opt_input, OPT_DEFAULT},
    {1, "o", "output", "-", opt_output, OPT_DEFAULT},
    {1, "m", "method", "fft", opt_method, OPT_DEFAULT},
    {0, "h", "help", NULL, opt_help, OPT_DEFAULT},
    {0, },
};
static string method; //Variable que contendrá el método a utilizar.
static istream *iss = 0; //Input Stream (clase para manejo de los flujos de entrada).
static ostream *oss = 0; //Output Stream (clase para manejo de los flujos de salida).
static fstream ifs; //Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos).
static fstream ofs; //Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos).

//Declaración de los prototipos utilizados anteriormente.

static void
opt_input(string const &arg)
{
    //Si el nombre del archivos es "-", usaremos la entrada
    //estandar. De lo contrario, abrimos un archivo en modo
    //de lectura.
    if ( arg == "-" ) {
        iss = &cin;	//Establezco la entrada estandar cin como flujo de entrada.
    }
    else {
        ifs.open(arg.c_str(), ios::in); //c_str(): Returns a pointer to an array that contains a null-terminated
                                        //sequence of characters (i.e., a C-string) representing
                                        //the current value of the string object.
        iss = &ifs;
    }

    //Verificamos que el stream este OK.
    if ( !iss->good() ) {
        cerr << "No se puede abrir "
             << arg
             << "."
             << endl;
        exit(1);
    }
}

static void opt_output(string const &arg)
{
    //Si el nombre del archivos es "-", usaremos la salida
    //estandar. De lo contrario, abrimos un archivo en modo
    //de escritura.
    if ( arg == "-" ) {
        oss = &cout; //Establezco la salida estandar cout como flujo de salida.
    } else {
        ofs.open(arg.c_str(), ios::out);
        oss = &ofs;
    }

    //Verificamos que el stream este OK.
    if ( !oss->good() ) {
        cerr << "No se puede abrir "
             << arg
             << "."
             << endl;
        exit(1); //EXIT: Terminacion del programa en su totalidad.
    }
}

static void opt_method(string const &arg)
{
    if (arg == "dft" || arg == "idft" || arg == "fft" || arg == "ifft" || arg == "fft-iter" || arg == "ifft-iter" || arg == "fft-inplace" || arg == "ifft-inplace") {
        method = arg; //Si el argumento cargado es correcto, se lo guarda para ser utilizado.
    }
    else {
        cerr << "Error: los metodos esperados son 'dft', 'idft', 'fft', 'ifft', 'fft-iter' o 'ifft-iter' o 'fft-inplace' o 'ifft-inplace'." << endl;
        exit(1); //EXIT: Terminacion del programa en su totalidad.
    }
}

static void opt_help(string const &arg)
{
    cout << "tp0 [-m method] [-i file] [-o file]"
         << endl;
    exit(0);
}

//--------------------------------------------------------------

int main(int argc, char * const argv[]) {
    try {
        cmdline cmdl(options);	//Objeto con parametro tipo option_t (struct) declarado globalmente. Ver linea 51 main.cc
        cmdl.parse(argc, argv); //Metodo de parseo de la clase cmdline.
        // procesar_entrada(method, iss, oss); //Función que realiza los calculos y los imprime.
        return 0;
    }
    catch (const char* msg) {
        cerr << msg << endl;
        return -1;
    }
}
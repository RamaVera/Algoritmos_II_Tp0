//============================================================================
// Name        : main.cpp
// Author      : Nacachian, Urquiza, Vera
// Version     : 1.1.1
// Description : Trabajo Practico Nro. 1
//============================================================================


#include <iostream>
#include <string>
#include "cmdline.h"
#include "BlockChainManager.h"


using namespace std;


/*=====================================================================================*/
// 									PROTOTIPOS
/*=====================================================================================*/


//static void opt_input(string const &);
//static void opt_output(string const &);
//static void opt_function(string const &);
//static void opt_help(string const &);
//static bool openOutputFile();


/*=====================================================================================*/
// 								ELEMENTOS GLOBALES
/*=====================================================================================*/

//static option_t options[] = {
//	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
//	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
//	{1, "f", "function", NULL, opt_function, OPT_MANDATORY},
//	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
//	{0, },
//};


//static istream* iss = 0;
//static ostream* oss = 0;
//static fstream ifs;
//static fstream ofs;
//
//static string outputFileName;



/*====================================================================================*/
//									MAIN
/*====================================================================================*/


int main(int argc, char * const argv[]){

	//------Valido Argumentos ------//
	//cmdline cmdl(options);
	//cmdl.parse(argc, argv);

	//------Creo Imagenes de origen y destino ------//

	return 0;
}



/*====================================================================================*/
// 						FUNCIONES INVOCADAS EN EL MAIN
/*====================================================================================*/

//------------------ Callbacks de CMDLINE ------------------------------//

//static void
//opt_input(string const &arg)
//{
//	// Si el nombre del archivos es "-", usaremos la entrada
//	// est?dar. De lo contrario, abrimos un archivo en modo
//	// de lectura.
//	//
//	if (arg == "-") {
//		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
//		cout<<"La direccion del archivo Origen es : Cin (Entrada Standar)" <<endl;
//
//	}
//	else {
//		ifs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
//										// sequence of characters (i.e., a C-string) representing
//										// the current value of the string object.
//		iss = &ifs;
//		cout<<"La direccion del archivo Origen es :"<< arg.c_str() <<endl;
//
//	}
//
//	// Verificamos que el stream este OK.
//	//
//	if (!iss->good()) {
//		cerr << "cannot open "
//		     << arg
//		     << "."
//		     << endl;
//		std::abort();
//	}
//}
//
//static void
//opt_output(string const &arg)
//{
//
//	// Si el nombre del archivos es "-", usaremos la salida
//	// est?dar. De lo contrario, abrimos un archivo en modo
//	// de escritura.
//	//
//	outputFileName = arg.c_str();
//
//	if (arg == "-") {
//		//oss = &cout;	// Establezco la salida estandar cout como flujo de salida
//		cout<< "La direccion del archivo Destino es: Cout (Salida Standar)" << endl;
//	} else {
//		//ofs.open(arg.c_str(), ios::out);
//		//oss = &ofs;
//		cout<< "La direccion del archivo Destino es: "<< arg.c_str() <<endl;
//	}
//
//}
//
//static void
//opt_function(string const &arg)
//{
//	stringstream iss(arg);
//	cout<< "La transformacion elegida es f(z)= " <<arg.c_str() <<endl;
//
//	// Intentamos extraer el factor de la l?ea de comandos.
//	// Para detectar argumentos que ?nicamente consistan de
//	// n?meros enteros, vamos a verificar que EOF llegue justo
//	// despu? de la lectura exitosa del escalar.
//	//
//	string transformString;
//	//iss >> transformString;
//	transformString = iss.str();
//	if (iss.bad()) {
//		cerr << "cannot read integer factor."
//			 << endl;
//		std::abort();
//	}
//
//	TransformStatus Status = ComplexTransform::isGoodExpresion(transformString);
//	switch(Status)
//	{
//	case TransformStatus::funtionIsOk:
//		{
//		cout << "La funcion se ingreso correctamente "<< endl;
//		string parsedString = ComplexTransform::parseExpresion(transformString);
//		//cout<< "La transformacion elegida es f(z)= " << parsedString <<endl;
//		ComplexTransform::setTransform(parsedString);
//		break;
//		}
//	case TransformStatus::functionIsNotBalanced:
//		cerr << "La funcion ingresada no esta balanceada "<< endl;
//		std::abort();
//		break;
//	case TransformStatus::functionHasOperatorError:
//		cerr <<" La funcion ingresada tiene un error de sintaxis debido a un caracter "<< endl;
//		std::abort();
//		break;
//	default:
//		cerr <<" Error desconocido "<< endl;
//		std::abort();
//	}
//}
//
//static void
//opt_help(string const &arg)
//{
//	cout << "cmdline [-f function] [-i file] [-o file]" << endl;
//	cout << "Funciones Admitidas: exp, Re, Im, log, cos, sen " << endl;
//	cout << "Las expresiones matematicas no deben tener espacios en blanco " << endl;
//	std::abort();
//}
//
//
//static bool
//openOutputFile(){
//
//
//	if(outputFileName == "-")
//	{
//		oss = & cout;
//	}
//	else{
//		ofs.open(outputFileName.c_str(), ios::out);
//		oss = &ofs;
//
//	}
//	// Verificamos que el stream este OK.
//	//
//	if (!oss->good()) {
//		cerr << "cannot open "
//		<< outputFileName
//		<< "."
//		<< endl;
//
//		ifs.close();
//		return false;
//
//	}
//
//	return true;
//
//}

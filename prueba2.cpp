#include <iostream>
#include <fstream>
#include <iomanip>//left,setw,fixed,showpoint,setprecision,right
#include <cstdlib>//exit

using namespace std;

void mostrar_linea(int, const char * const, double);

int main(){
  int cuenta;
  char nombre[30];
  double saldo;

  ifstream ArchivoClientesEntrada; //archivo lógico

  ArchivoClientesEntrada.open("clientes.txt",ios::in);
  
  if(!ArchivoClientesEntrada){
    cerr << "No se pudo abrir el archivo"<<endl;
    exit(1);
  }
  cout <<left<<setw(10)<<"CUENTA"<<setw(13)<<"NOMBRE"<<"SALDO"<<endl<<fixed<<showpoint;
  
  while(ArchivoClientesEntrada>>cuenta>>nombre>>saldo){
    mostrar_linea(cuenta,nombre,saldo);
  }


  ArchivoClientesEntrada.close();

  system("pause");
  return 0;
}

//mostrar cada registro del archivo
void mostrar_linea(int cuenta,const char * const nombre, double saldo){
  cout<< left << setw(10)<< cuenta << setw(13)<< nombre <<setw(7)<< setprecision(2)<<right<<saldo<<endl;
}
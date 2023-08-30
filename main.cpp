#include <iostream>
#include "PlanArreglo.h"
#include <locale>

using namespace std;

int MenuOpciones(){
    char Opcion;
    do {
        cout<<"\n\n\nL: Leer la lista de claves: ";
        cout<<"\nA: Dar de alta un nuevo alumno: ";
        cout<<"\nB: Dar de baja un alumno: ";
        cout<<"\nI: Imprimir la lista de claves: ";
        cout<<"\nF: Finalizar el proceso. ";
        cout<<"\n\n Ingrese opción de trabajo: ";
        cin>>Opcion;
        Opcion=toupper(Opcion);
    } while (Opcion != 'A' && Opcion != 'B' && Opcion != 'L' && Opcion != 'I' && Opcion != 'F');
    return Opcion;
}

void Menu(){
    Arreglo<int> ClavAlum;
    int Clave, Res;
    char Opc;
    do {
        Opc= MenuOpciones();
        switch(Opc){
            case 'L': {
                ClavAlum.Lectura(); break;
                }
            case 'I': {
                ClavAlum.Escribe();
                break;
                }
            case 'A': {
                cout<<"\n\n Clave del nuevo alumno: ";
                cin>>Clave;
                Res= ClavAlum.InsertaDesordenado(Clave);
                if (Res == 1){
                    cout<<"\n\n El nuevo alumno ya fue dado de alta. ";
                }else{
                    if (Res == 0){
                        cout<<"\n\n No hay espacio para registrar el nuevo alumno. ";
                    }else{
                        cout<<"\n\n Esa clave ya fue registrada previamente. ";
                    }
                }
                break;
            }
            case 'B': {
                cout<<"\n\n Clave del alumno a dar de baja: ";
                cin>>Clave;
                Res= ClavAlum.EliminaDesordenado(Clave);
                if (Res == 1){
                    cout<<"\n\n El alumno ya fue dado de baja. ";
                    }else{
                        if (Res == 0){
                            cout<<"\n\n No hay alumnos registrados. ";
                        }else{
                            cout<<"\n\n Esa clave no está registrada. ";
                        }
                    break;
                    }
                }
            case 'F': cout<<"\n\n Termina el proceso.\n\n ";
                break;
            }
    } while (Opc != 'F');
}





int main(){
    setlocale(LC_ALL,"");
    Menu();
    return 0;
}

// PROMEDIO DE CALIFICACIONES DE 4 ESTUDIANTES

#include <iostream>

using namespace std;

int main()
{
    string nombre;
    float nota;
    float suma=0;
    int cantnotas=0;
    float promedio=0;
    int i=1;
    
    cout<<"Entre el nombre del participante "<<i<<":"; //Mensaje para solicitar el nombre del participante
    cin>>nombre; //Insertar nombre
    cout<<"Entre la nota de matematica de "<<nombre<<":"; //Solicitar nota al usuario
    cin>>nota; //insertar nota
    suma+=nota; //sumar la nota insertada en la variable suma
    cantnotas++; //incrementar en uno, haciendo referencia que se ha guardado una nota
    i++; //incrementamos en uno para tener la opcion de insertar los proximos datos
    
    cout<<"Entre el nombre del participante "<<i<<":";
    cin>>nombre;
    cout<<"Entre la nota de matematica de "<<nombre<<":";
    cin>>nota;
    suma+=nota;
    cantnotas++;
    i++;
    
    cout<<"Entre el nombre del participante "<<i<<":";
    cin>>nombre;
    cout<<"Entre la nota de matematica de "<<nombre<<":";
    cin>>nota;
    suma+=nota;
    cantnotas++;
    i++;
    
    cout<<"Entre el nombre del participante "<<i<<":";
    cin>>nombre;
    cout<<"Entre la nota de matematica de "<<i<<":";
    cin>>nota;
    suma+=nota;
    cantnotas++;
    if(suma!=0)
    {
        promedio=suma/cantnotas;
        cout<<"El promedio de calificaciones es: "<<promedio;
        
    }
    else
    cout<<"Verifique que los participantes se hayan examinado";

    return 0;
}

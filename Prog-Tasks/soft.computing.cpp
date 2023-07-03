#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Trabajador {
public:
    std::string nombre;
    int edad;
    char sexo;
    double salario;
    int horas_trabajadas;

    Trabajador(std::string nombre, int edad, char sexo, double salario, int horas_trabajadas)
        : nombre(nombre), edad(edad), sexo(sexo), salario(salario), horas_trabajadas(horas_trabajadas) {}
};

class Empresa {
public:
    std::string nombre;
    std::string direccion;
    std::vector<Trabajador> trabajadores;

    Empresa(std::string nombre, std::string direccion)
        : nombre(nombre), direccion(direccion) {}
};

int main() {
    // Crear la empresa y la lista de trabajadores
    Empresa softcomputing("SoftComputing", "Calle Falsa 123, Ciudad Ficticia");
    softcomputing.trabajadores = {
        Trabajador("Juan", 35, 'M', 12000, 230),
        Trabajador("Maria", 28, 'F', 9000, 210),
        Trabajador("Carlos", 42, 'M', 18000, 250),
        Trabajador("Sofia", 30, 'F', 11000, 190)
    };

    // Ordenar la lista de trabajadores por edad ascendente
    std::sort(softcomputing.trabajadores.begin(), softcomputing.trabajadores.end(),
              [](const Trabajador& a, const Trabajador& b) {
                  return a.edad < b.edad;
              });

    // Imprimir información de la empresa y la lista de trabajadores
    std::cout << "Nombre de la empresa: " << softcomputing.nombre << std::endl;
    std::cout << "Dirección postal de la empresa: " << softcomputing.direccion << std::endl;

    std::cout << "Lista de trabajadores de la empresa ordenados por edad ascendente:" << std::endl;
    for (const Trabajador& trabajador : softcomputing.trabajadores) {
        std::cout << "Nombre: " << trabajador.nombre
                  << ", Edad: " << trabajador.edad
                  << ", Sexo: " << trabajador.sexo
                  << ", Salario: " << trabajador.salario
                  << ", Horas trabajadas: " << trabajador.horas_trabajadas
                  << std::endl;
    } 
    return 0;
    
     }
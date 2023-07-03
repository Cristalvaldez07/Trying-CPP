#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Clase Medicamento
class Medicamento {
public:
    Medicamento(string codigo, string nombre, string fechaFabricacion, string fechaVencimiento, int existenciaFisica, float precioUnitario) {
        this->codigo = codigo;
        this->nombre = nombre;
        this->fechaFabricacion = fechaFabricacion;
        this->fechaVencimiento = fechaVencimiento;
        this->existenciaFisica = existenciaFisica;
        this->precioUnitario = precioUnitario;
    }

    // Métodos de acceso
    string getCodigo() { return codigo; }
    string getNombre() { return nombre; }
    string getFechaFabricacion() { return fechaFabricacion; }
    string getFechaVencimiento() { return fechaVencimiento; }
    int getExistenciaFisica() { return existenciaFisica; }
    float getPrecioUnitario() { return precioUnitario; }

    // Métodos de modificación
    void setExistenciaFisica(int existenciaFisica) { this->existenciaFisica = existenciaFisica; }
    void setPrecioUnitario(float precioUnitario) { this->precioUnitario = precioUnitario; }

private:
    string codigo;
    string nombre;
    string fechaFabricacion;
    string fechaVencimiento;
    int existenciaFisica;
    float precioUnitario;
};

// Clase Estante
class Estante {
public:
    // Método para agregar un nuevo medicamento al estante
    void agregarMedicamento(Medicamento medicamento) {
        medicamentos.push_back(medicamento);
    }

    // Método para obtener el código del medicamento más vendido
    string getCodigoMedicamentoMasVendido() {
        if (medicamentos.empty()) {
            return "";
        }

        sort(medicamentos.begin(), medicamentos.end(), [](Medicamento m1, Medicamento m2) {
            return m1.getExistenciaFisica() > m2.getExistenciaFisica();
        });

        return medicamentos[0].getCodigo();
    }

    // Método para calcular el precio unitario de un medicamento dado su código
    float calcularPrecioUnitario(string codigoMedicamento) {
        for (Medicamento medicamento : medicamentos) {
            if (medicamento.getCodigo() == codigoMedicamento) {
                if (medicamento.getPrecioUnitario() == -1) {
                    // Calcular el precio unitario si es un medicamento nacional
                    float costoDeProduccion = 100;  // Supongamos que el costo de producción es de 100
                    float precioUnitario = costoDeProduccion * 0.6;  // Aplicamos un 6% de costo de almacenamiento
                    medicamento.setPrecioUnitario(precioUnitario);
                }

                return medicamento.getPrecioUnitario();
            }
        }

        return -1;
    }

    // Método para obtener la cantidad de medicamentos nacionales cuyo precio de venta está por encima de un valor dado
    int getCantidadMedicamentosNacionalesPorEncimaDe(float valor) {
        int cantidad = 0;

        for (Medicamento medicamento : medicamentos) {
            if (medicamento.getPrecioUnitario() != -1 && medicamento.getPrecioUnitario() > valor) {
                cantidad++;
            }
        }

        return cantidad;
    }

private:
    vector<Medicamento> medicamentos;
};

int main() {
    Estante estante;

    int opcion;
    do {
        // Mostrar el menú de opciones
        cout << "Farmacia" << endl;
        cout << "1. Agregar un nuevo medicamento" << endl;
        cout << "2. Mostrar el código del medicamento más vendido" << endl;
        cout << "3. Calcular el precio unitario de un medicamento" << endl;
        cout << "4. Mostrar la cantidad de productos nacionales cuyo precio de venta está por encima de un valor dado" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese la opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                // Pedir los datos del nuevo medicamento y agregarlo al estante
                string codigo, nombre, fechaFabricacion, fechaVencimiento;
                int existenciaFisica;
                cout << "Ingrese el código del medicamento: ";
                cin >> codigo;
                cout << "Ingrese el nombre del medicamento: ";
                cin >> nombre;
                cout << "Ingrese la fecha de fabricación del medicamento (DD/MM/AAAA): ";
                cin >> fechaFabricacion;
                cout << "Ingrese la fecha de vencimiento del medicamento (DD/MM/AAAA): ";
                cin >> fechaVencimiento;
                cout << "Ingrese la existencia física del medicamento: ";
                cin >> existenciaFisica;

                Medicamento medicamento(codigo, nombre, fechaFabricacion, fechaVencimiento, existenciaFisica, -1);
                estante.agregarMedicamento(medicamento);

                cout << "Medicamento agregado correctamente" << endl;

                break;
            }
            case 2: {
                // Mostrar el código del medicamento más vendido
                string codigoMedicamentoMasVendido = estante.getCodigoMedicamentoMasVendido();
                if (codigoMedicamentoMasVendido == "") {
                    cout << "No hay medicamentos registrados en el estante" << endl;
                } else {
                    cout << "El código del medicamento más vendido es: " << codigoMedicamentoMasVendido << endl;
                }

                break;
            }
            case 3: {
                // Calcular el precio unitario de un medicamento dado su código
                string codigoMedicamento;
                cout << "Ingrese el código del medicamento: ";
                cin >> codigoMedicamento;

                float precioUnitario = estante.calcularPrecioUnitario(codigoMedicamento);
                if (precioUnitario == -1) {
                    cout << "El medicamento no está registrado en el estante" << endl;
                } else {
                    cout << "El precio unitario del medicamento es: " << precioUnitario << endl;
                }

                break;
            }
            case 4: {
                // Mostrar la cantidad de medicamentos nacionales cuyo precio de venta está por encima de un valor dado
                float valor;
                cout << "Ingrese el valor: ";
                cin >> valor;

                int cantidad = estante.getCantidadMedicamentosNacionalesPorEncimaDe(valor);
                cout << "La cantidad de medicamentos nacionales cuyo precio de venta está por encima de " << valor << " es: " << cantidad << endl;

                break;
            }
            case 5: {
                cout << "Ha salido del programa de manera exitosa " << endl;
                break;
            }
            default: {
                cout << "Opción inválida, por favor intente de nuevo" << endl;
                break;
            }
        }
    } while(opcion != 5);

    return 0;
}
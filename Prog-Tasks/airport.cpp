#include <iostream>
#include <cstring>
using namespace std;

//Declarando clase padre Aeronave
class Aeronave
{
 private:
 string matricula;
 double capacidad;
 int kmRecorridos;
 int tipoaeronave;
 double impuesto;
 public:
 Aeronave();
 Aeronave(string matricula, double capacidad, int kmRecorridos, int tipoaeronave, double
impuesto);

 //Métodos de escritura
 void SetMatricula(string m);
 void SetCapacidad(double c);
 void SetKmRecorridos(int k);
 void SetTipoAeronave(int ti);

 //Métodos de lectura y devuelve el valor
 string GetMatricula();
 double GetCapacidad();
 int GetKmRecorridos();
 int GetTipoAeronave();
 virtual double Impuesto();
 virtual void MostrarDatosAeronave();


};

//Declarando clases hijas que heredan de la clase Padre Aeronave
class Pasajero : public Aeronave
{
 private:
 int cantPrimera, cantTuristica;
 public:
 Pasajero();
 Pasajero(string matricula, int capacidad, int kmRecorridos, int tipoaeronave, double
impuesto, int cantPrimera, int cantTuristica);
 void SetCantPrimera(int cantP);
 void SetCantTurista(int cantT);
 int GetPasajerosPClase();
 int GetPasajetosClaseT();
 void MostrarDatosAeronave() override;
 double Impuesto() override;

};
class Jets : public Aeronave
{
 private:
 string firma;
 double precio;
 public:
 Jets();
 Jets(string matricula, int capacidad, int kmRecorridos, int tipoaeronave, double impuesto,
string firma, double precio);
 void SetFirma(string fir);
 void SetPrecio(double pre);
 string GetFirma();
 double GetPrecio();
 void MostrarDatosAeronave() override;
 double Impuesto() override;


};

//Definiendo la clase controladora Torre
class Torre
{
 protected:
 Aeronave **aeronaves;
 int cantReal;
 public:
 Torre();
 ~Torre();
 int GetCantReal();
 void Adicionar(Aeronave * aero);
 void MostrarDatosAeronave();
 string MatriculaAvionMayorImpuesto(); //Devuelve matrícula del avión que pagará un mayor impuesto por la utilización del espacio aéreo
 int CantidadJetsVolandoEspacioAereo(); //Devuelve la cantidad de Jets que están sobrevolando el espacio aéreo.
};

//Inicializando constructores de las clases: clase padre Aeronave, clases hijas, Pasajero y Jets, clase controladora Torre
Aeronave::Aeronave(string matricula, double capacidad, int kmRecorridos, int tipoaeronave,
double impuesto)
{
 this->matricula = matricula;
 this->capacidad = capacidad;
 this->kmRecorridos = kmRecorridos;
 this->tipoaeronave = tipoaeronave;
 this->impuesto = impuesto;
}
Pasajero::Pasajero(string matricula, int capacidad, int kmRecorridos, int tipoaeronave, double
impuesto, int cantPrimera, int cantTuristica):Aeronave(matricula, capacidad, kmRecorridos,
tipoaeronave, impuesto)
{
 this->cantPrimera = cantPrimera;
 this->cantTuristica = cantTuristica;
}
Jets::Jets(string matricula, int capacidad, int kmRecorridos, int tipoaeronave, double impuesto,
string firma, double precio):Aeronave(matricula, capacidad, kmRecorridos, tipoaeronave,
impuesto)
{
 this->firma = firma;
 this->precio = precio;
}
Torre::Torre()
{
 cantReal=0;
 aeronaves = new Aeronave * [100];
}

//Destructor del arreglo de objetos
Torre::~Torre()
{
 for(int i = 0; i < cantReal; i++)
 delete aeronaves[i];
 delete []aeronaves;
}

//Métodos de lectura (Get) y escritura (Set)
void Aeronave::SetMatricula(string m)
{
 matricula=m;
}
void Aeronave::SetCapacidad(double c)
{
 capacidad=c;
}
void Aeronave::SetKmRecorridos(int k)
{
 kmRecorridos=k;
}
void Aeronave::SetTipoAeronave(int ti)
{
 tipoaeronave=ti;
}
double Aeronave::Impuesto()
{
 return impuesto;
}
void Pasajero::SetCantPrimera(int cantP)
{
 cantPrimera=cantP;
}
void Pasajero::SetCantTurista(int cantT)
{
 cantTuristica=cantT;
}

//Método polimórfico para calcular el impuesto de la Aeronave Pasajero
double Pasajero::Impuesto()
{
 double impues;
 int ca=GetCapacidad();
 int pPC=GetPasajerosPClase();
 int pCT=GetPasajetosClaseT();
 int kmr=GetKmRecorridos();
 impues=(ca*(pPC+pCT))*kmr;
 return impues;
}
double Jets::Impuesto()
{
 double impues;
 int ca=GetCapacidad();
 double precp=GetPrecio();
 int kmr=GetKmRecorridos();
 impues=ca*precp/kmr;
 return impues;
}
void Jets::SetFirma(string fir)
{
 firma=fir;
}
void Jets::SetPrecio(double pre)
{
 precio=pre;
}
int Torre::GetCantReal()
{
 return cantReal;
}
string Aeronave::GetMatricula()
{
 return matricula;
}
double Aeronave::GetCapacidad()
{
 return capacidad;
}
int Aeronave::GetKmRecorridos()
{
 return kmRecorridos;
}

int Aeronave::GetTipoAeronave()
{
 return tipoaeronave;
}
int Pasajero::GetPasajerosPClase()
{
 return cantPrimera;
}
int Pasajero::GetPasajetosClaseT()
{
 return cantTuristica;
}
string Jets::GetFirma()
{
 return firma;
}
double Jets::GetPrecio()
{
 return precio;
}

//Método para guardar los objetos de tipo Aeronave (Avión de Pasajeros y Avión Jets) en el arreglo aeronaves
void Torre::Adicionar(Aeronave * aero)
{
 aeronaves[cantReal]=aero;
 cantReal++;
}

//Polimorfismo. Método virtual de la clase padre Aeronave
void Aeronave::MostrarDatosAeronave()
{
 cout<<"Matrícula: "<<this->GetMatricula()<<'\t'<<"Capacidad: "<<this->GetCapacidad()<<'\t'<<"Km Recorridos: "<<this->GetKmRecorridos()<<endl;
};

//Método mostrar datos de los objetos Aeronave tipo Pasajero
void Pasajero::MostrarDatosAeronave()
{
 cout<<"Aeronave tipo Pasajero"<<endl;
 cout<<"Matrícula: "<<this->GetMatricula()<<'\t'<<"Capacidad: "<<this->GetCapacidad()<<'\t'<<"Kms Recorridos: "<<this->GetKmRecorridos()<<'\t'<<"1er Clase:"<<this->GetPasajerosPClase()<<'\t'<<"Clase Turista: "<<this->GetPasajetosClaseT()<<endl;
 cout<<"Impuesto espacio aéreo: "<<(this->GetCapacidad()*(this->GetPasajerosPClase()+this->GetPasajetosClaseT()))*this->GetKmRecorridos()<<"DOP"<<endl;
}

//Método mostrar datos de los objetos Aeronave tipo Jets
void Jets::MostrarDatosAeronave()
{
 cout<<"Aeronave tipo Jet"<<endl;
 cout<<"Matrícula: "<<this->GetMatricula()<<'\t'<<"Capacidad: "<<this->GetCapacidad()<<'\t'<<"Kms Recorridos: "<<this->GetKmRecorridos()<<'\t'<<"Firma: "<<this->GetFirma()<<'\t'<<"Precio: "<<this->GetPrecio()<<endl;
 cout<<"Impuesto espacio aéreo: "<<(this->GetCapacidad()*this->GetPrecio())/GetKmRecorridos()<<"DOP"<<endl;
}

//Método mostrar datos de las aeronaves de la clase controladora
void Torre::MostrarDatosAeronave()
{
 for(int i=0; i<cantReal; i++)
 {
 cout<<"Datos de la Aeronave"<<i+1<<endl;
 if(aeronaves[i]->GetTipoAeronave()==1)
 {
 cout<<"Aeronave de pasajero"<<endl;
 aeronaves[i]->MostrarDatosAeronave();
 }
 else
 {
 cout<<"Aeronave Jet"<<endl;
 aeronaves[i]->MostrarDatosAeronave();
 }
 }
}

//La matrícula del avión que pagará un mayor impuesto por la utilización del espacio aéreo.
string Torre::MatriculaAvionMayorImpuesto()
{
 double mayor_impuesto;
 string mat_aer;

 mayor_impuesto=0;

 for(int i=0; i<cantReal; i++)
 {

 if(aeronaves[i]->Impuesto()>mayor_impuesto)
 {
 mayor_impuesto=aeronaves[i]->Impuesto();

 }

 mat_aer=aeronaves[i]->GetMatricula();
 }

 return mat_aer;
}

//Cantidad de Jets que están sobrevolando el espacio aéreo.
int Torre::CantidadJetsVolandoEspacioAereo()
{
 int cant_jets_vol=0;

 for(int i=0; i<cantReal; i++)
 {
 if(aeronaves[i]->GetTipoAeronave() == 2)

 cant_jets_vol++;

 }
 return cant_jets_vol;
}

//Función principal para la ejecución del programa en consola
int main()
{
 string ma;
 double ca;
 int kmr;
 int tip;
 int imp;
 int cantAeronaves=0;
 int i=0;

 //Datos Aeronave de Pasajeros
 int cP;
 int cT;

 //Datos Aeronave Jets
 string fir;
 double pre;
 Aeronave * aernuevo;
 
 //Entrar datos de la Aeronave
 cout<<"Cantidad de aeronaves dentro del corredor aéreo: ";
 cin>>cantAeronaves;
 Torre * to = new Torre();
 do
 {
 cout<<"Datos de la Aeronave: "<<i+1<<endl;
 cout<<"Matrícula: ";
 cin>>ma;
 cout<<"Capacidad: ";
 cin>>ca;
 cout<<"Kilómetros: ";
 cin>>kmr;
 cout<<"Tipo Aeronave: ";
 cin>>tip;
 if(tip==1)
 {
 Pasajero *p;
 cout<<"Cantidad Pasajeros en Primera Clase: ";
 cin>>cP;
 cout<<"Cantidad Pasajeros en Clase Turista: ";
 cin>>cT;
 imp=p->Impuesto();
 aernuevo = new Pasajero (ma, ca, kmr, tip, imp, cP, cT);
 }
 else
 {
 Jets *j;
 cout<<"Firma del Jet: ";
 cin>>fir;
 cout<<"Precio del Jet: ";
 cin>>pre;
 imp=j->Impuesto();
 aernuevo = new Jets (ma, ca, kmr, tip, imp, fir, pre);
 }
 to->Adicionar(aernuevo);
 cantAeronaves--;
 i++;
 }
 while(cantAeronaves!=0);

 to->MostrarDatosAeronave();

 cout<<"Matrícula del avión que pagará un mayor impuesto por la utilización del espacioaéreo: "<<to->MatriculaAvionMayorImpuesto()<<endl;
 cout<<"Cantidad de Jets que están sobrevolando el espacio aéreo: "<<to->CantidadJetsVolandoEspacioAereo();

 return 0;
}
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Punto{
    private:
       double x, h;
    public:
        Punto();
        void setPunto(double, double);
        double getPuntoX();
        double getPuntoH();
};

Punto::Punto(){};

void Punto::setPunto(double _x, double _h){
    x= _x;
    h= _h;
}

double Punto::getPuntoH(){
    return h;
}

double Punto::getPuntoX(){
    return x;
}

class Funcion{
    private:
        double resultado;
    public:
        Funcion();
        void setFuncion(double);
        double getFuncion();
        double seleccionar_operacion(int,double,double);
        double resolucion_diferencia_centales(double,double);
        int menu();
};

Funcion::Funcion(){}

void Funcion::setFuncion(double _resultado){
    resultado=_resultado;
}

double Funcion::getFuncion(){
    return resultado;
}

/**menu**/
int Funcion::menu(){
   int opcion;

    cout<<endl<<"\tIngresa la operacion desea realizar"<<endl<<endl;
    cout<<"  1- (a+b)                 6- sqrt(a,b)"<<endl;
    cout<<"  2- (a-b)                 7- (a+b)*c"<<endl;
    cout<<"  3- (a*b)                 8- (a-b)*c"<<endl;
    cout<<"  4- (a/b)                 9- (a+b)/c"<<endl;
    cout<<"  5- a^b                   10- (a-b)/c"<<endl;
   cin>>opcion;

   return opcion;
}


/**carga de funcion y resolucion de la parte de arriba del metodo por Diferncias Centrales**/
double Funcion::seleccionar_operacion(int opc, double x1, double x2){
    double rta1=0;
    double rta2=0;

    double resultado_x1=0;
    double resultado_x2=0;

    double numero1=0, numero2=0, numero3=0;
    double number1=0, number2=0, number3=0;

    char operador;

    int flag=0;
    int opcion=0;

do{
    if(flag>0){
        cout<<endl<<"\tIngresa la operacion desea realizar."<<endl<<endl;
        cout<<"  1- (a+b)                 6- sqrt(a,b)"<<endl;
        cout<<"  2- (a-b)                 7- (a+b)*c"<<endl;
        cout<<"  3- (a*b)                 8- (a-b)*c"<<endl;
        cout<<"  4- (a/b)                 9- (a+b)/c"<<endl;
        cout<<"  5- a^b                   10- (a-b)/c"<<endl;
        cin>>opc;
        if(opc>10){
            return (resultado_x1-resultado_x2);
        }
    }
    if(opc!=5 && opc!=6){
        cout<<"1: Ingresar primer numero"<<endl<<" 2:'X' para ingresar la incognita."<<endl;
        cout<<"En caso de solo agregar un numero, agregar el numero cero (0)."<<endl;
    }else{
        if(opc==5){
            cout<<"1: Ingresar la base "<<endl<<"2:'X' para ingresar la incognita."<<endl;
            cout<<"En caso de solo agregar un numero, agregar el numero cero (0)."<<endl;}
            else{
                cout<<" 1:Ingresar el radicando"<<endl<<"2:'X' para ingresar la incognita."<<endl;
                cout<<"En caso de solo agregar un numero, agregar el numero cero (0)."<<endl;
            }
        }

    cin>>opcion;

   if(opcion==1){
        cout<<"Ingrese numero: "<<endl;
        cout<<"En caso de solo agregar un numero, agregar el numero cero (0)."<<endl;
        cin>>numero1;
        number1=numero1;
   }else{
       if(opcion==0){
           number1=0, numero1=0;
       }
        else{
                numero1=x1;
                number1=x2;
            }
        }

  /**-----------------------------------------------------------------**/
    if(opc!=5 && opc!=6){
    cout<<endl<<"1: Ingresar segundo numero: "<<endl<<"2:'X' para ingresar la incognita."<<endl;
    cout<<"En caso de solo agregar un numero, agregar el numero cero (0)."<<endl;}
    else{
        if(opc==5){
            cout<<endl<<"1: Ingresar el exponente"<<endl<<"2:'X' para ingresar la incognita."<<endl;
            cout<<"En caso de solo agregar un numero, agregar el numero cero (0)."<<endl;
        }else{
            cout<<endl<<"1: Ingresar el indice"<<endl<<"2:'X' para ingresar la incognita."<<endl;
            cout<<"En caso de solo agregar un numero, agregar el numero cero (0)."<<endl;
        }
    }

   cin>>opcion;

   if(opcion==1){
        cout<<"Ingrese numero: "<<endl;
        cout<<"En caso de solo agregar un numero, agregar el numero cero (0)."<<endl;
        cin>>numero2;
        number2=numero2;
   }else{
       if(opcion==0){
           number2=0, numero2=0;
       }
        else{
                numero2=x1;
                number2=x2;
            }
        }
   /**-----------------------------------------------------------------**/
    if(opc>=7){
        cout<<"1: Ingresar tercer numero"<<endl<<"2:'X' para ingresar la incognita."<<endl;
        cin>>opcion;

           if(opcion==1){
                cout<<"Ingrese numero: "<<endl;
                cin>>numero3;
                number3=numero3;
           }else{
                numero3=x1;
                number3=x2;
           }
    }

     /**-----------------------------------------------------------------**/

    switch(opc){
        case 1:
            rta1=numero1+numero2;
            rta2=number1+number2;
            break;
        case 2:
            rta1=numero1-numero2;
            rta2=number1-number2;
            break;
        case 3:
            rta1=numero1*numero2;
            rta2=number1*number2;
            break;
        case 4:
            if(numero2 == 0 || number2==0){
                cout<<" NO SE PUEDE DIVIDIR POR 0!"<<endl;
                break;
            }
            rta1=numero1/numero2;
            rta2=number1/number2;

            break;
        case 5:
            rta1=pow(numero1,numero2);
            rta2=pow(number1,number2);
            break;

        case 6:
            if(numero2==1 || number2==1){
                rta1=numero1;
                rta2=number1;
                 break;
            }
            else{
                if(numero2==2 || number2==2){
                    rta1=sqrt(numero1);
                    rta2=sqrt(number1);
                     break;
                }
                if(numero2==3 || number2==3){
                    rta1=cbrt(numero1);
                    rta2=cbrt(number1);
                     break;
                }
                if(numero2==4){
                    rta1=pow(numero1, 0.25);
                    rta2=pow(number1, 0.25);
                     break;
                }
                if(numero2==5){
                    rta1=pow(numero1, 0.2);
                    rta2=pow(number1, 0.2);
                    break;
                }
            }
            break;
        case 7:
             rta1=(numero1+numero2)*numero3;
             rta2=(number1+number2)*number3;
            break;
        case 8:
            rta1=(numero1-numero2)*numero3;
             rta2=(number1-number2)*number3;
            break;
        case 9:
            if(numero3 == 0){
                cout<<"NO SE PUEDE DIVIDIR POR 0!"<<endl;
                break;
            }
            rta1=(numero1+numero2)/numero3;
             rta2=(number1+number2)/number3;
            break;
        case 10:
            if(numero3 == 0){
                cout<<"NO SE PUEDE DIVIDIR POR 0!"<<endl;
                break;
            }
            rta1=(numero1-numero2)/numero3;
             rta2=(number1-number2)/number3;
            break;

    }
 /**-----------------------------------------------------------------**/
    if(flag==1){
        resultado_x1+=rta1;
        resultado_x2+=rta2;
    }
    if(flag==2){
        resultado_x1-=rta1;
        resultado_x2-=rta2;
    }else{
        resultado_x1=rta1;
        resultado_x2=rta2;
    }

   /**-----------------------------------------------------------------**/
    cout<<endl<<" ¿Desea ingresar otra operacion? 1: SI    2:NO."<<endl;
    cin>>opcion;
    if(opcion==1){
        cout<<"Ingrese el operador. ('+' o '-') o pulse cualquier tecla para salir."<<endl;
        cin>>operador;
        if(operador=='+'){
                flag=1;
                rta1=0;
                rta2=0;
        }
       else{ if(operador=='-'){
            flag=2;
            rta1=0;
            rta2=0;
        }else{
            return (resultado_x1-resultado_x2);
        }
       }

    }
}while(opcion==1);

   /**-----------------------------------------------------------------**/

       return (resultado_x1-resultado_x2);
}
/**----------------------------------------------------------------------------------------------------------**/
double Funcion::resolucion_diferencia_centales(double rta, double punto_h){
    return rta/(2*punto_h);
}

int main(){
    Punto punto;
    Funcion funcion; /**clases instanciadas**/

    double punto_x=0;
    double punto_h=0;

    double diferencia=0;
    double suma=0;
    int op=0;

    int opcion=0;
    double resultado_resta=0;
    double resultado_diferencias_centrales=0;
    char operador;

    cout<<endl<<"BIENVENIDO AL SISTEMA"<<endl<<endl;
    cout<<"1:  Calcular derivacion numerica mediante el metodo de Diferencias Centrales."<<endl;
    cout<<endl<<"  f'(Xo) = "<<"f(X0 + h ) + f( Xo - h ) "<<"\n\t---------------------------  "<<"\n\t\t2h"<<endl;
    cout<<"    Pulse cualquier tecla para salir."<<endl<<endl;
    cin>>op;

    while(op==1){
        cout<<"1:  Ingresar los puntos X y H para comenzar."<<endl;
        cout<<"    Pulse cualquier tecla para salir."<<endl<<endl;
        cin>>op;

        if(op==1){
            cout<<" Cargar punto X"<<endl;
            cin>>punto_x;
            cout<<" Cargar punto H"<<endl;
            cin>>punto_h;
            cout<<endl<<"  f'(x) = "<<"f("<<punto_x<<" + "<<punto_h<<") - f("<<punto_x<<" - "<<punto_h<<" )"<<"\n\t---------------------------  "<<"\n\t\t2 * ("<<punto_h<<")"<<endl;
            punto.setPunto(punto_x, punto_h);
            diferencia = punto.getPuntoX()-punto.getPuntoH();
            suma = punto.getPuntoX()+punto.getPuntoH();
            cout<<endl<<"  f'(x) = "<<"f("<<suma<<") - f("<<diferencia<<")"<<"\n\t  ----------------  "<<"\n\t\t "<<2*punto_h<<endl;
        }

        cout<<endl<<"la obtencion de la suma de los puntos X y H es "<<suma<<endl;
        cout<<"La obtencion de la resta de los puntos x y H es "<<diferencia<<endl<<endl;

        opcion=funcion.menu();

        resultado_resta=funcion.seleccionar_operacion(opcion, suma, diferencia);
        resultado_diferencias_centrales=funcion.resolucion_diferencia_centales(resultado_resta,punto_h);

        funcion.setFuncion(resultado_diferencias_centrales);
         cout<<endl<<"  f'(x)=\t  "<<resultado_resta<<"\n\t--------------------   =  "<<funcion.getFuncion()<<"\n\t\t2 * ("<<punto_h<<")"<<endl;
        cout<<endl<<"El resultado de la ecuacion utilizando derivacion numerica con el metodo de Diferencias Centrales es: "<<funcion.getFuncion()<<endl;
        cout<<endl<<"¿Desea realizar otra derivacion de analisis numerico? 1: SI      2: NO"<<endl;
        cin>>op;
        }


    cout<<endl<<"MUCHAS GRACIAS POR USAR EL SISTEMA"<<endl;
    return 0;
}





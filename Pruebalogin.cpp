#include <iostream>
using namespace std;

//declaracion define
#define PASSWORD "vector"

bool flagPass = false;
void printMenuE(void);
void printMenuA(void);
void login();

int main(void){
    string password = "";
    bool continuar = false;
    int user = 0;
    int opcion = 0;
    bool endprogram = true;
    
    cout << "------Pizzeria Jaritinu------" <<endl;
    cout << "1. Empleado";
    cout << "2. Administrador";
    cout << "Seleccione el tipo de usuario (1 o 2): ";
    cin >> user;
        
    do{
        if(flagPass == true){
            printMenuA();
            switch(opcion){
                    case 1: login(); break;
                   // case 2: addRestaurantOrder(); break;
                 //   case 3: showDeliveryOrder(); break;
                  //  case 4: searchOrderbyClient();break;
                  // // case 5: delteOrder();break;
                  //  case 6: showRestaurantOrder();break;
                   // case 7: totalSells();break;
                    case 8: endprogram = false;
            }

        }else{
            printMenuE();
        }

    }while(continuar);

    return 0;
}

void printMenuE(void){
    cout << "\n1. Agregar orden a domicilio\n";
    cout << "2.  Agregar orden en restaurante\n";
    cout << "3.  Ver ordenes a domicilio\n";
    cout << "4.  Ver ordenes en restaurantes\n";
    cout << "5.  Despachar ordenes a domicilio\n";
    cout << "6.  Despachar ordenes a restaurante\n";
    cout << "7.  Ver tiempo promedio de espera a domicilio\n";
    cout << "8.  Ver tiempo promedio de espera restaurante\n";
    cout << "9. Calcular total de ventas\n";
    cout << "10. Cambia de usuario\n";
    cout << "11. Salir\n";
    cout << "Opcion: ";
}

void printMenuA(void){
    cout << "\n1. Agregar orden a domicilio\n";
    cout << "2.  Agregar orden en restaurante\n";
    cout << "3.  Ver ordenes a domicilio\n";
    cout << "4.  Ver ordenes en restaurantes\n";
    cout << "5.  Despachar ordenes a domicilio\n";
    cout << "6.  Despachar ordenes a restaurante\n";
    cout << "7.  Ver tiempo promedio de espera a domicilio\n";
    cout << "8.  Ver tiempo promedio de espera restaurante\n";
    cout << "9.  Cancelar orden\n";
    cout << "10. Calcular total de ventas\n";
    cout << "11. Cambia de usuario\n";
    cout << "12. Salir\n";
    cout << "Opcion: ";
}

void login(){

}


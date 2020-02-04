#include <iostream>
#include <string>

//declaracion define
#define PASSWORD "vector"

using namespace std;

enum mainDish {pizza, pasta, lasagna};
enum drink {beer, soda, tea};
enum starter {garlicBread, pizzaRolls, cheeseSticks};
enum paymentType {cash,card};

//declaraciones de estrucuturas
struct address{
    int houseNumber;
    string suburb;
    string city;
    string estate;
};

struct mainInfo{
    string name;
    mainDish pDish;
    drink pDrink;
    starter pStarter;
    paymentType pay;
    int idOrder;
    float total;
    int time;
};

struct deliveryOrder{
    address clientAddress;
    int telephone;
    mainInfo deliveryInfo;
};

struct restaurantOrder{
    int cTable;
    mainInfo houseInfo;
};

//variables globales
int idDeliveryNumber = 0;
int idRestaurantNumber = 0;
int restaurantOrderNumber = 0;
int deliveryOrderNumber = 0;
deliveryOrder* deliveryList;
restaurantOrder* restaurantList;
bool flagPass = false;
int user = 0;
int counterPass = 0;
//Prototipos
void addDeliveryOrder(), addRestaurantOrder(), showDeliveryOrder(),showRestaurantOrder(), searchOrderbyClient(), delteOrder(), printMenuA(void),printMenuE(void);
bool loginUser(void);

int main(){
    // Mostrar menu al usuario
    
    bool endprogram = true;
    int opcion = 0;
    cout << "------Pizzeria Jaritinu------" <<endl;
    cout << "1. Administrador";
    cout << "2. Empleado";
    cout << "Seleccione el tipo de usuario (1 o 2): ";
    cin >> user;
    do{
        switch (user)
        {
        case 1:
           /* do{
                cout << "Digite el password: ";
                getline(cin,password);
                if (password.compare(PASSWORD) == 0){
                    flagPass = true;
                }
                else{
                    cout << "\nPassword incorrecto." << endl;
                    counterPass++;
                }
            }while (flagPass == false && counterPass < 3);
        */
        do{
            if (flagPass == true){
        //        bool continuar = true;
                    printMenuA(),
                    cin >> opcion;
                    cin.ignore();
                    
                    switch(opcion){
                        case 1: addDeliveryOrder(); break;
                        case 2: addRestaurantOrder(); break;
                        case 3: showDeliveryOrder(); break;
                        case 4: searchOrderbyClient();break;
                        case 5: delteOrder();break;
                        case 6: showRestaurantOrder();break;
                        case 7: totalSells();break;
                        case 8: endprogram = false; break;
                    }
                
            }
            else{
                flagPass = loginUser();
                if(counterPass==3)
                    endprogram = false;
            }
        }while(endprogram);
            break;
        case 2:
            
            do{
                    int opcion = 0;
                    printMenuE();
                    cin >> opcion;
                    cin.ignore();
                    
                    switch(opcion){
                        case 1: addDeliveryOrder(); break;
                        case 2: addRestaurantOrder(); break;
                        case 3: showDeliveryOrder(); break;
                        case 4: searchOrderbyClient();break;
                        case 5: showRestaurantOrder();break;
                        case 6: totalSells();break;
                        case 7: loginUser();break;
                        case 8: endprogram = false; break;
                    }
                }while(endprogram);
        default:
            return 0;
            break;
        }
    }while(endprogram);

    
    return 0;
}

bool loginUser(){
    string password = "";
    
    do{
        cout << "Digite el password: ";
        getline(cin,password);
        if (password.compare(PASSWORD) == 0){
            flagPass = true;
            counterPass = 0;
        }
        else{
            cout << "\nPassword incorrecto." << endl;
            counterPass++;
        }
    }while (flagPass == false && counterPass < 3);
    if(counterPass == 3)
        flagPass = false;

    return flagPass;
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

void addDeliveryOrder(){

} 
void addRestaurantOrder(){

} 
void showDeliveryOrder(){

}

void delteOrder(){

}

void showRestaurantOrder(){

}
void totalSells(){

}

void searchOrderbyClient(){

}
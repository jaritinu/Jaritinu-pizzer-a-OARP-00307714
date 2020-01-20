#include <iostream>
#include <string>
using namespace std;

struct deliveryOrder{
    string nameClient;
    string address;
    string telephone;
    int mainDish;
    int appetizer;
    int drink;
    int amount;
    int paymentType;
};
struct restaurantOrder{
    string nameClient;
    int clientNumber;
    int mainDish;
    int appetizer;
    int drink;
    int amount;
    int paymentType;
};
struct libro catalogo[10];
int restaurantOrderNumber = 0;
int deliveryOrderNumber = 0;

void addDeliveryOrder(), addRestaurantOrder(), showDeliveryOrder(),showRestaurantOrder();

int main(){
    // Mostrar menu al usuario
    string clave = "vector";
    string password = "";
    int counterPass = 0;
    bool flagPass = false;
    cout << "------Pizzeria Jaritinu------" <<endl;
    do{
        cout << "Digite el password: ";
        getline(cin,password);
        if (password == clave){
            flagPass = true;
        }
        else{
            cout << "\nPassword incorrecto." << endl;
            counterPass++;
        }
    }while (flagPass == false && counterPass < 3);
    
    if (flagPass==true){
        bool continuar = true;
        do{
            int opcion = 0;
            cout << "\n1. Agregar pedido a domicilio\n";
            cout << "2. Agregar encargo en restaurante\n";
            cout << "3. Ver pedidos a domicilio\n";
            cout << "4. Ver encargas a restaurantes\n";
            cout << "5. Ver total de venta\n";
            cout << "Opcion: ";
            cin >> opcion;
            cin.ignore();
            
            switch(opcion){
                case 1: addDeliveryOrder(); break;
                case 2: addRestaurantOrder(); break;
                case 3: showDeliveryOrder(); break;
                case 4: showRestaurantOrder();break;
                case 5: totalSells();break;
                case 6: continuar = false;
            }
        }while(continuar);
    }
    else{
        cout << "\nFallo los 3 intentos" << endl;
    }
    return 0;
}
void addDeliveryOrder(){

} 
void addRestaurantOrder(){

} 
void showDeliveryOrder(){

}

void showRestaurantOrder(){

}
void totalSells(){

}
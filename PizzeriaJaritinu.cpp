#include <iostream>
#include <string>

#define PASSWORD "clave"

using namespace std;

struct address{
    int houseNumber;
    string suburb;
    string city;
    string estate;
};

struct deliveryOrder{
    int idDelivery;
    string nameClient;
    address clientAddress;
    string telephone;
    int mainDish;
    int appetizer;
    int drink;
    int amount;
    int paymentType;
};
struct restaurantOrder{
    int idRestaurant;
    string nameClient;
    int clientNumber;
    int mainDish;
    int appetizer;
    int drink;
    int amount;
    int paymentType;
};

int idDeliveryNumber = 0;
int idRestaurantNumber = 0;
deliveryOrder* deliveryList;
restaurantOrder* restaurantList;

int restaurantOrderNumber = 0;
int deliveryOrderNumber = 0;

void addDeliveryOrder(), addRestaurantOrder(), showDeliveryOrder(),showRestaurantOrder(), searchOrderbyClient(), delteOrder();

int main(){
    // Mostrar menu al usuario
    string clave = "vector";
    string password = "";
    int counterPass = 0;
    int user = 0;
    bool flagPass = false;
    cout << "------Pizzeria Jaritinu------" <<endl;
    cout << "1. Empleado";
    cout << "2. Administrador";
    cout << "Seleccione el tipo de usuario (1 o 2): ";

    switch (user)
    {
    case 1:
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
                cout << "4. Buscar orden por cliente\n";
                cout << "5. Eliminar orden\n";
                cout << "6. Ver encargas a restaurantes\n";
                cout << "7. Ver total de venta\n";
                cout << "8. Salir\n";
                cout << "Opcion: ";
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
                    case 8: continuar = false;
                }
            }while(continuar);
        }
        else{
            cout << "\nFallo los 3 intentos" << endl;
        }
        break;
    case 2:
        bool continuar = true;
        do{
                int opcion = 0;
                cout << "\n1. Agregar pedido a domicilio\n";
                cout << "2. Agregar encargo en restaurante\n";
                cout << "3. Ver pedidos a domicilio\n";
                cout << "4. Buscar orden por cliente\n";
                cout << "5. Ver encargas a restaurantes\n";
                cout << "6. Ver total de venta\n";
                cout << "7. Salir\n";
                cout << "Opcion: ";
                cin >> opcion;
                cin.ignore();
                
                switch(opcion){
                    case 1: addDeliveryOrder(); break;
                    case 2: addRestaurantOrder(); break;
                    case 3: showDeliveryOrder(); break;
                    case 4: searchOrderbyClient();break;
                    case 5: showRestaurantOrder();break;
                    case 6: totalSells();break;
                    case 7: continuar = false;
                }
            }while(continuar);
    default:
        return 0;
        break;
    }


    
    return 0;
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
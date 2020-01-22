#include <iostream>
#include <string>

#define PASSWORD "vector"

using namespace std;

enum mainDish {pizza, pasta, lasagna};
enum drink {beer, soda, tea};
enum starter {garlicBread, pizzaRolls, cheeseSticks};
enum paymentType {cash,card};

struct address{
    string settlement, municipality,deparment;
    int numberHouse;
};

struct mainInfo{
    string name;
    mainDish pDish;
    drink pDrink;
    starter pStarter;
    paymentType pay;
    int idOrder;
    float total;
};


struct delivery{
    address deliveryAddress;
    int cellphone;
    mainInfo deliveryInfo;
};

struct houseOrder{
    int pTable;
    mainInfo houseInfo;
};
//variables globales
bool isAdmin = false;
int idOrder = 1;
//prototipos
bool loginUser(void);

int main(void){
    delivery* dArray =NULL;
    houseOrder* hArray = NULL;
    int option = 0;


    if(!loginUser())
        return 0;

    do{
        printMenu(); cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
            addOrder(dArray);
            break;
        case 2:
            addOrder(hArray);
            break;
        case 3:
            
            break;
        case 4:
            
            break;       
        default:
            break;
        }
    }while(option != 0);
    return 0;
}

bool loginUser(void){
    string enterPass = "";
    char option;
    cout << "INICIO DE SESION" << endl;
    cout << "A - Administrador" << endl;
    cout << "E - Empleado" << endl;
    cout << "Su opcion:\t"; cin >> option;

    switch (option){
        case 'a':
        case 'A':
            cout << "Digite la contraseña: "; cin >> enterPass;

            if(enterPass.compare(PASSWORD) == 0){
                isAdmin = true;
                return true;
            }
            else{
                cout << "Contraseña incorrecta" << endl;
            }
        break;
        case 'e':
        case 'E':
            isAdmin = false;
            return true;
            break;
        default:
            break;
    }
    return false;
}

void printMenu(void){
    cout << "SISTEMA DE DESPACHO PIZZERIA JARITINU" << endl;
    cout << "1.Agregar ordenes a domicilo" << endl;
    cout << "2. Agregar ordenes en restaurantes" << endl;
    cout << "3. Ver ordenes a domicilio" << endl;
    cout << "4. Ver ordenes en restaurantea" << endl;
    cout << "Su opcion: ";
}

void addOrder(delivery* array){
    int size = 0, aux =0;
    cout << "Cantidad de pedidos a ingresar: "; cin >>  size;
    cin.ignore();

    array = new delivery[size];

    for(int i = 0; i < size; i++){
        cout << "Nombre:\t "; getline(cin,array[i].deliveryInfo.name);
        cout << "Direccion" << endl;
        cout << "Colonia:\t"; getline(cin,array[i].deliveryAddress.settlement);
        cout << "Municipio:\t"; getline(cin,array[i].deliveryAddress.municipality);
        cout << "Departamento:\t"; getline(cin,array[i].deliveryAddress.deparment);
        cout << "No. casa:\t"; cin >> array[i].deliveryAddress.numberHouse;
        cin.ignore();

        cout << "Entradas" << endl;
        cout << "1 -  Pan con ajo  - ";
        cout << "2 - Pizzarolls  -";

        if(aux == 1)
            array[i].deliveryInfo.pDish = pizza;
        else if(aux ==2)
            array[i].deliveryInfo.pDish = pasta;
        else
            array[i].deliveryInfo.pDish = lasagna;   


        cout << "Entradas" << endl;
        cout << "1 - Pan con ajo -";
        cout << "2 - Pizzarolls  -";


        if(aux == 1)
            array[i].deliveryInfo.s = pizza;
        else if(aux ==2)
            array[i].deliveryInfo.pDish = pasta;
        else
            array[i].deliveryInfo.pDish = lasagna;   


        array[i].deliveryInfo.idOrder = idOrder++;

        if(aux == 1)
            array[i].deliveryInfo.pay =card;
        else
            array[i].deliveryInfo.pay =cash;
        
        cout << "Monto: "; cin >> array[i].deliveryInfo.total;
        cin.ignore();
        cout << "Telefono: "; cin >> array[i].cellphone;
        cin.ignore();
            
        
    }
}

void addOrder(houseOrder* array){
    int size = 0, aux =0;
    cout << "Cantidad de pedidos a ingresar: "; cin >>  size;
    cin.ignore();

    array = new houseOrder[size];

    for(int i = 0; i < size; i++){
        cout << "Nombre:\t "; getline(cin,array[i].houseInfo.name);
        cout << "Direccion" << endl;
        cout << "Colonia:\t"; getline(cin,array[i].deliveryAddress.settlement);
        cout << "Municipio:\t"; getline(cin,array[i].deliveryAddress.municipality);
        cout << "Departamento:\t"; getline(cin,array[i].deliveryAddress.deparment);
        cout << "No. casa:\t"; cin >> array[i].deliveryAddress.numberHouse;
        cin.ignore();

        cout << "Entradas" << endl;
        cout << "1 Pan con ajo";


        if(aux == 1)
            array[i].houseInfo.pDish = pizza;
        else if(aux ==2)
            array[i].houseInfo.pDish = pasta;
        else
            array[i].houseInfo.pDish = lasagna;   


        cout << "Entradas" << endl;
        cout << "1 Pan con ajo";


        if(aux == 1)
            array[i].deliveryInfo.s = pizza;
        else if(aux ==2)
            array[i].deliveryInfo.pDish = pasta;
        else
            array[i].deliveryInfo.pDish = lasagna;   


        array[i].deliveryInfo.idOrder = idOrder++;

        if(aux == 1)
            array[i].deliveryInfo.pay =card;
        else
            array[i].deliveryInfo.pay =cash;
        
        cout << "Monto: "; cin >> array[i].deliveryInfo.total;
            
        
    }
}

void searchByName(delivery* array, int size){
    bool userExists =false;
    string aux = "";
    cout << "Nombre a buscar: "; getline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].deliveryInfo.name) == 0){
            //imprimir datos
            userExists = true;
        }
    }

    (!userExists) ? cout << "No existe el usuario" : cout << "";
}

void searchByName(houseOrder* array, int size){
    bool userExists =false;
    string aux = "";
    cout << "Nombre a busar: "; getline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].houseInfo.name) == 0){
            //imprimir datos
            userExists = true;
        }
    }

    (!userExists) ? cout << "No existe el usuario" : cout << "";
}
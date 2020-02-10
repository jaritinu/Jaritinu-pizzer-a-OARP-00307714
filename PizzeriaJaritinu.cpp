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


struct NodoD{
    deliveryOrder order;
    struct NodoD *next;
};

struct NodoR{
    restaurantOrder order;
    struct NodoR *next;
};

//variables globales

int idOrder = 0;
NodoD* deliveryList;
NodoR* restaurantList;
bool flagPass = false;
int user = 0;
int counterPass = 0;
//Prototipos
void addOrderD(); 
void addOrderR(); 
void showDeliveryOrder();
void showRestaurantOrder(); 
void delteOrderD(); 
void printMenuA(void);
void printMenuE(void);
void dispatchOrderD();
void dispatchOrderR();
void averageTimeD();
void averageTimeR();
void cancelOrder();
float totalSells();
bool loginUser(void);


//Listas
void addEndList(deliveryOrder p);
void addEndList(restaurantOrder p);
bool compare(restaurantOrder a, restaurantOrder b);
bool compare(deliveryOrder a, deliveryOrder b);
void delteOrderR();

int main(){
    // Mostrar menu al usuario
    
    bool endprogram = true;
    bool continuar = true;
    int opcion = 0;
    cout << "------Pizzeria Jaritinu------" <<endl;
    cout << "1. Administrador" << endl;
    cout << "2. Empleado" << endl;
    cout << "Seleccione el tipo de usuario (1 o 2): ";
    cin >> user;
    cin.ignore();
    do{
        switch (user)
        {
        case 1:
            do{
                if (flagPass == true){
            //        bool continuar = true;
                        printMenuA(),
                        cin >> opcion;
                        cin.ignore();
                        
                        switch(opcion){
                            case 1: addOrderD(); break;
                            case 2: addOrderR(); break;
                            case 3: showDeliveryOrder(deliveryList); break;
                            case 4: showRestaurantOrder(restaurantList); break;
                            case 5: dispatchOrderD(); break;
                            case 6: dispatchOrderR(); break;
                            case 7: averageTimeD(); break;
                            case 8: averageTimeR(); break;
                            case 9: cancelOrder(); break;
                            case 10: totalSells(); break;
                            case 11: continuar=false; user=2; break;
                            case 12: continuar = false; endprogram = false; break;
                            default: cout << "\nError!"; break;
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
                        case 1: addOrderD(); break;
                        case 2: addOrderR(); break;
                        case 3: showDeliveryOrder(deliveryList); break;
                        case 4: showRestaurantOrder(restaurantList); break;
                        case 5: dispatchOrderD(); break;
                        case 6: dispatchOrderR(); break;
                        case 7: averageTimeD(); break;
                        case 8: averageTimeR(); break;
                        case 9: totalSells(); break;
                        case 10: loginUser(); continuar = false;break;
                        case 11: continuar = false; endprogram = false; break;
                        default: cout << "\nError!"; break;
                    }
                }while(continuar); 
                break;
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
            user =1;
        }
        else{
            cout << "\nPassword incorrecto." << endl;
            counterPass++;
            user=2;
        }
    }while (flagPass == false && counterPass < 3);
    if(counterPass == 3)
        flagPass = false;

    return flagPass;
}

void printMenuE(void){
    cout << "\n1.  Agregar orden a domicilio\n";
    cout << "2.  Agregar orden en restaurante\n";
    cout << "3.  Ver ordenes a domicilio\n";
    cout << "4.  Ver ordenes en restaurantes\n";
    cout << "5.  Despachar ordenes a domicilio\n";
    cout << "6.  Despachar ordenes a restaurante\n";
    cout << "7.  Ver tiempo promedio de espera a domicilio\n";
    cout << "8.  Ver tiempo promedio de espera restaurante\n";
    cout << "9.  Calcular total de ventas\n";
    cout << "10. Cambia de usuario\n";
    cout << "11. Salir\n";
    cout << "Opcion: ";
}

void printMenuA(void){
    cout << "\n1.  Agregar orden a domicilio\n";
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

void addOrderD(){
    deliveryOrder p;
    int aux;
    cout << "Nombre:\t"; getline(cin, p.deliveryInfo.name);
    cout << "Direccion" << endl;
    cout << "Colonia:\t"; getline(cin, p.clientAddress.suburb);
    cout << "Municipio:\t"; getline(cin, p.clientAddress.city);
    cout << "Departamento:\t"; getline(cin, p.clientAddress.estate);
    cout << "No. casa:\t"; cin >> p.clientAddress.houseNumber;
    cin.ignore();

    cout << "Entrada" << endl;
    cout << "1 - Pan con ajo" << endl;
    cout << "2 - Pizza rolls" << endl;
    cout << "3 - Palitos de queso" << endl;
    cout << "Su opcion:\t"; cin >> aux;
    cin.ignore();

    if(aux == 1)
        p.deliveryInfo.pStarter = garlicBread;
    else if(aux == 2)
        p.deliveryInfo.pStarter = pizzaRolls;
    else
        p.deliveryInfo.pStarter = cheeseSticks;

    cout << "Plato principal" << endl;
    cout << "1 - Pizza" << endl;
    cout << "2 - Pasta" << endl;
    cout << "3 - Lasagna" << endl;
    cout << "Su opcion:\t"; cin >> aux;
    cin.ignore();

    if(aux == 1)
        p.deliveryInfo.pDish = pizza;
    else if(aux == 2)
        p.deliveryInfo.pDish = pasta;
    else
        p.deliveryInfo.pDish = lasagna;

    cout << "Bebida" << endl;
    cout << "1 - Cerveza" << endl;
    cout << "2 - Soda" << endl;
    cout << "3 - Te helado" << endl;
    cout << "Su opcion:\t"; cin >> aux;
    cin.ignore();

    if(aux == 1)
        p.deliveryInfo.pDrink = beer;
    else if(aux == 2)
        p.deliveryInfo.pDrink = soda;
    else
        p.deliveryInfo.pDrink = tea;

    p.deliveryInfo.idOrder = idOrder++;
        
    cout << "Tipo de pago" << endl;
    cout << "1 - Tarjeta" << endl;
    cout << "2 - Efectivo" << endl;
    cout << "Su opcion:\t"; cin >> aux;
    cin.ignore();

    if(aux == 1)
        p.deliveryInfo.pay = card;
    else
        p.deliveryInfo.pay = cash;

    cout << "Monto: "; cin >> p.deliveryInfo.total;
    cin.ignore();
    cout << "Telefono: "; cin >> p.telephone;
    cin.ignore();

} 
void addOrderR(){
    restaurantOrder p;
    int aux;
    cout << "Nombre:\t"; getline(cin, p.houseInfo.name);
    cout << "Numero de personas:" << endl; cin >> p.cTable;
    cin.ignore();

    cout << "Entrada" << endl;
    cout << "1 - Pan con ajo" << endl;
    cout << "2 - Pizza rolls" << endl;
    cout << "3 - Palitos de queso" << endl;
    cout << "Su opcion:\t"; cin >> aux;
    cin.ignore();

    if(aux == 1)
        p.houseInfo.pStarter = garlicBread;
    else if(aux == 2)
        p.houseInfo.pStarter = pizzaRolls;
    else
        p.houseInfo.pStarter = cheeseSticks;

    cout << "Plato principal" << endl;
    cout << "1 - Pizza" << endl;
    cout << "2 - Pasta" << endl;
    cout << "3 - Lasagna" << endl;
    cout << "Su opcion:\t"; cin >> aux;
    cin.ignore();

    if(aux == 1)
        p.houseInfo.pDish = pizza;
    else if(aux == 2)
        p.houseInfo.pDish = pasta;
    else
        p.houseInfo.pDish = lasagna;

    cout << "Bebida" << endl;
    cout << "1 - Cerveza" << endl;
    cout << "2 - Soda" << endl;
    cout << "3 - Te helado" << endl;
    cout << "Su opcion:\t"; cin >> aux;
    cin.ignore();

    if(aux == 1)
        p.houseInfo.pDrink = beer;
    else if(aux == 2)
        p.houseInfo.pDrink = soda;
    else
        p.houseInfo.pDrink = tea;

    p.houseInfo.idOrder = idOrder++;
        
    cout << "Tipo de pago" << endl;
    cout << "1 - Tarjeta" << endl;
    cout << "2 - Efectivo" << endl;
    cout << "Su opcion:\t"; cin >> aux;
    cin.ignore();

    if(aux == 1)
        p.houseInfo.pay = card;
    else
        p.houseInfo.pay = cash;

    cout << "Monto: "; cin >> p.houseInfo.total;
    cin.ignore();
} 
void showDeliveryOrder(NodoD* list){
    if(!list){
        return;
    }
    else{
        cout << list->order.deliveryInfo.idOrder << endl;
        showDeliveryOrder(list->next);
    }
}
void showRestaurantOrder(NodoR* list){
      if(!list){
        return;
    }
    else{
        cout << list->order.houseInfo.idOrder << endl;
        showRestaurantOrder(list->next);
    }
}

void cancelOrder(){
    int n = 0;
    cout << "1. Cancelar Delivery" << endl;
    cout << "2. Cancelar Restaurante" << endl;
    cout << "Seleccione el tipo de usuario (1 o 2): ";
    cin >> n; cin.ignore();
    if(n==1)
        delteOrderD();
    else if(n==2)
        delteOrderR();
}

void delteOrderD(){
    string name = "";
    int order = 0;
    deliveryOrder aux;
    cout << "\nOrden a eliminar: ";
    cin >> order; cin.ignore();
    cout << "\nNombre de cliente";
    getline(cin,name);
    aux.deliveryInfo.idOrder=order;
    aux.deliveryInfo.name=name;
    NodoD *p = deliveryList, *q = NULL;
    
    while(p != NULL && !compare(p->order, aux)){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        cout << "Orden a borrar NO existe" << endl;
        return;
    }
    if(q == NULL)
        deliveryList = p->next;
    else
        q->next = p->next;
    delete(p);
    cout << "Orden cancelada!" << endl;
}

void delteOrderR(){
    string name = "";
    int order = 0;
    restaurantOrder aux;
    cout << "\nOrden a eliminar: ";
    cin >> order; cin.ignore();
    cout << "\nNombre de cliente";
    getline(cin,name);
    aux.houseInfo.idOrder=order;
    aux.houseInfo.name=name;
    NodoR *p = restaurantList, *q = NULL;
    
    while(p != NULL && !compare(p->order, aux)){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        cout << "Orden a borrar NO existe" << endl;
        return;
    }
    if(q == NULL)
        restaurantList = p->next;
    else
        q->next = p->next;
    delete(p);
    cout << "Orden cancelada!" << endl;
}


float totalSells(){

}


void dispatchOrderD(){

}

void dispatchOrderR(){

}
void averageTimeD(){

}

void averageTimeR(){

}

void addEndList(deliveryOrder p) {
    NodoD *newOrder = new NodoD;
    newOrder->order = p;
    newOrder->next = NULL;
    
    if (deliveryList == NULL) {
        deliveryList = newOrder;
    } else {
        NodoD *p = deliveryList;
        NodoD *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->next;
        }
        q->next = newOrder;
    }
}

void addEndList(restaurantOrder p){
    NodoR *newOrder = new NodoR;
    newOrder->order = p;
    newOrder->next = NULL;
    
    if (restaurantList == NULL) {
        restaurantList = newOrder;
    } else {
        NodoR *p = restaurantList;
        NodoR *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->next;
        }
        q->next = newOrder;
    }
}


bool compare(restaurantOrder a, restaurantOrder b){
    return (a.houseInfo.idOrder == b.houseInfo.idOrder) && (a.houseInfo.idOrder==b.houseInfo.idOrder);
}
bool compare(deliveryOrder a, deliveryOrder b){
    return (a.deliveryInfo.idOrder == b.deliveryInfo.idOrder) && (a.deliveryInfo.idOrder==b.deliveryInfo.idOrder);
}


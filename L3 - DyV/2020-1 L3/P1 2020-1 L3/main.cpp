

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 22 de octubre de 2024, 10:51 PM
 */


#include <iomanip>

//long Matriz_inventario = { 77512345678920015990000040005060, 
//                            77512341234560009690000400050030, 
//                            77512349876540009990000300039035, 
//                            77512346969690001990003000100010, 
//                            77512346669990014990000110010020, 
//                            77512349696960006990000200026025 
//                             } ;
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  // Para std::stoi
#include <cstring>  // Para strcpy
using namespace std;
const int MAX_DIGITS = 32;
const int PRICE_DIGITS = 5;
const int DISCOUNT_DIGITS = 2;
const int STOCK_DIGITS = 3;
const int MIN_STOCK_DIGITS = 2;
const int GTIN_DIGITS = 12;

double get_final_price(const std::string &stream) {
    std::string str_price = stream.substr(GTIN_DIGITS, PRICE_DIGITS);
    std::string str_discount = stream.substr(GTIN_DIGITS + PRICE_DIGITS + STOCK_DIGITS + MIN_STOCK_DIGITS, DISCOUNT_DIGITS);
    
    double price = atoi(str_price) / 100.0;
    int discount = atoi(str_discount);
    double final_price = price * ((100 - discount) / 100.0);
    
    return final_price;
}

int get_stock_diff(const string &stream) {
    string str_stock = stream.substr(GTIN_DIGITS + PRICE_DIGITS, STOCK_DIGITS);
    string str_min_stock = stream.substr(GTIN_DIGITS + PRICE_DIGITS + STOCK_DIGITS, MIN_STOCK_DIGITS);
    return atoi(str_stock) - atoi(str_min_stock);
}

void merge(vector<std::string> &db, int ini, int mid, int end) {
    int l1 = mid - ini + 1;
    int l2 = end - mid;

    vector<std::string> leftArray(l1 + 1);
    vector<std::string> rightArray(l2 + 1);

    for (int i = 0; i < l1; ++i) {
        leftArray[i] = db[ini + i];
    }

    for (int i = 0; i < l2; ++i) {
        rightArray[i] = db[mid + 1 + i];
    }

    int p = 0, q = 0, i = ini;
    while (p < l1 && q < l2) {
        if (get_final_price(leftArray[p]) > get_final_price(rightArray[q])) {
            db[i++] = leftArray[p++];
        } else {
            db[i++] = rightArray[q++];
        }
    }

    while (p < l1) db[i++] = leftArray[p++];
    while (q < l2) db[i++] = rightArray[q++];
}

void merge_sort_for_offers(vector<string> &db, int ini, int end) {
    if (ini >= end) return;

    int mid = (ini + end) / 2;
    merge_sort_for_offers(db, ini, mid);
    merge_sort_for_offers(db, mid + 1, end);
    merge(db, ini, mid, end);
}

void show_offers(const vector<string> &db, int ini, int end) {
    cout << "Los productos del pasillo de ofertas son:\n";
    for (int i = ini; i <= end; ++i) {
        string str_discount = db[i].substr(GTIN_DIGITS + PRICE_DIGITS + STOCK_DIGITS + MIN_STOCK_DIGITS, DISCOUNT_DIGITS);
        cout << "\t" << db[i] << " | " << atoi(str_discount) << " descuento | P.F.: S/. " 
                  << get_final_price(db[i]) << "\n";
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de productos a registrar: ";
    cin >> n;
    
    vector<std::string> db(n);
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese la trama del producto " << i + 1 << " (32 dígitos): ";
        cin >> db[i];
    }

    int numOfertas = n; // Puedes ajustar esto según el criterio de ofertas.
    
    merge_sort_for_offers(db, 0, numOfertas - 1);
    show_offers(db, 0, numOfertas - 1);

    return 0;
}





//
// Created by 72358 on 24/04/2025.
//
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string idRemitente, criptograma;
    char opcion;

    // Solicitar información al usuario Y
    cout << "Ingrese el ID del remitente (X): ";
    getline(cin, idRemitente);

    cout << "¿Desea cargar el criptograma desde un archivo? (s/n): ";
    cin >> opcion;
    cin.ignore(); // Limpiar el buffer de entrada

    if (opcion == 's' || opcion == 'S') {
        string nombreArchivo;
        cout << "Nombre del archivo: ";
        getline(cin, nombreArchivo);

        ifstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            getline(archivo, criptograma);
            archivo.close();
        } else {
            cout << "Error al abrir el archivo." << endl;
            return 1;
        }
    } else {
        cout << "Ingrese el criptograma: ";
        getline(cin, criptograma);
    }

    // Obtener llaves
    KeyAgent agente;
    string miIdDestinatario = "Y"; // Identificador del destinatario Y

    string llavePublicaDestinatario = agente.getPublic(miIdDestinatario);
    string llavePrivadaDestinatario = agente.getPrivate(miIdDestinatario); // Solicitará contraseña
    string llavePublicaRemitente = agente.getPublic(idRemitente);

    // Crear el criptógrafo con las llaves del destinatario
    Criptografo cripto(llavePublicaDestinatario, llavePrivadaDestinatario);

    // Desencriptar el mensaje
    string mensajeOriginal = cripto.recibir(llavePublicaRemitente, criptograma);

    // Mostrar el mensaje
    cout << "\nMensaje recibido: " << endl;
    cout << mensajeOriginal << endl;

    return 0;
}
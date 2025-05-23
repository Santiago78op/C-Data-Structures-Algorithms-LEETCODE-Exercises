//
// Created by 72358 on 24/04/2025.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string idDestinatario, mensaje;

    // Solicitar información al usuario X
    cout << "Ingrese el ID del destinatario (Y): ";
    getline(cin, idDestinatario);

    cout << "Ingrese el mensaje a enviar: ";
    getline(cin, mensaje);

    // Obtener llaves
    KeyAgent agente;
    string miIdRemitente = "X"; // Identificador del remitente X

    string llavePublicaRemitente = agente.getPublic(miIdRemitente);
    string llavePrivadaRemitente = agente.getPrivate(miIdRemitente); // Solicitará contraseña
    string llavePublicaDestinatario = agente.getPublic(idDestinatario);

    // Crear el criptógrafo con las llaves del remitente
    Criptografo cripto(llavePublicaRemitente, llavePrivadaRemitente);

    // Generar el criptograma
    string criptograma = cripto.enviar(llavePublicaDestinatario, mensaje);

    // Mostrar o guardar el criptograma
    cout << "\nCriptograma generado: " << endl;
    cout << criptograma << endl;

    // Opcionalmente, guardar en un archivo
    cout << "\n¿Desea guardar el criptograma en un archivo? (s/n): ";
    char respuesta;
    cin >> respuesta;

    if (respuesta == 's' || respuesta == 'S') {
        string nombreArchivo;
        cout << "Nombre del archivo: ";
        cin >> nombreArchivo;

        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            archivo << criptograma;
            archivo.close();
            cout << "Criptograma guardado en " << nombreArchivo << endl;
        } else {
            cout << "Error al abrir el archivo para escritura." << endl;
        }
    }

    return 0;
}
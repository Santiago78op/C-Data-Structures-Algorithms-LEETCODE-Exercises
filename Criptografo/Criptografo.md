//
// Created by 72358 on 24/04/2025.
//
#include "Criptografo.h"
#include <string>

class KeyAgent {
public:
    //* obtiene la llave pública de la persona identificada por id
    string getPublic(string id) ;
    /* obtiene la llave privada de la persona identificada por id.
       Solicitará contraseña interactivamente */
};

class Criptografo {
public:
    Criptografo(string llvPub, string llvPriv){
        this->llvPublica = llvPub;
        this->llvPrivada = llvPriv;
    }

    /** genera el criptograma para enviar un mensaje certificado usando las
        llaves propias y la llave del destinatario llvDestinatario */
    string enviar (string llvDestinatario,string mensaje){
        // Generamos una llave de sesión aleatoria para encripción simétrica
        string llaveSesion = sesion();

        // Paso 1: Encriptamos el mensaje con la llave de sesión (AES, simétrica)
        string mensajeEncriptado = encriptaAES(llaveSesion, mensaje);

        // Paso 2: Encriptamos la llave de sesión con la llave pública del destinatario (RSA)
        string llaveSesionEncriptada = encriptaRSA(llvDestinatario, llaveSesion);

        // Paso 3: Preparamos el paquete a firmar (llave encriptada + mensaje encriptado)
        string paquete = llaveSesionEncriptada + ":" + mensajeEncriptado;

        // Paso 4: Firmamos el paquete con nuestra llave privada (RSA)
        string firma = encriptaRSA(this->llvPrivada, paquete);

        // Paso 5: Construimos el criptograma final (firma + paquete)
        string criptograma = firma + "::" + paquete;

        return criptograma;
    }

    /** Recibe un criptograma certificado usando las llaves propias y la
        llave del remitente llvRemitente y genera el mensaje recibido*/
    string recibir (string llvRemitente,string criptograma){
        // Separamos el criptograma en sus partes
        size_t posSeparador = criptograma.find("::");
        if (posSeparador == string::npos) {
            return "Error: formato de criptograma inválido";
        }

        // Extraemos la firma y el paquete
        string firma = criptograma.substr(0, posSeparador);
        string paquete = criptograma.substr(posSeparador + 2);

        // Paso 1: Verificamos la firma usando la llave pública del remitente
        string paqueteVerificado = desencriptaRSA(llvRemitente, firma);

        // Verificamos que el paquete verificado coincida con el paquete recibido
        if (paqueteVerificado != paquete) {
            return "Error: firma inválida";
        }

        // Separamos el paquete en llave de sesión encriptada y mensaje encriptado
        posSeparador = paquete.find(":");
        if (posSeparador == string::npos) {
            return "Error: formato de paquete inválido";
        }

        string llaveSesionEncriptada = paquete.substr(0, posSeparador);
        string mensajeEncriptado = paquete.substr(posSeparador + 1);

        // Paso 2: Desencriptamos la llave de sesión con nuestra llave privada
        string llaveSesion = desencriptaRSA(this->llvPrivada, llaveSesionEncriptada);

        // Paso 3: Desencriptamos el mensaje con la llave de sesión
        string mensajeOriginal = desencriptaAES(llaveSesion, mensajeEncriptado);

        return mensajeOriginal;
    }

private:
    string llvPublica, llvPrivada ;
    /** devuelve el criptograma correspondiente a la encripción RSA del
        mensaje con la llave llv (pública o privada) */
    string encriptaRSA(string llv, string mensaje) ;

    /** devuelve el mensaje correspondiente a la desencripción RSA del
        criptograma con la llave llv (pública o privada) */
    string desencriptaRSA (string llv, string criptograma) ;

    /** devuelve el criptograma correspondiente a la encripción AES del
        mensaje con la llave llv */
    string encriptaAES(string llv, string mensaje) ;

    /** devuelve el mensaje correspondiente a la desencripción AES del
        criptograma con la llave llv */
    string desencriptaAES (string llv, string criptograma) ;

    /** genera una llave de sesión aleatoria */
    string sesion() ;
};
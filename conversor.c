#include <stdio.h>
#include <stdlib.h>

// Definición de tasas de cambio (Valores referenciales ajustables)
// Puedes actualizar estos valores según la tasa actual del día.
#define TASA_GTQ_A_USD 0.128 // 1 GTQ = 0.128 USD approx.
#define TASA_GTQ_A_EUR 0.117 // 1 GTQ = 0.117 EUR approx.
#define TASA_USD_A_GTQ 7.82  // 1 USD = 7.82 GTQ approx.
#define TASA_USD_A_EUR 0.91  // 1 USD = 0.91 EUR approx.
#define TASA_EUR_A_GTQ 8.55  // 1 EUR = 8.55 GTQ approx.
#define TASA_EUR_A_USD 1.10  // 1 EUR = 1.10 USD approx.

// Prototipos de funciones
void mostrarMenuPrincipal();
void procesarConversion(int opcionOrigen, int opcionDestino);
const char* obtenerSimbolo(int opcion);

int main() {
    int opcion;
    int opcionDestino;

    system("clear"); // En Windows, usa system("cls"); si esta función no limpia la pantalla.

    printf("╔═════════════════════════════════════════╗\n");
    printf("║      CONVERSOR DE MONEDAS FUTURISTA     ║\n");
    printf("╚═════════════════════════════════════════╝\n");

    while (1) {
        mostrarMenuPrincipal();
        printf("\nSelecciona la moneda de ORIGEN: ");
        if (scanf("%d", &opcion) != 1) {
             printf("Entrada no válida.\n");
             break; // Salir si la entrada no es un número
        }

        if (opcion == 4) {
            printf("\nGracias por usar el conversor. ¡Adiós!\n");
            break;
        }

        if (opcion < 1 || opcion > 4) {
            printf("\nOpcíon inválida. Intente de nuevo.\n");
            continue;
        }

        printf("\nSelecciona la moneda de DESTINO (1. GTQ, 2. USD, 3. EUR): ");
        if (scanf("%d", &opcionDestino) != 1) {
             printf("Entrada no válida.\n");
             break;
        }
        
        if (opcionDestino < 1 || opcionDestino > 3) {
            printf("\nOpcíon de destino inválida.\n");
            continue;
        }

        if (opcion == opcionDestino) {
             printf("\n[Sistema]: No es necesario convertir a la misma moneda.\n");
             continue;
        }

        procesarConversion(opcion, opcionDestino);
    }

    return 0;
}

void mostrarMenuPrincipal() {
    printf("\n--- Moneda de Origen ---\n");
    printf("1. Quetzales (GTQ)\n");
    printf("2. Dólares Estadounidenses (USD)\n");
    printf("3. Euros (EUR)\n");
    printf("4. Salir\n");
}

const char* obtenerSimbolo(int opcion) {
    switch (opcion) {
        case 1: return "Q.";
        case 2: return "$";
        case 3: return "€";
        default: return "";
    }
}

void procesarConversion(int opcionOrigen, int opcionDestino) {
    float cantidad;
    float resultado = 0;
    const char* simboloOrigen = obtenerSimbolo(opcionOrigen);
    const char* simboloDestino = obtenerSimbolo(opcionDestino);

    printf("\nIngrese la cantidad en %s %s: ", 
           (opcionOrigen == 1 ? "Quetzales" : (opcionOrigen == 2 ? "Dólares" : "Euros")),
           simboloOrigen);
    
    if (scanf("%f", &cantidad) != 1 || cantidad < 0) {
        printf("Cantidad inválida o negativa.\n");
        return;
    }

    // Conversión GTQ -> Otros
    if (opcionOrigen == 1) {
        if (opcionDestino == 2) resultado = cantidad * TASA_GTQ_A_USD;
        else if (opcionDestino == 3) resultado = cantidad * TASA_GTQ_A_EUR;
    }
    // Conversión USD -> Otros
    else if (opcionOrigen == 2) {
        if (opcionDestino == 1) resultado = cantidad * TASA_USD_A_GTQ;
        else if (opcionDestino == 3) resultado = cantidad * TASA_USD_A_EUR;
    }
    // Conversión EUR -> Otros
    else if (opcionOrigen == 3) {
        if (opcionDestino == 1) resultado = cantidad * TASA_EUR_A_GTQ;
        else if (opcionDestino == 2) resultado = cantidad * TASA_EUR_A_USD;
    }

    printf("\n>> [RESULTADO]: %s %.2f equivale a: %s %.2f\n", 
           simboloOrigen, cantidad, simboloDestino, resultado);
}
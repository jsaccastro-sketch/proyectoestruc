#include <iostream>
#include <string>
using namespace std;

// =============================================
// FUNCIONES BÁSICAS DE OPERADORES LÓGICOS
// =============================================

bool Negacion(bool a)
{
    return !a;
}

bool DobleNegacion(bool a)
{
    return !!a; // doble negación regresa el mismo valor
}

bool Conjuncion(bool a, bool b)
{ // AND  (∧)
    return a && b;
}

bool Disyuncion(bool a, bool b)
{ // OR   (∨)
    return a || b;
}

bool DisyuncionExclusiva(bool a, bool b)
{ // XOR (⊕)
    return a != b;
}

bool Condicional(bool a, bool b)
{ // →  (Si a entonces b)
    return !a || b;
}

bool Bicondicional(bool a, bool b)
{ // ↔
    return a == b;
}

// =============================================
// FUNCIÓN PRINCIPAL DE TU PARTE (PARTE 2)
// =============================================

void evaluarExpresionCon3Variables()
{
    bool p, q, r;
    int opcion;
    bool resultado;

    cout << "\n=== EVALUACIÓN DE EXPRESIONES CON 3 VARIABLES ===\n\n";

    // Pedir valores de verdad
    cout << "Ingrese el valor de p (1 = Verdadero, 0 = Falso): ";
    cin >> p;
    cout << "Ingrese el valor de q (1 = Verdadero, 0 = Falso): ";
    cin >> q;
    cout << "Ingrese el valor de r (1 = Verdadero, 0 = Falso): ";
    cin >> r;

    cout << "\n=== Elija la expresión que desea evaluar ===\n";
    cout << "1. p ∧ q\n";
    cout << "2. p ∨ q\n";
    cout << "3. p → q\n";
    cout << "4. p ↔ q\n";
    cout << "5. p ⊕ q\n";
    cout << "6. ~p ∧ q\n";
    cout << "7. (p ∧ q) ∨ r\n";
    cout << "8. p → (q ∨ r)\n";
    cout << "9. (p ↔ q) ∧ (q ↔ r)\n";
    cout << "10. ~p ∨ (q ∧ r)\n";
    cout << "11. Personalizada (más opciones)\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        resultado = Conjuncion(p, q);
        break;
    case 2:
        resultado = Disyuncion(p, q);
        break;
    case 3:
        resultado = Condicional(p, q);
        break;
    case 4:
        resultado = Bicondicional(p, q);
        break;
    case 5:
        resultado = DisyuncionExclusiva(p, q);
        break;
    case 6:
        resultado = Conjuncion(Negacion(p), q);
        break;
    case 7:
        resultado = Disyuncion(Conjuncion(p, q), r);
        break;
    case 8:
        resultado = Condicional(p, Disyuncion(q, r));
        break;
    case 9:
        resultado = Conjuncion(Bicondicional(p, q), Bicondicional(q, r));
        break;
    case 10:
        resultado = Disyuncion(Negacion(p), Conjuncion(q, r));
        break;

    case 11:
        cout << "\nEsta opción todavía está en desarrollo...\n";
        resultado = false;
        break;

    default:
        cout << "Opción no válida.\n";
        resultado = false;
    }

    cout << "\nResultado: " << (resultado ? "VERDADERO" : "FALSO") << endl;
}

// Función para probar todo (menú temporal)
void menuAvanzado()
{
    int opcion;
    do
    {
        cout << "\n\n=== MENÚ PARTE 2 - EXPRESIONES AVANZADAS ===\n";
        cout << "1. Evaluar expresión con p, q, r\n";
        cout << "2. Probar operadores individuales\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        if (opcion == 1)
        {
            evaluarExpresionCon3Variables();
        }
        else if (opcion == 2)
        {
            // Aquí puedes agregar pruebas individuales después
            cout << "Probar operadores individuales (pendiente)\n";
        }

    } while (opcion != 0);
}

// Función main solo para probar tu módulo (temporal)
int main()
{
    menuAvanzado();
    return 0;
}
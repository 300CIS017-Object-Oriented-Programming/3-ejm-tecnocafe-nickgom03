//
// Created by lenovo on 20/08/2025.
//
#include "Cafe.h"




void mostrarCartaProductos()
{
    cout << "\n--- Carta de productos ---\n";
    cout << "1. Tinto       $" << PRECIO_TINTO << "\n";
    cout << "2. Cappuccino  $" << PRECIO_CAPPUCCINO << "\n";
    cout << "3. Pandebono   $" << PRECIO_PANDEBONO << "\n";
    cout << "4. Sandwich    $" << PRECIO_SANDWICH << "\n";
    cout << "5. Papa rellena $" << PRECIO_PAPARELLENA << "\n";
}

int leerCodigoProducto()
{
    cout << "Ingrese el codigo del producto (1-4): ";
    int codigo;
    cin >> codigo;
    while (codigo < 1 || codigo > 4)
    {
        cout << "Codigo inválido. Intente de nuevo (1-4): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> codigo;
    }
    return codigo;
}

int leerCantidadProducto()
{
    cout << "Ingrese la cantidad (1-20): ";
    int cantidad;
    cin >> cantidad;
    while (cantidad < 1 || cantidad > 20)
    {
        cout << "Cantidad invalida. Intente de nuevo (1-20): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> cantidad;
    }
    return cantidad;
}

int obtenerPrecioPorCodigo(int codigoProducto)
{
    switch (codigoProducto)
    {
    case 1:
        {
            return PRECIO_TINTO;
        }
    case 2:
        {
            return PRECIO_CAPPUCCINO;
        }
    case 3:
        {
            return PRECIO_PANDEBONO;
        }
    case 4: {
        return PRECIO_SANDWICH;
    }
            case 5: {
        return PRECIO_PAPARELLENA;
    }
    default:
        {
            return 0;
        }
    }
}

string obtenerNombreProducto(int codigoProducto)
{
    switch (codigoProducto)
    {
    case 1:
        {
            return "Tinto";
        }
    case 2:
        {
            return "Cappuccino";
        }
    case 3:
        {
            return "Pandebono";
        }
    case 4:
        {
            return "Sándwich";
        }
    default:
        {
            return "Desconocido";
        }
    }
}

void registrarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados)
{
    if (cantidadItemsRegistrados >= MAX_ITEMS)
    {
        cout << "No es posible registrar más ítems en el pedido.\n";
        return;
    }
    mostrarCartaProductos();
    int codigo = leerCodigoProducto();
    int cantidad = leerCantidadProducto();

    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        if (codigos[i] == codigo)
        {
            cantidades[i] += cantidad;
            cout << "Producto actualizado: " << obtenerNombreProducto(codigo)
                << " x" << cantidades[i] << " (cantidad acumulada)\n\n";
            return;
        }
    }

    codigos[cantidadItemsRegistrados] = codigo;
    cantidades[cantidadItemsRegistrados] = cantidad;
    cantidadItemsRegistrados++;

    cout << "Producto agregado: " << obtenerNombreProducto(codigo)
        << " x" << cantidad << "\n\n";
}

double calcularSubtotalPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados)
{
    double subtotal = 0.0;
    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        int precioUnitario = obtenerPrecioPorCodigo(codigos[i]);
        subtotal += precioUnitario * cantidades[i];
    }
    return subtotal;
}

int leerTipoUsuario()
{
    cout << "Tipo de usuario (1=Estudiante, 2=Profesor, 3=Visitante): ";
    int tipo;
    cin >> tipo;
    while (tipo < 1 || tipo > 3)
    {
        cout << "Opción inválida. Intente de nuevo (1-3): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> tipo;
    }
    return tipo;
}

double obtenerPorcentajeDescuento(int tipoUsuario)
{
    if (tipoUsuario == 1)
    {
        return DESCUENTO_ESTUDIANTE;
    }
    if (tipoUsuario == 2)
    {
        return DESCUENTO_PROFESOR;
    }
    return DESCUENTO_VISITANTE;
}

double calcularTotal(double subtotal, double porcentajeDescuento)
{
    return subtotal * (1.0 - porcentajeDescuento);
}

void mostrarResumenPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados,
                          double porcentajeDescuento)
{
    cout << "\n===== Resumen del Pedido =====\n";
    double subtotal = 0.0;
    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        string nombre = obtenerNombreProducto(codigos[i]);
        int precio = obtenerPrecioPorCodigo(codigos[i]);
        double parcial = precio * cantidades[i];
        subtotal += parcial;
        cout << "- " << nombre << " x" << cantidades[i] << " = $" << parcial << "\n";
    }
    cout << "Subtotal: $" << subtotal << "\n";
    cout << "Descuento aplicado: " << (porcentajeDescuento * 100) << "%\n";
}

void mostrarProductoMasCaro(const int codigos[], const int cantidades[], int cantidadItemsRegistrados);
{
    if (n == 0) {
        std::cout <<"No hay productos por el momento"<<endl;
        return;
    }
    double precioMax = 0;
    int idxMax = 0;
    for (int i = 0; i < cantidadItemsRegistrados; i++) {
        double precioActual = obtenerPrecioPorCodigo(codigos[i]);
        if (precioActual > precioMax) {
            precioMax = precioActual;
            idxMax = i;
        }
    }

    std::cout << "Producto mas caro: " << obtenerNombreProducto(idxMax) << "Precio: " << precioMax <<"Cantidad: " << cantidades[idxMax] << std::endl;

}

void eliminarProducto(int codigos[], int cantidades[], int &n, int codigo);
{
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (codigos[i] == codigos[pos]) {
            pos = i;
        }
    }
    if (pos == -1) {
        std::cout <<"El codigo " << codigo << " no esta.\n";
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        codigos[i] = codigos[i + 1];
        cantidades[i + 1] = cantidades[i];
    }
}

void prediligenciarProductosDemo(int codigos[], int cantidades[], int & cantidadItemsRegistrados)
{
    // Limpiar pedido actual si existe
    cantidadItemsRegistrados = 0;

    // Añadir productos de ejemplo
    codigos[0] = 1;  // Tinto
    cantidades[0] = 2;

    codigos[1] = 3;  // Pandebono
    cantidades[1] = 3;

    codigos[2] = 4;  // Sandwich
    cantidades[2] = 1;

    cantidadItemsRegistrados = 3;

    cout << "\nSe han cargado productos de ejemplo en el pedido:\n";
    cout << "- 2 Tintos\n";
    cout << "- 3 Pandebonos\n";
    cout << "- 1 Sándwich\n\n";
    cout << "- 4 Empanadas\n";
    cout << "- 2 Papa Rellena\n";
}
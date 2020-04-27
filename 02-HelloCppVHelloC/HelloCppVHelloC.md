# Niveles del Lenguaje: Hello.cpp vHello.c
### GithubUser: *FernandoLlallire*
### Legajo *1406693*
### Apellido: *Llallire*
### Nombre: *Fernando*
### Numero y título del trabajo: *Niveles del Lenguaje: Hello.cpp vHello.c*
### Curso: *K2051*
### Año de cursada: *2020*
#### Enunciado

1. Armar una tabla con similitudes y diferencias para cada uno de los tres niveles del lenguaje, que compare ambas versiones de hello.
2. Opcional: Agregar una tercera versión en otro lenguaje de programación.

#### Hipótesis de trabajo que surgen luego de leer el enunciado.

> Observar todos los pasos de analisis Léxico, Sintáctico y Semántico del proceso de compilacion del lenguaje C y C++. Explicarlos y ver las diferencias que presentan en cada uno.

#### Resolución

Hello world en C
```c
#include <stdio.h>
int main() {
   printf("Hello, World!");
   return 0;
}
```
Hello world en C++
```cpp
#include <iostream>

int main() {
    std::cout << "Hello World!";
    return 0;
}
```

Hello world en JavaScript
```javascript
console.log("Hello, World!")
```


|sintaxis| C        | C++           | JavaScript  |
|:---:| :---: |:---:| :---:|
|Léxico|[(keyword, `int`), (identifier, `main`),(separator, `(`), (separator, `)`), (separator, `{`), (identifier, `printf` ), (separator, `(`), (literal, `"Hello world!"`), (separator, `)`), (separator, `;` ), (keyword, `return`), (literal, `0`), (separator, `;`), (separator, `}`)]| [(keyword, `int`), (identifier, `main`),(separator, `(`), (separator, `)`), (separator, `{`), (identifier, `std`), (operator, `::`), (identifier, `cout`), (operator, `<<`), (literal, `"Hello world!"`), (separator, `)`), (separator, `;`), (keyword, `return`), (literal, `0`), (separator, `;`), (separator, `}`)] | [(identifier, `console`), (operator, `.`), (identifier, `log`), (literal, `"Hello world!"`), (separator, `)`)] |
|Sintáctico| Verifica que `int main()`, `printf("Hello, World!")`, `return 0` sean gramaticalmente correctos segun el lenguaje C | Verifica que `int main()`, `std::cout << "Hello World!"`, `return 0` sean gramaticalmente correctos segun el lenguaje C++| verifica que `console.log("Hello, World!")` sea gramaticalmente correcto segun el lenguaje JavaScript |
|Semántico| Verifica que el valor entregado al metodo `printf` sea un tipo valido para imprimir. Verifica que el parametro del `return` sea del tipo `integer` y este definido antes de su uso. | Verifica que exista un metodo llamado `cout` en el scope `std`. Verifica que el valor entregado al metodo `cout` sea un tipo valido para imprimir. Verifica que el parametro del `return` sea del tipo `integer` y que el valor este definido antes de su uso.  | Verifica que el valor usado en el metodo `console.log` este definido antes de su uso|

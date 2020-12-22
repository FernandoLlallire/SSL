# Trabajo N° 9
### Githubuser: *FernandoLlallire*
### Legajo *1406693*
### Apellido: *Llallire*
### Nombre: *Fernando*
### Numero y título del trabajo: *Calculadora Infija: ConstrucciónManual — Iteración #2*
### Curso: *K2051*
### Año de cursada: *2020*
#### Enunciado

### Objetivos

* Experimentar el diseño de la especificación de lenguajes a nivel léxico y sintáctico.
* Experimentar la implementación manual del nivel léxico y sintáctico de lenguajes.

### Temas

* Especificación del nivel Léxico y Sintáctico.
* Implementación del nivel Léxico y Sintáctico.
* Implementación de Scanner
* Implementación de Parser

### Problema

Análisis de expresiones aritméticas infijas simples que incluya:

* Números naturales con representación literal en base 10.
* Identificadores de variables.
* Adición.
* Multiplicación.

Ejemplos de expresiones incorrectas:

```
A+2*3
2*A+3
A
2
```
Ejemplos de expresiones incorrectas:
```
+
42+
+A
```

### Solución

Especificar e implementar los niveles léxicos y sintácticos del lenguaje.

### Restricciones

* El scanner y el parser deben estar lógicamente separados.
* El parser se comunica con el scanner con la operación `GetNextToken`, el scanner toma los caracteres de `stdin` con getchar.

### Tareas

1. Diseñar el nivel léxico del lenguaje.
2. Diseñar el nivel sintáctico del lenguaje.
3. Implementar el scanner.
4. Implementar el parser.
5. Probar

### Productos

* `README.md`
* `Calc.md`
* `Makefile`
* `Scanner.h`
* `Parser.h`
* `Parser.c`
* `Scanner.c`
* `Calc.c`

## Hipótesis de trabajo que surgen luego de leer el enunciado
Se agregan los parentesis, y se pide que se agregue un proceso de interpretacion semantica.
Esto implica un par de cosas:</br></br>
**Analsis lexico** Ahora el analisis lexico vamos a usar Flex, el cual procesa un stream de caracteres y produce un programa  que reconoce los lexemas (expresiones regulares). Para entender mejor como es el uso de esta herramienta tenemos que entender que vamos a generar un archivo llamado scanner.l donde se suministran las regex y el codigo que tiene que ejecutarse al matchear.  </br>
Este archivo va ser el *Sorce file* que usa flex para generar el programa *yylex*. Este programa va a tomar como entrada el archivo *test* con nuestras expresiones a evaluar y va ejecutar cada accion en especifico a medida que encuentre  las ReGex definidas.

Como en el tp7 se definio la logica del scanner, parser y el analisis semantico, solo hay que pasar el scanner a flex.

Para poder usar Flex en ubuntu se tiene que correr este comando 
```
sudo apt-get install flex
```

</br>

**Analisis Sintactico** este se ejecuta en el parser y es quien se encarga de llamar al scanner para poder detectar la construccion sintactica.<br>
A diferencia del TP8 ahora vamos a usar Yacc/Bison para esta parte. Yacc usa un Análisis Sintáctico Ascendente, el cual nos permite tener un GIC/BNF definido en `parser.y`.
En cuanto al funcionamiento es el mismo, el `calc.c` llama al metodo `yyparse()`, el cual es el metodo del llamado a bison. Bison al ser el parser del programa es el encargado del llamado al scaner para poder indentificar los lexemas y a que token pertenecen, esto se logra llamando al metodo `extern int yylex();` el cual es creado por flex. Logrando de esta manera el mismo comportamiento que tenemos con los tepes anteriores, donde el parser es quien llama al scanner.
Algo que si se cambio es que ahora la definicion de los tokens no se hacen en el scaner, si no que se delega esa funcionalidad a bison el cual crea un archivo con todas las definiciones necesarias en un header aparte llamado `parserTokens.h`, esto es necesario por el modo en que se estan importando los headers en este proyecto, si no fuera asi se dejaria que estuvieran solamente definidas en `parser.c`.

**Analisis Semantico** este analisis es invocado por el Analsis sintactico, el cual al detectar una construccion semantica valida, invoca la rutina semantica correspondiente.


Para el analisis sintactico nos basamos en el Análisis Sintáctico Ascendente.
El cual esta representado con este GIC

```
Lista_de_sentencias: Sentencia FDT | Lista_de_sentencias '\n' Sentencia FDT
Sentencia: $identificador | identificador = Expresion
Expresion: Termino | Expresion + Termino
Termino: Factor | Termino * Factor
Factor: Number | Identifier | (Expresion)
``` 


Para el analisis Lexico vamos a usar este BNF para representarlo (Metalenguaje usado para expresar GIC)

```
<identificador> ::= <letra> { <letra o dígito> }
<letra o dígito> ::= <letra> | <dígito>
<letra> ::= a | b | c | d | e | f | g | h | i | j | k | l | m | n | o |
p | q | r | s | t | u | v | w | x | y | z | A | B | C | D |
E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S |
T | U | V | W | X | Y | Z
<dígito> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
<numero> ::= <numero> { <numero> }
```
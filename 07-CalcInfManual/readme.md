# Trabajo N° 7
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
**Analsis lexico** el cual va detectar los diferentes lexemas y los Lenguajes reguales a los que pertenecen (Tokens).
Esto lo vamos a ver en el metodo del **scanner** el cual es el encargado de interpretar lexemas y devolver un enum con el tipo de token.
</br>

**Analisis Sintactico** este se ejecuta en el parser y es quien se encarga de llamar al scanner para poder detectar la construccion sintactica.

**Analisis Semantico** este analisis es invocado por el Analsis sintactico, el cual al detectar una construccion semantica valida, invoca la rutina semantica correspondiente.


Para el analisis sintactico nos basamos en el Analisis Sintactico Descendente Recursivo (ASDR).
El cual esta representado con este GIC

```
Lista_de_sentencias: Sentencia FDT | Sentencia '\n' Lista_de_sentencias FDT
Sentencia: $identificador | identificador = Expresion
Expresion: Termino | Expresion + Termino
Termino: Factor | Termino * Factor
Factor: Number | (Expresion)
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
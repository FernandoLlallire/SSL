Parte 1
# Comparacion entre Strings en C y en Java

### ¿El tipo es parte del lenguaje en algún nivel?

En el lenguaje C no existe el tipo de dato String, si no que es un array compuesto por cada uno de los caracteres del string y un caracter `\0` al final.
En Java el tipo de dato String existe de manera nativa.

### ¿El tipo es parte de la biblioteca?
En C el tipo de dato String no existe para el Stdio.h
En Java El tipo de dato String es un objeto que vienen nativamente en el JRE.

### ¿Qué alfabeto usa?
En C podemos usar cualquier caracter Ascii.
En Java podemos representar cualquiere caracter en el formato UTF-16.

### ¿Cómo se resuelve la alocación de memoria?
En C los Strings son cosiderados array de strings, los cuales son alocados en el stack.
En Java al ser un String un objeto la memoria es alocada en el heap.
en ambos casos se tiene una referencia 

### ¿El tipo tiene mutabilidad o es inmutable?
En C el String es un array donde los valores que contiene son  mutables.
En Java el String es Inmutables pero se puede cambiar la refencia del mismo para que el objeto String, tenga otra cadena de caracteres diferente.

### ¿El tipo es un first class citizen?
En C el tipo de dato String no es un FCC.
En Java los Strings si son FCC.

## ¿Cuál   es   la   mecánica   para   ese   tipo   cuando   se   los   pasa   comoargumentos?
En C se pasa como argumento un puntero que apunta al primer valor del array que contiene los caracteres del String.
En Java se pasa una referencia al objeto con que contiene una referencia referencia del String.

### ¿Y cuando son retornados por una función?
En C se devuelve un puntero al primer elemento del array que contiene los caracteres del String.
En Java se devuelve una referencia al Objeto que contiene una referencia del String.
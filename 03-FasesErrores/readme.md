# Fases de la Traducción y Errores
### GithubUser: *FernandoLlallire*
### Legajo *1406693*
### Apellido: *Llallire*
### Nombre: *Fernando*
### Numero y título del trabajo: *Fases de la Traducción y Errores*
### Curso: *K2051*
### Año de cursada: *2020*
#### Enunciado

1. Investigar  las  funcionalidades  y  opciones  que  su  compilador  presenta  paralimitar el inicio y fin de las fases de traducción.
2. Para la siguiente secuencia de pasos:
   1. Transicribir en readme.md cada comando ejecutado 
   2. Describir en readme.md el resultado u error obtenidos para cada paso.

#### Hipótesis de trabajo que surgen luego de leer el enunciado.

>

#### Resolución

1. Escribir hello2.c, que es una variante de hello.c:
   ```cpp
        #include <stdio.h>
        int/*medio*/main(void){
            int i=42;
            prontf("La respuesta es %d\n");
   ```

2. Preprocesar   hello2.c,   no   compilar,   y   generar hello2.i.   Analizar   sucontenido

3. Escribir hello3.c, una nueva variante:
   ```cpp
        int printf(const char *s, ...);
        int main(void){
        int i=42;
        prontf("La respuesta es %d\n");
   ```
4. Investigar la semántica de la primera línea.
   
Se declara el prototipo de la funcion printf, y los argumentos que va a recibir

5. Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferenciasentre hello3.c y hello3.i.

Se le agregan tags como los de `<command-line>` y `<built-in>` ademas de la definicion del nombre del archivo, pero a diferencia que el hello2.```cppi no se le agrega ninguna libreria ni prototipado.

6. Compilar el resultado y generar hello3.s, no ensamblar.

Al compilar y generar el hello3.s obtenemos el siguiente mensaje

    gcc hello3.i -std=c18 -S -o hello3.s
    hello3.c: In function ‘main’: [-Wimplicit-function-declaration]
    prontf("La respuesta es %d\n");
    ^~~~~~
    printf
    hello3.c:4:9: error: expected declaration or statement at end of input

Podemos ver que tenemos un error de sintactico, ya que nunca se escribe `}` para cerrar el bucle del scope main.

7. Corregir  en  el  nuevo  archivo  hello4.c  y  empezar  de  nuevo,  generar hello4.s, no ensamblar.

8. Investigar hello4.s.

9. Ensamblar hello4.s en hello4.o, no vincular.
En este paso estamos generando el codigo objeto del hello4.c

10.  Vincular hello4.o con la biblioteca estándar y generar el ejecutable.

Vamos a realizar la vinculacion con `gcc -Wall hello4.c /usr/include/stdio.h -o hello4`

    hello4.c: In function ‘main’:
    hello4.c:4:9: warning: implicit declaration of function ‘prontf’; did you mean ‘printf’? [-Wimplicit-function-declaration]
    prontf("La respuesta es %d\n");
    ^~~~~~ 
Como podemos ver tenemos un error sintactico, ya que esta mal escrita la funcion `printf`

11.  Corregir en hello5.c y generar el ejecutable
  
Vamos a realizar la vinculacion con `gcc -Wall hello5.c /usr/include/stdio.h -o hello5`

    hello5.c: In function ‘main’:
    hello5.c:4:34: warning: format ‘%d’ expects a matching ‘int’ argument [-Wformat=]
    printf("La respuesta es %d\n");
                            ~^
esto error semantico ocurre por que no estamos validando bien el tipo de dato entregado para printf, que necesita un tipo de dato int.

12.  Ejecutar y analizar el resultado.
  
13. Corregir en hello6.c y empezar de nuevo.
Al ejecutar el codigo como `./hello6` nos da el siguiente mensaje `La respuesta es 42`

14.  Escribir hello7.c, una nueva variante:
  ```cpp
    int main(void){
    int i=42;
    printf("La respuesta es %d\n", i);
    }
  ```
Vamos a tener el siguiente mensaje al generar el ejecutable


    hello7.c: In function ‘main’:
    hello7.c:3:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
        printf("La respuesta es %d\n", i);
        ^~~~~~
    hello7.c:3:5: warning: incompatible implicit declaration of built-in function ‘printf’
    hello7.c:3:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
    hello7.c:1:1:
    #include <stdio.h>
     int main(void){
    hello7.c:3:5:
        printf("La respuesta es %d\n", i);
        ^~~~~~

15. Explicar porqué funciona.
    Como no estan definidas todas las instancias de printf, cuando llega a la implementacion en el
    codigo genera una definicion `implicita` para poder trabajarla, gracias a esto es que funciona
    pero si existiera otra instancia de printf con otros argumentos, nos daria error ya que no esta definida la funcion.
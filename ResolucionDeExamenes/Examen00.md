# Examen N° 0
### Curso: K2051
### Año de cursada: 2020
### Legajo 1406693
### Apellido: Llallire
### Nombre: Fernando

***
 ### Parte 1
1. Indique la tarea más representativa para la cual un Ingeniero en Sistemas de Información está calificado.
>El ingeniero en Sistemas de Información es profecionl apto para la  interpretación y resolución de problemas mediante el empleo de metodologías de sistemas y tecnologías de procesamiento de información.

2. Defina información.

  > Conjunto de datos procesado que nos da a conocer el sistema y nos permite tomar decisiones a corde al mismo.

3. Indique las asignaturas del área de programación.
>Asignaturas
>1. Matemática Discreta
>2. Algoritmos y Estructuras de Datos
>3. Sintaxis y Semántica de los Lenguajes
>4. Paradigmas de Programación
>5. Gestión de Datos

4. Indique las asignaturas del área de sistemas de información.
>Analisis de sistemas
>
>Sistemas y Organizaciones
>
>Diseño de Sistemas
>
>Administracion de recursos
>
>Projecto Final

5. Indique el paradigma de programación aplicado en primer año de la carrera.
>El Paradigma de programacion usado en primer año es el imperativo.

6. Defina abstracción.
>Separación de un elemento de su contexto, dejar de lado los detalles para enfocar en lo importante
***
### Parte 2

1. Indique diferencias entre secuencia y conjunto.
> Un conjunto es una colección de objetos de una misma especie, estos objetos se los define como elementos del conjunto. La secuencia a diferencia del el orden de los terminos que lo componen tiene importancia y ademas un mismo termino puede aparecer en mas de una posición.

2. Defina el concepto matemático secuencia.
>Una secuencia es una sucesión en una lista de elementos, uno despúes del otro , numerada en el orden creciente de los números naturales.

3. Defina función matemática.
> es una relación entre dominio y el codominio de forma que a cada elemento x del dominio le corresponde un único elemento f(x) del codominio
4. Defina grafo.
>Un grafo es un conjunto de puntos o nodos unidos por arcos o aristas.

5. Defina partición de un conjunto.
>Conjunto de subconjuntos disjuntivos y no vacios generada por la relacion de equivalencia definida en un conjunto.

6. (1 punto) Sea X={a,b} indique P(X)
> P(X) = { Ø , { a } , { b } , X }

7. Defina Lenguaje Formal.
>El lenguaje es un subconjunto de la clausura de Kleene del alfabeto "V", el cual es un conjunto de todas las palabras, de cualquier longitud, que se puede escribir con letras del alfabeto "V" .

8. Defina autómata finito.
>Maquina reconocedora de lenguajes regulares. se representa por una 5-upla formada por el conjunto finito de estados, el alfabeto de entrada, la función de transición, el estado inicial, y el conjunto de estados finales.
***
### Parte 3

3. Defina algoritmo.
>Un  algoritmo  se  puede  definir  como  una  secuencia  de  instrucciones  que  representan  un  modelo  de  solución  para  determinado  tipo  de  problemas.

2. Defina programación estructurada.
>El Paradigma de programacion estructurada se basado en utilizar funciones o subrutinas y unicamente usando como estructutas de control la Secuencial, Condicional y la de Iteración

3. Indique las tres estructuras de control de flujo de ejecución de la programación estructurada
>* "Secuencial" la ejecucion de una sentencia tras otra.
>* "Condicional" ejecucion de un conjunto de sentencias dependiendo de una variable booleana
>* "Iteración" ejecucion de un conjunto de sentencias mientras una variable booleana sea verdadera.

4. Indique las diferencias entre parámetro y argumento.
>Los parámetros son propiedades que aparecen en la definicion en una metodo mientras que los argumentos son los datos que pasamos a los parametros del metodo al ser llamado.

5. Explique las dos formas de transferencia de argumentos.
>Podemos transferir argumentos por "valor" haciendo una copia del argumento en el parametro del metodo y por "referencia" donde la posicion de memoria que esta asigana al paramtro del metodo es el mismo que el del argumento pasado.

6. Explique las diferencias entre parámetros de entrada, de salida y de entrada/salida.
>Los parametros de entada solo pueden usarse para el ingreso de datos, los de salida para el retorno de datos mientras que los de entrada/salida puede usarse para ambos usos.

7. Defina tipo de dato abstracto.
>Un tipo de dato abstracto es un modelo que define valores y operaciones que se pueden realizar sobre ellos, y es abstracto por que quien lo utiliza, no necesita conocer los detalles de la representacion interna o como estan implementadas las operaciones.

8. Indique las diferencias entre una pila y una cola
>La pila es una estructura de datos ordenada que permite almacenar y recuperar datos con un modo de acceso LIFO. Mientras que la cola es una estructura de datos que permite almacenar y recuperar datos con un modo de acceso FIFO.

9. Defina archivo.
>Conjunto de bytes almacenados en un dispositvo.

10. Diseñe un algoritmo que dado un arreglo de naturales a y su longitud n calcule el promedio

```go
#Codigo en GOlang
package main

import (
	"fmt"
)

func main() {
	values := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	sum := 0
	result := 0
	for _, value := range values {
		sum += value
	}
	result = sum / len(values)
	fmt.Println(result)
}

```

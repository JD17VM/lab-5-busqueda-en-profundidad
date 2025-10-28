# Laboratorio 05 - Búsqueda en Profundidad

1. Casos extremos. ¿Cuál es el resultado de GRAPHdfs( G) cuando G->A es 0? ¿Y cuando G->V es 1?
2. Base de la recursión. ¿Cuál es la base de la recursión en la función dfsR()?
3. Ejecuta una búsqueda en profundidad en el grafo dado por las siguientes listas de adyacencia. Haga un
rastreo de la búsqueda.
4. Realice el seguimiento de la ejecución de la función GRAPHdfs() sobre el grafo no dirigido definido por
los aristas 3-7, 1-4, 7-8, 0-5, 5-2, 3-8, 2-9, 0-6, 4-9, 2-6 y 6-4.
5. Imprimir rastreo. Modifique las funciones GRAPHdfs() y dfsR() para que impriman un rastreo como el de
los ejemplos anteriores. Para realizar la sangría, utilice una variable de sangría global que se incremente
cuando la ejecución entre en dfsR() y se decremente cuando la ejecución salga de dfsR(). Para probar
tus funciones, prepara un programa que tome como entrada un grafo representado por un archivo de
texto.
Un archivo de adyacencia es un archivo de texto que tiene el siguiente formato: la primera línea del archivo contiene un
número entero estrictamente positivo V y cada una de las líneas V siguientes contiene un número entero positivo seguido de
otros cero o más números enteros, todos ellos comprendidos entre 0 y V-1. He aquí un ejemplo:
( El último carácter del archivo es un \n.) Un archivo de adyacencia describe un grafo con 0..V-1 vértices. Las últimas V líneas
del archivo definen los arcos del grafo: la línea que empieza por v contiene la lista de todos los vecinos de v.
6. ¿El siguiente algoritmo iterativo realiza una búsqueda en profundidad? Las funciones con el prefijo
STACK manipulan una pila de vértices: STACKinit() crea una pila vacía, STACKpush() coloca un vértice en
la pila, STACKpop() retira un vértice de la pila y STACKempty() devuelve verdadero si la pila está vacía.
7. DFS iterativa para listas de adyacencia. Escriba una versión iterativa de la función dfsR() para grafos
representados por listas de adyacencia.
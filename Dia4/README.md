
# DIA 4
## ELECCIÓN DEL PROBLEMA
Porque se ha usado grafos y un algoritmo de BFS vistos en clase.
## ESTRUCTURA DE DATOS UTILIZADA
Grafos y Hash personalizada para puntos.
## COMO SE HA ABORDADO EL PROBLEMA
Analizando priemero la entrada, construimos el grafo creando nodos por cada @ y los conectamos con todos sus otros nodos del grafo vecinos.
Para la primera parte: Miramos los que tengan mas de 4 vecinos y los contamos.
Para la segunda parte: Un BFS para ir eliminando en cascada todos aquellos que ya no vayan teniendo mas de 4 vecinos.
## ALTERNATIVAS
Recorrer y rerecorrer la matriz hasta que no queden mas (natural) 
## QUE SE HA APRENDIDO
Implementacion de grafos y usos de estos mas haya de encontrar y recorrer caminos.

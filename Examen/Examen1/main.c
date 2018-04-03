/* 
Descripción del problema

Funciones:
    - insert(char *string, char *insert, int pos)
        Inserta la string 'insert' en la posición 'pos' en la string 'string'
        1.- Crea un buffer con el que se estará trabajando
        2.- Copia los elementos de string hasta la posición (Sin incluir) en buffer.
        3.- Calcula el length de lo copiado en 'len'
        4.- Copia en buffer a partir de lo copiado anteriormente (En la posición de 'len'), la string que se quiere insertar.
        5.- Se vuelve a calcular el 'len' de 'string'
        6.- Copian en el buffer a partir de lo copiado anteriormente (En la nueva posición 'len'), la string faltante.
        7.- Se copia buffer en string, remplazandola
        COMPLEJIDAD: O(4n), debido a los 4 strcpy realizados
    (Nota, esta función, realiza el trabajo necesario, aunque hace de más -Copiar la primera parte de string-. 
    Esto es porque la inserción siempre se realiza en la posición 0. Se podría comentar el primer strncpy y seguiría funcionando. 
    Pero este insert es una función que ya había implementado.)

    - main()
        0.- Se crea el buffer capaz de almacenar de sobra la línea. Se le hace un malloc().
        1.- Primero obtiene el número de casos que se van a probar, usando strtol(),
            que convierte el valor númerico de una string a la base que se le indique.
            Esta función necesita de otro puntero que es usado como un buffer interno.
            Ese puntero 'ptr' no se vuelve a usar.
            Este valor se guarda en 
        2.- Se inicia un ciclo for, que termina después de ejecutar todos los casos.
        3.- Se lee la línea y se almacena en el buffer. También se le borra el caracter de salto de línea.
        4.- Se crea la string 'reversedLine' para almacenar la línea en reversa. Se utiliza malloc().
        5.- Se obtiene la primer palabra utilizando la función strsep(). Esta función recibe &buffer y un caractér delimitante.
            strsep retorna el apuntador a una string en el buffer que esta rodeada por el caracter delimitante; y cambia buffer,
            haciendo que comience por la parte del string a partir de la subtring retornada. Hace esto hasta que regresa un puntero nulo.
            Entonces si a strsep se le alimenta ' ' como delimitante, se puede obtener palabra por palabra hasta que se retorne nulo.
            COMPLEJIDAD O(n).
        6.- Se inserta la substring a 'reversedLine' en la posición 0.
        7.- Se inserta un ' ' en la posición 0 de 'reversedLine'.
        8.- Se obtine la siguiente palabra utilizanfo strsep() en el ciclo while (Paso 5).
        9.- Al terminar, la string tiene un ' ' al inicio innecesario. Este caracter se elimina cambiando el apuntador de
            'reversedLine' por la dirección de su segundo elemento.
        10.- Se imprime la línea y comienza el análisis de la siguiente.

        COMPLEJIDAD POR LÍNEA: O(palabras * (4n + n)) >= O(n)
        COMPLEJIDAD TOTAL: O(lineas * COMPLEJIDAD POR LÍNEA) >= O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "sample-Reverse.1.in"

void insert(char *string, char *insert, int pos) {
    char buf[2048] = {};
    strncpy(buf, string, pos);
    int len = strlen(buf);
    strcpy(buf+len, insert);
    len += strlen(insert);
    strcpy(buf+len, string+pos);
    strcpy(string, buf);
}

int main(int argc, char **argv) {

    FILE *fileInput = fopen(FILENAME, "r");

    char *buffer;
    size_t bufsize = 2048;
    buffer = (char *) malloc(bufsize * sizeof(char));

    getline(&buffer, &bufsize, fileInput);
    char *ptr;
    int numCase = strtol(buffer, &ptr, 10);

    for(int i = 0; i < numCase; i++) {

        getline(&buffer, &bufsize, fileInput);
        int n = strcspn(buffer, "\n");
        buffer[n] = '\0';

        char *reversedLine = (char *) malloc(2048 * sizeof(char));

        // printf("Read: %s\n", buffer);

        if(buffer != NULL) {
            char *substr;
            while((substr = strsep(&buffer, " ")) != NULL) {
                // printf("\tWord: %s\n", substr);
                insert(reversedLine, substr, 0);
                insert(reversedLine, " ", 0);
            }
            reversedLine = &reversedLine[1];
            printf("%s\n", reversedLine);
        }
    }

    return 0;
}
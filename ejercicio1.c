#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno {
   int matricula;
   char nombre[50];
   char direccion[50];
};
void datos_alumnos(FILE *fp);
void desplegar_datos_alumnos(FILE *fp);

int main() {
    FILE *fp;
    fp = fopen("registros.dat", "ab");
    if (fp == NULL) {
        printf("ERROR al abrir el archivo.");
        exit(1);
    }
    datos_alumnos(fp);
    fclose(fp);
    fp = fopen("registros.dat", "rb");
    if (fp == NULL) {
        printf("ERROR al abrir el archivo.");
        exit(1);
    }
    desplegar_datos_alumnos(fp);
    fclose(fp);
    return 0;}

void datos_alumnos(FILE *fp) {
    struct alumno a;
    printf("Ingrese la matricula (deje en blanco para terminar): ");
    char input[50];
    while (fgets(input, sizeof(input), stdin) != NULL && input[0] != '\n') {
        if (sscanf(input, "%d", &a.matricula) == 1) {
            printf("Ingrese el nombre: ");
            scanf("%s", a.nombre);
            printf("Ingrese la direccion: ");
            scanf("%s", a.direccion);
            fwrite(&a, sizeof(struct alumno), 1, fp);

            while (getchar() != '\n')
                continue;
        } else {
            break;
        }
        printf("Ingrese la matricula (deje en blanco para terminar): ");}
}
void desplegar_datos_alumnos(FILE *fp) {
    struct alumno a;
    while (fread(&a, sizeof(struct alumno), 1, fp) == 1) {
        printf("Matricula: %d\n", a.matricula);
        printf("Nombre: %s\n", a.nombre);
        printf("Direccion: %s\n", a.direccion);
        printf("\n");
    }
}

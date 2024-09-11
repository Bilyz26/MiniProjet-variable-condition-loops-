#include <stdio.h>

int main() {
    int option;
    char prenom[50], nom[50];
    int note, minNote = 101, maxNote = -1;
    char nomMin[50], nomMax[50];
    int totalStudents = 0;
    int sumNotes = 0;
    int notes[100];
    int noteCount = 0;

    do {
        printf("Choisissez une option:\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Calculer et afficher la moyenne\n");
        printf("3. Afficher l'étudiant avec la meilleure et la pire note\n");
        printf("4. Vérifier combien d'étudiants ont une note supérieure à la moyenne\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Entrez le prénom de l'étudiant: ");
                scanf("%s", prenom);
                printf("Entrez le nom de l'étudiant: ");
                scanf("%s", nom);
                printf("Entrez la note de l'étudiant: ");
                scanf("%d", &note);

                if (note < minNote) {
                    minNote = note;
                    snprintf(nomMin, sizeof(nomMin), "%s %s", prenom, nom);
                }
                if (note > maxNote) {
                    maxNote = note;
                    snprintf(nomMax, sizeof(nomMax), "%s %s", prenom, nom);
                }

                notes[noteCount++] = note;
                sumNotes += note;
                totalStudents++;

                printf("Étudiant ajouté.\n");
                break;

            case 2:
                if (totalStudents > 0) {
                    double average = (double)sumNotes / totalStudents;
                    printf("La moyenne des notes est: %.2f\n", average);
                } else {
                    printf("Aucun étudiant ajouté.\n");
                }
                break;

            case 3:
                if (totalStudents > 0) {
                    printf("L'étudiant avec la meilleure note (%d) est: %s\n", maxNote, nomMax);
                    printf("L'étudiant avec la pire note (%d) est: %s\n", minNote, nomMin);
                } else {
                    printf("Aucun étudiant ajouté.\n");
                }
                break;

            case 4:
                if (totalStudents > 0) {
                    double average = (double)sumNotes / totalStudents;
                    int aboveAverageCount = 0;
                    for (int i = 0; i < noteCount; i++) {
                        if (notes[i] > average) {
                            aboveAverageCount++;
                        }
                    }
                    printf("Nombre d'étudiants ayant une note supérieure à la moyenne: %d\n", aboveAverageCount);
                } else {
                    printf("Aucun étudiant ajouté.\n");
                }
                break;

            case 5:
                printf("Quitter le programme.\n");
                break;

            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }

    } while (option != 5);

    return 0;
}

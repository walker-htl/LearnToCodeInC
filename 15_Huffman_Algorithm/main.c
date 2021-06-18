#include <stdio.h>
#include "huffman_tree.h"

int main() {
    int no_of_characters = 0;
    char *fileName ="SimpleText.txt";

    // todo: dieser Methodenaufruf würde man nicht in die main Methode geben!
    h_chars *letter_stats = get_huffmann_letter_array(&no_of_characters, fileName);

    // todo: diese Ausgabe gehört nicht in die main Methode!
    printf("1. Step: collect all letters with their frequencies\n");
    for (int i = 0; i < no_of_characters; i++) {
        printf("%d. character=[%c] with frequency=%d\n", i, letter_stats[i].character, letter_stats[i].frequency);
    }

    printf("\n2. Step: create tree\n");
    //todo: die Ausgabe des Baumes sollte man nicht sehen und auch diese Methode gehört nicht hier her!
    h_node *tree = build_huffman_tree(letter_stats, &no_of_characters);

    printf("\n3. Step: decode code\n");
    // todo: decode sollte einen char pointer zurückliefern!
    decode("111001011011", tree);

    printf("\n\n4. step: encode text?\n");

    return 0;
}
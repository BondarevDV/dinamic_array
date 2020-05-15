#include <iostream>
#include <stdio.h>
#include "bdvarray.h"
#include <stdio.h>     /* для printf */
#include <stdlib.h>    /* для exit */
#include <getopt.h>



int main(int argc, char **argv)
{
    int c;
    BdvArray<int> codeTable;
    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"add", 1, nullptr, 0},
            {"delete", 1, nullptr, 0},
            {"verbose", 0, nullptr, 0},
            {"create", 1, nullptr, 'c'},
            {"file", 1, nullptr, 0}
        };

        c = getopt_long (argc, argv, "", long_options, &option_index);
        if (c == -1)
            break;

        switch (c) {
        case 0:
            printf ("параметр %s", long_options[option_index].name);
            if (optarg)
                printf (" с аргументом %s", optarg);
            printf ("\n");
            break;
        default:
            printf ("?? getopt возвратило код символа 0%o ??\n", c);
        }
    }

    if (optind < argc) {
        printf ("элементы ARGV, не параметры: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        printf ("\n");
    }
    exit (0);
//    BdvArray<int> codeTable;
//    std::cout << "Hello World!" << std::endl;
//    std::cout << "size = " << codeTable.size() << std::endl;
//    int index = 0;
//    codeTable.Add(1);
//    codeTable.Add(2);
//    codeTable.Add(3);
//    codeTable.Add(4);
//    std::cout << "size = " << codeTable.size() << std::endl;
//    auto test = codeTable[0];
//    printf ("item array index=%d, value=%d\n",index, test);
//    if (argc > 1){
//          std::cout << argv[0]<<std::endl;} else {
//          std::cout << "Not arguments" << std::endl;
//    }
//    putchar('\a');  /* здесь подается звуковой сигнал */
//    printf("Счет закончен");

    return 0;
}

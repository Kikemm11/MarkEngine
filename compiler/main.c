#include <stdio.h>
#include <stdlib.h>
#include <expression.hpp>
#include <string>  // Para usar std::string

extern FILE* yyin;
extern int yyparse();
extern Expression* parser_result;

void usage(char* argv[])
{
    printf("Usage: %s input_file\n", argv[0]);
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        usage(argv);
    }

    yyin = fopen(argv[1], "r");

    if (!yyin)
    {
        printf("Could not open %s\n", argv[1]);
        exit(1);
    }

    int result = yyparse();

    if (result == 0)
    {
        // Crear la variable donde se almacenará el texto formateado
        std::string output;


        output = "\\documentclass{article}\n\n\\begin{document}\n";
        output += parser_result->eval();  // Agregar el resultado de eval() a la cadena
        output += "\n\\end{document}";

        printf("%s\n", output.c_str());

        // Abrir el archivo de salida en modo escritura
        FILE* outputFile = fopen("output.txt", "w");  // Aquí se guarda en 'output.txt'
        if (!outputFile)
        {
            printf("Error opening file for writing\n");
            exit(1);
        }

        fprintf(outputFile, "%s\n", output.c_str());
       
        fclose(outputFile);

        parser_result->destroy();
    }
    else
    {
        printf("Parse failed!\n");
    }

    return 0;
}






// #include <stdio.h>
// #include <stdlib.h>

// #include <expression.hpp>

// extern FILE* yyin;
// extern int yyparse();

// extern Expression* parser_result;

// void usage(char* argv[])
// {
//     printf("Usage: %s input_file\n", argv[0]);
//     exit(1);
// }

// int main(int argc, char* argv[])
// {
//     if (argc != 2)
//     {
//         usage(argv);
//     }

//     yyin = fopen(argv[1], "r");

//     if (!yyin)
//     {
//         printf("Could not open %s\n", argv[1]);
//         exit(1);
//     }

//     int result = yyparse();

//     if (result == 0)
//     {
//         std::string output;
//         output = "\\documentclass{article}\n\n\\begin{document}\n";
//         output += parser_result->eval();  
//         output += "\n\\end{document}";

//         printf("%s\n", output.c_str());
//         parser_result->destroy();
//     }
//     else
//     {
//         printf("Parse failed!\n");
//     }

//     return 0;
// }
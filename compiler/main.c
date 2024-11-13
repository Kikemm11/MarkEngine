/*
Authors:
- Iván Maldonado (Kikemaldonado11@gmail.com)
- Maria José Vera (nandadevi97816@gmail.com)

Developed at: November 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

        output = parser_result->eval();  
        
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
    
        int result = system("pdflatex -jobname=output -output-directory=. output.txt");

        if (result == -1) {
        fprintf(stderr, "Error running pdflatex\n");
        return 1;
        }

        system("rm output.aux output.log ");

        parser_result->destroy();
    }
    else
    {
        printf("Parse failed!\n");
    }

    return 0;
}
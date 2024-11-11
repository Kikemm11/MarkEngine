/*
Authors:
- Iván Maldonado (Kikemaldonado11@gmail.com)
- Maria José Vera (nandadevi97816@gmail.com)

Developed at: November 2024
*/

#include <expression.hpp>
#include <string>


// Expression destructor
Expression::~Expression() {}



// Program rule treatment

Program::Program(Expression* _head, Expression* _program, std::vector<std::string> &titles) noexcept
{
        // Get program header
        std::string _head_str = _head->eval();

        //Get program content wether it has index or not
        std::string _program_str = _program->eval();
        int pos = _program_str.find("@index:");
        const int SUBSTRING_SIZE = 7;

        if (pos != -1)
        {
            std::string pre_string = _program_str.substr(0, pos -1);
            std::string pos_string = _program_str.substr(pos + SUBSTRING_SIZE, _program_str.size());

            std::string index = "( Latext index ->\n";

            for (auto title : titles)
            {
                index = index + title + "\n";
            }

            index = index + ")\n";

            program = pre_string + index + pos_string;

        }
        else
        {
            program = _program->eval();
        }

        program = "\\documentclass{article}\n\n" + _head_str + "\\begin{document}\n\\maketitle\n" + program + "\n\\end{document}";
}

void Program::destroy() noexcept {}

std::string Program::eval() noexcept
{
    return program;
}


// Head rule treatment

Head::Head(Expression* _title, Expression* _author, Expression* _date) noexcept
{
        head = _title->eval() + _author->eval() + _date->eval();
}

void Head::destroy() noexcept {}

std::string Head::eval() noexcept
{
    return head;
}


// Title rule treatment

Title::Title(Expression* _title, std::vector<std::string> &titles) noexcept
{
        title = "\\title{" + _title->eval() + "}\n\n";

        titles.push_back(_title->eval());
}

void Title::destroy() noexcept {}

std::string Title::eval() noexcept
{
    return title;
}


// Author rule treatment

Author::Author(Expression* _author) noexcept
{
        author = "\\author{" + _author->eval() + "}\n\n";
}

void Author::destroy() noexcept {}

std::string Author::eval() noexcept
{
    return author;
}


// Date rule treatment

Date::Date(Expression* _date) noexcept
{
        date = "\\date{" + _date->eval() + "}\n\n";
}

void Date::destroy() noexcept {}

std::string Date::eval() noexcept
{
    return date;
}


// Subtitle rule treatment

Subtitle::Subtitle(Expression* _subtitle) noexcept
{
        subtitle = "\\subsection{" + _subtitle->eval() + "}\n\n";
}

void Subtitle::destroy() noexcept {}

std::string Subtitle::eval() noexcept
{
    return subtitle;
}


// Chapter rule treatment

Chapter::Chapter(Expression* _chapter) noexcept
{
        chapter = "\\section{" + _chapter->eval() + "}\n\n";
}

void Chapter::destroy() noexcept {}

std::string Chapter::eval() noexcept
{
    return chapter;
}


// Abstract rule treatment

Abstract::Abstract(Expression* _abstract) noexcept
{
        abstract = "\\begin{abstract} \n" + _abstract->eval() + "\n\\end{abstract}\n\n";
}

void Abstract::destroy() noexcept {}

std::string Abstract::eval() noexcept
{
    return abstract;
}


// Index rule treatment

Index::Index(std::vector<std::string> & titles) noexcept
{
        index = "@index:";
}

void Index::destroy() noexcept {}

std::string Index::eval() noexcept
{
    return index;
}


// Paragraph rule treatment

Paragraph::Paragraph(Expression* _paragraph) noexcept
{
    //paragraph = "\\paragraph{" + _paragraph->eval() + "}\n\n";
    paragraph = _paragraph->eval() + "\n";
}

void Paragraph::destroy() noexcept {}

std::string Paragraph::eval() noexcept
{
    return paragraph;
}


// List rule treatment

List::List(Expression* _list) noexcept
{
        list = "( Latex -> " + _list->eval() + " )\n";

        //elements = this->get_elements(_list->eval());
}

void List::destroy() noexcept {}

std::string List::eval() noexcept
{
    return list;
}

std::vector<std::string> List::get_elements(std::string str) noexcept
{
    std::vector<std::string> elements;
    int pos = 0;
    while(pos < str.size()){
        pos = str.find(",");
        elements.push_back(str.substr(0,pos));
        str.erase(0,pos+1); 
    }
    return elements;
}


// Image rule treatment

Image::Image(std::string _img_path) noexcept
{
        image = "\\begin{figure}[h] \n\\includegraphics[width=0.5\\textwidth]{" + _img_path + "}\n\\end{figure}\n\n";
}


void Image::destroy() noexcept {}

std::string Image::eval() noexcept
{
    return image;
}


// Quote rule treatment

Quote::Quote(Expression* _quote, Expression* _author, Expression* _year) noexcept
{
        quote = "\\begin{quote}\n" + _quote->eval() + "\n\\end{quote}\n\\begin{flushright}\n" + _author->eval() + "\nyear: " + _year->eval() + "\\end{flushright}\n\n";
}


void Quote::destroy() noexcept {}

std::string Quote::eval() noexcept
{
    return quote;
}


// Foot rule treatment

Foot::Foot(Expression* _foot) noexcept
{
        foot = "\\footnote{" + _foot->eval() + "}\n\n";
}

void Foot::destroy() noexcept {}

std::string Foot::eval() noexcept
{
    return foot;
}


// Row rule treatment

Row::Row(Expression* _row) noexcept
{
        row =  _row->eval() + " \\\\ \n";
}

void Row::destroy() noexcept {}

std::string Row::eval() noexcept
{
    return row;
}

std::vector<std::string> Row::get_values(std::string str) noexcept
{
    std::vector<std::string> values;
    int pos = 0;
    while(pos < str.size()){
        pos = str.find(",");
        values.push_back(str.substr(0,pos));
        str.erase(0,pos+1); 
    }
    return values;
}


// RowList rule treatment (Concatenate n number of rows)

RowList::RowList(Expression* old_row, Expression* new_row) noexcept
{
    rows = old_row->eval() + new_row->eval();
}

void RowList::destroy() noexcept {}

std::string RowList::eval() noexcept
{
    return rows;
}


// Table rule treatment

Table::Table(Expression* _head, Expression* _rows) noexcept
{
        columns = this->get_columns(_head->eval());
        rows = this->get_columns(_rows->eval());

        table = "\\begin{table}[h]\n\\centering\n";
        table += "\\begin{tabular}{" + std::string(columns.size(), 'c') + "}\n\\hline\n";

        
        // Agregar los encabezados de las columnas
        for (size_t i = 0; i < columns.size(); ++i) {
        table += columns[i];
            if (i < columns.size() - 1) {
                table += " & ";
            }
        }
        table += " \\\\ \\hline\n";

    // agregar las filas
        for (size_t i = 0; i < rows.size(); ++i) {
        table += rows[i];
            if (i < rows.size() - 1) {
                table += " & ";
            }
        }
        table += "\\\\ \\hline\n";
 

        table += "\\end{tabular}\n\\caption{Mi tabla de ejemplo}\n\\end{table}\n";
        
}

void Table::destroy() noexcept {}

std::string Table::eval() noexcept
{
    return table;
}

std::vector<std::string> Table::get_columns(std::string str) noexcept
{
    std::vector<std::string> columns;
    size_t pos = 0;

    // Mientras haya comas en la cadena
    while (pos < str.size()) {
        size_t next_pos = str.find(",", pos); // Buscar la siguiente coma
        
        // Si no encontramos más comas, tomamos la subcadena desde `pos` hasta el final
        if (next_pos == std::string::npos) {
            columns.push_back(str.substr(pos)); // Agregar lo restante
            break; // Salir del ciclo
        }

        // Si encontramos una coma, agregamos la subcadena desde `pos` hasta `next_pos`
        columns.push_back(str.substr(pos, next_pos - pos));

        // Actualizamos `pos` para que apunte después de la coma
        pos = next_pos + 1;
    }

    return columns;
}


std::vector<std::string> Table::get_rows(std::string str) noexcept
{
    std::vector<std::string> rows;
    size_t pos = 0;

    // Mientras haya comas en la cadena
    while (pos < str.size()) {
        size_t next_pos = str.find(",", pos); // Buscar la siguiente coma
        
        // Si no encontramos más comas, tomamos la subcadena desde `pos` hasta el final
        if (next_pos == std::string::npos) {
            rows.push_back(str.substr(pos)); // Agregar lo restante
            break; // Salir del ciclo
        }

        // Si encontramos una coma, agregamos la subcadena desde `pos` hasta `next_pos`
        rows.push_back(str.substr(pos, next_pos - pos));

        // Actualizamos `pos` para que apunte después de la coma
        pos = next_pos + 1;
    }

    return rows;
}





// Item rule treatment

Item::Item(Expression* _source, Expression* _target, Expression* _info) noexcept
{
        item = "( Latex diagram items -> " + _source->eval() + " connects to " + _target->eval() + " Info: " + _info->eval() + ")\n";
}

void Item::destroy() noexcept {}

std::string Item::eval() noexcept
{
    return item;
}


// ItemList rule treatment (Concatenate n number of rows)

ItemList::ItemList(Expression* old_item, Expression* new_item) noexcept
{
    items = old_item->eval() + new_item->eval();
}

void ItemList::destroy() noexcept {}

std::string ItemList::eval() noexcept
{
    return items;
}


// Diagram rule treatment

Diagram::Diagram(Expression* _items) noexcept
{
        diagram = "( Latex diagram ->\n" + _items->eval() + "\n)\n";
}

void Diagram::destroy() noexcept {}

std::string Diagram::eval() noexcept
{
    return diagram;
}


// LineBreak rule treatment

LineBreak::LineBreak(Expression* _linebreak) noexcept
{
        linebreak = "\\vspace{" + _linebreak->eval() + "cm}\n\n";
}

void LineBreak::destroy() noexcept {}

std::string LineBreak::eval() noexcept
{
    return linebreak;
}

// NewPage rule treatment

NewPage::NewPage() noexcept
{
        new_page = "\\newpage \n\n";
}

void NewPage::destroy() noexcept {}

std::string NewPage::eval() noexcept
{
    return new_page;
}

// Text rule treatment (Raw text and atomic expr for MarkEngine purpose)

Text::Text(std::string _text) noexcept
    : text{_text} {}

void Text::destroy() noexcept {}

std::string Text::eval() noexcept
{
    return text;
}


// Bold rule treatment (Raw bold text and atomic expr for MarkEngine purpose)

Bold::Bold(std::string _bold_text) noexcept
{
        bold_text = "\\textbf{" + _bold_text.substr(1, _bold_text.size() - 2) + "} ";
}


void Bold::destroy() noexcept {}

std::string Bold::eval() noexcept
{
    return bold_text;
}


// Italic rule treatment (Raw italic text and atomic expr for MarkEngine purpose)

Italic::Italic(std::string _italic_text) noexcept
{
        italic_text = "\\textit{" + _italic_text.substr(1, _italic_text.size() - 2) + "} ";
}


void Italic::destroy() noexcept {}

std::string Italic::eval() noexcept
{
    return italic_text;
}


// Underline rule treatment (Raw underline text and atomic expr for MarkEngine purpose)

Underline::Underline(std::string _underline_text) noexcept
{
        underline_text = "\\underline{" + _underline_text.substr(1, _underline_text.size() - 2) + "} ";
}


void Underline::destroy() noexcept {}

std::string Underline::eval() noexcept
{
    return underline_text;
}


// String rule treatment (Concatenate different types of text into one string)

String::String(Expression* old_text, Expression* new_text) noexcept
{
    str = old_text->eval() + new_text->eval();
}

void String::destroy() noexcept {}

std::string String::eval() noexcept
{
    return str;
}


// Expression List rule treatment (Concatenate different types of expression in one big text)

ExpressionList::ExpressionList(Expression* prev_expr, Expression* current_expr) noexcept
{
        concat_expr_list = prev_expr->eval() + current_expr->eval();
}

void ExpressionList::destroy() noexcept {}

std::string ExpressionList::eval() noexcept
{
    return concat_expr_list;
}
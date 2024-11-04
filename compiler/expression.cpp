#include <expression.hpp>

#include <string>


// Expression destructor
Expression::~Expression() {}


// Title rule treatment

Title::Title(Expression* _title, std::vector<std::string> &titles) noexcept
{
        title = "( Latex -> " + _title->eval() + " )\n";

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
        author = "( Latex -> " + _author->eval() + " )\n";
}

void Author::destroy() noexcept {}

std::string Author::eval() noexcept
{
    return author;
}


// Date rule treatment

Date::Date(Expression* _date) noexcept
{
        date = "( LatexDATE -> " + _date->eval() + " )\n";
}

void Date::destroy() noexcept {}

std::string Date::eval() noexcept
{
    return date;
}


// Subtitle rule treatment

Subtitle::Subtitle(Expression* _subtitle) noexcept
{
        subtitle = "( Latex -> " + _subtitle->eval() + " )\n";
}

void Subtitle::destroy() noexcept {}

std::string Subtitle::eval() noexcept
{
    return subtitle;
}


// Chapter rule treatment

Chapter::Chapter(Expression* _chapter) noexcept
{
        chapter = "( Latex -> " + _chapter->eval() + " )\n";
}

void Chapter::destroy() noexcept {}

std::string Chapter::eval() noexcept
{
    return chapter;
}


// Abstract rule treatment

Abstract::Abstract(Expression* _abstract) noexcept
{
        abstract = "( Latex -> " + _abstract->eval() + " )\n";
}

void Abstract::destroy() noexcept {}

std::string Abstract::eval() noexcept
{
    return abstract;
}


// Index rule treatment

Index::Index(std::vector<std::string> & titles) noexcept
{
        index = "( Latext ->\n";

        for (auto title : titles)
        {
            index = index + title + "\n";
        }

        index = index + ")\n";

}

void Index::destroy() noexcept {}

std::string Index::eval() noexcept
{
    return index;
}


// Paragraph rule treatment

Paragraph::Paragraph(Expression* _paragraph) noexcept
{
        paragraph = "( Latex -> " + _paragraph->eval() + " )\n";
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
        image = "( Latex img path -> " + _img_path + " )\n";
}


void Image::destroy() noexcept {}

std::string Image::eval() noexcept
{
    return image;
}


// Quote rule treatment

Quote::Quote(Expression* _quote, Expression* _author, Expression* _year) noexcept
{
        quote = "( Latex quote -> quote: " + _quote->eval() + " author: " + _author->eval() + " year: " + _year->eval() + " )\n";

}

void Quote::destroy() noexcept {}

std::string Quote::eval() noexcept
{
    return quote;
}


// Foot rule treatment

Foot::Foot(Expression* _foot) noexcept
{
        foot = "( Latex -> " + _foot->eval() + " )\n";
}

void Foot::destroy() noexcept {}

std::string Foot::eval() noexcept
{
    return foot;
}


// Row rule treatment

Row::Row(Expression* _row) noexcept
{
        row = "( Latex row values -> " + _row->eval() + " )\n";

        //values = this->get_values(_row->eval());
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
        table = "( Latex table ->\n" + _head->eval() + "\n" + _rows->eval() + "\n)\n";
        //columns = this->get_columns(_head->eval());
}

void Table::destroy() noexcept {}

std::string Table::eval() noexcept
{
    return table;
}

std::vector<std::string> Table::get_columns(std::string str) noexcept
{
    std::vector<std::string> columns;
    int pos = 0;
    while(pos < str.size()){
        pos = str.find(",");
        columns.push_back(str.substr(0,pos));
        str.erase(0,pos+1); 
    }
    return columns;
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
        linebreak = "( Latex -> " + _linebreak->eval() + " )\n";
}

void LineBreak::destroy() noexcept {}

std::string LineBreak::eval() noexcept
{
    return linebreak;
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
        bold_text = "BOLD " + _bold_text + " BOLD";
}


void Bold::destroy() noexcept {}

std::string Bold::eval() noexcept
{
    return bold_text;
}


// Italic rule treatment (Raw italic text and atomic expr for MarkEngine purpose)

Italic::Italic(std::string _italic_text) noexcept
{
        italic_text = "ITALIC " + _italic_text + " ITALIC";
}


void Italic::destroy() noexcept {}

std::string Italic::eval() noexcept
{
    return italic_text;
}


// Underline rule treatment (Raw underline text and atomic expr for MarkEngine purpose)

Underline::Underline(std::string _underline_text) noexcept
{
        underline_text = "UNDERLINE " + _underline_text + " UNDERLINE";
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

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
        author = "( Latexxxxx -> " + _author->eval() + " )\n";
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
        list = "( Latexxxxx -> " + _list->eval() + " )\n";

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

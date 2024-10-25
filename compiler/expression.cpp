#include <expression.hpp>

#include <string>


Expression::~Expression() {}



Title::Title(Expression* _title) noexcept
    : title{_title->eval()} {}

void Title::destroy() noexcept {}

std::string Title::eval() noexcept
{
    return title;
}


Text::Text(std::string text) noexcept
    : text{text} {}

void Text::destroy() noexcept {}

std::string Text::eval() noexcept
{
    return text;
}


String::String(Expression* old_text, Expression* new_text) noexcept
    : str{old_text->eval() + new_text->eval()} {}

void String::destroy() noexcept {}

std::string String::eval() noexcept
{
    return str;
}

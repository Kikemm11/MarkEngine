#pragma once

#include <string>

#include <vector>

// Expression definition

class Expression
{
public:
    virtual ~Expression();

    virtual void destroy() noexcept = 0;

    virtual std::string eval() noexcept = 0;

};

// Main Program definition

class Program : public Expression
{
public:
    Program(Expression* _program, std::vector<std::string> &titles) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string program;

};

// Title definition

class Title : public Expression
{
public:
    Title(Expression* _title, std::vector<std::string> &titles) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string title;
};

// Author definition

class Author : public Expression
{
public:
    Author(Expression* _author) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string author;
};

// Date definition

class Date : public Expression
{
public:
    Date(Expression* _date) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string date;
};

// Subtitle definition

class Subtitle : public Expression
{
public:
    Subtitle(Expression* _subtitle) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string subtitle;
};

// Chapter definition

class Chapter : public Expression
{
public:
    Chapter(Expression* _chapter) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string chapter;
};

// Abstract definition

class Abstract : public Expression
{
public:
    Abstract(Expression* _abstract) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string abstract;
};

// Index definition

class Index : public Expression
{
public:
    Index(std::vector<std::string> & titles) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string index;
};

// Paragraph definition

class Paragraph : public Expression
{
public:
    Paragraph(Expression* _paragraph) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string paragraph;
};

// List definition

class List : public Expression
{
public:
    List(Expression* _list) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

    std::vector<std::string> get_elements(std::string str) noexcept;

private:
    std::string list;
    std::vector<std::string> elements;
};

// Image definition

class Image : public Expression
{
public:
    Image(std::string _img_path) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string image;
};

// Quote definition

class Quote : public Expression
{
public:
    Quote(Expression* _quote, Expression* _author, Expression* _year) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string quote;
};


// Foot definition

class Foot : public Expression
{
public:
    Foot(Expression* _foot) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string foot;
};

// Row definition

class Row : public Expression
{
public:
    Row(Expression* _row) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

    std::vector<std::string> get_values(std::string str) noexcept;

private:
    std::string row;
    std::vector<std::string> values;
};

// RowList definition

class RowList: public Expression
{
public:
    RowList(Expression* old_row, Expression* new_row) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string rows;

};

// Table definition

class Table : public Expression
{
public:
    Table(Expression* _head, Expression* _rows) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

    std::vector<std::string> get_columns(std::string str) noexcept;

private:
    std::string table;
    std::vector<std::string> columns;
};

// Item definition

class Item : public Expression
{
public:
    Item(Expression* _source, Expression* _target, Expression* _info) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string item;
};

// ItemList definition

class ItemList: public Expression
{
public:
    ItemList(Expression* old_item, Expression* new_item) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string items;

};

// Diagram definition

class Diagram : public Expression
{
public:
    Diagram(Expression* _items) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string diagram;
};

// LineBreak definition

class LineBreak : public Expression
{
public:
    LineBreak(Expression* _linebreak) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string linebreak;
};

// NewPage definition

class NewPage : public Expression
{
public:
    NewPage() noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string new_page;
};

// Text definition

class Text : public Expression
{
public:
    Text(std::string _text) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string text;
};

// Bold definition

class Bold : public Expression
{
public:
    Bold (std::string _bold_text) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string bold_text;
};

// Italic definition

class Italic : public Expression
{
public:
    Italic (std::string _italic_text) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string italic_text;
};

// Underline definition

class Underline : public Expression
{
public:
    Underline (std::string _underline_text) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string underline_text;
};

// String definition

class String: public Expression
{
public:
    String(Expression* old_text, Expression* new_text) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string str;

};

// ExpresionList definition

class ExpressionList: public Expression
{
public:
    ExpressionList(Expression* prev_expr, Expression* current_expr) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string concat_expr_list;

};

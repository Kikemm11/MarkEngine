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


// Text definition

class Text : public Expression
{
public:
    Text(std::string text) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string text;
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

#pragma once

#include <string>


class Expression
{
public:
    virtual ~Expression();

    virtual void destroy() noexcept = 0;

    virtual std::string eval() noexcept = 0;

};

class Title : public Expression
{
public:
    Title(Expression* _title) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string title;
};


class Author : public Expression
{
public:
    Author(Expression* _author) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string author;
};


class Date : public Expression
{
public:
    Date(Expression* _date) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string date;
};


class Text : public Expression
{
public:
    Text(std::string text) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string text;
};


class String: public Expression
{
public:
    String(Expression* old_text, Expression* new_text) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string str;

};

class ExpressionList: public Expression
{
public:
    ExpressionList(Expression* prev_expr, Expression* current_expr) noexcept;

    void destroy() noexcept override;

    std::string eval() noexcept override;

private:
    std::string concat_expr_list;

};

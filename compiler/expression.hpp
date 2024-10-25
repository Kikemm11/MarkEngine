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

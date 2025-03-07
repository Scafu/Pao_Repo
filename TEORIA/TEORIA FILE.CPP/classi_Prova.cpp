#include "classi_Prova.h"
#include <iostream>
#include <ostream>
#include <string>

Article::Article(std::string title_in, std::string type_in, int year_in) : title(title_in), type(type_in), year(year_in), price(0)
{
    std::cout << "Costruito un articolo" << std::endl;
}

Article::~Article()
{
    std::cout << "Articolo distrutto" << std::endl;
}
int Article::getYear() const
{
    return year;
}
std::string Article::getType() const
{
    return type;
}

std::string Article::getTitle() const
{
    return title;
}

double Game::getPrice() const
{
    return price;
}

Game::Game(std::string title_in, std::string type_in, int year_in, std::string genre_in, std::string publisher_in) : Article(title_in, type_in, year_in), genre(genre_in), publisher(publisher_in)
{
    price = 40;
    std::cout << "Gioco costruito" << std::endl;
}

Game::~Game()
{
    std::cout << "Gioco distrutto" << std::endl;
}

std::string Game::getPublisher() const
{
    return publisher;
}
std::string Game::getGenre() const
{
    return genre;
}

Book::Book(std::string title_in, std::string type_in, int year_in, std::string publisher_in, std::string shop_in)
    : Article(title_in, type_in, year_in), publisher(publisher_in), shop(shop_in)
{
    price = 19;
    std::cout << "Libro costruito: " << title_in << std::endl;
}

Book::~Book()
{
    std::cout << "Libro distrutto: " << getTitle() << std::endl;
}

double Book::getPrice() const
{
    return price;
}

std::string Book::getPublisher() const
{
    return publisher;
}

std::string Book::getShop() const
{
    return shop;
}

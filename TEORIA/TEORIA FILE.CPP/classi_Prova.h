#include <string>



class Article {
    public:
        Article(std::string title_in, std::string type_in, int year_in);
        ~Article();
        virtual double getPrice() const = 0;
        std::string getTitle() const;
        std::string getType() const;
        int getYear() const;
        
    private:
        std::string title;
        std::string type;
        int year;
        
    protected:
        int price;
        

};


class Game: public Article{
    public:
        Game(std::string title_in, std::string type_in, int year_in, std::string genre_in, std::string publisher);
        ~Game();
        double getPrice() const override;
        std::string getPublisher() const;
        std::string getGenre() const;
    private:
        std::string genre;
        std::string publisher;

};

class Book: public Article{
    public:
        Book(std::string title_in, std::string type_in, int year_in, std::string publisher_in, std::string shop_in);
        ~Book();
        std::string getPublisher() const;
        std::string getShop() const;
        double getPrice() const override;

    private:
        std::string publisher;
        std::string shop;
};



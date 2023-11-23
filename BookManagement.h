#include "Data.h"
class BookManagement 
{
    private:
        Graphics g;
    public: 
        void addbook(Data&);
        void deleteBook(Data&);
        void showBook(Data&);
        void editPriceBook(Data&);
        void searchByAuthor(Data&);
        void showBookByCategory(Data&);

};

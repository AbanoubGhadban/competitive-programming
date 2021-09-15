#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <map>

using namespace std;

struct Book
{
    string title, author;
    int isBorrowed;
    int isReturned;
    
    inline bool operator< (const Book& other) const {
        if (author != other.author)
            return author < other.author;
        return title < other.title;
    }
};

struct cmp_str
{
   bool operator()(char const *a, char const *b) const
   {
      return std::strcmp(a, b) < 0;
   }
};

int main() {
    vector<Book> books;
    map<const char*, int, cmp_str> bookIndices;
    char line[200];

    while (1) {
        fgets (line, 200, stdin);
        if (strncmp (line, "END", 3) == 0)
            break;

        line[strlen(line) - 1] = 0; // remove new line at end of the string
        char* titlepos = strstr (line + 1, "\"");
        *titlepos = 0; // Add null termination after the title

        Book book = {
            line + 1, // Skip first quotation
            titlepos + 5, // Skip " by " after the book title
            0,
            0
        };
        books.push_back (book);
    }

    sort (books.begin(), books.end());
    for (size_t i = 0; i < books.size(); i++)
    {
        bookIndices[books[i].title.c_str()] = i;
    }
    
    while (1) {
        fgets (line, 200, stdin);

        if (strncmp (line, "END", 3) == 0)
            break;

        if (strncmp (line, "BORROW", 6) == 0) {
            line[strlen(line) - 2] = 0;
            int index = bookIndices[line + 8];
            books[index].isBorrowed = 1;
            books[index].isReturned = 0;
        } else if (strncmp (line, "RETURN", 6) == 0) {
            line[strlen(line) - 2] = 0;
            int index = bookIndices[line + 8];
            books[index].isBorrowed = 0;
            books[index].isReturned = 1;
        } else { // SHELVE Command
            int lastAvailable = -1;
            for (size_t i = 0; i < books.size(); i++)
            {
                if (books[i].isReturned) {
                    if (lastAvailable == -1)
                        printf("Put \"%s\" first\n", books[i].title.c_str());
                    else {
                        printf("Put \"%s\" after \"%s\"\n", books[i].title.c_str(), books[lastAvailable].title.c_str());
                    }
                    books[i].isReturned = 0;
                }

                if (!books[i].isBorrowed)
                    lastAvailable = i;
            }
            
            printf("END\n");
        }
    }

    return 0;
}

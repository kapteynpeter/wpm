#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define ASCII_BREAK 3
#define ASCII_SPACE 32
#define ASCII_NEWLINE 13
#define ASCII_BACKSPACE 8
#define ASCII_A 97
#define ASCII_Z 122

#define LINE_MAX_LEN 500
#define LEN_WORD_BANK 271

char *word_bank[LEN_WORD_BANK] =
{
    "was", "are", "have", "had", "were", "can", "said", "use", "will", "would",
    "make", "like", "has", "look", "write", "see", "could", "been", "call",
    "find", "did", "get", "come", "made", "may", "take", "know", "live",
    "give", "think", "say", "help", "tell", "follow", "came", "want", "show",
    "set", "put", "does", "must", "ask", "went", "read", "need", "move", "try",
    "change", "play", "spell", "found", "study", "learn", "should", "add",
    "keep", "start", "thought", "saw", "turn", "might", "close", "seem",
    "open", "begin", "got", "run", "walk", "began", "grow", "took", "carry",
    "hear", "stop", "miss", "eat", "watch", "let", "cut", "talk", "being", 
    "leave", "word", "time", "number", "way", "people", "water", "day", "part",
    "sound", "work", "place", "year", "back", "thing", "name", "sentence",
    "man", "line", "boy", "farm", "end", "men", "land", "home", "hand",
    "picture", "air", "animal", "house", "page", "letter", "point", "mother",
    "answer", "america", "world", "food", "country", "plant", "school",
    "father", "tree", "city", "earth", "eye", "head", "story", "example", 
    "life", "paper", "group", "children", "side", "feet", "car", "mile", 
    "night", "sea", "river", "state", "book", "idea", "face", "indian", "girl",
    "mountain", "list", "song", "family", "one", "all", "each", "other", "many",
    "some", "two", "more", "long", "new", "little", "most", "good", "great",
    "right", "mean", "old", "any", "same", "three", "small", "another", "large",
    "big", "even", "such", "different", "kind", "still", "high", "every", "own",
    "light", "left", "few", "next", "hard", "both", "important", "white", "four",
    "second", "enough", "above", "young", "not", "when", "there", "how", "out", 
    "then", "first", "now", "only", "very", "just", "where", "much", "before", 
    "too", "also", "around", "well", "here", "why", "again", "off", "away", 
    "near", "below", "last", "never", "always", "together", "often", "once", 
    "later", "far", "really", "almost", "sometimes", "soon", "for", "with", "from", 
    "about", "into", "down", "over", "after", "through", "between", "under", 
    "along", "until", "without", "you", "that", "his", "they", "this", "what", 
    "your", "which", "she", "their", "them", "these", "her", "him", "who", 
    "its", "our", "something", "those", "and", "but", "than", "because", "while"
};

typedef struct letter_s 
{
    unsigned short letter;
    unsigned short color;
} letter_t;

int get_chunk_of_random_words(int num_words, char ** word_bank, char * outbuff)
{
    int chars_written = 0;
    srand(time(NULL));
    // todo maybe make this safer by checking that you're not overflowing the buffer outbuff
    for (int i = 0; i < num_words; i++)
    {
        int j = rand() % LEN_WORD_BANK - 1;
        char * rand_str = word_bank[j];
        chars_written += snprintf(outbuff + chars_written, strlen(rand_str) + 2, "%s ", rand_str);
    }
    memset(outbuff + strlen(outbuff) - 1, 0x00, 1);
}

int getch_noblock() {
    if (_kbhit())
        return _getch();
    else
        return -1;
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int write_char(char c, int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%c", c);
}

int write_lines(char * line) {
    COORD pos;
    pos.X = 10;
    pos.Y = 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", line);
}

void clrscr() {
    printf("\e[1;1H\e[2J");
}

char * test_str_1 = "hello moto nice to meet you";
char * test_str_2 = "fart time hello moto now go";

int main() {
    // printf("hello, world");

    // start a timer
    // while timer is not timed out
    bool quit = false;
    int pos_x = 0;
    int pos_y = 0;

    char line[LINE_MAX_LEN] = {0};

    get_chunk_of_random_words(3, word_bank, line);
    printf("%s", line);

    char * master_string = "hello moto nice to meet you";
    // write_lines(master_string);
    // printf("%s", master_string);

    hidecursor();

    while(!quit) 
    {
        int keypress = _getch();
        // printf("%u\n", keypress);

        if (keypress == ASCII_BREAK)
        {
            quit = true;
        }

        else if (keypress == ASCII_NEWLINE)
        {

        }

        else if (keypress == ASCII_BACKSPACE)
        {

        }

        else if (master_string[pos_x] == ASCII_NEWLINE)
        {

        }

        else if (master_string[pos_x] == ASCII_SPACE)
        {

        }
        else if ((master_string[pos_x] >= ASCII_A) && (master_string[pos_x] <= ASCII_Z))
        {
            printf("here");
            if (keypress == ASCII_SPACE)
            {
                // logic to jump to the next word
                while (1) {
                    if (master_string[pos_x] == ASCII_SPACE) 
                    {
                        pos_x++;
                        // append the letter to recorded letter buffer in yellow
                        break;
                    }
                    else if (master_string[pos_x] == ASCII_NEWLINE)
                    {
                        pos_x = 0;
                        if (pos_y == 0)
                        {
                            pos_y++;
                        }
                        else
                        {
                            clrscr();
                            // display the timer
                            // line1 = recorded colors
                            // line2 = line3
                            // line3 = get random chunk of words
                            // display the new lines
                        }
                        // recorded letter buffer = empty
                        // master string = line2
                        // set the cursor to the new position maybe
                    }
                    else
                    {
                        // if the letter is wrong, write it in red
                        // write char in red
                        // append the letter to the recorded letters buffer in red
                        pos_x++;
                    }
                }

            } 
            else
            {
                if (keypress == master_string[pos_x])
                {
                    // append the letter to the recorded letters buffer in yello
                } 
                else
                {
                    // append the letter to the recorded letter buffer in red
                }
                write_char(keypress, 15, 5);
                pos_x++;
            }
        }
        printf("%u ASCII_A ASCII_Z\n", master_string[pos_x]);

    }
    return 0;
}
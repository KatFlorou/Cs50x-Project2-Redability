#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);



int main(int argc, string argv[])
{
    //Prompt user for text
    string text = get_string("Text: ");
    //printf("%s\n", text);

    //Print the number of letters
    float letters = count_letters(text);
    //printf("%f letters\n", letters);

    //Print the number of words
    float words = count_words(text);
    //printf("%f words\n", words);

    //Print the number of sentences
    float sentences = count_sentences(text);
    //printf("%f sentences\n", sentences);

    //Function that calculates reading level
    float L = letters / words * 100;
    float S = sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if ((int) round(index) < 16 && (int) round(index) > 0)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if ((int) round(index) <= 0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

//Function that counts the number of letters in the text
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }
    return letters;
}


//Function that counts the number of words in the text
int count_words(string text)
{
    int space = 0;
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            space++;
        }
    }
    words = space + 1;
    return words;
}


//Function that counts the number of sentences in the text
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}

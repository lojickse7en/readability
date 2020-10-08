#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //asks to input text
    string t = get_string("Text: ");

    int count_letters, count_words, count_sentences;

    //initialize each of following to zero
    count_letters = 0;
    count_words = 0 + 1;
    count_sentences = 0;

    // iterate through the imputed string. Storing the length in a variable instead of calling strlen over and over {  for (int i = 0; i < strlen(t); i++) }. That way we can use strlen in other loops and avoid confusion
    //for (int i = 0, len = strlen(t); i < len; i++)

    //for loop to interate through string
    for (int i = 0 ; i < strlen(t); i++)
    {
        //if condition to ensure the array looks for a capital or lower case letter 
        if ((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z'))

        {
            //iterate to the next caracter if above is true
            count_letters++;
        }
        else if (t[i] == ' ')
        {
            count_words++;
        }
        else if (t[i] == '!' || t[i] == '.' || t[i] == '?')
        {
            count_sentences++;
        }

    }

    printf("\n%i Letter(s) \n%i Word(s) \n%i Sentence(s) \n", count_letters, count_words, count_sentences);
    
    //implement the coleman-liau index and print the appropiat grade level of the text
    float L = 100 * ((float)count_letters / (float)count_words);
    float S = 100 * ((float)count_sentences / (float)count_words);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (grade < 16 && grade >= 0)
    {
        printf("\nGrade %i\n", grade);
    }
    else if (grade >= 16)
    {
        printf("\nGrade 16+\n");
    }
    else
    {
        printf("\nBefore Grade 1\n");
    }
}
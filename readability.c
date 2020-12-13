#include <stdio.h>
#include <cs50.h>
#include <math.h>

int count_words(char str[]);
int count_letters(char str[]);
int count_sentances(char str[]);
float colemanLiau(int words, int let, int sent);

int main(void)
{
    int index = 0;
    string name = get_string("Text: ");
    
    // get the words, letters, and sentances
    int words = count_words(name);
    int letters = count_letters(name);
    int sent = count_sentances(name);
    
    // pass through coleman Liau index to get grade back
    float grade = colemanLiau(words, letters, sent);
    
    // printf the grade
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %.0f\n", roundf(grade));
    }
}

// count the number of words in given string
int count_words(char str[])
{
    int count = 1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            count++;
        }
    }
    return count;
}

// retrun number of letters in string 
int count_letters(char str[])
{
    int letters = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <='z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            letters++;
        }
    }
    return letters;
}

// return number of sentances in string
int count_sentances(char str[])
{
    int sentances = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] == '.' || str[i] == '?') || (str[i] == '!'))
        {
            sentances++;
        }
    }
    return sentances;
}

// calculate coleman Liau index to get grade 
float colemanLiau(int words, int let, int sent)
{
    float grade = 0.0588 * (100 * (float) let / words) - 0.296 * (100 * (float) sent / words) - 15.8;
    return grade;
}
# This programm count grade level of some text based on Coleman-Liau formula
from cs50 import get_string
# Ask user to input some text
text = get_string("Text: ").upper()


# Function for count letters in text
def count_letters(text):
    x = 0
    for i in text:
        if i != '\0' and i >= 'A' and i <= 'Z':
            x += 1
    return x


# Function for count words in text
def count_words(text):
    y = 1
    for i in text:
        if i == ' ':
            y += 1
    return y


# Function for count sentences in text
def count_sentences(text):
    z = 0
    for i in text:
        if i == '.' or i == '!' or i == '?':
            z += 1
    return z


# Call the functions and set retuning value to variables
var_count_letters = count_letters(text)
var_count_words = count_words(text)
var_count_sentences = count_sentences(text)


# This function compute grade of some text
def index_count(var_count_letters, var_count_words, var_count_sentences):
    l = (var_count_letters / var_count_words) * 100
    s = (var_count_sentences / var_count_words) * 100
    index = round((0.0588 * l) - (0.296 * s) - 15.8)
    return index


# Call the index_count function
var_index = index_count(var_count_letters, var_count_words, var_count_sentences)
# Print out results
if var_index < 1:
    print("Before Grade 1")
elif var_index >= 1 and var_index <= 16:
    print(f"Grade {var_index}")
elif var_index > 16:
    print("Grade 16+")
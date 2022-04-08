from cs50 import get_int
# Ask user for input if input less than 0 or more than 8 repet ask
while True:
    input = get_int("Input height of pyramid: ")
    # Check if input between 1 and 8
    if input >= 1 and input <= 8:
        break
# Doing loop and draw stairs
for i in range(1, input + 1):
    print(" " * (input - i) + "#" * i)
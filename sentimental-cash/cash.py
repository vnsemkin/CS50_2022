from cs50 import get_float

while True:
    cents = get_float("Change owed: ")
    # Check if input more than 0
    if cents > 0:
        break


# Count numbers of quaters
def calculate_quaters(cents):
    if cents >= 0.25:
        quaters = cents / 0.25
    else:
        quaters = 0
    return int(quaters)


# Count number of dimes
def calculate_dimes(cents):
    if cents >= 0.10:
        dimes = cents / 0.10
    else:
        dimes = 0
    return int(dimes)


# Count number of nickels
def calculate_nickels(cents):
    if cents >= 0.05:
        nickels = cents / 0.05
    else:
        nickels = 0
    return int(nickels)


# Count number of pennies
def calculate_pennies(cents):
    if cents >= 0.01:
        pennies = cents / 0.01
    else:
        pennies = 0
    return int(pennies)


# Call function and assing return to quaters variable
quaters = calculate_quaters(cents)
cents = round((cents - quaters * 0.25), 2)
# Call function and assing return to dimes variable
dimes = calculate_dimes(cents)
cents = round((cents - dimes * 0.10), 2)
# Call function and assing return to nickels variable
nickels = calculate_nickels(cents)
cents = round((cents - nickels * 0.05), 2)
# Call function and assing return to pennies variable
pennies = calculate_pennies(cents)
# Print result
print(quaters + dimes + nickels + pennies)


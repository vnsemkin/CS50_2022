from csv import DictReader
import sys


def main():
    # TODO: Check for command-line usage
    # Checking command-line usage if wrong exit with print notification
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py FILENAME FILENAME")
    # TODO: Read database file into a variable
    # Read file cvs from command - line
    with open(sys.argv[1], "r") as file:
        # Creating object reader where reader.fieldsname first row
        reader = DictReader(file)
        # Create new dict for persons that stores for each
        # person first row as a key second as a value
        dict_list = list(reader)
    # TODO: Read DNA sequence file into a variable
    # Read file and save it the list sequence
    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # Find longest match, open new list
    count = []
    # Itterate from 1 to how many person we have
    for i in range(1, len(reader.fieldnames)):
        # Take first element from dictionary then second and so on
        strs = reader.fieldnames[i]
        # Set list to 0
        count.append(0)
        # Iterate through sequence list start from 0 to lenght of sequence
        for j in range(len(sequence)):
            # Initilize variable counter to count matches
            counter = 0
            # Find first match slicing sequence with lenght of STR
            if sequence[j:(j + len(strs))] == strs:
                # If found first match initilize new variable to move through list of STR
                # step is lenght of STR
                lenght = 0
                # After first match itterate through STR list with step of STR's lenght
                while sequence[(j + lenght):(j + lenght + len(strs))] == strs:
                    # If match count matches plus 1
                    counter += 1
                    # Shift to lenght of STR
                    lenght += len(strs)
            # Compare counter of STR's match with list
            if counter > count[i - 1]:
                # Set list equals variable
                count[i - 1] = counter
    # TODO: Check database for matching profiles
    # Iterate though dictionary lenght
    for i in range(len(dict_list)):
        # Initilize variable to count matces
        match = 0
        # Iterate though number of person(Start from 1 as 0 is person name)
        for j in range(1, len(reader.fieldnames)):
            # Try to find match of number of matching STR some person and list of STR
            if int(count[j - 1]) == int(dict_list[i][reader.fieldnames[j]]):
                # When mactch count plus 1
                match += 1
                # Final conclution if count equals to person STR's lenght
            if match == (len(reader.fieldnames) - 1):
                print(dict_list[i]['name'])
                exit(0)
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

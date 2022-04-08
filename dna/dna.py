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
    for i in range(len(reader.fieldnames) - 1):
        strs = reader.fieldnames[i + 1]
        # Call function to find longest run
        run = longest_match(sequence, strs)
        # Write result to list
        count.append(run)
    # TODO: Check database for matching profiles
    # Iterate though dictionary lenght
    for i in range(len(dict_list)):
        # Initilize variable to count matces
        match = 0
        # Iterate though number of person(Start from 1 as 0 is person name)
        for j in range(len(reader.fieldnames) - 1):
            # Try to find match of number of matching STR some person and list of STR
            if int(count[j]) == int(dict_list[i][reader.fieldnames[j + 1]]):
                # When mactch count plus 1
                match += 1
                # Final conclution if count equals to person STR's lenght
            if match == (len(reader.fieldnames) - 1):
                print(dict_list[i]['name'])
                exit(0)
    print("No match")


def longest_match(sequence, strs):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(strs)
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
            if sequence[start:end] == strs:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
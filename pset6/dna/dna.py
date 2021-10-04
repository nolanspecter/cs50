import sys
import csv


def main():
    # Check for number of arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # Init list of STRs and ppl in the database
    profiles = []
    STRs = []

    # Read database into memory
    with open(sys.argv[1], "r") as database:
        dict_read = csv.DictReader(database)
        STRs = dict_read.fieldnames[1:]
        for row in dict_read:
            profiles.append(row)

    STR_count = dict.fromkeys(STRs, 0)

    # Read test sequence into memory
    with open(sys.argv[2], "r") as text:
        line = text.readline()

        # Count numer of max repitition for each STR
        for STR in STRs:
            STR_count[STR] = count(line, STR)

    for profile in profiles:
        match = 0

        # Check number of matching STRs
        for STR in STRs:
            if int(profile[STR]) == STR_count[STR]:
                match += 1

        if match == len(STRs):
            print(profile['name'])
            exit(0)
    print("No match")
    exit(1)


def count(sequence, STR):
    length = len(STR)
    max_rep = 0

    for i in range(len(sequence)):
        rep_count = 0

        # Start count if match
        if sequence[i: i + length] == STR:
            rep_count += 1
            # Keep looking for consecutive match
            while sequence[i: i + length] == sequence[i + length: i + 2 * length]:
                rep_count += 1
                # Shift i manually to next STR
                i += length

        if rep_count > max_rep:
            max_rep = rep_count

    return max_rep


main()

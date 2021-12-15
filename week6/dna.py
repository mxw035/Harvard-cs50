# imports from both libraries csv and sys the argv, exit, reader, and Dictreader fxns
from csv import reader, DictReader
from sys import argv, exit

# defines main fxn


def main():
    # check the cla length and if not correct prints error message for user
    if len(argv) != 3:
        print("Usage: python dna.py, databases/csv sequences/txt")
        exit(1)
    # assigns/ names the argv[1] and argv[2] files
    db_path = argv[1]
    seq_path = argv[2]
    # opens db_path to reade and creates a list called dict_list out of info when every row will have its own section
    with open(db_path, "r") as csvfile:
        reader = DictReader(csvfile)
        dict_list = list(reader)
    # oepns the seq_path to read and looks at the string in var sequence created by read fxn
    with open(seq_path, "r") as file:
        sequence = file.read()
    # creats a empty list called max_counts
    max_counts = []
    # makes a for loop that looks through the reader file starting on 1
    for i in range(1, len(reader.fieldnames)):
        # creates var STR set to reader of i means it roates through the file adding to STR each itteration
        STR = reader.fieldnames[i]
        # adds to the max count list
        max_counts.append(0)
        # creates a for loop looking through the len of sequnece
        for j in range(len(sequence)):
            # creates var STR_count and sets it to 0
            STR_count = 0
            # checks for the max STR
            if sequence[j:(j + len(STR))] == STR:
                k = 0
                while sequence[(j + k):(j + k + len(STR))] == STR:
                    STR_count += 1
                    k += len(STR)
                # sets new max
                if STR_count > max_counts[i - 1]:
                    max_counts[i - 1] = STR_count
    # for loop looking for matches
    for i in range(len(dict_list)):
        matches = 0
        for j in range(1, len(reader.fieldnames)):
            if int(max_counts[j - 1]) == int(dict_list[i][reader.fieldnames[j]]):
                matches += 1
            if matches == (len(reader.fieldnames) - 1):
                print(dict_list[i]['name'])
                exit(0)


main()

print("No Match")

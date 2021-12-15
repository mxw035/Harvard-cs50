# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []  # create the list
    file = sys.argv[1]  # creates the file name pointer
    # TODO: Read teams into memory from file
    with open(file) as csvf:  # opens file as csvf
        reader = csv.DictReader(csvf)  # usings dictreader to read trough csv file one at a time treating it like dict
        for row in reader:  # sets a loop for each row in reader
            team = row  # team  = row
            team["rating"] = int(team["rating"])  # changes team rating to int so it can be used for stats
            teams.append(team)  # changes the team list at the team location
    # print(teams)

    counts = {}  # creates an empty dict called coutns
    # TODO: Simulate N tournaments and keep track of win counts
    for simulation in range(N):  # creates a simulation loop in range of n or 1000
        winner = simulate_tournament(teams)  # sets winner to the simulated tournament teams return
        if winner in counts:  # if that winner is in counts add 1 to score
            counts[winner] = counts[winner] + 1
        else:
            counts[winner] = 1  # if not create that winner eqaul to a count of 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):  # defines a fucntion called simulate tournaments with the input of teams list
    """Simulate a tournament. Return name of winning team."""  # kind of like a comment but helps with documentation incase of errors
    # TODO
    rounds = len(teams)  # sets rounds equal to the length of the teams
    if rounds >= 2:  # if more than 2 teams or two rounds
        teams = simulate_round(teams)  # set teams equal to the simulate round fxn return with input of teamd
        return simulate_tournament(teams)  # return the output of simulated tournament with input of teams
    else:  # else if rounds less than 2 then the winner is set to the first team in teams list
        winner = teams[0]["team"]
        return winner  # returns the winner name to main fxn


if __name__ == "__main__":
    main()

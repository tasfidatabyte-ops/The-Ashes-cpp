#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

/* Global scores for current batting pair */
int strikerScore = 0;
int nonStrikerScore = 0;

/* Display match header and team players */
void head(string australia[], string england[])
{
    cout << "-------------------------------------------\n";
    cout << "---------- The Ashes ----------------------\n";
    cout << "                3rd Test\n";
    cout << "         Australia vs England\n";
    cout << "-------------------------------------------\n";
    cout << "We are live at Lords, London\n";
    cout << "-------------------------------------------\n";

    cout << "| Australia           |      | England      |\n";
    cout << "-------------------------------------------\n";

    for (int i = 0; i < 11; i++)
    {
        cout << "| " << setw(18) << left << australia[i]
             << "|      | " << setw(14) << england[i] << "|\n";
        cout << "-------------------------------------------\n";
    }
}

/* First delivery of the innings */
void firstBall(int &inputRun, string striker,
               int &currentRun, int &balls,
               string &currentBatter, string bowler)
{
    cout << "\nBowler " << bowler << " to " << striker << ": ";
    cin >> inputRun;

    while (inputRun < 0 || inputRun > 6 || inputRun == 5)
    {
        cout << "Invalid run! Enter 0,1,2,3,4 or 6: ";
        cin >> inputRun;
    }

    currentBatter = striker;
    currentRun = inputRun;
}

/* Print dismissal commentary */
void outMessage(int batterScore, string batter, string bowler)
{
    cout << "\nOUT! " << batter << " is dismissed by " << bowler << endl;
    cout << "Final score: " << batterScore << endl;
}

/* Main batting simulation */
int playBatting(int compRuns[], string bowler,
                string batter1, string batter2,
                int ausScores[], int engScores[],
                int batterIndex, int &teamScore)
{
    int run = 0, run1 = 0, run2 = 0;
    int balls = 0, overs = 0;
    string currentBatter = "";
    bool striker = true;   // batter1 starts on strike

    firstBall(run1, batter1, run, balls, currentBatter, bowler);
    balls = 1;

    while (true)
    {
        int randomIndex = rand() % 5;
        int computerRun = compRuns[randomIndex];

        /* OUT condition */
        if (run == computerRun)
        {
            if (currentBatter == batter1)
            {
                outMessage(strikerScore, batter1, bowler);
                ausScores[batterIndex] = strikerScore;
                strikerScore = 0;
                return 1; // striker out
            }
            else
            {
                outMessage(nonStrikerScore, batter2, bowler);
                ausScores[batterIndex + 1] = nonStrikerScore;
                nonStrikerScore = 0;
                return 2; // non-striker out
            }
        }
        else
        {
            if (striker)
                strikerScore += run;
            else
                nonStrikerScore += run;

            teamScore += run;

            cout << "Score: "
                 << batter1 << " (" << strikerScore << ") | "
                 << batter2 << " (" << nonStrikerScore << ") | "
                 << "Team: " << teamScore << endl;
        }

        /* End of over */
        if (balls == 6)
        {
            overs++;
            balls = 0;
            striker = !striker; // change strike
        }

        /* Decide next batter */
        if (run % 2 != 0)
            striker = !striker;

        if (striker)
        {
            cout << "\n" << batter1 << " on strike: ";
            cin >> run1;
            while (run1 < 0 || run1 > 6 || run1 == 5)
            {
                cout << "Invalid run! Enter 0,1,2,3,4 or 6: ";
                cin >> run1;
            }
            currentBatter = batter1;
            run = run1;
        }
        else
        {
            cout << "\n" << batter2 << " on strike: ";
            cin >> run2;
            while (run2 < 0 || run2 > 6 || run2 == 5)
            {
                cout << "Invalid run! Enter 0,1,2,3,4 or 6: ";
                cin >> run2;
            }
            currentBatter = batter2;
            run = run2;
        }

        balls++;
    }
}

/* Handle batting order and wickets */
void selection(string australia[], string england[],
               int compRuns[], int ausScores[], int engScores[])
{
    int batter1Index = 0;
    int batter2Index = 1;
    int nextBatterIndex = 2;
    int bowlerIndex = 8;
    int teamScore = 0;

    string batter1 = australia[batter1Index];
    string batter2 = australia[batter2Index];

    cout << "\nOpening batsmen: " << batter1 << " & " << batter2 << endl;

    int outType = playBatting(compRuns, england[bowlerIndex],
                              batter1, batter2,
                              ausScores, engScores,
                              batter1Index, teamScore);

    bowlerIndex++;

    while (nextBatterIndex < 11)
    {
        if (outType == 1)
        {
            batter1 = australia[nextBatterIndex++];
            batter1Index = nextBatterIndex - 1;
        }
        else
        {
            batter2 = australia[nextBatterIndex++];
            batter2Index = nextBatterIndex - 1;
        }

        if (bowlerIndex > 10)
            bowlerIndex = 8;

        outType = playBatting(compRuns, england[bowlerIndex],
                              batter1, batter2,
                              ausScores, engScores,
                              batter1Index, teamScore);

        bowlerIndex++;
    }

    cout << "\nInnings complete. Final Score: " << teamScore << endl;
}

/* Main function */
int main()
{
    srand(time(0));

    string australia[11] = {
        "David Warner", "Usman Khawaja", "Ricky Ponting", "Travis Head",
        "Steve Smith", "Marnus Labuschagne", "Mitchell Marsh",
        "Alex Carey", "Mitchell Starc", "Pat Cummins", "Josh Hazlewood"};

    string england[11] = {
        "Jason Roy", "Ben Duckett", "Harry Brook", "Joe Root",
        "Zak Crawley", "Ben Stokes", "Jonny Bairstow",
        "Moeen Ali", "Stuart Broad", "James Anderson", "Jofra Archer"};

    int ausScores[11]{};
    int engScores[11]{};
    int compRuns[5] = {1, 2, 3, 4, 6};

    head(australia, england);
    selection(australia, england, compRuns, ausScores, engScores);

    int total = 0;
    for (int s : ausScores)
        total += s;

    cout << "\nAustralia 1st Innings Total: " << total << endl;
    return 0;
}

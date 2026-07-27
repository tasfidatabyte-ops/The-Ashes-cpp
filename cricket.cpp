#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int score1{0}, score2{0}, total_out{0}, eng_out{0}, aus_out{0};

void runCommentary(int run, string batter)
{
    cout << "\033[36m"; // Cyan color for commentary
    switch (run)
    {
    case 0:
        cout << batter << " defends the ball carefully. No run taken.\n";
        break;
    case 1:
        cout << batter << " takes a quick single. Smart running between the wickets!\n";
        break;
    case 2:
        cout << batter << " pushes it to the gap and runs two. Excellent placement!\n";
        break;
    case 3:
        cout << batter << " sprints for three! Great awareness and energy.\n";
        break;
    case 4:
        cout << batter << " hits a glorious cover drive for four! Absolutely exquisite shot.\n";
        break;
    case 6:
        cout << batter << " smashes a huge six! What a massive strike!\n";
        break;
    default:
        cout << batter << " does something unusual. Interesting shot!\n";
        break;
    }
    cout << "\033[0m"; // Reset color
}

void displayTeamScore(int playerScores[], string teamName, int numPlayers, string playerNames[])
{
    int totalScore = 0;
    cout << "\033 [31m";
    cout << "\n----- Scorecard: " << teamName << " -----\n";
    cout << left << setw(20) << "Player Name" << "Score\n";
    cout << "-----------------------------\n";

    for (int i = 0; i < numPlayers; i++)
    {
        cout << left << setw(20) << playerNames[i] << playerScores[i] << endl;
        totalScore += playerScores[i];
    }
    cout << "-----------------------------\n";
    cout << left << setw(20) << "Total Team Score:" << totalScore << "\n";
    cout << "-----------------------------\n";
}

void head(string ausses[], string lions[]) // For displaying the player and statments
{
    cout << "-------------------------------------------" << endl;
    cout << "----------\033[34m-----The   Ashes-----------------" << endl;
    cout << "\033[31m                3rd Test" << endl;
    cout << "         Australia vs Engalnd" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "\033[32mWe are live here in Lords London The home of Cricket" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "\033[31m--------------------------------------------" << endl;
    cout << setw(10) << left << "| Australia         |      | England       |" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < 11; i++)
    {
        cout << "\033[34m| " << setw(18) << ausses[i] << "|      | " << setw(14) << lions[i] << "| " << endl;
        cout << "--------------------------------------------" << endl;
    }
    cout << "\033[33m" << endl;
}

void first(int &run1, string batter1, int &run, int &balls, string &batter, string bolwer)
{
    cout << "--------------------------------------------------------" << endl;
    cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
    cin >> run1;
    cout << "--------------------------------------------------------" << endl;
    batter = batter1;
    cout << left << setw(20) << batter << " played..." << endl;
    cout << "-----------------------------------------" << endl;
    run = run1;
}

void out(int score, string batter, string bolwer)
{
    cout << "------------------------------------------------------" << endl;
    cout << " Out " << endl;
    if (score == 0)
    {
        cout << batter << " goes on duck" << endl;
        cout << "There is little change in pace.." << endl;
        cout << "Slower one worked for " << bolwer << " not for " << batter << endl;
    }
    else if (score == 100)
    {
        cout << "A good hands of hundered by " << batter << " on fisrt day of ashes live here in Lords" << endl;
    }
    else if (score > 90 && score <= 99)
        cout << "This will be good innings in the history of ashes but.... luck was not with " << batter << endl;
    else if (score >= 51 && score <= 90)
        cout << "A good knock by hands of " << batter << endl;
    else if (score == 50)
        cout << "Another destructive fifty by " << batter << endl;
    else if (score >= 16 && score <= 49)
        cout << "Luck was not with " << batter << endl;
    else
        cout << "huge embarrasment by " << batter << endl;
    cout << "Total score by " << batter << " is: " << score << endl;
    cout << "------------------------------------------------------" << endl;
}

int main2(int comp[], string bolwer, string batter1, string batter2, int aus_score[], int eng_score[], int bat1, int bat2, int &score)
{
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(28) << left << batter1 << " is on striker end |" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|" << setw(24) << left << batter2 << " is on non striker end |" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|" << setw(28) << left << bolwer << " is on pace attack |" << endl;
    cout << "-------------------------------------------------" << endl
         << endl;
    cout << "\033[33m" << endl;
    int run{0}, run1{0}, run2{0}, comp_b{0}, temp, balls{0}, overs{0};
    string batter = "";
    bool strike = true;
    first(run1, batter1, run, balls, batter, bolwer); // For fisrt delivery
    balls = 1;
    while (true)
    {
        temp = rand() % 5;   // for taking index
        comp_b = comp[temp]; // for geting value form array
        if (run == comp_b)
        {
            total_out++;
            if (batter == batter1)
            {
                out(score1, batter1, bolwer);
                eng_score[bat1] = score1;
                return 1; // batter1 out
            }
            else
            {
                out(score2, batter2, bolwer);
                eng_score[bat2] = score2;
                return 2; // batter2 out
            }
        }
        else
        {
            if (strike)
                score1 += run;
            else
                score2 += run;
            score += run;
            cout << "\033[32m Score Update: " << batter1 << " (" << score1 << ")  |  " << batter2 << " (" << score2 << ")  |  " << "Team: " << score << "  |Out: " << total_out << " |" << endl;
            runCommentary(run, batter);
        }

        if (balls == 6)
        {
            overs++;
            cout << overs << endl;
            balls = 0;
            if (strike == true)
            {
                cout << "--------------------------------------------------------" << endl;
                cout << left << setw(20) << batter2 << " is on strike" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                cin >> run2;
                cout << "--------------------------------------------------------" << endl;
                batter = batter2;
                cout << left << setw(20) << batter << " played..." << endl;
                cout << "-----------------------------------------" << endl;
                run = run2;
                strike = false;
            }
            else if (strike == false)
            {
                cout << "--------------------------------------------------------" << endl;
                cout << left << setw(20) << batter1 << " is on strike" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                cin >> run1;
                cout << "--------------------------------------------------------" << endl;
                batter = batter1;
                cout << left << setw(20) << batter << " played..." << endl;
                cout << "-----------------------------------------" << endl;
                cout << endl;
                run = run1;
                strike = true;
            }
            strike = !strike;
        }
        else
        {
            if (run % 2 != 0)
            {
                if (strike == true)
                {
                    cout << "--------------------------------------------------------" << endl;
                    cout << left << setw(20) << batter2 << " is on strike" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                    cin >> run2;
                    cout << "--------------------------------------------------------" << endl;
                    batter = batter2;
                    cout << left << setw(20) << batter << " played..." << endl;
                    cout << "-----------------------------------------" << endl;
                    run = run2;
                    strike = false;
                }
                else if (strike == false)
                {
                    cout << "--------------------------------------------------------" << endl;
                    cout << left << setw(20) << batter1 << " is on strike" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                    cin >> run1;
                    cout << "--------------------------------------------------------" << endl;
                    batter = batter1;
                    cout << left << setw(20) << batter << " played..." << endl;
                    cout << "-----------------------------------------" << endl;
                    run = run1;
                    strike = true;
                }
            }
            else
            {
                if (strike == true)
                {
                    cout << "--------------------------------------------------------" << endl;
                    cout << left << setw(20) << batter1 << " is on strike" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                    cin >> run1;
                    cout << "--------------------------------------------------------" << endl;
                    batter = batter1;
                    cout << left << setw(20) << batter << " played..." << endl;
                    cout << "-----------------------------------------" << endl;
                    run = run1;
                    strike = true;
                }
                else if (strike == false)
                {
                    cout << "--------------------------------------------------------" << endl;
                    cout << left << setw(20) << batter2 << " is on strike" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                    cin >> run2;
                    cout << "--------------------------------------------------------" << endl;
                    batter = batter2;
                    cout << left << setw(20) << batter << " played..." << endl;
                    cout << "-----------------------------------------" << endl;
                    run = run2;
                    strike = false;
                }
            }
        }
        balls++;
    }
    return 0;
}

int main1(int comp[], string bolwer, string batter1, string batter2, int aus_score[], int eng_score[], int bat1, int bat2, int &score)
{
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(28) << left << batter1 << " is on striker end |" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|" << setw(24) << left << batter2 << " is on non striker end |" << endl;
    cout << "|-----------------------------------------------|" << endl;
    cout << "|" << setw(28) << left << bolwer << " is on pace attack |" << endl;
    cout << "-------------------------------------------------" << endl
         << endl;
    cout << "\033[33m" << endl;
    int run{0}, run1{0}, run2{0}, comp_b{0}, temp, balls{0}, overs{0};
    string batter = "";
    bool strike = true;
    first(run1, batter1, run, balls, batter, bolwer); // For fisrt delivery
    balls = 1;
    while (true)
    {
        temp = rand() % 5;   // for taking index
        comp_b = comp[temp]; // for geting value form array
        if (run == comp_b)
        {
            total_out++;
            if (batter == batter1)
            {
                out(score1, batter1, bolwer);
                aus_score[bat1] = score1;
                return 1; // batter1 out
            }
            else
            {
                out(score2, batter2, bolwer);
                aus_score[bat2] = score2;
                return 2; // batter2 out
            }
        }
        else
        {
            if (strike)
                score1 += run;
            else
                score2 += run;
            score += run;
            cout << "\033[32m Score Update: " << batter1 << " (" << score1 << ")  |  " << batter2 << " (" << score2 << ")  |  " << "Team: " << score << "  |Out: " << total_out << " |" << endl;
            runCommentary(run,batter);
        }

        if (balls == 6)
        {
            overs++;
            cout << overs << endl;
            balls = 0;
            if (strike == true)
            {
                cout << "--------------------------------------------------------" << endl;
                cout << left << setw(20) << batter2 << " is on strike" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                cin >> run2;
                cout << "--------------------------------------------------------" << endl;
                batter = batter2;
                cout << left << setw(20) << batter << " played..." << endl;
                cout << "-----------------------------------------" << endl;
                run = run2;
                strike = false;
            }
            else if (strike == false)
            {
                cout << "--------------------------------------------------------" << endl;
                cout << left << setw(20) << batter1 << " is on strike" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                cin >> run1;
                cout << "--------------------------------------------------------" << endl;
                batter = batter1;
                cout << left << setw(20) << batter << " played..." << endl;
                cout << "-----------------------------------------" << endl;
                cout << endl;
                run = run1;
                strike = true;
            }
            strike = !strike;
        }
        else
        {
            if (run % 2 != 0)
            {
                if (strike == true)
                {
                    cout << "--------------------------------------------------------" << endl;
                    cout << left << setw(20) << batter2 << " is on strike" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                    cin >> run2;
                    cout << "--------------------------------------------------------" << endl;
                    batter = batter2;
                    cout << left << setw(20) << batter << " played..." << endl;
                    cout << "-----------------------------------------" << endl;
                    run = run2;
                    strike = false;
                }
                else if (strike == false)
                {
                    cout << "--------------------------------------------------------" << endl;
                    cout << left << setw(20) << batter1 << " is on strike" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                    cin >> run1;
                    cout << "--------------------------------------------------------" << endl;
                    batter = batter1;
                    cout << left << setw(20) << batter << " played..." << endl;
                    cout << "-----------------------------------------" << endl;
                    run = run1;
                    strike = true;
                }
            }
            else
            {
                if (strike == true)
                {
                    cout << "--------------------------------------------------------" << endl;
                    cout << left << setw(20) << batter1 << " is on strike" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                    cin >> run1;
                    cout << "--------------------------------------------------------" << endl;
                    batter = batter1;
                    cout << left << setw(20) << batter << " played..." << endl;
                    cout << "-----------------------------------------" << endl;
                    run = run1;
                    strike = true;
                }
                else if (strike == false)
                {
                    cout << "--------------------------------------------------------" << endl;
                    cout << left << setw(20) << batter2 << " is on strike" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << " Nice delivery by " << bolwer << " now its up to batsman: ";
                    cin >> run2;
                    cout << "--------------------------------------------------------" << endl;
                    batter = batter2;
                    cout << left << setw(20) << batter << " played..." << endl;
                    cout << "-----------------------------------------" << endl;
                    run = run2;
                    strike = false;
                }
            }
        }
        balls++;
    }
    return 0;
}

void selection1(string ausses[], string lions[], int comp[], int aus_score[], int eng_score[], int &score_australia, int &score_england)
{
    string batter1, batter2, bolwer;

    int bat1 = 0;    // index for batter1
    int bat2 = 1;    // index for batter2
    int nextBat = 2; // next new batsman
    int bol = 8;     // starting bowler index
                     // team score (passed to main1)

    batter1 = ausses[bat1];
    batter2 = ausses[bat2];
    cout << "\n\033[32m Opening Batsmen: " << batter1 << " & " << batter2 << endl;

    int strike = main1(comp, lions[bol], batter1, batter2, aus_score, eng_score, bat1, bat2, score_australia);

    bol++;

    // loop until all batsmen are out
    while (nextBat < 11)
    {
        cout << "\n----------------------------------" << endl;
        if (strike == 1) // batter1 OUT
        {
            cout << batter1 << " is OUT" << endl;
            batter1 = ausses[nextBat];
            cout << "\033[32m New batsman comes in: " << batter1 << endl;
            bat1 = nextBat;
            score1 = 0;
            nextBat++;
        }
        else if (strike == 2) // batter2 OUT
        {
            cout << batter2 << " is OUT" << endl;
            batter2 = ausses[nextBat];
            cout << "New batsman comes in: " << batter2 << endl;
            bat2 = nextBat;
            score2 = 0;
            nextBat++;
        }
        else
        {
            break; // safety
        }
        if (bol > 10)
            bol = 8;
        strike = main1(comp, lions[bol], batter1, batter2, aus_score, eng_score, bat1, bat2, score_australia);
        bol++;
    }
    aus_score[bat1] = score1;
    aus_score[bat2] = score2;
    cout << "\n=========== INNINGS COMPLETE ===========" << endl;
    cout << "Total score by team Australia is: " << score_australia << " And total out is: " << total_out << endl;
    cout << "\n========================================" << endl;
    aus_out = total_out;
    total_out = 0;
}

void selection2(string ausses[], string lions[], int comp[], int aus_score[], int eng_score[], int &score_australia, int &score_england)
{
    string batter1, batter2, bolwer;

    int bat1 = 0;    // index for batter1
    int bat2 = 1;    // index for batter2
    int nextBat = 2; // next new batsman
    int bol = 8;     // starting bowler index
                     // team score (passed to main1)

    batter1 = lions[bat1];
    batter2 = lions[bat2];
    cout << "\n\033[32m Opening Batsmen: " << batter1 << " & " << batter2 << endl;

    int strike = main2(comp, ausses[bol], batter1, batter2, aus_score, eng_score, bat1, bat2, score_england);

    bol++;

    // loop until all batsmen are out
    while (nextBat < 11)
    {
        cout << "\n----------------------------------" << endl;
        if (strike == 1) // batter1 OUT
        {
            cout << batter1 << " is OUT" << endl;
            batter1 = lions[nextBat];
            cout << "\033[32m New batsman comes in: " << batter1 << endl;
            bat1 = nextBat;
            score1 = 0;
            nextBat++;
        }
        else if (strike == 2) // batter2 OUT
        {
            cout << batter2 << " is OUT" << endl;
            batter2 = lions[nextBat];
            cout << "New batsman comes in: " << batter2 << endl;
            bat2 = nextBat;
            score2 = 0;
            nextBat++;
        }
        else
        {
            break; // safety
        }
        if (bol > 10)
            bol = 8;
        strike = main2(comp, ausses[bol], batter1, batter2, aus_score, eng_score, bat1, bat2, score_england);
        bol++;
    }
    eng_score[bat1] = score1;
    eng_score[bat2] = score2;
    cout << "\n=========== INNINGS COMPLETE ===========" << endl;
    cout << "Total score by team England is: " << score_england << " And total out is: " << total_out << endl;
    cout << "\n========================================" << endl;
    eng_out = total_out;
    total_out = 0;
}

int main()
{
    string ausses[11]{
        "David Warner", "Usman Khawja", "Ricking pointing", " Head", "Steve Smith", "Marnus Labuscahnge",
        "Mitchell Marsh", "Alex Carey", "Micthel Starc", "Pat Cummnis", "Jossh Hazlewood"};

    string lions[11]{
        "Jahson Roy",
        "Ben Duckett",
        "Harry Brook",
        "Joe Root",
        "Zack Crawley",
        "Ben Stokes",
        "Jony Bairstrow",
        "Mooen Ali",
        "Straut Broad",
        "James Anderson",
        "Jofa Arcther",
    };
    srand(time(0));
    int aus_score[11]{};
    int eng_score[11]{};
    int comp[5]{1, 2, 3, 4, 6};
    int score_australia = 0;
    int score_engalnd = 0;
    head(ausses, lions);
    cout << "\033[31m ----Now it's time for the toss----" << endl;

    cout << "\033[33mCommentator: Wasim Akram says, 'Who will win the toss today?'\n";
    cout << "Commentator: Ravi Shastri adds, 'Both teams are looking strong, this will be exciting!'\n";
    int toss_comp = rand() % 2;
    string ausCaptain = "Pat Cummins";
    string engCaptain = "Ben Stokes";

    if (toss_comp == 0)
    {
        cout << "\033[32mAustralia won the toss!" << endl;
        cout << ausCaptain << " (Australia Captain) chooses to bat first." << endl;
        selection1(ausses, lions, comp, aus_score, eng_score, score_australia, score_engalnd);
        cout << "\n\033[33m----- Second Innings: England is batting -----" << endl;
        selection2(ausses, lions, comp, aus_score,  eng_score, score_australia, score_engalnd);
    }
    else
    {
        cout << "\033[32mEngland won the toss!" << endl;
        cout << engCaptain << " (England Captain) chooses to bat first." << endl;
        selection2(ausses, lions, comp, aus_score, eng_score, score_australia, score_engalnd);
        cout << "\n\033[33m----- Second Innings: Australia is batting -----" << endl;
        selection1(ausses, lions, comp, aus_score, eng_score, score_australia, score_engalnd);
    }

    cout << "\033[31m============================================" << endl;
    cout << "              🏏 Match Summary 🏏" << endl;
    displayTeamScore(aus_score, "Australia", 11, ausses);
    displayTeamScore(eng_score, "England", 11, lions);
    cout << "--------------------------------------------" << endl;
    cout << "Australia total score: " << score_australia << " for " <<  aus_out << " wickets" << endl;
    cout << "England total score: " << score_engalnd << " for " << eng_out << " wickets" << endl;
    cout << "--------------------------------------------" << endl;
    if (score_australia > score_engalnd)
    {
        cout << "🔥 The Ashes triumph goes Down Under! Team Australia have conquered England in a thrilling contest!" << endl;
        cout << "Cheers to Warner, Smith, and the mighty Aussie lineup!" << endl;
    }
    else if (score_australia < score_engalnd)
    {
        cout << "⚡ England has snatched victory in front of their home crowd! Team England rise victorious in the historic Ashes clash!" << endl;
        cout << "Kudos to Root, Stokes, and the valiant Lions!" << endl;
    }
    else
    {
        cout << "⚖️ What a battle! The Ashes end in a hard-fought draw!" << endl;
        cout << "Both teams gave their all, leaving fans on the edge of their seats!" << endl;
        cout << "🏟️ Cricket magic at its finest! 🏟️" << endl;
    }
    cout << "============================================" << endl;
    cout << "Thanks for following the epic contest! Until next Ashes clash… 🏏" << endl;
    return 0;
}

# Virtual-Turkish-Super-League-Table
You are required to code a program that can create a virtual Turkish Super League Table. 
### Project Requirements
-	There are 10 teams in the league. And the number of teams may be changed if needed. 
-	The team gets 2 points for a win, 1 point for a draw and -1 point for a loss. And these may be changed if needed. 
-	Each team has a one character alias and at most 12 character team name. The team aliases shall be  like ‘A’, ‘B’, ‘C’, ‘D’, ‘E’, ‘F’, ‘G’, ‘H’, ‘I’, ‘J’. The names of the teams are stored in “takimlar.txt” file. You will be given these files during your exam.
-	Initially each team’s points and matches should be 0.
-	The program should be able to input matches from both keyboard and the files and calculate the points table. 
-	When the user enters a result from the keyboard, it should be in the following format “A 3 C 2”. This means that team A and team C has played a game, and A scored 3 and C scored 2 goals.
-	For the file input each line in the file will have to have the exact format of the keyboard input. Naturally, the file may have more than one line representing different matches.
-	If the user enters a result for an already played game, the system should give a warning and ignore the incorrect input.
-	The points table should be printed out to a file and to the screen sorted by the points, team names or aliases. If needed the team names should be printed in capital.
-	The number of teams in the league, the points awarded to win, draw and loss should be kept in a file named as ayarlar.txt. You will also be given a file during the exam.
-	The following properties are expected from the points table

1.	Aliases - A, B, C, etc.
2.	Name of the team, 12 characters
3.	Total matches played
4.	Wins
5.	Draws	6.	Losses
7.	Goals Scored
8.	Goals Allowed
9.	Goal Difference
10.	Points

### Required for Coding
-	During the coding, you should make sure that you take advantage of functions as much as possible. The main function should mostly contain function calls..
-	The teams should be stored in a structure.
-	You are expected to code as a group without outside help. You may seek help from your friends to understand the problem, to develop algorithms. You shall never copy others codes. If this happens, you may be subjected to a disciplinary investigation. Each submitted code will be cross correlated for similarity. 
-	When you submit your code it should be submitted as a single c file “student_no.c” 
-	You are expected to submit a code that can be compiled in a Debian based Linux OS. Compiling and running the code is your responsibility. We will not help you to compile and debug your code during the exam.

### Scoring, Group Work and Important Dates
-	The project must be coded as a group formed by two students.Each student should undertake certain parts of the code.
-	Each student will get 40% from the project and 60% from the part of his/her responsibility.
-	The project points will be your midterm exam results.
-	If you do not take part, you will be marked as absent in the midterms.
-	The final submission date is 28-04-2019.
-	The exam dates will be announced later.

|                                                                                      |     |
|--------------------------------------------------------------------------------------|-----|
| Compile and Run                                                                      | %10 |
| Moduler programming and coding style, documentation                                  | %20 |
| Keyboard based demonstration                                                         | %10 |
| Usage of Structs in the code - File operations                                       | %10 |
| Sorting algorithms - String operations, sorting according to team name               | %15 |
| The handling of incorrect inputs - Calculating points by reading entries from a file | %15 |
| Presentation and being able to change his/her code                                   | %20 |


| Texts Required for Homework |                                                    |                                                                                                 |
|-----------------------------|----------------------------------------------------|-------------------------------------------------------------------------------------------------|
| ayarlar.txt                 | Number of teams<br/> Win Points<br/> Draw Points<br/> Loss Points | 10<br/> 2<br/> 1<br/> -1<br/>                                                                                       |
| takimlar.txt                | A<br/> B<br/> C<br/> D<br/> E<br/> F<br/> G<br/> H<br/> I<br/> J<br/>                                | Arsenal<br/> Chelsea<br/> Liverpool<br/> Tottenham<br/> Brighton<br/> Everton<br/> Burnley<br/> Southampton<br/> Watford<br/> Fulham         |
| maclar1.txt                 |                                                    | A 3 B 0<br/> C 0 D 0<br/> E 1 F 3<br/> G 4 H 5<br/> B 0 A 2<br/> I 1 J 0<br/> B 1 C 2<br/> D 3 E 2<br/> F 1 G 0<br/> A 1 B 1<br/> H 0 I 0<br/> J 2 A 1 |


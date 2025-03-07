#pragma once

void UI();
int ClickBottom();
void ExitGame();
int StartGame();
void AI();
int JudgeGame(int x, int y);
void StartGameUI(int type);
void EndGameBLACK(int type);
void EndGameWHITE(int type);
void Player2();
void EndGameDraw(int type);
void ClearBoard();
void Withdraw();
void StartUI();
int  ClickBottom2();
int StartGame2();
int AI_score(int x, int y, int t);
void AI_First(int type);
void ChangeColor();
void UI_AI();
int JudgeForbidden(int t);
void EndGameForbidden();
void AI_2();
void AIPlay();
int AIPlay2(int n, int score);
int AIPlay2_F(int n, int score);
int AIPlay2_F_2(int n, int score);
void ReversalChess();
void FindFirstPosition();
void StartGame3();
void PrintMap();
void PrintStep();
void WithdrawAnyStep();
void PrintChess(int step, int x, int y, int color);
void EndGame(int type,int situation);
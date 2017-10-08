#pragma once

void countToRank(int col, int count);

void setRanking();
void setRowLeftRank(int col, int row);
void setRowRightRank(int col, int row);
void setColUpRank(int col, int row);
void setColDownRank(int col, int row);
void setK1UpRank(int col, int row);
void setK1DownRank(int col, int row);
void setK2UpRank(int col, int row);
void setK2DownRank(int col, int row);
int searchTopRanking();
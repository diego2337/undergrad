

// Copyright 2011 Jefferson Willian
// willmont7@gmail.com

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

#define MAX 1001
#define INF 1000000

using std::string;
using std::sort;
using std::cin;

typedef struct Player {
  string name;
  int pts;
}Player;

bool compare(Player a, Player b) {
  if (a.pts == b.pts)
    return a.name < b.name;
  return a.pts > b.pts;
}

int main() {
  int n;
  Player players[MAX];
  int higher;
  int lower;
  int temp;
  int current;
  int games = 1;

  while (scanf("%d", &n) && n != 0) {
    for (int i = 0;i < n;i++) {
      higher = 0;
      lower = INF;

      players[i].pts = 0;
      cin >> players[i].name;

      for (int j = 0;j < 12;j++) {
        scanf("%d", &temp);
        if (temp > higher)
          higher = temp;
        if (temp < lower)
          lower = temp;
        players[i].pts += temp;
      }
      /* Retira os menor e maior valores calculados */
      players[i].pts -= lower+higher;
    }

    /* Ordena de acordo com a pontuacao e/ou ordem alfabetica */
    sort(players, players+n, compare);

    current = 0;

    printf("Teste %d\n", games++);
    for (int i = 0;i < n;i++) {
      if (i == 0 || players[i].pts != players[i-1].pts)
        current = i+1;
      printf("%d %d %s\n", current, players[i].pts, players[i].name.c_str());
    }

    printf("\n");
  }

  return 0;
}